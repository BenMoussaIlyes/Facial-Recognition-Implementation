int thisPin = 12;
int maxBrightness = 60 ;
char c='N';
int waiting = 0 ;
float brightness ;

void setup() {
  Serial.begin(9600);
    pinMode(thisPin, OUTPUT);
    pinMode(11, OUTPUT);
digitalWrite(11, HIGH);

}

void loop() {
char inter=Serial.read();

if(inter=='Y' or inter=='N') {
c=inter;
   
            }
  if (waiting>0) {
    waiting-= 1 ;
    }

Serial.print("this is c : ");
Serial.println(c);
Serial.println(inter);

if (c !='Y' and waiting == 0 ) {
 brightness = analogRead(A1);
//Serial.println(brightness);


 if (brightness < 330 ) {brightness = 0 ; }
else if (brightness > 900 ) {brightness = maxBrightness ; }
else{
brightness=map (brightness, 330,900 , 0 ,maxBrightness ) ;
}
analogWrite(thisPin, brightness);
}
if(c=='Y') {
analogWrite(thisPin, 255);
waiting= 100 ;
            }
delay(2);

}