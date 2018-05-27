#ifndef IMAGEINTERACTOR_H
#define IMAGEINTERACTOR_H// !IMAGEINTERACTOR_H

#include <vtkSmartPointer.h>
#include <vtkObjectFactory.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkTextMapper.h>
#include <vtkSetGet.h>
#include <vtkImageViewer2.h>
#include <sstream>


class StatusMessage {
public:
	static std::string Format(int slice, int maxSlice) {
		std::stringstream tmp;
		tmp << "Slice Number  " << slice + 1 << "/" << maxSlice + 1;
		return tmp.str();
	}
};

class ImageInteractor : public vtkInteractorStyleImage
{
public:
	static ImageInteractor* New();
	vtkTypeMacro(ImageInteractor, vtkInteractorStyleImage);
	ImageInteractor();
	~ImageInteractor();


protected:
	vtkSmartPointer<vtkImageViewer2> _ImageViewer;
	vtkSmartPointer<vtkTextMapper> _StatusMapper;
	int _Slice;
	int _MinSlice;
	int _MaxSlice;

public:
	void SetImageViewer(vtkSmartPointer<vtkImageViewer2> imageViewer);

	void SetStatusMapper(vtkSmartPointer<vtkTextMapper> statusMapper);


protected:
	void MoveSliceForward();

	void MoveSliceBackward();

	virtual void OnKeyDown();

	virtual void OnMouseWheelForward();

	virtual void OnMouseWheelBackward();
};

//vtkStandardNewMacro(ImageInteractor);

#endif IMAGEINTERACTOR_H