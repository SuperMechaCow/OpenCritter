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
P 6200 4600
F 0 "U1" H 5700 5950 60  0000 C CNN
F 1 "CP2102N" H 5850 4550 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-24_4x4mm_Pitch0.5mm" H 6050 4600 60  0001 C CNN
F 3 "" H 6050 4600 60  0001 C CNN
	1    6200 4600
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 59C9487D
P 4900 4000
F 0 "R4" V 4980 4000 50  0000 C CNN
F 1 "1K" V 4900 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4830 4000 50  0001 C CNN
F 3 "" H 4900 4000 50  0001 C CNN
	1    4900 4000
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 59C94915
P 4100 3900
F 0 "C3" H 4125 4000 50  0000 L CNN
F 1 "4.7uF" H 4125 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4138 3750 50  0001 C CNN
F 3 "" H 4100 3900 50  0001 C CNN
	1    4100 3900
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 59C94ADB
P 4450 3900
F 0 "C4" H 4475 4000 50  0000 L CNN
F 1 "0.1uF" H 4475 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4488 3750 50  0001 C CNN
F 3 "" H 4450 3900 50  0001 C CNN
	1    4450 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 59C94DA8
P 3900 4150
F 0 "#PWR017" H 3900 3900 50  0001 C CNN
F 1 "GND" H 3900 4000 50  0000 C CNN
F 2 "" H 3900 4150 50  0001 C CNN
F 3 "" H 3900 4150 50  0001 C CNN
	1    3900 4150
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR018
U 1 1 59C94E0C
P 3900 3650
F 0 "#PWR018" H 3900 3500 50  0001 C CNN
F 1 "+3.3V" H 3900 3790 50  0000 C CNN
F 2 "" H 3900 3650 50  0001 C CNN
F 3 "" H 3900 3650 50  0001 C CNN
	1    3900 3650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR019
U 1 1 59C94E58
P 5150 3300
F 0 "#PWR019" H 5150 3150 50  0001 C CNN
F 1 "+3.3V" H 5150 3440 50  0000 C CNN
F 2 "" H 5150 3300 50  0001 C CNN
F 3 "" H 5150 3300 50  0001 C CNN
	1    5150 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 3800 4900 3800
Wire Wire Line
	4900 3800 4900 3850
Wire Wire Line
	4900 4150 4900 4200
Wire Wire Line
	4900 4200 5450 4200
Wire Wire Line
	3900 3650 4450 3650
Wire Wire Line
	4450 3650 4450 3750
Wire Wire Line
	3900 4150 4450 4150
Wire Wire Line
	4450 4150 4450 4050
Wire Wire Line
	4100 4150 4100 4050
Connection ~ 4100 4150
Wire Wire Line
	4100 3750 4100 3650
Connection ~ 4100 3650
Wire Wire Line
	5150 3300 5150 4000
Wire Wire Line
	5150 4000 5450 4000
Wire Wire Line
	5150 3900 5450 3900
Wire Wire Line
	4900 3600 5450 3600
Wire Wire Line
	4900 3700 5450 3700
Wire Wire Line
	6900 3700 7450 3700
Wire Wire Line
	6900 3800 7450 3800
Text HLabel 7450 3700 2    60   Input ~ 0
TXD
Text HLabel 7450 3800 2    60   Input ~ 0
RXD
Text HLabel 4900 3600 0    60   Input ~ 0
D+
Text HLabel 4900 3700 0    60   Input ~ 0
D-
Connection ~ 5150 3900
$EndSCHEMATC
