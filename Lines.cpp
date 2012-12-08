#include "Lines.h"
#include <QtGui>
#include "SimpleSerial.hpp"
#include <iostream>
#include <string>
#include "Ball.h"
#include <vector>

#define BAUD 9600
#define MADC 191 //median adc value
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1


Lines::Lines(QWidget *parent)
	: QWidget(parent)
{
	 this->parent = parent;

	 /*Create Serial Object*/
	 try{
		this->wunder =  new SimpleSerial("COM3", BAUD);
	 }catch(boost::system::system_error& e){
		std::cerr<<tmp<<": Error: "<<std::endl;//<<e.what()<<std::endl;
	 }

	 /*Create centered paddle. Draw with translated */
	 this->paddle = new QRect ((Xcenter - (paddle_width / 2)), (Ypaddle - (paddle_height /2)), paddle_width, paddle_height);
	 this->paddletranslated = new QRect();
	 this->leftboundary = new QRect(0, 0, 30 , 600);
	 this->topboundary = new QRect(0, 0, 800, 30);
	 this->rightboundary = new QRect(770, 0 , 30, 800);
	 this->bottomboundary = new QRect(0, 550, 800, 30);

	 this->invisible = new QColor(0,0,0,0);
	 this->ball = new Ball();
	 this->timer = new QTimer(this);

	 this->ball->speed = 21;
	 this->ball->xdirection = LEFT;
	 this->ball->ydirection = DOWN;

	 QObject::connect(timer, SIGNAL(timeout()), this->ball, SLOT(move()));
	 timer->start(5); //Move ball every 5 milliseconds

	 createBlocks();
}

		

void Lines::paintEvent(QPaintEvent *e){
	Q_UNUSED(e);
	QPainter qp(this);
	/*Create serial object */
	try { 

			// Make a SimpleSerial object with the parameter for your Wunderboard/OS
			
			
			this->tmp = this->wunder->readLine();

			/*handles odd SimpleSerial Problems*/
			if(this->tmp.length() != 3)
				adcval = MADC; //send it back to the middle
			else
				adcval = atoi(this->tmp.c_str()) - MADC ;

		} catch(boost::system::system_error& e)
		{
			std::cerr<<tmp<<": Error: "<<std::endl;//<<e.what()<<std::endl;
		}
	qp.setWindow(0,0, 800, 600);
	drawBoundary(&qp);
	drawPaddle(&qp);
	drawBall(&qp);
	drawBlocks(&qp);
	check_collision();

	
}


void Lines::drawPaddle(QPainter *qp){
		QPen pen(Qt::black, 10, Qt::SolidLine);
		qp->setPen(pen);
		*this->paddletranslated = this->paddle->translated((24*adcval) ,0);
		qp->drawRect(*this->paddletranslated); //draw a translated version of the paddle
}

void Lines::drawBall(QPainter *qp){
		QPen pen (Qt::blue, 10, Qt::SolidLine);
		qp->setPen(pen);
		qp->drawRect(*this->ball->rect);
}

void Lines::drawBoundary(QPainter *qp){
	QPen pen (Qt::black, 10, Qt::SolidLine);
	qp->setPen(pen);
	qp->fillRect(*this->leftboundary, Qt::black); //Left Boundary
	qp->fillRect(*this->topboundary, Qt::black); // Top Boundary
	qp->fillRect(*this->rightboundary, Qt::black); // Right Boundary
	pen.setColor(*this->invisible); //Make the bottom invisible
	qp->setPen(pen);
	qp->drawRect(*this->bottomboundary); //Should be invisible after testing
}

/*Checks all collisions with the ball and changes its velocity accordingly and removes blocks if required*/
void Lines::check_collision(){

	/*Paddle*/
	if(this->paddletranslated->intersects(*this->ball->rect))
		this->ball->ydirection = -1;

	/*World Boundaries*/
	if(this->leftboundary->intersects(*this->ball->rect))
		this->ball->xdirection = 1;

	if(this->topboundary->intersects(*this->ball->rect))
		this->ball->ydirection = 1;

	if(this->rightboundary->intersects(*this->ball->rect))
		this->ball->xdirection = -1;

	if(this->bottomboundary->intersects(*this->ball->rect))
		this->ball->reset();

	/*Breakout Blocks*/
	if(this->block11->intersects(*this->ball->rect)){
		this->ball->ydirection *= -1;
		this->block11->setRect(0,0,0,0);
	}
	if(this->block12->intersects(*this->ball->rect)){
		this->ball->ydirection *= -1;
		this->block12->setRect(0,0,0,0);
	}
	if(this->block13->intersects(*this->ball->rect)){
		this->ball->ydirection *= -1;
		this->block13->setRect(0,0,0,0);
	}

	if(this->block14->intersects(*this->ball->rect)){
		this->ball->ydirection *= -1;
		this->block14->setRect(0,0,0,0);
	}
	if(this->block15->intersects(*this->ball->rect)){
		this->ball->ydirection *= -1;
		this->block15->setRect(0,0,0,0);
	}
	if(this->block16->intersects(*this->ball->rect)){
		this->ball->ydirection *= -1;
		this->block16->setRect(0,0,0,0);
	}
}

void Lines::createBlocks(){
	this->block11 = new QRect(50,40, this->paddle_width, this->paddle_height);
	this->block12 = new QRect(175,40, this->paddle_width, this->paddle_height);
	this->block13 = new QRect (300, 40, this->paddle_width, this->paddle_height);
	this->block14 = new QRect(425,40, this->paddle_width, this->paddle_height);
	this->block15 = new QRect(550,40, this->paddle_width, this->paddle_height);
	this->block16 = new QRect (675, 40, this->paddle_width, this->paddle_height);
	


}

void Lines::drawBlocks(QPainter *qp){
	QPen pen (Qt::red , 10, Qt::SolidLine);
	qp->setPen(pen);
	qp->drawRect(*this->block11);
	qp->drawRect(*this->block12);
	qp->drawRect(*this->block13);
	qp->drawRect(*this->block14);
	qp->drawRect(*this->block15);
	qp->drawRect(*this->block16);

}