#include "DeepSeek_API_test.h"
#include "chatAI.h"

#include <QSettings>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

DeepSeek_API_test::DeepSeek_API_test(Ui::chatAIClass* ui)
	: ui(ui)
{
	question_text = ui->text1_4;
	answer_text = ui->text1_3;
	yes = ui->yes;
    networkManager = new QNetworkAccessManager(this);

	connect(yes, &QPushButton::clicked, this, &DeepSeek_API_test::on_yes_clicked);
}

DeepSeek_API_test::~DeepSeek_API_test()
{
}

void DeepSeek_API_test::on_yes_clicked() {
	answer_text->setPlainText("What is the capital of France?");
    QString question = question_text->toPlainText();
    if (question.isEmpty()) return;

    // 从安全位置读取API Key（示例从配置文件读取）
    QString appPath = "D:/git/work/chatAI/chatAI/x64/Debug";
    QSettings settings(appPath + "/config.ini", QSettings::IniFormat);

    QString apiKey = settings.value("API/Key").toString();

    // 构造请求
    QNetworkRequest request(QUrl("https://api.deepseek.com/v1/chat/completions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    // 构造请求体
    QJsonObject jsonBody;
    jsonBody["model"] = "deepseek-chat";
    jsonBody["temperature"] = 0.7;
    QJsonArray messages;
    messages.append(QJsonObject{ {"role", "user"}, {"content", question} });
    jsonBody["messages"] = messages;

    // 发送请求
    QNetworkReply* reply = networkManager->post(request, QJsonDocument(jsonBody).toJson());
    connect(reply, &QNetworkReply::finished, this, &DeepSeek_API_test::handleReplyFinished);
}

void DeepSeek_API_test::handleReplyFinished() {
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    yes->setEnabled(true);

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject root = doc.object();
        QString answer = root["choices"].toArray()[0].toObject()["message"].toObject()["content"].toString();
        answer_text->append("助手：" + answer);
    }
    else {
        answer_text->setText("错误: " + reply->errorString());
    }
    reply->deleteLater();
}
