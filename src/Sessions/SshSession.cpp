#include "SshSession.h"

#include <libssh/libssh.h>

// Implementation reconstructed from the libssh RAII wrapper class at
// 0x627-0x62a (see SSH-INTERNALS.md). The wrapper predates the bridge:
// construction throws on failure, options throw on -1, and interactive
// authentication runs the kbdint loop transcribed from FUN_00629dea.

namespace
{

class GetError // thrown by every wrapper method on SSH error (FUN_0062860c)
{
public:
	GetError(ssh_session session, int code)
		: m_message(QString::fromUtf8(ssh_get_error(session)))
		, m_code(code)
	{
	}

	QString m_message;
	int m_code;
};

class SshSessionContext // RAII wrapper: FUN_006292ce ctor / FUN_00629a77 dtor
{
public:
	SshSessionContext()
		: m_session(ssh_new())
	{
		// FUN_006292ce: ssh_new() failure -> throw "Session init failed."
		if (m_session == nullptr)
			throw GetError(nullptr, -1);
	}

	~SshSessionContext()
	{
		// FUN_00629a6f/0x629a77: disconnect + free together
		ssh_disconnect(m_session);
		ssh_free(m_session);
	}

	void setOption(enum ssh_options_e type, const void *value)
	{
		// FUN_0062870c
		if (ssh_options_set(m_session, type, value) == SSH_ERROR)
			throw GetError(m_session, SSH_ERROR);
	}

	void setOption(enum ssh_options_e type, unsigned int value)
	{
		// FUN_00628906: uint variants are passed by address
		if (ssh_options_set(m_session, type, &value) == SSH_ERROR)
			throw GetError(m_session, SSH_ERROR);
	}

	int availableAuthMethods() // ssh_userauth_list @ FUN_00629b0b
	{
		return ssh_userauth_list(m_session, nullptr);
	}

	QStringList interactivePrompts()
	{
		QStringList prompts;
		const int count = ssh_userauth_kbdint_getnprompts(m_session);
		for (int i = 0; i < count; ++i) {
			char echo = 0;
			const char *prompt = ssh_userauth_kbdint_getprompt(m_session, i, &echo);
			prompts.append(QString::fromLatin1(prompt));
		}
		return prompts;
	}

	// FUN_00629dea transcribed: the interactive authentication loop.
	// Returns libssh auth code (SSH_AUTH_*), 3 = SSH_AUTH_INFO means
	// another round of prompts is required.
	int authenticateInteractive(const std::function<QStringList(const QStringList &)> &responder)
	{
		for (;;) {
			const QStringList prompts = interactivePrompts();
			if (prompts.count() != 3) // FUN_00629dea: list count check == 3
				break;

			const QStringList answers = responder(prompts);

			const int rc = ssh_userauth_kbdint(m_session, nullptr, nullptr);
			if (rc != SSH_AUTH_INFO)
				return rc;
		}
		return ssh_userauth_kbdint(m_session, nullptr, nullptr);
	}

	King::ServerKnownState verifyKnownHost() // ssh_is_server_known @ FUN_006286ba
	{
		switch (ssh_session_is_known_server(m_session)) {
		case SSH_KNOWN_HOSTS_OK:         return King::ServerKnown;
		case SSH_KNOWN_HOSTS_CHANGED:    return King::ServerChanged;
		case SSH_KNOWN_HOSTS_OTHER:      return King::ServerMismatched;
		default:                         return King::ServerUnknown;
		}
	}

private:
	ssh_session m_session;
};

} // namespace

SshSession::SshSession(QObject *parent)
	: SuperSession(parent)
{
}
