using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor rightDriveB;
extern motor rightDriveC;
extern motor rightDriveD;
extern motor rightDriveA;
extern motor leftDriveB;
extern motor leftDriveC;
extern motor leftDriveA;
extern motor leftDriveD;
extern controller Controller1;
extern motor_group Intake;
extern digital_out mogo;
extern inertial Inertial9;
extern rotation WallRotation;
extern optical ColorSorter;
extern digital_out pto;
extern limit LimitSelector;
extern digital_out wallAligner;
extern digital_out doinker;
extern rotation ForwardTracker;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );