使用方法：

1、请仔细阅读“3、Linux\1、Linux用户手册\EasyARM-iMX28xx Linux开发指南 20150901 V1.03.pdf”（以
   下简称《Linux开发指南》）第14.3节的内容，完成QT编译环境的搭建

2、假定将源代码APP.cpp拷贝到ubuntu系统的/home/vmuser/qt/APP目录。进入该目录，执行下列指令：
	qmake -project -o APP.pro	# 指令中的“o”为小写字母
	qmake
	make

3、连接好开发套件的液晶显示屏后上电，将编译好的QT程序拷贝到开发套件

4、运行某示例程序之前，请先仔细阅读对应目录下的README文件（如果存在）