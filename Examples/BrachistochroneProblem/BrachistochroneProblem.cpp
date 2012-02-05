/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   B R A C H I S T O C H R O N E   P R O B L E M    C L A S S                                                 */
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
#include <cstdlib>
#include <fstream> 
#include <cmath>

// Flood includes

#include "BrachistochroneProblem.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

 
namespace Flood
{

// GENERAL CONSTRUCTOR

BrachistochroneProblem::BrachistochroneProblem(MultilayerPerceptron* new_multilayer_perceptron)
: ObjectiveFunctional(new_multilayer_perceptron)
{
   xa = 0.0;
   ya = 1.0;
   xb = 1.0;
   yb = 0.0;

   // This problem is very sensitive to this parameter!
   tolerance = 1.0e-6;
   initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DEFAULT CONSTRUCTOR

BrachistochroneProblem::BrachistochroneProblem(void) : ObjectiveFunctional()
{
   xa = 0.0;
   ya = 1.0;
   xb = 1.0;
   yb = 0.0;

   // This problem is very sensitive to this parameter!!!
   tolerance = 1.0e-6;
   initial_size = 1000000;
}


// DESTRUCTOR

BrachistochroneProblem::~BrachistochroneProblem(void) 
{
}


// METHODS

// double get_xa(void) method

double BrachistochroneProblem::get_xa(void)
{
   return(xa);
}


// double get_ya(void) method

double BrachistochroneProblem::get_ya(void)
{
   return(ya);
}


// double get_xb(void) method

double BrachistochroneProblem::get_xb(void)
{
   return(xb);
}


// double get_yb(void) method

double BrachistochroneProblem::get_yb(void)
{
   return(yb);
}


// double get_tolerance(void) method

double BrachistochroneProblem::get_tolerance(void)
{
   return(tolerance);   
}


// int get_initial_size(void) method

int BrachistochroneProblem::get_initial_size(void)
{
   return(initial_size);   
}


// void set_xa(double) method

void BrachistochroneProblem::set_xa(double new_xa)
{
   xa = new_xa;
}


// void set_ya(double) method

void BrachistochroneProblem::set_ya(double  new_ya)
{
   ya = new_ya;
}


// void set_xb(double) method

void BrachistochroneProblem::set_xb(double  new_xb)
{
   xb = new_xb;
}


// void set_yb(double) method

void BrachistochroneProblem::set_yb(double  new_yb)
{
   yb = new_yb;
}


// void set_tolerance(double) method

void BrachistochroneProblem::set_tolerance(double new_tolerance)
{
   tolerance = new_tolerance;

   ordinary_differential_equations.set_tolerance(tolerance);
}


// void set_initial_size(int) method

void BrachistochroneProblem::set_initial_size(int new_initial_size)
{
   initial_size =  new_initial_size;

   ordinary_differential_equations.set_initial_size(initial_size);
}


// void set_problem(double, double, double, double) method

void BrachistochroneProblem::set_problem(double new_xa, double new_ya, double new_xb, double new_yb)
{
   xa = new_xa;
   ya = new_ya;
   xb = new_xb;
   yb = new_yb;
}


// Vector<double> calculate_particular_solution(const Vector<double>&)

Vector<double> BrachistochroneProblem::calculate_particular_solution(const Vector<double>& input)
{
   Vector<double> particular_solution(1);

   double x = input[0];

   particular_solution[0] = ya + (yb-ya)*(x-xa)/(xb-xa);

   return(particular_solution);
}


// Vector<double> calculate_homogeneous_solution(const Vector<double>&)

Vector<double> BrachistochroneProblem::calculate_homogeneous_solution(const Vector<double>& input)
{
   Vector<double> homogeneous_solution(1);

   double x = input[0];

   homogeneous_solution[0] = (x-xa)*(x-xb);

   return(homogeneous_solution);
}


// Vector<double> calculate_particular_solution_derivative(const Vector<double>&)

Vector<double> BrachistochroneProblem::calculate_particular_solution_derivative(const Vector<double>&)
{
   Vector<double> particular_solution_derivative(1);

   particular_solution_derivative[0] = (yb-ya)/(xb-xa);

   return(particular_solution_derivative);
}


// Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&)

Vector<double> BrachistochroneProblem::calculate_homogeneous_solution_derivative(const Vector<double>& input)
{
   Vector<double> homogeneous_solution_derivative(1);

   double x = input[0];

   homogeneous_solution_derivative[0] = (x-xa) + (x-xb);

   return(homogeneous_solution_derivative);
}


// double calculate_descent_time_integrand(double, double) method

double BrachistochroneProblem::calculate_descent_time_integrand(double x, double)
{
   double descent_time_integrand = 0.0;

   Vector<double> input(1, x);

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input, *this);

   double y = output[0];

   Matrix<double> Jacobian = multilayer_perceptron_pointer->calculate_Jacobian(input, *this);

   double dydt = Jacobian[0][0];

   // This problem is very sensitive to this parameter!

   double small = 1.0e-6;

   if(y >= ya)
   {
      y = ya - small;
      dydt = 0.0;
   }

   // Get descent time integrand

   double numerator = 1.0 + pow(dydt,2);
   double denominator = ya-y;

   descent_time_integrand = sqrt(numerator/denominator);
   
   return(descent_time_integrand);   
}


// double calculate_descent_time(void) method

double BrachistochroneProblem::calculate_descent_time(void)      
{
   double descent_time = 0.0;

   double const g = 9.81;

   Vector<double> x;
   Vector<double> y;     

   // This problem is very sensitive to this parameter!
   double small = 1.0e-6;

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this, x, y, 
   &BrachistochroneProblem::calculate_descent_time_integrand,
   xa+small, xb, 0.0);

   double integral = y[points_number-1];

   descent_time = integral/sqrt(2.0*g);

   return(descent_time);   
}


// double calculate_objective(void) method

double BrachistochroneProblem::calculate_objective(void)
{
   return(calculate_descent_time());
}


// std::string to_XML(void) method

std::string BrachistochroneProblem::to_XML(void)
{
   std::stringstream buffer;

   return(buffer.str());
}


// std::string get_results_string(void) method

std::string BrachistochroneProblem::get_results_string(void)
{
   std::stringstream buffer;

   // File header

   buffer << "<Flood version='3.0' class='BrachistochroneProblem' type='Results'>" << std::endl;
   buffer << "<!-- Column data: x y -->" << std::endl;

   // File data

   Vector<double> input(1);
   Vector<double> output(1);

   double x = 0.0;
   double y = 0.0;
   
   int points_number = 101;

   buffer << "<Results>" << std::endl;   

   for(int i = 0; i < points_number; i++)
   {
      // Obtain x

      x = xa + (xb - xa)*i/(points_number-1.0);

      // Obtain y[i]

      input[0] = x;

      output = multilayer_perceptron_pointer->calculate_output(input, *this);

      y = output[0];
      
      // Write x and y 

      buffer << x << " " << y << std::endl;   
   }

   buffer << "</Results>" << std::endl;   

   return(buffer.str());
}


// void print_results(void) method

void BrachistochroneProblem::print_results(void)
{
	std::cout << get_results_string();
}


// void save(const char*) method

void BrachistochroneProblem::save_results(const char* filename)
{
   std::fstream file; 

   file.open(filename, std::ios::out);

   if(!file.is_open())
   {
      std::cout << "Cannot open brachistochrone problem results data file." << std::endl;

      exit(1);
   }

   file << get_results_string();

   file.close();
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
