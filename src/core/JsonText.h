#pragma once

#include <QByteArray>

namespace JsonText {

// 资产文件含 // 行注释（wind.config / wind.actions），字符串内的 // 不受影响
inline QByteArray stripLineComments(const QByteArray &input)
{
    QByteArray out;
    out.reserve(input.size());
    bool inString = false;
    bool escaped = false;

    for (int i = 0; i < input.size(); ++i) {
        const char c = input.at(i);
        if (inString) {
            out.append(c);
            if (escaped)
                escaped = false;
            else if (c == '\\')
                escaped = true;
            else if (c == '"')
                inString = false;
            continue;
        }
        if (c == '"') {
            inString = true;
            out.append(c);
            continue;
        }
        if (c == '/' && i + 1 < input.size() && input.at(i + 1) == '/') {
            while (i < input.size() && input.at(i) != '\n' && input.at(i) != '\r')
                ++i;
            if (i < input.size())
                out.append(input.at(i));
            continue;
        }
        out.append(c);
    }
    return out;
}

// 字符串字面量内的 0x00-0x1F 控制字符（含裸换行）替换为空格
inline QByteArray replaceControlCharsInStrings(const QByteArray &input)
{
    QByteArray out;
    out.reserve(input.size());
    bool inString = false;
    bool escaped = false;

    for (const char c : input) {
        if (inString) {
            if (escaped) {
                escaped = false;
                if (static_cast<unsigned char>(c) < 0x20) {
                    out.append(' ');
                    continue;
                }
            } else if (c == '\\') {
                escaped = true;
            } else if (c == '"') {
                inString = false;
            } else if (static_cast<unsigned char>(c) < 0x20) {
                out.append(' ');
                continue;
            }
        } else if (c == '"') {
            inString = true;
        }
        out.append(c);
    }
    return out;
}

} // namespace JsonText
