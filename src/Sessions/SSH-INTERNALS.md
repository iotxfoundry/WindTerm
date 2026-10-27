# SSH 实现内部结构(逆向笔记,第二阶段)

> 数据来源:libssh PLT 交叉引用扫描(49 个 API 调用点,见文末)+ Ghidra 反编译。
> 地址均为 WindTerm 2.7.0 主程序 VA(非 PIE)。枚举值见 `KingEnums.h`。

## 分层架构

```
SuperSession / SuperBridge / SuperCommander   (0x7d4-0x7dc, 0x90e-0x912)
  信号/槽层:d->bridge 薄转发(state 存 bridge+0x2c)
      ↓
Bridge 状态机层                                (0x838-0x84b)
  QObject 世界,QMetaObject::activate 发射 stateChanged(0x11a8220)
      ↓
libssh 包装类(RAII + C++ 异常)               (0x627-0x62a)★ 本文件范围
      ↓
libssh.so.4 = 0.9.6 + WindTerm 补丁(源码在 src/libssh)
```

## 包装类要点

- **构造** `0x6292ce`:`ssh_new()` 失败 → `__cxa_throw("Session init failed.")`
- **析构** `0x629a6f/0x629a77`:`ssh_disconnect()` + `ssh_free()` 同函数(RAII)
- **setOption** `0x62870c`(void*)/ `0x628906`(uint):`ssh_options_set() == -1` → 抛错
  (作者补丁的 `SSH_OPTIONS_PROXY_HOST/PORT/EXTERNAL_CALLBACKS` 即经此处下发)
- **known_hosts**:`ssh_is_server_known@0x6286ba`、`ssh_write_knownhost@0x628a3a`

## 认证流(实证)

`0x629dea` —— authInteractive 底层核心:

```cpp
int authKbdint(ssh_session s) {
    QStringList prompts;
    do {
        int n = ssh_userauth_kbdint_getnprompts(s);
        for (int i = 0; i < n; i++) {
            char echo; auto p = ssh_userauth_kbdint_getprompt(s, i, &echo);
            prompts << QString::fromAscii(p);
        }
        uiCallback(prompts);                    // FUN_00627315:上抛登录向导
        // 答案经 ssh_userauth_kbdint_setanswer 回填(0x62a185)
        int rc = ssh_userauth_kbdint(s, NULL, NULL);
        if (rc != SSH_AUTH_INFO /*3*/) return rc;  // SUCCESS=2/DENIED=0/ERROR=-1
    } while (true);
}
```

认证面:kbdint(主)、publickey(0x627584)、try_publickey(0x628885)、
auth_agent→Pageant 补丁(0x627b06)、userauth_list=authMethods(0x629b0b)。
**无 ssh_userauth_password 直调** —— 密码认证走 kbdint/agent 路径。

## libssh API → 调用点(节选,完整表 /tmp/opencode/ssh_callsites.json)

| API | 调用点 |
|---|---|
| ssh_new | 0x6292d9 |
| ssh_free / ssh_disconnect | 0x629a77 / 0x629a6f |
| ssh_options_set | 0x62872a 0x62892a 0x62898c 0x6289e8 |
| ssh_userauth_kbdint(_getnprompts/_getprompt/_setanswer) | 0x629fd0 / 0x629e2d / 0x629e72 / 0x62a185 |
| ssh_userauth_publickey / try_publickey | 0x627584 / 0x628885 |
| ssh_userauth_list | 0x629b0b |
| ssh_channel_request_auth_agent | 0x627b06 |
| ssh_is_server_known / ssh_write_knownhost | 0x6286ba / 0x628a3a |

## 待办

- [ ] ssh_connect 未直调(经函数指针/虚表)→ 由 ssh_session_is_connected 调用者交叉定位
- [ ] Bridge 状态机(0x838-0x84b)函数逐个还原
- [ ] UI 回调链 FUN_00627315/00627110/0062713a/00627308 细化
