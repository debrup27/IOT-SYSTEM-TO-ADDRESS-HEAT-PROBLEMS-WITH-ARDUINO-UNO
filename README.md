# IOT-SYSTEM-TO-ADDRESS-HEAT-PROBLEMS-WITH-ARDUINO-UNO
##### To monitor and advice the user accordingly for taking various precautions against heat

![](https://img.shields.io/badge/Arduino-2.3.2-red) ![](https://img.shields.io/badge/Contribute_Now!-yellow)
---

## Contributors
>- [Debrup Sengupta](mailto:debrupsengupta26@gmail.com) ![](https://img.shields.io/badge/TopContributor!-green)
>- [Anjan Das](mailto:anjandas1920@gmail.com)
>- [Aakash Das](mailto:pfaakashdas@gmail.com) 
>- [Sukrit Ray](mailto:samfeghterman@gmail.com) 
>- [Rajarshee Sarkar](mailto:sarkarrajarshee2003@gmail.com)
>- [Prerona Ghosh Dastidar](mailto:preronargd@gmail.com)

## Problems in the Real Life
The extreme heat often leads to adverse effects on the common masses and confuses them on what countermeasures they should be taking in order to face the heat and take effective actions. 
The excessive heat also leads to heatstrokes and more frequently the students suffer from this problem, we wish to counter this and provide an affordable solution.

## Proposed Solution

An Arduino system that monitors:- 

- Monitors temperature and humidity and gives recommended solutions to the user for facing the heat.
- Measures the pulse of the user and warns them if there are possible chances of a heatstroke.
- Monitors the sunlight and accordingly recommends whether the user should use an umbrella and sunscreen or not.
- Asks the user to enter their weight and accordingly ask them to drink the recommended amount of water in order to stay hydrated
- Displays all results in bluetooth and allows the user to input their weights in terminal.

## Harwares and Sensors used

>- Arduino Uno R3
>- DHT11 Temperature and Humidity sensor
>- HW-827 Pulse sensor
>- LDR Module(MH Sensor series)
>- HC-05 blutooth module
>- LCD Display
>- pcf8574 I2C Serial interface for LCD Display

## Libraries Used

- [DHT11 Library](https://codeload.github.com/adidax/dht11/legacy.zip/refs/heads/master)
- [LiquidCrystal Library](https://downloads.arduino.cc/libraries/github.com/arduino-libraries/LiquidCrystal-1.0.7.zip)
- [SoftWareSerial](https://docs.arduino.cc/learn/built-in-libraries/software-serial/)
- [Wire.h](https://www.arduino.cc/reference/en/language/functions/communication/wire/)


## Circuit Diagram

![circuit_diagram](https://github.com/debrup27/IOT-SYSTEM-TO-ADDRESS-HEAT-PROBLEMS-WITH-ARDUINO-UNO/assets/168071999/d508d659-7bc7-4377-a5ca-110a92b6839f)


## Problems and Contributions

The current solution does not employ and industrial approach but rather is a proof-of-concept as a hobby project. We tend to improve the user experience and 
Anyone is more than welcome to contribute, add features, or use this code to implement new features in this code. We wish to implement this in a portable and scalable format of a pocket watch and 
smart watch in the future. We would also introduce several other measures such as blood oxygen monitoring and an Artificial Intelligence Monitoring System which would recommend the user to take the best
possible countermeasures. All this will be done keeping in mind the affordablity of the product which is one of our main concerns.
