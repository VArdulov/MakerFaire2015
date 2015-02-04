/*
 * Author: Victor Ardulov, Shaul Fuhrmann
 * Date: February 2, 2015
 * File: MotorControl.h
 * Description:
 * Definitions and prototypes for the ArmController.cpp
 * to be able tosimply operate the arm, without having
 * to become bloated.
 */

 #ifndef MOTORCONTROL_H
 
 #define MOTORCONTROL_H
 /* 
  * MotorId-
  * Type that will allow us to simply identify which
  * motor we want to send data to it.
  */

 enum MotorId
 {
 	BASE = 0,
 	SHOULDER = 1,
 	ELBOW = 2,
 	WRIST = 3,
 	FINGER = 4
 };

 /*
  * moveMotorTo -
  * Takes in a Vector of the palm position and returns
  * the 
  */
 const Vector moveMotorTo(const Vector position);


 #endif