/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   F U N C T I O N   R E G R E S S I O N   U T I L I T I E S   C L A S S   H E A D E R              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTFUNCTIONREGRESSIONUTILITIES_H__
#define __TESTFUNCTIONREGRESSIONUTILITIES_H__

// Flood includes

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;


class TestFunctionRegressionUtilities : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:  

   // GENERAL CONSTRUCTOR

   explicit TestFunctionRegressionUtilities(void);


   // DESTRUCTOR

   virtual ~TestFunctionRegressionUtilities(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Get methods

   void test_get_multilayer_perceptron_pointer(void);
   void test_get_input_target_data_set_pointer(void);
   
   void test_get_display(void);

   // Set methods

   void test_set_multilayer_perceptron_pointer(void);
   void test_set_input_target_data_set_pointer(void);

   void test_set_display(void);

   // Arfificial data generators

   void test_generate_artificial_data(void);

   // Testing target output data methods

   void test_calculate_testing_target_output_data(void);
   void test_get_testing_target_output_data(void);
   void test_print_testing_target_output_data(void);
   void test_save_testing_target_output_data(void);

   // Linear regression parameters methods

   void test_calculate_linear_regression_parameters(void);
   void test_get_linear_regression_parameters(void);
   void test_print_linear_regression_parameters(void);
   void test_save_linear_regression_parameters(void);

   // Linear regression analysis methods

   void test_get_linear_regression_analysis(void);
   void test_print_linear_regression_analysis(void);
   void test_save_linear_regression_analysis(void);

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
