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

CCS811 sensor(&Wire /*IIC_ADDRESS=0x5A*/);

/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
int addr = 0;

void setup() {
    Serial.begin(115200);
    /*Wait for the chip to be initialized completely, and then exit*/
    while(sensor.begin() != 0){
        Serial.println("failed to init chip, please check if the chip connection is fine");
        delay(1000);
    }
    /**
     * @brief Set measurement cycle
     * @param cycle:in typedef enum{
     *                  eClosed,      //Idle (Measurements are disabled in this mode)
     *                  eCycle_1s,    //Constant power mode, IAQ measurement every second
     *                  eCycle_10s,   //Pulse heating mode IAQ measurement every 10 seconds
     *                  eCycle_60s,   //Low power pulse heating mode IAQ measurement every 60 seconds
     *                  eCycle_250ms  //Constant power mode, sensor measurement every 250ms
     *                  }eCycle_t;
     */
    sensor.setMeasCycle(sensor.eCycle_1s);

  //console for data testing


}


void loop() {
  delay(1000);
    if(sensor.checkDataReady() == true){
        String val = "CO2: " + String(sensor.getCO2PPM()) + "ppm, TVOC: " + String(sensor.getTVOCPPB()) + "ppb \n";
        EEPROM.put(addr, val);
        addr+= sizeof(val);
    }
   if (Serial.available() > 0) {
      for (int index = 0 ; index < EEPROM.length() ; index++) {
        Serial.print(EEPROM[ index ]);
      }
  }
    sensor.writeBaseLine(0x847B);
    //delay cannot be less than measurement cycle
    //delay(1000);
}
