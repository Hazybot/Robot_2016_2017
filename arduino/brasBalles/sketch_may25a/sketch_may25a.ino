const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;

void setup(){
   pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
   pinMode(enablePin, OUTPUT); 
   
     digitalWrite(enablePin, HIGH);
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW);
}

void loop(){
  

  
}
