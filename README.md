# window-alert-system
This Arduino project alerts the user to close the window in certain weather conditions.

Demo video: https://1drv.ms/u/s!AlJEYb5G7LkfgchPa6fXcBKt0pHusg?e=0PbXY6

![Schema](https://user-images.githubusercontent.com/47451756/112886204-46cc5a80-90da-11eb-9afa-a516fc88a7b9.PNG)

The Problem

•	We all like the fresh air outside, that is why we leave the window open, but sometimes we forget it open, and it starts to rain outside.
•	Especially when we have a window like the one on the left, we have a problem. Without a doubt, the rain enters the house and can damage the parquet or wet certain objects in the house.
•	Another problem that arises when we forget about an open window is when outside starts to get too hot or too cold, thus affecting the temperature in our homes.

The Solution

•	My solution is a window alert system that warns the user if they forgot the window open and it started raining or it got too cold or too hot outside.
•	The device can be turned on or off by pressing the button at the bottom of the device. A green LED lets the user know that the device is on.
•	The device will warn the user about the opened window by buzzing and blinking a red LED.

Temperature Sensor

•	The device uses a DHT11 temperature and humidity sensor.
•	It is used to check if the temperature is lower than 18˚C or greater than 30˚.
•	The DHT.h library is used to retrieve the temperature from the sensor.

Tilt Sensor

•	The device uses a SW520D tilt sensor.
•	It is used to check if the window is open or not.
•	The window is considered open when the sensor sends a HIGH value.

Raindrop Sensor

•	The device uses a FC-37 raindrop sensor.
•	It sends a value between 0 and 1023 through its analog pin. It will send lower values when it has water on it.
•	The device considers it is raining if the value sent by the raindrop sensor is lower than 600.

Buzzer

•	An active buzzer is used together with the red LED to warn the user if the window is opened and at least one of the other 2 conditions is met, that is temperature being outside the accepted range or rain is detected.
