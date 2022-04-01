#include <cmath>

#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

// Constructor, set following, direction, and set initial state to in and stopped
ShooterSubsystem::ShooterSubsystem() {

    ShooterMotor.Set(ControlMode::Velocity, 0.0);
}

// Methods

// Implementation of subsystem periodic method goes here.
// for example, publish encoder settings or motor currents to dashboard
void ShooterSubsystem::Periodic() {
// get the electric eye statuses

}

void ShooterSubsystem::Shoot() {
    ShooterMotor.Set(ControlMode::PercentOutput, 1);
    IndexerMotor.Set(ControlMode::PercentOutput, -0.8);
    
}

void ShooterSubsystem::ShootCheckRPM() {
// get RPMs from network tables to avoid a ShooterSubsystem dependancy
// Here we check that RPMS are within kRPM_OK on the low side.  Anything faster is ok
// If you're worried about goign to fast, change this calculation
    if ((frc::SmartDashboard::GetNumber("RPM",0.0) + SRPM_OK) >= STargetRPM) 
        ShooterMotor.Set(ControlMode::PercentOutput, kShootSpeed);
}

void ShooterSubsystem::Unjam() {
    ShooterMotor.Set(ControlMode::PercentOutput, -0.3);
    IndexerMotor.Set(ControlMode::PercentOutput, 0.3);
}

void ShooterSubsystem::FeedForward() {
    ShooterMotor.Set(ControlMode::PercentOutput, kShootFeedForward);
}
void ShooterSubsystem::Intake() {
    ShooterMotor.Set(ControlMode::PercentOutput, 0.4);
    IntakerMotor.Set(ControlMode::PercentOutput, -0.5);
    IndexerMotor.Set(ControlMode::PercentOutput, 0.5);
}

void ShooterSubsystem::IntakeReverse(){

    ShooterMotor.Set(ControlMode::PercentOutput, -0.5);
    IntakerMotor.Set(ControlMode::PercentOutput, 0.5);
}
void ShooterSubsystem::Stop() {
    ShooterMotor.Set(ControlMode::PercentOutput, 0.0);
    IndexerMotor.Set(ControlMode::PercentOutput, 0.0);
    IntakerMotor.Set(ControlMode::PercentOutput, 0.0);
}

