#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tray Program");

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setToolTip("Tray Program" "\n"
                         "Работа со сворачиванием программы в трей");

    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction(trUtf8("Развернуть окно"), this);
    QAction * quitAction = new QAction(trUtf8("Выход"), this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    trayIcon->setContextMenu(menu);
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    if(this->isVisible() && ui->checkBox->isChecked()){
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Tray Program",
                              trUtf8("Приложение свернуто в трей. Для того чтобы, "
                                     "развернуть окно приложения, щелкните по иконке приложения в трее"),
                              icon,
                              5000);
    }
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:
        if(ui->checkBox->isChecked()){
            if(!this->isVisible()){
                this->show();
            } else {
                this->hide();
            }
        }
        break;
    default:
        break;
    }
}
