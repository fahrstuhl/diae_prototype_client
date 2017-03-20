#ifndef NETWORKLOCKINGPLAINTEXTEDIT_H
#define NETWORKLOCKINGPLAINTEXTEDIT_H

#include <QPlainTextEdit>

class NetworkLockingPlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT

public:
    using QPlainTextEdit::QPlainTextEdit;

protected:
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);
};

#endif // NETWORKLOCKINGPLAINTEXTEDIT_H
