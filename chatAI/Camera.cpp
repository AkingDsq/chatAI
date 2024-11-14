#include "Camera.h"
#include "chatAI.h"
#include <opencv2/opencv.hpp>

Camera::Camera(Ui::chatAIClass *ui)
	: ui(ui)
{
	open = ui->Open;
	connect(open, &QPushButton::clicked, this, &Camera::OpenCamera);
}

Camera::~Camera()
{}
void Camera::OpenCamera() {
	cv::Mat image;								// 创建一个空图像
	image = cv::imread("C:/Users/dsq2/Desktop/watermark.PNG");	// 读取输入图像
	if (image.empty()) {
		qDebug() << "Error: Could not open or find the image!";
		return;
	}
	cv::namedWindow("Image");					// 定义窗口
	cv::imshow("Image", image);					// 显示图像
	cv::waitKey(0);								// 键入的正数表示等待的毫秒数，0表示永远地等待按键
}