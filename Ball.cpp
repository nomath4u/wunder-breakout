
#include <QtGui>
#include "Ball.h"

Ball::Ball(void){
	this->rect = new QRect(Xcenter, (Ypaddle - 200), ball_width, ball_height);
}



Ball::~Ball(void)
{
}


void Ball::move(){
	this->rect->translate(this->speed * this->xdirection, this->speed * this->ydirection);
}

void Ball::reset(){
	this->rect->moveTo(Xcenter, (Ypaddle - 200));
}
