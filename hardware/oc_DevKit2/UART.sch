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
Sheet 3 5
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
L CP2102N U1
U 1 1 59C93D7F
P 5850 4600
F 0 "U1" H 5350 5950 60  0000 C CNN
F 1 "CP2102N" H 5500 4550 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-24_4x4mm_Pitch0.5mm" H 5700 4600 60  0001 C CNN
F 3 "" H 5700 4600 60  0001 C CNN
	1    5850 4600
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 59C9487D
P 4300 4000
F 0 "R4" V 4380 4000 50  0000 C CNN
F 1 "1K" V 4300 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4230 4000 50  0001 C CNN
F 3 "" H 4300 4000 50  0001 C CNN
	1    4300 4000
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 59C94915
P 2850 4150
F 0 "C3" H 2875 4250 50  0000 L CNN
F 1 "4.7uF" H 2875 4050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2888 4000 50  0001 C CNN
F 3 "" H 2850 4150 50  0001 C CNN
	1    2850 4150
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59C94A49
P 2100 4150
F 0 "C1" H 2125 4250 50  0000 L CNN
F 1 "4.7uF" H 2125 4050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2138 4000 50  0001 C CNN
F 3 "" H 2100 4150 50  0001 C CNN
	1    2100 4150
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 59C94A6F
P 2450 4150
F 0 "C2" H 2475 4250 50  0000 L CNN
F 1 "0.1uF" H 2475 4050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2488 4000 50  0001 C CNN
F 3 "" H 2450 4150 50  0001 C CNN
	1    2450 4150
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 59C94ADB
P 3200 4150
F 0 "C4" H 3225 4250 50  0000 L CNN
F 1 "0.1uF" H 3225 4050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3238 4000 50  0001 C CNN
F 3 "" H 3200 4150 50  0001 C CNN
	1    3200 4150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 59C94DA8
P 2650 4400
F 0 "#PWR017" H 2650 4150 50  0001 C CNN
F 1 "GND" H 2650 4250 50  0000 C CNN
F 2 "" H 2650 4400 50  0001 C CNN
F 3 "" H 2650 4400 50  0001 C CNN
	1    2650 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 59C94DCF
P 1900 4400
F 0 "#PWR018" H 1900 4150 50  0001 C CNN
F 1 "GND" H 1900 4250 50  0000 C CNN
F 2 "" H 1900 4400 50  0001 C CNN
F 3 "" H 1900 4400 50  0001 C CNN
	1    1900 4400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR019
U 1 1 59C94DEA
P 1900 3900
F 0 "#PWR019" H 1900 3750 50  0001 C CNN
F 1 "+5V" H 1900 4040 50  0000 C CNN
F 2 "" H 1900 3900 50  0001 C CNN
F 3 "" H 1900 3900 50  0001 C CNN
	1    1900 3900
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR020
U 1 1 59C94E0C
P 2650 3900
F 0 "#PWR020" H 2650 3750 50  0001 C CNN
F 1 "+3.3V" H 2650 4040 50  0000 C CNN
F 2 "" H 2650 3900 50  0001 C CNN
F 3 "" H 2650 3900 50  0001 C CNN
	1    2650 3900
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR021
U 1 1 59C94E58
P 4800 3300
F 0 "#PWR021" H 4800 3150 50  0001 C CNN
F 1 "+3.3V" H 4800 3440 50  0000 C CNN
F 2 "" H 4800 3300 50  0001 C CNN
F 3 "" H 4800 3300 50  0001 C CNN
	1    4800 3300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR022
U 1 1 59C94E99
P 4650 3050
F 0 "#PWR022" H 4650 2900 50  0001 C CNN
F 1 "+5V" H 4650 3190 50  0000 C CNN
F 2 "" H 4650 3050 50  0001 C CNN
F 3 "" H 4650 3050 50  0001 C CNN
	1    4650 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3800 4300 3800
Wire Wire Line
	4300 3800 4300 3850
Wire Wire Line
	4300 4150 4300 4200
Wire Wire Line
	4300 4200 5100 4200
Wire Wire Line
	1900 3900 2450 3900
Wire Wire Line
	2450 3900 2450 4000
Wire Wire Line
	2100 4000 2100 3900
Connection ~ 2100 3900
Wire Wire Line
	2450 4400 2450 4300
Wire Wire Line
	1900 4400 2450 4400
Wire Wire Line
	2100 4300 2100 4400
Connection ~ 2100 4400
Wire Wire Line
	2650 3900 3200 3900
Wire Wire Line
	3200 3900 3200 4000
Wire Wire Line
	2650 4400 3200 4400
Wire Wire Line
	3200 4400 3200 4300
Wire Wire Line
	2850 4400 2850 4300
Connection ~ 2850 4400
Wire Wire Line
	2850 4000 2850 3900
Connection ~ 2850 3900
Wire Wire Line
	4800 3900 4800 3300
Wire Wire Line
	4650 3050 4650 4100
Wire Wire Line
	4650 4000 5100 4000
Wire Wire Line
	4800 3900 5100 3900
Wire Wire Line
	4650 4100 5100 4100
Wire Wire Line
	4000 3600 5100 3600
Wire Wire Line
	4000 3700 5100 3700
Wire Wire Line
	6550 3700 7100 3700
Wire Wire Line
	6550 3800 7100 3800
Text HLabel 7100 3700 2    60   Input ~ 0
TXD
Text HLabel 7100 3800 2    60   Input ~ 0
RXD
Connection ~ 4650 4000
Text HLabel 4000 3600 0    60   Input ~ 0
D+
Text HLabel 4000 3700 0    60   Input ~ 0
D-
Text Notes 1750 4700 0    60   ~ 0
As close the power pins as possible
Text Notes 1850 3600 0    60   ~ 0
Power Filter Caps
Wire Notes Line
	1600 3450 3550 3450
Wire Notes Line
	3550 3450 3550 4750
Wire Notes Line
	3550 4750 1600 4750
Wire Notes Line
	1600 4750 1600 3450
Wire Wire Line
	4950 3800 4950 3900
Connection ~ 4950 3900
Connection ~ 4950 3800
$EndSCHEMATC
