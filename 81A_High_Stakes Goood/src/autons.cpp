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


void blue_right(){
  Intake.setVelocity(100, pct);
  
  chassis.drive_timeout = 750;
  chassis.drive_distance(-14.5);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(-90);
  chassis.drive_timeout = 700;
  chassis.drive_distance(-7);
  Intake.spin(forward);
  wait(0.75, sec);
  Intake.stop();
  chassis.drive_distance(9);
  Intake.setVelocity(80, percent);
  //chassis.turn_timeout = 500;
  //chassis.turn_to_angle(0);
  //chassis.drive_timeout = 500;
  //chassis.drive_distance(-2);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-4);
  chassis.turn_to_angle(127);//was-128
  chassis.drive_distance(-16);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-10);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  chassis.drive_distance(-5);//was -11
  mogo = true; 
  wait(0.25, sec);
  //chassis.drive_distance(5);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-8); // was 2
  Intake.spin(forward);
  chassis.drive_distance(21);
  chassis.drive_distance(12);
  //wait(0.2, sec);
  chassis.turn_to_angle(-83);//was 100
  chassis.drive_distance(15); 
  chassis.drive_distance(-15);
  chassis.turn_to_angle(-120);//was 110
  chassis.drive_distance(19);
  //wait(0.3, sec);
  chassis.drive_distance(-30);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-150);//was 140
  chassis.drive_distance(30);
  chassis.drive_distance(20);
  wallAligner = true;
}

void blue_left(){
  Intake.setVelocity(80, pct);
  
  chassis.drive_distance(-18);
  chassis.turn_to_angle(37);
  chassis.drive_distance(-15);
  wait(0.5, seconds);
  chassis.drive_timeout = 800;
  chassis.drive_distance(-8);
  mogo = true;
  Intake.spin(forward);
  wait(0.5, seconds);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(12);
  chassis.drive_timeout = 750;
  chassis.drive_distance(8);
  chassis.turn_to_angle(90);
  chassis.drive_distance(20);
  chassis.turn_to_angle(135);
  chassis.drive_distance(10);
  wallAligner = true;
}