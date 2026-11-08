#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor leftDriveB = motor(PORT8, ratio6_1, true);
motor leftDriveA = motor(PORT20, ratio6_1, true);
motor leftDriveC = motor(PORT9, ratio6_1, false);
motor rightDriveC = motor(PORT19, ratio6_1, true);
motor rightDriveB = motor(PORT7, ratio6_1, false);
motor rightDriveA = motor(PORT11, ratio6_1, false);
limit LimitSelector = limit(Brain.ThreeWirePort.H);
motor IntakeStage2 = motor(PORT1, ratio18_1, true);
motor IntakeMain = motor(PORT2, ratio6_1, false);
motor basket = motor(PORT13, ratio18_1, false);
inertial Inertial10 = inertial(PORT10);
digital_out hood = digital_out(Brain.ThreeWirePort.B);
digital_out matchload = digital_out(Brain.ThreeWirePort.D);
digital_out descore = digital_out(Brain.ThreeWirePort.C);
digital_out bobby = digital_out(Brain.ThreeWirePort.A);

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