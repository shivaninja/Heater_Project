

	PROJECT 1:
		(No SPI Protocol): This one does not uses the SPI communication protocol. 
		It is implementation of " Header Control System " in Arduino. It uses built in ADC(Analog to digital converter) & its in built function "analogRead() to read the temperature"
 		to read data from sensor. Project 1 acts as base project or template to more advance project 2. Project 1 is similar to project 2 except that it does not uses SPI and it uses TMP36 sensor.
   		Make sure to inclue #include <Arduino.h> header.
     

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
