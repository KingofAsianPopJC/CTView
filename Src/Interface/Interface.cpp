#include "Interface.h"
#include <QFileDialog>

Interface::Interface(QWidget *parent):QMainWindow(parent)
{
	ui.setupUi(this);
	invokePress();
	mImageInteractorT = vtkSmartPointer<ImageInteractor>::New();
	mImageInteractorC = vtkSmartPointer<ImageInteractor>::New();
	mImageInteractorS = vtkSmartPointer<ImageInteractor>::New();
}

Interface::~Interface()
{

}

void Interface::invokePress()
{
	connect(ui.Open, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
	connect(ui.Save, SIGNAL(triggered()), this, SLOT(slotSaveFile()));
	connect(ui.ChangeTransversal, SIGNAL(valueChanged(int)), this, SLOT(slotTransversalFrameChange(int)));
	connect(ui.ChangeCorona, SIGNAL(valueChanged(int)), this, SLOT(slotCoronaFrameChange(int)));
	connect(ui.ChangeSagittal, SIGNAL(valueChanged(int)), this, SLOT(slotSagittalFrameChange(int)));
}

void Interface::mDisplayTransversal()
{
	mImageDisplay.DisplayTransversal(mImageSeriesInput.getDicomSeriesReader());
	mImageInteractorT->SetImageViewer(mImageDisplay.getImageViewerT());
	mImageInteractorT->SetStatusMapper(mImageDisplay.getTextMappperT());
	mImageDisplay.getImageViewerT()->SetRenderWindow(ui.DisplayWindow_1->GetRenderWindow());
	mImageDisplay.getImageViewerT()->SetupInteractor(ui.DisplayWindow_1->GetInteractor());
	ui.DisplayWindow_1->GetInteractor()->SetInteractorStyle(mImageInteractorT);
	mImageDisplay.getImageViewerT()->Render();
	mImageDisplay.getImageViewerT()->GetRenderer()->ResetCamera();
	mImageDisplay.getImageViewerT()->Render();
	ui.DisplayWindow_1->GetInteractor()->Start();
}

void Interface::mDisplayCorana()
{
	mImageDisplay.DisplayCorona(mImageSeriesInput.getDicomSeriesReader());
	mImageInteractorC->SetImageViewer(mImageDisplay.getImageViewerC());
	mImageInteractorC->SetStatusMapper(mImageDisplay.getTextMappperC());
	mImageDisplay.getImageViewerC()->SetRenderWindow(ui.DisplayWindow_2->GetRenderWindow());
	mImageDisplay.getImageViewerC()->SetupInteractor(ui.DisplayWindow_2->GetInteractor());
	ui.DisplayWindow_2->GetInteractor()->SetInteractorStyle(mImageInteractorC);
	mImageDisplay.getImageViewerC()->Render();
	mImageDisplay.getImageViewerC()->GetRenderer()->ResetCamera();
	mImageDisplay.getImageViewerC()->Render();
	ui.DisplayWindow_2->GetInteractor()->Start();
}

void Interface::mDisplaySagittal()
{
	mImageDisplay.DisplaySagittal(mImageSeriesInput.getDicomSeriesReader());
	mImageInteractorS->SetImageViewer(mImageDisplay.getImageViewerS());
	mImageInteractorS->SetStatusMapper(mImageDisplay.getTextMappperS());
	mImageDisplay.getImageViewerS()->SetRenderWindow(ui.DisplayWindow_3->GetRenderWindow());
	mImageDisplay.getImageViewerS()->SetupInteractor(ui.DisplayWindow_3->GetInteractor());
	ui.DisplayWindow_3->GetInteractor()->SetInteractorStyle(mImageInteractorS);
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
	ui.ChangeTransversal->setMaximum(mImageDisplay.getImageViewerT()->GetSliceMax());
	mImageDisplay.getImageViewerT()->SetSlice(value);
	std::string msg = StatusMessage::Format(value, mImageDisplay.getImageViewerT()->GetSliceMax());
	mImageDisplay.getTextMappperT()->SetInput(msg.c_str());
	mImageDisplay.getImageViewerT()->Render();
}

void Interface::slotCoronaFrameChange(int value)
{
	ui.ChangeCorona->setMaximum(mImageDisplay.getImageViewerC()->GetSliceMax());
	mImageDisplay.getImageViewerC()->SetSlice(value);
	std::string msg = StatusMessage::Format(value, mImageDisplay.getImageViewerC()->GetSliceMax());
	mImageDisplay.getTextMappperC()->SetInput(msg.c_str());
	mImageDisplay.getImageViewerC()->Render();
}

void Interface::slotSagittalFrameChange(int value)
{
	ui.ChangeSagittal->setMaximum(mImageDisplay.getImageViewerS()->GetSliceMax());
	mImageDisplay.getImageViewerS()->SetSlice(value);
	std::string msg = StatusMessage::Format(value, mImageDisplay.getImageViewerS()->GetSliceMax());
	mImageDisplay.getTextMappperS()->SetInput(msg.c_str());
	mImageDisplay.getImageViewerS()->Render();
}
