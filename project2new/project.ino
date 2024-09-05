#include <Servo.h>

// Define the pins for the ultrasonic sensors

const int TRIG_PIN_1 = 2;  
const int ECHO_PIN_1 = 3;  
const int TRIG_PIN_2 = 4;  
const int ECHO_PIN_2 = 5;  
const int TRIG_PIN_3 = 6;
const int ECHO_PIN_3 = 7;
const int SERVO_PIN = A1; 
// Create servo object to control a servo
Servo myServo;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set the trigger pins as outputs and the echo pins as inputs
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  // Attach the servo on pin 10 to the servo object
  myServo.attach(10);
}

void loop() {
  // Read the distances from the ultrasonic sensors
  int distance1 = getDistance(trigPin1, echoPin1);
  int distance2 = getDistance(trigPin2, echoPin2);
  int distance3 = getDistance(trigPin3, echoPin3);

  // Print the distances for debugging
  Serial.print("Distance from Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm | Distance from Sensor 2: ");
  Serial.print(distance2);
  Serial.print(" cm | Distance from Sensor 3: ");
  Serial.println(distance3);

  // Determine which sensor detects the object at the greatest distance
  if (distance1 > distance2 && distance1 > distance3) {
    Serial.println("Sensor 1 has the greatest distance");
    moveTowardsSensor(1);
  } else if (distance2 > distance1 && distance2 > distance3) {
    Serial.println("Sensor 2 has the greatest distance");
    moveTowardsSensor(2);
  } else if (distance3 > distance1 && distance3 > distance2) {
    Serial.println("Sensor 3 has the greatest distance");
    moveTowardsSensor(3);
  } else {
    Serial.println("No sensor has the greatest distance");
  }

  // Add a small delay to avoid overwhelming the serial monitor
  delay(500);
}

int getDistance(int trigPin, int echoPin) {
  // Send a 10-microsecond pulse to the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the pulse duration from the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  int distance = duration * 0.034 / 2;

  return distance;
}

void moveTowardsSensor(int sensorNumber) {
  // Function to move towards the specified sensor
  Serial.print("Moving towards sensor ");
  Serial.println(sensorNumber);

  // Move the servo motor to a specific angle based on the sensor number
  if (sensorNumber == 1) {
    myServo.write(90); // Move to 90 degrees
  } else if (sensorNumber == 2) {
    myServo.write(0); // Move to 0 degrees
  } else if (sensorNumber == 3) {
    myServo.write(180); // Move to 180 degrees
  }
}
