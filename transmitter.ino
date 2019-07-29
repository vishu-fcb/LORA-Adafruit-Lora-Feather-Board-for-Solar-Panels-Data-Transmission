#include <SPI.h>
#include <RH_RF95.h>

//for feather m0
#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 3


// Change to 434.0 or other frequency, must match RX's freq!
#define RF95_FREQ 868.1
#define LED 13
uint32_t timer = millis();
RH_RF95 rf95(RFM95_CS, RFM95_INT);
char bufRX485[RH_RF95_MAX_MESSAGE_LEN];
void setup()
{
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  while (!Serial1);
  Serial.begin(19200);
  delay(100);
  Serial1.begin(19200);
  delay(100);

  Serial.println("Feather LoRa TX Test!");
  delay(10);

  // manual reset
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  while (!rf95.init()) {
    Serial.println("LoRa radio init failed");
    while (1);
  }
  Serial.println("LoRa radio init OK!");
  if (!rf95.setFrequency(RF95_FREQ)) {
    while (1);
  }
  Serial.print("Set Freq to: "); Serial.println(RF95_FREQ);

  rf95.setTxPower(23, false);
  delay(1000);
  digitalWrite(LED, LOW);
}

int16_t packetnum = 0;  // packet counter, we increment per xmission

void loop()
{
  char br;
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
  if (Serial1.available()) {
    br = Serial1.read();

    if (getTelegram() > 0) {
      sendLora();
    }
  }
}

int getTelegram() {
  char *p = bufRX485, str, br, output[9]="";
  int i , n , rs485count = 0;
  for (i = 0; i <= 1000; i++) {
    if (Serial1.available()) {
      br = Serial1.read();
//      if(isalpha(br)){
//      Serial.println("dwdsdd");        
//      }
//      else {
//      Serial.println("int");        
//      }
      
      Serial.println(br);
      *p = br;
      p++;
      rs485count++;
      itoa(br, output, 10);
      Serial.println(output);

      puts(output);
      ++br;
      rf95.send((uint8_t*)output, sizeof(output));
      rf95.waitPacketSent();

    }
    delay(10);
  }
  *p = 0;
  return (-1);
}
void sendLora() {
//  int i = 0, n ;
//  char bufTX[RH_RF95_MAX_MESSAGE_LEN];
//  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
//  uint8_t len = sizeof(buf);
//  uint8_t len2 = sizeof(bufRX485);
//  char *p = bufTX;
//
//
//  for (i = 0; i <= len2; i++) {
//    Serial.println(bufRX485[i], HEX);
//    if ((bufRX485[i-1] == 0x10) and (bufRX485[i]==0x03))
//    break;
//  }
//  Serial.println(bufRX485);
//  Serial.println(i);
//  //rf95.send((uint8_t *)bufRX485, strlen(bufRX485) + 1);
//  delay(1);
//  rf95.waitPacketSent();
//  delay(10);
}
