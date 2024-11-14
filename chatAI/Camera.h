#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chatAI.h"
#include "chatAI.h"

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camera(Ui::chatAIClass* ui);
    ~Camera();

private:
    Ui::chatAIClass* ui;
    QPushButton* open;

public slots:
    void OpenCamera();
};

