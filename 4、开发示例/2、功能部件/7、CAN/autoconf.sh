#/bin/sh
ifconfig can0 down
echo CAN0 down.
# set bitrate
echo Setting up bitrate to 1000000.
echo 1000000 > /sys/devices/platform/FlexCAN.0/bitrate 
echo reading /sys/devices/platform/FlexCAN.0/bitrate.
echo `cat /sys/devices/platform/FlexCAN.0/bitrate`.
ifconfig can0 up
echo CAN0 up.
