#pragma once
#include<vtkSmartPointer.h>
#include<vtkDICOMImageReader.h>

class ImageIO
{
public:
	ImageIO();
	~ImageIO();

	void readDicomSeries(std::string &InputDirectory);
	virtual vtkSmartPointer<vtkDICOMImageReader> getDicomSeriesReader();

private:
	vtkSmartPointer<vtkDICOMImageReader> mDicomSeriesReader;
};