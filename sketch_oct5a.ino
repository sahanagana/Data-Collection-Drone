//cloud config
#include <ThingerESP8266.h>

#define USERNAME
#define DEVICE_ID
#define DEVICE_CREDENTIAL

#define SSID
#define SSID_PASSWORD 

//initialize
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL)

void setup() {
  // setting up input sensors
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  //connect to wifi
  thing.add_wifi(SSID, SSID_PASSWORD);

  //console for data testing
  Console.begin()
  //create bridge
  Bridge.begin()

}

void loop() {
  // put your main code here, to run repeatedly:

}
