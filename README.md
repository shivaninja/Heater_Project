
"READ ME"

	IMPORTANT:  
		NOTE: This Whole project folder consists of two Projects( PROJECT 1 & PROJECT 2).
  		NOTE: Project 2 is updated version of 1. They both are very similar and uses same system.  The Only difference is the protocol & sensor they use.



	PROJECT 1:
		(No SPI Protocol): This one does not uses the SPI communication protocol. 
		It is implementation of " Header Control System " in Arduino. It uses built in ADC(Analog to digital converter) & its in built function "analogRead() to read the temperature"
 		to read data from sensor. Project 1 acts as base project or template to more advance project 2. Project 1 is similar to project 2 except that it does not uses SPI and it uses TMP36 sensor.


	PROJECT 2:
		(Uses SPI Protocol): This one uses the SPI communication protocol. 
		It is implementation of " Header Control System " in Arduino. It uses SPI protocol & its functions to read data/Temperature from sensor.
  		So, make sure to include  "" #include <Wire.h> "" // Library for I²C communication
		Project 2 uses LM75 sensor.


	Minimum Sensors Required:
		Temperature Sensor (TMP36 or LM75)                                                                              
        	To measure the current temperature so the Arduino can decide whether to  turn the heater on or off.
		Required: Analog: TMP36, LM75 — simple, low cost, connect to an analog input pin.
		Not Required but recommended: Digital: DS18B20 (1-Wire), DHT22 (Not recommended because digital sensors can’t support analog)
  
		TMP36: Used when no protocol is used & TMP36 uses just in-built ADC                   
        LM75: Can be used with communication protocols such as I2C.
