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
  如果出现类似下图所示的DLL丢失的情况，请安装Visual C++ Redistributable for Visual Studio 2015，下载链接：https://www.microsoft.com/en-us/download/confirmation.aspx?id=48145
  ![](./image001.png)
  如果出现下图中的窗口，请检查jlnk是否正确连接
  ![](./image002.png)
##3. 使用方法
  最新版本在程序**正常**退出的情况下会自动保存基地址，行数，列数等信息，第一次使用时，建议打开文件夹下的settings.ini，设置地址等信息，如下图所示：
  ![](./image/image003.png)
  ![](./image/image004.png)
  关键在于baseAddr的设置，该文件可在工程目录/build/工程名/debug/lst/xxx.map中查看，建议直接在工程路径下找*.map
  比如，假设工程名为firedemo，则该文件的目录为：
  ![](./image/image005.png)
  假设存储图片的数组名为IMG_BUFF，如下图所示
  ![](./image/image006.png)
  此时在MAP文件中能找到IMG_BUFF的地址，如图：
  ![](./image/image007.png)
  上图中左边是变量名，右边的地址0x1fff04c0填入上文中的settings.ini中的baseAddr即可,对于本例，最终更改的ini截图如下：
  ![](./image/image008.png)
    如果是新摄像头，分辨率默认最大为160*120，否则为320*240，如果出现图像显示不正确的情况，请检查行和列是否正确填写


