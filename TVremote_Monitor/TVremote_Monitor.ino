#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
//  irrecv.blink13(true);
}

void loop(){
    if (irrecv.decode(&results)){
        
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;
        switch(results.value){
          20DF22DD
          case 0x20DF22DD:
          Serial.println("OK");
          break;
          case 0x20DF02FD:
          Serial.println("FORWARD");
          break;
          case 0x20DF827D:
          Serial.println("BACK");
          break;
          case 0x20DF807F:
          Serial.println("CH-");
          break;
          case 0x20DF00FF:
          Serial.println("CH+");
          break;
        }
        key_value = results.value;
        irrecv.resume();
        Serial.println(key_value, HEX);
    }
}
