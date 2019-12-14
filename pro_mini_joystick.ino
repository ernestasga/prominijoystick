#include "Joystick.h"

// Create Joystick
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, 2, 0,
  true, true, false, false, false, false,
  false, false, false, false, false);
  
// Set to true to test "Auto Send" mode or false to test "Manual Send" mode.
const bool testAutoSendMode = true;
//const bool testAutoSendMode = false;

int xin = A0;
int yin = A1;

int b1in = 2;
int b2in = 3;

void setup() {
  // put your setup code here, to run once:
  
  // Set Range Values
  Joystick.setXAxisRange(-127, 127);
  Joystick.setYAxisRange(-127, 127);


  pinMode(xin, INPUT);
  pinMode(yin, INPUT);


  pinMode(b1in, INPUT_PULLUP);
  pinMode(b2in, INPUT_PULLUP);

  Joystick.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(xin);
  int y = analogRead(yin);


  
  Joystick.setXAxis(map(x, 0, 1023, -127, 127));
  Joystick.setYAxis(map(y, 1023, 0, -127, 127));

  Joystick.setButton(0, !digitalRead(b1in));
  Joystick.setButton(1, !digitalRead(b2in));

}
