#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
while (! Serial.available());
if(Serial.available()){

  // We have to store the value into hex 
//unsigned char datarcv  =Serial.read();
//We have to store the incoming data into the array of data. 
char rcvData[100];
Serial.readBytes(rcvData,100); 

for(int i =0 ; i < sizeof(rcvData) ; i++){
    if( (rcvData[i] == 0xD3 ) && (rcvData[i+1]== 0x00) && (rcvData[i+2] == 0x13) && (rcvData[i+3] == 0x3E)){
      Serial.print("\n");
    }
    Serial.print(rcvData[i],HEX); 
}

}

}
