// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
//sets contants for PID loops and for motors without encoders 
constexpr double kIntakeSpeed = 0.5;
constexpr double kTargetRPM = 500;

constexpr double kRPM_OK = 10.0;


constexpr double kShootSpeed = 1.0;
constexpr double SRPM_OK = 10.0;
constexpr double STargetRPM = 500;
constexpr double kShootFeedForward = 0.2;



constexpr double kIndexerSpeed = 1.0;

