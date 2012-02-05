/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A R   P R O B L E M   N E U R O C O M P U T I N G   C L A S S   H E A D E R                              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __CARPROBLEMNEUROCOMPUTING_H__
#define __CARPROBLEMNEUROCOMPUTING_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

namespace Flood
{

class CarProblemNeurocomputing : public ObjectiveFunctional
{

public:

     // GENERAL CONSTRUCTOR

   CarProblemNeurocomputing(MultilayerPerceptron*);

     // DEFAULT CONSTRUCTOR

   CarProblemNeurocomputing(void);


   // DESTRUCTOR

   virtual ~CarProblemNeurocomputing(void);


   // METHODS

   // Get methods

   double get_initial_position(void);
   double get_initial_velocity(void);

   double get_final_position_goal(void);
   double get_final_velocity_goal(void);

   double getMinimumAcceleration(void);
   double get_maximum_acceleration(void);

   double get_final_position_error_weight(void);
   double get_final_velocity_error_weight(void);

   double get_final_time_weight(void);

   // Set methods

   void set_initial_position(double);
   void set_initial_velocity(double);

   void set_final_position_goal(double);
   void set_final_velocity_goal(double);

   void set_minimum_acceleration(double);
   void set_maximum_acceleration(double);

   void set_final_position_error_weight(double);
   void set_final_velocity_error_weight(double);

   void set_final_time_weight(double);

   // Boundary condition methods

   Vector<double> calculate_particular_solution(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution(const Vector<double>&);

   // State equation methods

   double calculate_position_dot(double, double, double);
   double calculate_velocity_dot(double, double, double);

   // Objective methods

   double calculate_objective(void);

   // Utility methods

   void save_results(const char*);

   void print_information(void);

private:

   double initial_position;
   double initial_velocity;
   double final_position_goal;
   double final_velocity_goal;
   double minimum_acceleration;
   double maximum_acceleration;

   double final_position_error_weight;
   double final_velocity_error_weight;
   double final_time_weight;

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
