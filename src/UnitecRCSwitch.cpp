/*-----------------------------------------------------------
  Library for controlling switching 433 Mhz remote controlled sockets from Unitec with pseudo rolling code

  by Till Nenz
  
  https://github.com/tnn85/UnitecRCSwitch
  -----------------------------------------------------------*/

#include "UnitecRCSwitch.h"

UnitecRCSwitch::UnitecRCSwitch() {
  this->_tx_pin = -1;
  this->_roll_index = 0;
  this->_codes = NULL;
}

UnitecRCSwitch::~UnitecRCSwitch() {
}

void UnitecRCSwitch::setBtnCodes(ButtonCodes *codes) {
  this->_codes = codes;
}


/**
   Enable transmissions

   @param nTransmitterPin    Arduino Pin to which the sender is connected to
*/
void UnitecRCSwitch::enableTransmit(int tx_pin) {
  this->_tx_pin = tx_pin;
  pinMode(this->_tx_pin, OUTPUT);
}

void UnitecRCSwitch::switchOn(WallSocket ws) {
  if (this->_roll_index > 3)
    this->_roll_index = 0;
  switch (ws) {
    case SOCKET_A: send((*this->_codes).btnAOnCodes[_roll_index++]); break;
    case SOCKET_B: send((*this->_codes).btnBOnCodes[_roll_index++]); break;
    case SOCKET_C: send((*this->_codes).btnCOnCodes[_roll_index++]); break;
    case SOCKET_D: send((*this->_codes).btnDOnCodes[_roll_index++]); break;
    default: Serial.println("Fehler\n"); break;
  }
}
void UnitecRCSwitch::switchOff(WallSocket ws) {
  if (this->_roll_index > 3)
    this->_roll_index = 0;
  switch (ws) {
    case SOCKET_A: send((*this->_codes).btnAOffCodes[_roll_index++]); break;
    case SOCKET_B: send((*this->_codes).btnBOffCodes[_roll_index++]); break;
    case SOCKET_C: send((*this->_codes).btnCOffCodes[_roll_index++]); break;
    case SOCKET_D: send((*this->_codes).btnDOffCodes[_roll_index++]); break;
    default: Serial.println("Fehler\n"); break;
  }
}

/**
   Send code

   @param code    Code as long value (24 Bit)
*/
void UnitecRCSwitch::send(long code) {
  int i, j, k;
  for (k = 0; k < 2; k++) { // Send 4 repetions (4 x 24 Bits) with short sync pause and another 4 repetions ( 4 x 24 Bits) with long sync pause
    for (j = 0; j < UNITEC_NUM_SEND_REPETIONS; j++) {
      if (k == 0) {
        this->pulse(1, 6);
      }
      else {
        this->pulse(8, 19);
      }
      for (i = 23; i >= 0; i--) { //24 Bits
        if (code & (1L << i)) { //Bit i = 1
          this->pulse(3, 1);
        }
        else {   //Bit i == 0
          this->pulse(1, 3);
        }
      }
    }
  }
}

/**
   Create pulse on digital out pin

   @param numLowPulses    Number of high pulse in multiples of UNITEC_PULSE_LENGTH
   @param numLowPulses    Number of low pulse in multiples of UNITEC_PULSE_LENGTH
*/
void UnitecRCSwitch::pulse(short numHighPulses, short numLowPulses) {
  digitalWrite(this->_tx_pin, HIGH);
  delayMicroseconds(UNITEC_PULSE_LENGTH * numHighPulses);
  digitalWrite(this->_tx_pin, LOW);
  delayMicroseconds(UNITEC_PULSE_LENGTH * numLowPulses);
}

//long UnitecRCSwitch::_switch_A_on_codes[UNITEC_NUM_ROLLINGCODES] = {13721648, 14595904, 13946480, 14372784};
//long UnitecRCSwitch::_switch_A_off_codes[UNITEC_NUM_ROLLINGCODES] = {13806992, 13996448, 14506528, 13831184};
//long UnitecRCSwitch::_switch_B_on_codes[UNITEC_NUM_ROLLINGCODES] = {14372788, 13946484, 14595908, 13721652};
//long UnitecRCSwitch::_switch_B_off_codes[UNITEC_NUM_ROLLINGCODES] = {13831188, 14506532, 13996452, 13806996};
//long UnitecRCSwitch::_switch_C_on_codes[UNITEC_NUM_ROLLINGCODES] = {14595916, 13721660, 14372796, 13946492};
//long UnitecRCSwitch::_switch_C_off_codes[UNITEC_NUM_ROLLINGCODES] = {13996460, 13807004, 13831196, 14506540};
//long UnitecRCSwitch::_switch_D_on_codes[UNITEC_NUM_ROLLINGCODES] = {13806994, 13996450, 14506530, 13831186};
//long UnitecRCSwitch::_switch_D_off_codes[UNITEC_NUM_ROLLINGCODES] = {13721650, 14595906, 13946482, 14372786};
