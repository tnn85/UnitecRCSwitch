# Arduino Unitec Remote Control Switch Library
https://github.com/tnn85/UnitecRCSwitch 
README file  

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

In order to send the right codes the codes for each button has to be sniffed with the rc-switch library "ReceiveDemo_Simple.ino" sketch and a 433Mhz receiver hooked up to the interrupt pin of an Arduino.

The data structure "ButtonCodes" can be used to store the received codes and passed to the library.

## Examples
The following example sketches are included with the **Unitec Remote Control Switch** library:

- **SimpleOnOff**: Uses pin 11 to turn on and off a wall socket with Button A codes.

