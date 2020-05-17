#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd=LiquidCrystal(12,11,5,4,3,2);
Servo myservo1; 
Servo myservo2; 
int pos = 0; 
int in1=31;
int in2=33;
char* p="AC";
int a=0;
const int t=50;
const int e=51;
int jit=0;
int mo=0;
long duration;
int distance;

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={
  {'1', '2', '3', 'A' },
   {'4', '5', '6', 'B' },
    {'7', '8', '9', 'C' },
     {'*', '0', '#', 'D' }
};
byte rowPins[ROWS]= {24,26,28,30};
byte colPins[COLS]= {32,34,36,38};
Keypad keypad = Keypad (makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup()
{
  pinMode(t,OUTPUT);              
  pinMode(e,INPUT);
  pinMode(48,OUTPUT);
  lcd.begin(16,2);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
   myservo1.attach(9);
   myservo2.attach(40);
  Serial.begin(9600);
}
void loop()
{ if(jit==0){
lcd.setCursor(0,0);
lcd.print("VENDING MACHINE");}
char key= keypad.getKey();
  
  if (key==p[a]){a++;delay(500);}
    if(a==2)
     { myservo2.write(180);  delay(2000);a=0;}
       if(key=='D'){ myservo2.write(0);}
      if(key=='1'&&mo>=5)
      {lcd.clear();
  lcd.setCursor(0,0);
lcd.print("DEDUCTED 5 RUPEES"); digitalWrite(in1,HIGH); if(in1)Serial.println("five rupee dedected");   delay(5000);digitalWrite(in1,LOW); 
lcd.setCursor(0,1);mo-=5;
lcd.print("AMOUNT LEFT=");lcd.setCursor(12,1);
lcd.print(mo);}
if(key=='1'&&mo==0){lcd.clear();
  lcd.setCursor(0,0);
lcd.print("PLEASE ADD MONEY");delay(5000);jit=0;}
if(key=='2'&&mo==0){lcd.clear();
  lcd.setCursor(0,0);
lcd.print("PLEASE ADD MONEY");delay(5000);jit=0;}
  

if(key=='2'&&mo>=10)
      {lcd.clear();
  lcd.setCursor(0,0);
lcd.print("DEDUCTED 10 RUPEES"); digitalWrite(in2,HIGH);  if(in1)Serial.println("TEN rupee dedected");  delay(5000);  digitalWrite(in2,LOW); 
lcd.setCursor(0,1);lcd.print("AMOUNT LEFT=");lcd.setCursor(12,1);mo-=10;
lcd.print(mo);}
    
  digitalWrite(t,LOW);
  delayMicroseconds(2);
  digitalWrite(t,HIGH);
  delayMicroseconds(10);
  digitalWrite(t,LOW);
  duration=pulseIn(e,HIGH);
  distance=duration*0.034/2;
Serial.println(pos);
  if(distance>200)
 {      pos++;
    myservo1.write(pos);              
    delay(20);               
  }
 if(distance<200)
 {
  if(pos>5)
  {
     
 Serial.println(pos);
  myservo1.write(80);  
   if(pos>=19&&pos<=32)
  {lcd.clear();
  lcd.setCursor(0,0);jit++;
lcd.print("RS 5 ADDED");mo+=5;
lcd.setCursor(0,1);
lcd.print("TOTAL AMOUNT=");
lcd.setCursor(13,1);
lcd.print(mo);

delay(1000);}
if(pos>=37&&pos<=43)
  {lcd.clear();
  lcd.setCursor(0,0);jit++;
lcd.print("RS 10 ADDED");
mo+=10; lcd.setCursor(0,1);
lcd.print("TOTAL AMOUNT=");
lcd.setCursor(13,1);
lcd.print(mo);delay(1000);}
 
  pos=0;
  } delay(300);
  myservo1.write(0); 
  }}

     
  
  