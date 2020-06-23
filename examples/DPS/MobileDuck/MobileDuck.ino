#include <ClusterDuck.h>

ClusterDuck duck;

unsigned long DELAY_TIME = 10000; // 1.5 sec
unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish

void setup() {
  // put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("D");
  duck.setupLoRa();
  duck.setupDisplay();
    
  delayStart = millis();   // start delay
  delayRunning = true; // not finished yet
}

void loop() {
  if(duck.getFlag()) {  //If LoRa packet received
    duck.flipFlag();
    duck.flipInterrupt();
    int pSize = duck.handlePacket();
    if(pSize > 0) {
      duck.getPacketData(pSize);
      Packet lastPacket = duck.getLastPacket();
    }
    duck.flipInterrupt();
    duck.startReceive();
  }



//   int packetSize = LoRa.parsePacket();
//   if (packetSize > 0) {
//     Serial.println("Ping Received");
//     int rssi = LoRa.packetRssi();
//     String fromWho = LoRa.readString();
//     if (fromWho.length() == 3) {
//       String payMe = "M01:" + fromWho + ":" + rssi;
// //      Serial.println("Ping Received");
// //      delay(1500);
// //      Serial.println("Ping Sent");
//       LoRa.beginPacket();
//       LoRa.print(payMe);
//       LoRa.endPacket();
//       Serial.println(payMe);
//       esp_restart();
//     }
//   }
}

