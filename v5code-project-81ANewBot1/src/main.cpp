#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Inertial3            inertial      3               
// rightDriveB          motor         1               
// rightDriveA          motor         8               
// rightDriveC          motor         10              
// leftDriveC           motor         20              
// leftDriveB           motor         17              
// leftDriveA           motor         16              
// LimitSelector        limit         B               
// IntakeStage2         motor_group   6, 5            
// IntakeStage1         motor         19              
// Lift                 motor_group   7, 9            
// DistanceSensor       distance      18              
// mogo                 digital_out   A               
// pto                  digital_out   C               
// ColorSorter          optical       15              
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

motor_group leftDrive = motor_group(leftDriveA, leftDriveB, leftDriveC);
motor_group rightDrive = motor_group(rightDriveA, rightDriveB, rightDriveC);

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
leftDrive,

//Right Motors:
rightDrive,

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT3,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

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
PORT5,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT7,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
8,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
13,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
4.5

);

// Create a new AI Vision Sensor "aiVision" with the aivision class.


int current_auton_selection = 0;
bool auto_started = false;

bool is_red = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  Inertial3.calibrate();
  wait(2, seconds);

  pto = false;

  ColorSorter.setLightPower(100, percent);
  ColorSorter.setLight(ledState::on);
  
  chassis.set_coordinates(0,  0,  0);

  Controller1.Screen.print(leftDriveA.temperature());
  Controller1.Screen.print(rightDriveA.temperature());


  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "RED RING SIDE");
        is_red = false;
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "BLUE RING SIDE");
        is_red = true;
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Programming Skills - ARNAV IS STANKY!!");
        is_red = true;
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "BLUE GOAL SIDE");
        is_red = true;
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "RED GOAL SIDE");
        is_red = true;
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
      ring_side_red(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      ring_side_blue();
      break;
    case 2:
      prog_skills();
      break;
    case 3:
      blue_goal_safe();
      break;
    case 4:
      red_goal_safe();
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
int currentState = 0;
bool latch = false;

bool toggle1 = false;
bool latch1 = false;

bool toggle2 = false;
bool latch2 = false;

bool toggle3 = false;
bool latch3 = false;

bool toggle4 = false;
bool latch4 = false;

bool intake_reversed = false;

const int number_of_states = 3;
int states[number_of_states] = {0, 100, 720};
int current_state = 0;
int target = 0;

void next_state() {
  current_state += 1;
  if (current_state == number_of_states){
    current_state = 0;
  }
  target = states[current_state];
}

void lift_control() {
  double Liftkp = 1.4;
  double LiftError = target - Lift.position(degrees);
  double LiftVelocity = Liftkp * LiftError;
  Lift.spinFor(LiftVelocity, degrees);
}

// AI Vision Sensor Profiles:



void usercontrol(void) {
  // User control code here, inside the loop

  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  Lift.setVelocity(100, pct);
  Lift.setStopping(hold);



  while (1) {
    
    if(intake_reversed == true) {
      IntakeStage1.setVelocity(100, pct);
      IntakeStage2.setVelocity(100, pct);
      
      if(Controller1.ButtonL1.pressing()) {
        IntakeStage1.spin(forward);
        IntakeStage2.spin(reverse);
        /*if(ColorSorter.color() == orange){
          wait(0.1, sec);
          IntakeStage2.stop();
          wait(0.4, sec);
        }*/
      }
      else if(Controller1.ButtonL2.pressing()) {
        IntakeStage1.spin(reverse);
        IntakeStage2.spin(forward);
      }
      else {
        IntakeStage1.stop();
        IntakeStage2.stop();
      }
    }
    else {
      if(Controller1.ButtonL1.pressing()) {
        IntakeStage1.spin(forward);
        IntakeStage2.spin(forward);
        /*if(ColorSorter.hue() <= 35){ // Color Sorter code for red
          wait(0.3, sec);
          IntakeStage2.stop();
          wait(0.05, sec);
        }*/
      }
      else if(Controller1.ButtonL2.pressing()) {
        IntakeStage1.spin(reverse);
        IntakeStage2.spin(reverse);
      }
      else {
        IntakeStage1.stop();
        IntakeStage2.stop();
      }
    }


    /*if(Controller1.ButtonR1.pressing()) {
      Lift.spin(forward);
    }
    else if(Controller1.ButtonR2.pressing()) {
      Lift.spin(reverse);
    }
    else {
      Lift.stop();
    }*/
    if (toggle1){
      mogo = true;
      
    }
    else {
      mogo = false;
    }

    if (Controller1.ButtonY.pressing()) {
      if(!latch1){ //flip the toggle one time and set the latch
      toggle1 = !toggle1;
      latch1 = true;
      }
    } else {
      //Once the BumperA is released then then release the latch too
      latch1 = false;
    }

    if(Controller1.ButtonR2.pressing()){
      IntakeStage1.spin(fwd);
      if (DistanceSensor.objectDistance(inches) <= 1){
        IntakeStage2.spin(reverse);
        wait(0.1, sec);
      }
    }

    if (Controller1.ButtonR1.pressing()) {
      
      intake_reversed = true;
      
      if (!latch) {
        currentState++;
        if (currentState > 3) {
          currentState = 1;
        }
        latch = true;
        switch (currentState) {
          case 1:
            Lift.setTimeout(1, sec); 
            Lift.spinFor(210, degrees);
            
            break;
          case 2:
            Lift.setTimeout(1, sec); 
            Lift.spinFor(360, degrees);
            break;
          case 3:
            Lift.setTimeout(1, sec); 
            Lift.spinFor(-600, degrees);
            break;
        }
      }
    } else {
      latch = false;
      intake_reversed = false;
    }

    if (toggle3){
      Lift.setTimeout(2, sec);
      Lift.spinFor(300, degrees);
      pto = true;
      
    }
    else {
      
    }

    if (Controller1.ButtonB.pressing()) {
      if (Controller1.ButtonA.pressing()){
        if(!latch3){ //flip the toggle one time and set the latch
          toggle3 = !toggle3;
          latch3 = true;
        }
      }
    } else {
      //Once the BumperA is released then then release the latch too
      latch3 = false;
    }

    if (toggle2){
      
    }
    else {
      
    }

    if (Controller1.ButtonA.pressing()) {
      Lift.setTimeout(2, sec);
      Lift.spinFor(540, degrees);
      Lift.spinFor(-20, degrees);
      Lift.stop();
      pto = true;
    }

    if (toggle4){
      pto = true;
      
    }
    else {
      pto = false;
    }

    if (Controller1.ButtonLeft.pressing()) {
      if(!latch4){ //flip the toggle one time and set the latch
      toggle4 = !toggle4;
      latch4 = true;
      }
    } else {
      //Once the BumperA is released then then release the latch too
      latch4 = false;
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