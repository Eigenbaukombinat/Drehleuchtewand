int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led7 = 7;
int led8 = 8;
int led9 = 9;
int ledrandom = random(2, 10);
int counter = 0;
int counterbreak = 500;
int del = 100;

// the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);
  while (!Serial) {   //waiting for the serial connection
  }
  Serial.println();
  Serial.print("Fade chaos jotilux");
  // declare pin 9 to be an output:
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(led8, OUTPUT);
pinMode(led9, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
// set the brightness of pin 9:

if (counter < counterbreak) {
//  Serial.println("chaos");
  del = random(300, 900);
  analogWrite(ledrandom, brightness);
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = random(2, 6);
    fadeAmount = -fadeAmount;
    ledrandom = random(2, 10);
  }
} else if (counter > counterbreak) {
//  Serial.pr,intln("gleich");
  del = 500;
  analogWrite(led2, brightness);
  analogWrite(led3, brightness);
  analogWrite(led4, brightness);
  analogWrite(led5, brightness);
  analogWrite(led6, brightness);
  analogWrite(led7, brightness);
  analogWrite(led8, brightness);
  analogWrite(led9, brightness);
  fadeAmount = 5;
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
} 
  if  (counter > (counterbreak + counterbreak)) {
  Serial.println("reset counter");
  counter = 0;
}
  counter = counter + 1;
  delay(del);
//  Serial.println(counter);
}
