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
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  
  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.drive_timeout = 750;
  chassis.drive_distance(-15.25);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(-90);
  chassis.drive_timeout = 700;
  chassis.drive_distance(-9);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  wait(0.75, sec);
  //Intake.spin(reverse);
  //wait(0.25, sec);
  chassis.drive_distance(9);
  IntakeStage1.stop();
  IntakeStage2.stop();
  //Intake.setVelocity(80, percent);
  //chassis.turn_timeout = 500;
  //chassis.turn_to_angle(0);
  //chassis.drive_timeout = 500;
  //chassis.drive_distance(-2);
  //chassis.turn_timeout = 250;
  chassis.turn_to_angle(180);
  chassis.drive_distance(-4);
  chassis.turn_to_angle(127);//was-128
  chassis.drive_distance(-16);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-16);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  //chassis.drive_timeout = 250;
  chassis.drive_distance(-4);//was -11
  mogo = true; 
  wait(0.15, sec);
  //chassis.drive_distance(5);
  //chassis.turn_timeout = 500;
  //chassis.turn_timeout = 550;
  chassis.turn_to_angle(-45); // was 2
  wait(0.15, sec);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  //chassis.drive_distance(15);
  //Intake.spin(forward);
  chassis.drive_distance(35);
  wait(0.15, sec);
  //Intake.spin(forward);
  chassis.drive_distance(-22);
  //wait(0.2, sec);
  //Intake.spin(forward);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(0);//was 100
  //Intake.spin(forward);
  chassis.drive_distance(19);
  //Intake.spin(forward);
  wait(0.15, sec); //was 110
  //Intake.spin(forward);
  chassis.drive_distance(5);
  //Intake.spin(forward);
  //wait(0.3, sec);
  //chassis.drive_distance(-25);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(-60);
  //Intake.spin(forward);
  chassis.drive_distance(18);
  //Intake.spin(forward);
  chassis.drive_distance(-19);
  //Intake.spin(forward);
  //chassis.drive_distance(-5);
  chassis.turn_timeout = 400;
  chassis.turn_to_angle(180);//was 140
  //Intake.spin(forward);
  chassis.drive_timeout = 300;
  chassis.drive_distance(8);
  //Intake.spin(forward);
  chassis.turn_timeout = 250;
  chassis.turn_to_angle(-145);
  //Intake.spin(forward);
  chassis.drive_timeout = 750;
  chassis.drive_distance(39);
  //chassis.drive_distance(6);
  wallAligner = true;
}



/*void blue_right(){
  Intake.setVelocity(100, pct);
  
  chassis.drive_timeout = 750;
  chassis.drive_distance(-15.5);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(-90);
  chassis.drive_timeout = 700;
  chassis.drive_distance(-9.5);
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
  chassis.drive_distance(-3);
  chassis.turn_to_angle(127);//was-128
  chassis.drive_distance(-16);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-10);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  chassis.drive_distance(-6);//was -11
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
  chassis.drive_distance(15);
  //wait(0.3, sec);
  chassis.drive_distance(-30);
  //chassis.drive_distance(-5);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-140);//was 140
  chassis.drive_distance(30);
  chassis.drive_distance(23);
  wallAligner = true;
}*/


void blue_left(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);

  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.drive_distance(-21.5);
  chassis.turn_to_angle(-37);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(-7);
  wait(0.35, seconds);
  chassis.drive_timeout = 800;
  chassis.drive_distance(-6);
  mogo = true;
  wait(0.5, seconds);
  IntakeStage2.spin(forward);
  IntakeStage1.spin(forward);
  wait(0.75, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(103);
  chassis.drive_distance(15);
  chassis.drive_timeout = 750;
  chassis.drive_distance(9);
  wait(0.5,  sec); // Can be reduced in later programs
  chassis.turn_to_angle(-90);
  chassis.drive_distance(15);
  chassis.turn_to_angle(-135);
  chassis.drive_distance(18);
  wallAligner = true;
}

void blue_right_elims(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  
  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.drive_timeout = 750;
  chassis.drive_distance(14.75);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(-90);
  chassis.drive_distance(4);
  wallStake = true;
  wait(0.75, sec);
  wallStake = false;
  chassis.drive_distance(-6);
  


  chassis.turn_to_angle(-50);
  chassis.drive_distance(-22);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-20);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  //chassis.drive_timeout = 250;
  chassis.drive_distance(-6);//was -11
  mogo = true; 
  wait(0.15, sec);
  chassis.turn_to_angle(141); // was 2
  //wait(0.15, sec);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(20);
  chassis.drive_distance(6);
  wait(0.15, sec);
  //Intake.spin(forward);
  chassis.drive_distance(-22);
  //wait(0.2, sec);
  //Intake.spin(forward);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(180);//was 100
  //Intake.spin(forward);
  chassis.drive_distance(19);
  //Intake.spin(forward);
  wait(0.15, sec); //was 110
  //Intake.spin(forward);
  chassis.drive_distance(5);
  //Intake.spin(forward);
  //wait(0.3, sec);
  //chassis.drive_distance(-25);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(118);
  //Intake.spin(forward);
  chassis.drive_distance(18);
  wait(0.15, sec);
  //Intake.spin(forward);
  chassis.drive_distance(-23);
  wait(0.1, sec);
  //Intake.spin(forward);
  //chassis.drive_distance(-5);
  chassis.turn_timeout = 400;
  chassis.turn_to_angle(0);//was 140
  //Intake.spin(forward);
  chassis.drive_timeout = 300;
  chassis.drive_distance(8);
  //Intake.spin(forward);
  chassis.turn_timeout = 250;
  chassis.turn_to_angle(-35);//was 140
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

  chassis.drive_timeout = 400;
  chassis.drive_distance(-5);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  wait(0.5, sec);
  IntakeStage1.stop();
  IntakeStage2.stop();
  chassis.drive_distance(11);
  chassis.drive_distance(8);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-15);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(-90);
  chassis.drive_timeout = 800;
  chassis.drive_distance(-8);
  mogo = true;
  wait(0.35, sec);
  //chassis.drive_distance(-3);
  
  /*chassis.turn_timeout = 700;
  chassis.turn_to_angle(6);
  Intake.spin(forward);
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
  chassis.drive_distance(14);*/
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(7);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(25);
  //wait(0.75, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(95);
  chassis.drive_distance(14);
  wait(0.5, sec);
  chassis.drive_distance(9);
  //wait(0.75, sec);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-180);
  //wait(0.35, sec);
  chassis.drive_distance(25);
  //wait(0.4, sec);
  chassis.drive_distance(12);
  //wait(0.4, sec);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-3);
  wait(0.5, sec);
  chassis.turn_to_angle(55);
  chassis.drive_distance(10);
  wait(0.5, sec);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-18);
  mogo = false;
  IntakeStage1.spinFor(-40, degrees);
  IntakeStage2.spinFor(-40, degrees);
  chassis.drive_distance(11);

  
  chassis.turn_to_angle(87);
  chassis.drive_distance(-15);
  chassis.turn_to_angle(87);
  chassis.drive_distance(-15);
  chassis.turn_to_angle(87);
  chassis.drive_distance(-15);
  chassis.turn_to_angle(87);
  chassis.drive_distance(-11);
  chassis.turn_to_angle(83);
  chassis.drive_distance(-18);
  chassis.drive_timeout = 800;
  chassis.turn_to_angle(83);
  chassis.drive_distance(-5);
  mogo = true;
  wait(0.35, sec);
  
  chassis.turn_timeout = 700;
  chassis.turn_to_angle(0);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
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
  IntakeStage2.stop();
  chassis.turn_to_angle(-55);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(10);
  //wait(0.5, sec);
  chassis.turn_to_angle(30);
  chassis.drive_distance(3);
  wait(0.5, sec);
  chassis.drive_distance(-13);
  mogo = false;
  chassis.drive_distance(14);

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
  IntakeStage2.stop();
  chassis.drive_distance(-25);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(-11);
  mogo = true;
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
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
  chassis.turn_to_angle(-97);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(-97);
  chassis.drive_distance(-30);

}

void blue_right_odom(){
  IntakeStage1.setVelocity(100, pct);
  
  chassis.drive_timeout = 750;
  chassis.drive_distance(-15.5);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(-90);
  chassis.drive_timeout = 700;
  chassis.drive_distance(-9.5);
  IntakeStage1.spin(forward);
  wait(0.75, sec);
  IntakeStage1.stop();
  chassis.drive_distance(9);
  //chassis.drive_distance(9);
  //Intake.setVelocity(80, percent);
  //chassis.turn_timeout = 500;
  //chassis.turn_to_angle(0);
  //chassis.drive_timeout = 500;
  //chassis.drive_distance(-2);
  //chassis.turn_to_angle(180);
  //chassis.drive_distance(-3);
  //chassis.turn_to_angle(127);//was-128
  chassis.turn_to_angle(130);
  chassis.drive_to_point(-10, 11.175);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-5);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  chassis.drive_distance(-4.5);//was -11
  mogo = true; 
  wait(0.25, sec);
  //chassis.drive_distance(5);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-61); // was 2
  IntakeStage1.spin(forward);
  chassis.drive_to_point(-38.98, 17.50);
  //wait(0.2, sec);
  chassis.turn_to_angle(-83);//was 100
  chassis.drive_distance(15); 
  chassis.drive_distance(-15);
  chassis.turn_to_angle(-120);//was 110
  chassis.drive_distance(15);
  //wait(0.3, sec);
  chassis.drive_distance(-30);
  //chassis.drive_distance(-5);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-140);//was 140
  chassis.drive_distance(30);
  chassis.drive_distance(23);
  wallAligner = true;
}

void OdomTesting() {
  chassis.drive_to_point(0, 24);
  chassis.turn_to_angle(90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(180);
  chassis.drive_distance(24);
  chassis.turn_to_angle(-90);
  chassis.drive_to_point(0, 10);
  chassis.turn_to_angle(0);
}

void blue_right_sigma(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  
  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.drive_timeout = 750;
  chassis.drive_distance(14.75);
  chassis.turn_timeout = 550;
  chassis.turn_to_angle(-90);
  chassis.drive_distance(4);
  wallStake = true;
  wait(0.75, sec);
  wallStake = false;
  chassis.drive_distance(-6);
  


  chassis.turn_to_angle(-50);
  chassis.drive_distance(-22);
  //chassis.turn_to_angle(-127);
  chassis.drive_distance(-20);
  //wait(0.5, sec);
  //chassis.drive_timeout = 800;
  //chassis.drive_timeout = 250;
  chassis.drive_distance(-6);//was -11
  mogo = true; 
  wait(0.15, sec);
  chassis.turn_to_angle(141); // was 2
  //wait(0.15, sec);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(20);
  chassis.drive_distance(6);
  wait(0.15, sec);
  //Intake.spin(forward);
  chassis.drive_distance(-22);
  //wait(0.2, sec);
  //Intake.spin(forward);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(180);//was 100
  //Intake.spin(forward);
  chassis.drive_distance(19);
  //Intake.spin(forward);
  wait(0.15, sec); //was 110
  //Intake.spin(forward);
  chassis.drive_distance(5);
  //Intake.spin(forward);
  //wait(0.3, sec);
  //chassis.drive_distance(-25);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(118);
  //Intake.spin(forward);
  chassis.drive_distance(18);
  wait(0.15, sec);
  //Intake.spin(forward);
  chassis.drive_distance(-23);
  wait(0.1, sec);
  //Intake.spin(forward);
  //chassis.drive_distance(-5);
  chassis.turn_timeout = 400;
  chassis.turn_to_angle(0);//was 140
  //Intake.spin(forward);
  chassis.drive_timeout = 300;
  chassis.drive_distance(8);
  //Intake.spin(forward);
  chassis.turn_timeout = 250;
  chassis.turn_to_angle(35);
  //Intake.spin(forward);
  chassis.drive_timeout = 750;
  chassis.drive_distance(39);
  //chassis.drive_distance(6);
  wallAligner = true;
}