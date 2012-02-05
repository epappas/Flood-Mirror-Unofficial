/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   I S O P E R I M E T R I C   P R O B L E M   C L A S S   H E A D E R                                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __ISOPERIMETRICPROBLEM_H__
#define __ISOPERIMETRICPROBLEM_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

namespace Flood
{

class IsoperimetricProblem : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR

   explicit IsoperimetricProblem(MultilayerPerceptron*);

   // DEFAULT CONSTRUCTOR

   explicit IsoperimetricProblem(void);

   // DESTRUCTOR

   virtual ~IsoperimetricProblem(void);

   // METHODS
   
   // Get methods

   double get_perimeter_goal(void);

   double get_area_weight(void);
   double get_perimeter_error_weight(void);

   // Set methods

   void get_perimeter_goal(double);

   void set_area_weight(double);
   void set_perimeter_error_weight(double);
   
   // Boundary conditions methods

   Vector<double> calculate_particular_solution(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution(const Vector<double>&);

   Vector<double> calculate_particular_solution_derivative(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&);

   // Area methods

   double calculate_area_integrand(double, double);
   double calculate_area(void);

   // Perimeter methods

   double calculate_perimeter_integrand(double, double);      
   double calculate_perimeter(void);       
   double calculate_perimeter_error(void);   
      
   // Objective methods

   double calculate_objective(void);

   // Utility methods

   std::string to_XML(void);

   void print_information(void);

   void save_results(const char*);   

private:

   double perimeter_goal;

   double perimeter_error_weight;

   double area_weight;

   OrdinaryDifferentialEquations ordinary_differential_equations;
};

}
#endif


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
