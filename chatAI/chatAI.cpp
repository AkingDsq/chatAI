#include "chatAI.h"

chatAI::chatAI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	b1 = ui.talkBegin;
	t1 = ui.text1;

	pages = ui.stackedWidget;       // 实例化 stackedWidget
	connect(ui.voice, &QPushButton::clicked, this, [this]() { on_stackedWidget_currentChanged(0); }); // 绑定按钮点击事件为切换页面0
	connect(ui.word, &QPushButton::clicked, this, [this]() { on_stackedWidget_currentChanged(1); });  // 绑定按钮点击事件为切换页面1
	connect(ui.chatAI, &QPushButton::clicked, this, [this]() { on_stackedWidget_currentChanged(2); }); // 绑定按钮点击事件为切换页面2
}

chatAI::~chatAI()
{}
QString test() {
	Py_Initialize();//使用python之前，要调用Py_Initialize();这个函数进行初始化
	if (!Py_IsInitialized())
	{
		printf("初始化失败！");
		return 0;
	}
	else {
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.path.append('./')");//这一步很重要，修改Python路径


		PyObject* pModule = NULL;//声明变量
		PyObject* pFunc = NULL;// 声明变量

		pModule = PyImport_ImportModule("hello");//这里是要调用的文件名hello.py
		if (pModule == NULL)
		{
			return "没找到该Python文件";
		}
		else {
			pFunc = PyObject_GetAttrString(pModule, "add");//这里是要调用的函数名
			PyObject* args = Py_BuildValue("(ii)", 28, 103);//给python函数参数赋值

			PyObject* pRet = PyObject_CallObject(pFunc, args);//调用函数

			int res = 0;
			PyArg_Parse(pRet, "i", &res);//转换返回类型

			qDebug() << "res:" << res;//输出结果
			QString s = QString::number(res);
			return s;

		}
		Py_Finalize();//调用Py_Finalize，这个根Py_Initialize相对应的。
	}
}
void chatAI::on_talkBegin_clicked() {
	qDebug() << "按钮被点击了"; // 输出调试信息
    QString value = test(); // 调用 test() 函数
    t1->setText(value); // 改变 QTextEdit 的文本内容
}
void chatAI::on_stackedWidget_currentChanged(int index) {
	if (pages != nullptr) {
		if (index < pages->count()) pages->setCurrentIndex(index); // 切换到对应页面
		else {
			qDebug() << "pages" << index << "为空";
		}
	}
	else {
		qDebug() << "pages为空";
	}
}