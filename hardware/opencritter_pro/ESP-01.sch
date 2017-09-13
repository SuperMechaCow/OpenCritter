EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:switches
LIBS:motors
LIBS:opencritter-cache
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 3 3
Title "OpenCritter DevKit1"
Date "2017-09-01"
Rev "1"
Comp "MechaMods"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2300 2950 2    60   Input ~ 0
EXT_RSTB
Text HLabel 2200 3050 2    60   Input ~ 0
CHIP_EN
Text HLabel 2150 3150 2    60   Input ~ 0
TX
Text HLabel 1350 3050 0    60   Input ~ 0
SCL
Text HLabel 5850 3700 0    60   Input ~ 0
SDA
Text HLabel 1150 2850 0    60   Input ~ 0
Rx
$Comp
L GND #PWR032
U 1 1 5984B719
P 1450 3150
F 0 "#PWR032" H 1450 2900 50  0001 C CNN
F 1 "GND" H 1450 3000 50  0000 C CNN
F 2 "" H 1450 3150 50  0001 C CNN
F 3 "" H 1450 3150 50  0001 C CNN
	1    1450 3150
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR033
U 1 1 5984B731
P 2400 2850
F 0 "#PWR033" H 2400 2700 50  0001 C CNN
F 1 "VCC" H 2400 3000 50  0000 C CNN
F 2 "" H 2400 2850 50  0001 C CNN
F 3 "" H 2400 2850 50  0001 C CNN
	1    2400 2850
	1    0    0    -1  
$EndComp
$Comp
L ESP8266EX U2
U 1 1 598711AC
P 7450 3950
F 0 "U2" H 8350 3400 60  0000 C CNN
F 1 "ESP8266EX" H 8550 3550 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-32-1EP_5x5mm_Pitch0.5mm" V 6250 3350 60  0001 C CNN
F 3 "" V 6250 3350 60  0001 C CNN
	1    7450 3950
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR034
U 1 1 598717B8
P 6950 2400
F 0 "#PWR034" H 6950 2250 50  0001 C CNN
F 1 "VCC" H 6950 2550 50  0000 C CNN
F 2 "" H 6950 2400 50  0001 C CNN
F 3 "" H 6950 2400 50  0001 C CNN
	1    6950 2400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR035
U 1 1 598717D2
P 8900 2400
F 0 "#PWR035" H 8900 2150 50  0001 C CNN
F 1 "GND" H 8900 2250 50  0000 C CNN
F 2 "" H 8900 2400 50  0001 C CNN
F 3 "" H 8900 2400 50  0001 C CNN
	1    8900 2400
	-1   0    0    1   
$EndComp
$Comp
L C C6
U 1 1 5987182E
P 8200 3000
F 0 "C6" H 8225 3100 50  0000 L CNN
F 1 "C" H 8225 2900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8238 2850 50  0001 C CNN
F 3 "" H 8200 3000 50  0001 C CNN
	1    8200 3000
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 598718B7
P 8200 2750
F 0 "C4" H 8225 2850 50  0000 L CNN
F 1 "C" H 8225 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8238 2600 50  0001 C CNN
F 3 "" H 8200 2750 50  0001 C CNN
	1    8200 2750
	0    1    1    0   
$EndComp
$Comp
L C C5
U 1 1 59871906
P 8650 2750
F 0 "C5" H 8675 2850 50  0000 L CNN
F 1 "C" H 8675 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8688 2600 50  0001 C CNN
F 3 "" H 8650 2750 50  0001 C CNN
	1    8650 2750
	0    1    1    0   
$EndComp
Text HLabel 5850 3500 0    60   Input ~ 0
CHIP_EN
Text HLabel 5850 3600 0    60   Input ~ 0
SCL
Text HLabel 5850 3900 0    60   Input ~ 0
Tx
Text HLabel 5850 3800 0    60   Input ~ 0
Rx
Text HLabel 5850 4000 0    60   Input ~ 0
EXT_RSTB
$Comp
L Antenna AE1
U 1 1 598721BC
P 9950 3900
F 0 "AE1" H 9875 3975 50  0000 R CNN
F 1 "Antenna" H 9875 3900 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 9950 3900 50  0001 C CNN
F 3 "" H 9950 3900 50  0001 C CNN
	1    9950 3900
	1    0    0    -1  
$EndComp
$Comp
L L L1
U 1 1 59872279
P 9250 4450
F 0 "L1" V 9200 4450 50  0000 C CNN
F 1 "L" V 9325 4450 50  0000 C CNN
F 2 "Inductors_SMD:L_0805_HandSoldering" H 9250 4450 50  0001 C CNN
F 3 "" H 9250 4450 50  0001 C CNN
	1    9250 4450
	1    0    0    -1  
$EndComp
$Comp
L L L2
U 1 1 5987234A
P 9450 4450
F 0 "L2" V 9400 4450 50  0000 C CNN
F 1 "L" V 9525 4450 50  0000 C CNN
F 2 "Inductors_SMD:L_0805_HandSoldering" H 9450 4450 50  0001 C CNN
F 3 "" H 9450 4450 50  0001 C CNN
	1    9450 4450
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 598726C3
P 8750 3600
F 0 "R8" V 8830 3600 50  0000 C CNN
F 1 "200" V 8750 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8680 3600 50  0001 C CNN
F 3 "" H 8750 3600 50  0001 C CNN
	1    8750 3600
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 5987270C
P 6250 4000
F 0 "R9" V 6330 4000 50  0000 C CNN
F 1 "470" V 6250 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6180 4000 50  0001 C CNN
F 3 "" H 6250 4000 50  0001 C CNN
	1    6250 4000
	0    1    1    0   
$EndComp
$Comp
L CAT250_EEPROM U3
U 1 1 59872BC0
P 1800 4450
F 0 "U3" H 1500 4700 50  0000 L CNN
F 1 "CAT250" H 1100 4200 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 1450 4400 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/CAT25010-D.PDF" H 1450 4400 50  0001 C CNN
	1    1800 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR036
U 1 1 598733FD
P 1800 4900
F 0 "#PWR036" H 1800 4650 50  0001 C CNN
F 1 "GND" H 1800 4750 50  0000 C CNN
F 2 "" H 1800 4900 50  0001 C CNN
F 3 "" H 1800 4900 50  0001 C CNN
	1    1800 4900
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR037
U 1 1 5987345E
P 1800 4050
F 0 "#PWR037" H 1800 3900 50  0001 C CNN
F 1 "VCC" H 1800 4200 50  0000 C CNN
F 2 "" H 1800 4050 50  0001 C CNN
F 3 "" H 1800 4050 50  0001 C CNN
	1    1800 4050
	1    0    0    -1  
$EndComp
Text Label 9250 3600 0    60   ~ 0
SCK
Text Label 9250 3500 0    60   ~ 0
/CS
Text Label 9250 3700 0    60   ~ 0
/HOLD
Text Label 9250 3800 0    60   ~ 0
DI
Text Label 9250 3900 0    60   ~ 0
DO
Text Label 9250 4000 0    60   ~ 0
/WP
Text Label 1100 4350 0    60   ~ 0
/WP
Text Label 1100 4450 0    60   ~ 0
/HOLD
Text Label 1100 4550 0    60   ~ 0
/CS
Text Label 2250 4350 0    60   ~ 0
SCK
Text Label 2250 4450 0    60   ~ 0
DO
Text Label 2250 4550 0    60   ~ 0
DI
$Comp
L GND #PWR038
U 1 1 598742AE
P 9250 4700
F 0 "#PWR038" H 9250 4450 50  0001 C CNN
F 1 "GND" H 9250 4550 50  0000 C CNN
F 2 "" H 9250 4700 50  0001 C CNN
F 3 "" H 9250 4700 50  0001 C CNN
	1    9250 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR039
U 1 1 598742DD
P 9450 4700
F 0 "#PWR039" H 9450 4450 50  0001 C CNN
F 1 "GND" H 9450 4550 50  0000 C CNN
F 2 "" H 9450 4700 50  0001 C CNN
F 3 "" H 9450 4700 50  0001 C CNN
	1    9450 4700
	1    0    0    -1  
$EndComp
Text HLabel 1250 2950 0    60   Input ~ 0
SDA
$Comp
L R R10
U 1 1 59876229
P 8350 5150
F 0 "R10" V 8430 5150 50  0000 C CNN
F 1 "12K" V 8350 5150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8280 5150 50  0001 C CNN
F 3 "" H 8350 5150 50  0001 C CNN
	1    8350 5150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR040
U 1 1 598763EC
P 8750 5050
F 0 "#PWR040" H 8750 4800 50  0001 C CNN
F 1 "GND" H 8750 4900 50  0000 C CNN
F 2 "" H 8750 5050 50  0001 C CNN
F 3 "" H 8750 5050 50  0001 C CNN
	1    8750 5050
	-1   0    0    1   
$EndComp
Text Label 7200 5150 1    60   ~ 0
ADC_IN
Text Label 7300 5150 1    60   ~ 0
GPIO16
Text Label 7400 5150 1    60   ~ 0
GPIO14
Text Label 7500 5150 1    60   ~ 0
GPIO12
Text Label 7600 5150 1    60   ~ 0
GPIO13
Text Label 7700 5150 1    60   ~ 0
GPIO15
Text Label 7800 5150 1    60   ~ 0
GPIO4
Text Label 7900 5150 1    60   ~ 0
GPIO5
$Comp
L C C7
U 1 1 59876B65
P 4700 4350
F 0 "C7" H 4725 4450 50  0000 L CNN
F 1 "C" H 4725 4250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4738 4200 50  0001 C CNN
F 3 "" H 4700 4350 50  0001 C CNN
	1    4700 4350
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 59876C5E
P 3550 4750
F 0 "C8" H 3575 4850 50  0000 L CNN
F 1 "C" H 3575 4650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3588 4600 50  0001 C CNN
F 3 "" H 3550 4750 50  0001 C CNN
	1    3550 4750
	-1   0    0    1   
$EndComp
$Comp
L Crystal_GND24 Y2
U 1 1 598765DF
P 4150 4550
F 0 "Y2" H 4275 4750 50  0000 L CNN
F 1 "40Mhz" H 3850 4750 50  0000 L CNN
F 2 "Crystals:Crystal_SMD_3225-4pin_3.2x2.5mm_HandSoldering" H 4150 4550 50  0001 C CNN
F 3 "" H 4150 4550 50  0001 C CNN
	1    4150 4550
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR041
U 1 1 598777AC
P 4700 4100
F 0 "#PWR041" H 4700 3850 50  0001 C CNN
F 1 "GND" H 4700 3950 50  0000 C CNN
F 2 "" H 4700 4100 50  0001 C CNN
F 3 "" H 4700 4100 50  0001 C CNN
	1    4700 4100
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR042
U 1 1 59877867
P 3550 5000
F 0 "#PWR042" H 3550 4750 50  0001 C CNN
F 1 "GND" H 3550 4850 50  0000 C CNN
F 2 "" H 3550 5000 50  0001 C CNN
F 3 "" H 3550 5000 50  0001 C CNN
	1    3550 5000
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 J11
U 1 1 59877FF4
P 7550 5350
F 0 "J11" H 7550 5800 50  0000 C CNN
F 1 "ESP GPIO" V 7650 5350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 7550 5350 50  0001 C CNN
F 3 "" H 7550 5350 50  0001 C CNN
	1    7550 5350
	0    1    1    0   
$EndComp
$Comp
L CONN_02X04 J10
U 1 1 59878263
P 1800 3000
F 0 "J10" H 1800 3250 50  0000 C CNN
F 1 "ESP" H 1800 2750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04_Pitch2.54mm" H 1800 1800 50  0001 C CNN
F 3 "" H 1800 1800 50  0001 C CNN
	1    1800 3000
	-1   0    0    1   
$EndComp
Text Label 4300 4550 0    60   ~ 0
XTAL_IN
Text Label 3550 4550 0    60   ~ 0
XTAL_OUT
Text Label 5800 4150 0    60   ~ 0
XTAL_IN
Text Label 5800 4250 0    60   ~ 0
XTAL_OUT
$Comp
L SW_SPST SW5
U 1 1 599A6510
P 4050 2800
F 0 "SW5" H 4050 2925 50  0000 C CNN
F 1 "GPIO0" H 4050 2700 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_EVQPE1" H 4050 2800 50  0001 C CNN
F 3 "" H 4050 2800 50  0001 C CNN
	1    4050 2800
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW6
U 1 1 599A6785
P 4050 3250
F 0 "SW6" H 4050 3375 50  0000 C CNN
F 1 "RESET" H 4050 3150 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_EVQPE1" H 4050 3250 50  0001 C CNN
F 3 "" H 4050 3250 50  0001 C CNN
	1    4050 3250
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 599CF88D
P 3500 2800
F 0 "R6" V 3580 2800 50  0000 C CNN
F 1 "10K" V 3500 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3430 2800 50  0001 C CNN
F 3 "" H 3500 2800 50  0001 C CNN
	1    3500 2800
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 599CF92C
P 3500 3250
F 0 "R7" V 3580 3250 50  0000 C CNN
F 1 "10K" V 3500 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3430 3250 50  0001 C CNN
F 3 "" H 3500 3250 50  0001 C CNN
	1    3500 3250
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR043
U 1 1 599CFCB5
P 3150 2800
F 0 "#PWR043" H 3150 2650 50  0001 C CNN
F 1 "VCC" H 3150 2950 50  0000 C CNN
F 2 "" H 3150 2800 50  0001 C CNN
F 3 "" H 3150 2800 50  0001 C CNN
	1    3150 2800
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR044
U 1 1 599D0207
P 3150 3250
F 0 "#PWR044" H 3150 3100 50  0001 C CNN
F 1 "VCC" H 3150 3400 50  0000 C CNN
F 2 "" H 3150 3250 50  0001 C CNN
F 3 "" H 3150 3250 50  0001 C CNN
	1    3150 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR045
U 1 1 599D029E
P 4450 2800
F 0 "#PWR045" H 4450 2550 50  0001 C CNN
F 1 "GND" H 4450 2650 50  0000 C CNN
F 2 "" H 4450 2800 50  0001 C CNN
F 3 "" H 4450 2800 50  0001 C CNN
	1    4450 2800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR046
U 1 1 599D02E5
P 4450 3250
F 0 "#PWR046" H 4450 3000 50  0001 C CNN
F 1 "GND" H 4450 3100 50  0000 C CNN
F 2 "" H 4450 3250 50  0001 C CNN
F 3 "" H 4450 3250 50  0001 C CNN
	1    4450 3250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR047
U 1 1 599D046B
P 3150 3550
F 0 "#PWR047" H 3150 3400 50  0001 C CNN
F 1 "VCC" H 3150 3700 50  0000 C CNN
F 2 "" H 3150 3550 50  0001 C CNN
F 3 "" H 3150 3550 50  0001 C CNN
	1    3150 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3150 1550 3150
Wire Wire Line
	2050 3050 2200 3050
Wire Wire Line
	2050 2950 2300 2950
Wire Wire Line
	2050 2850 2400 2850
Wire Wire Line
	2150 3150 2050 3150
Wire Wire Line
	1150 2850 1550 2850
Wire Wire Line
	1250 2950 1550 2950
Wire Wire Line
	1350 3050 1550 3050
Wire Wire Line
	7700 2550 7700 3200
Wire Wire Line
	8900 3200 7800 3200
Wire Wire Line
	8900 2400 8900 3200
Wire Wire Line
	6950 2550 6950 2400
Wire Wire Line
	8350 3000 8900 3000
Connection ~ 8900 3000
Wire Wire Line
	6950 2550 7700 2550
Wire Wire Line
	7600 3200 7600 2750
Wire Wire Line
	7600 2750 8050 2750
Connection ~ 7700 2750
Wire Wire Line
	8350 2750 8500 2750
Wire Wire Line
	8800 2750 8900 2750
Connection ~ 8900 2750
Wire Wire Line
	7300 3200 7300 3000
Wire Wire Line
	7300 3000 8050 3000
Wire Wire Line
	7400 3200 7400 3000
Connection ~ 7400 3000
Wire Wire Line
	7500 3200 7500 3000
Connection ~ 7500 3000
Wire Wire Line
	7200 2550 7200 3200
Connection ~ 7200 2550
Wire Wire Line
	7100 3200 7100 3000
Wire Wire Line
	7100 3000 7200 3000
Connection ~ 7200 3000
Wire Wire Line
	6450 3500 5850 3500
Wire Wire Line
	6450 3600 5850 3600
Wire Wire Line
	6450 3700 5850 3700
Wire Wire Line
	6450 3800 5850 3800
Wire Wire Line
	6450 3900 5850 3900
Wire Wire Line
	8450 3600 8600 3600
Wire Wire Line
	8450 3500 9250 3500
Wire Wire Line
	8900 3600 9250 3600
Wire Wire Line
	8450 3700 9250 3700
Wire Wire Line
	8450 3800 9250 3800
Wire Wire Line
	8450 3900 9250 3900
Wire Wire Line
	8450 4000 9250 4000
Wire Wire Line
	1800 4050 1800 4150
Wire Wire Line
	1800 4900 1800 4750
Wire Wire Line
	2250 4350 2200 4350
Wire Wire Line
	2250 4450 2200 4450
Wire Wire Line
	2250 4550 2200 4550
Wire Wire Line
	1400 4350 1100 4350
Wire Wire Line
	1400 4450 1100 4450
Wire Wire Line
	1400 4550 1100 4550
Wire Wire Line
	8450 4200 9950 4200
Connection ~ 9250 4200
Connection ~ 9450 4200
Wire Wire Line
	9250 4200 9250 4300
Wire Wire Line
	9450 4200 9450 4300
Wire Wire Line
	9450 4700 9450 4600
Wire Wire Line
	9250 4700 9250 4600
Wire Wire Line
	9950 4200 9950 4100
Wire Wire Line
	6450 4000 6400 4000
Wire Wire Line
	6100 4000 5850 4000
Wire Wire Line
	7400 4750 7400 5150
Wire Wire Line
	7500 4750 7500 5150
Wire Wire Line
	7600 4750 7600 5150
Wire Wire Line
	7700 4750 7700 5150
Wire Wire Line
	7800 4750 7800 5150
Wire Wire Line
	7900 4750 7900 5150
Wire Wire Line
	8000 4750 8000 5150
Wire Wire Line
	8000 5150 8200 5150
Wire Wire Line
	8500 5150 8750 5150
Wire Wire Line
	8750 5150 8750 5050
Wire Wire Line
	7300 4750 7300 5150
Wire Wire Line
	7200 4750 7200 5150
Wire Wire Line
	6450 4150 5800 4150
Wire Wire Line
	5800 4250 6450 4250
Wire Wire Line
	4700 4550 4700 4500
Wire Wire Line
	4700 4100 4700 4200
Wire Wire Line
	3550 4900 3550 5000
Wire Wire Line
	3550 4550 4000 4550
Wire Wire Line
	4300 4550 4700 4550
Wire Wire Line
	4150 4350 4150 4150
Wire Wire Line
	4150 4750 4150 4950
Wire Wire Line
	4150 4950 3550 4950
Connection ~ 3550 4950
Wire Wire Line
	3550 4550 3550 4600
Wire Wire Line
	4150 4150 4700 4150
Connection ~ 4700 4150
Wire Wire Line
	4450 2800 4250 2800
Wire Wire Line
	4450 3250 4250 3250
Wire Wire Line
	3150 2800 3350 2800
Wire Wire Line
	3150 3250 3350 3250
Wire Wire Line
	3650 3250 3850 3250
Wire Wire Line
	3650 2800 3850 2800
Wire Wire Line
	3750 3250 3750 3050
Wire Wire Line
	3750 3050 4650 3050
Connection ~ 3750 3250
Wire Wire Line
	3750 2800 3750 2600
Wire Wire Line
	3750 2600 4650 2600
Connection ~ 3750 2800
Wire Wire Line
	3150 3550 3400 3550
Wire Wire Line
	3600 3550 4650 3550
Text HLabel 4650 3550 2    60   Input ~ 0
CHIP_EN
Text HLabel 4650 2600 2    60   Input ~ 0
SDA
Text HLabel 4650 3050 2    60   Input ~ 0
EXT_RSTB
Wire Notes Line
	700  2400 2900 2400
Wire Notes Line
	2900 2400 2900 3500
Wire Notes Line
	2900 3500 700  3500
Wire Notes Line
	700  3500 700  2400
Wire Notes Line
	3000 2400 5200 2400
Wire Notes Line
	5200 2400 5200 3700
Wire Notes Line
	5200 3700 3000 3700
Wire Notes Line
	3000 3700 3000 2400
Wire Notes Line
	3000 3800 5200 3800
Wire Notes Line
	5200 3800 5200 5300
Wire Notes Line
	5200 5300 3000 5300
Wire Notes Line
	3000 5300 3000 3800
Wire Notes Line
	2900 3600 2900 5300
Wire Notes Line
	2900 5300 700  5300
Wire Notes Line
	700  5300 700  3600
Wire Notes Line
	700  3600 2900 3600
Text Notes 750  2500 0    60   ~ 0
ESP-01 Dock
Text Notes 750  3700 0    60   ~ 0
Flash
Text Notes 3050 3900 0    60   ~ 0
Clock
Text Notes 3050 2500 0    60   ~ 0
Programmer
Wire Notes Line
	5300 5550 5300 2150
Wire Notes Line
	5300 2150 10100 2150
Wire Notes Line
	10100 2150 10100 5550
Wire Notes Line
	10100 5550 5300 5550
Text Notes 5350 2250 0    60   ~ 0
ESP8266 Core
$Comp
L Jumper_NO_Small JP3
U 1 1 599D46E4
P 3500 3550
F 0 "JP3" H 3500 3630 50  0000 C CNN
F 1 "Enable" H 3510 3490 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3500 3550 50  0001 C CNN
F 3 "" H 3500 3550 50  0001 C CNN
	1    3500 3550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
