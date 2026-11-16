// [B-OPENSOURCE] 第一方开源件 —— **勿逆向**。
// 这是 WindTerm 作者以 Apache-2.0 开源的一手组件(基于上游 ptyqt / 自研),不是反编译对象;
// 移植或修改须按 docs/calibration.md 逐句同构记录。分类依据见 src/README.md §1b。

 /*
 * Copyright 2020, WindTerm.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SPLITTER_H
#define SPLITTER_H

#pragma once

#include <QSplitter>

extern const char* const SPLITTER_RATIO;

class Splitter : public QSplitter
{
	Q_OBJECT

public:
	explicit Splitter(QWidget *parent = 0);
	~Splitter();

	void showIndex(int index);
	void hideIndex(int index);
	bool isIndexVisible(int index);
	void setIndexVisible(int index, bool visible);

	void setMainIndex(int mainIndex);
	// FUN_008ca062(52B,0028.c:11457):槽位替换 — 旧 widget deleteLater 后
	//   insertWidget(index, 新 widget)(语料 receiver = this,实参面照录)。
	void replaceIndex(int index, QWidget *widget);

protected:
	bool eventFilter(QObject *obj, QEvent *event);

	QSplitterHandle *createHandle();

Q_SIGNALS:
	void showIndexRequested(int index);
	void hideIndexRequested(int index);

private:
	Q_DISABLE_COPY(Splitter)

	int m_mainIndex;
};

#endif // SPLITTER_H