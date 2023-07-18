#ifndef THREAD_H
#define THREAD_H
#include <QObject>

#include <QtConcurrent/QtConcurrent>

class GameScene;

class Thread: public QObject
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);
    //Thread(){};
    Thread(const Thread& ref){(void) ref;};
    Thread& operator=(const Thread& ref){(void) ref; return *this;};
    ~Thread() = default;
    QFuture<void> run(GameScene *gameScene, int i);

signals:
    void findTarget();
};

#endif // THREAD_H
