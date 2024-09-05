#include <Servo.h>

const int TRIG_PIN_1 = 2;  
const int ECHO_PIN_1 = 3;  
const int TRIG_PIN_2 = 4;  
const int ECHO_PIN_2 = 5;  
const int TRIG_PIN_3 = 6;
const int ECHO_PIN_3 = 7;
const int SERVO_PIN = A1;  

Servo servo; 

float duration_us_1, distance_cm_1;
float duration_us_2, distance_cm_2;
float duration_us_3, distance_cm_3;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  pinMode(TRIG_PIN_3, OUTPUT);
  pinMode(ECHO_PIN_3, INPUT);
  servo.attach(SERVO_PIN);
  servo.write(0);
}

void loop() {
 
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);
  duration_us_1 = pulseIn(ECHO_PIN_1, HIGH);
  distance_cm_1 = 0.017 * duration_us_1;

  
  digitalWrite(TRIG_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_2, LOW);
  duration_us_2 = pulseIn(ECHO_PIN_2, HIGH);
  distance_cm_2 = 0.017 * duration_us_2;

  
  digitalWrite(TRIG_PIN_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_3, LOW);
  duration_us_3 = pulseIn(ECHO_PIN_3, HIGH);
  distance_cm_3 = 0.017 * duration_us_3;

  Serial.print("distance 1: ");
  Serial.print(distance_cm_1);
  Serial.println(" cm");
  Serial.print("distance 2: ");
  Serial.print(distance_cm_2);
  Serial.println(" cm");
  Serial.print("distance 3: ");
  Serial.print(distance_cm_3);
  Serial.println(" cm");

  
  if (distance_cm_1 >= distance_cm_2) {
        
        if (distance_cm_1 >= distance_cm_3) {
           servo.write(180); 
        }
        else {
            servo.write(180);
        }
    }
    else {
        
        if (distance_cm_2>= distance_cm_3) {
          servo.write(90);
        }
        else {
            servo.write(0);
        }
    }

  delay(0);
}
