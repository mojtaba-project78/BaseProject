#ifndef XOBJECTMANAGEMENT_H
#define XOBJECTMANAGEMENT_H

#include <QQuickView>
#include <QQuickItem>
#include <QString>
#include <QObject>
#include <QVariant>

#include "XLogManagement.h"

class XObjectManagement
{
public:
    void setObject(QObject* m_object);
    QObject *getObject();
    void checkObject();

    void call(QString objectName, const char* functionName, QVariantMap map = {});
    void singleCall(QString objectName, const char* functionName, QVariant map);
    void call(const char* functionName, QVariantMap map = {});
    void singleCall(const char* functionName, QVariant map);

    void set(QString objectName, const char* propertyName, QVariant value);
    QVariant get(QString objectName, const char* propertyName);

private:
    QObject *m_obj;
};

extern XObjectManagement m_object;

#endif // XOBJECTMANAGEMENT_H
