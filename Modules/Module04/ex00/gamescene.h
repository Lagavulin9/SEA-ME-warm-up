#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QVector>
#include <QFuture>
#include "game.h"

class Thread;
class QTimer;
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);
    ~GameScene();

    std::atomic<bool> running, pause;
    Game m_game;
    QTimer* m_timer;
    QPixmap m_bgPixmap, m_carPixmap[5];
    QVector<Thread*> threads;
    QVector<QFuture<void>> futures;
    QMutex mutex;

private slots:
    void update();

private:
    void loadPixmap();

    bool m_upDir, m_rightDir, m_downDir, m_leftDir;
    // QGraphicsScene interface
    void carMovement();
    void carCollision();
    void renderScene();
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // GAMESCENE_H
