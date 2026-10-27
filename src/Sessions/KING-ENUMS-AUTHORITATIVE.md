# King:: 枚举权威表(声明池直读,2026-10-27)

来源:枚举声明池(rodata 0x8ce700-0x8cf400,209 名)。
值 = 声明序(0 起,显式值未逐项证);交叉验证见文末。

## ToolButtonStyle(5 值)
| 0 ToolButtonIconOnly | 1 ToolButtonTextOnly | 2 ToolButtonTextBesideIcon | 3 ToolButtonTextUnderIcon |
| 4 ToolButtonFollowStyle |

## CaretShape(4 值)
| 0 LineCaret | 1 BlockCaret | 2 RectangleCaret | 3 UnderlineCaret |

## ChangeReason(12 值)
| 0 NoneChanged | 1 HorizontalScrollChanged | 2 VerticalScrollChanged | 3 HeightChanged |
| 4 WidthChanged | 5 ContentChanged | 6 SelectionChanged | 7 MarginStyleChanged |
| 8 MarginTextChanged | 9 MarkerAdded | 10 MarkerRemoved | 11 WindowMoved |

## ColumnMarkerStyle(2 值)
| 0 LineMarker | 1 BackgroundMarker |

## DecorationType(23 值)
| 0 DecorationNull | 1 DecorationHidden | 2 DecorationSolid | 3 DecorationDouble |
| 4 DecorationThick | 5 DecorationHotspot | 6 DecorationDot | 7 DecorationDash |
| 8 DecorationDashDot | 9 DecorationDashDotDot | 10 DecorationStrike | 11 DecorationWavy |
| 12 DecorationBackground | 13 DecorationLineBackground | 14 DecorationLineEndingBackground | 15 DecorationBox |
| 16 DecorationRoundbox | 17 DecorationDashedbox | 18 DecorationDottedbox | 19 DecorationIcon |
| 20 DecorationFont | 21 DecorationLink | 22 DecorationVisitedLink |

## ScreenLocation(5 值)
| 0 TopLocation | 1 OneQuarterLocation | 2 CenterLocation | 3 ThreeQuarterLocation |
| 4 BottomLocation |

## Eol(3 值)
| 0 SYSTEM | 1 CRLF | 2 NATIVE |

## IndentGuideStyle(3 值)
| 0 LookBothGuide | 1 LookForwardGuide | 2 RealGuide |

## LineType(2 值)
| 0 DocumentLine | 1 VisibleLine |

## MarginType(7 值)
| 0 MarginUnknown | 1 MarginBlank | 2 MarginFold | 3 MarginNumber |
| 4 MarginSymbol | 5 MarginText | 6 MarginTimestamp |

## MatchOption(3 值)
| 0 MatchCase | 1 MatchRegex | 2 MatchWord |

## SelectionType(8 值)
| 0 StreamSelection | 1 ColumnSelection | 2 TextPosition | 3 Nowhere |
| 4 Anywhere | 5 LeadingPosition | 6 TrailingPosition | 7 SelectedPosition |

## WrapMode(3 值)
| 0 NoWrap | 1 CharWrap | 2 WordWrap |

## Charset(27 值)
| 0 CharsetUnknown | 1 UserSupplemental | 2 Ascii | 3 DecSpecial |
| 4 DecAltAscii | 5 DecAltSepcial | 6 DecSupplemental | 7 DecTechnical |
| 8 DecBritish | 9 DecDutch | 10 DecFinnish | 11 DecFrench |
| 12 DecFrenchCanadian | 13 DecGerman | 14 DecItalian | 15 DecNorwegianDanish |
| 16 DecPortuguese | 17 DecSpanish | 18 DecSwedish | 19 DecSwiss |
| 20 IsoCyrillicSupplemental | 21 IsoGreekSupplemental | 22 IsoHebrewSupplemental | 23 IsoLatin1Supplemental |
| 24 IsoLatin2Supplemental | 25 IsoTurkishSupplemental | 26 CharsetMax |

## FingerprintType(2 值)
| 0 Sha1 | 1 Md5 |

## LogOption(4 值)
| 0 eLogNone | 1 eLogOverwrite | 2 eLogAppend | 3 eLogCheckDontLog |

## LogType(6 值)
| 0 eLogNothing | 1 eLogDebug | 2 eLogPrintable | 3 eLogProtocol |
| 4 eLogTerm | 5 eLogEverything |

## ModemType(3 值)
| 0 XModem | 1 YModem | 2 ZModem |

## OneKeyType(3 值)
| 0 UnknownOneKey | 1 SshOneKey | 2 AccountOneKey |

## Protocol(6 值)
| 0 ProtocolUnknown | 1 ProtocolSerial | 2 ProtocolShell | 3 ProtocolSSH |
| 4 ProtocolTCP | 5 ProtocolTelnet |

## ServerKnownState(4 值)
| 0 ServerUnknown | 1 ServerKnown | 2 ServerChanged | 3 ServerMismatched |

## SessionAuthState(6 值)
| 0 AuthError | 1 AuthSuccess | 2 AuthDenied | 3 AuthInfo |
| 4 AuthPartial | 5 AuthAgain |

## SessionState(11 值)
| 0 Unconnected | 1 HostLookup | 2 Connecting | 3 Connected |
| 4 Bound | 5 Closing | 6 Listening | 7 HostAuthed |
| 8 HostAuthing | 9 HostDenied | 10 HostVerified |

## Status(1 值)
| 0 Error |

## TransmitType(2 值)
| 0 Download | 1 Upload |

## TriggerType(13 值)
| 0 TriggerUnknown | 1 TriggerAfterConnection | 2 TriggerAfterDisconnection | 3 TriggerBeforeConnection |
| 4 TriggerBeforeDisconnection | 5 TriggerCustomLink | 6 TriggerCustomMenu | 7 TriggerExpect |
| 8 TriggerHighlightText | 9 TriggerPlaySound | 10 TriggerRunCommand | 11 TriggerSendText |
| 12 TriggerShowTooltip |

## TunnelType(4 值)
| 0 UnknownTunnel | 1 DynamicTunnel | 2 LocalTunnel | 3 RemoteTunnel |

## WriteReason(7 值)
| 0 UserWriteReason | 1 ExpectReason | 2 RemoteRequestReason | 3 SenderWriteReason |
| 4 SyncInputWriteReason | 5 TriggerReason | 6 TransferCenter |

## 复合别名

- ChangeReasons = Q_FLAGS(ChangeReason)(已还原的 TextView 修改原因位集)
- MatchOptions = Q_FLAGS(MatchOption)

## 交叉验证

1. SessionState 12 值与 Frida 实测序列(Unconnected→Connecting→Connected→
   HostVerified,断开直落)完全吻合。
2. Protocol{Unknown,Serial,Shell,SSH,TCP,Telnet} —— protocolExtCapable(==2||
   ==4)= Shell/TCP、protocolAltCapable(==3)= SSH,与 Telnet modem 分支互证。
3. CaretShape{Line,Block,Rectangle,Underline} —— cursorBlinkBit 的 0x2b 掩码
   (DECSCUSR shape×blink 分离语义)。
4. Charset 24 值(Ascii/DecSpecial/Dec 国家集/ISO 补充集/CharsetMax)= 字符集
   槽表(ScreenData.h kCharset94/96Slots)的真名域。
5. ModemType{XModem,YModem,ZModem} + TransmitType{Download,Upload} ——
   binaryTransfer 方向参与 transferBinary 信号参数闭环。
6. WriteReason 7 值(User/Expect/RemoteRequest/SenderWrite/SyncInput/Trigger/
   TransferCenter)= textWritten(text, writeReason) 语义域。
7. DecorationType 19 值(Null~VisitedLink,含 Wavy/Dashedbox)= TextView 装饰域。
8. TriggerType 10 值(CustomLink/CustomMenu/Expect/HighlightText/PlaySound/
   RunCommand/SendText/ShowTooltip + 连接时序 4)= 会话触发器域。
9. LogType/LogOption(eLog* 前缀)= 日志子系统配置域。
