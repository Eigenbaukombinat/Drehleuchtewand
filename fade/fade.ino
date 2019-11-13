int led_ro = 2;
int led_mi = 6;
int led_ru = 7;
int led_lo = 9;
int mot_ro = 3;
int mot_mi = 4;
int mot_ru = 5;
int mot_lo = 8;
int pinrandom = random(2, 10);
int counter = 0;
int counterbreak = 500;
int del = 100;
int allLED[] = {led_ro, led_mi, led_ru, led_lo};
int LEDanzahl = 4;
int allMot[] = {mot_ro, mot_mi, mot_ru, mot_lo};
int MOTanzahl = 4;

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
pinMode(led_ro, OUTPUT);
pinMode(mot_ro, OUTPUT);
pinMode(mot_mi, OUTPUT);
pinMode(mot_ru, OUTPUT);
pinMode(led_mi, OUTPUT);
pinMode(led_ru, OUTPUT);
pinMode(mot_lo, OUTPUT);
pinMode(led_lo, OUTPUT);
//selftest();
}

// the loop routine runs over and over again forever:
void loop() {
// set the brightness of pin 9:

if (counter < counterbreak) {
//  Serial.println("chaos");
  del = random(300, 900);
  analogWrite(pinrandom, brightness);
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = random(2, 6);
    fadeAmount = -fadeAmount;
    pinrandom = random(2, 10);
  }
} else if (counter > counterbreak) {
//  Serial.pr,intln("gleich");
  del = 500;
  analogWrite(led_ro, brightness);
  analogWrite(mot_ro, brightness);
  analogWrite(mot_mi, brightness);
  analogWrite(mot_ru, brightness);
  analogWrite(led_mi, brightness);
  analogWrite(led_ru, brightness);
  analogWrite(mot_lo, brightness);
  analogWrite(led_lo, brightness);
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

//
//void selftest() {
//  int LED;
//  for (int allLED=0; allLED<LEDanzahl; LED=LED+1){
//    brightness = 255;
//    analogWrite(LED, brightness);
//    Serial.print("LED");
//    Serial.print(LED);
//    delay(3000);
//    analogWrite(LED, 0);
//  }
//  int MOT;
//  for (int allMOT=0; allMOT<MOTanzahl; MOT=MOT+1){
//    brightness = 255;
//    analogWrite(MOT, brightness);
//    Serial.print("Motor");
//    Serial.print(MOT);
//    delay(3000);
//    analogWrite(MOT, 0);
//  }
//}
