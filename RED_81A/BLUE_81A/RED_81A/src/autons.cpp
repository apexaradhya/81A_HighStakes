#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}

motor_group LeftDrive = motor_group(leftDriveA, leftDriveB, leftDriveC, leftDriveD);
motor_group RightDrive = motor_group(rightDriveA, rightDriveB, rightDriveC, rightDriveD);

void red_right(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.drive_distance(-21.5);
  chassis.turn_to_angle(37);
  chassis.drive_distance(-7);
  wait(0.35, seconds);
  chassis.drive_timeout = 800;
  chassis.drive_distance(-6);
  mogo = true;
  wait(0.5, seconds);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  wait(0.75, sec);
  chassis.turn_to_angle(-103);
  chassis.drive_distance(15);
  chassis.drive_timeout = 750;
  chassis.drive_distance(9);
  wait(0.5,  sec); // Can be reduced in later programs
  chassis.turn_to_angle(90);
  chassis.drive_distance(15);
  chassis.turn_to_angle(135);
  chassis.drive_distance(15);
  wallAligner = true;

  /*chassis.turn_timeout = 200;  GOAL RUSH CODE
  chassis.turn_to_angle(3);
  chassis.drive_distance(-37);
  //chassis.drive_distance(-9);
  //chassis.turn_timeout = 300;
  chassis.turn_to_angle(-31);
  //chassis.drive_timeout = 400;
  chassis.drive_distance(-9.5);
  wait(0.1, sec);
  chassis.drive_distance(-6.5);
  mogo = true;
  //wait(0.15, sec);
  chassis.turn_to_angle(75);
  IntakeStage1.spin(fwd);
  chassis.drive_distance(16);
  wait(0.5, sec);
  mogo = false;
  chassis.turn_to_angle(-75);
  chassis.drive_distance(-6);
  mogoTipper = true;
  chassis.turn_to_angle(-143);
  wait(0.5, sec);
  IntakeStage1.stop();
  mogoTipper = false;
  chassis.drive_distance(-20);
  chassis.drive_distance(-3);
  mogo = true;
  chassis.turn_to_angle(-80);
  IntakeStage1.spin(fwd);
  chassis.drive_distance(18);
  chassis.turn_to_angle(70);
  chassis.drive_distance(30);
  chassis.drive_distance(10);
  chassis.turn_to_angle(100);
  chassis.drive_distance(5);
  doinker = true;
  chassis.drive_distance(-6);
  doinker = false;
  chassis.turn_to_angle(85);
  chassis.drive_distance(10);
  chassis.turn_to_angle(-170);
  chassis.drive_distance(25);
  chassis.right_swing_to_angle(135);
  wallAligner = true;*/
}




void red_left(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;
  
  chassis.drive_timeout = 750;
  chassis.drive_distance(-15);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(90);
  chassis.drive_timeout = 700;
  chassis.drive_distance(-9);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  wait(0.75, sec);
  //IntakeStage1.spin(reverse);
  //wait(0.25, sec);
  chassis.drive_distance(9);
  IntakeStage1.stop();
  IntakeStage2.stop();
  //IntakeStage1.setVelocity(80, percent);
  //chassis.turn_timeout = 500;
  //chassis.turn_to_angle(0);
  //chassis.drive_timeout = 500;
  //chassis.drive_distance(-2);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-4);
  chassis.turn_to_angle(-127);//was-128
  chassis.drive_distance(-16);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-16);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  chassis.drive_distance(-4);//was -11
  mogo = true; 
  wait(0.15, sec);
  //chassis.drive_distance(5);
  chassis.turn_to_angle(45); // was 2
  wait(0.15, sec);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(35);
  wait(0.15, sec);
  chassis.drive_distance(-22);
  //wait(0.2, sec);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(0);//was 100
  chassis.drive_distance(19);
  wait(0.15, sec); //was 110
  chassis.drive_distance(5);
  //wait(0.3, sec);
  //chassis.drive_distance(-25);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(60);
  chassis.drive_distance(18);
  chassis.drive_distance(-19);
  //chassis.drive_distance(-5);
  chassis.turn_timeout = 400;
  chassis.turn_to_angle(180);//was 140
  chassis.drive_timeout = 300;
  chassis.drive_distance(8);
  chassis.turn_timeout = 250;
  chassis.turn_to_angle(145);
  chassis.drive_timeout = 700;
  chassis.drive_distance(35);
  //chassis.drive_distance(6);
  wallAligner = true;
}


void red_left_elims(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  
  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.drive_timeout = 750;
  chassis.drive_distance(14.25);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(90);
  chassis.drive_distance(4);
  wallStake = true;
  wait(0.75, sec);
  wallStake = false;
  chassis.drive_distance(-6);
  


  chassis.turn_to_angle(50);
  chassis.drive_distance(-22);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-20);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  //chassis.drive_timeout = 250;
  chassis.drive_distance(-6);//was -11
  mogo = true; 
  wait(0.15, sec);
  chassis.turn_to_angle(-141); // was 2
  //wait(0.15, sec);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(20);
  chassis.drive_distance(8);
  wait(0.15, sec);
  //IntakeStage1.spin(forward);
  chassis.drive_distance(-22);
  //wait(0.2, sec);
  //IntakeStage1.spin(forward);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(180);//was 100
  //IntakeStage1.spin(forward);
  chassis.drive_distance(19);
  //IntakeStage1.spin(forward);
  wait(0.15, sec); //was 110
  //IntakeStage1.spin(forward);
  chassis.drive_distance(5);
  //IntakeStage1.spin(forward);
  //wait(0.3, sec);
  //chassis.drive_distance(-25);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(-118);
  //IntakeStage1.spin(forward);
  chassis.drive_distance(18);
  wait(0.15, sec);
  //IntakeStage1.spin(forward);
  chassis.drive_distance(-23);
  wait(0.1, sec);
  //IntakeStage1.spin(forward);
  //chassis.drive_distance(-5);
  chassis.turn_timeout = 400;
  chassis.turn_to_angle(35);//was 140
  chassis.drive_distance(30);
  IntakeStage2.stop();
  chassis.drive_distance(20);
  chassis.turn_to_angle(0);
  chassis.drive_distance(30);
  chassis.drive_distance(30);
  chassis.drive_distance(30);
}


void prog_skills(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  /*chassis.drive_kp = 10;
  chassis.drive_ki = 5;
  chassis.drive_kd = 1;*/

  //ORIGINAL
  /*chassis.drive_timeout = 400;
  chassis.drive_distance(-5);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  wait(0.5, sec);
  IntakeStage1.stop();
  IntakeStage2.stop();
  chassis.drive_distance(10);
  chassis.drive_distance(8);*/

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);

  wallStake = true;
  wait(0.5, sec);
  wallStake = false;
  chassis.drive_distance(-20);
  chassis.drive_distance(20);
  chassis.drive_distance(-11.5);
  chassis.turn_to_angle(90);

  chassis.drive_distance(-17);
  chassis.drive_timeout = 800;
  chassis.drive_distance(-6);
  mogo = true;
  wait(0.35, sec);

  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-170);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(24);
  chassis.turn_timeout = 500;
  wait(0.2, sec);
  chassis.turn_to_angle(-90);//was 93
  wait(0.2, sec);
  chassis.drive_distance(12);
  //wait(0.5, sec);
  chassis.drive_distance(11);//was 12
  chassis.turn_to_angle(-160);
  chassis.drive_distance(20);
  //wait(0.2, sec);
  chassis.right_swing_to_angle(-13);
  chassis.turn_to_angle(-13);
  chassis.turn_timeout = 500;//was turn
  chassis.drive_distance(30);
  chassis.turn_to_angle(-5);
  wait(0.35, sec);
  chassis.drive_distance(15);
  //wait(0.4, sec);
  chassis.drive_distance(-3);//hash?
  chassis.drive_distance(7);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  wait(0.35, sec);
  chassis.turn_to_angle(-125);//was 55
  //wait(0.2, sec);
  chassis.drive_distance(15);//was 11
  //wait(0.25, sec);
  chassis.drive_distance(-3);//hash?
  //chassis.turn_to_angle(140);
  chassis.turn_to_angle(135);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-11);
  mogo = false;
  IntakeStage2.spinFor(-40, degrees);
  chassis.drive_distance(10);

  chassis.turn_to_angle(-90);
  chassis.drive_distance(-35);
  chassis.drive_distance(-30);
  chassis.drive_distance(-15);
  wait(0.25, sec);
  chassis.drive_distance(-7);
  chassis.drive_distance(-6);

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;
  
  mogo = true;
  wait(0.35, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(168);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(30);
  chassis.drive_distance(4);
  chassis.turn_timeout = 500;
  wait(0.2, sec);
  chassis.turn_to_angle(93);//was 93
  wait(0.2, sec);
  chassis.drive_distance(14);
  //wait(0.5, sec);
  chassis.drive_distance(12);//was 12
  wait(0.2, sec);
  chassis.turn_to_angle(150);
  chassis.drive_distance(37);
  chassis.drive_distance(7);
  wait(0.2, sec);
  chassis.left_swing_to_angle(10);
  chassis.turn_to_angle(10);
  chassis.turn_timeout = 500;//was turn
  chassis.drive_distance(30);
  chassis.drive_distance(18);
  chassis.turn_to_angle(5);
  wait(0.35, sec);
  chassis.drive_distance(22);
  //wait(0.4, sec);
  chassis.drive_distance(-3);//hash?
  chassis.drive_distance(12);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  wait(0.35, sec);
  //wait(0.6, sec);
  chassis.turn_to_angle(125);//was 55
  //wait(0.2, sec);
  chassis.drive_distance(18);//was 11
  //wait(0.25, sec);
  chassis.drive_distance(-10);//hash?
  //chassis.turn_to_angle(140);
  chassis.turn_to_angle(-115);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-11);
  mogo = false;
  IntakeStage2.spinFor(-40, degrees);
  chassis.drive_distance(10);

  /*chassis.turn_timeout = 500;
  chassis.turn_to_angle(-12);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(24);//was 27
  //wait(0.75, sec);
  //chassis.turn_timeout = 500;
  chassis.turn_to_angle(-90);//was 93
  chassis.drive_distance(14);
  wait(0.5, sec);
  chassis.drive_distance(16);//was 12
  wait(0.5, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-180);//was turn
  //wait(0.35, sec);
  chassis.drive_distance(25);
  //wait(0.4, sec);
  chassis.drive_distance(-2);//hash?
  chassis.drive_distance(22);
  //wait(0.4, sec);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  wait(0.6, sec);
  chassis.turn_to_angle(-60);//was 55
  chassis.drive_distance(15);//was 11
  wait(0.5, sec);
  chassis.drive_distance(-2);//hash?
  chassis.turn_to_angle(28);
  chassis.drive_distance(3);
  wait(0.65, sec);
  chassis.drive_distance(-17);
  mogo = false;
  IntakeStage1.spinFor(-40, degrees);
  IntakeStage2.spinFor(-40, degrees);
  chassis.drive_distance(15);*/
  /*chassis.turn_timeout = 700;
  chassis.turn_to_angle(0);
  IntakeStage1.spin(forward);
  chassis.drive_distance(28);
  wait(0.75, sec);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(-98);
  chassis.drive_distance(24);
  wait(0.35, sec);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(180);
  wait(0.35, sec);
  chassis.drive_distance(30);
  wait(0.4, sec);
  chassis.drive_distance(10);
  wait(0.4, sec);
  chassis.drive_distance(-3);
  IntakeStage1.stop();
  chassis.turn_to_angle(-55);
  IntakeStage1.spin(forward);
  chassis.drive_distance(10);
  //wait(0.5, sec);
  chassis.turn_to_angle(30);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-13);
  wallAligner = false;
  chassis.drive_distance(14);*/ //Original Code

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.turn_to_angle(180);
  chassis.drive_distance(30);
  chassis.drive_distance(30);
  chassis.drive_distance(25);
  chassis.turn_to_angle(45);
  chassis.drive_distance(-36);
  chassis.drive_distance(-36);
  //wait(0.75, sec);
  chassis.left_swing_to_angle(-85);
  //wait(0.1, sec);
  //
  //
  //
  chassis.drive_distance(-32);
  chassis.drive_distance(-28);

  chassis.turn_to_angle(-65);
  chassis.drive_distance(30);
  chassis.drive_distance(25);
  chassis.right_swing_to_angle(90);
  chassis.drive_distance(-30);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(80);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);

  /*
  //wait(0.15, sec);
  //chassis.drive_distance(-3);
  chassis.swing_timeout = 700;
  chassis.right_swing_to_angle(90);
  
  //
  chassis.drive_distance(-15);
  chassis.drive_distance(-5);
  wait(0.1, sec);
  chassis.drive_distance(-6);
  mogo = true;
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  //wait(0.5, sec);
  chassis.turn_to_angle(-120);
  //chassis.drive_distance(-25);
  //chassis.swing_timeout = 500;
  chassis.drive_distance(30);
  chassis.drive_distance(30);
  chassis.turn_to_angle(35);
  chassis.drive_distance(30);
  chassis.drive_distance(10);
  wait(0.25, sec);
  chassis.drive_distance(-12);
  chassis.turn_to_angle(180);
  chassis.drive_distance(30);
  chassis.drive_distance(30);
  //doinker = true;
  //chassis.turn_to_angle(90);
  chassis.drive_distance(10);
  wait(0.5, sec);
  chassis.swing_timeout = 700;
  chassis.right_swing_to_angle(140);
  mogo = false;
  chassis.drive_distance(-28);
  
  chassis.drive_distance(35);
  chassis.turn_to_angle(-120);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(-92);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);

  chassis.turn_to_angle(-120);
  chassis.drive_distance(30);
  chassis.turn_to_angle(120);

  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  //doinker = false;
  //mogo = false;*/
  /*chassis.drive_distance(30);
  chassis.drive_distance(30);
  chassis.drive_distance(20);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-93);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-105);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-105);
  chassis.drive_distance(-30);
  chassis.drive_distance(20);*/


}

  /* //ORIGINAL
  chassis.drive_timeout = 400;
  chassis.drive_distance(-5);
  IntakeStage1.spin(forward);
  wait(0.5, sec);
  IntakeStage1.stop();
  chassis.drive_distance(10);
  chassis.drive_distance(8);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-15.5);//was -15.5
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(-90);
  chassis.drive_timeout = 800;
  chassis.drive_distance(-5.5);
  mogo = true;
  wait(0.35, sec);
  //chassis.drive_distance(-3);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(6);
  IntakeStage1.spin(forward);
  chassis.drive_distance(28);
  wait(0.75, sec);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(98);
  chassis.drive_distance(27);
  wait(0.35, sec);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(180);
  wait(0.35, sec);
  chassis.drive_distance(30);
  wait(0.4, sec);
  chassis.drive_distance(10);
  wait(0.4, sec);
  chassis.drive_distance(-3);
  chassis.turn_to_angle(55);
  chassis.drive_distance(10);
  wait(1, sec);
  chassis.turn_to_angle(-30);
  wait(1, sec);
  chassis.drive_distance(-10);
  mogo = false;
  chassis.drive_distance(14);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(13);
  IntakeStage1.spin(forward);
  chassis.drive_distance(24);//was 27
  //wait(0.75, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(90);//was 93
  chassis.drive_distance(14);
  wait(0.5, sec);
  chassis.drive_distance(12);//was 12
  //wait(0.75, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-180);//was turn
  //wait(0.35, sec);
  chassis.drive_distance(25);
  //wait(0.4, sec);
  chassis.drive_distance(-3);//hash?
  chassis.drive_distance(20);
  //wait(0.4, sec);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  wait(0.5, sec);
  chassis.turn_to_angle(55);//was 55
  chassis.drive_distance(13);//was 11
  wait(0.5, sec);
  chassis.drive_distance(-2);//hash?
  chassis.turn_to_angle(-30);
  chassis.drive_distance(3);
  wait(0.4, sec);
  chassis.drive_distance(-20);
  mogo = false;
  IntakeStage1.spinFor(-40, degrees);

  chassis.drive_distance(10);

  chassis.turn_to_angle(90);
  chassis.drive_distance(-15);
  //chassis.turn_to_angle(87);
  chassis.drive_distance(-15);
  //chassis.turn_to_angle(87);
  chassis.drive_distance(-15);
  //chassis.turn_to_angle(87);
  chassis.drive_distance(-11);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-14);
  //chassis.turn_to_angle(90);//was hashed
  chassis.drive_distance(-6);//was -7
  mogo = true;
  wait(0.35, sec);
  //chassis.turn_timeout = 500;
  chassis.turn_to_angle(-12);
  IntakeStage1.spin(forward);
  chassis.drive_distance(24);//was 27
  //wait(0.75, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-90);//was 93
  chassis.drive_distance(14);
  wait(0.5, sec);
  chassis.drive_distance(14);//was 12
  //wait(0.75, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-180);//was turn
  //wait(0.35, sec);
  chassis.drive_distance(25);
  //wait(0.4, sec);
  chassis.drive_distance(-3);//hash?
  chassis.drive_distance(20);
  //wait(0.4, sec);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  wait(0.5, sec);
  chassis.turn_to_angle(-55);//was 55
  chassis.drive_distance(13);//was 11
  wait(0.5, sec);
  chassis.drive_distance(-2);//hash?
  chassis.turn_to_angle(45);
  chassis.drive_distance(3);
  wait(1, sec);
  chassis.drive_distance(-20);
  mogo = false;
  IntakeStage1.spinFor(-40, degrees);
  chassis.drive_distance(16);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(0);
  IntakeStage1.spin(forward);
  chassis.drive_distance(28);
  wait(0.75, sec);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(-98);
  chassis.drive_distance(24);
  wait(0.35, sec);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(180);
  wait(0.35, sec);
  chassis.drive_distance(30);
  wait(0.4, sec);
  chassis.drive_distance(10);
  wait(0.4, sec);
  chassis.drive_distance(-3);
  IntakeStage1.stop();
  chassis.turn_to_angle(-55);
  IntakeStage1.spin(forward);
  chassis.drive_distance(10);
  //wait(0.5, sec);
  chassis.turn_to_angle(30);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-13);
  wallAligner = false;
  chassis.drive_distance(14); //Original Code
  chassis.turn_to_angle(0);
  chassis.drive_distance(30);
  chassis.drive_distance(15);
  chassis.turn_to_angle(48);
  chassis.drive_distance(36);
  chassis.drive_distance(10);
  //wait(0.75, sec);
  chassis.turn_to_angle(-145);
  chassis.drive_distance(5);
  IntakeStage1.stop();
  chassis.drive_distance(-25);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(-11);
  mogo = true;
  IntakeStage1.spin(forward);
  wait(0.5, sec);
  chassis.drive_distance(-17);
  //chassis.drive_distance(-25);
  chassis.swing_timeout = 500;
  chassis.right_swing_to_angle(-85);
  mogo = false;
  chassis.drive_distance(30);
  chassis.drive_distance(30);
  chassis.drive_distance(20);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-93);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-105);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-105);
  chassis.drive_distance(-30);
  chassis.drive_distance(20);


}*/


void pid_test() {
  chassis.drive_kp = 10;
  chassis.drive_ki = 5;
  chassis.drive_kd = 1;

  //chassis.drive_distance(48);
  //chassis.turn_timeout = 500;
  chassis.turn_to_angle(180);
  chassis.drive_distance(48);
  //chassis.turn_to_angle(180);
  
}

void red_left_sigma(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  
  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.drive_timeout = 750;
  chassis.drive_distance(14.25);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(90);
  chassis.drive_distance(4);
  wallStake = true;
  wait(0.75, sec);
  wallStake = false;
  chassis.drive_distance(-6);
  


  chassis.turn_to_angle(50);
  chassis.drive_distance(-22);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-20);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  //chassis.drive_timeout = 250;
  chassis.drive_distance(-6);//was -11
  mogo = true; 
  wait(0.15, sec);
  chassis.turn_to_angle(-141); // was 2
  //wait(0.15, sec);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(20);
  chassis.drive_distance(8);
  wait(0.15, sec);
  //IntakeStage1.spin(forward);
  chassis.drive_distance(-22);
  //wait(0.2, sec);
  //IntakeStage1.spin(forward);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(180);//was 100
  //IntakeStage1.spin(forward);
  chassis.drive_distance(19);
  //IntakeStage1.spin(forward);
  wait(0.15, sec); //was 110
  //IntakeStage1.spin(forward);
  chassis.drive_distance(5);
  //IntakeStage1.spin(forward);
  //wait(0.3, sec);
  //chassis.drive_distance(-25);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(-118);
  //IntakeStage1.spin(forward);
  chassis.drive_distance(18);
  wait(0.15, sec);
  //IntakeStage1.spin(forward);
  chassis.drive_distance(-23);
  wait(0.1, sec);
  //IntakeStage1.spin(forward);
  //chassis.drive_distance(-5);
  chassis.turn_timeout = 400;
  chassis.turn_to_angle(0);//was 140
  //IntakeStage1.spin(forward);
  chassis.drive_timeout = 300;
  chassis.drive_distance(8);
  //IntakeStage1.spin(forward);
  chassis.turn_timeout = 250;
  chassis.turn_to_angle(-35);
  //IntakeStage1.spin(forward);
  chassis.drive_timeout = 750;
  chassis.drive_distance(34);
  //chassis.drive_distance(6);
  wallAligner = true;
}

void red_goal_rush() {
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  
  chassis.drive_kp = 2;
  chassis.drive_kd = 20;
  chassis.drive_ki = 0;

  chassis.drive_timeout = 800;
  chassis.drive_distance(36);
  chassis.turn_timeout = 150;
  chassis.turn_to_angle(-10);
  chassis.drive_timeout = 500;
  chassis.drive_distance(12);
  doinker = true;
  chassis.drive_distance(-14);
  doinker = false;
  chassis.swing_timeout = 500;
  chassis.right_swing_to_angle(5);
  chassis.drive_distance(-14);
  IntakeStage2.spin(fwd);
  
  chassis.drive_timeout = 5000;
  chassis.turn_timeout = 500;
  
  chassis.turn_to_angle(-40);
  chassis.drive_distance(12);
  chassis.drive_distance(-5);
  chassis.right_swing_to_angle(140);
  chassis.drive_distance(-25);
  //chassis.drive_distance(-10);
  wait(0.1, sec);
  chassis.drive_distance(-12);
  wait(0.05, sec);
  chassis.drive_distance(-4);
  mogo = true;
  wait(0.15, sec);
  IntakeStage1.spin(fwd);
  IntakeStage2.spin(forward);
  wait(0.5, sec);
  IntakeStage1.stop();
  IntakeStage2.stop();
  chassis.drive_distance(30);
  chassis.turn_to_angle(45);
  mogo = false;
  chassis.drive_distance(8);
  chassis.turn_to_angle(175);
  chassis.drive_distance(-20);
  wait(0.1, sec);
  chassis.drive_distance(-6);
  chassis.drive_distance(-8);
  mogo = true;
  chassis.turn_to_angle(165);
  IntakeStage1.spin(fwd);
  IntakeStage2.spin(forward);
  chassis.drive_distance(40);
  doinker = true;

}

void prog_skills_odom(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  /*chassis.drive_kp = 10;
  chassis.drive_ki = 5;
  chassis.drive_kd = 1;*/

  //ORIGINAL
  /*chassis.drive_timeout = 400;
  chassis.drive_distance(-5);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  wait(0.5, sec);
  IntakeStage1.stop();
  IntakeStage2.stop();
  chassis.drive_distance(10);
  chassis.drive_distance(8);*/

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);

  wallStake = true;
  wait(0.5, sec);
  wallStake = false;
  chassis.drive_distance(-20);
  chassis.drive_distance(20);
  chassis.drive_distance(-10.5);
  chassis.turn_to_angle(90);

  chassis.drive_to_point(-3.64, -0.435);
  chassis.drive_timeout = 800;
  chassis.drive_distance(-7);
  chassis.drive_distance(-6);
  mogo = true;
  wait(0.35, sec);

  chassis.turn_timeout = 500;
  chassis.turn_to_point(-7.2, -25.716);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_to_point(-7.2, -25.716);
  chassis.drive_distance(4);
  chassis.turn_timeout = 500;
  wait(0.2, sec);
  chassis.turn_to_point(-34.086, -40.947);//was 93
  wait(0.2, sec);
  chassis.drive_to_point(-34.086, -40.947);
  //wait(0.5, sec);
  chassis.turn_to_point(-40.212, -55.864);
  chassis.drive_to_point(-40.212, -55.864);  
  wait(0.2, sec);
  chassis.drive_to_point(-34.086, -40.947);
  chassis.turn_to_point(-46.798, -17.592);
  chassis.drive_to_point(-46.798, -17.592);
  wait(0.2, sec);
  chassis.turn_to_point(-47.3, -0.739);
  chassis.drive_to_point(-47.3, -0.739);
  chassis.drive_distance(-3);
  chassis.turn_to_point(-43.12, -14.7);
  chassis.drive_to_point(-43.12, -14.7);
  chassis.drive_distance(-5);
  chassis.turn_to_point(-46.798, -17.592);
  chassis.drive_to_point(-43.415, 7.412);


  chassis.turn_to_angle(-10);
  chassis.turn_timeout = 500;//was turn
  chassis.drive_distance(30);
  chassis.turn_to_angle(-5);
  wait(0.35, sec);
  chassis.drive_distance(15);
  //wait(0.4, sec);
  chassis.drive_distance(-3);//hash?
  chassis.drive_distance(7);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  //wait(0.6, sec);
  chassis.turn_to_angle(-125);//was 55
  //wait(0.2, sec);
  chassis.drive_distance(15);//was 11
  //wait(0.25, sec);
  chassis.drive_distance(-3);//hash?
  //chassis.turn_to_angle(140);
  chassis.turn_to_angle(135);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-11);
  mogo = false;
  IntakeStage2.spinFor(-40, degrees);
  chassis.drive_distance(9);

  chassis.turn_to_angle(-90);
  chassis.drive_distance(-35);
  chassis.drive_distance(-30);
  chassis.drive_distance(-15);
  wait(0.25, sec);
  chassis.drive_distance(-7);
  chassis.drive_distance(-6);

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;
  
  mogo = true;
  wait(0.35, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(173);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(24);
  chassis.turn_timeout = 500;
  wait(0.2, sec);
  chassis.turn_to_angle(90);//was 93
  wait(0.2, sec);
  chassis.drive_distance(14);
  //wait(0.5, sec);
  chassis.drive_distance(12);//was 12
  chassis.turn_to_angle(160);
  chassis.drive_distance(20);
  //wait(0.2, sec);
  chassis.left_swing_to_angle(10);
  chassis.turn_to_angle(10);
  chassis.turn_timeout = 500;//was turn
  chassis.drive_distance(30);
  chassis.turn_to_angle(5);
  wait(0.35, sec);
  chassis.drive_distance(15);
  //wait(0.4, sec);
  chassis.drive_distance(-3);//hash?
  chassis.drive_distance(7);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  //wait(0.6, sec);
  chassis.turn_to_angle(125);//was 55
  //wait(0.2, sec);
  chassis.drive_distance(15);//was 11
  //wait(0.25, sec);
  chassis.drive_distance(-3);//hash?
  //chassis.turn_to_angle(140);
  chassis.turn_to_angle(-135);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-11);
  mogo = false;
  IntakeStage2.spinFor(-40, degrees);
  chassis.drive_distance(10);

  /*chassis.turn_timeout = 500;
  chassis.turn_to_angle(-12);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(24);//was 27
  //wait(0.75, sec);
  //chassis.turn_timeout = 500;
  chassis.turn_to_angle(-90);//was 93
  chassis.drive_distance(14);
  wait(0.5, sec);
  chassis.drive_distance(16);//was 12
  wait(0.5, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-180);//was turn
  //wait(0.35, sec);
  chassis.drive_distance(25);
  //wait(0.4, sec);
  chassis.drive_distance(-2);//hash?
  chassis.drive_distance(22);
  //wait(0.4, sec);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  wait(0.6, sec);
  chassis.turn_to_angle(-60);//was 55
  chassis.drive_distance(15);//was 11
  wait(0.5, sec);
  chassis.drive_distance(-2);//hash?
  chassis.turn_to_angle(28);
  chassis.drive_distance(3);
  wait(0.65, sec);
  chassis.drive_distance(-17);
  mogo = false;
  IntakeStage1.spinFor(-40, degrees);
  IntakeStage2.spinFor(-40, degrees);
  chassis.drive_distance(15);*/
  /*chassis.turn_timeout = 700;
  chassis.turn_to_angle(0);
  IntakeStage1.spin(forward);
  chassis.drive_distance(28);
  wait(0.75, sec);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(-98);
  chassis.drive_distance(24);
  wait(0.35, sec);
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(180);
  wait(0.35, sec);
  chassis.drive_distance(30);
  wait(0.4, sec);
  chassis.drive_distance(10);
  wait(0.4, sec);
  chassis.drive_distance(-3);
  IntakeStage1.stop();
  chassis.turn_to_angle(-55);
  IntakeStage1.spin(forward);
  chassis.drive_distance(10);
  //wait(0.5, sec);
  chassis.turn_to_angle(30);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-13);
  wallAligner = false;
  chassis.drive_distance(14);*/ //Original Code

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.turn_to_angle(0);
  chassis.drive_distance(30);
  chassis.drive_distance(24);
  IntakeStage1.spin(forward);
  chassis.turn_to_angle(-136);
  chassis.drive_distance(36);
  chassis.drive_distance(14);
  //wait(0.75, sec);
  chassis.turn_to_angle(20);
  chassis.drive_distance(7);
  //wait(0.1, sec);
  //
  chassis.drive_kp = 0.25;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.25;
  //
  //
  chassis.drive_distance(-32);
  chassis.drive_distance(-22);
  //wait(0.15, sec);
  //chassis.drive_distance(-3);
  chassis.swing_timeout = 700;
  chassis.right_swing_to_angle(90);
  
  //
  chassis.drive_distance(-15);
  chassis.drive_distance(-5);
  wait(0.1, sec);
  chassis.drive_distance(-6);
  mogo = true;
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  //wait(0.5, sec);
  chassis.turn_to_angle(-120);
  //chassis.drive_distance(-25);
  //chassis.swing_timeout = 500;
  chassis.drive_distance(30);
  chassis.drive_distance(30);
  chassis.turn_to_angle(35);
  chassis.drive_distance(30);
  chassis.drive_distance(10);
  wait(0.25, sec);
  chassis.drive_distance(-12);
  chassis.turn_to_angle(180);
  chassis.drive_distance(30);
  chassis.drive_distance(30);
  //doinker = true;
  //chassis.turn_to_angle(90);
  chassis.drive_distance(10);
  wait(0.5, sec);
  chassis.swing_timeout = 700;
  chassis.right_swing_to_angle(140);
  mogo = false;
  chassis.drive_distance(-28);
  
  chassis.drive_distance(35);
  chassis.turn_to_angle(-120);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(-92);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);

  chassis.turn_to_angle(-120);
  chassis.drive_distance(30);
  chassis.turn_to_angle(120);

  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  chassis.drive_distance(-30);
  //doinker = false;
  //mogo = false;
  /*chassis.drive_distance(30);
  chassis.drive_distance(30);
  chassis.drive_distance(20);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-93);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-105);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-105);
  chassis.drive_distance(-30);
  chassis.drive_distance(20);*/


}