#include "networklockingplaintextedit.h"

void NetworkLockingPlainTextEdit::focusInEvent(QFocusEvent *event)
{
    this->setPlainText("focused");
    QPlainTextEdit::focusInEvent(event);
}

void NetworkLockingPlainTextEdit::focusOutEvent(QFocusEvent *event)
{
    this->setPlainText("");
    QPlainTextEdit::focusOutEvent(event);
}
