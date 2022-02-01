// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/Joystick.h>
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include <frc/XboxController.h>
#include "subsystems/DriveTrain.h"

#include "subsystems/IntakeSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
 
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  // Declares Drivetrain as m_drive
  DriveTrain m_drive;

  IntakeSubsystem m_intake;

  ShooterSubsystem m_shooter;
  // Adds Jotsticks to the robot.
  frc::Joystick m_leftStick{0};
  frc::Joystick m_rightStick{1};

  frc::XboxController m_xbox{2};

  void ConfigureButtonBindings();

  
};
