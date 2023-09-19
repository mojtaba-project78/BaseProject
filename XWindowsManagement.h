#ifndef XWINDOWMANAGEMENT_H
#define XWINDOWMANAGEMENT_H

#include <QObject>
#include <QString>
#include <QtDebug>
#include <memory>

#include "XAppConfiguration.h"
#include "XObjectManagement.h"
#include "XLogManagement.h"

class XWindowManagement : public QObject
{
    Q_OBJECT
public:
    explicit XWindowManagement(QObject *parent = nullptr);

public slots:
	void setWindowActive(int m_windowId);
	void openWindow(int m_windowId);
	void openPage(QString m_objectName);
	void openPage(QString m_objectName, QString functionName);
	void openPage(QString m_objectName, QString functionName, QVariantMap map);
	void closePage(QString objectName);
	int getWindowActiveByIndex();
	QString getActivePage();

private:
    int m_active_window;
    QString m_active_page;
};

extern std::unique_ptr<XWindowManagement> m_window;

#endif // XWINDOWMANAGEMENT_H
