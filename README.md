# Punch Detection

A mini project designed to gather IMU data from different types of punches and analyze them.

The set-up is very rudimentary, comprising of some simple wiring between an Arduino Nano and an IMU MPU6050. 

![Epic Set up](https://github.com/user-attachments/assets/a670c3a3-f021-4c78-8981-4990edf72129)


## Workflow
- Mount the set up onto forearm using wristbands for support
- Plug Arduino Nano into the designated port and upload sketch
- Unplug Arduino after uploading and plug it into alternative power supply. In this case, this is a powerbank
- The Arduino will now IMU data for up to 4 seconds. Punch, wave, and do whatever motions you'd like
- Replug back into the port
- Open up Serial Monitor and look at the IMU values being dumped
