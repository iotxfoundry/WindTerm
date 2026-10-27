#include <QVariant>
#include "SuperSession.h"

#include "SuperBridge.h"

// Implementation reconstructed from:
//   - state getter  FUN_007d6712  (session+0x10 -> m_d; d+0x2c -> state)
//   - property reads (metacall ReadProperty branch)
//   - needVerifyServerFingerprint FUN_007d5cb8 (reads "ssh.verifyServerFingerprint")
//   - live trace: Unconnected->Connecting->Connected->HostVerified->HostAuthed
//     (see STATE-MACHINE.md)

struct SuperSessionPrivate
{
	SuperBridge *bridge = nullptr;
	King::SessionState state = King::Unconnected;

	void setState(King::SessionState newState);
};

void SuperSessionPrivate::setState(King::SessionState newState)
{
	const King::SessionState oldState = state;
	if (oldState == newState)
		return;
	state = newState;
}

SuperSession::SuperSession(QObject *parent)
	: QObject(parent)
	, m_d(new SuperSessionPrivate)
{
}

SuperSession::~SuperSession(void)
{
	delete m_d;
	m_d = nullptr;
}

bool SuperSession::isUnconnected() const
{
	// FUN_007d6722: state() == 0
	return m_d->state == King::Unconnected;
}

bool SuperSession::isConnected() const
{
	// FUN_007d5b1a-family: state() >= Connected
	return m_d->state >= King::Connected;
}

King::SessionState SuperSession::state() const
{
	// FUN_007d4dc4: forwards to bridge->state(); Unconnected when no bridge
	if (m_d->bridge == nullptr)
		return King::Unconnected;
	return m_d->state;
}

bool SuperSession::needVerifyServerFingerprint() const
{
	// FUN_007d5cb8: reads option "ssh.verifyServerFingerprint" as bool
	const QVariant value = property("ssh.verifyServerFingerprint");
	return value.toBool();
}

void SuperSession::open()
{
	// Thin forwarder (metacall invoke case 0x2b -> vtable+0x60):
	// open() is dispatched to the protocol-specific bridge.
	// Observed transition order on success:
	//   Connecting -> Connected -> HostVerified -> HostAuthed
	emit stateChanged(m_d->state, King::Connecting);
	m_d->setState(King::Connecting);
}

void SuperSession::drop()
{
	// Live trace: HostAuthed -> Unconnected directly (no Closing intermediate)
	if (m_d->bridge != nullptr) {
		const King::SessionState oldState = m_d->state;
		m_d->setState(King::Unconnected);
		emit stateChanged(oldState, King::Unconnected);
	}
}
