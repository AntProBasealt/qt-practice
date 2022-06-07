#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    keyCAE = new QShortcut(this);
    keyCAE->setKey(Qt::CTRL + Qt::ALT + Qt::Key_Enter);
    connect(keyCAE, SIGNAL(activated()), this, SLOT(slotShortcutCAE()));

//    keyAltQ = new QShortcut(this); // Инициализируем объект
//    keyAltQ->setKey(Qt::ALT + Qt::Key_Q); // Устанавливаем сочетание клавиш
//    // подключаем обработчик нажатия клавиши
//    connect(keyAltQ, SIGNAL(activated()), this, SLOT(slotShortcutAltQ()));

    keyAltQ = new QShortcut(this);
    keyAltQ->setKey(Qt::ALT + Qt::Key_Q);
    connect(keyAltQ, &QShortcut::activated, this, &QMessageBox::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotShortcutCAE()
{
    if(this->isFullScreen()){
        this->showNormal();
    } else {
        this->showFullScreen();
    }
}

void MainWindow::slotShortcutAltQ()
{
    QMessageBox::information(this,
                             "Горячая клавиша",
                             "Мои поздравления!!! Горячая клавиша работает",
                             QMessageBox::Ok);
}
