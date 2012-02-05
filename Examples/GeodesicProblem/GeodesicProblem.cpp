/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   G E O D E S I C   P R O B L E M   C L A S S                                                                */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */ 
/*                                                                                                              */
/****************************************************************************************************************/


#include <iostream>     
#include <fstream>     
#include <cmath>     

#include "GeodesicProblem.h"     
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"     

namespace Flood
{

// GENERAL CONSTRUCTOR

GeodesicProblem::GeodesicProblem(MultilayerPerceptron* new_multilayer_perceptron)       
: ObjectiveFunctional(new_multilayer_perceptron)
{
   xa = 0.0;
   ya = 1.0;
   xb = 1.0;
   yb = 0.0;

   double tolerance = 1.0e-12;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DEFAULT CONSTRUCTOR

GeodesicProblem::GeodesicProblem(void) : ObjectiveFunctional()
{
   xa = 0.0;
   ya = 0.1;
   xb = 1.0;
   yb = 0.0;

   double tolerance = 1.0e-12;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DESTRUCTOR

GeodesicProblem::~GeodesicProblem(void) 
{

}


// METHODS

// double get_xa(void) method

double GeodesicProblem::get_xa(void)
{
   return(xa);
}


// double get_ya(void) method

double GeodesicProblem::get_ya(void)
{
   return(ya);
}


// double get_xb(void) method

double GeodesicProblem::get_xb(void)
{
   return(xb);
}

   
// double get_yb(void) method

double GeodesicProblem::get_yb(void)
{
   return(yb);
}
  

// void set_xa(double) method

void GeodesicProblem::set_xa(double new_xa)
{
   xa = new_xa;
}

   
// void set_ya(double) method

void GeodesicProblem::set_ya(double new_ya)
{
   ya = new_ya;
}

   
// void set_xb(double) method

void GeodesicProblem::set_xb(double new_xb)
{
   xb = new_xb;
}


// void set_yb(double) method

void GeodesicProblem::set_yb(double new_yb)
{
   yb = new_yb;
}


// Vector<double> calculate_particular_solution(const Vector<double>&)

Vector<double> GeodesicProblem::calculate_particular_solution(const Vector<double>& input)
{
   Vector<double> particular_solution(1);

   double x = input[0];

   particular_solution[0] = ya + (yb-ya)*(x-xa)/(xb-xa);

   return(particular_solution);
}


// Vector<double> calculate_homogeneous_solution(const Vector<double>&)

Vector<double> GeodesicProblem::calculate_homogeneous_solution(const Vector<double>& input)
{
   Vector<double> homogeneous_solution(1);

   double x = input[0];

   homogeneous_solution[0] = (x-xa)*(x-xb);

   return(homogeneous_solution);
}


// Vector<double> calculate_particular_solution_derivative(const Vector<double>&)

Vector<double> GeodesicProblem::calculate_particular_solution_derivative(const Vector<double>&)
{
   Vector<double> particular_solution_derivative(1, (yb-ya)/(xb-xa));

   return(particular_solution_derivative);
}


// Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&)

Vector<double> GeodesicProblem::calculate_homogeneous_solution_derivative(const Vector<double>& input)
{
   Vector<double> homogeneous_solution_derivative(1);

   double x = input[0];

   homogeneous_solution_derivative[0] = (x-xa) + (x-xb);

   return(homogeneous_solution_derivative);
}


// double calculate_arc_length_integrand(double, double) method

double GeodesicProblem::calculate_arc_length_integrand(double x, double)
{
   double arcLengthIntegrand = 0.0;

   Vector<double> input(1, x);

   Matrix<double> Jacobian = multilayer_perceptron_pointer->calculate_Jacobian(input, *this);

   double dydx = Jacobian[0][0];

   arcLengthIntegrand = sqrt(1.0 + pow(dydx,2));

   return(arcLengthIntegrand);   
}


// double calculate_arc_length(void) method       

double GeodesicProblem::calculate_arc_length(void)      
{
   double arcLength = 0.0;

   Vector<double> x;
   Vector<double> y;

   int points_number 
   = ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   x, y, 
   &GeodesicProblem::calculate_arc_length_integrand,
   xa, xb, 0.0);

   arcLength = y[points_number-1];

   return(arcLength);   
}


// double calculate_objective(void) method

double GeodesicProblem::calculate_objective(void)
{
   return(calculate_arc_length());
}


// void save_results(const char*) method

void GeodesicProblem::save_results(const char* filename)
{
   std::fstream file; 

   // Control sentence

   file.open(filename, std::ios::out);

   if(!file.is_open())
   {
      std::cout << "Cannot open geodesic problem results data file."  << std::endl;
      
      exit(1);
   }

   Vector<double> input(1);
   Vector<double> output(1);

   double x = 0.0;
   double y = 0.0;
    
   // File header

    file << "% Flood Neural Network. Geodesic problem results data file." << std::endl
         << "% Column data:" << std::endl
         << "%  1 - Independent variable (x)" << std::endl
         << "%  2 - Dependent variable (y)" << std::endl
         << std::endl;

   // File data

   int points_number = 1001;

   for(int i = 0; i < points_number; i++)
   {
      // Obtain x

      x = i/(points_number-1.0);

      // Obtain input

      input[0] = x;

      // Obtain output

      output = multilayer_perceptron_pointer->calculate_output(input, *this);

      // Obtain y

      y = output[0];

      // Write x and y to file

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
