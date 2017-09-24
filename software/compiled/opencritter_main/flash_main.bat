ECHO off
cls
ECHO	Please change parameter "-cp" in this bat file to the com port you wish to use
esptool.exe -vv -cd ck -cb 256000 -cp COM7 -ca 0x00000 -cf opencritter_main.ino.bin