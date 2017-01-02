#ifndef IMAGESHOWWIDGET_H
#define IMAGESHOWWIDGET_H

#include <QWidget>
#include <QPainter>

class ImageShowWidget : public QWidget
{
    Q_OBJECT
private:
    char *vbufferPointer;
    int xwidth,yheight;
public:
    explicit ImageShowWidget(QWidget *parent = 0,char * newbufferPointer=0, int xwidth=240,int yheight=320);
    void setVbufferAddr(char  * newaddr){
         this->vbufferPointer = newaddr;
    }
    void setSize(int x, int y){
        this->resize(x,y);
        this->xwidth = x;
        this->yheight = y;
    }
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // IMAGESHOWWIDGET_H
