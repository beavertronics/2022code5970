#pragma once

#include <ctre/Phoenix.h>

#include <frc/DigitalInput.h>

#include <frc2/command/SubsystemBase.h>


class ClimberSubsystem : public frc2::SubsystemBase {
 public:
  ClimberSubsystem();

  // Subsystem methods go here.

/**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Moves the climber up
   */
  void Climbup();

  /**
   * Move balls towards the shooter only if the shooter RPM is close to target
   */
  void ClimbAuto();

  /**
   * Move balls away from the shooter, towards the intake
   */
  void Climbdown();

  /**
   * Stop the Climber
   */
  void ClimbStop();
  
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX ClimbMotor{21};
};