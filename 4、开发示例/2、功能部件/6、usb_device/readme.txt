ʹ�÷�����

g_file_storage.ko��
	���ɲο���3.Linux\1.Linux�û��ֲ�\EasyARM-iMX28xx Linux����ָ�� 20150901 V1.03.pdf����8.10�����ݣ�

	1���ڿ����׼��Ĺ����ڴ��л���һ��ռ���Ϊ��ͨ�ļ�ʹ�ã�
		dd if=/dev/zero of=/dev/shm/disk bs=1024 count=10240

	2������g_file_storage.ko������
		insmod g_file_storage.ko stall=0 file=/dev/shm/disk removable=1

	3���̽�JP5��ʹ��MicroUSB�������ӿ����׼���USB OTG��������USB�ӿڼ��ɡ�

usb_storage_up.sh��
	ִ�иýű������Զ����������1��2����ֱ�ӽ��е�3�����ɡ�

	