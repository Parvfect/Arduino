

const int ledPin =  10;// the number of the LED pin


//Morse code library (taken from http://crumbsofcode.com/text-to-morse-code-in-c/)
char text[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
 '1','2','3','4','5','6','7','8', '9','0' };
 
String morse[36] = {".-","-...","-.-.","-..",".","..-","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",
 ".----","..---","...--","....-",".....","-....","--....","---..","----.","-----"};
//End of morse code library


void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // set the pin value on low at the begin
  Serial.begin(9600);

}

void morse_it(String x){

  for(int i=0; i<x.length(); i++){
    if(x[i] == '.'){
      dot();
    }
    else{
      dash();
    }
  }
}

void dot() {
  //Morse code dot
  digitalWrite(ledPin,LOW);
  delay(200);
}

void dash() {
  //Morse code dash
  digitalWrite(ledPin, HIGH);
  delay(200);
 }

void wordSpace(){
  digitalWrite(ledPin, LOW);
  delay(1000);
}

void letterSpace(){
  digitalWrite(ledPin, LOW);
  delay(1000);
}

void loop() {
 
    String sentence = "PASTA";
   /** Serial.println("Enter word to be converted to morse code");
    while (Serial.available() == 0) {
    // Wait for User to Input Data
      sentence = Serial.readString(); //Read the data the user has input
      Serial.println(sentence);
      //break;
   }
   Serial.println("ayo");
*/
   for(int i = 0; i<sentence.length(); i++){
    char x = sentence[i];
    if (x == ' '){
      wordSpace();
    }
    else{
      for(int j=0; j<36; j++){
        if(x == text[j]){
          morse_it(morse[j]);
          letterSpace();
          break;
        }
      }
    }
   }
}


