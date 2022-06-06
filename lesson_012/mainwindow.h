#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QShortcut>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // слоты для обработки нажатий горячих клавиш
    void slotShortcutCAE();
    void slotShortcutAltQ();

private:
    Ui::MainWindow  *ui;
    QShortcut       *keyCAE;    // объект горячей клавиши F11
    QShortcut       *keyAltQ;  // объект сочетания клавиш Ctrl + D
};
#endif // MAINWINDOW_H
