/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <cmath>

#include "commands/DefaultDrive.h"
#include "Constants.h"

DefaultDrive::DefaultDrive(DriveTrain* subsystem,
                           std::function<double()> left,
                           std::function<double()> right)
    : m_drive{subsystem}, m_left{left}, m_right{right} {
  AddRequirements({subsystem});
}

void DefaultDrive::Execute() {

  // Apply stick deadzone 
  double m_leftStick = m_left();
  
  double m_rightStick = m_right();
  

  // drive it
  m_drive->TankDrive(m_leftStick, m_rightStick);
}

// no end condition, this is the fallback state