/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   I S O P E R I M E T R I C   P R O B L E M   C L A S S                                                      */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/

// Flood includes

#include "IsoperimetricProblem.h"     
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

IsoperimetricProblem::IsoperimetricProblem(MultilayerPerceptron* new_multilayer_perceptron_pointer)       
: ObjectiveFunctional(new_multilayer_perceptron_pointer)
{
   perimeter_goal = 1.0;

   perimeter_error_weight = 1.0;
   area_weight = 1.0e-3;

   double tolerance = 1.0e-12;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);   
}


// DEFAULT CONSTRUCTOR

IsoperimetricProblem::IsoperimetricProblem(void) : ObjectiveFunctional()
{
   perimeter_goal = 1.0;

   perimeter_error_weight = 1.0;
   area_weight = 1.0e-3;

   double tolerance = 1.0e-12;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);   
}


// DESTRUCTOR

IsoperimetricProblem::~IsoperimetricProblem(void) 
{

}


// METHODS

// double get_perimeter_goal(void) method

double IsoperimetricProblem::get_perimeter_goal(void)
{
   return(perimeter_goal);
}


// double get_area_weight(void) method

double IsoperimetricProblem::get_area_weight(void)
{
   return(area_weight);
}


// double get_perimeter_error_weight(void) method

double IsoperimetricProblem::get_perimeter_error_weight(void)
{
   return(perimeter_error_weight);
}


// void get_perimeter_goal(double) method

void IsoperimetricProblem::get_perimeter_goal(double newPerimeterGoal)
{
   perimeter_goal = newPerimeterGoal;
}


// void set_area_weight(double) method

void IsoperimetricProblem::set_area_weight(double newAreaWeight)
{
   area_weight = newAreaWeight;
}


// void set_perimeter_error_weight(double) method

void IsoperimetricProblem::set_perimeter_error_weight(double newPerimeterErrorWeight)
{
   perimeter_error_weight = newPerimeterErrorWeight;
}


// Vector<double> calculate_particular_solution(const Vector<double>&) method

Vector<double> IsoperimetricProblem::calculate_particular_solution(const Vector<double>&)
{
   Vector<double> particular_solution(2);
   particular_solution[0] = 0.0;
   particular_solution[1] = 0.0;

   return(particular_solution);
}


// Vector<double> calculate_homogeneous_solution(const Vector<double>&) method

Vector<double> IsoperimetricProblem::calculate_homogeneous_solution(const Vector<double>& input)
{
   Vector<double> homogeneous_solution(2);

   double t = input[0];

   homogeneous_solution[0] = t*(t-1.0);
   homogeneous_solution[1] = t*(t-1.0);

   return(homogeneous_solution);
}


// Vector<double> calculate_particular_solution_derivative(const Vector<double>&) method

Vector<double> IsoperimetricProblem::calculate_particular_solution_derivative(const Vector<double>&)
{
   Vector<double> particular_solution_derivative(2);
   particular_solution_derivative[0] = 0.0;
   particular_solution_derivative[1] = 0.0;

   return(particular_solution_derivative);
}


// Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&) method

Vector<double> IsoperimetricProblem::calculate_homogeneous_solution_derivative(const Vector<double>& input)
{
   Vector<double> homogeneous_solution_derivative(2);

   double t = input[0];

   homogeneous_solution_derivative[0] = 2.0*t - 1.0;
   homogeneous_solution_derivative[1] = 2.0*t - 1.0;

   return(homogeneous_solution_derivative);
}


// double calculate_area_integrand(double) method

double IsoperimetricProblem::calculate_area_integrand(double t, double)
{
   double areaIntegrand = 0.0;
   
   // Set input 

   Vector<double> input(1, t);

   // Get output

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input, *this);

   double x = output[0];
   double y = output[1];

   // Get Jacobian
   
   Matrix<double> Jacobian = multilayer_perceptron_pointer->calculate_Jacobian(input, *this);

   double dxdt = Jacobian[0][0];
   double dydt = Jacobian[0][1];

   // Calculate area integrand

   areaIntegrand = x*dydt - y*dxdt;
   
   return(areaIntegrand);   
}


// double calculate_area(void) method       

double IsoperimetricProblem::calculate_area(void)      
{
   double area = 0.0;

   Vector<double> x;
   Vector<double> y;

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this, x, y, 
   &IsoperimetricProblem::calculate_area_integrand,
   0.0, 1.0, 0.0);

   area = fabs(0.5*y[points_number-1]);

   return(area);   
}


// double calculate_perimeter_integrand(double, double) method

double IsoperimetricProblem::calculate_perimeter_integrand(double t, double)
{
   double perimeterIntegrand = 0.0;

   // Set input

   Vector<double> input(1, t);

   // Get Jacobian
   
   Matrix<double> Jacobian = multilayer_perceptron_pointer->calculate_Jacobian(input, *this);

   double dxdt = Jacobian[0][0];
   double dydt = Jacobian[0][1];

   // Calculate perimeter integrand

   perimeterIntegrand = sqrt(pow(dxdt,2) + pow(dydt,2));

   return(perimeterIntegrand);
}


// double calculate_perimeter(void) method       

double IsoperimetricProblem::calculate_perimeter(void)      
{
   double perimeter = 0.0;

   Vector<double> x;
   Vector<double> y;

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this, x, y, 
   &IsoperimetricProblem::calculate_perimeter_integrand,
   0.0, 1.0, 0.0);

   perimeter = y[points_number-1];

   return(perimeter);   
}


// double calculate_perimeter_error(void) method       

double IsoperimetricProblem::calculate_perimeter_error(void)    
{   
   double perimeter = calculate_perimeter();

   double perimeter_error = perimeter_goal - perimeter;

   return(perimeter_error);
}


// double calculate_objecitve(void) method

double IsoperimetricProblem::calculate_objective(void)
{
   double perimeter_error = calculate_perimeter_error();
   double area = calculate_area();

   return(-1.0*area_weight*area + perimeter_error_weight*pow(perimeter_error,2));
}


// void save_results(const char*) method

void IsoperimetricProblem::save_results(const char* filename)
{
   std::fstream file; 

   file.open(filename, std::ios::out);

   if(!file.is_open())
   {
      std::cout << std::endl
                << "Cannot open isoperimetric problem results data file." 
                << std::endl;
      
      exit(1);
   }

   // File header

   file << "% Flood Neural Network. Isoperimetric problem results data file." << std::endl
        << "% Column data:" << std::endl
        << "%  1 - Independent variable (t)" << std::endl
        << "%  2 - Dependent variable (x)" << std::endl
        << "%  3 - Dependent variable (y)" << std::endl
        << std::endl;

   // File data

   Vector<double> input(1);
   Vector<double> output(2);

   Vector<double> particular_solution(2);
   Vector<double> homogeneous_solution(2);

   double t = 0.0;
   double x = 0.0;
   double y = 0.0;

   int points_number = 1001;

   for(int i = 0; i < points_number; i++)
   {
      // Obtain t

      t = (double)i/(double)(points_number-1.0);

      // Obtain x and y

      input[0] = t;

      output = multilayer_perceptron_pointer->calculate_output(input, *this);
      
      x = output[0];
      y = output[1];
      
      // Write t, x and y to file

      file << t << " " << x << " " << y << std::endl;   
   }   

   file.close();
}


// std::string to_XML(void) method

std::string IsoperimetricProblem::to_XML(void)
{
   std::stringstream buffer;

   return(buffer.str());
}


// void print_information(void) method

void IsoperimetricProblem::print_information(void)
{
   double perimeter_error = calculate_perimeter_error();
   double area = calculate_area();

   std::cout << "Perimeter error: " << perimeter_error << std::endl
             << "Area: " << area << std::endl;
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
