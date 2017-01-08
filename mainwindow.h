#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <imageshowwidget.h>
#include <QVector>
#include <assert.h>
#include <QSettings>
#include <QSpinBox>
#include <QTextEdit>
#include "jlink.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~MainWindow();

private:
    JLink * jlink;
    Ui::MainWindow *ui;
    QVector<unsigned char> vbuff;
    uint32_t baseAddr;
    QTimer *timer;
    ImageShowWidget *cw;
    int row;
    int column;
	void loadIni();
	void saveIni();
public slots:
    void updateVbuff();
    void updateBaseAddrColumnRow();
};

#endif // MAINWINDOW_H
