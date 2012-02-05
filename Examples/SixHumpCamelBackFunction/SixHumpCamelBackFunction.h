/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   S I X   H U M P   C A M E L   B A C K   C L A S S   H E A D E R                                            */
/*                                                                                                              */
/*   Alicia & Iorga                                                                                             */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: a_kalms@hotmail.com, iorga1@mixmail.com                                                            */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __SIXHUMPCAMELBACKFUNCTION_H__
#define __SIXHUMPCAMELBACKFUNCTION_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"

namespace Flood
{

class SixHumpCamelBackFunction : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR

   SixHumpCamelBackFunction(MultilayerPerceptron*);


   // DEFAULT CONSTRUCTOR

   SixHumpCamelBackFunction(void);


   // DESTRUCTOR

   virtual ~SixHumpCamelBackFunction(void);


   // METHODS

   // Objective methods

   double calculate_objective(void);

   // Objective gradient methods

   Vector<double> calculate_objective_gradient(void);

   // Objective function Hessian methods

   Matrix<double> calculate_Hessian(void);
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
