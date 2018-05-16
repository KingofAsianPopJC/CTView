#include <QtWidgets/QMainWindow>
#include <ui_InterFace.h>
#include <ImageIO.h>
#include <ImageDisplay.h>
#include <ImageInteractor.h>

class Interface : public QMainWindow
{
	Q_OBJECT

public:
	Interface(QWidget *parent = Q_NULLPTR);
	~Interface();

private:	
	Ui::CTViewer ui;
	ImageDisplay mImageDisplay;
	ImageIO mImageSeriesInput;
	void invokePress();
	void mDisplayTransversal();
	void mDisplayCorana();
	void mDisplaySagittal();

private slots:
    void slotOpenFile();
	void slotSaveFile();
	void slotTransversalFrameChange(int value);
	void slotCoronaFrameChange(int value);
	void slotSagittalFrameChange(int value);
};