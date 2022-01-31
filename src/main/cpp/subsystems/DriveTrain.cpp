// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() {
  // Implementation of subsystem constructor goes here.
  // Stuff you want to happen once, when robot code starts running

  // Initialize each motor with MotionMagic settings
  // Made this a function since we do the same thing four times
  //ConfigureMotor(&RightLead);
  //ConfigureMotor(&RightFollow);
  //ConfigureMotor(&LeftLead);
  //ConfigureMotor(&LeftFollow);

  // Invert right side, since DifferentialDrive no longer does it for us
  LeftLead.SetInverted(true);
  LeftFollow.SetInverted(true);

  //Drive train motor grouping start
  RightFollow.Follow(RightLead);
  LeftFollow.Follow(LeftLead);
}

void DriveTrain::Periodic() {
  // Implementation of subsystem periodic method goes here.
}
void DriveTrain::TankDrive(double left, double right) {
  m_drive.TankDrive(left, right);
}
void DriveTrain::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
