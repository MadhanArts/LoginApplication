#include "mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFont>
#include <dialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Image icon for username
    QLabel *lab=new QLabel(this);
    lab->setMinimumSize(70,70);
    lab->move(100,50);
    QPixmap pixx("E:/QtCreator/username_icon.jpg");
    lab->setPixmap(pixx.scaled(20,20));

    //Set image icon in center
    QLabel *mlabel=new QLabel(this);
    mlabel->move(180,10);
    mlabel->setAlignment(Qt::AlignHCenter);
    QPixmap pix("E:/QtCreator/login_icon.jpg");
    mlabel->setPixmap(pix.scaled(100, 50));

    //QLabel for username mainwindow.cpp*
    QLabel *unLabel=new QLabel("UserName",this);
    unLabel->setMinimumSize(70,50);
    unLabel->move(130,50);
    QPalette l1;
    l1.setColor(QPalette::WindowText,Qt::red);
    unLabel->setPalette(l1);

    //QLineEdit for username
    QLineEdit *unLineEdit=new QLineEdit(this);
    unLineEdit->setMinimumSize(200,50);
    unLineEdit->move(220,50);

    //set the lineedit border to red color
    unLineEdit->setStyleSheet("border: 2px solid red");

    //Image icon for password
    QLabel *labb=new QLabel(this);
    labb->setMinimumSize(200,50);
    labb->move(100,110);
    QPixmap pixxx("E:/QtCreator/password_icon.png");
    labb->setPixmap(pixxx.scaled(20,20));

    //QLabel for password
    QLabel *pwd=new QLabel("Password",this);
    pwd->setMinimumSize(70,50);
    pwd->move(130,110);
    QPalette l2;
    l2.setColor(QPalette::WindowText,Qt::green);
    pwd->setPalette(l2);

    //QLineEdit for password
    QLineEdit *pwdLineEdit=new QLineEdit(this);
    pwdLineEdit->setMinimumSize(200,50);
    pwdLineEdit->move(220,110);
    pwdLineEdit->setEchoMode(QLineEdit::Password);

    //set the lineedit border to green color
    pwdLineEdit->setStyleSheet("border: 2px solid green");

    //QLabel
    QLabel *account=new QLabel("Dont have account",this);
    account->setMinimumSize(120,50);
    account->move(130,170);

    //QPushButton for signup
    QFont button("Times",8,QFont::Bold);
    QPushButton *button1=new QPushButton("SignUp",this);
    button1->setFont(button);
    button1->move(250,180);
    connect(button1,&QPushButton::clicked,[=](){
        Dialog *dialog=new Dialog(this);
        int result = dialog->exec();
        if(result == QDialog::Rejected)
        {
            close();
        }
    });

    //QPushButton for Login
    QFont buttons("Times",18,QFont::Bold);
    QPushButton *button2=new QPushButton("Login",this);
    button2->setFont(buttons);
    button2->setMinimumSize(100, 70);
    button2->move(220,280);
    connect(button2,&QPushButton::clicked,[=](){
        if(unLineEdit->text() == "Madhan" && pwdLineEdit->text() == "123456")
        {
            QMessageBox::information(this, "Login", "Username and Password are correct");
        }
        else
        {
            QMessageBox::information(this, "Login", "Username and password are incorrect");
        }
    });

}

MainWindow::~MainWindow()
{
}

