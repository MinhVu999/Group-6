#include <SPI.h>
#include <LoRa.h>

#define SS 10
#define RST 9
#define DIO0 2

void setup() {
    Serial.begin(9600);
    while (!Serial);
    
    Serial.println("LoRa Sender");
    
    LoRa.setPins(SS, RST, DIO0);
    
    if (!LoRa.begin(433E6)) {  // Chỉnh tần số theo module (433E6, 868E6, 915E6)
        Serial.println("LoRa init failed. Check connections.");
        while (1);
    }
}

void loop() {
    Serial.println("Sending packet...");
    
    LoRa.beginPacket();
    LoRa.print("Hello LoRa!");
    LoRa.endPacket();
    
    delay(2000);  // Gửi mỗi 2 giây
}
