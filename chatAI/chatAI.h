#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chatAI.h"
#include "test1.h"
#include "Camera.h"
class Camera;

class chatAI : public QMainWindow
{
    Q_OBJECT

public:
    chatAI(QWidget* parent = nullptr);
    ~chatAI();

private:
    Ui::chatAIClass *ui;
    Camera *camera;

    QPushButton *b1 ;
    QTextEdit *t1 ;
    QPushButton *voice ;
    QPushButton *word ;
    QPushButton *chat ;
    QPushButton *Cv ;

    QStackedWidget *pages;     //ҳ���л��ؼ�

public slots:
    void on_talkBegin_clicked();         //
    void on_stackedWidget_currentChanged(int index); // �л�ҳ��ʱ�����Ĳۺ���
};
