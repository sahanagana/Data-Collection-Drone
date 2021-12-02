/*
 * EEPROM Write
 *
 * Stores values read from analog input 0 into the EEPROM.
 * These values will stay in the EEPROM when the board is
 * turned off and may be retrieved later by another sketch.
 */

#include <EEPROM.h>
//tvoc config
//#include <Console.h>
#include <CCS811.h>


void setup() {
    Serial.begin(115200);
    Serial.println("Clearing EEPROM..."):
    for (int i = 0 ; i < EEPROM.length() ; i++) {
      EEPROM.write(i, 0);
    }
}


void loop() {
  delay(1000);
  //do nothing

}
