#include "harperc_final.h"
#include <QtGui/QApplication>
#include <QtGui>
#include "window.h"


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MyWindow window(&app);
	window.resize(800, 600);
	window.setWindowTitle("Wunder-Level");
	window.show();








	return app.exec();
}
