#include "Camera.h"
#include "chatAI.h"

chatAI::chatAI(QWidget *parent)
    : QMainWindow(parent)
	, ui(new Ui::chatAIClass)
{
    ui->setupUi(this);
	camera = new Camera(ui); // 实例化

	b1 = ui->talkBegin;
	t1 = ui->text1;
	voice = ui->voice;
	word = ui->word;
	chat = ui->chatAI;
	Cv = ui->Cv;

	pages = ui->stackedWidget;       // 实例化 stackedWidget
	connect(voice, &QPushButton::clicked, this, [this]() { on_stackedWidget_currentChanged(0); }); // 绑定按钮点击事件为切换页面0
	connect(word, &QPushButton::clicked, this, [this]() { on_stackedWidget_currentChanged(1); });  // 绑定按钮点击事件为切换页面1
	connect(chat, &QPushButton::clicked, this, [this]() { on_stackedWidget_currentChanged(2); }); // 绑定按钮点击事件为切换页面2
	connect(Cv, &QPushButton::clicked, this, [this]() { on_stackedWidget_currentChanged(3); }); // 绑定按钮点击事件为开始对话
}

chatAI::~chatAI()
{}
QString test() {
	Py_Initialize();//使用python之前，要调用Py_Initialize();这个函数进行初始化
	if (!Py_IsInitialized())
	{
		return "初始化失败！";
	}
	else {
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.path.append('./')");//这一步很重要，修改Python路径


		PyObject* pModule = NULL;//声明变量
		PyObject* pFunc = NULL;// 声明变量

		pModule = PyImport_ImportModule("voice_test");//这里是要调用的文件名hello.py
		if (pModule == NULL)
		{
			return "没找到该Python文件";
		}
		else {
			pFunc = PyObject_GetAttrString(pModule, "my_record");//这里是要调用的函数名
			PyObject* args = Py_BuildValue("(i)", 16000);//给python函数参数赋值

			PyObject* pRet = PyObject_CallObject(pFunc, args);//调用函数

			QString res = "null";
			PyArg_Parse(pRet, "s", &res);//转换返回类型

			qDebug() << "res:" << res;//输出结果
			//QString s = QString::number(res);
			return res;

		}
		Py_Finalize();//调用Py_Finalize，这个根Py_Initialize相对应的。
	}
}
void chatAI::on_talkBegin_clicked() {
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