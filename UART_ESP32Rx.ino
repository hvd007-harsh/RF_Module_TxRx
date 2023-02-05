#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200,SERIAL_8N1);

}

void loop() {
while (! Serial.available());
if(Serial.available()){
uint8_t * datarcv  = (uint8_t*) Serial.read();
if(sizeof(datarcv) != 0){
unsigned char temp[1000]; 
 int j = 0;
 int count =0;
 for(int i = 0; i <sizeof(datarcv); i++){
   
      while(datarcv[j+count] != 0xD3 && datarcv[j+1+count] != 0x00 && datarcv[j+2+count] != 0x13 && datarcv[j+3+count] != 0x3E){
    
          if(datarcv[j] == 0xD3 && datarcv[j+1] == 0x00 && datarcv[j+2] == 0x13 && datarcv[j+3] == 0x3E){
     
             if(sizeof(temp)!=0){
                 delay(1000);
                 count= j;
                 j=0;
             }

          }
      Serial.print(datarcv[j]); 
      j++;
   }
 
  }
}
}
}
