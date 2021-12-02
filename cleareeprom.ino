/*
 * EEPROM Clear
 *
 * Clear all values in eeprom.
 * Use after retrieving data.
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
