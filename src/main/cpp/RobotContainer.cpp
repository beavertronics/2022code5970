// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/button/JoystickButton.h>
#include <frc/Joystick.h>
#include "commands/DefaultDrive.h"


#include <frc/shuffleboard/Shuffleboard.h>
#include "commands/ClimbUp.h"
#include "commands/ClimbDown.h"
#include "commands/ClimbAuto.h"
#include "commands/ClimbStop.h"

#include "commands/ShooterShoot.h"
#include "commands/ShooterStop.h"
#include "commands/ShooterUnjam.h"
#include "commands/Intake.h"
#include "Constants.h"

RobotContainer::RobotContainer()
: m_autonomousCommand(m_drive) {
  // Initialize all of your commands and subsystems here
 // Initialize all of your commands and subsystems here

  // Add commands to the autonomous command chooser
  

// lord help us 
  // Configure the button bindings
  ConfigureButtonBindings(); 

// Set up default drive command.  Does this whenever the DriveSubSystem isn't doing anything else
    m_drive.SetDefaultCommand(DefaultDrive(
      &m_drive,
      [this] { return m_leftStick.GetY(); },
      [this] { return m_rightStick.GetY(); }));

// Set default intake, shooter, and indexer command.  Does this when not doing something else
  m_shooter.SetDefaultCommand(ShooterStop(&m_shooter));

// Set default climber command.  Does this when not doing something else
  m_climb.SetDefaultCommand(ClimbStop(&m_climb));
}


void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // Just driving isn't a button, it's the default mode for the DriveTrain 
  // subsystem, see above

  // Why use these new JoyStickButton commands?  Because they're the "command" way to do it
  
  //  .WhileHeld() keeps firing off the job while you hold the button, rescheduling it if it stops.
  //  .WhenHeld() only does it once
  //  both cancel the job when you let go of the button.
  // We have most of these commands go forever, to get canceled when the button is let off?
  // how to mess with them in auto, then?  Need end conditions, and Triggers that aren't
  // tied to buttons.  Answer: timeouts.
  // So, changed the .WhileHeld() to .WhenHeld()

  // Spin up shooter motor for low while pressed
  frc2::JoystickButton(&m_xbox, Button::kA)
      .WhenHeld(ShooterShoot(&m_shooter));

  //Spin up shooter motor for high while pressed, and rumble controller if you're too close
  frc2::JoystickButton(&m_xbox, Button::kY)
      .WhenHeld(ShooterUnjam(&m_shooter));

  frc2::JoystickButton(&m_xbox, Button::kX)
      .WhenHeld(Intake(&m_shooter));

  frc2::JoystickButton(&m_xbox, Button::kBumperLeft)
      .WhenHeld(ClimbUp(&m_climb));
    
  frc2::JoystickButton(&m_xbox, Button::kBumperRight)
      .WhenHeld(ClimbDown(&m_climb));

  
  frc2::JoystickButton(&m_leftStick, 1)
        .ToggleWhenPressed(DefaultDrive(
      &m_drive,
      [this] { return -m_rightStick.GetY(); },
      [this] { return -m_leftStick.GetY(); }));   

   

  // move intake arm out and spin intake wheels while A is held down
// you can stack commands like this (below).  But in this case, RetractIntake is the default anyway
//      .WhenReleased(RetractIntake(&m_cargo)); 

}


frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

