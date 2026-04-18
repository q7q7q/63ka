#include "arduino_secrets.h"

//define sketches

int SW1 = 8;  
int SW2 = 7;  
int SW4 = 6;  
int SW8 = 5;  
int SW16 = 4; 
int SW32 = 3; 

int LED1 = 14; 
int LED2 = 15; 
int LED4 = 26; 
int LED8 = 27; 
int LED16 = 28; 
int LED32 = 29; 

int BUZZER = 0; 

bool LEDstate[6] = {false, false, false, false, false, false}; 
bool SWstate[6] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}; 
bool timerRunning = false;
int totalSeconds = 0; //how many seconds left on timer
unsigned long milliseconds = 0;

void setup() {
  //switches, the inputs
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW4, INPUT_PULLUP);
    pinMode(SW8, INPUT_PULLUP);
    pinMode(SW16, INPUT_PULLUP);
    pinMode(SW32, INPUT_PULLUP);

  //led, the outputs
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED8, OUTPUT);
    pinMode(LED16, OUTPUT);
    pinMode(LED32, OUTPUT);
  //buzzer, also an output
    pinMode(BUZZER, OUTPUT);
    
  updateDisplay(); 

void loop() {
    checkSW();
  if(timerRunning == true && millis()-milliseconds>=60000){ 
    oneMinuteLEDUpdate(); 
    milliseconds = millis(); //update milliseconds
  }
    checkTimerStop();
  delay(50);
}

void oneMinuteLEDUpdate(){
  if(LEDstate[0] == true){
    LEDstate[0] = false;
    totalSeconds -= 60; 
  } else {
    if(LEDstate[1] == true){
      LEDstate[1] = false;
      LEDstate[0] = true;
      totalSeconds -= 60; 
    } else {
      if(LEDstate[2] == true){ 
        LEDstate[2] = false;
        LEDstate[1] = true;
        LEDstate[0] = true; 
        totalSeconds -= 60; 
      } else {
        if(LEDstate[3] == true){
        LEDstate[3] = false;
        LEDstate[2] = true;
        LEDstate[1] = true;
        LEDstate[0] = true; 
        totalSeconds -= 60; 
        } else {
          if(LEDstate[4] == true){ 
            LEDstate[4] = false;
            LEDstate[3] = true;
            LEDstate[2] = true;
            LEDstate[1] = true;
            LEDstate[0] = true; 
            totalSeconds -= 60; 
          } else {
            if(LEDstate[5] == true){ 
            LEDstate[5] = false;
            LEDstate[4] = true;
            LEDstate[3] = true;
            LEDstate[2] = true;
            LEDstate[1] = true;
            LEDstate[0] = true; 
            totalSeconds -= 60; 
            }
          }
        }
      }
    }
  }
  updateDisplay();
} //end of oneMinuteLEDUpdate

void checkSW(){
  int sw[6]= {SW1, SW2, SW4, SW8, SW16, SW32};
  int values[6]= {1, 2, 4, 8, 16, 32};
  
  if(timerRunning == false && totalSeconds > 0){ 
    timerRunning = true; //turn on the timer
  }

  for (int i = 0; i < 6; i++){
    bool SWstateNEW = digitalRead(sw[i]); //checks from [sw] array
    if(SWstate[i] == HIGH && SWstateNEW == LOW){
      LEDstate[i] = !LEDstate[i]; //LED, on >> off, off >> on
    }
    if(LEDstate[i] == true){
      totalSeconds += 60 * values[i]; remaining, 60 x number of minutes added
    } else {
      totalSeconds -= 60 * values[i];
    }//end of LEDstate check, and updating new "seconds left".
    SWstate[i] = SWstateNEW;  to update button state
    }//end of (for int i=0; i<6; i++, check SW)
    
    updateDisplay();
  
  }//end of checkSW

void checkTimerStop(){
  if(totalSeconds <= 0){ //it's always 0 but just to make sure
    timerRunning = false;
    totalSeconds = 0; //again, ik this is useless but just to make sure
    for (int i = 0; i < 8; i++) { //beep 8 times at a good frequency (comftorable frequency)
          tone(BUZZER, 554, 500); //c# sound, 554hz
          delay(500); 
    }
  } 
}

void updateDisplay() { 
  digitalWrite(LED1, LEDstate[0]);
  digitalWrite(LED2, LEDstate[1]);
  digitalWrite(LED4, LEDstate[2]);
  digitalWrite(LED8, LEDstate[3]);
  digitalWrite(LED16, LEDstate[4]);
  digitalWrite(LED32, LEDstate[5]);
}