/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   B R A C H I S T O C H R O N E   P R O B L E M   C L A S S   H E A D E R                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __BRACHISTOCHRONEPROBLEM_H__
#define __BRACHISTOCHRONEPROBLEM_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

namespace Flood
{

class BrachistochroneProblem : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR

   explicit BrachistochroneProblem(MultilayerPerceptron*);


   // DEFAULT CONSTRUCTOR

   explicit BrachistochroneProblem(void);


   // DESTRUCTOR

   virtual ~BrachistochroneProblem(void);


   // METHODS

   // Get methods

   double get_xa(void);
   double get_ya(void);
   double get_xb(void);
   double get_yb(void);

   double get_tolerance(void);
   int get_initial_size(void);

   // Set methods

   void set_xa(double);
   void set_ya(double);
   void set_xb(double);
   void set_yb(double);

   void set_problem(double, double, double, double);

   void set_tolerance(double);
   void set_initial_size(int);

   // Boundary conditions methods

   Vector<double> calculate_particular_solution(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution(const Vector<double>&);

   Vector<double> calculate_particular_solution_derivative(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&);

   // Descent time methods

   double calculate_descent_time_integrand(double, double);
   double calculate_descent_time(void);

   // Objective evaluation methods

   double calculate_objective(void);

   // Utility methods

   std::string to_XML(void);

   std::string get_results_string(void);
   void print_results(void);
   void save_results(const char*);

private:

   double xa;
   double ya;
   double xb;
   double yb;

   OrdinaryDifferentialEquations ordinary_differential_equations;
   double tolerance;
   int initial_size;



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
