/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   O R D I N A R Y   D I F F E R E N T I A L   E Q U A T I O N S   C L A S S                        */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// Flood includes

#include "TestOrdinaryDifferentialEquations.h"


using namespace Flood;


// GENERAL CONSTRUCTOR

TestOrdinaryDifferentialEquations::TestOrdinaryDifferentialEquations(void) : UnitTesting() 
{   
}


// DESTRUCTOR

TestOrdinaryDifferentialEquations::~TestOrdinaryDifferentialEquations(void)
{
}


// void test_constructor(void) method

void TestOrdinaryDifferentialEquations::test_constructor(void)
{
   message += "test_constructor\n";
}


// void test_destructor(void) method

void TestOrdinaryDifferentialEquations::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_points_number(void) method

void TestOrdinaryDifferentialEquations::test_get_points_number(void)
{
   message += "test_get_points_number\n";
}


// void test_get_tolerance(void) method

void TestOrdinaryDifferentialEquations::test_get_tolerance(void)
{
   message += "test_get_tolerance\n";

}


// void test_get_initial_size(void) method

void TestOrdinaryDifferentialEquations::test_get_initial_size(void)
{
   message += "test_get_initial_size\n";

}


// void test_get_warning_size(void) method

void TestOrdinaryDifferentialEquations::test_get_warning_size(void)
{
   message += "test_get_warning_size\n";
}


// void test_get_error_size(void) method

void TestOrdinaryDifferentialEquations::test_get_error_size(void)
{
   message += "test_get_error_size\n";
}


// void test_get_display(void) method

void TestOrdinaryDifferentialEquations::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_default(void) method

void TestOrdinaryDifferentialEquations::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_set_points_number(void) method

void TestOrdinaryDifferentialEquations::test_set_points_number(void)
{
   message += "test_set_points_number\n";
}


// void test_set_tolerance(void) method

void TestOrdinaryDifferentialEquations::test_set_tolerance(void)
{
   message += "test_set_tolerance\n";
}


// void test_set_initial_size(void) method

void TestOrdinaryDifferentialEquations::test_set_initial_size(void)
{
   message += "test_set_initial_size\n";
}


// void test_set_warning_size(void) method

void TestOrdinaryDifferentialEquations::test_set_warning_size(void)
{
   message += "test_set_warning_size\n";
}


// void test_set_error_size(void) method

void TestOrdinaryDifferentialEquations::test_set_error_size(void)
{
   message += "test_set_error_size\n";
}


// void test_set_display(void) method

void TestOrdinaryDifferentialEquations::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_calculate_Runge_Kutta_integral_1(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_integral_1(void)
{
   message += "test_calculate_Runge_Kutta_integral_1\n";
}


// void test_calculate_Runge_Kutta_integral_2(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_integral_2(void)
{
   message += "test_calculate_Runge_Kutta_integral_2\n";
}


// void test_calculate_Runge_Kutta_integral_3(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_integral_3(void)
{
   message += "test_calculate_Runge_Kutta_integral_3\n";
}


// void test_calculate_Runge_Kutta_integral_4(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_integral_4(void)
{
   message += "test_calculate_Runge_Kutta_integral_4\n";
}


// void test_calculate_Runge_Kutta_integral_5(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_integral_5(void)
{
   message += "test_calculate_Runge_Kutta_integral_5\n";
}


// void test_calculate_Runge_Kutta_Fehlberg_integral_1(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_Fehlberg_integral_1(void)
{
   message += "test_calculate_Runge_Kutta_Fehlberg_integral_1\n";
}


// void test_calculate_Runge_Kutta_Fehlberg_integral_2(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_Fehlberg_integral_2(void)
{
   message += "test_calculate_Runge_Kutta_Fehlberg_integral_2\n";
}


// void test_calculate_Runge_Kutta_Fehlberg_integral_3(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_Fehlberg_integral_3(void)
{
   message += "test_calculate_Runge_Kutta_Fehlberg_integral_3\n";
}


// void test_calculate_Runge_Kutta_Fehlberg_integral_4(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_Fehlberg_integral_4(void)
{
   message += "test_calculate_Runge_Kutta_Fehlberg_integral_4\n";
}


// void test_calculate_Runge_Kutta_Fehlberg_integral_5(void) method

void TestOrdinaryDifferentialEquations::test_calculate_Runge_Kutta_Fehlberg_integral_5(void)
{
   message += "test_calculate_Runge_Kutta_Fehlberg_integral_5\n";
}


// void run_test_case(void) method

void TestOrdinaryDifferentialEquations::run_test_case(void)
{
   message += "Running ordinary differential equations test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_points_number();

   test_get_tolerance();
   test_get_initial_size();
   test_get_warning_size();
   test_get_error_size();

   test_get_display();

   // Set methods

   test_set_default();

   test_set_points_number();

   test_set_tolerance();
   test_set_initial_size();
   test_set_warning_size();
   test_set_error_size();

   test_set_display();

   // Runge-Kutta methods

   test_calculate_Runge_Kutta_integral_1();
   test_calculate_Runge_Kutta_integral_2();
   test_calculate_Runge_Kutta_integral_3();
   test_calculate_Runge_Kutta_integral_4();
   test_calculate_Runge_Kutta_integral_5();

   // Runge-Kutta-Fehlberg methods

   test_calculate_Runge_Kutta_Fehlberg_integral_1();
   test_calculate_Runge_Kutta_Fehlberg_integral_2();
   test_calculate_Runge_Kutta_Fehlberg_integral_3();
   test_calculate_Runge_Kutta_Fehlberg_integral_4();
   test_calculate_Runge_Kutta_Fehlberg_integral_5();

   message += "End of ordinary differential equations test case\n";
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
