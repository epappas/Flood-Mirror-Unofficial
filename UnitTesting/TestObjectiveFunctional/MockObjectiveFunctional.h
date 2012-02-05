/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M O C K   O B J E C T I V E   F U N C T I O N A L   C L A S S   H E A D E R                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __MOCKOBJECTIVEFUNCTIONAL_H__
#define __MOCKOBJECTIVEFUNCTIONAL_H__


// Flood includes

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"


using namespace Flood;


class MockObjectiveFunctional : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR

   explicit MockObjectiveFunctional(MultilayerPerceptron*);


   // DEFAULT CONSTRUCTOR

   explicit MockObjectiveFunctional(void);


   // DESTRUCTOR

   virtual ~MockObjectiveFunctional(void); 
   // METHODS

   double calculate_objective(void);

   Vector<double> calculate_objective_gradient(void);

   Matrix<double> calculate_Hessian(void);

   Matrix<double> calculate_inverse_Hessian(void);

   Vector<double> calculate_vector_dot_Hessian(const Vector<double>&);
};


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
