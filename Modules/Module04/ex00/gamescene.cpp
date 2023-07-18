#include "gamescene.h"
#include "thread.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDir>
#include <QPainter>
#include <QtConcurrent/QtConcurrent>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, running(true), pause(false), m_game(), m_timer(new QTimer(this)),
    m_upDir(false), m_rightDir(false), m_downDir(false), m_leftDir(false)
{
    loadPixmap();
    setSceneRect(0, 0, Game::RESOLUTION.width(), Game::RESOLUTION.height());
    connect(m_timer, &QTimer::timeout, this, &GameScene::update);

    m_timer->start(m_game.ITERATION_VALUE);
    for (int i=1; i< Game::COUNT_OF_CARS; ++i)
    {
        Thread* newThread = new Thread;
        threads.push_back(newThread);
        futures.push_back(newThread->run(this, i));
    }
    update();
}

GameScene::~GameScene()
{
    running = false;
    for(auto& future : futures) {
        future.waitForFinished();
    }
}

void GameScene::loadPixmap()
{
    if(m_bgPixmap.load(m_game.PATH_TO_BACKGROUND_PIXMAP))
    {
        qDebug() << "BgPixmap is loaded successfully";
    }
    else
    {
        qDebug() << "BgPixmap is not loaded successfully";
    }


    if(m_carPixmap[0].load(m_game.PATH_TO_CAR_PIXMAP[0]))
    {
        qDebug() << "CarPixmap[0] is loaded successfully";
    }
    else
    {
        qDebug() << "CarPixmap[0] is loaded successfully";
    }

    if(m_carPixmap[1].load(m_game.PATH_TO_CAR_PIXMAP[1]))
    {
        qDebug() << "CarPixmap[1] is loaded successfully";
    }
    else
    {
        qDebug() << "CarPixmap[1] is loaded successfully";
    }

    if(m_carPixmap[2].load(m_game.PATH_TO_CAR_PIXMAP[2]))
    {
        qDebug() << "CarPixmap[2] is loaded successfully";
    }
    else
    {
        qDebug() << "CarPixmap[2] is loaded successfully";
    }

    if(m_carPixmap[3].load(m_game.PATH_TO_CAR_PIXMAP[3]))
    {
        qDebug() << "CarPixmap[3] is loaded successfully";
    }
    else
    {
        qDebug() << "CarPixmap[3] is loaded successfully";
    }

    if(m_carPixmap[4].load(m_game.PATH_TO_CAR_PIXMAP[4]))
    {
        qDebug() << "CarPixmap[4] is loaded successfully";
    }
    else
    {
        qDebug() << "CarPixmap[4] is loaded successfully";
    }
}

void GameScene::carMovement()
{
    if (m_upDir && m_game.speed < m_game.maxSpeed)
    {
        if (m_game.speed < 0)
        {
            m_game.speed += m_game.dec;
        }
        else
        {
            m_game.speed += m_game.acc;
        }
    }

    if (m_downDir && m_game.speed > -m_game.maxSpeed)
    {
        if (m_game.speed > 0)
        {
            m_game.speed -= m_game.dec;
        }
        else
        {
            m_game.speed -= m_game.acc;
        }
    }


    if (!m_upDir && !m_downDir)
    {
        if (m_game.speed - m_game.dec > 0)
        {
            m_game.speed -= m_game.dec;
        }
        else if (m_game.speed + m_game.dec < 0)
        {
            m_game.speed += m_game.dec;
        }
        else
        {
            m_game.speed = 0;
        }
    }


    if (m_rightDir && m_game.speed!=0)
    {
        m_game.angle += m_game.turnSpeed * m_game.speed/m_game.maxSpeed;
    }

    if (m_leftDir && m_game.speed!=0)
    {
        m_game.angle -= m_game.turnSpeed * m_game.speed/m_game.maxSpeed;
    }

    m_game.cars[0].speed = m_game.speed;
    m_game.cars[0].angle = m_game.angle;

    for(int i = 0; i < m_game.COUNT_OF_CARS; i++)
    {
        m_game.cars[i].move();
    }
}

void GameScene::carCollision()
{
    for(int i = 0; i < Game::COUNT_OF_CARS;i++)
    {
        for(int j=0; j<Game::COUNT_OF_CARS;j++)
        {
            int dx=0, dy=0;
            while (dx*dx + dy*dy < 4* m_game.car_R*m_game.car_R)
             {
               m_game.cars[i].x += dx/10.0;
               m_game.cars[i].x += dy/10.0;
               m_game.cars[j].x -= dx/10.0;
               m_game.cars[j].y -= dy/10.0;
               dx = m_game.cars[i].x - m_game.cars[j].x;
               dy = m_game.cars[i].y - m_game.cars[j].y;
               if (!dx && !dy)
               {
                   break;
               }
             }
        }
    }
}

void GameScene::renderScene()
{
    static int index = 0;
    QString fileName = QDir::currentPath() + QDir::separator() + "screen" + QString::number(index++) + ".png";
    QRect rect = sceneRect().toAlignedRect();
    QImage image(rect.size(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter(&image);
    render(&painter);
    image.save(fileName);
    qDebug() << "saved " << fileName;
}

void GameScene::update()
{
    if (pause)
        return ;
    clear();
    QGraphicsPixmapItem* bgItem = new QGraphicsPixmapItem(m_bgPixmap);
    bgItem->setTransformationMode(Qt::SmoothTransformation);
    bgItem->setScale(2);
    addItem(bgItem);

    mutex.lock();
    carMovement();
    carCollision();

    if (m_game.cars[0].x > 320)
    {
        m_game.offsetX = m_game.cars[0].x-320;
    }
    if ( m_game.cars[0].y > 240)
    {
        m_game.offsetY = m_game.cars[0].y-240;
    }
    bgItem->setPos(-m_game.offsetX, -m_game.offsetY);

    for(int i=0; i < Game::COUNT_OF_CARS; i++)
    {
        QGraphicsPixmapItem* carItem = new QGraphicsPixmapItem(m_carPixmap[i]);
        carItem->setTransformationMode(Qt::SmoothTransformation);
        carItem->setScale(1);
        //42x69 average of pixmaps
        carItem->setTransformOriginPoint(21, 34);
        carItem->setPos(m_game.cars[i].x - m_game.offsetX, m_game.cars[i].y - m_game.offsetY);
        carItem->setRotation(m_game.cars[i].angle * 180/3.141593);
        addItem(carItem);
    }
    mutex.unlock();
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
    {
        m_upDir = true;
    }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
    {
        m_rightDir = true;
    }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
    {
        m_downDir = true;
    }
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
    {
        m_leftDir = true;
    }
        break;
    case Qt::Key_Z:
    {
        renderScene();
    }
    case Qt::Key_Space:
    {
        pause = !pause;
    }
        break;
    }
    QGraphicsScene::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
    {
        m_upDir = false;
    }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
    {
        m_rightDir = false;
    }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
    {
        m_downDir = false;
    }
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
    {
        m_leftDir = false;
    }
        break;
    }
    QGraphicsScene::keyReleaseEvent(event);
}
