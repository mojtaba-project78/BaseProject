#include "XObjectManagement.h"

XObjectManagement m_object;

//==============================================================================
void XObjectManagement::setObject(QObject* m_object) {
    this->m_obj = m_object;
}

//==============================================================================
QObject *XObjectManagement::getObject() {
    return this->m_obj;
}

//==============================================================================
void XObjectManagement::checkObject()
{
    if(m_obj == nullptr)
        LOG_TRACE(QString("object of engine pointer is nullptr."));

    return;
}

//==============================================================================
void XObjectManagement::call(QString objectName, const char* functionName, QVariantMap map)
{
    checkObject();
    QObject* myObject = getObject()->findChild<QObject*>(objectName);
    if(!myObject) {
        LOG_TRACE(QString("objectName: '%1' not found").arg(objectName));
        return;
    }

    if(map.isEmpty())
        QMetaObject::invokeMethod(myObject, functionName);
    else
        QMetaObject::invokeMethod(myObject, functionName, Q_ARG(QVariant, QVariant::fromValue(map)));
}

//==============================================================================
void XObjectManagement::singleCall(QString objectName, const char *functionName, QVariant map)
{
    checkObject();
    QObject* myObject = getObject()->findChild<QObject*>(objectName);
    if(!myObject) {
        LOG_TRACE(QString("objectName: '%1' not found").arg(objectName));
        return;
    }
    QMetaObject::invokeMethod(myObject, functionName, Q_ARG(QVariant, QVariant::fromValue(map)));
}

//==============================================================================
void XObjectManagement::call(const char *functionName, QVariantMap map)
{
    checkObject();
    if(map.isEmpty())
        QMetaObject::invokeMethod(this->getObject(), functionName);
    else
        QMetaObject::invokeMethod(this->getObject(), functionName, Q_ARG(QVariant, QVariant::fromValue(map)));
}

//==============================================================================
void XObjectManagement::singleCall(const char *functionName, QVariant map)
{
     QMetaObject::invokeMethod(getObject(), functionName, Q_ARG(QVariant, QVariant::fromValue(map)));
}

//==============================================================================
void XObjectManagement::set(QString objectName, const char* propertyName, QVariant value)
{
    checkObject();
    QObject* myObject = this->m_obj->findChild<QObject*>(objectName);
    if(!myObject) {
        LOG_TRACE(QString("objectName: '%1' not found").arg(objectName));
        return;
    }

    myObject->setProperty(propertyName, value);
}

//==============================================================================
QVariant XObjectManagement::get(QString objectName, const char* propertyName)
{
    checkObject();
    QObject* myObject = this->m_obj->findChild<QObject*>(objectName);
    if(!myObject) {
        LOG_TRACE(QString("objectName: '%1' not found").arg(objectName));
        return NULL;
    }
    return myObject->property(propertyName);
}
