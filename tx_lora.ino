#include <SPI.h>
#include <RH_RF95.h>

// Define pin connections
#define RFM95_CS 10
#define RFM95_RST 9
#define RFM95_INT 2

// Define frequency (must match receiver)
#define RF95_FREQ 433.0

RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setup() {
  Serial.begin(9600);
  delay(100);

  // Reset LoRa module
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  if (!rf95.init()) {
    Serial.println("LoRa init failed");
    while (1);
  }

  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println("Set frequency failed");
    while (1);
  }

  rf95.setTxPower(13, false);  // 13 dBm

  Serial.println("LoRa transmitter initialized");
}

void loop() {
  const char *msg = "Halo dari pengirim!";
  rf95.send((uint8_t *)msg, strlen(msg));
  rf95.waitPacketSent();

  Serial.println("Pesan dikirim: ");
  Serial.println(msg);

  delay(3000); // kirim tiap 3 detik
}
