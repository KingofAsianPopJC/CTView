#include "Interface.h"
#include <QtWidgets/QApplication>

vtkStandardNewMacro(ImageInteractor);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Interface w;
	w.show();
	return a.exec();
}

