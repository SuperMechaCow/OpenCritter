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
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
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
L MCP73831 U2
U 1 1 598E6981
P 6200 2750
F 0 "U2" H 6200 3450 60  0000 C CNN
F 1 "MCP73831" H 6200 2650 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5_HandSoldering" H 6200 2750 60  0001 C CNN
F 3 "" H 6200 2750 60  0001 C CNN
	1    6200 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 598E6B28
P 5500 3200
F 0 "#PWR020" H 5500 2950 50  0001 C CNN
F 1 "GND" H 5500 3050 50  0000 C CNN
F 2 "" H 5500 3200 50  0001 C CNN
F 3 "" H 5500 3200 50  0001 C CNN
	1    5500 3200
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 598E6D68
P 6450 1900
F 0 "D1" H 6450 2000 50  0000 C CNN
F 1 "LED" H 6450 1800 50  0000 C CNN
F 2 "LEDs:LED_0805_HandSoldering" H 6450 1900 50  0001 C CNN
F 3 "" H 6450 1900 50  0001 C CNN
	1    6450 1900
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 598E6E39
P 6200 3100
F 0 "R6" V 6280 3100 50  0000 C CNN
F 1 "1K" V 6200 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6130 3100 50  0001 C CNN
F 3 "" H 6200 3100 50  0001 C CNN
	1    6200 3100
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 598E6F59
P 5950 1900
F 0 "R5" V 6030 1900 50  0000 C CNN
F 1 "1K" V 5950 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5880 1900 50  0001 C CNN
F 3 "" H 5950 1900 50  0001 C CNN
	1    5950 1900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR021
U 1 1 598E7039
P 7200 3100
F 0 "#PWR021" H 7200 2850 50  0001 C CNN
F 1 "GND" H 7200 2950 50  0000 C CNN
F 2 "" H 7200 3100 50  0001 C CNN
F 3 "" H 7200 3100 50  0001 C CNN
	1    7200 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR022
U 1 1 598E7067
P 6200 4050
F 0 "#PWR022" H 6200 3800 50  0001 C CNN
F 1 "GND" H 6200 3900 50  0000 C CNN
F 2 "" H 6200 4050 50  0001 C CNN
F 3 "" H 6200 4050 50  0001 C CNN
	1    6200 4050
	1    0    0    -1  
$EndComp
$Comp
L Battery_Cell BT1
U 1 1 598E7294
P 6900 3800
F 0 "BT1" H 7000 3900 50  0000 L CNN
F 1 "3.7V" H 7000 3800 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" V 6900 3860 50  0001 C CNN
F 3 "" V 6900 3860 50  0001 C CNN
	1    6900 3800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR023
U 1 1 598E75C7
P 7750 2650
F 0 "#PWR023" H 7750 2500 50  0001 C CNN
F 1 "+5V" H 7750 2790 50  0000 C CNN
F 2 "" H 7750 2650 50  0001 C CNN
F 3 "" H 7750 2650 50  0001 C CNN
	1    7750 2650
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW3
U 1 1 59CAC9CF
P 4800 4100
F 0 "SW3" H 4800 4225 50  0000 C CNN
F 1 "Power" H 4800 4000 50  0000 C CNN
F 2 "oc_footprints:JS102011JAQN" H 4800 4100 50  0001 C CNN
F 3 "" H 4800 4100 50  0001 C CNN
	1    4800 4100
	0    1    1    0   
$EndComp
$Comp
L MIC5205 U3
U 1 1 59CADC13
P 6200 4850
F 0 "U3" H 6200 5150 60  0000 C CNN
F 1 "MIC5205" H 6200 4550 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5_HandSoldering" H 6200 4500 60  0001 C CNN
F 3 "" H 6200 4500 60  0001 C CNN
	1    6200 4850
	1    0    0    -1  
$EndComp
$Comp
L CP C5
U 1 1 59CADDAF
P 5000 5050
F 0 "C5" H 5025 5150 50  0000 L CNN
F 1 "10uF" H 5025 4950 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-A_EIA-3216-18_Reflow" H 5038 4900 50  0001 C CNN
F 3 "" H 5000 5050 50  0001 C CNN
	1    5000 5050
	1    0    0    -1  
$EndComp
$Comp
L CP C8
U 1 1 59CADDDF
P 7350 5050
F 0 "C8" H 7375 5150 50  0000 L CNN
F 1 "10uF" H 7375 4950 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-A_EIA-3216-18_Reflow" H 7388 4900 50  0001 C CNN
F 3 "" H 7350 5050 50  0001 C CNN
	1    7350 5050
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 59CADE28
P 6200 3750
F 0 "C6" H 6225 3850 50  0000 L CNN
F 1 "10uF" H 6225 3650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6238 3600 50  0001 C CNN
F 3 "" H 6200 3750 50  0001 C CNN
	1    6200 3750
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 59CADE9D
P 7200 2900
F 0 "C7" H 7225 3000 50  0000 L CNN
F 1 "10uF" H 7225 2800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7238 2750 50  0001 C CNN
F 3 "" H 7200 2900 50  0001 C CNN
	1    7200 2900
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 59CAE08B
P 6950 5250
F 0 "R7" V 7030 5250 50  0000 C CNN
F 1 "1K" V 6950 5250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6880 5250 50  0001 C CNN
F 3 "" H 6950 5250 50  0001 C CNN
	1    6950 5250
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 59CAE0C9
P 6950 4900
F 0 "D2" H 6950 5000 50  0000 C CNN
F 1 "LED" H 6950 4800 50  0000 C CNN
F 2 "LEDs:LED_0805_HandSoldering" H 6950 4900 50  0001 C CNN
F 3 "" H 6950 4900 50  0001 C CNN
	1    6950 4900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR024
U 1 1 59CAE399
P 7750 5650
F 0 "#PWR024" H 7750 5400 50  0001 C CNN
F 1 "GND" H 7750 5500 50  0000 C CNN
F 2 "" H 7750 5650 50  0001 C CNN
F 3 "" H 7750 5650 50  0001 C CNN
	1    7750 5650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR025
U 1 1 59CAE3C0
P 7750 4450
F 0 "#PWR025" H 7750 4300 50  0001 C CNN
F 1 "+3.3V" H 7750 4590 50  0000 C CNN
F 2 "" H 7750 4450 50  0001 C CNN
F 3 "" H 7750 4450 50  0001 C CNN
	1    7750 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2250 6900 2250
Wire Wire Line
	6900 2250 6900 3100
Wire Wire Line
	6900 3100 6350 3100
Wire Wire Line
	6050 3100 5500 3100
Wire Wire Line
	5500 2450 5500 3200
Wire Wire Line
	5500 2450 5600 2450
Wire Wire Line
	7200 3050 7200 3100
Connection ~ 5500 3100
Wire Wire Line
	4800 3500 6900 3500
Wire Wire Line
	6200 3950 6900 3950
Wire Wire Line
	6900 3500 6900 3600
Wire Wire Line
	6200 3500 6200 3600
Wire Wire Line
	6200 3900 6200 4050
Connection ~ 6200 3950
Wire Wire Line
	6900 3950 6900 3900
Wire Wire Line
	6800 2650 7750 2650
Wire Wire Line
	7200 2750 7200 2650
Connection ~ 7200 2650
Wire Wire Line
	7050 2650 7050 1900
Wire Wire Line
	7050 1900 6600 1900
Connection ~ 7050 2650
Wire Wire Line
	6300 1900 6100 1900
Wire Wire Line
	5800 1900 5500 1900
Wire Wire Line
	5500 1900 5500 2250
Wire Wire Line
	5500 2250 5600 2250
Wire Wire Line
	5600 2650 4800 2650
Wire Wire Line
	4800 2650 4800 3900
Connection ~ 6200 3500
Wire Wire Line
	4800 4700 5750 4700
Wire Wire Line
	5450 4700 5450 5000
Wire Wire Line
	5450 5000 5750 5000
Connection ~ 5450 4700
Wire Wire Line
	5000 5450 7750 5450
Wire Wire Line
	5750 4850 5300 4850
Wire Wire Line
	5300 4850 5300 5450
Connection ~ 5300 5450
Wire Wire Line
	6650 4700 7750 4700
Wire Wire Line
	7750 4700 7750 4450
Wire Wire Line
	6950 4750 6950 4700
Connection ~ 6950 4700
Wire Wire Line
	6950 5050 6950 5100
Wire Wire Line
	6950 5400 6950 5450
Connection ~ 6950 5450
Wire Wire Line
	7750 5450 7750 5650
Wire Wire Line
	5000 5450 5000 5200
Wire Wire Line
	5000 4900 5000 4700
Connection ~ 5000 4700
Wire Wire Line
	7350 4700 7350 4900
Connection ~ 7350 4700
Wire Wire Line
	7350 5200 7350 5450
Connection ~ 7350 5450
Wire Wire Line
	4800 4700 4800 4300
Connection ~ 4800 3500
$EndSCHEMATC
