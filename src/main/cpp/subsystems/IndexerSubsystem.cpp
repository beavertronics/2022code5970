#include <cmath>

#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/IndexerSubsystem.h"

#include "Constants.h"

// Constructor, set following, direction, and set initial state to in and stopped
IndexerSubsystem::IndexerSubsystem() {

    IndexerMotor.Set(ControlMode::PercentOutput, 0.0);
}

// Methods

// Implementation of subsystem periodic method goes here.
// for example, publish encoder settings or motor currents to dashboard
void IndexerSubsystem::Periodic() {
// get the electric eye statuses

}

void IndexerSubsystem::Forward() {
    IndexerMotor.Set(ControlMode::PercentOutput, kIndexerSpeed);
}

void IndexerSubsystem::ForwardCheckRPM() {
// get RPMs from network tables to avoid a ShooterSubsystem dependancy
// Here we check that RPMS are within kRPM_OK on the low side.  Anything faster is ok
// If you're worried about goign to fast, change this calculation
    if ((frc::SmartDashboard::GetNumber("RPM",0.0) + kRPM_OK) >= kTargetRPM) 
        IndexerMotor.Set(ControlMode::PercentOutput, kIndexerSpeed);
}

void IndexerSubsystem::Backward() {
    IndexerMotor.Set(ControlMode::PercentOutput, -kIndexerSpeed);
}
// Command to stop the intake motor and set to 0 speed
void IndexerSubsystem::Stop() {
    IndexerMotor.Set(ControlMode::PercentOutput, 0.0);
}