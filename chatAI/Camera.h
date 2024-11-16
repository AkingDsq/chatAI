#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chatAI.h"
#include "chatAI.h"

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QTimer>

using namespace cv;
using namespace std;

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camera(Ui::chatAIClass* ui);
    ~Camera();
    //MatתQLabel
    QImage MatImageToQt(const Mat& src);

private:
    Ui::chatAIClass* ui;
    QLabel* camera;

    QAction* openAction;
    QAction* closeAction;

    VideoCapture cap;
    Mat src_image;
    QTimer* timer;
    QImage* image;

public slots:
    void readFarme();
    void OpenCamera();
    void CloseCamera();
};

