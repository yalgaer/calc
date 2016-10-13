#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_button0_clicked();
    void on_buttonPeriod_clicked();
    void on_buttonPlus_clicked();
    void on_buttonMinus_clicked();
    void on_buttonSlash_clicked();
    void on_buttonAsterisk_clicked();
    void on_buttonEqual_clicked();
    
protected:
    void keyPressEvent(QKeyEvent *event);
    void txtToDouble();
    void clearSetText();
    void numericButtonPressed(int number);
    bool eventFilter(QObject *obj, QEvent *event);//in Dialog header


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
