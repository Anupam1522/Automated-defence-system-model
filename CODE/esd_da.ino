#include <Servo.h>

// Define the pins for our HC-SR04 Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

// Variables to store the sensor reading
long duration;
int distance;

// Create servo objects to control our motors
Servo myServo1; // This servo sweeps the sensor
Servo myServo2; // This servo aims the launcher
Servo myServo3; // This servo pulls the firing pin

void setup() {
  pinMode(trigPin, OUTPUT); // The trigger pin sends out a sound pulse
  pinMode(echoPin, INPUT);  // The echo pin listens for the return pulse
  Serial.begin(9600);       // Start serial communication to see what's happening in the Serial Monitor

  // Attach our servos to their corresponding pins on the Arduino
  myServo1.attach(12);
  myServo2.attach(13);
  myServo3.attach(9);

  // Set the initial positions for the servos on startup
  myServo1.write(0);  // Aim the sensor servo to the start position
  myServo2.write(0);  // Aim the launcher servo to the start position
  myServo3.write(45); // Set the firing servo to its 'loaded' position
  delay(1000);        // Give the servos a moment to get into position
}

void loop() {
  // Begin the scanning sweep from 0 to 90 degrees
  for (int i = 0; i <= 90; i++) {
    myServo1.write(i); // Move the sensor servo
    myServo2.write(i); // Move the launcher servo in sync
    delay(30);         // A small delay to make the sweep smooth

    distance = calculateDistance(); // Check the distance at the current angle

    // Print the current status to the serial monitor for debugging
    Serial.print("Scanning at angle: ");
    Serial.print(i);
    Serial.print(" degrees, Distance: ");
    Serial.println(distance);

    // Check if a target has entered the "danger zone" (less than 50 cm)
    if (distance > 0 && distance < 50) {
      Serial.println("Target detected! Locking on...");
      myServo1.write(i); // Lock the sensor servo in place
      myServo2.write(i); // Lock the launcher servo in place
      delay(500);

      // Fire the missile!
      Serial.println("Missile launched!");
      myServo3.write(165); // Move the firing pin to release the rubber band
      delay(500);
      myServo3.write(45);  // Return the firing pin to the 'loaded' position

      // Mission complete! The system halts here.
      // You'll need to reset the Arduino to run the scan again.
      while(true);
    }
  }
}

// A handy function to get the distance from the ultrasonic sensor
int calculateDistance() {
  // Send out a clean 10 microsecond pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read how long it takes for the echo to return
  duration = pulseIn(echoPin, HIGH);

  // The speed of sound is 0.034 cm/µs. The pulse travels to the object AND back, so we divide by 2.
  distance = duration * 0.034 / 2;

  // Ignore faulty readings that are too close or too far
  if (distance <= 0 || distance > 400) {
    return 400;
  }

  return distance;
}
