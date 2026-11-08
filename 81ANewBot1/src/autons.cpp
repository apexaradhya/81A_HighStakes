#include "vex.h"

void redSortOut(){
  if(ColorSorter.hue() <= 35){ // Color Sorter code to sort out red
    wait(0.3, sec);
    IntakeStage2.stop();
    wait(0.05, sec);
  }
}

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

/*void prog_skills(){
  
  chassis.drive_kp = 2;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;

  chassis.drive_to_point(0, 0);
  chassis.drive_to_point(10.876, -21.113);
  chassis.drive_to_point(35.189, -22.819);
  chassis.drive_to_point(109.724, -60.354);
  chassis.drive_to_point(74.962, -47.131);
  chassis.drive_to_point(-5.865, -46.065);
  chassis.drive_to_point(0.107, -57.581);
  chassis.drive_to_point(14.822, -58.648);
  chassis.drive_to_point(58.754, -47.345);
  chassis.drive_to_point(58.328, -62.273);
  chassis.drive_to_point(105.672, -47.558);
  chassis.drive_to_point(100.767, -30.284);
  chassis.drive_to_point(119.961, -57.368);
  chassis.drive_to_point(105.672, -29.644);
  chassis.drive_to_point(106.099, -1.919);
  chassis.drive_to_point(98.208, 7.891);
  chassis.drive_to_point(121.027, 0.213);
  chassis.drive_to_point(90.317, -30.71);
  chassis.drive_to_point(11.196, 46.705);
  chassis.drive_to_point(11.623, 61.847);
  chassis.drive_to_point(0.746, 47.771);
  chassis.drive_to_point(-1.173, 59.714);
  chassis.drive_to_point(20.58, 29.217);
  chassis.drive_to_point(10.77, 23.672);
  chassis.drive_to_point(39.774, 50.33);
  chassis.drive_to_point(58.328, 46.918);
  chassis.drive_to_point(58.541, 61.847);
  chassis.drive_to_point(82.64, 47.771);
  chassis.drive_to_point(82, 23.672);
  chassis.drive_to_point(118.255, 46.492);
  chassis.drive_to_point(105.886, 48.198);
  chassis.drive_to_point(105.672, 60.78);
  chassis.drive_to_point(116.336, 59.714);
}*/

void blue_goal_safe() {
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);

  chassis.drive_kp = 2;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;
  
  chassis.drive_distance(-8);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-4);
  mogo = true;
  chassis.turn_to_angle(95);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(8);
  wait(1, sec);
  chassis.swing_timeout = 800;
  chassis.left_swing_to_angle(-160);
  chassis.drive_distance(-10);
  mogo = false;
  chassis.drive_distance(8);
  chassis.turn_to_angle(0);
  wait(0.5, sec);
  chassis.drive_distance(-3);
}

void red_goal_safe() {
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);

  chassis.drive_kp = 2;
  chassis.drive_kd = 0.1;
  chassis.drive_ki = 0.5;
  
  chassis.drive_distance(-8);
  chassis.turn_to_angle(45);
  chassis.drive_distance(-4);
  mogo = true;
  chassis.turn_to_angle(-95);
  IntakeStage1.spin(forward);
  IntakeStage2.spin(forward);
  chassis.drive_distance(8);
  wait(1, sec);
  chassis.swing_timeout = 800;
  chassis.right_swing_to_angle(160);
  chassis.drive_distance(-10);
  mogo = false;
  chassis.drive_distance(8);
  chassis.turn_to_angle(0);
  wait(0.5, sec);
  chassis.drive_distance(-3);
}

void prog_skills(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  Lift.setVelocity(100, pct);
  Lift.setStopping(hold);

  chassis.drive_kp = 6;
  chassis.drive_kd = 10;
  //chassis.drive_ki = 0.01;

  

  //IntakeStage1.spin(fwd);//alliance stake
  IntakeStage1.spin(fwd, 5.5, volt);
  IntakeStage2.spin(fwd, 11, volt);
  wait(0.5, sec);
  chassis.drive_distance(4.5);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-4.5);
  chassis.drive_distance(-2);
  mogo = true;//1st mogo
  chassis.drive_distance(-0.5);
  IntakeStage1.spin(fwd);
  IntakeStage2.spin(fwd);
  
  chassis.turn_to_angle(15);//1st ring
  chassis.drive_distance(8);

  chassis.turn_to_angle(88);//2nd ring
  chassis.drive_distance(8);
  chassis.drive_distance(-2);
  
  chassis.turn_to_angle(32);//3rd ring
  chassis.drive_distance(8);
  
  chassis.drive_distance(-9);//4th and 5th ring
  chassis.drive_distance(2);
  chassis.turn_to_angle(180);
  chassis.drive_distance(8);
  wait(0.15, sec);
  chassis.drive_distance(7);

  chassis.drive_distance(-7);//6th ring
  chassis.turn_to_angle(90);
  chassis.drive_distance(5);
  chassis.drive_distance(-5);
  wait(0.2, sec);

  chassis.turn_to_angle(-35);//1st mogo in corner
  chassis.drive_distance(-7);
  mogo = false;

  chassis.drive_distance(4.75);//2nd mogo traversal
  chassis.turn_to_angle(90);
  chassis.drive_distance(-17);
  chassis.drive_distance(-4);
  chassis.drive_distance(-3.5);
  mogo = true;

  chassis.turn_to_angle(-13);//1st ring (2)
  chassis.drive_distance(9);
  wait(0.4, sec);

  chassis.turn_to_angle(-92);//2nd ring (2)
  chassis.drive_distance(8);
  chassis.drive_distance(-2);
  
  chassis.turn_to_angle(-32);//3rd ring (2)
  chassis.drive_distance(9);
  
  chassis.drive_distance(-11);//4th and 5th ring (2)
  chassis.drive_distance(4);
  chassis.turn_to_angle(180);
  chassis.drive_distance(9.5);
  wait(0.15, sec);
  chassis.drive_distance(6);

  chassis.drive_distance(-5);//6th ring (2)
  chassis.turn_to_angle(-90);
  chassis.drive_distance(6);
  chassis.drive_distance(-5);
  wait(0.2, sec);

  chassis.turn_to_angle(40);//2nd mogo in corner
  chassis.drive_distance(-7);
  mogo = false;

  chassis.drive_distance(6); // Wall Stake Ring Getting
  chassis.turn_to_angle(0);
  IntakeStage2.stop();
  chassis.drive_distance(22);
  IntakeStage2.setTimeout(1, sec);
  IntakeStage2.spinFor(450, degrees);
  chassis.turn_to_angle(90);
  chassis.drive_distance(9);
  chassis.turn_to_angle(-140);
  chassis.drive_distance(-9);
  mogo = true;
  chassis.swing_timeout = 800;
  chassis.right_swing_to_angle(-100);
  
  IntakeStage2.spin(fwd);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(-137);
  mogo = false;
  IntakeStage2.stop();
  chassis.drive_distance(-3);

  chassis.drive_distance(10);
  chassis.turn_to_angle(-55);
  chassis.drive_distance(10);
  chassis.right_swing_to_angle(-87);
  chassis.drive_distance(20);
  chassis.drive_distance(7);
  chassis.drive_distance(-3);
  chassis.drive_distance(5);


} 

void ring_side_blue(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  Lift.setVelocity(100, pct);
  Lift.setStopping(hold);

  chassis.drive_kp = 4;
  chassis.drive_kd = 10;
  chassis.drive_ki = 0.01;


  Lift.setTimeout(1/2, sec);
  Lift.spinFor(400, degrees);
  chassis.drive_distance(7);
  chassis.drive_distance(-3.5);
  Lift.spin(reverse);
  chassis.swing_timeout = 550;
  chassis.left_swing_to_angle(-70);
  chassis.drive_distance(-8);
  chassis.drive_distance(-6);
  mogo = true;
  Lift.stop();
  chassis.drive_distance(2);
  IntakeStage1.spin(fwd);
  IntakeStage2.spin(fwd);
  
  chassis.turn_to_angle(180);
  //redSortOut(); // Sorting Out Red
  chassis.drive_distance(9.5);
  //redSortOut(); // Sorting Out Red
  chassis.drive_distance(-5);
  //redSortOut(); // Sorting Out Red

  chassis.turn_timeout = 400;
  chassis.turn_to_angle(108);
  //redSortOut(); // Sorting Out Red
  chassis.drive_distance(5);
  //redSortOut(); // Sorting Out Red
  chassis.drive_distance(-6);
  //redSortOut(); // Sorting Out Red
  //wait(0.15, sec);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(180);
  //redSortOut(); // Sorting Out Red
  chassis.drive_timeout = 300;
  chassis.drive_distance(3);
  //redSortOut(); // Sorting Out Red
  chassis.drive_timeout = 5000;
  chassis.turn_timeout = 500;
  //redSortOut(); // Sorting Out Red
  chassis.turn_to_angle(110);
  //redSortOut(); // Sorting Out Red
  chassis.drive_distance(6);
  //redSortOut(); // Sorting Out Red
  chassis.drive_distance(-11);
  //redSortOut(); // Sorting Out Red
  chassis.turn_timeout = 300;
  //redSortOut(); // Sorting Out Red
  chassis.turn_to_angle(-135);
  //redSortOut(); // Sorting Out Red
  chassis.drive_distance(3);
  //redSortOut(); // Sorting Out Red
  chassis.drive_distance(-17);

  /*chassis.turn_to_angle(-135);
  chassis.drive_timeout = 1350;
  chassis.drive_distance(25);
  //chassis.turn_to_angle(180);
  //wait(0.05, sec);
  //chassis.turn_to_angle(-135);
  chassis.drive_distance(-3);
  chassis.drive_distance(5);
  chassis.turn_to_angle(-130);
  chassis.drive_distance(-30);
  chassis.drive_distance(3);
  chassis.drive_distance(-8);*/
}

void ring_side_red(){
  IntakeStage1.setVelocity(100, pct);
  IntakeStage2.setVelocity(100, pct);
  Lift.setVelocity(100, pct);
  Lift.setStopping(hold);

  chassis.drive_kp = 4;
  chassis.drive_kd = 10;
  chassis.drive_ki = 0.01;

  wait(1.5, sec);

  Lift.setTimeout(1/2, sec);
  Lift.spinFor(400, degrees);
  chassis.drive_distance(7);
  chassis.drive_distance(-3);
  Lift.spin(reverse);
  chassis.swing_timeout = 550;
  chassis.right_swing_to_angle(60);
  chassis.drive_distance(-8);
  chassis.drive_distance(-7);
  mogo = true;
  Lift.stop();
  chassis.drive_distance(2);
  IntakeStage1.spin(fwd);
  IntakeStage2.spin(fwd);
  chassis.turn_to_angle(180);
  chassis.drive_distance(9.5);
  chassis.drive_distance(-5);

  chassis.turn_timeout = 400;
  chassis.turn_to_angle(-108);
  chassis.drive_distance(5);
  chassis.drive_distance(-6);
  //wait(0.15, sec);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(180);
  chassis.drive_timeout = 300;
  chassis.drive_distance(3);
  chassis.drive_timeout = 5000;
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(-110);
  chassis.drive_distance(6);
  chassis.drive_distance(-11);
  chassis.turn_timeout = 300;
  chassis.turn_to_angle(135);
  chassis.drive_distance(3);
  chassis.drive_distance(-15);
}