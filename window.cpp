#include "window.h"
#include <QtGui>
#include <iostream>
#include "Lines.h"

MyWindow::MyWindow(void)
{
	
}

MyWindow::MyWindow(QApplication* app){
	this->app = app;
	button = new QPushButton("Quit");
	timer = new QTimer(this);
	
	mainLayout = new QVBoxLayout;
	
	/* Re-implement time permiting 
	mainLayout->addWidget(button);*/

	mainLayout->minimumSize();
	setLayout(mainLayout);
	Lines* line = new Lines(this);
	line->resize(800, 600);
	QObject::connect(button, SIGNAL(clicked()), this->app, SLOT(quit()));

	/*Set up paintEvent timer */
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(5); //update window every 5 milliseconds


}


MyWindow::~MyWindow(void)
{
}
