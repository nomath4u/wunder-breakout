#ifndef HARPERC_FINAL_H
#define HARPERC_FINAL_H

#include <QtGui/QMainWindow>
#include "ui_harperc_final.h"

class harperc_final : public QMainWindow
{
	Q_OBJECT

public:
	harperc_final(QWidget *parent = 0, Qt::WFlags flags = 0);
	~harperc_final();

private:
	Ui::harperc_finalClass ui;
};

#endif // HARPERC_FINAL_H
