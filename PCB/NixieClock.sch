EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 11693 16535 portrait
encoding utf-8
Sheet 1 1
Title "Nixie Clock"
Date "2019-08-26"
Rev "0.1"
Comp "GZT project"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L nixies:IN-12A N1
U 1 1 5D644170
P 9350 4450
F 0 "N1" H 9125 5275 50  0000 L BNN
F 1 "IN-12A" H 9350 4450 50  0000 L BNN
F 2 "nixies-us:IN-12-DSUB" H 9350 4600 50  0001 C CNN
F 3 "" H 9350 4450 60  0001 C CNN
	1    9350 4450
	1    0    0    -1  
$EndComp
$Comp
L nixies:IN-12A N2
U 1 1 5D64431F
P 9350 6000
F 0 "N2" H 9125 6825 50  0000 L BNN
F 1 "IN-12A" H 9350 6000 50  0000 L BNN
F 2 "nixies-us:IN-12-DSUB" H 9350 6150 50  0001 C CNN
F 3 "" H 9350 6000 60  0001 C CNN
	1    9350 6000
	1    0    0    -1  
$EndComp
$Comp
L nixies:IN-12A N3
U 1 1 5D644397
P 9350 8000
F 0 "N3" H 9000 8750 50  0000 L BNN
F 1 "IN-12A" H 9350 8000 50  0000 L BNN
F 2 "nixies-us:IN-12-DSUB" H 9350 8150 50  0001 C CNN
F 3 "" H 9350 8000 60  0001 C CNN
	1    9350 8000
	1    0    0    -1  
$EndComp
$Comp
L nixies:IN-12A N4
U 1 1 5D6443EC
P 9350 9550
F 0 "N4" H 9125 10375 50  0000 L BNN
F 1 "IN-12A" H 9350 9550 50  0000 L BNN
F 2 "nixies-us:IN-12-DSUB" H 9350 9700 50  0001 C CNN
F 3 "" H 9350 9550 60  0001 C CNN
	1    9350 9550
	1    0    0    -1  
$EndComp
$Comp
L nixies:IN-12A N5
U 1 1 5D644484
P 9350 11500
F 0 "N5" H 8950 12250 50  0000 L BNN
F 1 "IN-12A" H 9350 11500 50  0000 L BNN
F 2 "nixies-us:IN-12-DSUB" H 9350 11650 50  0001 C CNN
F 3 "" H 9350 11500 60  0001 C CNN
	1    9350 11500
	1    0    0    -1  
$EndComp
$Comp
L nixies:IN-12A N6
U 1 1 5D6444E9
P 9350 13050
F 0 "N6" H 9000 13800 50  0000 L BNN
F 1 "IN-12A" H 9350 13050 50  0000 L BNN
F 2 "nixies-us:IN-12-DSUB" H 9350 13200 50  0001 C CNN
F 3 "" H 9350 13050 60  0001 C CNN
	1    9350 13050
	1    0    0    -1  
$EndComp
$Comp
L Device1:Lamp_Neon NE1
U 1 1 5D645472
P 9300 6800
F 0 "NE1" V 9200 6500 50  0000 L CNN
F 1 "Lamp_Neon" V 9200 7000 50  0000 L CNN
F 2 "mynixies:NE2-NEON-BULB-DRILL" V 9300 6900 50  0001 C CNN
F 3 "" V 9300 6900 50  0001 C CNN
	1    9300 6800
	0    1    1    0   
$EndComp
$Comp
L Device1:Lamp_Neon NE2
U 1 1 5D6459B9
P 9300 7100
F 0 "NE2" V 9200 6800 50  0000 L CNN
F 1 "Lamp_Neon" V 9200 7300 50  0000 L CNN
F 2 "mynixies:NE2-NEON-BULB-DRILL" V 9300 7200 50  0001 C CNN
F 3 "" V 9300 7200 50  0001 C CNN
	1    9300 7100
	0    1    1    0   
$EndComp
$Comp
L Device1:Lamp_Neon NE3
U 1 1 5D646523
P 9300 10350
F 0 "NE3" V 9200 10050 50  0000 L CNN
F 1 "Lamp_Neon" V 9200 10550 50  0000 L CNN
F 2 "mynixies:NE2-NEON-BULB-DRILL" V 9300 10450 50  0001 C CNN
F 3 "" V 9300 10450 50  0001 C CNN
	1    9300 10350
	0    1    1    0   
$EndComp
$Comp
L Device1:Lamp_Neon NE4
U 1 1 5D64662F
P 9300 10600
F 0 "NE4" V 9200 10300 50  0000 L CNN
F 1 "Lamp_Neon" V 9200 10800 50  0000 L CNN
F 2 "mynixies:NE2-NEON-BULB-DRILL" V 9300 10700 50  0001 C CNN
F 3 "" V 9300 10700 50  0001 C CNN
	1    9300 10600
	0    1    1    0   
$EndComp
$Comp
L 74xx_IEEE1:74141 U9
U 1 1 5D647224
P 7900 4300
F 0 "U9" H 7900 4300 50  0000 C CNN
F 1 "74141" H 8200 3700 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 7900 4300 60  0001 C CNN
F 3 "" H 7900 4300 60  0001 C CNN
	1    7900 4300
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE1:74141 U10
U 1 1 5D647468
P 7900 5850
F 0 "U10" H 7900 5850 50  0000 C CNN
F 1 "74141" H 8200 5250 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 7900 5850 60  0001 C CNN
F 3 "" H 7900 5850 60  0001 C CNN
	1    7900 5850
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE1:74141 U11
U 1 1 5D6474EE
P 7900 7850
F 0 "U11" H 7900 7850 50  0000 C CNN
F 1 "74141" H 8200 7250 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 7900 7850 60  0001 C CNN
F 3 "" H 7900 7850 60  0001 C CNN
	1    7900 7850
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE1:74141 U12
U 1 1 5D6477BA
P 7900 9400
F 0 "U12" H 7900 9400 50  0000 C CNN
F 1 "74141" H 8200 8800 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 7900 9400 60  0001 C CNN
F 3 "" H 7900 9400 60  0001 C CNN
	1    7900 9400
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE1:74141 U13
U 1 1 5D647A50
P 7900 11350
F 0 "U13" H 7900 11350 50  0000 C CNN
F 1 "74141" H 8200 10750 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 7900 11350 60  0001 C CNN
F 3 "" H 7900 11350 60  0001 C CNN
	1    7900 11350
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE1:74141 U14
U 1 1 5D647AC5
P 7900 12900
F 0 "U14" H 7900 12900 50  0000 C CNN
F 1 "74141" H 8200 12300 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 7900 12900 60  0001 C CNN
F 3 "" H 7900 12900 60  0001 C CNN
	1    7900 12900
	1    0    0    -1  
$EndComp
$Comp
L 74xx1:74HC595 U5
U 1 1 5D648D79
P 6200 5050
F 0 "U5" H 5900 5600 50  0000 C CNN
F 1 "74HC595" H 5900 4400 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 6200 5050 50  0001 C CNN
F 3 "" H 6200 5050 50  0001 C CNN
	1    6200 5050
	1    0    0    -1  
$EndComp
$Comp
L 74xx1:74HC595 U6
U 1 1 5D64948D
P 6200 8600
F 0 "U6" H 5900 9150 50  0000 C CNN
F 1 "74HC595" H 5900 7950 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 6200 8600 50  0001 C CNN
F 3 "" H 6200 8600 50  0001 C CNN
	1    6200 8600
	1    0    0    -1  
$EndComp
$Comp
L 74xx1:74HC595 U7
U 1 1 5D649583
P 6200 12100
F 0 "U7" H 5900 12650 50  0000 C CNN
F 1 "74HC595" H 5900 11450 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 6200 12100 50  0001 C CNN
F 3 "" H 6200 12100 50  0001 C CNN
	1    6200 12100
	1    0    0    -1  
$EndComp
$Comp
L Device1:R R3
U 1 1 5D64B297
P 10050 4450
F 0 "R3" V 10130 4450 50  0000 C CNN
F 1 "1.5K" V 10050 4450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 4450 50  0001 C CNN
F 3 "" H 10050 4450 50  0001 C CNN
	1    10050 4450
	0    1    1    0   
$EndComp
$Comp
L Device1:R R4
U 1 1 5D64B56C
P 10050 6000
F 0 "R4" V 10130 6000 50  0000 C CNN
F 1 "1.5K" V 10050 6000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 6000 50  0001 C CNN
F 3 "" H 10050 6000 50  0001 C CNN
	1    10050 6000
	0    1    1    0   
$EndComp
$Comp
L Device1:R R7
U 1 1 5D64B628
P 10050 8000
F 0 "R7" V 10130 8000 50  0000 C CNN
F 1 "1.5K" V 10050 8000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 8000 50  0001 C CNN
F 3 "" H 10050 8000 50  0001 C CNN
	1    10050 8000
	0    1    1    0   
$EndComp
$Comp
L Device1:R R8
U 1 1 5D64B6F0
P 10050 9550
F 0 "R8" V 10130 9550 50  0000 C CNN
F 1 "1.5K" V 10050 9550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 9550 50  0001 C CNN
F 3 "" H 10050 9550 50  0001 C CNN
	1    10050 9550
	0    1    1    0   
$EndComp
$Comp
L Device1:R R11
U 1 1 5D64C15A
P 10050 11500
F 0 "R11" V 10130 11500 50  0000 C CNN
F 1 "1.5K" V 10050 11500 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 11500 50  0001 C CNN
F 3 "" H 10050 11500 50  0001 C CNN
	1    10050 11500
	0    1    1    0   
$EndComp
$Comp
L Device1:R R12
U 1 1 5D64C234
P 10050 13050
F 0 "R12" V 10130 13050 50  0000 C CNN
F 1 "1.5K" V 10050 13050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 13050 50  0001 C CNN
F 3 "" H 10050 13050 50  0001 C CNN
	1    10050 13050
	0    1    1    0   
$EndComp
$Comp
L Device1:R R9
U 1 1 5D64C303
P 10050 10350
F 0 "R9" V 10130 10350 50  0000 C CNN
F 1 "180K" V 10050 10350 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 10350 50  0001 C CNN
F 3 "" H 10050 10350 50  0001 C CNN
	1    10050 10350
	0    1    1    0   
$EndComp
$Comp
L Device1:R R10
U 1 1 5D64C3F6
P 10050 10600
F 0 "R10" V 10130 10600 50  0000 C CNN
F 1 "180K" V 10050 10600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 10600 50  0001 C CNN
F 3 "" H 10050 10600 50  0001 C CNN
	1    10050 10600
	0    1    1    0   
$EndComp
$Comp
L Device1:R R5
U 1 1 5D64C49F
P 10050 6800
F 0 "R5" V 10130 6800 50  0000 C CNN
F 1 "180K" V 10050 6800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 6800 50  0001 C CNN
F 3 "" H 10050 6800 50  0001 C CNN
	1    10050 6800
	0    1    1    0   
$EndComp
$Comp
L Device1:R R6
U 1 1 5D64C8AD
P 10050 7100
F 0 "R6" V 10130 7100 50  0000 C CNN
F 1 "180K" V 10050 7100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9980 7100 50  0001 C CNN
F 3 "" H 10050 7100 50  0001 C CNN
	1    10050 7100
	0    1    1    0   
$EndComp
$Comp
L MCU_Module1:WeMos_D1_mini U2
U 1 1 5D656ABC
P 2600 5100
F 0 "U2" H 2750 5850 50  0000 L CNN
F 1 "WeMos_D1_mini" H 2650 4350 50  0000 L CNN
F 2 "Modules:Pololu_Breakout-16_15.2x20.3mm" H 2600 3950 50  0001 C CNN
F 3 "" H 750 3950 50  0001 C CNN
	1    2600 5100
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear1:L7805 U1
U 1 1 5D656F44
P 2400 1250
F 0 "U1" H 2250 1375 50  0000 C CNN
F 1 "L7805" H 2400 1375 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220-3_Vertical" H 2425 1100 50  0001 L CIN
F 3 "" H 2400 1200 50  0001 C CNN
	1    2400 1250
	1    0    0    -1  
$EndComp
$Comp
L Connector1:Barrel_Jack J1
U 1 1 5D657187
P 1100 1350
F 0 "J1" H 1100 1560 50  0000 C CNN
F 1 "Barrel_Jack" H 1100 1150 50  0000 C CNN
F 2 "Connectors:BARREL_JACK" H 1150 1310 50  0001 C CNN
F 3 "" H 1150 1310 50  0001 C CNN
	1    1100 1350
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR2
U 1 1 5D6575F4
P 1500 1800
F 0 "#PWR2" H 1500 1550 50  0001 C CNN
F 1 "GND" H 1500 1650 50  0000 C CNN
F 2 "" H 1500 1800 50  0001 C CNN
F 3 "" H 1500 1800 50  0001 C CNN
	1    1500 1800
	1    0    0    -1  
$EndComp
$Comp
L power1:+12V #PWR1
U 1 1 5D65771F
P 1500 1150
F 0 "#PWR1" H 1500 1000 50  0001 C CNN
F 1 "+12V" H 1500 1290 50  0000 C CNN
F 2 "" H 1500 1150 50  0001 C CNN
F 3 "" H 1500 1150 50  0001 C CNN
	1    1500 1150
	1    0    0    -1  
$EndComp
$Comp
L Device1:C C1
U 1 1 5D657E20
P 1900 1500
F 0 "C1" H 1925 1600 50  0000 L CNN
F 1 "470nF" H 1925 1400 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 1938 1350 50  0001 C CNN
F 3 "" H 1900 1500 50  0001 C CNN
	1    1900 1500
	1    0    0    -1  
$EndComp
$Comp
L Device1:C C2
U 1 1 5D658746
P 2800 1500
F 0 "C2" H 2825 1600 50  0000 L CNN
F 1 "470nF" H 2825 1400 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 2838 1350 50  0001 C CNN
F 3 "" H 2800 1500 50  0001 C CNN
	1    2800 1500
	1    0    0    -1  
$EndComp
$Comp
L power1:+5V #PWR6
U 1 1 5D658A91
P 2800 1150
F 0 "#PWR6" H 2800 1000 50  0001 C CNN
F 1 "+5V" H 2800 1290 50  0000 C CNN
F 2 "" H 2800 1150 50  0001 C CNN
F 3 "" H 2800 1150 50  0001 C CNN
	1    2800 1150
	1    0    0    -1  
$EndComp
$Comp
L power1:+5V #PWR3
U 1 1 5D658FEB
P 2500 4200
F 0 "#PWR3" H 2500 4050 50  0001 C CNN
F 1 "+5V" H 2500 4340 50  0000 C CNN
F 2 "" H 2500 4200 50  0001 C CNN
F 3 "" H 2500 4200 50  0001 C CNN
	1    2500 4200
	1    0    0    -1  
$EndComp
NoConn ~ 2200 4700
NoConn ~ 2200 5000
NoConn ~ 2200 5100
$Comp
L power1:GND #PWR4
U 1 1 5D65932C
P 2600 6150
F 0 "#PWR4" H 2600 5900 50  0001 C CNN
F 1 "GND" H 2600 6000 50  0000 C CNN
F 2 "" H 2600 6150 50  0001 C CNN
F 3 "" H 2600 6150 50  0001 C CNN
	1    2600 6150
	1    0    0    -1  
$EndComp
NoConn ~ 3000 4600
$Comp
L Sensor1:BME280 U3
U 1 1 5D65BAAA
P 3550 3250
F 0 "U3" H 3200 3700 50  0000 C CNN
F 1 "BME280" H 3850 3700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Horizontal" H 5050 2800 50  0001 C CNN
F 3 "" H 3550 3050 50  0001 C CNN
	1    3550 3250
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR9
U 1 1 5D65BEAB
P 3450 4000
F 0 "#PWR9" H 3450 3750 50  0001 C CNN
F 1 "GND" H 3450 3850 50  0000 C CNN
F 2 "" H 3450 4000 50  0001 C CNN
F 3 "" H 3450 4000 50  0001 C CNN
	1    3450 4000
	1    0    0    -1  
$EndComp
$Comp
L power1:+3.3V #PWR5
U 1 1 5D65D634
P 2700 4200
F 0 "#PWR5" H 2700 4050 50  0001 C CNN
F 1 "+3.3V" H 2700 4340 50  0000 C CNN
F 2 "" H 2700 4200 50  0001 C CNN
F 3 "" H 2700 4200 50  0001 C CNN
	1    2700 4200
	1    0    0    -1  
$EndComp
$Comp
L power1:+3.3V #PWR8
U 1 1 5D65D9F8
P 3450 2550
F 0 "#PWR8" H 3450 2400 50  0001 C CNN
F 1 "+3.3V" H 3450 2690 50  0000 C CNN
F 2 "" H 3450 2550 50  0001 C CNN
F 3 "" H 3450 2550 50  0001 C CNN
	1    3450 2550
	1    0    0    -1  
$EndComp
NoConn ~ 3650 2650
NoConn ~ 3650 3850
$Comp
L power1:VCC #PWR7
U 1 1 5D66003C
P 3000 1150
F 0 "#PWR7" H 3000 1000 50  0001 C CNN
F 1 "VCC" H 3000 1300 50  0000 C CNN
F 2 "" H 3000 1150 50  0001 C CNN
F 3 "" H 3000 1150 50  0001 C CNN
	1    3000 1150
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR13
U 1 1 5D660F95
P 6200 5850
F 0 "#PWR13" H 6200 5600 50  0001 C CNN
F 1 "GND" H 6200 5700 50  0000 C CNN
F 2 "" H 6200 5850 50  0001 C CNN
F 3 "" H 6200 5850 50  0001 C CNN
	1    6200 5850
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR15
U 1 1 5D6611E7
P 6200 9400
F 0 "#PWR15" H 6200 9150 50  0001 C CNN
F 1 "GND" H 6200 9250 50  0000 C CNN
F 2 "" H 6200 9400 50  0001 C CNN
F 3 "" H 6200 9400 50  0001 C CNN
	1    6200 9400
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR17
U 1 1 5D661E29
P 6200 12900
F 0 "#PWR17" H 6200 12650 50  0001 C CNN
F 1 "GND" H 6200 12750 50  0000 C CNN
F 2 "" H 6200 12900 50  0001 C CNN
F 3 "" H 6200 12900 50  0001 C CNN
	1    6200 12900
	1    0    0    -1  
$EndComp
$Comp
L power1:VCC #PWR12
U 1 1 5D66317D
P 6200 4350
F 0 "#PWR12" H 6200 4200 50  0001 C CNN
F 1 "VCC" H 6200 4500 50  0000 C CNN
F 2 "" H 6200 4350 50  0001 C CNN
F 3 "" H 6200 4350 50  0001 C CNN
	1    6200 4350
	1    0    0    -1  
$EndComp
$Comp
L power1:VCC #PWR14
U 1 1 5D66346E
P 6200 7900
F 0 "#PWR14" H 6200 7750 50  0001 C CNN
F 1 "VCC" H 6200 8050 50  0000 C CNN
F 2 "" H 6200 7900 50  0001 C CNN
F 3 "" H 6200 7900 50  0001 C CNN
	1    6200 7900
	1    0    0    -1  
$EndComp
$Comp
L power1:VCC #PWR16
U 1 1 5D6635B7
P 6200 11400
F 0 "#PWR16" H 6200 11250 50  0001 C CNN
F 1 "VCC" H 6200 11550 50  0000 C CNN
F 2 "" H 6200 11400 50  0001 C CNN
F 3 "" H 6200 11400 50  0001 C CNN
	1    6200 11400
	1    0    0    -1  
$EndComp
$Comp
L 74xx1:74HC595 U4
U 1 1 5D6654F3
P 3550 8600
F 0 "U4" H 3250 9150 50  0000 C CNN
F 1 "74HC595" H 3250 7950 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 3550 8600 50  0001 C CNN
F 3 "" H 3550 8600 50  0001 C CNN
	1    3550 8600
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR11
U 1 1 5D665502
P 3550 9400
F 0 "#PWR11" H 3550 9150 50  0001 C CNN
F 1 "GND" H 3550 9250 50  0000 C CNN
F 2 "" H 3550 9400 50  0001 C CNN
F 3 "" H 3550 9400 50  0001 C CNN
	1    3550 9400
	1    0    0    -1  
$EndComp
$Comp
L power1:VCC #PWR10
U 1 1 5D665509
P 3550 7900
F 0 "#PWR10" H 3550 7750 50  0001 C CNN
F 1 "VCC" H 3550 8050 50  0000 C CNN
F 2 "" H 3550 7900 50  0001 C CNN
F 3 "" H 3550 7900 50  0001 C CNN
	1    3550 7900
	1    0    0    -1  
$EndComp
NoConn ~ 3950 9100
NoConn ~ 3950 8900
NoConn ~ 3950 8800
NoConn ~ 3950 8700
NoConn ~ 3950 8600
$Comp
L Transistor_BJT1:MPSA42 Q2
U 1 1 5D6668B3
P 6300 6700
F 0 "Q2" H 6500 6775 50  0000 L CNN
F 1 "MPSA42" H 6500 6700 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 6500 6625 50  0001 L CIN
F 3 "" H 6300 6700 50  0001 L CNN
	1    6300 6700
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT1:MPSA42 Q4
U 1 1 5D666C2F
P 6800 7100
F 0 "Q4" H 7000 7175 50  0000 L CNN
F 1 "MPSA42" H 7000 7100 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 7000 7025 50  0001 L CIN
F 3 "" H 6800 7100 50  0001 L CNN
	1    6800 7100
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR19
U 1 1 5D667208
P 6650 7450
F 0 "#PWR19" H 6650 7200 50  0001 C CNN
F 1 "GND" H 6650 7300 50  0000 C CNN
F 2 "" H 6650 7450 50  0001 C CNN
F 3 "" H 6650 7450 50  0001 C CNN
	1    6650 7450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT1:MPSA42 Q1
U 1 1 5D66829E
P 6200 10300
F 0 "Q1" H 6400 10375 50  0000 L CNN
F 1 "MPSA42" H 6400 10300 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 6400 10225 50  0001 L CIN
F 3 "" H 6200 10300 50  0001 L CNN
	1    6200 10300
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT1:MPSA42 Q3
U 1 1 5D6682A4
P 6700 10700
F 0 "Q3" H 6900 10775 50  0000 L CNN
F 1 "MPSA42" H 6900 10700 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 6900 10625 50  0001 L CIN
F 3 "" H 6700 10700 50  0001 L CNN
	1    6700 10700
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR18
U 1 1 5D6682B1
P 6550 11050
F 0 "#PWR18" H 6550 10800 50  0001 C CNN
F 1 "GND" H 6550 10900 50  0000 C CNN
F 2 "" H 6550 11050 50  0001 C CNN
F 3 "" H 6550 11050 50  0001 C CNN
	1    6550 11050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 12450 8650 12450
Wire Wire Line
	8650 12450 8650 13450
Wire Wire Line
	8650 13450 8850 13450
Wire Wire Line
	8500 12550 8850 12550
Wire Wire Line
	8500 12650 8850 12650
Wire Wire Line
	8500 12750 8850 12750
Wire Wire Line
	8500 12850 8850 12850
Wire Wire Line
	8500 12950 8850 12950
Wire Wire Line
	8500 13050 8850 13050
Wire Wire Line
	8500 13150 8850 13150
Wire Wire Line
	8500 13250 8850 13250
Wire Wire Line
	8500 13350 8850 13350
Wire Wire Line
	8500 10900 8650 10900
Wire Wire Line
	8650 10900 8650 11900
Wire Wire Line
	8650 11900 8850 11900
Wire Wire Line
	8500 11000 8850 11000
Wire Wire Line
	8500 11100 8850 11100
Wire Wire Line
	8500 11200 8850 11200
Wire Wire Line
	8500 11300 8850 11300
Wire Wire Line
	8500 11400 8850 11400
Wire Wire Line
	8500 11500 8850 11500
Wire Wire Line
	8500 11600 8850 11600
Wire Wire Line
	8500 11700 8850 11700
Wire Wire Line
	8500 11800 8850 11800
Wire Wire Line
	8500 7400 8650 7400
Wire Wire Line
	8650 7400 8650 8400
Wire Wire Line
	8650 8400 8850 8400
Wire Wire Line
	8500 7500 8850 7500
Wire Wire Line
	8500 7600 8850 7600
Wire Wire Line
	8500 7700 8850 7700
Wire Wire Line
	8500 7800 8850 7800
Wire Wire Line
	8500 7900 8850 7900
Wire Wire Line
	8500 8000 8850 8000
Wire Wire Line
	8500 8100 8850 8100
Wire Wire Line
	8500 8200 8850 8200
Wire Wire Line
	8500 8300 8850 8300
Wire Wire Line
	8500 8950 8650 8950
Wire Wire Line
	8650 8950 8650 9950
Wire Wire Line
	8650 9950 8850 9950
Wire Wire Line
	8500 9050 8850 9050
Wire Wire Line
	8500 9150 8850 9150
Wire Wire Line
	8500 9250 8850 9250
Wire Wire Line
	8500 9350 8850 9350
Wire Wire Line
	8500 9450 8850 9450
Wire Wire Line
	8500 9550 8850 9550
Wire Wire Line
	8500 9650 8850 9650
Wire Wire Line
	8500 9750 8850 9750
Wire Wire Line
	8500 9850 8850 9850
Wire Wire Line
	8500 5400 8650 5400
Wire Wire Line
	8650 5400 8650 6400
Wire Wire Line
	8650 6400 8850 6400
Wire Wire Line
	8500 5500 8850 5500
Wire Wire Line
	8500 5600 8850 5600
Wire Wire Line
	8500 5700 8850 5700
Wire Wire Line
	8500 5800 8850 5800
Wire Wire Line
	8500 5900 8850 5900
Wire Wire Line
	8500 6000 8850 6000
Wire Wire Line
	8500 6100 8850 6100
Wire Wire Line
	8500 6200 8850 6200
Wire Wire Line
	8500 6300 8850 6300
Wire Wire Line
	8500 3850 8650 3850
Wire Wire Line
	8650 3850 8650 4850
Wire Wire Line
	8650 4850 8850 4850
Wire Wire Line
	8500 3950 8850 3950
Wire Wire Line
	8500 4050 8850 4050
Wire Wire Line
	8500 4150 8850 4150
Wire Wire Line
	8500 4250 8850 4250
Wire Wire Line
	8500 4350 8850 4350
Wire Wire Line
	8500 4450 8850 4450
Wire Wire Line
	8500 4550 8850 4550
Wire Wire Line
	8500 4650 8850 4650
Wire Wire Line
	8500 4750 8850 4750
Wire Wire Line
	7300 4150 6800 4150
Wire Wire Line
	6800 4150 6800 4650
Wire Wire Line
	6800 4650 6600 4650
Wire Wire Line
	6600 4750 6900 4750
Wire Wire Line
	6900 4750 6900 4250
Wire Wire Line
	6900 4250 7300 4250
Wire Wire Line
	7300 4350 7000 4350
Wire Wire Line
	7000 4350 7000 4850
Wire Wire Line
	7000 4850 6600 4850
Wire Wire Line
	6600 4950 7100 4950
Wire Wire Line
	7100 4950 7100 4450
Wire Wire Line
	7100 4450 7300 4450
Wire Wire Line
	6600 5050 7100 5050
Wire Wire Line
	7100 5050 7100 5700
Wire Wire Line
	7100 5700 7300 5700
Wire Wire Line
	7300 5800 7000 5800
Wire Wire Line
	7000 5800 7000 5150
Wire Wire Line
	7000 5150 6600 5150
Wire Wire Line
	6600 5250 6900 5250
Wire Wire Line
	6900 5250 6900 5900
Wire Wire Line
	6900 5900 7300 5900
Wire Wire Line
	7300 6000 6800 6000
Wire Wire Line
	6800 6000 6800 5350
Wire Wire Line
	6800 5350 6600 5350
Wire Wire Line
	7300 7700 6800 7700
Wire Wire Line
	6800 7700 6800 8200
Wire Wire Line
	6800 8200 6600 8200
Wire Wire Line
	6600 8300 6900 8300
Wire Wire Line
	6900 8300 6900 7800
Wire Wire Line
	6900 7800 7300 7800
Wire Wire Line
	7300 7900 7000 7900
Wire Wire Line
	7000 7900 7000 8400
Wire Wire Line
	7000 8400 6600 8400
Wire Wire Line
	6600 8500 7100 8500
Wire Wire Line
	7100 8500 7100 8000
Wire Wire Line
	7100 8000 7300 8000
Wire Wire Line
	6600 8600 7100 8600
Wire Wire Line
	7100 8600 7100 9250
Wire Wire Line
	7100 9250 7300 9250
Wire Wire Line
	7300 9350 7000 9350
Wire Wire Line
	7000 9350 7000 8700
Wire Wire Line
	7000 8700 6600 8700
Wire Wire Line
	6600 8800 6900 8800
Wire Wire Line
	6900 8800 6900 9450
Wire Wire Line
	6900 9450 7300 9450
Wire Wire Line
	7300 9550 6800 9550
Wire Wire Line
	6800 9550 6800 8900
Wire Wire Line
	6800 8900 6600 8900
Wire Wire Line
	7300 11200 6800 11200
Wire Wire Line
	6800 11200 6800 11700
Wire Wire Line
	6800 11700 6600 11700
Wire Wire Line
	6600 11800 6900 11800
Wire Wire Line
	6900 11800 6900 11300
Wire Wire Line
	6900 11300 7300 11300
Wire Wire Line
	7300 11400 7000 11400
Wire Wire Line
	7000 11400 7000 11900
Wire Wire Line
	7000 11900 6600 11900
Wire Wire Line
	6600 12000 7100 12000
Wire Wire Line
	7100 12000 7100 11500
Wire Wire Line
	7100 11500 7300 11500
Wire Wire Line
	6600 12100 7100 12100
Wire Wire Line
	7100 12100 7100 12750
Wire Wire Line
	7100 12750 7300 12750
Wire Wire Line
	7300 12850 7000 12850
Wire Wire Line
	7000 12850 7000 12200
Wire Wire Line
	7000 12200 6600 12200
Wire Wire Line
	6600 12300 6900 12300
Wire Wire Line
	6900 12300 6900 12950
Wire Wire Line
	6900 12950 7300 12950
Wire Wire Line
	7300 13050 6800 13050
Wire Wire Line
	6800 13050 6800 12400
Wire Wire Line
	6800 12400 6600 12400
Wire Wire Line
	6600 5550 6700 5550
Wire Wire Line
	6700 5550 6700 6000
Wire Wire Line
	6700 6000 5700 6000
Wire Wire Line
	5700 6000 5700 8200
Wire Wire Line
	5700 8200 5800 8200
Wire Wire Line
	6600 9100 6700 9100
Wire Wire Line
	6700 9100 6700 9550
Wire Wire Line
	6700 9550 5700 9550
Wire Wire Line
	5700 9550 5700 11700
Wire Wire Line
	5700 11700 5800 11700
Wire Wire Line
	5800 5250 5700 5250
Wire Wire Line
	5700 5250 5700 5850
Wire Wire Line
	5700 5850 6200 5850
Wire Wire Line
	6200 5850 6200 5750
Wire Wire Line
	5500 4950 5800 4950
Wire Wire Line
	5500 4350 6200 4350
Wire Wire Line
	6200 4350 6200 4450
Wire Wire Line
	6200 7900 6200 8000
Wire Wire Line
	5800 8800 5700 8800
Wire Wire Line
	5700 8800 5700 9400
Wire Wire Line
	5700 9400 6200 9400
Wire Wire Line
	6200 9400 6200 9300
Wire Wire Line
	5800 12300 5700 12300
Wire Wire Line
	5700 12300 5700 12900
Wire Wire Line
	5700 12900 6200 12900
Wire Wire Line
	6200 12900 6200 12800
Wire Wire Line
	5500 12200 5800 12200
Wire Wire Line
	5500 5150 5500 6400
Wire Wire Line
	5500 8700 5800 8700
Wire Wire Line
	5600 11900 5800 11900
Wire Wire Line
	5600 4850 5600 6500
Wire Wire Line
	5600 8400 5800 8400
Wire Wire Line
	5250 5150 5500 5150
Connection ~ 5500 8700
Wire Wire Line
	5300 4850 5600 4850
Connection ~ 5600 8400
Wire Wire Line
	5500 4950 5500 4350
Wire Wire Line
	5800 8500 5400 8500
Wire Wire Line
	5400 8500 5400 7900
Wire Wire Line
	5400 7900 6200 7900
Wire Wire Line
	5800 12000 5400 12000
Wire Wire Line
	5400 12000 5400 11400
Wire Wire Line
	5400 11400 6200 11400
Wire Wire Line
	6200 11400 6200 11500
Wire Wire Line
	9750 4450 9900 4450
Wire Wire Line
	10350 4450 10200 4450
Wire Wire Line
	10350 6000 10200 6000
Connection ~ 10350 4450
Wire Wire Line
	9900 6000 9750 6000
Wire Wire Line
	9500 6800 9900 6800
Wire Wire Line
	9500 7100 9900 7100
Wire Wire Line
	10350 6800 10200 6800
Connection ~ 10350 6000
Wire Wire Line
	10350 7100 10200 7100
Connection ~ 10350 6800
Wire Wire Line
	10350 8000 10200 8000
Connection ~ 10350 7100
Wire Wire Line
	9900 8000 9750 8000
Wire Wire Line
	10350 9550 10200 9550
Connection ~ 10350 8000
Wire Wire Line
	9900 9550 9750 9550
Wire Wire Line
	10350 10350 10200 10350
Connection ~ 10350 9550
Wire Wire Line
	9900 10350 9500 10350
Wire Wire Line
	9900 10600 9500 10600
Wire Wire Line
	10350 10600 10200 10600
Connection ~ 10350 10350
Wire Wire Line
	10350 11500 10200 11500
Connection ~ 10350 10600
Wire Wire Line
	9900 11500 9750 11500
Wire Wire Line
	10350 13050 10200 13050
Connection ~ 10350 11500
Wire Wire Line
	9900 13050 9750 13050
Wire Wire Line
	1500 1250 1500 1150
Wire Wire Line
	1400 1450 1500 1450
Wire Wire Line
	1500 1450 1500 1750
Connection ~ 1500 1250
Wire Wire Line
	1900 1150 1900 1250
Connection ~ 1900 1250
Wire Wire Line
	1500 1750 1900 1750
Wire Wire Line
	1900 1650 1900 1750
Connection ~ 1500 1750
Wire Wire Line
	2400 1750 2400 1550
Connection ~ 1900 1750
Wire Wire Line
	2800 1750 2800 1650
Connection ~ 2400 1750
Wire Wire Line
	2700 1250 2800 1250
Wire Wire Line
	2800 1150 2800 1250
Connection ~ 2800 1250
Wire Wire Line
	2500 4200 2500 4300
Connection ~ 5600 4850
Wire Wire Line
	5800 4650 4450 4650
Wire Wire Line
	4450 4650 4450 4700
Wire Wire Line
	4450 4700 3000 4700
Wire Wire Line
	3000 4800 5300 4800
Wire Wire Line
	5300 4800 5300 4850
Wire Wire Line
	3000 4900 5250 4900
Wire Wire Line
	5250 4900 5250 5150
Connection ~ 5500 5150
Wire Wire Line
	3450 3850 3450 4000
Wire Wire Line
	3000 5200 4800 5200
Wire Wire Line
	4800 5200 4800 3150
Wire Wire Line
	4800 3150 4150 3150
Wire Wire Line
	4650 3350 4150 3350
Wire Wire Line
	4950 2950 4150 2950
Wire Wire Line
	4950 2950 4950 5300
Wire Wire Line
	4950 5300 3000 5300
Wire Wire Line
	4650 3350 4650 5400
Wire Wire Line
	4650 5400 3000 5400
Wire Wire Line
	3000 5500 4500 5500
Wire Wire Line
	4500 5500 4500 3550
Wire Wire Line
	4500 3550 4150 3550
Wire Wire Line
	2700 4200 2700 4300
Wire Wire Line
	3450 2650 3450 2550
Wire Wire Line
	3000 5100 3400 5100
Wire Wire Line
	3400 5100 3400 6150
Wire Wire Line
	3000 5000 3900 5000
Wire Wire Line
	3900 5000 3900 6050
Wire Wire Line
	3000 1250 3000 1150
Connection ~ 6200 12900
Connection ~ 6200 9400
Connection ~ 6200 5850
Connection ~ 6200 11400
Connection ~ 6200 7900
Connection ~ 6200 4350
Wire Wire Line
	2600 5900 2600 6150
Wire Wire Line
	2950 8200 3150 8200
Wire Wire Line
	3150 8800 3050 8800
Wire Wire Line
	3050 9400 3550 9400
Wire Wire Line
	3550 9400 3550 9300
Wire Wire Line
	2100 8700 3150 8700
Wire Wire Line
	2250 8400 3150 8400
Wire Wire Line
	3150 8500 2750 8500
Wire Wire Line
	2750 7900 3550 7900
Wire Wire Line
	3550 7900 3550 8000
Connection ~ 3550 9400
Connection ~ 3550 7900
Wire Wire Line
	3050 8800 3050 9400
Wire Wire Line
	2750 8500 2750 7900
Wire Wire Line
	2100 6400 2100 8700
Wire Wire Line
	2250 6500 2250 8400
Wire Wire Line
	6600 12600 6600 13450
Wire Wire Line
	6600 13450 2950 13450
Wire Wire Line
	2950 13450 2950 8200
Wire Wire Line
	9100 6800 7400 6800
Wire Wire Line
	7400 6800 7400 6400
Wire Wire Line
	7400 6400 6400 6400
Wire Wire Line
	6400 6400 6400 6500
Wire Wire Line
	9100 7100 7200 7100
Wire Wire Line
	7200 7100 7200 6800
Wire Wire Line
	7200 6800 6900 6800
Wire Wire Line
	6900 6800 6900 6900
Wire Wire Line
	6400 6900 6400 7400
Wire Wire Line
	6400 7400 6650 7400
Wire Wire Line
	6900 7400 6900 7300
Wire Wire Line
	6650 7450 6650 7400
Connection ~ 6650 7400
Wire Wire Line
	3950 8300 5300 8300
Wire Wire Line
	5300 8300 5300 7100
Wire Wire Line
	5300 7100 6600 7100
Wire Wire Line
	6100 6700 5200 6700
Wire Wire Line
	5200 6700 5200 8200
Wire Wire Line
	5200 8200 3950 8200
Wire Wire Line
	2100 6400 5500 6400
Connection ~ 5500 6400
Wire Wire Line
	2250 6500 5600 6500
Connection ~ 5600 6500
Wire Wire Line
	7300 10000 6300 10000
Wire Wire Line
	6300 10000 6300 10100
Wire Wire Line
	7100 10400 6800 10400
Wire Wire Line
	6800 10400 6800 10500
Wire Wire Line
	6300 10500 6300 11000
Wire Wire Line
	6300 11000 6550 11000
Wire Wire Line
	6800 11000 6800 10900
Wire Wire Line
	6550 11050 6550 11000
Connection ~ 6550 11000
Wire Wire Line
	5200 10700 6500 10700
Wire Wire Line
	7100 10400 7100 10600
Wire Wire Line
	7100 10600 9100 10600
Wire Wire Line
	7300 10000 7300 10350
Wire Wire Line
	7300 10350 9100 10350
Wire Wire Line
	3950 8400 5300 8400
Wire Wire Line
	5300 8400 5300 10300
Wire Wire Line
	5300 10300 6000 10300
Wire Wire Line
	5200 10700 5200 8500
Wire Wire Line
	5200 8500 3950 8500
Connection ~ 2600 6150
Wire Wire Line
	1400 1250 1500 1250
$Comp
L power1:PWR_FLAG #FLG1
U 1 1 5D66CB9A
P 1900 1150
F 0 "#FLG1" H 1900 1225 50  0001 C CNN
F 1 "PWR_FLAG" H 1900 1300 50  0000 C CNN
F 2 "" H 1900 1150 50  0001 C CNN
F 3 "" H 1900 1150 50  0001 C CNN
	1    1900 1150
	1    0    0    -1  
$EndComp
$Comp
L power1:PWR_FLAG #FLG2
U 1 1 5D66D7D7
P 1900 1800
F 0 "#FLG2" H 1900 1875 50  0001 C CNN
F 1 "PWR_FLAG" H 1900 1950 50  0000 C CNN
F 2 "" H 1900 1800 50  0001 C CNN
F 3 "" H 1900 1800 50  0001 C CNN
	1    1900 1800
	1    0    0    1   
$EndComp
$Comp
L Connector1:Conn_01x03_Male J3
U 1 1 5D6521C9
P 4150 6050
F 0 "J3" H 4150 6250 50  0000 C CNN
F 1 "Conn_01x03_Male" H 4150 5850 50  0000 C CNN
F 2 "Connectors_JST:JST_EH_B03B-EH-A_03x2.50mm_Straight" H 4150 6050 50  0001 C CNN
F 3 "" H 4150 6050 50  0001 C CNN
	1    4150 6050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3900 6050 3950 6050
Wire Wire Line
	3400 6150 3950 6150
Wire Wire Line
	2600 6150 3300 6150
Wire Wire Line
	3300 6150 3300 5950
Wire Wire Line
	3300 5950 3950 5950
Wire Wire Line
	10350 3400 10350 3650
$Comp
L power1:PWR_FLAG #FLG3
U 1 1 5D65A925
P 10100 3400
F 0 "#FLG3" H 10100 3475 50  0001 C CNN
F 1 "PWR_FLAG" H 10100 3550 50  0000 C CNN
F 2 "" H 10100 3400 50  0001 C CNN
F 3 "" H 10100 3400 50  0001 C CNN
	1    10100 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector1:Conn_01x03_Male J4
U 1 1 5D65B901
P 10450 3200
F 0 "J4" H 10450 3400 50  0000 C CNN
F 1 "Conn_01x03_Male" H 10450 3000 50  0000 C CNN
F 2 "Connectors_JST:JST_EH_B03B-EH-A_03x2.50mm_Straight" H 10450 3200 50  0001 C CNN
F 3 "" H 10450 3200 50  0001 C CNN
	1    10450 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	10100 3400 10100 3650
Wire Wire Line
	10100 3650 10350 3650
Connection ~ 10350 3650
$Comp
L power1:GND #PWR20
U 1 1 5D65C3C4
P 10550 3500
F 0 "#PWR20" H 10550 3250 50  0001 C CNN
F 1 "GND" H 10550 3350 50  0000 C CNN
F 2 "" H 10550 3500 50  0001 C CNN
F 3 "" H 10550 3500 50  0001 C CNN
	1    10550 3500
	1    0    0    -1  
$EndComp
$Comp
L power1:+12V #PWR21
U 1 1 5D65C53F
P 10750 3400
F 0 "#PWR21" H 10750 3250 50  0001 C CNN
F 1 "+12V" H 10750 3540 50  0000 C CNN
F 2 "" H 10750 3400 50  0001 C CNN
F 3 "" H 10750 3400 50  0001 C CNN
	1    10750 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 3400 10550 3500
Wire Wire Line
	10450 3400 10450 3650
Wire Wire Line
	10450 3650 10750 3650
Wire Wire Line
	10750 3650 10750 3400
Wire Wire Line
	5500 8700 5500 12200
Wire Wire Line
	5600 8400 5600 11900
Wire Wire Line
	10350 4450 10350 6000
Wire Wire Line
	10350 6000 10350 6800
Wire Wire Line
	10350 6800 10350 7100
Wire Wire Line
	10350 7100 10350 8000
Wire Wire Line
	10350 8000 10350 9550
Wire Wire Line
	10350 9550 10350 10350
Wire Wire Line
	10350 10350 10350 10600
Wire Wire Line
	10350 10600 10350 11500
Wire Wire Line
	10350 11500 10350 13050
Wire Wire Line
	1500 1250 1900 1250
Wire Wire Line
	1900 1250 1900 1350
Wire Wire Line
	1900 1250 2100 1250
Wire Wire Line
	1500 1750 1500 1800
Wire Wire Line
	1900 1750 2400 1750
Wire Wire Line
	1900 1750 1900 1800
Wire Wire Line
	2400 1750 2800 1750
Wire Wire Line
	2800 1250 3000 1250
Wire Wire Line
	2800 1250 2800 1350
Wire Wire Line
	5600 4850 5800 4850
Wire Wire Line
	5500 5150 5800 5150
Wire Wire Line
	6650 7400 6900 7400
Wire Wire Line
	5500 6400 5500 8700
Wire Wire Line
	5600 6500 5600 8400
Wire Wire Line
	6550 11000 6800 11000
Wire Wire Line
	10350 3650 10350 4450
$EndSCHEMATC
