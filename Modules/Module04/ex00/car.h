#ifndef CAR_H
#define CAR_H

#include <cmath>
#include <QDebug>
#include <QObject>

class Car: public QObject
{
public:
  explicit Car(QObject *parent = nullptr);
  ~Car(){};
  Car(const Car& ref)
  {
      this->angle = ref.angle;
      this->n = ref.n;
      this->num_checkpoints = ref.num_checkpoints;
      for(int i = 0; i < this->num_checkpoints; ++i)
      {
          for(int j = 0; j < 2; ++j)
          {
              this->points[i][j] = ref.points[i][j];
          }
      }
      this->speed = ref.speed;
      this->x = ref.x;
      this->y = ref.y;
  }

  Car(int _num_checkpoints = 0, const int _points[8][2] = {})
      : speed(2), angle(0), n(0)
  {
        num_checkpoints = _num_checkpoints;
        for(int i = 0; i < num_checkpoints; ++i)
        {
            for(int j = 0; j < 2; ++j)
            {
                points[i][j] = _points[i][j];
            }
        }
  };

  Car& operator=(const Car& ref)
  {
    this->angle = ref.angle;
    this->n = ref.n;
    this->num_checkpoints = ref.num_checkpoints;
    for(int i = 0; i < this->num_checkpoints; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            this->points[i][j] = ref.points[i][j];
        }
    }
    this->speed = ref.speed;
    this->x = ref.x;
    this->y = ref.y;
    return *this;
  };

  void move()
   {
    x += sin(angle) * speed;
    y -= cos(angle) * speed;
   }

   float x,y,speed,angle; int n;
   int num_checkpoints;
   int points[8][2];

public slots:
  void findTarget()
  {
    float tx= points[n][0];
    float ty= points[n][1];
    float beta = angle-atan2(tx-x,-ty+y);
    if (sin(beta)<0)
    {
        angle+=0.005*speed;
    }
    else
    {
        angle-=0.005*speed;
    }
    if ((x-tx)*(x-tx)+(y-ty)*(y-ty)<25*25)
    {
        n=(n+1) % num_checkpoints;
    }
   }
};

#endif // CAR_H
