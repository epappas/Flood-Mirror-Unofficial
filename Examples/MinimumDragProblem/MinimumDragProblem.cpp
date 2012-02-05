/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M I N I M U M   D R A G   P R O B L E M   C L A S S                                                        */
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
#include <math.h>
#include <float.h>

// Flood includes

#include "MinimumDragProblem.h"

namespace Flood
{

// GENERAL CONSTRUCTOR

MinimumDragProblem::MinimumDragProblem(MultilayerPerceptron* new_multilayer_perceptron)
: ObjectiveFunctional(new_multilayer_perceptron)
{                     
   double tolerance = 1.0e-6;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DEFAULT CONSTRUCTOR

MinimumDragProblem::MinimumDragProblem(void) : ObjectiveFunctional()
{
   double tolerance = 1.0e-6;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DESTRUCTOR

MinimumDragProblem::~MinimumDragProblem(void) 
{

}


// METHODS

// Vector<double> calculate_particular_solution(const Vector<double>&) method

Vector<double> MinimumDragProblem::calculate_particular_solution(const Vector<double>& input)
{
   Vector<double> particular_solution(1);

   double x = input[0];

   double xa = 0.0;
   double ya = 0.0;

   double xb = 1.0;
   double yb = 1.0;

   particular_solution[0] = ya + (yb-ya)*(x-xa)/(xb-xa);

   return(particular_solution);
}


// Vector<double> calculate_homogeneous_solution(const Vector<double>&)

Vector<double> MinimumDragProblem::calculate_homogeneous_solution(const Vector<double>& input)
{
   Vector<double> homogeneous_solution(1);

   double x = input[0];

   double xa = 0.0;
   double xb = 1.0;

   homogeneous_solution[0] = (x-xa)*(x-xb);

   return(homogeneous_solution);
}


// Vector<double> calculate_particular_solution_derivative(const Vector<double>&)

Vector<double> MinimumDragProblem::calculate_particular_solution_derivative(const Vector<double>&)
{
   Vector<double> particular_solution_derivative(1);
   
   double xa = 0.0;
   double ya = 0.0;

   double xb = 1.0;
   double yb = 1.0;

   particular_solution_derivative[0] = (yb-ya)/(xb-xa);

   return(particular_solution_derivative);
}


// Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&)

Vector<double> MinimumDragProblem::calculate_homogeneous_solution_derivative(const Vector<double>& input)
{
   Vector<double> homogeneous_solution_derivative(1);

   double x = input[0];

   double xa = 0.0;
   double xb = 1.0;

   homogeneous_solution_derivative[0] = (x-xa) + (x-xb);

   return(homogeneous_solution_derivative);
}


// double calculate_drag_integrand(void) method

double MinimumDragProblem::calculate_drag_integrand(double x, double)
{
   double dragIntegrand = 0.0;

   Vector<double> input(1, x);

   // Get output

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input, *this);

   double y = output[0];

   // Get output derivative 

   Matrix<double> Jacobian = multilayer_perceptron_pointer->calculate_Jacobian(input, *this);
  
   double dydx = Jacobian[0][0];

   if(y < 0.0)
   {
      y = 0.0;
      dydx = 0.0;
   }
   else if(y > 1.0)
   {
      y = 1.0;
      dydx = 0.0;
   }
   
   dragIntegrand = y*pow(dydx,3); 
 
   return(dragIntegrand);       
}


// double calculate_drag(void) method

double MinimumDragProblem::calculate_drag(void)
{
   double drag = 0.0;

   Vector<double> x;
   Vector<double> y;

   int points_number = ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   x, y, 
   &MinimumDragProblem::calculate_drag_integrand,
   0.0, 1.0, 0.0);

   drag = y[points_number-1];
   
   return(drag);
}


// double calculate_objective(void) method

double MinimumDragProblem::calculate_objective(void)
{
   return(calculate_drag());
}


// void save_results(const char*) method

void MinimumDragProblem::save_results(const char* filename)
{
   std::fstream file; 

   file.open(filename, std::ios::out);

   if(!file.is_open())
   {
      std::cout << std::endl
                << "Cannot open minimum drag problem results data file."
                << std::endl << std::endl;

      exit(1);
   }

   file << "% Flood Neural Network. Minimum drag problem results data file." << std::endl
        << "% Column data:" << std::endl
        << "% 1 - Independent variable (x)" << std::endl
        << "% 2 - Dependent variable (x)" << std::endl;
        
   Vector<double> input(1);
   Vector<double> output(1);

   double x = 0.0;
   double y = 0.0;
        
   int points_number = 1001;

   for(int i = 0; i < points_number; i++)
   {
      x = (double)i/(double)(points_number-1.0);
      
      input[0] = x;
      
      output = multilayer_perceptron_pointer->calculate_output(input, *this);

      y = output[0];

      if(y < 0.0)
      {
         y = 0.0;
      } 
      else if(y > 1.0)
      {
         y = 1.0;
      }
     
      file << x << " " << y << std::endl;
   }                

   file.close();
}

}

// Flood: An Open Source Neural Networks C++ Library.
// Copyright (C) 2005-2007 Roberto Lopez 
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
