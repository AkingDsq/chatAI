#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chatAI.h"

class chatAI : public QMainWindow
{
    Q_OBJECT

public:
    chatAI(QWidget *parent = nullptr);
    ~chatAI();

private:
    Ui::chatAIClass ui;
};
