#include <ImageDisplay.h>

ImageDisplay::ImageDisplay()
{
	mImageViewerT = vtkSmartPointer<vtkImageViewer2>::New();
	mImageViewerC = vtkSmartPointer<vtkImageViewer2>::New();
	mImageViewerS = vtkSmartPointer<vtkImageViewer2>::New();
}

ImageDisplay::~ImageDisplay()
{

}

void ImageDisplay::DisplayTransversal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerT->SetSliceOrientationToXY();
	mImageViewerT->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
}

void ImageDisplay::DisplayCorona(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerC->SetSliceOrientationToXZ();
	mImageViewerC->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
}

void ImageDisplay::DisplaySagittal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerS->SetSliceOrientationToYZ();
	mImageViewerS->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
}

vtkSmartPointer<vtkImageViewer2> ImageDisplay::getImageViewerT()
{
	return mImageViewerT;
}

vtkSmartPointer<vtkImageViewer2> ImageDisplay::getImageViewerC()
{
	return mImageViewerC;
}

vtkSmartPointer<vtkImageViewer2> ImageDisplay::getImageViewerS()
{
	return mImageViewerS;
}