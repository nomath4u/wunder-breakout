#pragma once

#include <QWidget>
#include <QtGui>
#include "SimpleSerial.hpp"
#include "Ball.h"
#include <vector>

	class Lines : public QWidget
	{
		Q_OBJECT  

	 public:
		Lines(QWidget *parent = 0);
		QWidget* parent;
		SimpleSerial* wunder;
		std::string tmp;
		QRect *paddletranslated;
		QRect *leftboundary;
		QRect *rightboundary;
		QRect *topboundary;
		QRect *bottomboundary; //Used for resetting/dying
		QColor *invisible;


		const static int Xcenter = 400;
		const static int Ypaddle = 500;
		const static int paddle_width = 100;
		const static int paddle_height = 10;
		const static int ball_width = 10;
		const static int ball_height = 10;


	

	  protected:
		bool pressed;
		int adcval;
		QRect *paddle;
		Ball *ball;
		QTimer *timer;
		std::vector<QRect*> blocks;

		/*Blocks*/
		QRect *block11;
		QRect *block12;
		QRect *block13;
		QRect *block14;
		QRect *block15;
		QRect *block16;
		QRect *block17;


		void paintEvent(QPaintEvent *event);
		void createBlocks();
		void drawPaddle(QPainter *qp);
		void drawBall(QPainter *qp);
		void drawBoundary(QPainter *qp);
		void drawBlocks(QPainter *qp);
		void check_collision(void);

	};

