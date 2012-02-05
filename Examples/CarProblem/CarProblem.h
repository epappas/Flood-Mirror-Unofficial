/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A R   P R O B L E M   C L A S S   H E A D E R                                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __CARPROBLEM_H__
#define __CARPROBLEM_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

namespace Flood
{

class CarProblem : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR

   explicit CarProblem(MultilayerPerceptron*);

   // DEFAULT CONSTRUCTOR

   explicit CarProblem(void);

   // DESTRUCTOR

   virtual ~CarProblem(void);


   // METHODS

   // Get methods

   double get_initial_position(void);
   double get_initial_velocity(void);

   double get_final_position_goal(void);
   double get_final_velocity_goal(void);

   double get_maximum_acceleration(void);
   double get_maximum_deceleration(void);
   
   double get_final_position_error_weight(void);
   double get_final_velocity_error_weight(void);

   double get_final_time_weight(void);

   OrdinaryDifferentialEquations& get_ordinary_differential_equations(void);

   // Set methods

   void set_initial_position(double);
   void set_initial_velocity(double);

   void set_final_position_goal(double);
   void set_final_velocity_goal(double);

   void set_maximum_acceleration(double);
   void set_maximum_deceleration(double);

   void set_final_position_error_weight(double);
   void set_final_velocity_error_weight(double);

   void set_final_time_weight(double);

   void set_ordinary_differential_equations(const OrdinaryDifferentialEquations&);

   // State equation methods

   double calculate_position_dot(double, double, double);
   double calculate_velocity_dot(double, double, double);

   // Evaluation methods

   double calculate_objective(void);

   // Utility methods

   std::string to_XML(void);

   void print_information(void);

   std::string get_results_string(void);
   void print_results(void);
   void save_results(const char*);

private:

   // Car parameters

   double maximum_acceleration;
   double maximum_deceleration;

   // Initial conditions

   double initial_position;
   double initial_velocity;

   // Goal values

   double final_position_goal;
   double final_velocity_goal;

   // Weight factors

   double final_position_error_weight;
   double final_velocity_error_weight;
   double final_time_weight;

   // Integration stuff

   OrdinaryDifferentialEquations ordinary_differential_equations;

};

}

#endif


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
