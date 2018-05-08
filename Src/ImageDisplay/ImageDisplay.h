#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <ImageIO.h>

class ImageDisplay
{
public:
	ImageDisplay();
	~ImageDisplay();

	void DisplayTransversal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader);
	void DisplayCorona(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader);
	void DisplaySagittal(vtkSmartPointer<vtkDICOMImageReader> InputDicomSeriesReader);
	
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerT();
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerC();
	virtual vtkSmartPointer<vtkImageViewer2> getImageViewerS();

private:
	vtkSmartPointer<vtkImageViewer2> mImageViewerT;
	vtkSmartPointer<vtkImageViewer2> mImageViewerC;
	vtkSmartPointer<vtkImageViewer2> mImageViewerS;

};