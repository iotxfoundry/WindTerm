#ifndef VIEWBASE_H
#define VIEWBASE_H

#pragma once

#include <QString>
#include <QIcon>
#include <QVariant>
#include <QByteArray>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// Shared view-model facade used by TerminalView / EditorView / GrepView
// (their metacall case tables all point into the 0x8c5-0x8c6 cluster).
// All methods resolve the shared view via FUN_008c52fa and delegate to
// the model cluster at 0x8b9-0x8bd.


class ViewBase
{
public:
	// FUN_008c52fa: dynamic_cast QWidget then walk UP the parent chain
	// (+8/+0x10) to the nearest ancestor of class 0x11ab130 (the view
	// session container); 0 when none
	void *sharedView() const
	{
		void *w = asQWidget(this);
		while (w) {
			if (void *v = castToViewContainer(w))
				return v;
			w = parentWidget(w);
		}
		return nullptr;
	}

	// FUN_008c5438: same walk for class 0x11ab390 (the find-engine owner)
	void *findEngineOwner() const;

	void *query();                    // FUN_008c5d72 -> FUN_008bdd52(view, x)
	// model: the pane's +0x38 QTabBar-backed model:
	//   FUN_008b99f6: id resolver — null arg -> 0; else QWidget cast +
	//     QStackedWidget::indexOf (model+0x60); -1 walks up parents
	//   FUN_008b9b8e/0x8b9bbc: setTabIcon/tab text (FUN_005ab196/0x5ab09e
	//     via QTabBar at model+0x58)
	//   FUN_008b9c06/0x8b9c46: tabIcon / label lookup
	//     (FUN_005ab1a0/0x5ab180 -> FUN_005a6fbe)
	//   FUN_008bdd0e: bounds (FUN_008b9b2a count) -> FUN_005ab5d4
	//     (QTabBar op) + change notify 3
	void *m_model;    // pane +0x38 (QTabBar at +0x58, stack at +0x60)
	bool checkWithFallback();         // FUN_008c5c16: model query 0x8bbe50,
	                                   //  fallback: type check 0x8c4fd4 +
	                                   //  session 0x8c5438 + QVariant path
	bool isLoaded() const;            // FUN_008c56f2: property("Loaded")
	QString nameProperty() const;     // FUN_008c5578: property("Url")
	void setArg1(void *a);            // FUN_008c5e24 -> FUN_008b9b98
	void setArg2(void *a);            // FUN_008c5e56 -> FUN_008b9bc6
	QIcon icon() const;               // FUN_008c5e88 -> FUN_008b9c18
	QStringList stringList() const;   // FUN_008c5ecc -> FUN_008b9c5c(view, x, 1)
	int *sharedSchemeRef() const;     // FUN_008c53f8: view+0x30 refcounted int
	                                   //  (atomic LOCK/UNLOCK refcount++)
	void walkSelectionLists();        // FUN_008c6cc2: CoW uint-list walk
	                                   //  (FUN_005e9480 detach)
	// FUN_008c6f48 (6.8K, full): the view-id collector — iterates the
	// CoW widget list (detach FUN_005e9480), dynamic_casts each entry to
	// QWidget, runs qt_qFindChildren_helper with metaobject 0x119a2e0,
	// then per found child does a manual QMap tree lookup of the "id"
	// property (operator< walk) comparing against the target string;
	// matches are collected via FUN_008c81e8
};

#endif // VIEWBASE_H
