/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   G E O D E S I C   P R O B L E M   C L A S S   H E A D E R                                                  */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __GEODESICPROBLEM_H__
#define __GEODESICPROBLEM_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

namespace Flood
{

class GeodesicProblem : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR

   explicit GeodesicProblem(MultilayerPerceptron*);


   // DEFAULT CONSTRUCTOR

   explicit GeodesicProblem(void);


   // DESTRUCTOR

   virtual ~GeodesicProblem(void);


   // METHODS

   // Get methods

   double get_xa(void);
   double get_ya(void);
   double get_xb(void);
   double get_yb(void);

   // Set methods

   void set_xa(double);
   void set_ya(double);
   void set_xb(double);
   void set_yb(double);

   // Arc length methods

   Vector<double> calculate_particular_solution(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution(const Vector<double>&);

   Vector<double> calculate_particular_solution_derivative(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&);

   // Arc length methods

   double calculate_arc_length_integrand(double, double);
   double calculate_arc_length(void);

   // Objective methods

   double calculate_objective(void);

   // Utility methods

   void save_results(const char*);

private:

   double xa;
   double ya;
   double xb;
   double yb;

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
