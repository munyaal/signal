#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>

//! [0]
class Bascula : public QThread
{
    Q_OBJECT

public:
    explicit Bascula(QObject *parent = nullptr);
    ~Bascula();

    void transaction(const QString &portName, int waitTimeout, const QString &request);
    void stopReading();


signals:
    void response(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;

    QString m_portName;
    QString m_request;
    int m_waitTimeout = 0;
    QMutex m_mutex;
    QWaitCondition m_cond;
    bool m_quit = false;
};
//! [0]

#endif // MASTERTHREAD_H
