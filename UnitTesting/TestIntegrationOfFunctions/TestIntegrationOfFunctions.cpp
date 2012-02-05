/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   I N TE G R A T I O N   O F   F U N C T I O N S   C L A S S                                       */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes 

#include <iostream>

// Flood includes

#include "../../Flood/Utilities/IntegrationOfFunctions.h"


// Unit testing includes

#include "../TestObjectiveFunctional/Polynomial.h"
#include "TestIntegrationOfFunctions.h"


using namespace Flood;


// GENERAL CONSTRUCTOR

TestIntegrationOfFunctions::TestIntegrationOfFunctions(void) : UnitTesting() 
{
}

// DESTRUCTOR

TestIntegrationOfFunctions::~TestIntegrationOfFunctions(void)
{
}


// void test_constructor(void) method

void TestIntegrationOfFunctions::test_constructor(void)
{
   message += "test_constructor\n";
}


// void test_destructor(void) method

void TestIntegrationOfFunctions::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_trapezoid_integral(void) method
//@todo
void TestIntegrationOfFunctions::test_calculate_trapezoid_integral(void)
{
   message += "test_calculate_trapezoid_integral\n";

   IntegrationOfFunctions iof;

   // Case 1

   Vector<double> x_1(11);
   x_1.initialize_sequential();

   Vector<double> y_1(11);
   y_1.initialize_sequential();

   double integral_1 = iof.calculate_trapezoid_integral(x_1, y_1);

   assert_true(integral_1 == 50.0, LOG);
   
   // Case 2

   MultilayerPerceptron mlp(1);

   Polynomial p(&mlp);

   Vector<double> coefficients(5);
   coefficients.initialize_sequential();

   p.set_coefficients(coefficients);   

//   double integral_2 = iof.calculate_Simpson_integral(&Polynomial());

//   double calculate_trapezoid_integral(double (*f)(double), double, double, int);  
}


// void test_calculate_Simpson_integral(void) method
//@todo
void TestIntegrationOfFunctions::test_calculate_Simpson_integral(void)
{
   message += "test_calculate_Simpson_integral\n";

   IntegrationOfFunctions iof;

   // Case 1

   Vector<double> x_1(11);
   x_1.initialize_sequential();

   Vector<double> y_1(11);
   y_1.initialize_sequential();

   double integral_1 = iof.calculate_Simpson_integral(x_1, y_1);

   assert_true(integral_1 == 50.0, LOG);
}


// void run_test_case(void) method

void TestIntegrationOfFunctions::run_test_case(void)
{
   message += "Running integration of functions test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Integration methods

   test_calculate_trapezoid_integral();
   test_calculate_Simpson_integral();

   message += "End of integration of functions test case\n";
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
