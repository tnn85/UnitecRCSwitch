/*-----------------------------------------------------------
  Library for controlling switching 433 Mhz remote controlled sockets from Unitec with pseudo rolling code

  by Till Nenz
  -----------------------------------------------------------*/

#ifndef UNITEC_RC_SWITCH_H
#define UNITEC_RC_SWITCH_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#include <stdint.h>

#define UNITEC_PULSE_LENGTH 380 // Min. pulse lenght in [µs]
#define UNITEC_NUM_SEND_REPETIONS 4
#define UNITEC_NUM_ROLLINGCODES 4
class UnitecRCSwitch {

  public:
    enum WallSocket {SOCKET_A, SOCKET_B, SOCKET_C, SOCKET_D};
    /**
     * A "ButtonCodes" lists all valid codes which for a the respective wall socket 
     * which can be obtained in the following manner:
     * 1) Hook up a 433Mhz receiver to an the interrupt pin of your Arduino board/microcontroller (e.g. pin 2 or 3 for Arduino Nano)
     * 2) Upload the "ReceiveDemo_Simple.ino" sketch example of the "rc-switch" library (https://github.com/sui77/rc-switch) 
     * 3) Press a button on the sender (A-D, ON and Off) as often as necessary until you receive the same code again (4 [=UNITEC_NUM_SEND_REPETIONS]  times for unitec 41120)
     * 4) Repeat this procedure for all buttons A-D and for both states "On" and "off" respectively
     * 5) Store the values store the decimal values in a struct of this type and pass it to the library
     */
    struct ButtonCodes {
        uint32_t btnAOnCodes[UNITEC_NUM_ROLLINGCODES];
        uint32_t btnAOffCodes[UNITEC_NUM_ROLLINGCODES];
        uint32_t btnBOnCodes[UNITEC_NUM_ROLLINGCODES];
        uint32_t btnBOffCodes[UNITEC_NUM_ROLLINGCODES];
        uint32_t btnCOnCodes[UNITEC_NUM_ROLLINGCODES];
        uint32_t btnCOffCodes[UNITEC_NUM_ROLLINGCODES];
        uint32_t btnDOnCodes[UNITEC_NUM_ROLLINGCODES];
        uint32_t btnDOffCodes[UNITEC_NUM_ROLLINGCODES];
    };
    UnitecRCSwitch();
    ~UnitecRCSwitch();
    void setBtnCodes (ButtonCodes *codes);
    void enableTransmit(int tx_pin = -1);
    void switchOn(WallSocket sw);
    void switchOff(WallSocket sw);
    void send(long code);
    


  private:
    
    void pulse(short numHighPulses, short numLowPulses);
    int _tx_pin;
    volatile int _roll_index;
    ButtonCodes *_codes;
};

#endif
