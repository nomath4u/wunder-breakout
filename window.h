#pragma once

#include <QtGui>

class MyWindow : public QWidget
{
	Q_OBJECT
public:
	MyWindow(void);
	MyWindow(QApplication*);
	~MyWindow(void);

protected:
	QPushButton *button;
	QVBoxLayout *mainLayout;
	QApplication *app;
	QSize *size;
	QTimer *timer;
	


};

