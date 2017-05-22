使用方法：

g_file_storage.ko：
	（可参考“3.Linux\1.Linux用户手册\EasyARM-iMX28xx Linux开发指南 20150901 V1.03.pdf”第8.10节内容）

	1、在开发套件的共享内存中划分一块空间作为普通文件使用：
		dd if=/dev/zero of=/dev/shm/disk bs=1024 count=10240

	2、加载g_file_storage.ko驱动：
		insmod g_file_storage.ko stall=0 file=/dev/shm/disk removable=1

	3、短接JP5，使用MicroUSB线缆连接开发套件的USB OTG与计算机的USB接口即可。

usb_storage_up.sh：
	执行该脚本可以自动完成上述第1、2步，直接进行第3步即可。

	