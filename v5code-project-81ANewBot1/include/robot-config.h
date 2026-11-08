using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern inertial Inertial3;
extern motor rightDriveB;
extern motor rightDriveA;
extern motor rightDriveC;
extern motor leftDriveC;
extern motor leftDriveB;
extern motor leftDriveA;
extern limit LimitSelector;
extern motor_group IntakeStage2;
extern motor IntakeStage1;
extern motor_group Lift;
extern distance DistanceSensor;
extern digital_out mogo;
extern digital_out pto;
extern optical ColorSorter;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );