#pragma once

#include <ctre/Phoenix.h>

#include <frc/DigitalInput.h>

#include <frc2/command/SubsystemBase.h>


class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem();

  // Subsystem methods go here.

/**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Move balls towards the shooter
   */
  void Shoot();

  /**
   * Move balls towards the shooter only if the shooter RPM is close to target
   */
  void ShootCheckRPM();

  /**
   * Move balls away from the shooter, towards the intake
   */
  void Unjam();

  /**
   * Stop the shooter
   */
  void Stop();
  
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_VictorSPX ShooterMotor{9};
};