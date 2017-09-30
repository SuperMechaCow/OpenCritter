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
LIBS:oc_DevKit2-cache
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 5 5
Title "OpenCritter Pro"
Date "2017-09-29"
Rev "1"
Comp "MechaMods"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Motor_DC M1
U 1 1 5984AF4B
P 6650 3300
F 0 "M1" V 6750 3400 50  0000 L CNN
F 1 "Motor" V 6400 3100 50  0000 L TNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 6650 3210 50  0001 C CNN
F 3 "" H 6650 3210 50  0001 C CNN
	1    6650 3300
	0    -1   -1   0   
$EndComp
$Comp
L LED D3
U 1 1 5984B0B1
P 6500 2900
F 0 "D3" H 6500 3000 50  0000 C CNN
F 1 "LED" H 6500 2800 50  0000 C CNN
F 2 "LEDs:LED_0805_HandSoldering" H 6500 2900 50  0001 C CNN
F 3 "" H 6500 2900 50  0001 C CNN
	1    6500 2900
	-1   0    0    1   
$EndComp
$Comp
L R R9
U 1 1 5984B154
P 6650 2100
F 0 "R9" V 6730 2100 50  0000 C CNN
F 1 "10K" V 6650 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6580 2100 50  0001 C CNN
F 3 "" H 6650 2100 50  0001 C CNN
	1    6650 2100
	0    -1   -1   0   
$EndComp
$Comp
L R R11
U 1 1 5984B2B6
P 7200 2100
F 0 "R11" V 7280 2100 50  0000 C CNN
F 1 "10K" V 7200 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7130 2100 50  0001 C CNN
F 3 "" H 7200 2100 50  0001 C CNN
	1    7200 2100
	0    -1   -1   0   
$EndComp
$Comp
L R R12
U 1 1 5984B38B
P 7750 2100
F 0 "R12" V 7830 2100 50  0000 C CNN
F 1 "10K" V 7750 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7680 2100 50  0001 C CNN
F 3 "" H 7750 2100 50  0001 C CNN
	1    7750 2100
	0    -1   -1   0   
$EndComp
$Comp
L R R10
U 1 1 5984B3B9
P 6950 2900
F 0 "R10" V 7030 2900 50  0000 C CNN
F 1 "10K" V 6950 2900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6880 2900 50  0001 C CNN
F 3 "" H 6950 2900 50  0001 C CNN
	1    6950 2900
	0    -1   -1   0   
$EndComp
Text HLabel 6500 4200 2    60   Input ~ 0
MISO
Text HLabel 6500 4300 2    60   Input ~ 0
MOSI
Text HLabel 6500 4100 2    60   Input ~ 0
SCK
Text HLabel 6500 4000 2    60   Input ~ 0
RESET
Text HLabel 8000 4300 2    60   Input ~ 0
SDA
Text HLabel 8000 4200 2    60   Input ~ 0
SCL
$Comp
L GND #PWR029
U 1 1 5984CE27
P 7250 3300
F 0 "#PWR029" H 7250 3050 50  0001 C CNN
F 1 "GND" H 7250 3150 50  0000 C CNN
F 2 "" H 7250 3300 50  0001 C CNN
F 3 "" H 7250 3300 50  0001 C CNN
	1    7250 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2400 6550 2400
Wire Wire Line
	6000 2500 7100 2500
Wire Wire Line
	6000 2600 7650 2600
$Comp
L GND #PWR030
U 1 1 5984D5F0
P 8300 2100
F 0 "#PWR030" H 8300 1850 50  0001 C CNN
F 1 "GND" H 8300 1950 50  0000 C CNN
F 2 "" H 8300 2100 50  0001 C CNN
F 3 "" H 8300 2100 50  0001 C CNN
	1    8300 2100
	-1   0    0    1   
$EndComp
Wire Wire Line
	6500 2100 6450 2100
Wire Wire Line
	6450 2100 6450 2400
Connection ~ 6450 2400
Wire Wire Line
	6800 2100 6850 2100
Wire Wire Line
	6850 2100 6850 2200
Wire Wire Line
	6850 2200 8300 2200
Wire Wire Line
	8300 2200 8300 2100
Wire Wire Line
	7350 2100 7400 2100
Wire Wire Line
	7400 2100 7400 2200
Connection ~ 7400 2200
Wire Wire Line
	7600 2100 7550 2100
Wire Wire Line
	7550 2100 7550 2600
Connection ~ 7550 2600
Wire Wire Line
	7900 2100 7950 2100
Wire Wire Line
	7950 2100 7950 2200
Connection ~ 7950 2200
Wire Wire Line
	7050 2100 7000 2100
Wire Wire Line
	7000 2100 7000 2500
Connection ~ 7000 2500
Wire Wire Line
	6950 2400 8300 2400
Wire Wire Line
	8300 2600 8050 2600
Wire Wire Line
	8300 2400 8300 2600
Wire Wire Line
	7500 2500 8300 2500
Connection ~ 8300 2500
$Comp
L Buzzer BZ1
U 1 1 5984AD97
P 7150 3800
F 0 "BZ1" V 7300 3850 50  0000 L CNN
F 1 "Buzzer" H 6850 3800 50  0000 L CNN
F 2 "Buzzers_Beepers:Buzzer_12x9.5RM7.6" V 7125 3900 50  0001 C CNN
F 3 "" V 7125 3900 50  0001 C CNN
	1    7150 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3700 6000 3700
Wire Wire Line
	6000 3300 6450 3300
Wire Wire Line
	7250 3300 6950 3300
Wire Wire Line
	7050 3900 7050 3950
$Comp
L GND #PWR031
U 1 1 5984EFAE
P 7050 3950
F 0 "#PWR031" H 7050 3700 50  0001 C CNN
F 1 "GND" H 7200 3900 50  0000 C CNN
F 2 "" H 7050 3950 50  0001 C CNN
F 3 "" H 7050 3950 50  0001 C CNN
	1    7050 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2650 5150 2650
Wire Wire Line
	5050 2750 5150 2750
Wire Wire Line
	5050 2850 5150 2850
Text Label 5150 2750 0    60   ~ 0
Button_B
Text Label 5150 2650 0    60   ~ 0
Button_C
Text Label 5150 2850 0    60   ~ 0
Button_A
Text Label 6000 2400 0    60   ~ 0
Button_A
Text Label 6000 2500 0    60   ~ 0
Button_B
Text Label 6000 2600 0    60   ~ 0
Button_C
Wire Wire Line
	5050 3150 5150 3150
Wire Wire Line
	5050 3250 5600 3250
Wire Wire Line
	5050 2950 5150 2950
Text Label 5150 2950 0    60   ~ 0
Heart
Text Label 5150 3150 0    60   ~ 0
MISO
Text Label 5600 3150 0    60   ~ 0
MOSI
$Comp
L GND #PWR032
U 1 1 59864C80
P 7250 2900
F 0 "#PWR032" H 7250 2650 50  0001 C CNN
F 1 "GND" H 7250 2750 50  0000 C CNN
F 2 "" H 7250 2900 50  0001 C CNN
F 3 "" H 7250 2900 50  0001 C CNN
	1    7250 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3850 5150 3850
Wire Wire Line
	5050 3750 5150 3750
Text Label 5150 3750 0    60   ~ 0
Rumble
Text Label 6000 3300 0    60   ~ 0
Rumble
Wire Wire Line
	7250 2900 7100 2900
Wire Wire Line
	6800 2900 6650 2900
Wire Wire Line
	6350 2900 6000 2900
Text Label 6000 2900 0    60   ~ 0
Heart
Text Label 6000 3700 0    60   ~ 0
Buzzer
Wire Wire Line
	6500 4000 6000 4000
Wire Wire Line
	6500 4100 6000 4100
Wire Wire Line
	6500 4200 6000 4200
Wire Wire Line
	6500 4300 6000 4300
Wire Wire Line
	8000 4200 7500 4200
Wire Wire Line
	8000 4300 7500 4300
Text Label 5150 3850 0    60   ~ 0
RESET
Text Label 6000 4000 0    60   ~ 0
RESET
Text Label 6000 4100 0    60   ~ 0
SCK
Text Label 6000 4200 0    60   ~ 0
MISO
Text Label 6000 4300 0    60   ~ 0
MOSI
Wire Wire Line
	5050 3050 5150 3050
Text Label 5150 3050 0    60   ~ 0
SCK
$Comp
L SW_Push SW4
U 1 1 59889EAE
P 6750 2400
F 0 "SW4" H 6800 2500 50  0000 L CNN
F 1 "ButA" H 6750 2340 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 6750 2600 50  0001 C CNN
F 3 "" H 6750 2600 50  0001 C CNN
	1    6750 2400
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW5
U 1 1 5988A0AF
P 7300 2500
F 0 "SW5" H 7350 2600 50  0000 L CNN
F 1 "ButB" H 7300 2440 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 7300 2700 50  0001 C CNN
F 3 "" H 7300 2700 50  0001 C CNN
	1    7300 2500
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW6
U 1 1 5988A12E
P 7850 2600
F 0 "SW6" H 7900 2700 50  0000 L CNN
F 1 "ButC" H 7850 2540 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 7850 2800 50  0001 C CNN
F 3 "" H 7850 2800 50  0001 C CNN
	1    7850 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3350 5150 3350
Text Label 5150 3350 0    60   ~ 0
Buzzer
$Comp
L ATTINY84A-MMH U4
U 1 1 59CAFF98
P 4000 3250
F 0 "U4" H 3150 4000 50  0000 C CNN
F 1 "ATTINY84A-MMH" H 3400 2500 50  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-20-1EP_4x4mm_Pitch0.5mm" H 4000 3050 50  0001 C CIN
F 3 "" H 4000 3250 50  0001 C CNN
	1    4000 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR033
U 1 1 59CB0BDB
P 2750 4000
F 0 "#PWR033" H 2750 3750 50  0001 C CNN
F 1 "GND" H 2750 3850 50  0000 C CNN
F 2 "" H 2750 4000 50  0001 C CNN
F 3 "" H 2750 4000 50  0001 C CNN
	1    2750 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 3850 2750 3850
Wire Wire Line
	2750 3850 2750 4000
Wire Wire Line
	2950 2650 2750 2650
Wire Wire Line
	2750 2650 2750 2450
$Comp
L +3.3V #PWR034
U 1 1 59CB0DD5
P 2750 2450
F 0 "#PWR034" H 2750 2300 50  0001 C CNN
F 1 "+3.3V" H 2750 2590 50  0000 C CNN
F 2 "" H 2750 2450 50  0001 C CNN
F 3 "" H 2750 2450 50  0001 C CNN
	1    2750 2450
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR035
U 1 1 59CB1277
P 8300 2400
F 0 "#PWR035" H 8300 2250 50  0001 C CNN
F 1 "+3.3V" H 8300 2540 50  0000 C CNN
F 2 "" H 8300 2400 50  0001 C CNN
F 3 "" H 8300 2400 50  0001 C CNN
	1    8300 2400
	1    0    0    -1  
$EndComp
Text Label 7500 4300 0    60   ~ 0
SDA
Text Label 7500 4200 0    60   ~ 0
SCK
Text Label 5600 3350 0    60   ~ 0
SDA
Wire Wire Line
	5600 3150 5600 3350
Connection ~ 5600 3250
$EndSCHEMATC
