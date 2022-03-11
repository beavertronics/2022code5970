/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto.h"
#include "commands/DriveStraight.h"
#include "commands/ShooterShoot.h"
// Can "decorate" commands.  eg:
// command.WithTimeout(1_s)  cancels the command after the time has elapsed
// Will be interrupted if m_limitSwitch.get() returns true.  eg, electric eyes and ball intake
// command.InterruptOn([&m_limitSwitch] { return m_limitSwitch.Get(); });

Autonomous::Autonomous(DriveTrain& DriveTrain, ShooterSubsystem& ShooterSubsystem) {
  SetName("Autonomous");
  AddCommands(
     DriveStraight(-1,DriveTrain).WithTimeout(1.5_s),
     ShooterShoot(0).WithTimeout(1.5_s)
      
    );
  // clang-format on
}