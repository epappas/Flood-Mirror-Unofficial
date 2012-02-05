/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M O C K   M U L T I L A Y E R   P E R C E P T R O N   C L A S S                                            */
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

#include "MockMultilayerPerceptron.h"


using namespace Flood;


// GENERAL CONSTRUCTOR

MockMultilayerPerceptron
::MockMultilayerPerceptron(int new_inputs_number, Vector<int> new_hidden_layers_size, int new_outputs_number)
: MultilayerPerceptron(new_inputs_number, new_hidden_layers_size, new_outputs_number)
{
}


// DEFAULT CONSTRUCTOR

MockMultilayerPerceptron::MockMultilayerPerceptron(void) : MultilayerPerceptron()
{
}


// DESTRUCTOR

/// Destructor.

MockMultilayerPerceptron::~MockMultilayerPerceptron(void) 
{
}


// METHODS

// Boundary conditions: (y_1,y_2) = (y_1,y_2)(x1,x2)
// x1 = -1, y_1 = -1
// x1 =  1, y_1 =  1

// Vector<double> calculate_particular_solution(const Vector<double>&) method

Vector<double> MockMultilayerPerceptron::calculate_particular_solution(const Vector<double>& input)
{
   double x = input[0];

   double a = -1.0;
   double ya = -1.0;

   double b = 1.0;
   double yb = 1.0;

   double phi_0 = ya + (yb-ya)*x/(b-a);

   Vector<double> particular_solution(1, phi_0);
  
   return(particular_solution);
}


// Vector<double> calculate_homogeneous_solution(const Vector<double>&) method

Vector<double> MockMultilayerPerceptron::calculate_homogeneous_solution(const Vector<double>& input)
{
   double x = input[0];

   double a = -1.0;
   double b = 1.0;

   double phi_1 = (x-a)*(x-b);  

   Vector<double> homogeneous_solution(1, phi_1);

   return(homogeneous_solution);
}


// Vector<double> calculate_particular_solution_derivative(const Vector<double>&) method

Vector<double> MockMultilayerPerceptron::calculate_particular_solution_derivative(const Vector<double>&)
{
   Vector<double> particular_solution_derivative(outputs_number);

   particular_solution_derivative[0] = 0.0;
   particular_solution_derivative[1] = 0.0;

   return(particular_solution_derivative);
}


// Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&) method

Vector<double> MockMultilayerPerceptron::calculate_homogeneous_solution_derivative(const Vector<double>&)
{
   Vector<double> homogeneous_solution_derivative(outputs_number);

   homogeneous_solution_derivative[0] = 0.0;
   homogeneous_solution_derivative[1] = 0.0;

   return(homogeneous_solution_derivative);
}


// std::string to_XML(void) method

std::string MockMultilayerPerceptron::to_XML(bool)
{
   std::string object;

   return(object);
}


// void print(void) method

void MockMultilayerPerceptron::print(void)
{
	std::cout << to_XML(true);
}


// void save(const char*) method

void MockMultilayerPerceptron::save(const char*)
{
}


// void load(const char*) method

void MockMultilayerPerceptron::load(const char*)   
{
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
