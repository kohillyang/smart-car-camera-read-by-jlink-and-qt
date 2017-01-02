#include "imageshowwidget.h"

ImageShowWidget::ImageShowWidget(QWidget *parent, char *newbufferPointer, int xwidth, int yheight) : QWidget(parent)
{
    this->setVbufferAddr(newbufferPointer);
    this->setSize(xwidth,yheight);
}
void ImageShowWidget::paintEvent(QPaintEvent *){
    QImage img = QImage(this->xwidth,this->yheight,QImage::Format_ARGB32);
    for(int i = 0;i<this->xwidth;i++){
        for(int j = 0;j<this->yheight;j++){
            char r= this->vbufferPointer[i*this->xwidth+j];
            img.setPixel(i,j,qRgb(r,r,r));        }
    }
    QPainter painter(this);
    painter.drawImage(0,0,img);
    painter.end();
}

