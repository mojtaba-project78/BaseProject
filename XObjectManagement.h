#ifndef XOBJECTMANAGEMENT_H
#define XOBJECTMANAGEMENT_H

#include <QObject>

class XObjectManagement : public QObject
{
    Q_OBJECT
public:
    explicit XObjectManagement(QObject *parent = nullptr);

signals:

};

#endif // XOBJECTMANAGEMENT_H
