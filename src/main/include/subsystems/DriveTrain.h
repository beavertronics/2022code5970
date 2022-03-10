// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include "Constants.h"
#include <frc/ADXRS450_Gyro.h> // gyro




class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
    void Periodic() override;

    // Declares the style of human control the robot will use
    void TankDrive(double left, double right);

    //void FULLYEET(double left, double right);


    void ZeroGyro(void);

    /**
   * Returns the heading of the robot.
   *
   * @return the robot's heading in degrees, from 180 to 180
   */
  units::degree_t GetHeading();

  /**
   * Returns the turn rate of the robot.
   *
   * @return The turn rate of the robot, in degrees per second
   */
  double GetTurnRate();

  /**
   * Returns the heading to the limelight target
   *
   * @return The heading at which the limelight target sits
   */
  units::degree_t GetLimelightTargetAngle();


    void SetMaxOutput(double maxOutput);
  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
    void SimulationPeriodic() override;
 /**
   * make sure target angle is in the right range
   *
   * @return The angle to turn to, put into -180,180 degrees
   */
  units::degree_t SanitizeAngle(units::degree_t target);
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.


  // right motor controllers

  WPI_VictorSPX RightLead{41};
  WPI_VictorSPX RightFollow{42};
  // left motor controllers
  WPI_VictorSPX LeftLead{43};
  WPI_VictorSPX LeftFollow{44};

  // DriveTrain being declared as diffy drive which is also WCD
  frc::DifferentialDrive m_drive{RightLead, LeftLead};
  frc::ADXRS450_Gyro gyro;  
  
   double gyroAngle = 0.0;  // What is the angle (degrees) from the gyro?
   double gyroRate = 0.0;  // What is the rate (degrees/sec) from the gyro?

};
