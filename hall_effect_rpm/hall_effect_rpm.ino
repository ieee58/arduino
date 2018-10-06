#include<TimerOne.h>

const int SIGPIN = A0;
const float GAUSS_PER_STEP = 2.713; 
float rawValue = 0.0;
float value = 0.0;
float zeroLevel = 61;
volatile unsigned long timersayisi = 0;
int kount=0;
int rps=0;
float rpm=0;
int r_new=0;
int r_old=0;
int dif=0;
int time_dif=0;
int baslangic=0;


void setup() {
  Serial.begin(9600);
  pinMode(SIGPIN,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("hall effect sensor testin program");
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timerISR);
  baslangic=millis();
}


void loop(){
  
  rawValue = analogRead (SIGPIN) - zeroLevel;
  r_new=abs(rawValue);
  dif=r_new-r_old;
  dif=abs(dif);
  //Serial.print("value");
  //Serial.println(dif);
// if(rawValue >5 && rawValue<=15){

if( dif>3) {
   kount++;

   digitalWrite(LED_BUILTIN, HIGH);
   r_old=r_new;
    //Serial.print("gordu");

    if (kount==10){
    time_dif=millis()-baslangic;
    rpm=60000*10/time_dif;
    rpm=rpm/2;
    baslangic=millis();
        Serial.print(" td ");
    Serial.println(rpm);
    kount=0;
    }
}

else if(dif<3){
   digitalWrite(LED_BUILTIN, LOW);
   // Serial.print("gormedı");
  
  }
  
}

void timerISR()
{
 /*timersayisi++;
 //if(timersayisi > 10000)
 //{
 rps=0;
 rpm=0;
 rps=kount;
 rpm=60*rps;
  Serial.print("RPS");
  Serial.println(rps);
  Serial.print("RPM");
  Serial.println(rpm);
  kount=0;
  
  timersayisi=0;

 
*/
 
 } 


