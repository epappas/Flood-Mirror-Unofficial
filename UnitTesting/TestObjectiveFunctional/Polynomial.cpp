/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   P O L Y N O M I A L   C L A S S                                                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

// Flood includes

#include "Polynomial.h"

// System includes

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>


using namespace Flood;


// GENERAL CONSTRUCTOR

Polynomial::Polynomial(MultilayerPerceptron* new_multilayer_perceptron_pointer)       
: ObjectiveFunctional(new_multilayer_perceptron_pointer)
{
}


// DEFAULT CONSTRUCTOR

Polynomial::Polynomial(void) : ObjectiveFunctional()
{
}


// DESTRUCTOR

Polynomial::~Polynomial(void)
{
}


// METHODS

// Vector<double> get_coefficients(void) method

Vector<double> Polynomial::get_coefficients(void)
{
   return(coefficients);
}


// void set_coefficients(Vector<double>) method

void Polynomial::set_coefficients(Vector<double> new_coefficients)
{
   coefficients = new_coefficients;
}


double Polynomial::calculate_output(double input)
{
   int size = coefficients.get_size();

   double output = 0.0;

   for(int i = 0; i < size; i++)
   {
      output += coefficients[i]*pow(input,i);
   }

   return(output);
}


// double calculate_objective(void) method

double Polynomial::calculate_objective(void)
{
   calculate_evaluation_count++;

   double input = multilayer_perceptron_pointer->get_independent_parameter(0);

   double objective = calculate_output(input);

   return(objective);
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
