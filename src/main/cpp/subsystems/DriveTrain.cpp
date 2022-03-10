// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"
#include <frc/smartdashboard/SmartDashboard.h>

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
  
  gyroAngle = gyro.GetAngle();
  frc::SmartDashboard::PutNumber("gyroAngle", gyroAngle);
  gyroRate = gyro.GetRate();
  frc::SmartDashboard::PutNumber("gyroRate", gyroRate);




}
void DriveTrain::TankDrive(double left, double right) {
  m_drive.TankDrive(left, right);
}
/*
void DriveTrain::FULLYEET(double left, double right){

  m_drive.TankDrive(1, 1);

}
*/
void DriveTrain::ZeroGyro(){
  gyro.Reset();
}
units::degree_t DriveTrain::GetHeading() {
  // make sure it fits in +/- 180.  Yaw does this, so should be ok.
  return units::degree_t((gyroAngle) * (kGyroReversed ? -1.0 : 1.0));
}

double DriveTrain::GetTurnRate() {
  return gyroRate * (kGyroReversed ? -1.0 : 1.0);
}
units::degree_t DriveTrain::SanitizeAngle(units::degree_t target){
  units::degree_t cleanedAngle = target;
  if ( cleanedAngle >= 180_deg) cleanedAngle -= 360_deg;
  if ( cleanedAngle <= -180_deg) cleanedAngle += 360_deg;
  return cleanedAngle;
}
void DriveTrain::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
