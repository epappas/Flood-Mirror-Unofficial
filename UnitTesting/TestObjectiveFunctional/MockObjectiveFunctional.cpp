/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M O C K   O B J E C T I V E   F U N C T I O N A L   C L A S S                                              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <iostream>
#include <fstream>
#include <cmath>

// Unit testing includes

#include "MockObjectiveFunctional.h"


using namespace Flood;


// GENERAL CONSTRUCTOR

MockObjectiveFunctional::MockObjectiveFunctional(MultilayerPerceptron* new_multilayer_perceptron_pointer)
: ObjectiveFunctional(new_multilayer_perceptron_pointer)
{
   regularization_method = None;

   objective_weight = 1.0;
   regularization_weight = 0.1;
}


// DEFAULT CONSTRUCTOR

MockObjectiveFunctional::MockObjectiveFunctional(void) : ObjectiveFunctional()
{
   regularization_method = None;

   objective_weight = 1.0;
   regularization_weight = 0.1;
}


// DESTRUCTOR

/// Destructor.

MockObjectiveFunctional::~MockObjectiveFunctional(void) 
{
}


// METHODS

// double calculate_objective(void) method

double MockObjectiveFunctional::calculate_objective(void)
{
   Vector<double> parameters = multilayer_perceptron_pointer->get_parameters();

   double objective = parameters.dot(parameters);

   return(objective);
}


// Vector<double> calculate_objective_gradient(void) method

Vector<double> MockObjectiveFunctional::calculate_objective_gradient(void)
{
   Vector<double> parameters = multilayer_perceptron_pointer->get_parameters();

   Vector<double> objective_gradient = parameters*2.0;

   return(objective_gradient);
}


// Matrix<double> calculate_Hessian(void) method

Matrix<double> MockObjectiveFunctional::calculate_Hessian(void)
{
   int parameters_number = multilayer_perceptron_pointer->get_parameters_number();

   Vector<double> parameters = multilayer_perceptron_pointer->get_parameters();   

   Matrix<double> Hessian(parameters_number, parameters_number);

   for(int i = 0; i < parameters_number; i++)
   {
      for(int j = 0; j < parameters_number; j++)
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

Matrix<double> MockObjectiveFunctional::calculate_inverse_Hessian(void)
{
   int parameters_number = multilayer_perceptron_pointer->get_parameters_number();

   Matrix<double> inverse_Hessian(parameters_number, parameters_number, 0.0);

   for(int i = 0; i < parameters_number; i++)
   {
      inverse_Hessian[i][i] = 0.5;
   }

   return(inverse_Hessian);
}


// Vector<double> calculate_vector_dot_Hessian(const Vector<double>&)

Vector<double> MockObjectiveFunctional::calculate_vector_dot_Hessian(const Vector<double>& vector)
{
   Matrix<double> Hessian = calculate_Hessian();

   return(vector.dot(Hessian));
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
