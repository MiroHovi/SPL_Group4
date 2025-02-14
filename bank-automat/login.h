#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnLoginOK_clicked();
    void LoginSlot (QNetworkReply *reply);

private:
    Ui::Login *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // LOGIN_H
