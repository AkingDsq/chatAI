import os
import speech_recognition as sr

def my_record(rate=16000):
    r = sr.Recognizer()

    # 获取当前程序的根目录
    base_path = os.path.dirname(os.path.abspath(__file__))

    # 创建 temp 文件夹的路径
    temp_path = os.path.join(base_path, "temp")

    # 创建 temp 目录，如果不存在的话
    os.makedirs(temp_path, exist_ok=True)

    # 创建 voices 文件夹的路径
    voices_path = os.path.join(temp_path, "voices")

    # 创建 voices 目录，如果不存在的话
    os.makedirs(voices_path, exist_ok=True)

    # 定义完整的文件路径
    file_path = os.path.join(voices_path, "myvoices.wav")

    try:
        with sr.Microphone(sample_rate=rate) as source:
            print("请说些什么")
            audio = r.listen(source)
    except Exception as e:
        print("录音失败:", e)
        return

    try:
        with open(file_path, "wb") as f:
            f.write(audio.get_wav_data())
        print("录音完成，文件保存为:", file_path)
    except Exception as e:
        print("文件写入失败:", e)
        return
    return "录音完成"