#define arr_len( x )  ( sizeof( x ) / sizeof( *x ) )

const int hall0 = 2;
const int hall1 = 3;
const int hall2 = 4;
const int hall3 = 5;
const int maglock = 11;
const int greenLED =  12;
const int redLED = 13;
int halls[4] = {hall0, hall1, hall2, hall3};
int hallsLen = arr_len(halls);


void setup() {
  Serial.begin(9600);
  for(int i = 0; i < hallsLen; i++){
    pinMode(halls[i], INPUT);
  }
  pinMode(maglock, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  digitalWrite(maglock, LOW);
}

void loop(){
  bool aligned = true;
  for(int i = 0; i < hallsLen; i++){
    Serial.print("Hall");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(digitalRead(halls[i]));
    if(digitalRead(halls[i])){
      aligned = false;
    }
  }
  
  if (aligned) {     
    digitalWrite(maglock, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);  
  } 
  else {
    digitalWrite(maglock, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }
}
