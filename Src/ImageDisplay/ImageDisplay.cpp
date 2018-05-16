#include <ImageDisplay.h>

ImageDisplay::ImageDisplay()
{
	mImageViewerT = vtkSmartPointer<vtkImageViewer2>::New();
	mImageViewerC = vtkSmartPointer<vtkImageViewer2>::New();
	mImageViewerS = vtkSmartPointer<vtkImageViewer2>::New();
	mText = vtkSmartPointer<vtkTextProperty>::New();
	mTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	mTextActor = vtkSmartPointer<vtkActor2D>::New();
	myImageInteractorStyle = vtkSmartPointer<ImageInteractor>::New();
}

ImageDisplay::~ImageDisplay()
{

}

void ImageDisplay::DisplayTransversal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerT->SetSliceOrientationToXY();
	mImageViewerT->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
	mImageViewerT->GetRenderer()->AddActor2D(this->mSetTextProperty(mImageViewerT));
}

void ImageDisplay::DisplayCorona(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerC->SetSliceOrientationToXZ();
	mImageViewerC->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
	mImageViewerC->GetRenderer()->AddActor2D(this->mSetTextProperty(mImageViewerC));
}

void ImageDisplay::DisplaySagittal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerS->SetSliceOrientationToYZ();
	mImageViewerS->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
	mImageViewerS->GetRenderer()->AddActor2D(this->mSetTextProperty(mImageViewerC));
}

vtkSmartPointer<vtkActor2D> ImageDisplay::mSetTextProperty(vtkSmartPointer<vtkImageViewer2> ResImageViewer)
{
	mText->SetFontFamilyToCourier();
	mText->SetFontSize(20);
	mText->SetVerticalJustificationToBottom();
	mText->SetJustificationToLeft();
	std::string msg = StatusMessage::Format(ResImageViewer->GetSliceMin(), ResImageViewer->GetSliceMax());
	mTextMapper->SetInput(msg.c_str());
	mTextMapper->SetTextProperty(mText);

	mTextActor->SetMapper(mTextMapper);
	mTextActor->SetPosition(15, 10);
	
	return mTextActor;
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

vtkSmartPointer<ImageInteractor> ImageDisplay::getImageInteractorStyle()
{
	return myImageInteractorStyle;
}
