/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   P L A N E - C Y L I N D E R   C L A S S                                                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>

// Flood includes

#include "PlaneCylinder.h"


namespace Flood
{

// GENERAL CONSTRUCTOR

PlaneCylinder::PlaneCylinder(MultilayerPerceptron* new_multilayer_perceptron)     
: ObjectiveFunctional(new_multilayer_perceptron)
{
   penalty = 1000.0;
}


// DESTRUCTOR

PlaneCylinder::~PlaneCylinder(void)
{

}


// METHODS

// double get_penalty(void) method

double PlaneCylinder::get_penalty(void)
{
   return(penalty);
}


// void set_penalty(double) method

void PlaneCylinder::set_penalty(double newPenalty)
{
   // Control sentence

   if(newPenalty <= 0.0)
   {
      std::cerr << std::endl
                << "Flood Error: PlaneCylinder class." << std::endl
                << "void set_penalty(double) method." << std::endl
                << "Penalty must be greater than 0." << std::endl
                << std::endl;

      exit(1);
   }

   // Set penalty

   penalty = newPenalty;
}


// double calculate_error(void) method

double PlaneCylinder::calculate_error(void)
{
   double error = 0.0;

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   double x = argument[0];
   double y = argument[1];
   
   if(pow(x,2) + pow(y,2) <= 1.0)
   {
      error = 0.0;
   }
   else
   {
      error = pow(x,2) + pow(y,2) - 1.0;
   } 
   
   return(error);       
}


// double calculate_objective(void) method

double PlaneCylinder::calculate_objective(void)
{
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   double x = argument[0];
   double y = argument[1];

   double objective_term = x + y;

   double error = calculate_error();

   double error_term = penalty*pow(error, 2);

   return(objective_term + error_term);
}


// void print_error(void) method

void PlaneCylinder::print_information(void)
{
   double error = calculate_error();
   
   std::cout << "Constraint Error: " << error << std::endl;
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
