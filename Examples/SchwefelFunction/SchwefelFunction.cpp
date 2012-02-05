/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   S C H W E F E L   F U N C T I O N   C L A S S                                                              */
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
#include <math.h>   

#include "SchwefelFunction.h"

namespace Flood
{

// GENERAL CONSTRUCTOR

SchwefelFunction::SchwefelFunction(MultilayerPerceptron* new_multilayer_perceptron)       
: ObjectiveFunctional(new_multilayer_perceptron)
{
   variables_number = 2;
}


// DESTRUCTOR

SchwefelFunction::~SchwefelFunction(void)
{

}


// METHODS

// int get_variables_number(void) method

int SchwefelFunction::get_variables_number(void)
{
   return(variables_number);
}


// void set_variables_number(int) method

void SchwefelFunction::set_variables_number(int new_variables_number)
{
   // Set number of variables 

   variables_number = new_variables_number;

   // Set multilayer perceptron stuff

   multilayer_perceptron_pointer->set_independent_parameters_number(variables_number);

   double minimum = -500.0;
   double maximum = 500.0;

   for(unsigned int i = 0; i < variables_number; i++)
   {
      std::stringstream buffer;
      buffer << "x" << i+1;
      multilayer_perceptron_pointer->set_independent_parameter_name(i, buffer.str());

      multilayer_perceptron_pointer->set_independent_parameter_minimum(i, minimum);
      multilayer_perceptron_pointer->set_independent_parameter_maximum(i, maximum); 
   }

   multilayer_perceptron_pointer->initialize_independent_parameters_uniform(minimum, maximum);

}


// double calculate_objective(void) method

double SchwefelFunction::calculate_objective(void)
{
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   double objective = 0.0;

   for(unsigned int i = 0; i < variables_number; i++)
   {
      objective += -argument[i]*sin(sqrt(fabs(argument[i])));
   }

   return(objective);
}


// Vector<double> calculate_objective_gradient(void) method

Vector<double> SchwefelFunction::calculate_objective_gradient(void)
{
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   Vector<double> objective_gradient(variables_number);

   for(unsigned int i = 0; i < variables_number; i++)
   {
      objective_gradient[i] = -sin(sqrt(fabs(argument[i])))-0.5*(sqrt(fabs(argument[i])))*cos(sqrt(fabs(argument[i])));
   }
   
   return(objective_gradient);
}


// Matrix<double> calculate_Hessian(void) method

Matrix<double> SchwefelFunction::calculate_Hessian(void)
{
   Matrix<double> hessian(variables_number, variables_number);

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   for(unsigned int i = 0; i < variables_number; i++)
   {
      for(unsigned int j = 0; j < variables_number; j++)
      {
         if(i == j)
         {
            hessian[i][j] = -3*cos(sqrt(fabs(argument[i])))/(4*(sqrt(fabs(argument[i])))) 
                          + 0.25*sin(sqrt(fabs(argument[i])));
         }
         else
         {
            hessian[i][j] = 0.0;
         }
      }
   }

   return(hessian);
}


// Matrix<double> calculate_inverse_Hessian(void) method

Matrix<double> SchwefelFunction::calculate_inverse_Hessian(void)
{
   Matrix<double> inverse_Hessian(variables_number, variables_number);

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   for(unsigned int i = 0; i < variables_number; i++)
   {
      for(unsigned int j = 0; j < variables_number; j++)
      {
         if(i == j)
         {
            inverse_Hessian[i][j] 
            = 1.0/(-3*cos(sqrt(fabs(argument[i])))/(4*(sqrt(fabs(argument[i]))))
            + 0.25*sin(sqrt(fabs(argument[i]))));
         }
         else
         {
            inverse_Hessian[i][j] = 0.0;
         }
      }
   }

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
