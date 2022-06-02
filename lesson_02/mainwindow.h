#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    /* Виртуальная функция родительского класса в нашем классе
     * переопределяется для изменения поведения приложения,
     *  чтобы оно сворачивалось в трей, когда мы этого хотим
     */
    void closeEvent(QCloseEvent * event);

private slots:
    /* Слот, который будет принимать сигнал от события
     * нажатия на иконку приложения в трее
     */
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon         * trayIcon;
};
#endif // MAINWINDOW_H
