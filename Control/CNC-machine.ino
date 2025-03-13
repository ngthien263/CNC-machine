#include "AccelStepper.h"   //https://www.airspayce.com/mikem/arduino/AccelStepper/
//#include <AccelStepper.h> //if use zip file to install

#define STEP1_STEPPIN 
#define STEP1_DIRPIN 
class StepMotor : public AccelStepper {
  public:
    StepMotor(uint8_t stepPin, uint8_t dirPin) : AccelStepper(AccelStepper::DRIVER, stepPin, dirPin){
      setMaxSpeed(1000);
      setCurrentPosition(0);
    }
    
    typedef enum {
      FULL_STEP = 1,   // 1/1 Step
      HALF_STEP = 2,   // 1/2 Step
      QUARTER_STEP = 4,  // 1/4 Step
      EIGHTH_STEP = 8,   // 1/8 Step
      SIXTEENTH_STEP = 16,  // 1/16 Step (A4988)
      //THIRTYSECOND_STEP = 32  // 1/32 Step (DRV8825)
    } MicroStepping;

    void movebyRotations(MicroStepping mstep, Direction dir, int sspeed, int rotations) {
       setCurrentPosition(0);
       int _steps = rotations * 200 * mstep;
       int _dir   =  (dir == DIRECTION_CW) ? 1 : -1;
       AccelStepper::setSpeed(sspeed * _dir);
       while(currentPosition() != _steps) {
          run();
       }
    }
};

StepMotor Step1(STEP1_STEPPIN ,STEP1_DIRPIN);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
