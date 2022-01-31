// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/Joystick.h>
#include "commands/DefaultDrive.h"

#include "Constants.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
 
 // Set up default drive command.  Does this whenever the DriveSubSystem isn't doing anything else
    m_drive.SetDefaultCommand(DefaultDrive(
      &m_drive,
      [this] { return m_leftStick.GetY(); },
      [this] { return m_rightStick.GetY(); }));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
