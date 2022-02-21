
#include <OSFS.h>
#include <EEPROM.h>
uint16_t OSFS::startOfEEPROM = 1;
uint16_t OSFS::endOfEEPROM = 1024;

void OSFS::readNBytes(uint16_t address, unsigned int num, byte* output) {
  for (uint16_t i = address; i < address + num; i++) {
    *output = EEPROM.read(i);
    output++;
  }
}
void OSFS::writeNBytes(uint16_t address, unsigned int num, const byte* input) {
  for (uint16_t i = address; i < address + num; i++) {
    EEPROM.update(i, *input);
    input++;
  }
}

void setup() {
  // put your setup code here, to run once:
    Serial.begin(57600);
    //create variable, random value
    int testInt = 25;
    //save in file
    OSFS::newFile("testInt", testInt, true);
    //create newint value and set it to something else
    int newInt = 0;
    //use file to set newint to testint
    OSFS::getFile("testInt", newInt);
    //check if values are the same
    Serial.println(newInt);
}

void loop() {
  // put your main code here, to run repeatedly:

}
