/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   R O S E N B R O C K   F U N C T I O N   C L A S S   H E A D E R                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __ROSENBROCKFUNCTION_H__
#define __ROSENBROCKFUNCTION_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"

namespace Flood
{

class RosenbrockFunction : public ObjectiveFunctional
{

private:

   int variables_number;

public:

   // GENERAL CONSTRUCTOR

   explicit RosenbrockFunction(MultilayerPerceptron*);

   // DEFAULT CONSTRUCTOR

   explicit RosenbrockFunction(void);

   // DESTRUCTOR

   virtual ~RosenbrockFunction(void);


   // METHODS

   // Get methods

   int get_variables_number(void);

   // Set methods

   void set_variables_number(int);

   // Evaluation methods

   double calculate_objective(void);

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
