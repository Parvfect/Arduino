
//https://www.circuitbread.com/tutorials/how-rgb-leds-work-and-how-to-control-color#:~:text=In%20a%20common%20anode%20RGB%20LED%2C%20the%20anode,the%20power%20supply.%20Common%20Anode%20RGB%20LED%20Pinout
/**
 *So this is how a RGB anode works
 *The long leg - which is the anode, goes to 5V
 *
 */

const int ledR = 10;
const int ledG = 9;
const int ledB = 11;
int Previous_PWMValue_RedPin = 0;
int Threshold_PWMValue_RedPin = 0;
int Previous_PWMValue_GreenPin = 0;
int Threshold_PWMValue_GreenPin = 0;
int Previous_PWMValue_BluePin = 0;
int Threshold_PWMValue_BluePin = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Pot_RedPin = analogRead(A0);
  int PWMValue_RedPin = Pot_RedPin/4;
  int Pot_GreenPin = analogRead(A1);
  int PWMValue_GreenPin = Pot_GreenPin/4;
  int Pot_BluePin = analogRead(A2);
  int PWMValue_BluePin = Pot_BluePin/4;
  
  //Use this code for RGB LED COMMON CATHODE and comment the code for COMMON ANODE
  analogWrite(ledR, PWMValue_RedPin);
  analogWrite(ledG, PWMValue_GreenPin);
  analogWrite(ledB, PWMValue_BluePin);
  
  //Use this code for RGB LED COMMON ANODE and comment the code for COMMON CATHODE
  /*
  analogWrite(RGBLED_RedPin, 255-PWMValue_RedPin);
  analogWrite(RGBLED_GreenPin, 255-PWMValue_GreenPin);
  analogWrite(RGBLED_BluePin, 255-PWMValue_BluePin);
  */
  
  //This section is for serial printing the RGB decimal values. 
  //Sometimes you get unstable output due to jumper wires not properly connected, poor quality breadboard, or poor quality potentiometers.
  float Threshold_PWMValue_RedPin = abs(Pot_RedPin - Previous_PWMValue_RedPin);
  float Threshold_PWMValue_GreenPin = abs(Pot_GreenPin - Previous_PWMValue_GreenPin);
  float Threshold_PWMValue_BluePin = abs(Pot_BluePin - Previous_PWMValue_BluePin);
  if (Threshold_PWMValue_RedPin >= 10 || Threshold_PWMValue_GreenPin >= 10 || Threshold_PWMValue_BluePin >= 10)
  
  Serial.print("RGB (");
  Serial.print(PWMValue_RedPin);
  Serial.print(", ");
  Serial.print(PWMValue_GreenPin);
  Serial.print(", ");
  Serial.print(PWMValue_BluePin);
  Serial.println(") ");
  Previous_PWMValue_RedPin = Pot_RedPin;
  Previous_PWMValue_GreenPin = Pot_GreenPin;
  Previous_PWMValue_BluePin = Pot_BluePin;
  //This section is for serial printing the RGB decimal values. 
  //Sometimes you get unstable output due to jumper wires not properly connected, poor quality breadboard, or poor quality potentiometers.
  
  delay(2);
} 
