#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QCloseEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    virtual void closeEvent(QCloseEvent *e);

private slots:
    void slot_display();

private:
    QTimer *timer;
    QTime m_time;
};

#endif // WIDGET_H
