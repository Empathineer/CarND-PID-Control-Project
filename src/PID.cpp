/*
 * PID.cpp
 *
 *  Created on: 16 August 2020
 *      Author: Carissa 
 */

#include "PID.h"
#include <limits>
#include <cmath>
#include<iostream>
#include "PID.h"


using namespace std;
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */


using namespace std;


PID::PID() {}

PID::~PID() {}

// void PID::Init(double Kp, double Ki, double Kd) {
void PID::Init() {

  // set PID coefficients
  
  this->Kp = 0.2;
  this->Ki = 1e-5;
  this->Kd = 1.0;

  // prepare controller for its first step
  init_step = true;

  // set initial errors to zero
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  // initialize twiddle state 
  twiddle = false;
  
//   //steer value updated following every error update
//   steer_val = 0.0;
}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
  p_error = d_error = i_error = 0.0;
}

void PID::UpdateError(double cte) {

  // Placeholder for time step
  double dt = 1.0;

  // Proportional error
  p_error = cte;

  // Intergral error
  i_error += cte * dt;

  // Derivative error
  // during first step there is not enough available information to
  // calculate a precise derivative
  if (init_step) {
    init_step = false;
  } else {
    d_error = (cte - prev_cte) / dt;
  }

  // Update previous cte
  prev_cte = cte;

}

double PID::UpdateSteerVal() {
  return - Kp * p_error - Ki * i_error - Kd * d_error;
}

// void PID::ControlDrift() {
//   return;
// }