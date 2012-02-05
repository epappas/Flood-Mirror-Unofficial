/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   E A S O M   F U N C T I O N   C L A S S                                                                    */
/*                                                                                                              */
/*   Gilles Cadose                                                                                              */
/*   Carlos Vargas de la Fuente                                                                                 */
/*   Hebert Sotelo Aedo                                                                                         */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*                                                                                                              */
/****************************************************************************************************************/

// Flood includes

#include "EasomFunction.h"

// System includes

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

namespace Flood
{

// GENERAL CONSTRUCTOR

EasomFunction::EasomFunction(MultilayerPerceptron* new_multilayer_perceptron)       
: ObjectiveFunctional(new_multilayer_perceptron)
{
}


// DESTRUCTOR

EasomFunction::~EasomFunction(void)
{
}


// METHODS

// double calculate_objective(void) method

double EasomFunction::calculate_objective(void)
{
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();
         
   double a = exp(-(pow((argument[0]- PI), 2) + pow((argument[1] - PI), 2))); 
    
   double objective = -cos(argument[0])*cos(argument[1])*a;
    
   return(objective);
}


// Vector<double> calculate_objective_gradient(void) method

Vector<double> EasomFunction::calculate_objective_gradient(void)
{
   const int variables_number = 2;

   Vector<double> objective_gradient(variables_number);

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();
   
   double a = exp(-(pow((argument[0]-PI), 2) + pow((argument[1]-PI), 2)));
   
   objective_gradient[0] = a*(sin(argument[0])*cos(argument[1])+2*cos(argument[0])*cos(argument[1])*(argument[0]-PI));
   objective_gradient[1] = a*(cos(argument[0])*sin(argument[1])+2*cos(argument[0])*cos(argument[1])*(argument[1]-PI));
   
   return(objective_gradient);
}


// Matrix<double> calculate_Hessian(void) method

Matrix<double> EasomFunction::calculate_Hessian(void)
{ 
   const int variables_number = 2;

   Matrix<double> Hessian(variables_number, variables_number);

   const double pi = 3.1415927;

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   double a = exp(-(pow((argument[0]-pi), 2) + pow((argument[1]-pi), 2)));
   double b = cos(argument[0])*cos(argument[1]);
   double c = sin(argument[0])*cos(argument[1]);
   double d = sin(argument[0])*sin(argument[1]);
   double e = cos(argument[0])*sin(argument[1]);
   
   Hessian[0][0] = a*(3.0*b - 4.0*c*(argument[0] - pi) - 4.0*b*pow((argument[0]-pi), 2));
   Hessian[0][1] = a*(-d    - 2.0*c*(argument[1] - pi) - 2.0*e*(argument[0]-pi) - 4.0*b*(argument[0]-pi)*(argument[1]-pi));
   Hessian[1][0] = a*(-d    - 2.0*c*(argument[1] - pi) - 2.0*e*(argument[0]-pi) - 4.0*b*(argument[0]-pi)*(argument[1]-pi));
   Hessian[1][1] = a*(3.0*b - 4.0*e*(argument[1] - pi) - 4.0*b*pow((argument[1]-pi), 2));

   return(Hessian);
}


// Matrix<double> calculate_inverse_Hessian(void) method

Matrix<double> EasomFunction::calculate_inverse_Hessian(void)
{
   const int variables_number = 2;

   Matrix<double> inverse_Hessian(variables_number, variables_number);
    
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   Matrix<double> Hessian = calculate_Hessian();
   
   double HessianDeterminant = Hessian[0][0]*Hessian[1][1] - Hessian[0][1]*Hessian[1][0];
 
   inverse_Hessian[0][0] = Hessian[1][1]/HessianDeterminant;
   inverse_Hessian[0][1] = -Hessian[0][1]/HessianDeterminant;
   inverse_Hessian[1][0] = -Hessian[1][0]/HessianDeterminant;
   inverse_Hessian[1][1] = Hessian[0][0]/HessianDeterminant;
 
   return(inverse_Hessian);
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
