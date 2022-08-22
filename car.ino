#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


char command;

void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
pinMode(13,OUTPUT);
}

void loop(){
  if(Serial.available() > 0){
    command = Serial.read();
    Serial.print(command);
    switch(command){
    case 'F':
      forward();
      break;
    case 'B':
       back();
      break;
    case 'L':
      left();
      break;
    case 'R':
      right();
      break;
    case 'O':
      led3();
      break;
    case 'o':
    led4();
    break;
    case 'S':
    Stop();
    break;

      
    }
  }
}

void forward()
{led1();
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD); 
}

void back()
{led2();
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}

void right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}
void led1(){
  
  
  digitalWrite(2,HIGH);
  digitalWrite(13,LOW);

  
  
  }

void led2(){
  digitalWrite(13,HIGH);
  digitalWrite(2,LOW);
  
  }
void led3(){

  
  digitalWrite(13,HIGH);
  digitalWrite(2,HIGH);
  }
void led4(){
  
  digitalWrite(13,LOW);
  digitalWrite(2,LOW);
}
