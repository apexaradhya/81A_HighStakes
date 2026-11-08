#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rightDriveB          motor         11              
// rightDriveC          motor         2               
// rightDriveD          motor         3               
// rightDriveA          motor         4               
// leftDriveB           motor         10              
// leftDriveC           motor         18              
// leftDriveA           motor         8               
// leftDriveD           motor         19              
// Controller1          controller                    
// Intake               motor_group   17, 12          
// mogo                 digital_out   A               
// Inertial9            inertial      9               
// WallRotation         rotation      13              
// ColorSorter          optical       14              
// pto                  digital_out   E               
// LimitSelector        limit         C               
// wallAligner          digital_out   D               
// doinker              digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(leftDriveA, leftDriveB, leftDriveC, leftDriveD),

//Right Motors:
motor_group(rightDriveA, rightDriveB, rightDriveC, rightDriveD),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT9,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.8,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
13,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
4.5

);

int current_auton_selection = 0;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  Inertial9.calibrate();
  wait(2, seconds);

  ColorSorter.setLight(ledState::on);
  ColorSorter.setLightPower(50, pct);
  ColorSorter.gestureDisable();

  Controller1.Screen.print(leftDriveA.temperature());
  Controller1.Screen.print(rightDriveA.temperature());
  Controller1.Screen.print(Intake.temperature());

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "RED: LEFT Side Solo AWP");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "RED: RIGHT Side Half AWP");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Programming Skills - ARNAV IS STANKY!!");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Swing Test");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Full Test");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "Odom Test");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "Tank Odom Test");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
        break;
    }
    if(LimitSelector.pressing()){
      while(LimitSelector.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      blue_right(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      blue_left();
      break;
    case 2:
      prog_skills();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

bool toggle = false;
bool latch = false;

bool toggle1 = false;
bool latch1 = false;

bool toggle2 = false;
bool latch2 = false;

bool toggle3 = false;
bool latch3 = false;


void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    Intake.setVelocity(100, percent);
    
    if (Controller1.ButtonL1.pressing()){
      Intake.spin(forward);
    }
    else if(Controller1.ButtonL2.pressing()){
      Intake.spin(reverse);
    }
    else {
      Intake.stop();
    }

    /*if (ColorSorter.hue() >= 217) {
      wait(0.3, sec);
      Intake.spinFor(-100, degrees);
      Intake.setTimeout(100, msec);
      Intake.spinFor(0.4, sec);
    }*/


    /*if (Controller1.ButtonR1.pressing()){

      leftDriveC.spin(reverse);
      rightDriveC.spin(reverse);
    }
    else if (Controller1.ButtonR2.pressing()){
      leftDriveC.setMaxTorque(100, pct);
      rightDriveC.setMaxTorque(100, pct);

      leftDriveC.spin(fwd);
      rightDriveC.spin(fwd);
    }
    else {

      leftDriveC.stop();
      rightDriveC.stop();
    }*/

    if (toggle){
      mogo = true;
      
    }
    else {
      mogo = false;

      leftDriveC.setVelocity(100, pct);
      rightDriveC.setVelocity(100, pct);
    }

    if (Controller1.ButtonY.pressing()) {
      if(!latch){ //flip the toggle one time and set the latch
      toggle = !toggle;
      latch = true;
      }
    } else {
      //Once the BumperA is released then then release the latch too
      latch = false;
    }

    if (toggle1){
      pto = true;      

      rightDriveC.setVelocity(100, pct);
      leftDriveC.setVelocity(100, pct);
     
      while (Controller1.ButtonR1.pressing()){
        leftDriveC.spin(forward);
        rightDriveC.spin(forward);
      }
      while (Controller1.ButtonR2.pressing()){
        leftDriveC.spin(reverse);
        rightDriveC.spin(reverse);
      }
      while (Controller1.ButtonL2.pressing()) {
        Intake.spin(reverse);
      }
      while (Controller1.ButtonL1.pressing()) {
        Intake.spin(fwd);
      }
     
      
    }
    else {
      pto = false;
    }
    if (Controller1.ButtonDown.pressing()) {
      if(!latch1){ //flip the toggle one time and set the latch
      toggle1 = !toggle1;
      latch1 = true;
      }
    } else {
      //Once the BumperA is released then then release the latch too
      latch1 = false;
    }

    if (toggle2){
      wallAligner = true;
    }
    else {
      wallAligner = false;
    }

    if (Controller1.ButtonB.pressing()) {
      if(!latch2){ //flip the toggle one time and set the latch
      toggle2 = !toggle2;
      latch2 = true;
      }
    } else {
      //Once the BumperA is released then then release the latch too
      latch2 = false;
    }

    if (toggle3){
      doinker = true;
    }
    else {
      doinker = false;
    }

    if (Controller1.ButtonRight.pressing()) {
      if(!latch3){ //flip the toggle one time and set the latch
      toggle3 = !toggle3;
      latch3 = true;
      }
    } else {
      //Once the BumperA is released then then release the latch too
      latch3 = false;
    }


    
    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_tank();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
  