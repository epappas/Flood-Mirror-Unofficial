/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   R O S E N B R O C K   F U N C T I O N   C L A S S                                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */ 
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>   

#include "RosenbrockFunction.h"

namespace Flood
{

// GENERAL CONSTRUCTOR

RosenbrockFunction::RosenbrockFunction(MultilayerPerceptron* new_multilayer_perceptron)       
: ObjectiveFunctional(new_multilayer_perceptron)
{
   variables_number = 2;
}


// DESTRUCTOR

RosenbrockFunction::~RosenbrockFunction(void)
{

}


// METHODS

// int get_variables_number(void) method

int RosenbrockFunction::get_variables_number(void)
{
   return(variables_number);
}


// void set_variables_number(int) method

void RosenbrockFunction::set_variables_number(int new_variables_number)
{
   variables_number = new_variables_number;
}


// double calculate_objective(void) method

double RosenbrockFunction::calculate_objective(void)
{
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   // Calculate objective

   double objective = 0.0;

   for(int i = 0; i < variables_number-1; i++)
   {
      objective += 100.0*pow(argument[i+1] - pow(argument[i],2), 2) + pow(1.0 - argument[i], 2);
   }

   return(objective);
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
