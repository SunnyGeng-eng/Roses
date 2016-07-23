#include "rose.h"

#include <QLabel>
#include <QPixmap>
#include <QBitmap>
#include <QDebug>

Rose::Rose(QWidget *parent)
    : QWidget(parent)
{
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowStaysOnTopHint | Qt::Tool;
    setWindowFlags(flags);   //桌面工具栏不显示软件图标

    QLabel *label = new QLabel(this);
    QPixmap pix;
    pix.load(tr(":/images/1.png"));
    label->setPixmap(pix);
    this->setMask(QBitmap(pix.mask()));

    resize(pix.size());

    isFixed = true;
    leftBtn = false;
}

Rose::~Rose()
{

}

void Rose::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosion = e->globalPos() - frameGeometry().topLeft();
        leftBtn = true;
        e->accept();
    }else{
        leftBtn = false;
        e->ignore();
    }
}

void Rose::mouseMoveEvent(QMouseEvent *e)
{
    if(isFixed){
        e->ignore();
        return;
    }
    if(leftBtn){
        move(e->globalPos() - dragPosion);
        e->accept();
    }
}

void Rose::slot_fixed(bool checked)
{
    qDebug() << "checked:" << checked;
    isFixed = checked;
}
