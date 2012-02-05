/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   S I X   H U M P   C A M E L   B A C K   F U N C T I O N   C L A S S                                        */
/*                                                                                                              */
/*   Alicia & Iorga                                                                                             */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: a_kalms@hotmail.com, iorga1@mixmail.com                                                            */
/*                                                                                                              */
/****************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <math.h>

#include "SixHumpCamelBackFunction.h"

namespace Flood
{

// GENERAL CONSTRUCTOR

SixHumpCamelBackFunction::SixHumpCamelBackFunction(MultilayerPerceptron* new_multilayer_perceptron)
:ObjectiveFunctional(new_multilayer_perceptron)
{
}


// DESTRUCTOR

SixHumpCamelBackFunction::~SixHumpCamelBackFunction(void)
{

}


// METHODS

// double calculate_objective(void) method

double SixHumpCamelBackFunction::calculate_objective(void)
{
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();
      
   double evaluation = pow(argument[0],2)*(4.0 - 2.1*pow(argument[0],2)+pow(argument[0],4.0)/3.0)
	          +argument[0]*argument[1]+pow(argument[1],2)*(4*pow(argument[1],2)-4);

   return(evaluation);
}


// Vector<double> calculate_objective_gradient(void) method

Vector<double> SixHumpCamelBackFunction::calculate_objective_gradient(void)
{
   unsigned int variables_number = 2;

   Vector<double> objective_gradient(variables_number);

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   objective_gradient[0] = 2*pow(argument[0],5) - 8.4*pow(argument[0],3) + 8*argument[0]+argument[1];
   objective_gradient[1] = argument[0]-8*argument[1]+16*pow(argument[1],3);

   return(objective_gradient);
}


// Matrix<double> calculate_Hessian(void) method

Matrix<double> SixHumpCamelBackFunction::calculate_Hessian(void)
{
   unsigned int variables_number = 2;

   Matrix<double> hessian(variables_number, variables_number);

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   hessian[0][0] = 10* pow(argument[0],4) - 25.2 * pow(argument[0],2) + 8;
   hessian[0][1] = 1.0;
   hessian[1][0] = 1.0;
   hessian[1][1] = 48*pow(argument[1],2)-8;

   return(hessian);
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
