# Automated Missile Defense System

Welcome to our project! This is a prototype of an automated defense turret we designed and built. It uses an ultrasonic sensor to scan for threats and a servo-powered launcher to fire a rubber-band "missile" at anything that gets too close.


> **A Quick Note on the Hardware**: Our original project report mentions using an ESP32 with Bluetooth for a permission-based firing system[1]. However, the code and circuit diagram here are for a simpler, fully automatic version that uses an Arduino Uno. This is the version we've documented and tested for this repository.

## The Core Idea

The concept is straightforward but effective:

1.  **Scanning the Area**: We mounted an ultrasonic sensor on a servo motor. The servo sweeps back and forth, allowing the sensor to continuously scan the environment for intruders[1].
2.  **Detecting a Threat**: The sensor measures the distance to objects in its path. If something comes within our pre-set "danger zone" (50 cm in the code), the system flags it as a target[1].
3.  **Locking On**: As soon as a target is confirmed, the scanning servo stops, locking the launcher's aim onto the target's position[1].
4.  **Neutralizing the Threat**: With the target locked, a third servo motor activates a simple firing pin, launching a rubber band to neutralize the threat. After firing, the system halts and needs to be reset to begin scanning again[1].

## Hardware We Used

Here's the list of components you'll need to build your own version[1]:

*   **The Brains**: Arduino Uno R3
*   **The Eyes**: HC-SR04 Ultrasonic Distance Sensor
*   **The Muscles**: 3x SG90 Micro Servo Motors
*   **The Skeleton**: A Breadboard and some Jumper Wires
*   **The Power**: A 5V DC power source (USB from a computer works great)
*   **The "Missile"**: A simple frame to hold and release a rubber band

## Wiring It All Up

Connect the components to your Arduino as shown in the table below. This setup matches the provided code[1].

| Component                 | Connects to Arduino Pin |
| :------------------------ | :---------------------- |
| **HC-SR04 Sensor**        |                         |
| VCC Pin                   | 5V                      |
| Trig Pin                  | Pin 10                  |
| Echo Pin                  | Pin 11                  |
| GND Pin                   | GND                     |
| **Servo 1 (Sensor Scan)** |                         |
| Signal Wire               | Pin 12                  |
| **Servo 2 (Launcher Aim)**|                         |
| Signal Wire               | Pin 13                  |
| **Servo 3 (Firing Pin)**  |                         |
| Signal Wire               | Pin 9                   |

*(Remember to connect the VCC (power) and GND (ground) wires for all three servos to the 5V and GND pins on the Arduino as well.)*

## Getting the Code Running

1.  First, you'll need the [Arduino IDE](https://www.arduino.cc/en/software).
2.  The `Servo.h` library we use comes built-in with the IDE, so no extra installations are needed.
3.  Open the `CODE/esd_da.ino` file from this repository in the Arduino IDE.
4.  Plug your Arduino Uno into your computer via USB.
5.  In the IDE, go to **Tools > Board** and select **Arduino/Genuino Uno**.
6.  Then go to **Tools > Port** and select the port your Arduino is connected to.
7.  Hit the "Upload" button (the arrow icon), and the code will be sent to the board.

## Connecting to a Bigger Picture: Sustainable Development Goals

We also considered how a project like this, even as a prototype, relates to broader global objectives. This system touches on several UN Sustainable Development Goals (SDGs)[1]:

*   **SDG 9 (Industry, Innovation, and Infrastructure)**: This project is a hands-on exploration of innovation in automation, robotics, and embedded systems[1].
*   **SDG 16 (Peace, Justice, and Strong Institutions)**: On a larger scale, technologies like this form the basis of modern security systems that help maintain peace and protect institutions[1].
*   **SDG 11 (Sustainable Cities and Communities)**: The core technology could be adapted for public safety in smart cities, like securing perimeters or monitoring critical infrastructure[1].
