/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto.h"
#include "commands/DriveStraight.h"
#include "commands/ShooterShoot.h"
#include "commands/DriveTurn.h"
#include "commands/Intake.h"
// Can "decorate" commands.  eg:
// command.WithTimeout(1_s)  cancels the command after the time has elapsed
// Will be interrupted if m_limitSwitch.get() returns true.  eg, electric eyes and ball intake
// command.InterruptOn([&m_limitSwitch] { return m_limitSwitch.Get(); });
//turn(1)= counter clock wise
//turn(-1) = clock wise

//straight(-1)= Shooter forwards
//straight(1)= intake forwards
//0.95 = 90degree turn 
//80 inches in 1 second at max power 
Autonomous::Autonomous(DriveTrain& DriveTrain, ShooterSubsystem& ShooterSubsystem) {
  SetName("Autonomous");
  AddCommands(
      ShooterShoot(ShooterSubsystem).WithTimeout(1.5_s),
      DriveStraight(1,DriveTrain).WithTimeout(1.2_s)
      //DriveTurn(1,DriveTrain).WithTimeout(0.3_s),
      //DriveStraight(1,DriveTrain).WithTimeout(2.3_s), 
      //Intake(ShooterSubsystem).WithTimeout(2.5_s)
      
     // DriveTurn(1,DriveTrain).WithTimeout(0.95_s),
      //DriveStraight(1,DriveTrain).WithTimeout(2.0_s)
      
    );
  // clang-format on
}