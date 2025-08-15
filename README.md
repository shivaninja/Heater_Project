
"READ ME"

	IMPORTANT:  
		NOTE: This Whole project folder consists of two Projects( PROJECT 1 & PROJECT 2).

  		NOTE: Project 2 is updated version of 1. They both are very similar and uses same system.  The Only difference is the protocol & sensor they use.



	PROJECT 1:
		(No SPI Protocol): This one does not uses the SPI communication protocol. 
		It is implementation of " Header Control System " in Arduino. It uses built in ADC(Analog to digital converter) & its in built function "analogRead()"
 		to read data from sensor. Project 1 acts as base project or template to more advance project 2. Project 1 is similar to project 2 except that it does not uses SPI and it uses TMP36 sensor.


	PROJECT 2:
		(Uses SPI Protocol): This one uses the SPI communication protocol. 
		It is implementation of " Header Control System " in Arduino. It uses SPI protocol & its functions to read data from sensor.
  		So, make sure to include  "" #include <Wire.h> "" // Library for I²C communication
		Project 2 uses LM75 sensor.
