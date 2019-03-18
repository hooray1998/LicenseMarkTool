#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QString>
#include <QStatusBar>
#include <QPixmap>
#include <QScreen>
#include <QDesktopWidget>
#include <QPainter>
#include <QLabel>
#include <stdio.h>
#include <QDir>
#include <QFileDialog>
#include <QtDebug>
#include <QStandardPaths>
#include <QMenu>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardPaths>
#include <math.h>
#include <string>
#include <iostream>
#include <QStandardItemModel>
#include <QCompleter>
#include <QLineEdit>
#include <QInputDialog>
#include <QTime>
#include <QTimer>
#include <QIcon>
#include <QTextEdit>
#include <QGridLayout>
#include <QProgressBar>
#include <QSpinBox>

#include "mylabel.h"
#include "helpdoc.h"
#include "secwidget.h"
#include "mythread.h"
#include <time.h>

using namespace std;




class FileInfo {

public:
    int finishNum;
    int lastNum;
    QString currentPath;
    QString savePath;
    QString specialPath;

    FileInfo();

};

class CurrentPlateNumber{
public:
    Point center;
    float width,height;
    int color;
    CurrentPlateNumber();
};
class CurrentPicture{
public:
    CurrentPlateNumber cpnumber[20];
    QString pictureName;
    QPixmap *picture;
    CurrentPicture();
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QString newName(int s, int v);//去掉.jpg
    QString newName();

    void init();
    void initStyle();
    void FixLayout();
    void  newPoint(Point &);//转换成真实坐标
    void updateFile();
    void readInfoFile();

    bool Contain(int ,int);
    bool Contain(Point&p);
    bool getCurrentPicture();
    bool WindowIsModify();
    bool ModifyWarning();
    bool judgeIsCurPn(QString p, QString curname);

    void SearchSaveNumber();
    void FindpnNumber();
    void setCurPn(int count,int color,double xcx,double xcy,double xw,double xh);
    void updateWindow(int i);
    void ShowCalculateNum();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
        void contextMenuEvent(QContextMenuEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent*event);
        void wheelEvent(QWheelEvent*e);
        void keyPressEvent(QKeyEvent*e);
private slots:
        void on_pushButton_PicturePath_clicked();
        void on_pushButton_SavePath_clicked();
        void on_pushButtonNextPicture_clicked();
        void on_pushButtonSavePlate_clicked();
        void on_pushButtonLastPicture_clicked();
        void on_pushButtonSpecial_clicked();
        void on_pushButtonChangeName_clicked();
        void on_pushButtonSkip_clicked();
        void on_pushButtonDeleteOld_clicked();
        void on_pushButtonMoveUntreated_clicked();
        void on_specialPath_clicked();

        void on_yellow_clicked();
        void on_blue_clicked();
        void on_black_clicked();
        void on_white_clicked();
        void on_green_clicked();
        void on_yellowgreen_clicked();

        void updateTime();
        void showSpeedAndRunTime();
        void gshSlot();

        void chooseMovePath();
        void startMove();
        void showProcess(int);
        void checkThreadIsEnd();
private:
    Ui::MainWindow *ui;
    SecWidget swidget;
    
    int l_x,l_y,l_width,l_height;

    QString lastSPath;
    FileInfo fileinfo;
    CurrentPicture cpn;
    Point tempP[3];
    bool isPress;
    int pointNum;
    QFileInfoList oglist;

    bool isGroupShow;
    bool isStore;
    bool Stored;
    int currentColor;

    int startCount;//程序打开时的页码。
    int lastFinishNumber;
    int RunTime;
    int lastMinuteCount[60];
    QTimer *shutTime;
    int pnnum;//辅助Pn_number;
    QTimer*timer;
    int i;
    int size;
    QWidget*widget;

    QSpinBox*num  ;
    QLabel*label1;
    QLabel*label2;
    QLineEdit*lineedit ;
    QPushButton*button;
    QPushButton*start ;
    QPushButton*cancel;
    QGridLayout*layout;
    QHBoxLayout*lay2;
    QString moveP;

    MyThread *mythread;
    QTimer* checkThreadIsEndTimer;
    int curThreadOperation;//0 = null,1=gsh,2=delOld,3=moveUntreated.
    QString lastText;//storaging the text before the thread starts;

    QWidget*progressWidget;
    QVBoxLayout*progressLayout;
    QLabel*tishilabel;
    QProgressBar *progress;
};

#endif // MAINWINDOW_H
