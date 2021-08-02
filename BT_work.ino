#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); //RX|TX

//initial motors pin
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char command;

int Frontlights = 4;
int Backlights = 8;
int Horn = 7;
int Extra = 5;

void setup() {

  Serial.begin(9600);
  BT.begin(9600);

  pinMode(Frontlights, OUTPUT);
  pinMode(Backlights, OUTPUT);
  pinMode(Horn, OUTPUT);
  pinMode(Extra, OUTPUT);
}

void loop() {
  if (BT.available() > 0) {
    command = BT.read();
    char input = (BT.read());
    Serial.print(input);
    Stop();
    switch (command) {
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
      case 'W':  //Front light ON
        digitalWrite(Frontlights, HIGH);
        break;
      case 'w':  //Front light OFF
        digitalWrite(Frontlights, LOW); 
        break;
      case 'U':  //Back light ON
        digitalWrite(Backlights, HIGH); 
        break;
      case 'u':  //Back light OFF
        digitalWrite(Backlights, LOW); 
        break;
      case 'V':  //Horn On
        digitalWrite(Horn, HIGH);
        break;
      case 'v':  //Horn OFF
        digitalWrite(Horn, LOW);
        break;
      case 'X':
        digitalWrite(Extra, HIGH);
        break;
      case 'x':
        digitalWrite(Extra, LOW) ;
        break;

          }
  }
}

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
