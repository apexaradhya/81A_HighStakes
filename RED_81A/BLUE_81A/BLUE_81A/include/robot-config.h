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
extern digital_out wallAligner;
extern inertial Inertial9;
extern rotation WallRotation;
extern optical ColorSorter;
extern digital_out wallStake;
extern limit LimitSelector;
extern digital_out mogo;
extern digital_out mogoTipper;
extern rotation ForwardTracker;
extern digital_out doinker;
extern motor IntakeStage1;
extern motor IntakeStage2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );