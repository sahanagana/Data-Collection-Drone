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


  //console for data testing


}


void loop() {
  delay(1000);
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
    */
        
    /*!
     * @brief Set baseline
     * @param get from getBaseline.ino
     */

}
