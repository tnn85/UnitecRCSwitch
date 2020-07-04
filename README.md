# Unitec remote control switch Arduino library
Switch Unitec 433Mhz remote controlled sockets
https://github.com/tnn85/UnitecRCSwitch   

## License
Arduino Button Library Copyright (C) 2020 Till Nenz GNU GPL v3.0

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License v3.0 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/gpl.html>

## Introduction
The Unitec Remote Control Switch library is switching on/off 433Mhz remote control wall socket adapters made or distributed by Unitec (Model: 48110). 

Unitec 433Mhz radio transmission protocol is unique and doesn't use the well known "1", "0", "F" tristate code word. It only uses bit pattern "F" (01) and a new bit pattern "Q" (10) which is not supported by rc-switch library.

Furthermore the sender uses a rolling code (each button sends 4 different codes in a rolling procedure). However, the receiver (the wall socket) does seem to accept only one code. 

Nevertheless the rolling code was implemented in this library nevertheless.

In order to send the right codes which are accepted by your particular device, the codes for each button have to be sniffed with the "rc-switch" library (https://github.com/sui77/rc-switch) "ReceiveDemo_Simple.ino" example sketch and a 433Mhz receiver hooked up to the interrupt 0 pin of an Arduino (e.g. for Arduino Nano pin 2).

The data structure "ButtonCodes" hast to be defined in your sketch (see SimpleOnOff example) and the received codes  have to be stored in it and passed to the library.

In contrast to "rc-switch" library setBtnCodes(ButtonCodes \*codes) has to be called

## Examples
The following example sketches are included with the **UnitecRCSwitch** library:

- **SimpleOnOff**: Uses pin 11 to turn on and off a wall socket with Button A codes.

