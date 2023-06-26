#include "XAppConfiguration.h"

std::unique_ptr<XAppConfiguration> m_config(new XAppConfiguration);

//==============================================================================
XAppConfiguration::XAppConfiguration(QObject *parent) : QObject(parent)
{
    m_folderName = "MyConfigurations";
}

void XAppConfiguration::initializing()
{
    LOG_TRACE("initializing...");

    if(!QFile::exists(QString("%1//%2").arg(m_folderName).arg("Configuration.ini"))) {
        LOG_TRACE(QString("file not found: %1").arg(QString("%1//%2").arg(m_folderName).arg("Configuration.ini")));

        //==============================================================================
        // creating data types
        QSettings m_config(QString("%1//%2").arg(m_folderName).arg("Configuration.ini"), QSettings::Format::IniFormat);
        m_config.setValue("WARNINGS/DONT_EDIT_REWRITE_VALUES", "");

        return;
    }
    QVariantMap map;

    //==============================================================================
    // ### define variables here...
    map.clear();
}

//==============================================================================
QVariant XAppConfiguration::get(QString m_key)
{
    QSettings m_config(QString("%1//%2").arg(m_folderName).arg("Configuration.ini"), QSettings::Format::IniFormat);
    return m_config.value(m_key);
}

//==============================================================================
void XAppConfiguration::update(QString m_key, QVariant m_value)
{
    LOG_TRACE(QString("Config Application Changed"));
    QSettings m_config(QString("%1//%2").arg(m_folderName).arg("Configuration.ini"), QSettings::Format::IniFormat);
    m_config.setValue(m_key, m_value);
}
