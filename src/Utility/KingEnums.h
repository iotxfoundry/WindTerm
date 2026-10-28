#ifndef KINGENUMS_H
#define KINGENUMS_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject enumerator
// tables (Q_ENUM registrations on the King metadata class). Values are
// exact; some entries deliberately skip values (bitmask/aliased values).

namespace King
{

enum CaretShape
{
	LineCaret = 0,
	BlockCaret = 1,
	RectangleCaret = 2,
	UnderlineCaret = 3
};

enum CaseSensitivity
{
	CaseInsensitive = 0,
	CaseSensitive = 1
};

enum ChangeReason
{
	NoneChanged = 0,
	HorizontalScrollChanged = 1,
	VerticalScrollChanged = 2,
	HeightChanged = 4,
	WidthChanged = 8,
	ContentChanged = 16,
	SelectionChanged = 32,
	MarginStyleChanged = 64,
	MarginTextChanged = 128,
	MarkerAdded = 256,
	MarkerRemoved = 512,
	WindowMoved = 1024
};

namespace ChangeReasonsNS
{
enum ChangeReasons
{
	NoneChanged = 0,
	HorizontalScrollChanged = 1,
	VerticalScrollChanged = 2,
	HeightChanged = 4,
	WidthChanged = 8,
	ContentChanged = 16,
	SelectionChanged = 32,
	MarginStyleChanged = 64,
	MarginTextChanged = 128,
	MarkerAdded = 256,
	MarkerRemoved = 512,
	WindowMoved = 1024
};
}  // using-scope: ChangeReasonsNS::NoneChanged ...

enum Charset
{
	CharsetUnknown = 0,
	UserSupplemental = 1,
	Ascii = 2,
	DecSpecial = 3,
	DecAltAscii = 4,
	DecAltSepcial = 5,
	DecSupplemental = 6,
	DecTechnical = 7,
	DecBritish = 8,
	DecDutch = 9,
	DecFinnish = 10,
	DecFrench = 11,
	DecFrenchCanadian = 12,
	DecGerman = 13,
	DecItalian = 14,
	DecNorwegianDanish = 15,
	DecPortuguese = 16,
	DecSpanish = 17,
	DecSwedish = 18,
	DecSwiss = 19,
	IsoCyrillicSupplemental = 20,
	IsoGreekSupplemental = 21,
	IsoHebrewSupplemental = 22,
	IsoLatin1Supplemental = 23,
	IsoLatin2Supplemental = 24,
	IsoTurkishSupplemental = 25,
	CharsetMax = 26
};

enum ColumnMarkerStyle
{
	LineMarker = 0,
	BackgroundMarker = 1
};

enum DecorationType
{
	DecorationNull = 0,
	DecorationHidden = 1,
	DecorationSolid = 2,
	DecorationDouble = 3,
	DecorationThick = 4,
	DecorationHotspot = 5,
	DecorationDot = 6,
	DecorationDash = 7,
	DecorationDashDot = 8,
	DecorationDashDotDot = 9,
	DecorationStrike = 10,
	DecorationWavy = 11,
	DecorationBackground = 12,
	DecorationLineBackground = 13,
	DecorationLineEndingBackground = 14,
	DecorationBox = 15,
	DecorationRoundbox = 16,
	DecorationDashedbox = 17,
	DecorationDottedbox = 18,
	DecorationIcon = 19,
	DecorationFont = 20,
	DecorationLink = 21,
	DecorationVisitedLink = 22
};

enum Direction
{
	Left = 0,
	Right = 1,
	Top = 2,
	Bottom = 3
};

enum DockArea
{
	UnknownDockArea = 0,
	LeftDockArea = 1,
	RightDockArea = 2,
	TopDockArea = 4,
	BottomDockArea = 8
};

enum EchoMode
{
	EchoNone = 0,
	EchoAll = 1,
	EchoEdit = 2,
	EchoRandom = 3
};

enum Eol
{
	SYSTEM = 0,
	CR = 1,
	LF = 2,
	CRLF = 3,
	NATIVE = 2
};

enum FingerprintType
{
	Sha1 = 0,
	Md5 = 1
};

enum IndentGuideStyle
{
	LookBothGuide = 0,
	LookForwardGuide = 1,
	RealGuide = 2
};

enum KeyMode
{
	UnknownMode = 0,
	WidgetMode = 1,
	NormalMode = 2,
	CommandMode = 4,
	RemoteMode = 8,
	LocalMode = 16,
	AnyMode = 31
};

namespace KeyModesNS
{
enum KeyModes
{
	UnknownMode = 0,
	WidgetMode = 1,
	NormalMode = 2,
	CommandMode = 4,
	RemoteMode = 8,
	LocalMode = 16,
	AnyMode = 31
};
}  // scope: KeyModesNS::...


enum Led
{
	NumLock = 1,
	Captial = 2,
	Scroll = 4
};

enum LineType
{
	DocumentLine = 0,
	VisibleLine = 1
};

enum LogOption
{
	eLogNone = 0,
	eLogOverwrite = 1,
	eLogAppend = 2,
	eLogCheckDontLog = 4
};

enum LogType
{
	eLogNothing = 0,
	eLogDebug = 1,
	eLogPrintable = 2,
	eLogProtocol = 4,
	eLogTerm = 8,
	eLogEverything = 14
};

enum MarginType
{
	MarginUnknown = 0,
	MarginBlank = 1,
	MarginFold = 2,
	MarginNumber = 3,
	MarginSymbol = 4,
	MarginText = 5,
	MarginTimestamp = 6
};

enum MatchOption
{
	MatchCase = 1,
	MatchRegex = 2,
	MatchWord = 4
};

namespace MatchOptionsNS
{
enum MatchOptions
{
	MatchCase = 1,
	MatchRegex = 2,
	MatchWord = 4
};
}  // scope: MatchOptionsNS::...


enum MessageLevel
{
	NormalMessage = 0,
	InfoMessage = 1,
	QuestionMessage = 2,
	WarningMessage = 3,
	ErrorMessage = 4,
	CriticalMessage = 5
};

enum ModemType
{
	XModem = 0,
	YModem = 1,
	ZModem = 2
};

enum OneKeyType
{
	UnknownOneKey = 0,
	SshOneKey = 1,
	AccountOneKey = 2
};

enum Orientation
{
	Horizontal = 1,
	Vertical = 2
};

enum Protocol
{
	ProtocolUnknown = 0,
	ProtocolSerial = 1,
	ProtocolShell = 2,
	ProtocolSSH = 3,
	ProtocolTCP = 4,
	ProtocolTelnet = 5
};

enum ScreenLocation
{
	TopLocation = 0,
	OneQuarterLocation = 1,
	CenterLocation = 2,
	ThreeQuarterLocation = 3,
	BottomLocation = 4
};

enum SelectionType
{
	StreamSelection = 1,
	ColumnSelection = 2
};

enum ServerKnownState
{
	ServerUnknown = 0,
	ServerKnown = 1,
	ServerChanged = 2,
	ServerMismatched = 3
};

enum SessionAuthState
{
	AuthError = 4294967295,
	AuthSuccess = 0,
	AuthDenied = 1,
	AuthInfo = 2,
	AuthPartial = 3,
	AuthAgain = 4
};

enum SessionState
{
	Unconnected = 0,
	HostLookup = 1,
	Connecting = 2,
	Connected = 3,
	Bound = 4,
	Closing = 5,
	Listening = 6,
	HostAuthed = 7,
	HostAuthing = 8,
	HostDenied = 9,
	HostVerified = 10
};

enum StandardButton
{
	NoneButton = 0,
	OkButton = 1,
	YesButton = 2,
	YesToAllButton = 4,
	NoButton = 8,
	NoToAllButton = 16,
	AbortButton = 32,
	ApplyButton = 64,
	CancelButton = 128,
	CloseButton = 256,
	DiscardButton = 512,
	HelpButton = 1024,
	IgnoreButton = 2048,
	ResetButton = 4096,
	RestoreButton = 8192,
	RetryButton = 16384,
	UserButton = 32768
};

namespace StandardButtonsNS
{
enum StandardButtons
{
	NoneButton = 0,
	OkButton = 1,
	YesButton = 2,
	YesToAllButton = 4,
	NoButton = 8,
	NoToAllButton = 16,
	AbortButton = 32,
	ApplyButton = 64,
	CancelButton = 128,
	CloseButton = 256,
	DiscardButton = 512,
	HelpButton = 1024,
	IgnoreButton = 2048,
	ResetButton = 4096,
	RestoreButton = 8192,
	RetryButton = 16384,
	UserButton = 32768
};
}  // scope: StandardButtonsNS::...


enum Status
{
	Error = 4294967295,
	Ok = 0
};

enum TabSelectionBehavior
{
	SelectLeftTab = 0,
	SelectRightTab = 1,
	SelectPreviousTab = 2
};

enum TextElideMode
{
	ElideLeft = 0,
	ElideRight = 1,
	ElideMiddle = 2,
	ElideNone = 3
};

enum TextPosition
{
	Nowhere = 0,
	Anywhere = 1,
	LeadingPosition = 2,
	TrailingPosition = 3,
	SelectedPosition = 4
};

enum ToolButtonPopupMode
{
	DelayedPopup = 0,
	MenuButtonPopup = 1,
	InstantPopup = 2
};

enum ToolButtonStyle
{
	ToolButtonIconOnly = 0,
	ToolButtonTextOnly = 1,
	ToolButtonTextBesideIcon = 2,
	ToolButtonTextUnderIcon = 3,
	ToolButtonFollowStyle = 4
};

enum TransmitType
{
	Download = 0,
	Upload = 1
};

enum TriggerType
{
	TriggerUnknown = 0,
	TriggerAfterConnection = 1,
	TriggerAfterDisconnection = 2,
	TriggerBeforeConnection = 3,
	TriggerBeforeDisconnection = 4,
	TriggerCustomLink = 5,
	TriggerCustomMenu = 6,
	TriggerExpect = 7,
	TriggerHighlightText = 8,
	TriggerPlaySound = 9,
	TriggerRunCommand = 10,
	TriggerSendText = 11,
	TriggerShowTooltip = 12
};

enum TunnelType
{
	UnknownTunnel = 0,
	DynamicTunnel = 1,
	LocalTunnel = 2,
	RemoteTunnel = 3
};

enum WrapMode
{
	NoWrap = 0,
	CharWrap = 1,
	WordWrap = 2
};

enum WriteReason
{
	UserWriteReason = 0,
	ExpectReason = 1,
	RemoteRequestReason = 2,
	SenderWriteReason = 3,
	SyncInputWriteReason = 4,
	TriggerReason = 5
};

} // namespace King

#endif // KINGENUMS_H
