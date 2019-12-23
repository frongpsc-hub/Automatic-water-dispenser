#define trigger1 2
#define echo1 3
#define trigger2 4
#define echo2 5
#define trigger3 6
#define echo3 7 
#define trigger4 8
#define echo4 9
#define LED 13
#define LED0 10
#define LED1 11
#define MOSFET1 12
#define MOSFET2 A5
#define limitSwitch A4
 
 
float time1=0,distance1=0,time2=0,distance2=0,time3=0,distance3=0,time4=0,distance4=0;
   
void setup()
{
Serial.begin(9600);

 pinMode(trigger1,OUTPUT);
 pinMode(echo1,INPUT);
 pinMode(trigger2,OUTPUT);
 pinMode(echo2,INPUT);
 pinMode(trigger3,OUTPUT);
 pinMode(echo3,INPUT);
 pinMode(trigger4,OUTPUT);
 pinMode(echo4,INPUT);
 pinMode(LED,OUTPUT);
 pinMode(LED0,OUTPUT);
 pinMode(LED1,OUTPUT);
 pinMode(MOSFET1,OUTPUT);
 pinMode(MOSFET2,OUTPUT);
 pinMode(limitSwitch,INPUT);
 delay(500);
}
 
void loop()
{
 measure_distance();
 if(distance1<6&&distance2<6&&distance3<6) 
 {
   digitalWrite(LED,HIGH);digitalWrite(LED0,HIGH);digitalWrite(LED1,LOW);digitalWrite(MOSFET1,HIGH);digitalWrite(MOSFET2,HIGH);
   //Serial.println("123");
   if(distance4<10)
    {
      digitalWrite(MOSFET1,LOW);digitalWrite(MOSFET2,LOW);
    }
 }
 else if(distance1<6&&distance2<6)
 {
  digitalWrite(LED,HIGH);digitalWrite(LED0,HIGH);digitalWrite(LED1,LOW);digitalWrite(MOSFET1,HIGH);digitalWrite(MOSFET2,HIGH);
  //Serial.println("12");
  if(distance4<14)
    {
      digitalWrite(MOSFET1,LOW);digitalWrite(MOSFET2,LOW);
    }
 }
 else if(distance1<6)
 {
  digitalWrite(LED,HIGH);digitalWrite(LED0,HIGH);digitalWrite(LED1,LOW);digitalWrite(MOSFET1,HIGH);digitalWrite(MOSFET2,HIGH);
  //Serial.println("1");
  if(distance4<15)
    {
      digitalWrite(MOSFET1,LOW);digitalWrite(MOSFET2,LOW);
    }
 }
 
 else
 {   
   digitalWrite(LED,LOW);digitalWrite(MOSFET1,LOW);digitalWrite(MOSFET2,LOW);digitalWrite(LED0,LOW);digitalWrite(LED1,HIGH);
   delay(500);
 } 
 
}

void measure_distance()
{
 digitalWrite(trigger1,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger1,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger1,LOW);
 delayMicroseconds(2);
 time1=pulseIn(echo1,HIGH);
 distance1=(time1/2)/29.1;
 Serial.println("Dis1 "+ String (distance1));
 //Serial.println(distance1);
 

 digitalWrite(trigger2,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger2,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger2,LOW);
 delayMicroseconds(2);
 time2=pulseIn(echo2,HIGH);
 distance2=(time2/2)/29.1;
Serial.println("Dis2 "+ String (distance2));

  digitalWrite(trigger3,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger3,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger3,LOW);
 delayMicroseconds(2);
 time3=pulseIn(echo3,HIGH);
 distance3=(time3/2)/29.1;
 Serial.println("Dis3 "+ String (distance3));
 
 digitalWrite(trigger4,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger4,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger4,LOW);
 delayMicroseconds(2);
 time4=pulseIn(echo4,HIGH);
 Serial.println("Dis4 "+String(distance4));
 distance4=(time4/2)/29.1;

} 
