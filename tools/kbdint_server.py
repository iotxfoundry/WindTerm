#!/usr/bin/env python3
# kbdint E2E 本地 SSH 服务器（asyncssh）：keyboard-interactive 两轮挑战。
# 用法：kbdint_server.py [record_file]
#   端口自分配（listen port=0），首行往 stdout 打 "<port>"，随后每轮认证收到的
#   answers 以 JSON 行记录到 stdout 与 record_file（若给定）：
#     {"round":1,"answers":["...","..."]}
# 挑战脚本（与 tests/test_ssh_kbdint_e2e.cpp 的回执约定，服务端为唯一判定方）：
#   轮 1: name="Verification" instruction="Answer:"
#         prompts=[("Token:", echo=False), ("Site:", echo=True)]
#         期望 Token=="tokéns"（UTF-8 样本）且 Site=="hq"
#   轮 2: name="Verification" instruction="Round 2:"
#         prompts=[("Code:", echo=False)] 期望 Code=="777"
#   全对→认证成功（无密码/无公钥，仅 kbdint）；pty+shell 请求照常接受，shell
#   数据回显，收到换行后回 "e2e-ok" 并关通道（给客户端一个确定终局）。
import asyncio
import json
import sys

import asyncssh

RECORD_FILE = None


class KbdintServer(asyncssh.SSHServer):
    def begin_auth(self, username):
        return True  # 认证必需（kbdint-only 服务器）

    def get_kbdint_challenge(self, username, lang, submethods):
        return ('Verification', 'Answer:', '', [('Token:', False), ('Site:', True)])

    def validate_kbdint_response(self, username, responses):
        # 无状态判定（round 计数不随 validate 递增，易错配）：按内容分流——
        # 轮1 答 ['tokéns','hq'] → 发第二轮 Code 挑战；轮2 答 ['777'] → 认证通过
        responses = list(responses)
        record = json.dumps({'answers': responses})
        sys.stdout.write(record + '\n')
        sys.stdout.flush()
        if RECORD_FILE:
            with open(RECORD_FILE, 'a', encoding='utf-8') as f:
                f.write(record + '\n')
        if responses == ['tokéns', 'hq']:
            return ('Verification', 'Round 2:', '', [('Code:', False)])
        if responses == ['777']:
            return True  # 两轮全对→认证成功
        return False  # 答错→认证失败

    def session_requested(self):
        return True

    def password_auth_supported(self):
        return False

    def public_key_auth_supported(self):
        return False

    def kbdint_auth_supported(self):
        return True


class ShellSession:
    # stream handler 工厂签名：asyncssh 把 (stdin, stdout, stderr) 交给我们（写入回显）
    def __init__(self):
        pass

    @staticmethod
    def handle(stdin, stdout, stderr):
        async def _run():
            try:
                while not stdin.at_eof():
                    data = await stdin.read(4096)
                    if not data:
                        break
                    stdout.write(data)  # 回显
                    if b'\r' in data or b'\n' in data:
                        stdout.write(b'e2e-ok\r\n')
                        await stdout.drain()
                        stdout.close()
                        break
            except Exception as e:  # 诊断可见（正常路径不应触达）
                stderr.write(f'srv-handler-err: {e!r}\n'.encode())
                await stderr.drain()
        return _run()


async def main():
    global RECORD_FILE
    record_file = sys.argv[1] if len(sys.argv) > 1 else None
    RECORD_FILE = record_file

    server = await asyncssh.listen(
        host='127.0.0.1', port=0,
        server_host_keys=[asyncssh.generate_private_key('ssh-ed25519')],
        server_factory=KbdintServer,
        session_factory=ShellSession.handle,  # stream handler（stdin/stdout/stderr）
        encoding=None,  # 字节流（终端数据泵语义）
    )
    port = server.sockets[0].getsockname()[1]
    sys.stdout.write(str(port) + '\n')
    sys.stdout.flush()
    await server.wait_closed()


if __name__ == '__main__':
    asyncio.run(main())
