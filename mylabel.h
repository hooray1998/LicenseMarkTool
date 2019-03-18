#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QtDebug>

class Point{
public:
    int x;
    int y;
    Point(){}
    Point(int ,int);
    Point(Point&p);
    void setValue(Point p);
};

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget*parent = 0);

    QPixmap capturePixmap[20];
    Point startpos[20],endpos[20];
    Point movePos;
    int pn_Number;
    int colorArray[20];
    bool isPress;
private:
    QPainter painter;
    void judgeRect(QRect &r);
public slots:
    void paintEvent(QPaintEvent *);
};

#endif // MYLABEL_H
