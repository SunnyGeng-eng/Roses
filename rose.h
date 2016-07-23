#ifndef ROSE_H
#define ROSE_H

#include <QWidget>
#include <QMouseEvent>

class Rose : public QWidget
{
    Q_OBJECT

public:
    Rose(QWidget *parent = 0);
    ~Rose();

protected:
    virtual void mousePressEvent(QMouseEvent *e);

    virtual void mouseMoveEvent(QMouseEvent *e);

public slots:
    void slot_fixed(bool checked);

public:
    bool isFixed;           //是否锁定位置

private:
    QPoint dragPosion;
    bool leftBtn;
};

#endif // ROSE_H
