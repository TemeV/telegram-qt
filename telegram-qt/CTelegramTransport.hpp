/*
    Copyright (C) 2014 Alexandr Akulich <akulichalexander@gmail.com>

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef CTELEGRAMTRANSPORT_HPP
#define CTELEGRAMTRANSPORT_HPP

#include <QObject>

#include <QByteArray>

class CTelegramCore;

struct SDataCenter {
    QString address;
    quint16 port;
};

class CTelegramTransport : public QObject
{
    Q_OBJECT
public:
    CTelegramTransport(QObject *parent = 0) : QObject(parent) { }
    virtual void sendPackage(const QByteArray &package) = 0;

    virtual void connectToDc(const SDataCenter &dc) = 0;

    virtual QByteArray getPackage() = 0;

    // Method for testing
    virtual QByteArray lastPackage() const = 0;

signals:
    void connected();
    void readyRead();

};

#endif // CTELEGRAMTRANSPORT_HPP