// Frida hook: live-trace King::SessionState transitions.
// Attach to a running WindTerm (needs ptrace_scope=0 on Ubuntu):
//   sudo sysctl -w kernel.yama.ptrace_scope=0
//   frida -p <pid> -l frida_statechanged.js
// Then connect/disconnect an SSH session; transitions print in order.
// Emit stub 0x91237e = SuperSession::stateChanged (VA, non-PIE binary).

const NAMES = ["Unconnected", "HostLookup", "Connecting", "Connected", "Bound",
               "Closing", "Listening", "HostAuthed", "HostAuthing",
               "HostDenied", "HostVerified"];

send({ boot: "ready" });
Interceptor.attach(ptr("0x91237e"), {
  onEnter(args) {
    const old = args[1].toInt32();
    let nv = [];
    for (const off of [0x8, 0x10, 0x18])
      nv.push(Memory.readU32(args[2].add(off)));
    send({ t: Date.now(), old: NAMES[old] !== undefined ? NAMES[old] : old, nv });
  }
});
