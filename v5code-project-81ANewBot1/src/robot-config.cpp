#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
inertial Inertial3 = inertial(PORT3);
motor rightDriveB = motor(PORT1, ratio6_1, false);
motor rightDriveA = motor(PORT8, ratio18_1, true);
motor rightDriveC = motor(PORT10, ratio6_1, true);
motor leftDriveC = motor(PORT20, ratio6_1, false);
motor leftDriveB = motor(PORT17, ratio6_1, true);
motor leftDriveA = motor(PORT16, ratio18_1, false);
limit LimitSelector = limit(Brain.ThreeWirePort.B);
motor IntakeStage2MotorA = motor(PORT6, ratio18_1, true);
motor IntakeStage2MotorB = motor(PORT5, ratio18_1, false);
motor_group IntakeStage2 = motor_group(IntakeStage2MotorA, IntakeStage2MotorB);
motor IntakeStage1 = motor(PORT19, ratio18_1, false);
motor LiftMotorA = motor(PORT7, ratio18_1, false);
motor LiftMotorB = motor(PORT9, ratio18_1, true);
motor_group Lift = motor_group(LiftMotorA, LiftMotorB);
distance DistanceSensor = distance(PORT18);
digital_out mogo = digital_out(Brain.ThreeWirePort.A);
digital_out pto = digital_out(Brain.ThreeWirePort.C);
optical ColorSorter = optical(PORT15);

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