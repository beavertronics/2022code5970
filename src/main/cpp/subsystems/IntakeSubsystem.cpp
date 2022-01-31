#include "subsystems/IntakeSubsystem.h"

#include "Constants.h"

// Constructor, set initial state to in and stopped
IntakeSubsystem::IntakeSubsystem() {
    IntakeMotor.Set(ControlMode::PercentOutput, 0.0);
}

void IntakeSubsystem::Intake() {
    IntakeMotor.Set(ControlMode::PercentOutput, kIntakeSpeed);
}

void IntakeSubsystem::Stop() {
    IntakeMotor.Set(ControlMode::PercentOutput, 0.0);
}

//void IntakeSubsystem::Unjam() {
    //IntakeMotor.Set(ControlMode::PercentOutput, -kIntakeSpeed);
//}