#include <cmath>

#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ClimberSubsystem.h"

#include "Constants.h"

// Constructor, set following, direction, and set initial state to in and stopped
ClimberSubsystem::ClimberSubsystem() {

    LeftClimbMotor.Set(ControlMode::PercentOutput, 0.0);
    RightClimbMotor.Set(ControlMode::PercentOutput, 0.0);
}

// Methods

// Implementation of subsystem periodic method goes here.
// for example, publish encoder settings or motor currents to dashboard
void ClimberSubsystem::Periodic() {
// get the electric eye statuses

}

void ClimberSubsystem::Climbup() {
    LeftClimbMotor.Set(ControlMode::PercentOutput, -kIntakeSpeed);
    RightClimbMotor.Set(ControlMode::PercentOutput, kIntakeSpeed);
}

void ClimberSubsystem::ClimbAuto() {
// get RPMs from network tables to avoid a ShooterSubsystem dependancy
// Here we check that RPMS are within kRPM_OK on the low side.  Anything faster is ok
// If you're worried about goign to fast, change this calculation
    if ((frc::SmartDashboard::GetNumber("RPM",0.0) + kRPM_OK) >= kTargetRPM) 
        LeftClimbMotor.Set(ControlMode::PercentOutput, kIntakeSpeed);
}

void ClimberSubsystem::Climbdown() {
    LeftClimbMotor.Set(ControlMode::PercentOutput, kIntakeSpeed);
    RightClimbMotor.Set(ControlMode::PercentOutput, -kIntakeSpeed);
    
}
// Command to stop the intake motor and set to 0 speed
void ClimberSubsystem::ClimbStop() {
    LeftClimbMotor.Set(ControlMode::PercentOutput, 0.0);
    RightClimbMotor.Set(ControlMode::PercentOutput, 0.0);

}