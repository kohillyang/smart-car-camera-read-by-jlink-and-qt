---
layout: default
title: 智能车摄像头读取软件
---
##1. 软件简介
　　项目托管于https://github.com/kohillyang/smart-car-camera-read-by-jlink-and-qt, 该软件旨在方便使用jlink读取摄像头数据，最新版本支持自定义分辨率，自定义地址，自定义刷新间隔
　　最新Release版本见：https://github.com/kohillyang/smart-car-camera-read-by-jlink-and-qt/releases/download/v0.1-alpha/cameraRead.zip
  软件截图如下：
  ![截图](https://raw.githubusercontent.com/kohillyang/smart-car-camera-read-by-jlink-and-qt/master/screensnap.jpg)
##2. 软件原理以及注意事项
　　原理很简单，电脑端将数据通过Jlink读取到电脑的内存中，使用QPicture画到电脑。PS：由于本人能力有限，拿到的jlink API也有限，所以如果出现软件无法连接智能车主控的情况，请重新下一次程序。下程序的过程中会自动恢复jlink的大部分设置。
　　K60可能出现被锁住无法下载的情况，请在jlink commander下输入unlock kinetis解决。
　　**NOTE：摄像头为5V供电，jlink 输出电源为3.3V，单使用jlink会出现摄像头电压不足，因此链接摄像头时请接通主电源（电池）。**
　　**NOTE：强行断开jlink会导致软件崩溃（所给api为C语言编写，无法捕获异常），会导致设置文件无法保存**
##3. 使用方法
　　最新版本在程序**正常**退出的情况下会自动保存基地址，行数，列数等信息，第一次使用时，建议打开文件夹下的settings.


