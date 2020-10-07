#include "ESP8266WiFi.h"

const int aquisicoes = 60;
int count = 0;

void piscaLed(){
  int i = 0;
    for(i=0;i<15;i++){
      digitalWrite(LED_BUILTIN, HIGH);
      delay(200);
      digitalWrite(LED_BUILTIN, LOW);
      delay(200);
    }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
    count = 1;
    for(; count <= aquisicoes; count++){
      int n = WiFi.scanNetworks();
        
      if (n == 0) {
        Serial.println("network not found");
      } else {
        for (int i = 0; i < n; ++i) {
          if(WiFi.BSSIDstr(i)=="B0:BE:76:F7:87:0C"){
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println(WiFi.RSSI(i));
          }
        }
      }
    }

    if(count==aquisicoes){
      piscaLed();
    }
    
    Serial.println("");
    digitalWrite(LED_BUILTIN, HIGH);

}
