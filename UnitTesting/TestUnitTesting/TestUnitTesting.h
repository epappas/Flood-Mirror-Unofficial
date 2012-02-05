/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   U N I T   T E S T I N G   C L A S S   H E A D E R                                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTUNITTESTING_H__
#define __TESTUNITTESTING_H__

// Flood includes

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;


class TestUnitTesting : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // CONSTRUCTOR

   explicit TestUnitTesting(void);

   // DESTRUCTOR

   virtual ~TestUnitTesting(void);

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Get methods

   void test_get_tests_count(void);
   void test_get_tests_passed_count(void);
   void test_get_tests_failed_count(void);

   void test_get_message(void);

   void test_get_display(void);

   // Set methods

   void test_set_tests_count(void);
   void test_set_tests_passed_count(void);
   void test_set_tests_failed_count(void);

   void test_set_message(void);

   void test_set_display(void);

   // Unit testing methods

   void test_assert_true(void);
   void test_assert_false(void);
   
   // Test case methods

   void test_run_test_case(void);
   void test_print_results(void);

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
