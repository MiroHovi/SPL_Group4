#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnLoginOK_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("pinCode",ui->textpinCode->text());

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(LoginSlot(QNetworkReply*)));
}

void Login::LoginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    loginManager->deleteLater();
}

