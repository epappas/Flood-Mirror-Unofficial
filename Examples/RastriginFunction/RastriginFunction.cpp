/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   R A S T R I G I N   F U N C T I O N   C L A S S                                                            */
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

#include "RastriginFunction.h"

namespace Flood
{

// GENERAL CONSTRUCTOR

RastriginFunction::RastriginFunction(MultilayerPerceptron* new_multilayer_perceptron)       
: ObjectiveFunctional(new_multilayer_perceptron)
{
   variables_number = 2;
}


// DESTRUCTOR

RastriginFunction::~RastriginFunction(void)
{

}


// METHODS


// int get_variables_number(void) method

int RastriginFunction::get_variables_number(void)
{
   return(variables_number);
}


// void set_variables_number(int) method

void RastriginFunction::set_variables_number(int new_variables_number)
{
   variables_number = new_variables_number;
}


// double calculate_objective(void) method

double RastriginFunction::calculate_objective(void)
{
   const double pi = 3.1415927;

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   double objective = 10.0*variables_number;

   for(int i = 0; i < variables_number; i++)
   {
      objective += pow(argument[i], 2) - 10.0*cos(2.0*pi*argument[i]);
   }

   return(objective);
}


// Vector<double> calculate_objective_gradient(void) method

Vector<double> RastriginFunction::calculate_objective_gradient(void)
{
   Vector<double> gradient(variables_number);

   const double pi = 3.1415927;

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   for(int i = 0; i < variables_number; i++)
   {
      gradient[i] = 2.0*argument[i] + 10.0*sin(2.0*pi*argument[i])*2.0*pi;
   }

   return(gradient);
}


// Matrix<double> calculate_Hessian(void) method

Matrix<double> RastriginFunction::calculate_Hessian(void)
{
   Matrix<double> Hessian(variables_number, variables_number);

   const double pi = 3.1415927;

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   for(int i = 0; i < variables_number; i++)
   {
      for(int j = 0; j < variables_number; j++)
      {
         if(i == j)
         {
            Hessian[i][j] = 2.0 + 10.0*cos(2.0*pi*argument[i])*4.0*pow(pi,2);
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

Matrix<double> RastriginFunction::calculate_inverse_Hessian(void)
{
   Matrix<double> inverse_Hessian(variables_number, variables_number);

   const double pi = 3.1415927;

   Vector<double> argument = multilayer_perceptron_pointer->get_independent_parameters();

   for(int i = 0; i < variables_number; i++)
   {
      for(int j = 0; j < variables_number; j++)
      {
         if(i == j)
         {
            inverse_Hessian[i][j] = 1.0/(2.0 + 10.0*cos(2.0*pi*argument[i])*4.0*pow(pi,2));
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
