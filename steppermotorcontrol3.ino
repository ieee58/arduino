const int stepPin = 3; 
const int dirPin = 4; 
int buton=6;
int buton2=7;
int d;
int f;
int e=800;
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(buton, INPUT);
  pinMode(buton2, INPUT);
}
void loop() {
 d=digitalRead(buton);
 if(d==HIGH) {
    digitalWrite(dirPin,HIGH);
    for(int x = 0; x < 600; x++) {
    
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(e); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(e); 
  }  } 
  
  delay(500);

  
 f=digitalRead(buton2);
if(f==HIGH){
  digitalWrite(dirPin,LOW);
  for(int x = 0; x < 600; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(e);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(e);
  }}
  delay(500);
} 

