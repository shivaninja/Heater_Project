
"READ ME"

	IMPORTANT:  
  		NOTE: Project 2 is updated version of 1. They both are very similar and uses same system.  The Only difference is the protocol & sensor they use.

	PROJECT 2:
		(Uses SPI Protocol): This one uses the SPI communication protocol. 
		It is implementation of " Header Control System " in Arduino. It uses SPI protocol & its functions to read data/Temperature from sensor.
  		So, make sure to include  "" #include <Wire.h> "" // Library for I²C communication & #include <Arduino.h> header.
		Project 2 uses LM75 sensor.

	Minimum Hardware & Sensors Required:
 		Arduino Uno.
   		LED.
	 	200 ohm resistors recommended.
   		Conducting wires.
		Temperature Sensor (TMP36 or LM75)                                                                              
        	To measure the current temperature so the Arduino can decide whether to  turn the heater on or off.
		Required: Analog: TMP36, LM75 — simple, low cost, connect to an analog input pin.
		Not Required but recommended: Digital: DS18B20 (1-Wire), DHT22 (Not recommended because digital sensors can’t support analog)
  
		TMP36: Used when no protocol is used & TMP36 uses just in-built ADC                   
        LM75: Can be used with communication protocols such as I2C.
