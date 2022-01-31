// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntakeSubsystem.h"

#include "Constants.h"

IntakeSubsystem::IntakeSubsystem() {
  // Implementation of subsystem constructor goes here.
  IntakeMotor.Set(ControlMode::PercentOutput, 0);
}

void IntakeSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}



void IntakeSubsystem::Intake() {
  // Implementation of subsystem intake forward method goes here.
}


void IntakeSubsystem::Stop() {
  // Implementation of subsystem intake stop method goes here.
  IntakeMotor.Set(ControlMode::PercentOutput, 0);
}

void IntakeSubsystem::Unjam() {
  // Implementation of subsystem intake unjam method goes here.

}

void IntakeSubsystem::GetRPM() {
  // Implementation of subsystem intake get rpm method goes here.
}
void IntakeSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
