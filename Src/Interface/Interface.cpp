#include "Interface.h"
#include <QFileDialog>

Interface::Interface(QWidget *parent):QMainWindow(parent)
{
	ui.setupUi(this);
	invokePress();
}

Interface::~Interface()
{

}

void Interface::invokePress()
{
	connect(ui.Open, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
	connect(ui.Save, SIGNAL(triggered()), this, SLOT(slotSaveFile()));
//	connect(ui.ChangeTransversal, SIGNAL(valueChange()), this, SLOT(slotTransversalFrameChange));
//	connect(ui.ChangeCorona, SIGNAL(valueChange()), this, SLOT(slotCoronaFrameChange()));
//	connect(ui.ChangeSagittal, SIGNAL(valueChange()), this, SLOT(slotSagittalFrameChange()));
}

void Interface::mDisplayTransversal()
{
	mImageDisplay.DisplayTransversal(mImageSeriesInput.getDicomSeriesReader());
	mImageDisplay.getImageViewerT()->SetRenderWindow(ui.DisplayWindow_1->GetRenderWindow());
	mImageDisplay.getImageViewerT()->SetupInteractor(ui.DisplayWindow_1->GetInteractor());
	mImageDisplay.getImageViewerT()->Render();
	mImageDisplay.getImageViewerT()->GetRenderer()->ResetCamera();
	mImageDisplay.getImageViewerT()->Render();
	ui.DisplayWindow_1->GetInteractor()->Start();
}

void Interface::mDisplayCorana()
{
	mImageDisplay.DisplayCorona(mImageSeriesInput.getDicomSeriesReader());
	mImageDisplay.getImageViewerC()->SetRenderWindow(ui.DisplayWindow_2->GetRenderWindow());
	mImageDisplay.getImageViewerC()->SetupInteractor(ui.DisplayWindow_2->GetInteractor());
	mImageDisplay.getImageViewerC()->Render();
	mImageDisplay.getImageViewerC()->GetRenderer()->ResetCamera();
	mImageDisplay.getImageViewerC()->Render();
	ui.DisplayWindow_2->GetInteractor()->Start();
}

void Interface::mDisplaySagittal()
{
	mImageDisplay.DisplaySagittal(mImageSeriesInput.getDicomSeriesReader());
	mImageDisplay.getImageViewerS()->SetRenderWindow(ui.DisplayWindow_3->GetRenderWindow());
	mImageDisplay.getImageViewerS()->SetupInteractor(ui.DisplayWindow_3->GetInteractor());
	mImageDisplay.getImageViewerS()->Render();
	mImageDisplay.getImageViewerS()->GetRenderer()->ResetCamera();
	mImageDisplay.getImageViewerS()->Render();
	ui.DisplayWindow_3->GetInteractor()->Start();
}

void Interface::slotOpenFile()
{
	QString DirectoryPath = QFileDialog::getExistingDirectory();
	mImageSeriesInput.readDicomSeries(DirectoryPath.toStdString());
	mDisplayTransversal();
	mDisplayCorana();
	mDisplaySagittal();
}

void Interface::slotSaveFile()
{
}

void Interface::slotTransversalFrameChange(int value)
{
}

void Interface::slotCoronaFrameChange(int value)
{
}

void Interface::slotSagittalFrameChange(int value)
{
}
