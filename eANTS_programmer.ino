
/**
 * This program is responsible for half duplex IR communication with
 * the eANTS for sensing and receiving various information.
 * TO do so, in essence, it addresses robots, the requests info and 
 * then listens for responses.
 * 
 * This program is also resonsible for programming the individual robots.
 * This is done by programatically putting them into bootloader mode
 * and then sending the new hex code over IR, as with normal data.
 */


 unsigned long readTime = 0;
 
 void setup() {
    //setRXEnabled(true);
    Serial.begin(9600);
    Serial1.begin(4800);
    //Serial2.begin(4800);
    delay(800);
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    //analogWrite(11, 127);
 }

 void loop(){
    if(Serial.available()){
      //setRXEnabled(false);
      //delay(1);
      Serial1.write(Serial.read());
      Serial1.flush();
      //delay(3);
      //while(Serial1.available())Serial1.read();
      //delay(1);
      //setRXEnabled(true);
    }
    if(Serial1.available()){
      Serial.write(Serial1.read());
    }
 }

/*
 void setRXEnabled(boolean value){
    if(value){
      digitalWrite(2, LOW);
    }else{
      digitalWrite(2, HIGH);
    }
 }
 */

