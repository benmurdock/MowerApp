// this header is needed for Bluetooth Serial -> works ONLY on ESP32
#include "BluetoothSerial.h"

// init Class:
BluetoothSerial ESP_BT;

// Parameters for Bluetooth interface
int incoming;

void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control");  //Name of your Bluetooth interface -> will show up on your phone
}

void loop() {

  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()) {
    incoming = ESP_BT.read();  //Read what we receive
       
    // ones place is key, hundred and ten place is value
    int value = floor(incoming / 10);
    int key = incoming % 10;


        // Serial.print("Key:"); Serial.print(key);
        // Serial.print("....Value:"); Serial.println(value);
        Serial.println(incoming);
        
        
        ESP_BT.write(incoming);
     
  }
}

