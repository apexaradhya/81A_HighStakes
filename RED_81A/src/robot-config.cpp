#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor rightDriveB = motor(PORT11, ratio6_1, false);
motor rightDriveC = motor(PORT2, ratio6_1, true);
motor rightDriveD = motor(PORT3, ratio18_1, false);
motor rightDriveA = motor(PORT4, ratio6_1, false);
motor leftDriveB = motor(PORT10, ratio6_1, true);
motor leftDriveC = motor(PORT18, ratio6_1, false);
motor leftDriveA = motor(PORT8, ratio6_1, true);
motor leftDriveD = motor(PORT19, ratio18_1, true);
controller Controller1 = controller(primary);
motor IntakeMotorA = motor(PORT17, ratio18_1, true);
motor IntakeMotorB = motor(PORT12, ratio18_1, true);
motor_group Intake = motor_group(IntakeMotorA, IntakeMotorB);
digital_out mogo = digital_out(Brain.ThreeWirePort.A);
inertial Inertial9 = inertial(PORT9);
rotation OdomTracker1 = rotation(PORT13, false);
optical ColorSorter = optical(PORT14);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}