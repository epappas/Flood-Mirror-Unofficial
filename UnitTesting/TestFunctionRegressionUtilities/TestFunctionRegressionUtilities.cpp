/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   F U N C T I O N   R E G R E S S I O N   U T I L I T I E S   C L A S S                            */
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

#include "../../Flood/Utilities/Vector.h"
#include "../../Flood/Utilities/Matrix.h"

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/Utilities/InputTargetDataSet.h"
#include "../../Flood/Utilities/FunctionRegressionUtilities.h"

// Unit testing includes

#include "TestFunctionRegressionUtilities.h"

using namespace Flood;


// GENERAL CONSTRUCTOR

TestFunctionRegressionUtilities::TestFunctionRegressionUtilities(void) : UnitTesting() 
{
}


// DESTRUCTOR

TestFunctionRegressionUtilities::~TestFunctionRegressionUtilities(void)
{
}


// METHODS

// void test_constructor(void) method

void TestFunctionRegressionUtilities::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   FunctionRegressionUtilities mu1;

   assert_true(mu1.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(mu1.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron constructor

   MultilayerPerceptron mlp2;
   FunctionRegressionUtilities mu2(&mlp2);

   assert_true(mu2.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(mu2.get_input_target_data_set_pointer() == NULL, LOG);

   // Input-target data set constructor

   InputTargetDataSet itds3;
   FunctionRegressionUtilities mu3(&itds3);

   assert_true(mu3.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(mu3.get_input_target_data_set_pointer() != NULL, LOG);

   // Multilayer perceptron and input-target data set constructor

   MultilayerPerceptron mlp4;
   InputTargetDataSet itds4;

   FunctionRegressionUtilities mu4(&mlp4, &itds4);

   assert_true(mu4.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(mu4.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_destructor(void) method

void TestFunctionRegressionUtilities::test_destructor(void)
{
   message += "test_destructor\n";
}


// Get methods

// void test_get_multilayer_perceptron_pointer(void) method

void TestFunctionRegressionUtilities::test_get_multilayer_perceptron_pointer(void)
{
   message += "test_get_multilayer_perceptron_pointer\n";

   FunctionRegressionUtilities mu;

   assert_true(mu.get_multilayer_perceptron_pointer() == NULL, LOG);

   MultilayerPerceptron mlp;

   mu.set_multilayer_perceptron_pointer(&mlp);
   
   assert_true(mu.get_multilayer_perceptron_pointer() != NULL, LOG);
}


// void test_get_input_target_data_set_pointer(void) method

void TestFunctionRegressionUtilities::test_get_input_target_data_set_pointer(void)
{
   message += "test_get_input_target_data_set_pointer\n";

   FunctionRegressionUtilities mu;

   assert_true(mu.get_input_target_data_set_pointer() == NULL, LOG);

   InputTargetDataSet itds;

   mu.set_input_target_data_set_pointer(&itds);
   
   assert_true(mu.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_get_display(void) method

void TestFunctionRegressionUtilities::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_multilayer_perceptron_pointer(void) method

void TestFunctionRegressionUtilities::test_set_multilayer_perceptron_pointer(void)
{
   message += "test_set_multilayer_perceptron_pointer\n";
}


// void test_set_input_target_data_set_pointer(void) method

void TestFunctionRegressionUtilities::test_set_input_target_data_set_pointer(void)
{
   message += "test_set_input_target_data_set_pointer\n";
}


// void test_set_display(void) method

void TestFunctionRegressionUtilities::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_generate_artificial_data(void) method

void TestFunctionRegressionUtilities::test_generate_artificial_data(void)
{
   message += "test_generate_artificial_data\n";

   InputTargetDataSet itds(3,5,7);

   FunctionRegressionUtilities fru(&itds);

   Vector<double> mean(5, 0.0);
   Vector<double> standard_deviation(5, 0.0);
   Vector<std::string> function_names(7, "ZeroFunction");

   fru.generate_artificial_data(mean, standard_deviation, function_names);

   Matrix<double>& data = itds.get_data();

   assert_true(itds.get_instances_number() == 3, LOG);
   assert_true(itds.get_input_variables_number() == 5, LOG);
   assert_true(itds.get_target_variables_number() == 7, LOG);
   assert_true(data == 0.0, LOG);
}


// void test_calculate_testing_target_output_data(void) method

void TestFunctionRegressionUtilities::test_calculate_testing_target_output_data(void)
{
   message += "test_calculate_testing_target_output_data\n";
   
   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_testing();

   FunctionRegressionUtilities fru(&mlp, &itds);

   Vector< Matrix<double> > testing_target_output_data = fru.calculate_testing_target_output_data();

   assert_true(testing_target_output_data.get_size() == 1, LOG);

   assert_true(testing_target_output_data[0].get_rows_number() == 1, LOG);
   assert_true(testing_target_output_data[0].get_columns_number() == 2, LOG);
   assert_true(testing_target_output_data[0] == 0.0, LOG);
}


// void test_get_testing_target_output_data(void) method

void TestFunctionRegressionUtilities::test_get_testing_target_output_data(void)
{
   message += "test_get_testing_target_output_data\n";

   MultilayerPerceptron mlp(1,1,2);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,2);
   itds.initialize_data(0.0);
   itds.set_testing();

   FunctionRegressionUtilities fru(&mlp, &itds);

   std::string testing_target_output_data =  fru.get_testing_target_output_data(true);

   assert_true(testing_target_output_data.length() != 0, LOG);
}


// void test_print_testing_target_output_data(void) method

void TestFunctionRegressionUtilities::test_print_testing_target_output_data(void)
{
   message += "test_print_testing_target_output_data\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_testing();

   FunctionRegressionUtilities fru(&mlp, &itds);
//   fru.print_testing_target_output_data();
}


// void test_save_testing_target_output_data(void) method

void TestFunctionRegressionUtilities::test_save_testing_target_output_data(void)
{
   message += "test_save_testing_target_output_data\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_testing();

   FunctionRegressionUtilities fru(&mlp, &itds);
   fru.save_testing_target_output_data("../Data/TestingTargetOutputData.xml");
}


// void test_calculate_linear_regression_parameters(void) method

void TestFunctionRegressionUtilities::test_calculate_linear_regression_parameters(void)
{
   message += "test_calculate_linear_regression_parameters\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   FunctionRegressionUtilities mu(&mlp, &itds);

   Vector< Vector<double> > linear_regression_parameters = mu.calculate_linear_regression_parameters();

   assert_true(linear_regression_parameters.get_size() == 0, LOG);


//   std::cout << linear_regression_parameters[0] << std::endl;

//   assert_true(linear_regression_parameters[0][0] == 0.0, LOG);
//   assert_true(linear_regression_parameters[0][1] == 0.0, LOG);
//   assert_true(linear_regression_parameters[0][2] == 1.0, LOG);  
}


// void test_get_linear_regression_parameters(void) method

void TestFunctionRegressionUtilities::test_get_linear_regression_parameters(void)
{
   message += "test_get_linear_regression_parameters\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   FunctionRegressionUtilities fru(&mlp, &itds);

   std::string linear_regression_parameters = fru.get_linear_regression_parameters(true);

   assert_true(linear_regression_parameters.length() != 0, LOG);
}


// void test_print_linear_regression_parameters(void) method

void TestFunctionRegressionUtilities::test_print_linear_regression_parameters(void)
{
   message += "test_print_linear_regression_parameters\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   FunctionRegressionUtilities fru(&mlp, &itds);
   //fru.print_linear_regression_parameters();
}


// void test_save_linear_regression_parameters(void) method

void TestFunctionRegressionUtilities::test_save_linear_regression_parameters(void)
{
   message += "test_save_linear_regression_parameters\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   FunctionRegressionUtilities fru(&mlp, &itds);
   fru.save_linear_regression_parameters("../Data/LinearRegressionParameters");
}


// void test_get_linear_regression_analysis(void) method

void TestFunctionRegressionUtilities::test_get_linear_regression_analysis(void)
{
   message += "test_get_linear_regression_analysis\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   FunctionRegressionUtilities fru(&mlp, &itds);

   std::string linear_regression_analysis = fru.get_linear_regression_analysis(true);

   assert_true(linear_regression_analysis.length() != 0, LOG);
}


// void test_print_linear_regression_analysis(void) method

void TestFunctionRegressionUtilities::test_print_linear_regression_analysis(void)
{
   message += "test_print_linear_regression_analysis\n";
}


// void test_save_linear_regression_analysis(void) method

void TestFunctionRegressionUtilities::test_save_linear_regression_analysis(void)
{
   message += "test_save_linear_regression_analysis\n";
}


// void run_test_case(void) method

void TestFunctionRegressionUtilities::run_test_case(void)
{
   message += "Running function regression utilities test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_multilayer_perceptron_pointer();
   test_get_input_target_data_set_pointer();
   
   test_get_display();

   // Set methods

   test_set_multilayer_perceptron_pointer();
   test_set_input_target_data_set_pointer();

   test_set_display();

   // Arfificial data generators

   test_generate_artificial_data();

   // Testing target output data methods

   test_calculate_testing_target_output_data();
   test_get_testing_target_output_data();
   test_print_testing_target_output_data();
   test_save_testing_target_output_data();

   // Linear regression parameters methods

   test_calculate_linear_regression_parameters();
   test_get_linear_regression_parameters();
   test_print_linear_regression_parameters();
   test_save_linear_regression_parameters();

   // Linear regression analysis methods

   test_get_linear_regression_analysis();
   test_print_linear_regression_analysis();
   test_save_linear_regression_analysis();

   message += "End of function regression utilities test case\n";
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
