#include "widget.h"

#include "rose.h"
#include "systemtrayicon.h"

#include <QApplication>
#include <QDesktopWidget>
#include <ctime>
#include <QDebug>
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowStaysOnTopHint | Qt::Tool;
    setWindowFlags(flags);   //隐藏任务栏软件图标

    setWindowTitle(QString("屏幕开满玫瑰花"));
    setWindowIcon(QIcon(":images/1.png"));

    showFullScreen();
    setWindowOpacity(0);

#if 1
    Rose *dlg = new Rose(this);
    int desktop_width = QApplication::desktop()->width();
    int desktop_high = QApplication::desktop()->height();

    int posX = desktop_width - dlg->width();
    int poxY = desktop_high - dlg->height() - 100;
    dlg->move(posX, poxY);

    dlg->show();

    //设置任务栏系统托盘
    QStringList strList;
    strList << "Rose" << "Rose V1.0";
    QIcon icon(":/images/3.png");
    SystemTrayIcon *trayIcon = new SystemTrayIcon(strList, icon, dlg);

    connect(trayIcon->actFixed, SIGNAL(triggered(bool)), dlg, SLOT(slot_fixed(bool)));
//    trayIcon->show();
#endif

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_display()));
//    timer->start(1000);
    m_time = QTime::currentTime();
}

Widget::~Widget()
{

}

void Widget::closeEvent(QCloseEvent *e)
{
    timer->stop();
}

void Widget::slot_display()
{
    QTime tmpTime = QTime::currentTime();

    int sec = m_time.secsTo(tmpTime);
    qDebug() << "tmpTime:" << tmpTime << "m_time:" << m_time;
    qDebug() << "sec:" << sec;
    if(sec < 120){
        Rose *dlg = new Rose(this);

        int desktop_width = QApplication::desktop()->width();
        int desktop_high = QApplication::desktop()->height();

        qsrand(time(NULL));
        int n = qrand() % 5;    //产生5以内的随机数

        int width = qrand() % desktop_width - dlg->width() / 2;
        int heigh = qrand() % desktop_high - dlg->height() / 2;
        dlg->move(width, heigh);
        dlg->show();
        qDebug() << "num:" << width << heigh << n;
    }else{
        timer->stop();
    }
}
