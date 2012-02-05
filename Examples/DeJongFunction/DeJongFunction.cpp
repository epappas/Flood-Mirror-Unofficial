/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   D E   J O N G   F U N C T I O N   C L A S S                                                                */
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
#include <string>
#include <sstream>
#include <cmath>   

// Flood includes

#include "DeJongFunction.h"

namespace Flood
{

// GENERAL CONSTRUCTOR

DeJongFunction::DeJongFunction(MultilayerPerceptron* new_multilayer_perceptron)       
: ObjectiveFunctional(new_multilayer_perceptron)
{
   variables_number = 2;
}


// DESTRUCTOR

DeJongFunction::~DeJongFunction(void)
{

}


// METHODS

// int get_variables_number(void) method

int DeJongFunction::get_variables_number(void)
{
   return(variables_number);
}


// void set_variables_number(int) method

void DeJongFunction::set_variables_number(int new_variables_number)
{
   variables_number = new_variables_number;

   // Set multilayer perceptron stuff

   multilayer_perceptron_pointer->set_independent_parameters_number(variables_number);
   
   for(int i = 0; i < variables_number; i++)
   {
      std::stringstream buffer;
      buffer << "x" << i+1;
      multilayer_perceptron_pointer->set_independent_parameter_name(i, buffer.str());

      multilayer_perceptron_pointer->set_independent_parameter_minimum(i, -5.12);
      multilayer_perceptron_pointer->set_independent_parameter_maximum(i, 5.12);  
   }

   multilayer_perceptron_pointer->initialize_independent_parameters_uniform(-5.12, 5.12);
}


// double calculate_objective(void) method

double DeJongFunction::calculate_objective(void)
{
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   return(argument.dot(argument));
}


// Vector<double> calculate_objective_gradient(void) method

Vector<double> DeJongFunction::calculate_objective_gradient(void)
{
   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   return(argument*2.0);
}


// Matrix<double> calculate_Hessian(void) method

Matrix<double> DeJongFunction::calculate_Hessian(void)
{
   Matrix<double> Hessian(variables_number, variables_number);

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   for(int i = 0; i < variables_number; i++)
   {
      for(int j = 0; j < variables_number; j++)
      {
         if(i == j)
         {
            Hessian[i][j] = 2.0;
         }
         else
         {
            Hessian[i][j] = 0.0;
         }
      }
   }

   return(Hessian);
}


// Matrix<double> calculate_inverse_Hessian(void) method

Matrix<double> DeJongFunction::calculate_inverse_Hessian(void)
{
   Matrix<double> inverse_Hessian(variables_number, variables_number);

   for(int i = 0; i < variables_number; i++)
   {
      for(int j = 0; j < variables_number; j++)
      {
         if(i == j)
         {
            inverse_Hessian[i][j] = 0.5;
         }
         else
         {
            inverse_Hessian[i][j] = 0.0;
         }
      }
   }

   return(inverse_Hessian);
}


// std::string to_XML(void) method

std::string DeJongFunction::to_XML(void)
{
   std::stringstream buffer;

   return(buffer.str());
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
