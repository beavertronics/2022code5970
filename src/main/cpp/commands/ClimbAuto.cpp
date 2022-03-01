// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ClimbAuto.h"

ClimbAuto::ClimbAuto(ClimberSubsystem* subsystem) : m_climb(subsystem) {
  AddRequirements({subsystem});
}

void ClimbAuto::Initialize() { m_climb->ClimbAuto(); }

// this is a state, it lasts till it's cancelled
// It is also the default state, so needs to run forever
// although we could check if we hit an electic eye
bool ClimbAuto::IsFinished() { return false; }