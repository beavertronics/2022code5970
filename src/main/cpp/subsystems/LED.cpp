/*
This section of the code controls the onboard LED lightstrips on the sides of the robot
NOT FINISHED - Mar. 29
*/
/*#include <array>

#include <frc/AddressableLED.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>

class Robot : public frc::TimedRobot {
  static constexpr int kLength = 60;
  frc::AddressableLED m_led{9}; // PORT NUMBER
  std::array<frc::AddressableLED::LEDData, kLength>m_ledBuffer;  // LEDData data type, kLength integer value
  int firstPixelHue = 0;// Store what the last hue of the first pixel is

 public:
  void Rainbow() {
    for (int i = 0; i < kLength; i++) {
      const auto pixelHue = (firstPixelHue + (i * 180 / kLength)) % 180;
      // Set the value
      m_ledBuffer[i].SetHSV(pixelHue, 255, 128);
    }
    // Increase by to make the rainbow "move"
    firstPixelHue += 3;
    // Check bounds
    firstPixelHue %= 180;
  }
  void Red(){// RED is hsv(0, 100%, 100%)
    for (int i = 0; i < kLength; i++){
        m_ledBuffer[i].setHSV(0, 255, 128));
    }
  }
  void Blue(){//Blue hsv(240, 100%, 100%)
    for (int i = 0; i < kLength; i++){
        m_ledBuffer[i].setHSV(240, 255, 128));
    }
  }
  void Orange(){//orange hsv(39, 100%, 100%)
    for (int i = 0; i < kLength; i++){
        m_ledBuffer[i].SetHSV(39, 255, 128));
    }
  }
  void Flag(){//pride flag, country flags
    // not set rn
  }

  void RobotInit() override {
    // Default to a length of 60, start empty output
    // Length is expensive to set, so only set it once, then just update data
    m_led.SetLength(kLength);
    m_led.SetData(m_ledBuffer);
    m_led.Start();
  }

  void RobotPeriodic(LED_Select) override {
    // Fill the buffer with a rainbow
    switch(LED_Select){//LED_Select parameter?
        case "rainbow":
            Rainbow();
            break;
        case "red":
            Red();
            break;
        case "blue":
            Blue();
            break;
        case "orange":
            Orange();
            break;
        case "flag":
            Flag();
            break;
        default:
            //team colors (HERE)
            
    }
    // Set the LEDs
    m_led.SetData(m_ledBuffer);
  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
*/
