using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftDriveA;
extern motor leftDriveB;
extern motor leftDriveC;
extern motor leftDriveD;
extern motor rightDriveA;
extern motor rightDriveB;
extern motor rightDriveC;
extern motor rightDriveD;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );