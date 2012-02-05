/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A R   P R O B L E M   C L A S S                                                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <string>
#include <sstream>
#include <iostream>     
#include <cstdlib>     
#include <fstream>     
#include <cmath>     

// Flood includes

#include "CarProblem.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"     

namespace Flood
{

// GENERAL CONSTRUCTOR

CarProblem::CarProblem(MultilayerPerceptron* new_multilayer_perceptron) 
: ObjectiveFunctional(new_multilayer_perceptron)
{
   // Car parameters

   maximum_acceleration = 1.0;
   maximum_deceleration = 1.0;

   // Initial conditions

   initial_position = 0.0;
   initial_velocity = 0.0;

   // Goal values

   final_position_goal = 1.0;
   final_velocity_goal = 0.0;

   // Weight factors

   final_position_error_weight = 1.0;
   final_velocity_error_weight = 1.0;

   final_time_weight = 1.0e-5;

   // Multilayer perceptron stuff

   multilayer_perceptron_pointer->set_input_variable_name(0, "time");

   multilayer_perceptron_pointer->set_output_variable_name(0, "throttle_acceleration");
   multilayer_perceptron_pointer->set_output_variable_name(1, "bracking_deceleration");
 
   multilayer_perceptron_pointer->set_output_variable_lower_bound(0, 0.0);
   multilayer_perceptron_pointer->set_output_variable_upper_bound(0, maximum_acceleration);

   multilayer_perceptron_pointer->set_output_variable_lower_bound(1, -maximum_deceleration);
   multilayer_perceptron_pointer->set_output_variable_upper_bound(1, 0.0);

   multilayer_perceptron_pointer->set_independent_parameter_name(0, "final_time");   
   multilayer_perceptron_pointer->set_independent_parameter_lower_bound(0, 0.0);

   // Integration stuff

   double tolerance = 1.0e-9;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DEFAULT CONSTRUCTOR

CarProblem::CarProblem(void): ObjectiveFunctional()
{
   // Car parameters

   maximum_acceleration = 1.0;
   maximum_deceleration = 1.0;

   // Initial conditions

   initial_position = 0.0;
   initial_velocity = 0.0;

   // Goal values

   final_position_goal = 1.0;
   final_velocity_goal = 0.0;

   // Weight factors

   final_position_error_weight = 1.0;
   final_velocity_error_weight = 1.0;

   final_time_weight = 1.0e-9;

   // Integration stuff

   double tolerance = 1.0e-12;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DESTRUCTOR

CarProblem::~CarProblem(void)
{
}


// METHODS

// double get_initial_position(void) method

double CarProblem::get_initial_position(void)
{
   return(initial_position);
}


// double get_initial_velocity(void) method

double CarProblem::get_initial_velocity(void)
{
   return(initial_velocity);
}


// double get_final_position_goal(void) method

double CarProblem::get_final_position_goal(void)
{
   return(final_position_goal);
}


// double get_final_velocity_goal(void) method

double CarProblem::get_final_velocity_goal(void)
{
   return(final_velocity_goal);
}


// double get_maximum_acceleration(void) method

double CarProblem::get_maximum_acceleration(void)
{
   return(maximum_acceleration);
}


// double get_maximum_deceleration(void) method

double CarProblem::get_maximum_deceleration(void)
{
   return(maximum_deceleration);
}


// double get_final_position_error_weight(void) method

double CarProblem::get_final_position_error_weight(void)
{
   return(final_position_error_weight);
}


// double get_final_velocity_error_weight(void) method

double CarProblem::get_final_velocity_error_weight(void)
{
   return(final_velocity_error_weight);
}


// double get_final_time_weight(void) method

double CarProblem::get_final_time_weight(void)
{
   return(final_time_weight);
}


// void set_initial_position(double) method

void CarProblem::set_initial_position(double new_initial_position)
{
   initial_position = new_initial_position;
}

   
// void set_initial_velocity(double) method

void CarProblem::set_initial_velocity(double new_initial_velocity)
{
   initial_velocity = new_initial_velocity;
}


// void set_final_position_goal(double) method

void CarProblem::set_final_position_goal(double new_final_position_goal)
{
   final_position_goal = new_final_position_goal;
}

   
// void set_final_velocity_goal(double) method

void CarProblem::set_final_velocity_goal(double new_final_velocity_goal)
{
   final_velocity_goal = new_final_velocity_goal;
}


// void set_maximum_acceleration(double) method

void CarProblem::set_maximum_acceleration(double new_maximum_acceleration)
{
   maximum_acceleration = new_maximum_acceleration;
}


// void set_maximum_deceleration(double) method

void CarProblem::set_maximum_deceleration(double new_maximum_deceleration)
{
   maximum_deceleration = new_maximum_deceleration;
}


// void set_final_position_error_weight(double) method

void CarProblem::set_final_position_error_weight(double new_final_position_error_weight)
{
   final_position_error_weight = new_final_position_error_weight;
}


// void set_final_velocity_error_weight(double) method

void CarProblem::set_final_velocity_error_weight(double new_final_velocity_error_weight)
{
   final_velocity_error_weight = new_final_velocity_error_weight;
}


// void set_final_time_weight(double) method

void CarProblem::set_final_time_weight(double new_final_time_weight)
{
   final_time_weight = new_final_time_weight;
}


// double calculate_position_dot(double, double, double) method

double CarProblem::calculate_position_dot(double, double, double velocity)
{
   double position_dot = velocity;

   return(position_dot);
}


// double calculate_velocity_dot(double, double, double) method

double CarProblem::calculate_velocity_dot(double time, double, double)
{
   Vector<double> input(1, time);

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input);

   double acceleration = output[0];
   double deceleration = output[1];

   double velocity_dot = acceleration + deceleration;

   return(velocity_dot);
}


// double calculate_objective(void) method

double CarProblem::calculate_objective(void)
{  
   // Evaluate objective functional

   double initial_time = 0.0;

   double final_time = multilayer_perceptron_pointer->get_independent_parameter(0);

   Vector<double> time;
   Vector<double> position;
   Vector<double> velocity;

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   time, position, velocity, 
   &CarProblem::calculate_position_dot,
   &CarProblem::calculate_velocity_dot,
   initial_time, final_time, initial_position, initial_velocity);

   // Obtain final position and velocity errors

   double final_position_error = fabs(final_position_goal - position[points_number-1]);
   double final_velocity_error = fabs(final_velocity_goal - velocity[points_number-1]);

   // Calculate evaluation

   double objective
   = final_time_weight*final_time
   + final_position_error_weight*pow(final_position_error, 2)
   + final_velocity_error_weight*pow(final_velocity_error, 2);

   return(objective);
}


// std::string get_results_string(void) method

std::string CarProblem::get_results_string(void)
{
   std::stringstream buffer;    int points_number = 1001;

   ordinary_differential_equations.set_points_number(points_number);

   // Solve state equations 

   Vector<double> time(points_number);
   Vector<double> position(points_number);
   Vector<double> velocity(points_number);

   Vector<double> independent_parameters 
    = multilayer_perceptron_pointer->get_independent_parameters();

   double initial_time = 0.0;
   double final_time = independent_parameters[0];
       
   ordinary_differential_equations.calculate_Runge_Kutta_integral(*this,
   time, position, velocity, 
   &CarProblem::calculate_position_dot,
   &CarProblem::calculate_velocity_dot,
   initial_time, final_time, initial_position, initial_velocity);

   double final_position = position[points_number-1];
   double final_position_error = final_position_goal - final_position;

   double final_velocity = velocity[points_number-1];
   double final_velocity_error = final_velocity_goal - final_velocity;

   // Obtain control 

   Vector<double> input(1);
   Vector<double> output(2);

   double acceleration = 0.0;
   double deceleration = 0.0;

    // Write header 

   buffer << "% Flood Neural Network. Car problem results data file." << std::endl
          << "% Final time: " << final_time << std::endl
          << "% Final position error: " << final_position_error << std::endl
          << "% Final velocity error: " << final_velocity_error << std::endl
          << "% Column data:" << std::endl
          << "%  1 - Time" << std::endl
          << "%  2 - Position" << std::endl
          << "%  3 - Velocity" << std::endl
          << "%  4 - Acceleration" << std::endl
          << "%  5 - Deceleration" << std::endl;

   for(int i = 0; i < points_number; i++)
   {
      input[0] = time[i];
      output = multilayer_perceptron_pointer->calculate_output(input);
      acceleration = output[0];
      deceleration = output[1];
      
      // Write time, trajectory and control signal to file   

      buffer << time[i] << " " 
             << position[i] << " "
             << velocity[i] << " "
             << acceleration << " " 
             << deceleration << std::endl;   
   }   

   return(buffer.str());
}


// void print_results(void) method

void CarProblem::print_results(void)
{
	std::cout << get_results_string();
}


// void save_results(const char*) method

void CarProblem::save_results(const char* filename)
{
   std::fstream file; 

   file.open(filename, std::ios::out);
   
   if(!file.is_open())
   {
      std::cerr << "Cannot open car problem results data file." << std::endl;

      exit(1);
   }

   file << get_results_string();


   file.close();
}


// std::string to_XML(void) method

std::string CarProblem::to_XML(void)
{
   std::stringstream buffer;

   return(buffer.str());
}


// void print_information(void) method

void CarProblem::print_information(void)
{
   // Solve state equations 

   Vector<double> time;
   Vector<double> position;
   Vector<double> velocity;

   Vector<double> independent_parameters 
   = multilayer_perceptron_pointer->get_independent_parameters();

   double initial_time = 0.0;
   double final_time = independent_parameters[0];

   if(final_time < 0.0)
   {
      final_time = 0.0;             
   }

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   time, position, velocity, 
   &CarProblem::calculate_position_dot,
   &CarProblem::calculate_velocity_dot,
   initial_time, final_time, initial_position, initial_velocity);

   // Obtain final position and velocity errors

   double final_position_error 
   = fabs(final_position_goal - position[points_number-1]);

   double final_velocity_error 
   = fabs(final_velocity_goal - velocity[points_number-1]);

   std::cout << "Final position error: " << final_position_error << std::endl      
             << "Final velocity error: " << final_velocity_error << std::endl
             << "Final time: " << final_time << std::endl;
}

}


// Flood: An Open Source Neural Networks C++ Library.
// Copyright (C) 2005-2010 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
