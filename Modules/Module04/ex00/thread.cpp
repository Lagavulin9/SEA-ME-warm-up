#include "thread.h"
#include "gamescene.h"

Thread::Thread(QObject* parent)
    : QObject{parent}
{}

QFuture<void> Thread::run(GameScene* gameScene, int i)
{
    QObject::connect(this, &Thread::findTarget, &gameScene->m_game.cars[i], &Car::findTarget);
    QFuture<void> future = QtConcurrent::run([gameScene, this]()
                                             {
                                                while (gameScene->running) {
                                                    gameScene->mutex.lock();
                                                    emit this->findTarget();
                                                    gameScene->mutex.unlock();
                                                }
                                            });
    return (future);
}
