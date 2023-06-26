#ifndef XLOGMANAGEMENT_H
#define XLOGMANAGEMENT_H

#include <QFile>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QDateTime>

#include "XObjectManagement.h"
#include "XAppConfiguration.h"

class XLogManagement
{
public:
    XLogManagement();
    ~XLogManagement();

public:
    void initializing();
    void addText(QString m_macto_file, QString m_macro_function, int m_macro_line, QString m_text = "");

private:
    QFile m_file;
    QString m_folderName;
};

extern XLogManagement m_log;

#define LOG_TRACE(x) m_log.addText(__FILE__, __FUNCTION__, __LINE__, x)

#endif // XLOGMANAGEMENT_H
