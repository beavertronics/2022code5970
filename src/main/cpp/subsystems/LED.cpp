#include <cmath>

#include <frc/smartdashboard/Smartdashboard.h>
/*
#include "subsystems/LED.h"
#include <frc/Addressableled.h>
#include "Constants.h"

// Constructor, set following, direction, and set initial state to in and stopped
LED::LED() {

static constexpr int kLength = 60;
    // Default to a length of 60, start empty output
    // Length is expensive to set, so only set it once, then just update data
    m_led.SetLength(kLength);
    m_led.SetData(m_ledBuffer);
    m_led.Start();
  // PWM port 9
  // Reuse the buffer
  // Store what the last hue of the first pixel is
 // int firstPixelHue = 0;
}

// Methods

// Implementation of subsystem periodic method goes here.
// for example, publish encoder settings or motor currents to dashboard
void LED::Periodic() {
// get the electric eye statuses

  // PWM port 9
  // Must be a PWM header, not MXP or DIO
 
  
      // Reuse the buffer
  // Store what the last hue of the first pixel is
 
  
}

void LED::Blue() {
for (int i = 0; i < kLength; i++) {
   m_ledBuffer[i].SetHSV(0, 100, 100);
}

m_led.SetData(m_ledBuffer);
}

void LED::Red() {
// get RPMs from network tables to avoid a ShooterSubsystem dependancy
// Here we check that RPMS are within kRPM_OK on the low side.  Anything faster is ok
// If you're worried about goign to fast, change this calculation
 
}

void LED::Orange() {

    
}
// Command to stop the intake motor and set to 0 speed
void LED::PrideFlag() {

}

/*/