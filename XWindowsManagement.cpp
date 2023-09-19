#include "XWindowsManagement.h"

std::unique_ptr<XWindowManagement> m_window(new XWindowManagement);

XWindowManagement::XWindowManagement(QObject *parent) : QObject(parent)
{}

//==============================================================================
void XWindowManagement::setWindowActive(int m_windowId)
{
    m_active_window = m_windowId;
}

//==============================================================================
void XWindowManagement::openWindow(int m_windowId)
{
    m_active_window = m_windowId;
    m_object.CallFunctionSingle("showWindow", m_windowId);
}

//==============================================================================
int XWindowManagement::getWindowActiveByIndex()
{
    return m_active_window;
}

//==============================================================================
void XWindowManagement::openPage(QString m_objectName)
{
    m_active_page = m_objectName;
    m_object.CallFunction(m_objectName, "open");
}

//==============================================================================
void XWindowManagement::openPage(QString m_objectName, QString functionName)
{
    m_active_page = m_objectName;
    m_object.CallFunction(m_objectName, functionName.toStdString().c_str());
    m_object.CallFunction(m_objectName, "open");
}

//==============================================================================
void XWindowManagement::openPage(QString m_objectName, QString functionName, QVariantMap map)
{
    m_active_page = m_objectName;
    m_object.CallFunction(m_objectName, functionName.toStdString().c_str(), map);
    m_object.CallFunction(m_objectName, "open");
}

//==============================================================================
void XWindowManagement::closePage(QString m_objectName)
{
    m_active_page = "";
    m_object.CallFunction(m_objectName, "close");
}

//==============================================================================
QString XWindowManagement::getActivePage()
{
    return m_active_page;
}

