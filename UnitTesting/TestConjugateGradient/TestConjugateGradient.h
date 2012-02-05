/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   C O N J U G A T E   G R A D I E N T   C L A S S   H E A D E R                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTCONJUGATEGRADIENT_H__
#define __TESTCONJUGATEGRADIENT_H__

// Flood includes

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;

class TestConjugateGradient : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit TestConjugateGradient(void); 


   // DESTRUCTOR

   virtual ~TestConjugateGradient(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Get methods

   void test_get_training_direction_method(void);
   void test_get_training_direction_method_name(void);

   // Set methods

   void test_set_training_direction_method(void);

   // Train methods

   void test_calculate_Polak_Ribiere_parameter(void);
   void test_calculate_Fletcher_Reeves_parameter(void);

   void test_calculate_Fletcher_Reeves_training_direction(void);
   void test_calculate_Polak_Ribiere_training_direction(void);

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

