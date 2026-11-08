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

void red_right(){
  IntakeMain.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  basket.setVelocity(100, pct);

  hood = true;

  IntakeMain.spin(fwd);
  chassis.drive_distance(5);
  chassis.turn_to_angle(-15);

  chassis.drive_kp = 1.0;

  chassis.drive_distance(28);
  chassis.turn_to_angle(90);
  
  matchload = true;
  IntakeMain.spin(fwd);
  IntakeStage2.spin(fwd);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(13.4);
  //chassis.drive_distance(1);
  wait(0.5, sec);
  //chassis.drive_distance(3);
  chassis.drive_distance(-11);
  matchload = false;
  //chassis.drive_distance(7);
  //wait(0.05, sec);
  //chassis.drive_distance(-9);
  chassis.turn_to_angle(-85);
  //chassis.drive_timeout = 1000;
  chassis.drive_distance(16);
  chassis.turn_to_angle(-90);
  //chassis.drive_timeout = 0500;
  chassis.drive_distance(4.2);
  //chassis.drive_distance(-3);
  hood = false;
  wait(0.15, sec);
  basket.spin(fwd);
  wait(1.85, sec);
  //chassis.drive_distance(-9);
  //descore = false;
  //chassis.drive_distance(10);

  chassis.drive_distance(-20);
  //descore = true;
  chassis.turn_to_angle(-135);
  basket.stop();
  IntakeMain.spin(reverse);
  
  chassis.drive_kp = 1.35;
  
  chassis.drive_distance(60);
  //IntakeMain.stop();
  //chassis.drive_distance(20);
  IntakeMain.spin(reverse);
  chassis.drive_timeout = 750;
  chassis.drive_distance(8);
  chassis.drive_timeout = 250;
  chassis.drive_distance(-10);

}

void red_left(){
  IntakeMain.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  basket.setVelocity(100, pct);

  hood = true;

  IntakeMain.spin(fwd);
  chassis.drive_distance(5);
  chassis.turn_to_angle(15);

  chassis.drive_kp = 1.0;

  chassis.drive_distance(28);
  chassis.turn_to_angle(-90);
  
  matchload = true;
  //IntakeMain.spin(fwd);
  IntakeStage2.spin(fwd);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(13.4);//matchload drive into
  //chassis.drive_distance(1);
  wait(0.5, sec);
  //chassis.drive_distance(3);
  chassis.drive_distance(-11);
  matchload = false;
  //chassis.drive_distance(7);
  //wait(0.05, sec);
  //chassis.drive_distance(-9);
  chassis.turn_to_angle(85);
  //chassis.drive_timeout = 1000;
  chassis.drive_distance(16);
  chassis.turn_to_angle(90);
  //chassis.drive_timeout = 0500;
  chassis.drive_distance(4.2);//final drive towards long
  //chassis.drive_distance(-3);
  hood = false;
  basket.spin(fwd);
  wait(2, sec);
  //chassis.drive_distance(-9);
  //descore = false;
  //chassis.drive_distance(10);

  chassis.drive_distance(-24);
  //descore = true;
  chassis.turn_to_angle(135);
  basket.stop();
  
  chassis.drive_kp = 1.3;
  IntakeMain.spin(fwd);
  IntakeStage2.spin(reverse);

  chassis.drive_distance(30);

  chassis.drive_distance(28);


}