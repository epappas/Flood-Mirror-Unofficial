/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A R   P R O B L E M   N E U R O C O M P U T I N G   C L A S S                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/

#include <iostream>     
#include <fstream>     
#include <math.h>     

#include "CarProblemNeurocomputing.h"

#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"     

namespace Flood
{

// GENERAL CONSTRUCTOR

CarProblemNeurocomputing::CarProblemNeurocomputing(MultilayerPerceptron* new_multilayer_perceptron)
: ObjectiveFunctional(new_multilayer_perceptron)
{
   minimum_acceleration = -1.0;
   maximum_acceleration = 1.0;

   initial_position = 0.0;
   initial_velocity = 0.0;

   final_position_goal = 1.0;
   final_velocity_goal = 0.0;

   final_position_error_weight = 1.0;
   final_velocity_error_weight = 1.0;

   final_time_weight = 1.0e-9;

   double tolerance = 1.0e-12;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DEFAULT CONSTRUCTOR

CarProblemNeurocomputing::CarProblemNeurocomputing(void): ObjectiveFunctional()
{
   minimum_acceleration = -1.0;
   maximum_acceleration = 1.0;

   initial_position = 0.0;
   initial_velocity = 0.0;

   final_position_goal = 1.0;
   final_velocity_goal = 0.0;

   final_position_error_weight = 1.0;
   final_velocity_error_weight = 1.0;

   final_time_weight = 1.0e-9;

   double tolerance = 1.0e-15;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DESTRUCTOR

CarProblemNeurocomputing::~CarProblemNeurocomputing(void)
{

}


// METHODS

// double get_initial_position(void) method

double CarProblemNeurocomputing::get_initial_position(void)
{
   return(initial_position);
}


// double get_initial_velocity(void) method

double CarProblemNeurocomputing::get_initial_velocity(void)
{
   return(initial_velocity);
}


// double get_final_position_goal(void) method

double CarProblemNeurocomputing::get_final_position_goal(void)
{
   return(final_position_goal);
}


// double get_final_velocity_goal(void) method

double CarProblemNeurocomputing::get_final_velocity_goal(void)
{
   return(final_velocity_goal);
}


// double getMinimumAcceleration(void) method

double CarProblemNeurocomputing::getMinimumAcceleration(void)
{
   return(minimum_acceleration);
}


// double get_maximum_acceleration(void) method

double CarProblemNeurocomputing::get_maximum_acceleration(void)
{
    return(maximum_acceleration);
}


// double get_final_position_error_weight(void) method

double CarProblemNeurocomputing::get_final_position_error_weight(void)
{
   return(final_position_error_weight);
}


// double get_final_velocity_error_weight(void) method

double CarProblemNeurocomputing::get_final_velocity_error_weight(void)
{
   return(final_velocity_error_weight);
}


// double get_final_time_weight(void) method

double CarProblemNeurocomputing::get_final_time_weight(void)
{
   return(final_time_weight);
}


// void set_initial_position(double) method

void CarProblemNeurocomputing::set_initial_position(double new_initial_position)
{
   initial_position = new_initial_position;
}

   
// void set_initial_velocity(double) method

void CarProblemNeurocomputing::set_initial_velocity(double new_initial_velocity)
{
   initial_velocity = new_initial_velocity;
}


// void set_final_position_goal(double) method

void CarProblemNeurocomputing::set_final_position_goal(double new_final_position_goal)
{
   final_position_goal = new_final_position_goal;
}

   
// void set_final_velocity_goal(double) method

void CarProblemNeurocomputing::set_final_velocity_goal(double new_final_velocity_goal)
{
   final_velocity_goal = new_final_velocity_goal;
}


// void set_minimum_acceleration(double) method

void CarProblemNeurocomputing::set_minimum_acceleration(double newMinimumAcceleration)
{
   minimum_acceleration = newMinimumAcceleration;
}


// void set_maximum_acceleration(double) method

void CarProblemNeurocomputing::set_maximum_acceleration(double new_maximum_acceleration)
{
   maximum_acceleration = new_maximum_acceleration;
}


// void set_final_position_error_weight(double) method

void CarProblemNeurocomputing
::set_final_position_error_weight(double new_final_position_error_weight)
{
   final_position_error_weight = new_final_position_error_weight;
}


// void set_final_velocity_error_weight(double) method

void CarProblemNeurocomputing::set_final_velocity_error_weight(double new_final_velocity_error_weight)
{
   final_velocity_error_weight = new_final_velocity_error_weight;
}


// void set_final_time_weight(double) method

void CarProblemNeurocomputing::set_final_time_weight(double new_final_time_weight)
{
   final_time_weight = new_final_time_weight;
}


// Vector<double> calculate_particular_solution(const Vector<double>&) method

Vector<double> CarProblemNeurocomputing::calculate_particular_solution(const Vector<double>&)
{
   Vector<double> particular_solution(1);

   return(particular_solution);
}


// Vector<double> calculate_homogeneous_solution(const Vector<double>&) method

Vector<double> CarProblemNeurocomputing::calculate_homogeneous_solution(const Vector<double>& input)
{
   Vector<double> homogeneous_solution(1);

   double time = input[0];

   Vector<double> independent_parameters = multilayer_perceptron_pointer->get_independent_parameters();

   double final_time = independent_parameters[0];

   homogeneous_solution[0] = time*(time-final_time);

   return(homogeneous_solution);
}


// double calculate_position_dot(double, double, double) method

double CarProblemNeurocomputing::calculate_position_dot(double, double, double velocity)
{
   double position_dot = velocity;

   return(position_dot);
}


// double calculate_velocity_dot(double, double, double) method

double CarProblemNeurocomputing::calculate_velocity_dot(double time, double, double)
{
   Vector<double> input(1, time);

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input, *this);

   double acceleration = output[0];

   double velocity_dot = acceleration;

   return(velocity_dot);
}


// double calculate_objective(void) method

double CarProblemNeurocomputing::calculate_objective(void)
{
    // Control sentence 

	if(multilayer_perceptron_pointer == NULL)
   {
      std::cerr << std::endl
               << "Flood Error: CarProblemNeurocomputing class." << std::endl
              << "double calculate_objective(void) method." << std::endl
              << "Pointer to multilayer perceptron object cannot be NULL." << std::endl;

        exit(1);
   }

   double evaluation = 0.0;
   
   // Increment number of evaluations

   calculate_evaluation_count++;

   // Evaluate objective functional

   int independent_parameters_number 
   = multilayer_perceptron_pointer->get_independent_parameters_number();

   if(independent_parameters_number != 1)
   {
      std::cout << std::endl
                << "Flood Error CarProblemNeurocomputing class."
                << "calculate_evaluation(void) method." << std::endl
                << "Number of independent parameters in multilayer perceptron " 
                << "must be one." << std::endl
                << std::endl;

      exit(1);                         
   }

   Vector<double> independent_parameters = multilayer_perceptron_pointer->get_independent_parameters();

   double initial_time = 0.0;
   double final_time = independent_parameters[0];

   // Solve state equations 

   Vector<double> time;
   Vector<double> position;
   Vector<double> velocity;

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   time, position, velocity, 
   &CarProblemNeurocomputing::calculate_position_dot,
   &CarProblemNeurocomputing::calculate_velocity_dot,
   initial_time, final_time, initial_position, initial_velocity);

   // Obtain final position and velocity errors

   double final_position_error 
   = fabs(final_position_goal - position[points_number-1]);

   double final_velocity_error 
   = fabs(final_velocity_goal - velocity[points_number-1]);

   // Calculate evaluation

   evaluation
   = final_time_weight*final_time
   + final_position_error_weight*pow(final_position_error, 2)
   + final_velocity_error_weight*pow(final_velocity_error, 2);

   return(evaluation);
}


// void save_results(const char*) method

void CarProblemNeurocomputing::save_results(const char* filename)
{
    int points_number = 1001;

   ordinary_differential_equations.set_points_number(points_number);

   // Solve state equations 

   Vector<double> time(points_number);
   Vector<double> position(points_number);
   Vector<double> velocity(points_number);

   Vector<double> independent_parameters = multilayer_perceptron_pointer->get_independent_parameters();

   double initial_time = 0.0;
   double final_time = independent_parameters[0];
          
   ordinary_differential_equations.calculate_Runge_Kutta_integral(*this,
   time, position, velocity, 
   &CarProblemNeurocomputing::calculate_position_dot,
   &CarProblemNeurocomputing::calculate_velocity_dot,
   initial_time, final_time, initial_position, initial_velocity);

   double final_position = position[points_number-1];
   double final_position_error = final_position_goal - final_position;

   double final_velocity = velocity[points_number-1];
   double final_velocity_error = final_velocity_goal - final_velocity;

   // Obtain control 

   Vector<double> input(1);
   Vector<double> output(1);

   Vector<double> acceleration(points_number);

   for(int i = 0; i < points_number; i++)
   {
      input[0] = time[i];
      output = multilayer_perceptron_pointer->calculate_output(input, *this);
      acceleration[i] = output[0];   
   }

   // Write data to file

   std::fstream file; 

   file.open(filename, std::ios::out);
   

   file << "% Automobile problem: " << std::endl
       << "% Final position: " << final_position << std::endl
       << "% Final position error: " << final_position_error << std::endl
       << "% Final velocity: " << final_velocity << std::endl
       << "% Final velocity error: " << final_velocity_error << std::endl
       << "% Final time: " << final_time << std::endl;

   
   file << "% Column data:" << std::endl
       << "%  1 - Time" << std::endl
       << "%  2 - Position" << std::endl
       << "%  3 - Velocity" << std::endl
       << "%  4 - Acceleration" << std::endl;

   for(int i = 0; i < points_number; i++)
   {
      // Write time, trajectory and control signal to file   

      file << time[i] << " " 
           << position[i] << " "
           << velocity[i] << " "
           << acceleration[i] << std::endl;   
   }   

   file.close();
}


// void print_information(void) method

void CarProblemNeurocomputing::print_information(void)
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
   &CarProblemNeurocomputing::calculate_position_dot,
   &CarProblemNeurocomputing::calculate_velocity_dot,
   initial_time, final_time, initial_position, initial_velocity);

   // Obtain final position and velocity errors

   double final_position_error 
   = fabs(final_position_goal - position[points_number-1]);

   double final_velocity_error 
   = fabs(final_velocity_goal - velocity[points_number-1]);

   std::cout << "Final time: " << final_time << std::endl
             << "Final position error: " << final_position_error << std::endl      
             << "Final velocity error: " << final_velocity_error << std::endl;
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
