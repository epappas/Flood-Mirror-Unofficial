/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A T E N A R Y   P R O B L E M   C L A S S                                                                */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */ 
/*                                                                                                              */
/****************************************************************************************************************/

// Flood includes

#include "CatenaryProblem.h"     
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"     

// System includes

#include <string>
#include <sstream>
#include <iostream>     
#include <fstream>     
#include <cmath>     

namespace Flood
{

// GENERAL CONSTRUCTOR

CatenaryProblem::CatenaryProblem(MultilayerPerceptron* new_multilayer_perceptron)
: ObjectiveFunctional(new_multilayer_perceptron)
{
   xa = 0.0;
   ya = 1.0;
   xb = 1.0;
   yb = 1.0;

   length_goal = 1.5;

   potential_energy_weight = 1.0;
   length_error_weight = 10.0;

   double tolerance = 1.0e-12;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DEFAULT CONSTRUCTOR

CatenaryProblem::CatenaryProblem(void) : ObjectiveFunctional()
{
   xa = 0.0;
   ya = 1.0;
   xb = 1.0;
   yb = 1.0;

   length_goal = 1.5;

   potential_energy_weight = 1.0;
   length_error_weight = 10.0;

   double tolerance = 1.0e-12;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DESTRUCTOR

CatenaryProblem::~CatenaryProblem(void) 
{
}


// METHODS

// double get_xa(void) method

double CatenaryProblem::get_xa(void)
{
   return(xa);
}


// double get_ya(void) method

double CatenaryProblem::get_ya(void)
{
   return(ya);
}


// double get_xb(void) method

double CatenaryProblem::get_xb(void)
{
   return(xb);
}

   
// double get_yb(void) method

double CatenaryProblem::get_yb(void)
{
   return(yb);
}
  

// double get_length_goal(void) method

double CatenaryProblem::get_length_goal(void)
{
   return(length_goal);
}


// double get_length_error_weight(void) method

double CatenaryProblem::get_length_error_weight(void)
{
   return(length_error_weight);
}


// double get_potential_energy_weight(void) method

double CatenaryProblem::get_potential_energy_weight(void)
{
   return(potential_energy_weight);
}


// void set_xa(double) method

void CatenaryProblem::set_xa(double new_xa)
{
   xa = new_xa;
}

   
// void set_ya(double) method

void CatenaryProblem::set_ya(double  new_ya)
{
   ya = new_ya;
}

   
// void set_xb(double) method

void CatenaryProblem::set_xb(double new_xb)
{
   xb = new_xb;
}


// void set_yb(double) method

void CatenaryProblem::set_yb(double  new_yb)
{
   yb = new_yb;
}


// void set_length_goal(double) method

void CatenaryProblem::set_length_goal(double new_length_goal)
{
   length_goal = new_length_goal;
}


// void set_length_error_weight(double) method

void CatenaryProblem::set_length_error_weight(double new_length_error_weight)
{
   length_error_weight = new_length_error_weight;
}


// void set_potential_energy_weight(double) method

void CatenaryProblem::set_potential_energy_weight(double new_potential_energy_weight)
{
   potential_energy_weight = new_potential_energy_weight;
}


// Vector<double> calculate_particular_solution(const Vector<double>&)

Vector<double> CatenaryProblem::calculate_particular_solution(const Vector<double>& input)
{
   Vector<double> particular_solution(1);

   double x = input[0];

   particular_solution[0] = ya + (yb-ya)*(x-xa)/(xb-xa);

   return(particular_solution);
}


// double calculate_homogeneous_solution(const Vector<double>&)

Vector<double> CatenaryProblem::calculate_homogeneous_solution(const Vector<double>& input)
{
   Vector<double> homogeneous_solution(1);

   double x = input[0];

   homogeneous_solution[0] = (x-xa)*(x-xb);

   return(homogeneous_solution);
}


// Vector<double> calculate_particular_solution_derivative(const Vector<double>&)

Vector<double> CatenaryProblem::calculate_particular_solution_derivative(const Vector<double>&)
{
   Vector<double> particular_solution_derivative(1);

   particular_solution_derivative[0] = (yb-ya)/(xb-xa);

   return(particular_solution_derivative);
}


// double calculate_homogeneous_solution_derivative(const Vector<double>&)

Vector<double> CatenaryProblem::calculate_homogeneous_solution_derivative(const Vector<double>& input)
{
   Vector<double> homogeneous_solution_derivative(1);

   double x = input[0];

   homogeneous_solution_derivative[0] = (x-xa) + (x-xb);

   return(homogeneous_solution_derivative);
}


// double calculate_potential_energy_integrand(double, double) method

double CatenaryProblem::calculate_potential_energy_integrand(double x, double)
{
   double potentialEnergyIntegrand = 0.0;

   Vector<double> input(1);
   Vector<double> output(1);
   Matrix<double> Jacobian(1, 1);

   input[0] = x;
   output = multilayer_perceptron_pointer->calculate_output(input, *this);

    double y = output[0];

   Jacobian = multilayer_perceptron_pointer->calculate_Jacobian(input, *this);

    double dydx = Jacobian[0][0];

   potentialEnergyIntegrand = y*sqrt(1.0 + pow(dydx,2));

   return(potentialEnergyIntegrand);   
}


// double calculate_potential_energy(void) method

double CatenaryProblem::calculate_potential_energy(void)
{
   double potential_energy = 0.0;

   Vector<double> x;
   Vector<double> y;

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   x, y, 
   &CatenaryProblem::calculate_potential_energy_integrand,
   xa, xb, 0.0);

   potential_energy = y[points_number-1];

   return(potential_energy);   
}


// double calculate_length_integrand(double) method

double CatenaryProblem::calculate_length_integrand(double x, double)
{
   double lengthIntegrand = 0.0;

   Vector<double> input(1, x);

   Matrix<double> Jacobian = multilayer_perceptron_pointer->calculate_Jacobian(input, *this);

    double dydx = Jacobian[0][0];

   lengthIntegrand = sqrt(1.0 + pow(dydx,2));

   return(lengthIntegrand);   
}


// double calculate_length(void) method       

double CatenaryProblem::calculate_length(void)      
{
   double length = 0.0;

   Vector<double> x;
   Vector<double> y;

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   x, y, 
   &CatenaryProblem::calculate_length_integrand,
   xa, xb, 0.0);

   length = y[points_number-1];

   return(length);   
}


// double calculate_length_error(void) method

double CatenaryProblem::calculate_length_error(void)
{
   double length_error = 0.0;

   double length = calculate_length();

   length_error = length - length_goal;

   return(length_error);
}


// double calculate_objective(void) method

double CatenaryProblem::calculate_objective()
{
   double potential_energy = calculate_potential_energy();
   double length_error = calculate_length_error();

   double objective = potential_energy_weight*potential_energy + length_error_weight*pow(length_error,2);

   return(objective);
}


// std::string to_XML(void) method

std::string CatenaryProblem::to_XML(void)
{
   std::stringstream buffer;

   return(buffer.str());
}


// void print_information(void) method

void CatenaryProblem::print_information(void)
{
   double potential_energy = calculate_potential_energy();
   double length_error = calculate_length_error();

   std::cout << "Length error: " << length_error << std::endl
             << "Potential energy: " << potential_energy << std::endl;
}
       

// void save_results(const char*) method

void CatenaryProblem::save_results(const char* filename)
{
   std::fstream file; 

   // Control sentence

   file.open(filename, std::ios::out);

   if(!file.is_open())
   {
	   std::cout << std::endl
                 << "Flood Error: CatenaryProblem class." << std::endl
                 << "void save_results(const char*) method." << std::endl
                 << "Cannot open catenary problem results data file."  << std::endl
				 << std::endl;
      
      exit(1);
   }

   Vector<double> input(1);
   Vector<double> output(1);

   double x = 0.0;
   double y = 0.0;
    
   // File header

   file << "% Flood Neural Network. Catenary problem results data file." << std::endl
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
