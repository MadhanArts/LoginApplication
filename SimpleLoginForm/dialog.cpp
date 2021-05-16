#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_confirm_button_clicked()
{
    QString email = ui->email_lineEdit->text();
    QString pwd = ui->password_lineEdit->text();
    QString confirmPwd = ui->confirmPassword_lineEdit->text();
    qDebug() << "Email :" << email;
    qDebug() << "Password :" << pwd;
    qDebug() << "Confirm Password :" << confirmPwd;

    if(!email.isEmpty() && !pwd.isEmpty() && !confirmPwd.isEmpty())
    {

    }
    else
    {
        qDebug() << "One Field is Empty";
    }
}

void Dialog::on_exit_button_clicked()
{
    close();
}
