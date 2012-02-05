/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   U N I T   T E S T I N G   C L A S S                                                              */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// Flood includes

#include "TestUnitTesting.h"

using namespace Flood;


// GENERAL CONSTRUCTOR

TestUnitTesting::TestUnitTesting(void) : UnitTesting() 
{   
}


// DESTRUCTOR

TestUnitTesting::~TestUnitTesting(void)
{
}


// void test_constructor(void)

void TestUnitTesting::test_constructor(void)
{
   message += "test_constructor\n"; 
}


// void test_destructor(void)

void TestUnitTesting::test_destructor(void)
{
   message += "test_destructor\n"; 
}


// void test_get_tests_count(void)

void TestUnitTesting::test_get_tests_count(void)
{
   message += "test_get_tests_count\n"; 
}


// void test_get_tests_passed_count(void)

void TestUnitTesting::test_get_tests_passed_count(void)
{
   message += "test_get_tests_passed_count\n"; 
}


// void test_get_tests_failed_count(void)

void TestUnitTesting::test_get_tests_failed_count(void)
{
   message += "test_get_tests_failed_count\n"; 
}


// void test_get_message(void)

void TestUnitTesting::test_get_message(void)
{
   message += "test_get_message\n"; 
}


// void test_get_display(void)

void TestUnitTesting::test_get_display(void)
{
   message += "test_get_display\n"; 
}


// void test_set_tests_count(void)

void TestUnitTesting::test_set_tests_count(void)
{
   message += "test_set_tests_count\n"; 
}


// void test_set_tests_passed_count(void)

void TestUnitTesting::test_set_tests_passed_count(void)
{
   message += "test_set_tests_passed_count\n"; 
}


// void test_set_tests_failed_count(void)

void TestUnitTesting::test_set_tests_failed_count(void)
{
   message += "test_set_tests_failed_count\n"; 
}


// void test_set_message(void)

void TestUnitTesting::test_set_message(void)
{
   message += "test_set_message\n"; 
}


// void test_set_display(void)

void TestUnitTesting::test_set_display(void)
{
   message += "test_set_display\n"; 
}


// void test_assert_true(void)

void TestUnitTesting::test_assert_true(void)
{
   message += "test_assert_true\n"; 
}


// void test_assert_false(void)

void TestUnitTesting::test_assert_false(void)
{
   message += "test_assert_false\n"; 
}


// void test_run_test_case(void)

void TestUnitTesting::test_run_test_case(void)
{
   message += "test_run_test_case\n"; 
}


// void test_print_results(void)

void TestUnitTesting::test_print_results(void)
{
   message += "test_print_results\n"; 
}


// void run_test_case(void) method

void TestUnitTesting::run_test_case(void)
{
   message += "Running unit testing test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_tests_count();
   test_get_tests_passed_count();
   test_get_tests_failed_count();

   test_get_message();

   test_get_display();

   // Set methods

   test_set_tests_count();
   test_set_tests_passed_count();
   test_set_tests_failed_count();

   test_set_message();

   test_set_display();

   // Unit testing methods

   test_assert_true();
   test_assert_false();
   
   // Test case methods

   test_run_test_case();
   test_print_results();

   message += "End of unit testing test case...\n";

}


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
