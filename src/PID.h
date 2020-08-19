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
  * Error trackers 
  */
  long counter;
  double error_total;
  double min_error;
  double max_error;
  
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
 
  /*
  * Overload init function to pass coeff vals directly from main()
  */
  void Init(double Kp, double Ki, double Kd);
  
  double AverageError(); 

  double MinError();

  double MaxError(); 
  
  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Output total error.
  */
  double TotalError();
  /*
  * Update steering value.
  */
};

#endif /* PID_H */