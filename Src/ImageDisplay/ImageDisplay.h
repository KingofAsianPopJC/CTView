#pragma once
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkObjectFactory.h>
#include <vtkActor2D.h>
#include <vtkInteractorStyleImage.h>
#include <vtkTextMapper.h>
#include <vtkTextProperty.h>
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <ImageInteractor.h>
#include <ImageIO.h>
#include <sstream>

class ImageDisplay
{
public:
	ImageDisplay();
	~ImageDisplay();

	void DisplayTransversal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader);
	void DisplayCorona(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader);
	void DisplaySagittal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader);
	vtkSmartPointer<vtkActor2D> mSetTextProperty(vtkSmartPointer<vtkImageViewer2> ResImageViewer,vtkSmartPointer<vtkTextMapper> ResTextMapper);
	
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerT();
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerC();
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerS();
	virtual vtkSmartPointer<vtkTextMapper> getTextMappperT();
	virtual vtkSmartPointer<vtkTextMapper> getTextMappperC();
	virtual vtkSmartPointer<vtkTextMapper> getTextMappperS();

private:
	vtkSmartPointer<vtkImageViewer2> mImageViewerT;
	vtkSmartPointer<vtkImageViewer2> mImageViewerC;
	vtkSmartPointer<vtkImageViewer2> mImageViewerS;
	vtkSmartPointer<vtkTextMapper> mTextMapperT;
	vtkSmartPointer<vtkTextMapper> mTextMapperC;
	vtkSmartPointer<vtkTextMapper> mTextMapperS;
	vtkSmartPointer<vtkActor2D> mTextActorT;
	vtkSmartPointer<vtkActor2D> mTextActorC;
	vtkSmartPointer<vtkActor2D> mTextActorS;
};