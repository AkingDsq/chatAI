#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chatAI.h"
#include "chatAI.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>

class DeepSeek_API_test : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeepSeek_API_test(Ui::chatAIClass* ui);
    ~DeepSeek_API_test();

    QTextEdit * question_text;
    QTextEdit * answer_text;
    QPushButton * yes;

private:
    Ui::chatAIClass* ui;
    QNetworkAccessManager* networkManager;


public slots:
    void on_yes_clicked();
    void handleReplyFinished();
};

