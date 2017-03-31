#include "lockingclient.h"

LockingClient::LockingClient(QObject *parent) : QObject(parent)
{
    LockingClient::LockingClient(QObject *parent) :
        QObject(parent)
    {
        connect(&m_webSocket, &QWebSocket::connected, this, &LockingClient::onConnected);
        connect(&m_webSocket, &QWebSocket::disconnected, this, &LockingClient::closed);
        m_webSocket.open(QUrl(QStringLiteral("ws:localhost:1234")));
    }

    void LockingClient::onTextMessageReceived(QString message)
    {
        if (message=="lock")
        {
            this->lock();
        }
        else if (message=="unlock")
        {
            this->unlock();
        }
        else
        {
            this->useMessage(message);
        }
    }

    void LockingClient::lock()
    {
        emit receivedLock();
    }

    void LockingClient::unlock()
    {
        emit receivedUnlock();
    }

    void LockingClient::useMessage(QString message)
    {
        emit receivedMessage(message);
    }

}
