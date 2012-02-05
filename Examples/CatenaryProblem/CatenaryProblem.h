/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A T E N A R Y   P R O B L E M   C L A S S   H E A D E R                                                  */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __CATENARYPROBLEM_H__
#define __CATENARYPROBLEM_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

namespace Flood
{

class CatenaryProblem : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR

   explicit CatenaryProblem(MultilayerPerceptron*);


   // DEFAULT CONSTRUCTOR

   explicit CatenaryProblem(void);


   // DESTRUCTOR

   virtual ~CatenaryProblem(void);


   // METHODS

   // Get methods

   double get_xa(void);
   double get_ya(void);
   double get_xb(void);
   double get_yb(void);

   double get_length_goal(void);

   double get_potential_energy_weight(void);
   double get_length_error_weight(void);

   // Set methods

   void set_xa(double);
   void set_ya(double);
   void set_xb(double);
   void set_yb(double);

   void set_length_goal(double);

   void set_potential_energy_weight(double);
   void set_length_error_weight(double);

   // Boundary conditions methods

   Vector<double> calculate_particular_solution(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution(const Vector<double>&);

   Vector<double> calculate_particular_solution_derivative(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&);

   // Potential energy methods

   double calculate_potential_energy_integrand(double, double);
   double calculate_potential_energy(void);

   // Lenght methods

   double calculate_length_integrand(double, double);
   double calculate_length(void);
   double calculate_length_error(void);

   // Objective methods

   double calculate_objective(void);

   // Utility methods

   std::string to_XML(void);

   void print_information(void);

   void save_results(const char*);

private:

   double xa;
   double ya;
   double xb;
   double yb;

   double length_goal;

   double potential_energy_weight;
   double length_error_weight;

   OrdinaryDifferentialEquations ordinary_differential_equations;
};

}

#endif


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
