#include <ImageDisplay.h>

ImageDisplay::ImageDisplay()
{
	mImageViewerT = vtkSmartPointer<vtkImageViewer2>::New();
	mImageViewerC = vtkSmartPointer<vtkImageViewer2>::New();
	mImageViewerS = vtkSmartPointer<vtkImageViewer2>::New();
	mTextMapperT = vtkSmartPointer<vtkTextMapper>::New();
	mTextMapperC = vtkSmartPointer<vtkTextMapper>::New();
	mTextMapperS = vtkSmartPointer<vtkTextMapper>::New();
	mTextActorT = vtkSmartPointer<vtkActor2D>::New();
	mTextActorC = vtkSmartPointer<vtkActor2D>::New();
	mTextActorS = vtkSmartPointer<vtkActor2D>::New();
}

ImageDisplay::~ImageDisplay()
{

}

void ImageDisplay::DisplayTransversal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerT->SetSliceOrientationToXY();
	mImageViewerT->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
	mImageViewerT->GetRenderer()->AddActor2D(this->mSetTextProperty(mImageViewerT, mTextMapperT));
}

void ImageDisplay::DisplayCorona(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerC->SetSliceOrientationToXZ();
	mImageViewerC->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
	mImageViewerC->GetRenderer()->AddActor2D(this->mSetTextProperty(mImageViewerC, mTextMapperC));
}

void ImageDisplay::DisplaySagittal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader)
{
	mImageViewerS->SetSliceOrientationToYZ();
	mImageViewerS->SetInputConnection(InputDicomSeriesReader->GetOutputPort());
	mImageViewerS->GetRenderer()->AddActor2D(this->mSetTextProperty(mImageViewerS, mTextMapperS));
}

vtkSmartPointer<vtkActor2D> ImageDisplay::mSetTextProperty(vtkSmartPointer<vtkImageViewer2> ResImageViewer,vtkSmartPointer<vtkTextMapper> ResTextMapper)
{
	vtkSmartPointer<vtkTextProperty> mText = vtkSmartPointer<vtkTextProperty>::New();
	mText->SetFontFamilyToCourier();
	mText->SetFontSize(20);
	mText->SetVerticalJustificationToBottom();
	mText->SetJustificationToLeft();
	std::string msg = StatusMessage::Format(ResImageViewer->GetSliceMin(), ResImageViewer->GetSliceMax());
	ResTextMapper->SetInput(msg.c_str());
	ResTextMapper->SetTextProperty(mText);

	if (ResTextMapper == mTextMapperT)
	{
		mTextActorT->SetMapper(ResTextMapper);
		mTextActorT->SetPosition(15, 10);
		return mTextActorT;
	}
	else if (ResTextMapper == mTextActorC)
	{
		mTextActorC->SetMapper(ResTextMapper);
		mTextActorC->SetPosition(15, 10);
		return mTextActorC;
	}
	else
	{
		mTextActorS->SetMapper(ResTextMapper);
		mTextActorS->SetPosition(15, 10);
		return mTextActorS;
	}
	
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

vtkSmartPointer<vtkTextMapper> ImageDisplay::getTextMappperT()
{
	return mTextMapperT;
}

vtkSmartPointer<vtkTextMapper> ImageDisplay::getTextMappperC()
{
	return mTextMapperC;
}

vtkSmartPointer<vtkTextMapper> ImageDisplay::getTextMappperS()
{
	return mTextMapperS;
}



