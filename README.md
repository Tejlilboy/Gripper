
# 5-Servo Robotic Arm with Joystick Control

A joystick-controlled robotic arm built using an Arduino, five servo motors, and two analog joysticks. This project explores embedded systems, servo motor control, analog input processing and basic robotic manipulation.

## Project Overview

This project is a manually controlled robotic arm capable of performing multiple movements using two joystick modules. Each joystick provides independent control over different sections of the arm, allowing the user to position the arm and operate its gripper.

The goal was to build a functional robotic arm while gaining practical experience with microcontrollers, electronics, and hardware-software integration.

## Features

- **5 servo motors:** Independent control of five actuators.
- **Dual-joystick control:** Analog joysticks control arm movement.
- **Rotating base:** Rotates the arm horizontally.
- **Articulated arm:** Multiple joints provide vertical positioning.
- **Rotating gripper:** Adjusts the claw's orientation.
- **Gripper control:** Opens and closes using a joystick button.
- **Joystick dead zone:** Helps reduce unintended movement caused by small analog input fluctuations.
- **Button debouncing:** Helps prevent repeated activations from a single button press.

## Hardware

| Component | Quantity |
|---|---:|
| Arduino Nano V3 | 1 |
| SG90 metal-gear servo motors | 5 |
| Analog joystick modules | 2 |
| Robotic arm structure | 1 |
| Jumper wires | As required |
| External servo power supply | 1 |

## Controls

The arm uses two joysticks to control five servo motors.

| Control | Function | Arduino Pin |
|---|---|---|
| Left joystick VRY | Base swivel | D3 |
| Left joystick VRX | Main arm joint | D5 |
| Right joystick VRX | Secondary arm joint | D6 |
| Right joystick VRY | Gripper rotation | D9 |
| Right joystick button | Open/close gripper | D10 |

### Analog Inputs

| Input | Arduino Pin |
|---|---|
| Left joystick VRX | A0 |
| Left joystick VRY | A1 |
| Right joystick VRX | A2 |
| Right joystick VRY | A3 |
| Right joystick button | A4 |

## Software

The project is programmed in C++ using the Arduino IDE and the Arduino Servo library.

### Main Concepts

- Servo motor positioning using the `Servo` library
- Reading analog joystick inputs with `analogRead()`
- Mapping joystick inputs to servo positions
- Constraining servo angles to safe limits
- Implementing a joystick dead zone
- Handling button inputs and preventing unintended repeated activations

## Setup

1. Assemble the robotic arm and mount the five servo motors.
2. Connect the joystick modules and servo signal wires according to the pin tables.
3. Connect the servo power supply and establish a common ground with the Arduino.
4. Open the project source code in the Arduino IDE.
5. Select the appropriate Arduino Nano board and port.
6. Upload the firmware.
7. Power on the arm and test each movement.

### Power Considerations

Servo motors can draw significant current, especially when starting or under load. Use a suitable external power supply for the servos rather than powering all five directly from the Arduino's 5V pin.
In the case of this project, a buck converter with the out put current of 5V 5A is HIGHLY recommended as it provides enough current to handle 5 servo stall.

Ensure the servo power supply and Arduino share a common ground.

## Challenges and Lessons Learned

This project provided hands-on experience with:

- Planning wiring and power distribution for a multi-servo system
- Managing servo movement and angle limits
- Integrating multiple actuators with a microcontroller
- Interpreting analog joystick signals
- Reducing unintended movement through dead zones
- Improving button reliability through debouncing


## Project Status

**Status: Completed**

This project was built as a practical introduction to robotic control and embedded electronics. It served as a foundation for exploring more advanced robotics projects.

## Future Improvements

Although the project is complete, possible future upgrades include:

- Wireless control using an ESP32
- A web-based control interface
- Improved mechanical stability and payload capacity
- More advanced movement control and coordinated motion

## Author

Tejwant Lilboy
