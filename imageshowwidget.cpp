#include "imageshowwidget.h"

ImageShowWidget::ImageShowWidget(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(320,240);
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

void ImageShowWidget::paintEvent(QPaintEvent *){
    QImage img = QImage(column,row,QImage::Format_ARGB32);
    qDebug()<<"size"<<column,row;
    if(this->image_buffer.size() < (this->column * this->row)){
        return;
    }
    for(int i = 0;i<row;i++){
        uchar *p = img.scanLine(i);
        for(int j = 0;j<column;j++){
            char r= this->image_buffer[i*column + j];
            p[j*4 + 0] = r;
            p[j*4 + 1] = r;
            p[j*4 + 2] = r;
        }
    }
    img = img.scaled(this->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QPainter painter(this);
    painter.drawImage(0,0,img);
    painter.end();
}

