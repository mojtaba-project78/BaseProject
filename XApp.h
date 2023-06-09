#ifndef XAPP_H
#define XAPP_H

#include <QObject>

#include <memory>

#include "XWindowsManagement.h"
#include "XAppConfiguration.h"
#include "XLogManagement.h"
#include "XObjectManagement.h"

class XApp : public QObject
{
    Q_OBJECT
public:
    explicit XApp(QObject *parent = nullptr);

signals:

};

extern std::unique_ptr<XApp> m_app;

#endif // XAPP_H
