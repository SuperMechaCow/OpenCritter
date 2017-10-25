avrdude -c usbasp -p m328p -U hfuse:w:0xD9:m
avrdude -c usbasp -p m328p -U lfuse:w:0xE2:m
avrdude -c usbasp -p m328p -b 57600 -U flash:w:iopu_debugbutton.ino.with_bootloader.hex
pause