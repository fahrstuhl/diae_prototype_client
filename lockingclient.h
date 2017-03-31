#ifndef LOCKINGCLIENT_H
#define LOCKINGCLIENT_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>

class LockingClient : public QObject
{
    Q_OBJECT
public:
    explicit LockingClient(QObject *parent = 0);

Q_SIGNALS:
    void closed();
    void receivedLock();
    void receivedUnlock();
    void receivedMessage(QString message);

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_webSocket;
};

#endif // LOCKINGCLIENT_H
