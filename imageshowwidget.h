#ifndef IMAGESHOWWIDGET_H
#define IMAGESHOWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QVector>
#include <QSizePolicy>
#include <QDebug>
class ImageShowWidget : public QWidget
{
    Q_OBJECT
private:
    QVector<unsigned char> image_buffer;
    int column = 120,row=160;
public:
    explicit ImageShowWidget(QWidget *parent = 0);
    void updateContentParameter(QVector<unsigned char> o_vec,int column,int row){
        image_buffer = QVector<unsigned char>(o_vec);
        this->column = column;
        this->row = row;
        this->update();
    }
    void paintEvent(QPaintEvent *);
};

#endif // IMAGESHOWWIDGET_H
