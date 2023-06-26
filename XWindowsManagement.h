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

    Q_INVOKABLE
    void initializing();

    Q_INVOKABLE
    void setWindowActive(int m_windowId);

    Q_INVOKABLE
    void moveWindow(int m_windowId);

    Q_INVOKABLE
    int getWindowActiveByIndex();

    Q_INVOKABLE
    void openPage(QString m_objectName);

    Q_INVOKABLE
    void openPage(QString m_objectName, QString functionName);

    Q_INVOKABLE
    void openPage(QString m_objectName, QString functionName, QVariantMap map);

    Q_INVOKABLE
    void closePage(QString objectName);

    Q_INVOKABLE
    QString getActivePage();

private:
    int m_active_window;
    QString m_active_page;
};

extern std::unique_ptr<XWindowManagement> m_window;

#endif // XWINDOWMANAGEMENT_H
