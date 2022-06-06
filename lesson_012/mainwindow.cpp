#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    keyCAE = new QShortcut(this);   // Инициализируем объект
    keyCAE->setKey(Qt::CTRL + Qt::ALT + Qt::Key_Enter);    // Устанавливаем код клавиши
    // цепляем обработчик нажатия клавиши
    connect(keyCAE, SIGNAL(activated()), this, SLOT(slotShortcutCAE()));

//    keyAltQ = new QShortcut(this); // Инициализируем объект
//    keyAltQ->setKey(Qt::ALT + Qt::Key_Q); // Устанавливаем сочетание клавиш
//    // подключаем обработчик нажатия клавиши
//    connect(keyAltQ, SIGNAL(activated()), this, SLOT(slotShortcutAltQ()));

    keyAltQ = new QShortcut(this); // Инициализируем объект
    keyAltQ->setKey(Qt::ALT + Qt::Key_Q); // Устанавливаем сочетание клавиш
    // подключаем обработчик нажатия клавиши
    connect(keyAltQ, &QShortcut::activated, this, &QMessageBox::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Слот для обработки нажатия клавиши F11
 * */
void MainWindow::slotShortcutCAE()
{
    /* В этом обработчике сделаем переключение приложения
     * в полноэкранный режим и обратно в нормальный режим окна
     * */
    if(this->isFullScreen()){
        this->showNormal();
    } else {
        this->showFullScreen();
    }
}

/* Слот для обработки сочетания клавиш Ctrl + D
 * */
void MainWindow::slotShortcutAltQ()
{
    /* Для обработки сочетания клавив Ctrl + D
     * сделаем информационный MessageBox,
     * который будет сигнализировать о том, что было нажато данное
     * сочетание клавиш
     * */
    QMessageBox::information(this,
                             "Горячая клавиша",
                             "Мои поздравления!!! Горячая клавиша работает",
                             QMessageBox::Ok);
}
