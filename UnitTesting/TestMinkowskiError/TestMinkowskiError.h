/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   M I N K O W S K I   E R R O R   C L A S S   H E A D E R                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __TESTMINKOWSKIERROR_H__
#define __TESTMINKOWSKIERROR_H__

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;


class TestMinkowskiError : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit TestMinkowskiError(void);


   // DESTRUCTOR

   virtual ~TestMinkowskiError(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Get methods

   void test_get_input_target_data_set_pointer(void);
   void test_get_Minkowski_parameter(void);

   // Set methods

   void test_set(void);
   void test_set_input_target_data_set_pointer(void);
   void test_set_Minkowski_parameter(void);

   // Evaluation methods

   void test_calculate_objective(void);   

   // Validation error methods

   void test_calculate_validation_error(void);

   // Gradient methods

   void test_calculate_output_errors(void);
   void test_calculate_hidden_errors(void);
   void test_calculate_hidden_layers_error_gradient(void);
   void test_calculate_output_layer_error_gradient(void);

   void test_calculate_objective_gradient(void);

   // Utility methods

   void test_to_XML(void);   
   void test_load(void);

   // Unit testing methods

   void run_test_case(void);
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
