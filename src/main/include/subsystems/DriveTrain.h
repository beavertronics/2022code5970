// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>




class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
    void Periodic() override;

    // Declares the style of human control the robot will use
    void TankDrive(double left, double right);

    void SetMaxOutput(double maxOutput);
  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
    void SimulationPeriodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.


  // right motor controllers
  WPI_VictorSPX RightLead{5};
  WPI_VictorSPX RightFollow{6};
  // left motor controllers
  WPI_VictorSPX LeftLead{3};
  WPI_VictorSPX LeftFollow{4};

  // DriveTrain being declared as diffy drive which is also WCD
  frc::DifferentialDrive m_drive{RightLead, LeftLead};

};
