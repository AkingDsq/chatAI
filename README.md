# chatAI 

## 首先需要下载python第三方库(pyAudio以及speechRecognition以及OpenCv )： 

注意:此步骤必须在配置环境之前，如果顺序反了可能配置的环境中没有包涵这些第三方库

### speechRecognition:

可以通过下列代码下载环境 

`pip install SpeechRecognition `

或者通过下方网址下载 SpeechRecognition-3.11.0-py2.py3-none-any.whl文件

https://pypi.org/project/SpeechRecognition/#files 

下载好后打开命令行进入到那个文件夹下，使用命令安装即可：

`cd SpeechRecognition-3.11.0-py2.py3-none-any.whl所在的文件夹 `

`pip install SpeechRecognition-3.11.0-py2.py3-none-any.whl`	 

### pyAudio同理：

https://pypi.org/project/PyAudio/#files 

`cd PyAudio-0.2.14-cp311-cp311-win_amd64.whl所在的文件夹` 

`pip install PyAudio-0.2.14-cp311-cp311-win_amd64.whl` 

### OpenCv:

进入下面的网址下载opencv的源文件，可以直接将整个源文件粘贴在本项目的根目录 

https://github.com/opencv/opencv/releases

## (注意)由于Qt + VS是通过c++进行编写开发的，所以想要调用python代码还需要配置python的环境在VS + Qt中 

首先找到python的根目录如C:\python，找到include以及libs文件夹，把这两个文件夹复制进项目根目录 

然后打开VS， 

在项目 -> 属性 -> C/C++ -> 常规中的附加包含目录，编辑并加入下列代码 

`$(SolutionDir)include` 

![include](https://github.com/AkingDsq/chatAI/blob/master/img/include.png)  

在项目 -> 属性 -> 链接器 -> 常规中的附加库目录，编辑并加入下列代码 

`$(SolutionDir)libs` 

![libs](https://github.com/AkingDsq/chatAI/blob/master/img/libs.png)  

在项目 -> 属性 -> 链接器 -> 输入中的附加依赖项，编辑并加入下列代码 

`python311.lib` 

![lib](https://github.com/AkingDsq/chatAI/blob/master/img/lib.png) 

## 同理还需要在VS中配置OpenCv的环境 

### 注意：opencv4.10需要在项目根目录才可以直接使用下面代码，如果路径不同需要根据具体路径进行修改

首先需要配置系统环境

我的电脑->属性->高级系统设置->环境变量->系统环境->Path，新建一个地址（需要根据opencv4.10的具体地址修改） 

例：E:\git\work\chatAI\chatAI\opencv4.10\build\x64\vc16\bin

![opencv系统环境](https://github.com/AkingDsq/chatAI/blob/master/img/opencv系统环境.png)

然后打开VS，

在项目 -> 属性 -> C/C++ -> 常规中的附加包含目录，编辑并加入下列代码 

`$(SolutionDir)opencv4.10\build\include` 

`$(SolutionDir)opencv4.10\build\include\opencv2` 

在项目 -> 属性 -> 链接器 -> 常规中的附加库目录，编辑并加入下列代码 

`$(SolutionDir)opencv4.10\build\x64\vc16\lib`  

在项目 -> 属性 -> 链接器 -> 输入中的附加依赖项，编辑并加入下列代码 (注意：debug环境与release不同)(opencv版本不同命名不同)

`opencv_world4100d.lib`    （debug环境）

`opencv_world4100.lib`        (release环境)

## AI对话（接入的DeepSeek的API） 
1. 获取API Key
注册/登录DeepSeek账号
访问DeepSeek开发者平台（如https://platform.deepseek.com），完成账号注册或登录。
创建API Key
进入控制台或API管理页面。
找到生成API Key的选项。
生成后，复制并保存密钥。

2. 在代码中使用API Key
### VS+Qt配置QNetwork环境
在Qt中使用这个功能需要使用QNetworkAccessManager，需要配置环境：

在项目 -> 属性 -> C/C++ -> 常规中的附加包含目录，编辑并加入下列代码 

`$(QTDIR)\include\QtNetwork` 

![QNet1](https://github.com/AkingDsq/chatAI/blob/master/img/QNet1.png)
在项目 -> 属性 -> 链接器 -> 输入中的附加依赖项，编辑并加入下列代码 (注意：debug环境与release不同)(Qt版本不同命名不同)

`$(QTDIR)\lib\Qt6Networkd.lib`    （debug环境）

`$(QTDIR)\lib\Qt6Network.lib`        (release环境)

![QNet2](https://github.com/AkingDsq/chatAI/blob/master/img/QNet2.png)

# 现在环境就配置完成了。
