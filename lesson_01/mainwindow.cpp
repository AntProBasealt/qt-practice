#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

QString emailRange = "([a-z0-9_-]+.)*[a-z0-9_-]+@[a-z0-9_-]+(.[a-z0-9_-])*.[a-z]{2,6}";
QRegExp emailRegex ("^" + emailRange + "$");

QRegExpValidator *emailValidator = new QRegExpValidator(emailRegex, this);
ui->lineEdit->setValidator(emailValidator);

}
MainWindow::~MainWindow()
{
    delete ui;
}

