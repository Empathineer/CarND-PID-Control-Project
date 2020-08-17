/*
 * PID.h
 *
 *  Created on: 16 August 2020
 *      Author: Carissa 
 */

#ifndef PID_H
#define PID_H
#include <vector>

class PID {

  // Attribute to store current cross track error
  double prev_cte;

  // Flag on to ensure derivative error is not calculated for initial step
  bool init_step;

public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  
  double Kp; // 
  double Ki; // integral coeff to correct system bias 
  double Kd; // derivative coeff 

  /*
  * State Booleans
  */ 
  bool twiddle;
  
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
//   void Init(double Kp, double Ki, double Kd);
  void Init();

  void Init(double Kp, double Ki, double Kd);
  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Output control command.
  */
  double UpdateSteerVal();
};

#endif /* PID_H */