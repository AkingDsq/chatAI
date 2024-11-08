# chatAI 

## 首先需要下载python第三方库： 

pyAudio以及speechRecognition 

可以通过下列代码下载环境 

`pip install SpeechRecognition `

或者通过下方网址下载 SpeechRecognition-3.11.0-py2.py3-none-any.whl文件

https://pypi.org/project/SpeechRecognition/#files 

下载好后打开命令行进入到那个文件夹下，使用命令安装即可：

`cd SpeechRecognition-3.11.0-py2.py3-none-any.whl所在的文件夹 `

`pip install SpeechRecognition-3.11.0-py2.py3-none-any.whl`	 

pyAudio同理：

https://pypi.org/project/PyAudio/#files 

`cd PyAudio-0.2.14-cp311-cp311-win_amd64.whl所在的文件夹` 

`pip install PyAudio-0.2.14-cp311-cp311-win_amd64.whl` 

## 由于Qt + VS是通过c++进行编写开发的，所以想要调用python代码还需要配置python的环境在VS + Qt中 

首先找到python的根目录如C:\python，找到include以及libs文件夹，把这两个文件夹复制进项目根目录 

然后打开VS， 在项目 -> 属性 -> 链接器 -> 常规中的附加库目录，编辑并加入下列代码 

`$(SolutionDir)libs` 

![libs](https://github.com/AkingDsq/chatAI/blob/master/img/libs.png) 

在项目 -> 属性 -> 链接器 -> 常规中的附加依赖项，编辑并加入下列代码 

`python311.lib` 

![lib](https://github.com/AkingDsq/chatAI/blob/master/img/lib.png) 

在项目 -> 属性 -> C/C++ -> 常规中的附加包涵目录，编辑并加入下列代码 

`$(SolutionDir)include` 

![include](https://github.com/AkingDsq/chatAI/blob/master/img/include.png) 
现在环境就配置完成了。
