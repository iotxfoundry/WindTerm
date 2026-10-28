# King:: 枚举权威表(QMetaObject 精确值,2026-10-27 复核)

来源:主程序 King 类 QMetaObject 枚举表(qmo_extract.py 直读,
`python3 tools/re/qmo_extract.py /opt/WindTerm_2.7.0/WindTerm --json`)。
45 枚举全部注册 Q_ENUM/Q_FLAGS,**值精确,非声明序猜测**。
4294967295 = 0xFFFFFFFF(-1)。与 KingEnums.h 逐值一致(脚本校验 45/45)。

## CaseSensitivity (2 值)
| 0 CaseInsensitive | 1 CaseSensitive |

## Direction (4 值)
| 0 Left | 1 Right | 2 Top | 3 Bottom |

## DockArea (5 值)
| 0 UnknownDockArea | 1 LeftDockArea | 2 RightDockArea | 4 TopDockArea |
| 8 BottomDockArea |

## EchoMode (4 值)
| 0 EchoNone | 1 EchoAll | 2 EchoEdit | 3 EchoRandom |

## KeyMode (7 值)
| 0 UnknownMode | 1 WidgetMode | 2 NormalMode | 4 CommandMode |
| 8 RemoteMode | 16 LocalMode | 31 AnyMode |

## KeyModes (Q_FLAGS, = KeyMode)
| 0 UnknownMode | 1 WidgetMode | 2 NormalMode | 4 CommandMode |
| 8 RemoteMode | 16 LocalMode | 31 AnyMode |

## Led (3 值)
| 1 NumLock | 2 Captial | 4 Scroll |

## MessageLevel (6 值)
| 0 NormalMessage | 1 InfoMessage | 2 QuestionMessage | 3 WarningMessage |
| 4 ErrorMessage | 5 CriticalMessage |

## Orientation (2 值)
| 1 Horizontal | 2 Vertical |

## StandardButton (17 值)
| 0 NoneButton | 1 OkButton | 2 YesButton | 4 YesToAllButton |
| 8 NoButton | 16 NoToAllButton | 32 AbortButton | 64 ApplyButton |
| 128 CancelButton | 256 CloseButton | 512 DiscardButton | 1024 HelpButton |
| 2048 IgnoreButton | 4096 ResetButton | 8192 RestoreButton | 16384 RetryButton |
| 32768 UserButton |

## StandardButtons (Q_FLAGS, = StandardButton)
| 0 NoneButton | 1 OkButton | 2 YesButton | 4 YesToAllButton |
| 8 NoButton | 16 NoToAllButton | 32 AbortButton | 64 ApplyButton |
| 128 CancelButton | 256 CloseButton | 512 DiscardButton | 1024 HelpButton |
| 2048 IgnoreButton | 4096 ResetButton | 8192 RestoreButton | 16384 RetryButton |
| 32768 UserButton |

## TabSelectionBehavior (3 值)
| 0 SelectLeftTab | 1 SelectRightTab | 2 SelectPreviousTab |

## TextElideMode (4 值)
| 0 ElideLeft | 1 ElideRight | 2 ElideMiddle | 3 ElideNone |

## ToolButtonPopupMode (3 值)
| 0 DelayedPopup | 1 MenuButtonPopup | 2 InstantPopup |

## ToolButtonStyle (5 值)
| 0 ToolButtonIconOnly | 1 ToolButtonTextOnly | 2 ToolButtonTextBesideIcon | 3 ToolButtonTextUnderIcon |
| 4 ToolButtonFollowStyle |

## CaretShape (4 值)
| 0 LineCaret | 1 BlockCaret | 2 RectangleCaret | 3 UnderlineCaret |

## ChangeReason (12 值)
| 0 NoneChanged | 1 HorizontalScrollChanged | 2 VerticalScrollChanged | 4 HeightChanged |
| 8 WidthChanged | 16 ContentChanged | 32 SelectionChanged | 64 MarginStyleChanged |
| 128 MarginTextChanged | 256 MarkerAdded | 512 MarkerRemoved | 1024 WindowMoved |

## ChangeReasons (Q_FLAGS, = ChangeReason)
| 0 NoneChanged | 1 HorizontalScrollChanged | 2 VerticalScrollChanged | 4 HeightChanged |
| 8 WidthChanged | 16 ContentChanged | 32 SelectionChanged | 64 MarginStyleChanged |
| 128 MarginTextChanged | 256 MarkerAdded | 512 MarkerRemoved | 1024 WindowMoved |

## ColumnMarkerStyle (2 值)
| 0 LineMarker | 1 BackgroundMarker |

## DecorationType (23 值)
| 0 DecorationNull | 1 DecorationHidden | 2 DecorationSolid | 3 DecorationDouble |
| 4 DecorationThick | 5 DecorationHotspot | 6 DecorationDot | 7 DecorationDash |
| 8 DecorationDashDot | 9 DecorationDashDotDot | 10 DecorationStrike | 11 DecorationWavy |
| 12 DecorationBackground | 13 DecorationLineBackground | 14 DecorationLineEndingBackground | 15 DecorationBox |
| 16 DecorationRoundbox | 17 DecorationDashedbox | 18 DecorationDottedbox | 19 DecorationIcon |
| 20 DecorationFont | 21 DecorationLink | 22 DecorationVisitedLink |

## ScreenLocation (5 值)
| 0 TopLocation | 1 OneQuarterLocation | 2 CenterLocation | 3 ThreeQuarterLocation |
| 4 BottomLocation |

## Eol (5 值)
| 0 SYSTEM | 1 CR | 2 LF | 3 CRLF |
| 2 NATIVE |

## IndentGuideStyle (3 值)
| 0 LookBothGuide | 1 LookForwardGuide | 2 RealGuide |

## LineType (2 值)
| 0 DocumentLine | 1 VisibleLine |

## MarginType (7 值)
| 0 MarginUnknown | 1 MarginBlank | 2 MarginFold | 3 MarginNumber |
| 4 MarginSymbol | 5 MarginText | 6 MarginTimestamp |

## MatchOption (3 值)
| 1 MatchCase | 2 MatchRegex | 4 MatchWord |

## MatchOptions (Q_FLAGS, = MatchOption)
| 1 MatchCase | 2 MatchRegex | 4 MatchWord |

## SelectionType (2 值)
| 1 StreamSelection | 2 ColumnSelection |

## TextPosition (5 值)
| 0 Nowhere | 1 Anywhere | 2 LeadingPosition | 3 TrailingPosition |
| 4 SelectedPosition |

## WrapMode (3 值)
| 0 NoWrap | 1 CharWrap | 2 WordWrap |

## Charset (27 值)
| 0 CharsetUnknown | 1 UserSupplemental | 2 Ascii | 3 DecSpecial |
| 4 DecAltAscii | 5 DecAltSepcial | 6 DecSupplemental | 7 DecTechnical |
| 8 DecBritish | 9 DecDutch | 10 DecFinnish | 11 DecFrench |
| 12 DecFrenchCanadian | 13 DecGerman | 14 DecItalian | 15 DecNorwegianDanish |
| 16 DecPortuguese | 17 DecSpanish | 18 DecSwedish | 19 DecSwiss |
| 20 IsoCyrillicSupplemental | 21 IsoGreekSupplemental | 22 IsoHebrewSupplemental | 23 IsoLatin1Supplemental |
| 24 IsoLatin2Supplemental | 25 IsoTurkishSupplemental | 26 CharsetMax |

## FingerprintType (2 值)
| 0 Sha1 | 1 Md5 |

## LogOption (4 值)
| 0 eLogNone | 1 eLogOverwrite | 2 eLogAppend | 4 eLogCheckDontLog |

## LogType (6 值)
| 0 eLogNothing | 1 eLogDebug | 2 eLogPrintable | 4 eLogProtocol |
| 8 eLogTerm | 14 eLogEverything |

## ModemType (3 值)
| 0 XModem | 1 YModem | 2 ZModem |

## OneKeyType (3 值)
| 0 UnknownOneKey | 1 SshOneKey | 2 AccountOneKey |

## Protocol (6 值)
| 0 ProtocolUnknown | 1 ProtocolSerial | 2 ProtocolShell | 3 ProtocolSSH |
| 4 ProtocolTCP | 5 ProtocolTelnet |

## ServerKnownState (4 值)
| 0 ServerUnknown | 1 ServerKnown | 2 ServerChanged | 3 ServerMismatched |

## SessionAuthState (6 值)
| 4294967295 AuthError | 0 AuthSuccess | 1 AuthDenied | 2 AuthInfo |
| 3 AuthPartial | 4 AuthAgain |

## SessionState (11 值)
| 0 Unconnected | 1 HostLookup | 2 Connecting | 3 Connected |
| 4 Bound | 5 Closing | 6 Listening | 7 HostAuthed |
| 8 HostAuthing | 9 HostDenied | 10 HostVerified |

## Status (2 值)
| 4294967295 Error | 0 Ok |

## TransmitType (2 值)
| 0 Download | 1 Upload |

## TriggerType (13 值)
| 0 TriggerUnknown | 1 TriggerAfterConnection | 2 TriggerAfterDisconnection | 3 TriggerBeforeConnection |
| 4 TriggerBeforeDisconnection | 5 TriggerCustomLink | 6 TriggerCustomMenu | 7 TriggerExpect |
| 8 TriggerHighlightText | 9 TriggerPlaySound | 10 TriggerRunCommand | 11 TriggerSendText |
| 12 TriggerShowTooltip |

## TunnelType (4 值)
| 0 UnknownTunnel | 1 DynamicTunnel | 2 LocalTunnel | 3 RemoteTunnel |

## WriteReason (6 值)
| 0 UserWriteReason | 1 ExpectReason | 2 RemoteRequestReason | 3 SenderWriteReason |
| 4 SyncInputWriteReason | 5 TriggerReason |

## 上一轮"声明池"结论的更正(池 = King stringdata,非新数据)

- 池边界按命名前缀猜测,三处错:SelectionType 吞并 TextPosition(独立枚举);
  SessionAuthState 吞并 SessionState+Status(三个枚举);WriteReason 尾部
  TransferCenter 不是其第 7 值(Q_ENUM 仅 6 键,TransferCenter 为 stringdata
  中相邻的其他名字)。
- 值错:ChangeReason/MatchOption/LogType/LogOption 为位掩码;SelectionType
  从 1 起;Eol 实 5 键(SYSTEM=0,CR=1,LF=2,CRLF=3,NATIVE=2);
  SessionAuthState AuthError=-1;Status={Error=-1,Ok=0}。
- "新发现 7 枚举"系误报:WriteReason/CaretShape/ModemType/TransmitType/
  FingerprintType/ServerKnownState 均已在本表(上轮 moc 池见到的只是
  参数类型名字符串)。

## 唯一真缺口

- `King::DataType`:SuperCommander moc 池参数类型名,**无 Q_ENUM 注册**,
  值域不在任何 QMetaObject 表内,需从使用它的代码分支反推。
