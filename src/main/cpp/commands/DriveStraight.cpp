/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveStraight.h"

#include <frc/controller/PIDController.h> 

#include "Robot.h"

DriveStraight::DriveStraight(double power, DriveTrain& drivetrain)
    : frc2::CommandHelper<frc2::PIDCommand, DriveStraight>(
          frc2::PIDController(kStabilizationP, kStabilizationI, kStabilizationD),
          [&drivetrain] { return 1; }, power,
          [&drivetrain](double output) { drivetrain.TankDrive(output, output); },
          {&drivetrain}),
      m_drivetrain(&drivetrain) {
  m_controller.SetTolerance(0.01);
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
  // Get everything in a safe starting state.

  frc2::PIDCommand::Initialize();
}

bool DriveStraight::IsFinished() {
  return m_controller.AtSetpoint();
}