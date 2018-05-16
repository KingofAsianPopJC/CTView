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
	vtkSmartPointer<vtkActor2D> mSetTextProperty(vtkSmartPointer<vtkImageViewer2> ResImageViewer);
	
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerT();
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerC();
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerS();
	virtual vtkSmartPointer<ImageInteractor> getImageInteractorStyle();

private:
	vtkSmartPointer<vtkImageViewer2> mImageViewerT;
	vtkSmartPointer<vtkImageViewer2> mImageViewerC;
	vtkSmartPointer<vtkImageViewer2> mImageViewerS;
	vtkSmartPointer<vtkTextProperty> mText;
	vtkSmartPointer<vtkTextMapper> mTextMapper;
	vtkSmartPointer<vtkActor2D> mTextActor;
	vtkSmartPointer<ImageInteractor> myImageInteractorStyle;
};