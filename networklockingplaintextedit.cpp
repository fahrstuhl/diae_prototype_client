#include "networklockingplaintextedit.h"
NetworkLockingPlainTextEdit::NetworkLockingPlainTextEdit(QPlainTextEdit *parent) :
    QPlainTextEdit(parent)
{
    connect(&this->lockingClient, &LockingClient::receivedLock, this, &NetworkLockingPlainTextEdit::lock);
    connect(&this->lockingClient, &LockingClient::receivedUnlock, this, &NetworkLockingPlainTextEdit::unlock);
    connect(&this->lockingClient,
            &LockingClient::receivedMessage, this, &NetworkLockingPlainTextEdit::useMessage);
}

void NetworkLockingPlainTextEdit::focusInEvent(QFocusEvent *event)
{
    QPlainTextEdit::focusInEvent(event);
}

void NetworkLockingPlainTextEdit::focusOutEvent(QFocusEvent *event)
{
    this->setPlainText("");
    QPlainTextEdit::focusOutEvent(event);
}

void NetworkLockingPlainTextEdit::lock()
{
    this->setReadOnly(true);
}

void NetworkLockingPlainTextEdit::unlock()
{
    this->setReadOnly(false);
}

void NetworkLockingPlainTextEdit::useMessage(QString message)
{
    this->setPlainText(message);
}
