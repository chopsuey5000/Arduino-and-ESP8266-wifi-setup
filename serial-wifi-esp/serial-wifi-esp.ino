/* uart_wifi.lua has to be uploaded  first to esp8266 with ESPlorer */

String ssid = "your_network";
String pass = "your_password";

boolean stringComplete = false;
String inputString ="";
boolean set_wifi_sended = false;

void setup() {
  delay(5000);

  Serial.begin(115200);
  Serial1.begin(9600);
  while (!Serial1) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  //run file stored in the esp
  Serial1.println("dofile(\"uart_wifi.lua\")");
  delay(1000);
  
}

void loop() {

}

void serialEvent1() {
  while (Serial1.available()>0) {
    // get the new byte:
    char inChar = (char)Serial1.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      delay(1500);
      Serial.println(inputString);
      inputString = "";
      stringComplete = true;
      if(!set_wifi_sended) {
        Serial1.println("set_wifi(\""+ssid+"\",\""+pass+"\")");
        set_wifi_sended = true; 
      }
    } 
  }
}
