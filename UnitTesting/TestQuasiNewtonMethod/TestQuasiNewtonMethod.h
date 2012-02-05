/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   Q U A S I - N E W T O N   M E T H O D    C L A S S   H E A D E R                                 */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTQUASINEWTONMETHOD_H__
#define __TESTQUASINEWTONMETHOD_H__

// Flood includes

#include "../../Flood/Utilities/UnitTesting.h"


using namespace Flood;


class TestQuasiNewtonMethod : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit TestQuasiNewtonMethod(void);


   // DESTRUCTOR

   virtual ~TestQuasiNewtonMethod(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void); 

   // Get methods

   void test_get_inverse_Hessian_approximation_method(void);
   void test_get_inverse_Hessian_approximation_method_name(void);

   // Set methods

   void test_set_inverse_Hessian_approximation_method(void);

   // Train methods

   void test_calculate_inverse_Hessian_approximation(void);
   void test_calculate_training_direction(void);

   void test_train(void);

   // Training history methods

   void test_resize_training_history(void);
   void test_set_reserve_all_training_history(void);
   void test_get_training_history_XML(void);   

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
