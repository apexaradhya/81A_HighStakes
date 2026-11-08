using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor leftDriveB;
extern motor leftDriveA;
extern motor leftDriveC;
extern motor rightDriveC;
extern motor rightDriveB;
extern motor rightDriveA;
extern limit LimitSelector;
extern motor IntakeStage2;
extern motor IntakeMain;
extern motor basket;
extern inertial Inertial10;
extern digital_out hood;
extern digital_out matchload;
extern digital_out descore;
extern digital_out bobby;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );