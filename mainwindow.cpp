#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QRect screen = QApplication::desktop()->screenGeometry();
    this->move(screen.center() - this->rect().center());

    QRegExp rx("\\d+[.]\\d+");
    
    QValidator *validator = new QRegExpValidator(rx, this);

    ui->lineEdit->setValidator(validator);
    ui->lineEdit->installEventFilter(this);
}

enum Type {
    DEFAULT,
    PLUS,
    MINUS,
    SLASH,
    ASTERISK
};

Type type = DEFAULT;
double v1 = 0;
double v2 = 0;
double v3 = 0;
bool cl = false;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::txtToDouble(){
    QString txt = ui->lineEdit->text();
    v1 = txt == "inf" ? 0 : txt.toDouble();
    cl = true;
}

void MainWindow::clearSetText(){
    ui->lineEdit->clear();
    ui->lineEdit->setText(QString::number(v3));
    v1 = v3;
}
void MainWindow::numericButtonPressed(int number){
    if(cl){
        ui->lineEdit->clear();
        cl = false;
    }
    if(ui->lineEdit->text() == "0"){
        ui->lineEdit->clear();
    }
    ui->lineEdit->insert(QString::number(number));
}

void MainWindow::on_pushButton_7_clicked(){
    numericButtonPressed(1);
}

void MainWindow::on_pushButton_8_clicked(){
    numericButtonPressed(2);

}

void MainWindow::on_pushButton_9_clicked(){
    numericButtonPressed(3);
}

void MainWindow::on_pushButton_4_clicked(){
    numericButtonPressed(4);
}

void MainWindow::on_pushButton_5_clicked(){
    numericButtonPressed(5);
}

void MainWindow::on_pushButton_6_clicked(){
    numericButtonPressed(6);
}

void MainWindow::on_pushButton_clicked(){
    numericButtonPressed(7);
}

void MainWindow::on_pushButton_2_clicked(){
    numericButtonPressed(8);
}

void MainWindow::on_pushButton_3_clicked(){
    numericButtonPressed(9);
}

void MainWindow::on_pushButton_10_clicked(){
    numericButtonPressed(0);
}

void MainWindow::on_pushButton_11_clicked(){
    ui->lineEdit->insert(".");
    cl = false;
}

void MainWindow::on_pushButton_15_clicked(){
    type = PLUS;
    txtToDouble();
}

void MainWindow::on_pushButton_14_clicked(){
    type = MINUS;
    txtToDouble();
}

void MainWindow::on_pushButton_12_clicked(){
    type = SLASH;
    txtToDouble();
}

void MainWindow::on_pushButton_13_clicked(){
    type = ASTERISK;
    txtToDouble();
}

void MainWindow::on_pushButton_16_clicked(){
    QString txt2 = ui->lineEdit->text();
    v2 = txt2.toDouble();
    if(type == PLUS){
        v3 = v1 + v2;
        clearSetText();
    }
    if(type == MINUS){
        v3 = v1 - v2;
        clearSetText();
    }
    if(type == SLASH){
        if(v2 == 0){
            printf("na 0 delit' nel'zya!");
            ui->lineEdit->clear();
            ui->lineEdit->setText("inf");
        }
        else{
            v3 = v1 / v2;
            clearSetText();
        }
    }
    if(type == ASTERISK){
        v3 = v1 * v2;
        clearSetText();
    }
    type = DEFAULT;
    cl = true;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    QString txt = ui->lineEdit->text();
    if(txt == "0" && (event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9)){
        ui->lineEdit->clear();
    }
    if(cl){
        switch (event->key()){
            case Qt::Key_1:
            case Qt::Key_2:
            case Qt::Key_3:
            case Qt::Key_4:
            case Qt::Key_5:
            case Qt::Key_6:
            case Qt::Key_7:
            case Qt::Key_8:
            case Qt::Key_9:
            case Qt::Key_0:
                ui->lineEdit->clear();
                cl = false;
            }
    }
    
    if(event->key() == Qt::Key_Escape){
        qApp->quit();
        printf("This is Esc/n");
    }
    if(event->key() == Qt::Key_Plus){
        type = PLUS;
        txtToDouble();
    }
    if(event->key() == Qt::Key_Minus){
        type = MINUS;
        txtToDouble();
    }
    if(event->key() == Qt::Key_Slash){
        type = SLASH;
        txtToDouble();
    }
    if(event->key() == Qt::Key_Asterisk){
        type = ASTERISK;
        txtToDouble();
    }
    if(event->key() == Qt::Key_Comma){
        ui->lineEdit->insert(".");
    }
    if(event->key() == Qt::Key_Equal || event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        QString txt2 = ui->lineEdit->text();
        v2 = txt2.toDouble();
        cl = false;
        if(type == PLUS){
            v3 = v1 + v2;
            clearSetText();
        }
        if(type == MINUS){
            v3 = v1 - v2;
            clearSetText();
        }
        if(type == SLASH){
            if(v2 == 0){
                printf("na 0 delit' nel'zya!");
                ui->lineEdit->clear();
                ui->lineEdit->setText("inf");
                v1 = 0;
            }
            else{
                v3 = v1 / v2;
                clearSetText();
            }
        }
        if(type == ASTERISK){
            v3 = v1 * v2;
            clearSetText();
        }
        type = DEFAULT;
        cl = true;
    }

    fflush(stdout);

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if(obj != ui->lineEdit || event->type() != QEvent::KeyPress){
        return false;
    }
    QKeyEvent* keyEvent = (QKeyEvent*)event;
    keyPressEvent(keyEvent);
    switch(keyEvent->key()){
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
        case Qt::Key_0:
        case Qt::Key_Delete:
        case Qt::Key_Backspace:
        case Qt::Key_Period:
        case Qt::Key_periodcentered:
            return false;
        }
    return true;
}


