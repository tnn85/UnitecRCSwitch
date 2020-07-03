#include <UnitecRCSwitch.h>          // https://github.com/tnn85/UnitecRCSwitch


UnitecRCSwitch mySwitch;

UnitecRCSwitch::ButtonCodes codes = {
 {13721648, 14595904, 13946480, 14372784}, // Button A ON codes
 {13806992, 13996448, 14506528, 13831184}, // Button A OFF codes
 {14372788, 13946484, 14595908, 13721652}, // Button B ON codes
 {13831188, 14506532, 13996452, 13806996}, // Button B OFF codes
 {14595916, 13721660, 14372796, 13946492}, // Button C ON codes
 {13996460, 13807004, 13831196, 14506540}, // Button C OFF codes
 {13806994, 13996450, 14506530, 13831186}, // Button D ON codes
 {13721650, 14595906, 13946482, 14372786}, // Button D OFF codes
};

void setup() {

  Serial.begin(9600);
  
  mySwitch.setBtnCodes(&codes);
  
  // Transmitter is connected to Arduino Pin #11  
  mySwitch.enableTransmit(11);
  
}

void loop() {

  /* Turn switch A on */
  mySwitch.switchOn(UnitecRCSwitch::SOCKET_A);
  delay(1000); 
  /* Turn switch A off */  
  mySwitch.switchOff(UnitecRCSwitch::SOCKET_A);
  delay(1000);


  delay(8000);
}
