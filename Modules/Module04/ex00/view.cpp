#include "view.h"
#include "gamescene.h"

View::View()
    : QGraphicsView{}, m_gameScene(new GameScene(this))
{
    setScene(m_gameScene);
    //resize(m_gameScene->sceneRect().width()+2, m_gameScene->sceneRect().height()+2);
    resize(1440, 1400);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
