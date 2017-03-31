#ifndef NETWORKLOCKINGPLAINTEXTEDIT_H
#define NETWORKLOCKINGPLAINTEXTEDIT_H

#include <QPlainTextEdit>
#include "lockingclient.h"

class NetworkLockingPlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT

public:
    explicit NetworkLockingPlainTextEdit(QPlainTextEdit *parent = Q_NULLPTR);

protected:
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);
    LockingClient lockingClient;
    void lock();
    void unlock();
    void useMessage(QString message);

};

#endif // NETWORKLOCKINGPLAINTEXTEDIT_H
