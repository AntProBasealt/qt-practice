#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

QString emailRange = "^[A-Za-z0-9]+([A-Za-z0-9._-]+)*[A-Za-z0-9]@[A-Za-z0-9]+\.[A-Za-z]{2,4}$";
QRegExp emailRegex (emailRange);

QRegExpValidator *emailValidator = new QRegExpValidator(emailRegex, this);
ui->lineEdit->setValidator(emailValidator);

}
MainWindow::~MainWindow()
{
    delete ui;
}

