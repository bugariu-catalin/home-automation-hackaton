
/*
  Arduino UNO firmware for Home Automation Hackaton project
 */
 
//int led = 13;

String COM_data = "";
boolean COM_data_ready = false;


void setup() {                
  Serial.begin(9600);  
  COM_data.reserve(200);
//  pinMode(led, OUTPUT);     
}

void loop() {
  //digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);               // wait for a second
  //digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  Serial.println("Ping");
 // delay(1000);               // wait for a second
    if (COM_data_ready) {
       //Execute command
       execCommand();
      Serial.println(COM_data); 
      COM_data = "";
      COM_data_ready = false;
  }

}

/*
  Execute commands from RPI
  Command string:
  COM_data[0] and COM_data[1] is the command code
  and the rest of the chars are optional parameters.
  Ignore commands with fewer then 2 chars
*/
void execCommand() {
  if (sizeof(COM_data)<2) return;
  
}

/*
  Send command to RPI
  param char a is the command group
  param char b is the command 
*/
void sendCommand(char a, char b) {
  if (a=='0') {
    //test cmd
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    COM_data += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      COM_data_ready = true;
    } 
  }
}

