#include "ImageIO.h"

ImageIO::ImageIO()
{
	mDicomSeriesReader = vtkSmartPointer<vtkDICOMImageReader>::New();
}

ImageIO::~ImageIO()
{

}

void ImageIO::readDicomSeries(std::string &InputDirectory)
{
	mDicomSeriesReader->SetDirectoryName(InputDirectory.c_str());
	mDicomSeriesReader->Update();
}

vtkSmartPointer<vtkDICOMImageReader> ImageIO::getDicomSeriesReader()
{
	return mDicomSeriesReader;
}
