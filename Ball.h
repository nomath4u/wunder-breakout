#pragma once

#include <QtGui>
#include "window.h"


class Ball : public QWidget
{
  Q_OBJECT  
  public:
	Ball(void);
	~Ball(void);
	void reset(void);

	const static int Xcenter = 400;
	const static int Ypaddle = 500;
	const static int paddle_width = 100;
	const static int paddle_height = 10;
	const static int ball_width = 10;
	const static int ball_height = 10;

	QRect* rect;
	int speed;
	int xdirection;
	int ydirection;



  public slots:
	void move(); 
	

  protected:
	  void check_collision(void);
	
};

