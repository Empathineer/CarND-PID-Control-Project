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
  this->Kp = 0.135;
  this->Kd = 1.28;
  this->Ki = 1.75e-5; //0.00001

  // prepare controller for its first step
  init_step = true;

  // set initial errors to zero
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  
  // Counters.
  counter = 0;
  error_total = 0.0;
  min_error = std::numeric_limits<double>::max();
  max_error = std::numeric_limits<double>::min();  
}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
  p_error = d_error = i_error = 0.0;
}

double PID::AverageError() {
  return error_total / counter;
}

double PID::MinError() {
  return min_error;
}

double PID::MaxError() {
  return max_error;
}

void PID::UpdateError(double cte) {

  // Placeholder for time step
  double dt = 1.0;

  // Proportional error
  p_error = cte;

  // Intergral error
  i_error += cte * dt;

  // Derivative error
  d_error = cte - prev_cte;
  
  prev_cte = cte;

  error_total += cte;
  counter++;

  if ( cte > max_error ) {
    max_error = cte;
  }
  if ( cte < min_error ) {
    min_error = cte;
  }
  

}

double PID::TotalError() {
  return p_error * Kp + i_error * Ki + d_error * Kd;
}


