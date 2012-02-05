/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M I N I M U M   D R A G   P R O B L E M   C L A S S   H E A D E R                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __MINIMUMDRAGPROBLEM_H__
#define __MINIMUMDRAGPROBLEM_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

namespace Flood
{ class MinimumDragProblem : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR

   explicit MinimumDragProblem(MultilayerPerceptron*);


   // DEFAULT CONSTRUCTOR

   explicit MinimumDragProblem(void);


   // DESTRUCTOR

   virtual ~MinimumDragProblem(void);


   // METHODS

   // Boundary conditions methods

   Vector<double> calculate_particular_solution(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution(const Vector<double>&);

   Vector<double> calculate_particular_solution_derivative(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&);   

   // Objective functional evaluation methods

   double calculate_drag_integrand(double, double);  
   double calculate_drag(void);

   double calculate_objective(void);

   // Utility methods

   void save_results(const char*);

private:

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
