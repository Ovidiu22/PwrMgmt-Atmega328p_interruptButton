# PwrMgmt-Atmega328p_interruptButton
 
Power Management of Atmega-328p

This sequence displays the possibility to save power by keeping the processor in sleep mode. Following sleep modes are available:

- SLEEP_MODE_IDLE
- SLEEP_MODE_ADC
- SLEEP_MODE_PWR_SAVE
- SLEEP_MODE_STANDBY
- SLEEP_MODE_PWR_DOWN


Wake-up is done using an external interrupt - a button on pin PIND2 (INT0).

For further details visit http://donalmorrissey.blogspot.com/2010/04/putting-arduino-diecimila-to-sleep.html or chapter 14 in Atmega datasheet.

# Schematic
![Schematic](https://user-images.githubusercontent.com/75970114/209919971-5533f2db-3d1c-490d-b57c-4596cf4a18c7.png)

