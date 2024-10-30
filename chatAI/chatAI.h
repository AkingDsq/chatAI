#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chatAI.h"
#include "test1.h"

class chatAI : public QMainWindow
{
    Q_OBJECT

public:
    chatAI(QWidget* parent = nullptr); 
    ~chatAI();

private:
    Ui::chatAIClass ui;

    QPushButton *b1 ;
    QTextEdit *t1 ;

public slots:
    void on_button_clicked();
};
