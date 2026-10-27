#include "SshBridge.h"

// Implementation notes (reconstructed, see SSH-INTERNALS.md):
// - The protocol logic lives in the bridge state-machine layer (0x838-0x84b)
//   driving a libssh RAII wrapper class (0x627-0x62a):
//   ctor ssh_new()/throw, dtor ssh_disconnect()+ssh_free(),
//   options via ssh_options_set (incl. the WindTerm SSH_OPTIONS_PROXY_*
//   patch enums), auth via ssh_userauth_kbdint (see below), publickey,
//   try_publickey, auth_agent (Pageant) and userauth_list.
// - Password auth has no direct ssh_userauth_password call site: it goes
//   through the interactive (kbdint) loop or the ssh agent.

SshBridge::SshBridge(QObject *parent)
	: SuperBridge(parent)
{
}
