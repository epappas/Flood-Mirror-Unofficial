/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   S U M   S Q U A R E D   E R R O R   C L A S S                                                    */
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
#include <fstream>
#include <cmath>

// Flood includes

#include "../../Flood/Utilities/InputTargetDataSet.h"
#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/ObjectiveFunctional/SumSquaredError.h"

// Unit testing includes

#include "TestSumSquaredError.h"

using namespace Flood;


// GENERAL CONSTRUCTOR

TestSumSquaredError::TestSumSquaredError(void) : UnitTesting() 
{
}


// DESTRUCTOR

TestSumSquaredError::~TestSumSquaredError(void) 
{
}


// METHODS

// void test_constructor(void) method

void TestSumSquaredError::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   SumSquaredError sse1;

   assert_true(sse1.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(sse1.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron

   MultilayerPerceptron mlp2;
   SumSquaredError sse2(&mlp2);

   assert_true(sse2.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(sse2.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron and input-target data set

   MultilayerPerceptron mlp3;
   InputTargetDataSet itds3;
   SumSquaredError sse3(&mlp3, &itds3);

   assert_true(sse3.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(sse3.get_input_target_data_set_pointer() != NULL, LOG);

}


// void test_destructor(void) method

void TestSumSquaredError::test_destructor(void)
{
   message += "test_destructor\n";

   SumSquaredError sse;

   sse.~SumSquaredError();
}


// void test_get_input_target_data_set_pointer(void) method

void TestSumSquaredError::test_get_input_target_data_set_pointer(void)
{
   message += "test_get_input_target_data_set_pointer\n";

   SumSquaredError sse;

   assert_true(sse.get_input_target_data_set_pointer() == NULL, LOG);

   InputTargetDataSet itds;

   sse.set_input_target_data_set_pointer(&itds);

   assert_true(sse.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_set_input_target_data_set_pointer(void) method

void TestSumSquaredError::test_set_input_target_data_set_pointer(void)
{
   message += "test_set_input_target_data_set_pointer\n";
}


// void test_calculate_objective(void) method

void TestSumSquaredError::test_calculate_objective(void)   
{
   message += "test_calculate_objective\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   assert_true(sse.calculate_objective() == 0.0, LOG);
}


// void test_calculate_squared_errors(void) method

void TestSumSquaredError::test_calculate_squared_errors(void)
{
   message += "test_calculate_squared_errors\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Vector<double> squared_errors = sse.calculate_squared_errors();

   assert_true(squared_errors.get_size() == 1, LOG);
   assert_true(squared_errors == 0.0, LOG);   
}


// void test_calculate_output_errors(void) method

void TestSumSquaredError::test_calculate_output_errors(void)
{
   message += "test_calculate_output_errors\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = sse.calculate_output_errors(forward_propagation_derivative, target);

   assert_true(output_errors.get_size() == 1, LOG);
   assert_true(output_errors == 0.0, LOG);   
}


// void test_calculate_hidden_errors(void) method

void TestSumSquaredError::test_calculate_hidden_errors(void)
{
   message += "test_calculate_hidden_errors\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = sse.calculate_output_errors(forward_propagation_derivative, target);

   Vector< Vector<double> > hidden_errors = sse.calculate_hidden_errors(forward_propagation_derivative, output_errors);

   assert_true(hidden_errors.get_size() == 1, LOG);
   assert_true(hidden_errors[0].get_size() == 1, LOG);   
   assert_true(hidden_errors[0] == 0.0, LOG);   
}


// void test_calculate_hidden_layers_error_gradient(void) method

void TestSumSquaredError::test_calculate_hidden_layers_error_gradient(void)
{
   message += "test_calculate_hidden_layers_error_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = sse.calculate_output_errors(forward_propagation_derivative, target);

   Vector< Vector<double> > hidden_errors = sse.calculate_hidden_errors(forward_propagation_derivative, output_errors);

   Vector<double> hidden_layers_error_gradient 
   = sse.calculate_hidden_layers_error_gradient(input, forward_propagation_derivative, hidden_errors);

   assert_true(hidden_layers_error_gradient.get_size() == mlp.get_hidden_layers_parameters_number(), LOG);
   assert_true(hidden_layers_error_gradient == 0.0, LOG);   
}


// void test_calculate_output_layer_error_gradient(void) method

void TestSumSquaredError::test_calculate_output_layer_error_gradient(void)
{
   message += "test_calculate_output_layer_error_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = sse.calculate_output_errors(forward_propagation_derivative, target);

   Vector<double> output_layer_error_gradient = sse.calculate_output_layer_error_gradient(forward_propagation_derivative, output_errors);

   assert_true(output_layer_error_gradient.get_size() == mlp.get_output_layer_parameters_number(), LOG);
   assert_true(output_layer_error_gradient == 0.0, LOG);   
}


// void test_calculate_objective_gradient(void) method

void TestSumSquaredError::test_calculate_objective_gradient(void)
{
   message += "test_calculate_objective_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Vector<double> objective_gradient = sse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   mlp.set(3,4,2);
   mlp.initialize_neural_parameters(0.0);

   itds.set(5,3,2);
   sse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   objective_gradient = sse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

   Vector<int> hidden_layers_size(3);
   hidden_layers_size[0] = 5;
   hidden_layers_size[1] = 1;
   hidden_layers_size[2] = 2;

   mlp.set(2,hidden_layers_size,3);
   mlp.initialize_neural_parameters(0.0);

   itds.set(5,2,3);
   sse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   objective_gradient = sse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

   mlp.set(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   itds.set(1,1,1);

   itds.initialize_data(0.0);

   objective_gradient = sse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   mlp.set(3,4,2);
   mlp.initialize_neural_parameters(0.0);

   itds.set(5,3,2);
   sse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   objective_gradient = sse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

   hidden_layers_size.set(3);
   hidden_layers_size[0] = 5;
   hidden_layers_size[1] = 1;
   hidden_layers_size[2] = 2;

   mlp.set(2,hidden_layers_size,3);
   mlp.initialize_neural_parameters(0.0);

   itds.set(5,2,3);
   sse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   objective_gradient = sse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

   mlp.initialize_neural_parameters(1.0);
   itds.initialize_data(1.0);

   objective_gradient = sse.calculate_objective_gradient();
   Vector<double> objective_gradient_numerical_differentiation = sse.calculate_objective_gradient_numerical_differentiation();

   assert_true(objective_gradient - objective_gradient_numerical_differentiation < 1.0e-3, LOG);
   assert_true(objective_gradient - objective_gradient_numerical_differentiation > -1.0e-3, LOG);
}


// void test_calculate_Jacobian(void) method

void TestSumSquaredError::test_calculate_Jacobian(void)
{   
   message += "test_calculate_Jacobian\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Matrix<double> Jacobian = sse.calculate_Jacobian();

   assert_true(Jacobian.get_rows_number() == itds.get_training_instances_number(), LOG);
   assert_true(Jacobian.get_columns_number() == mlp.get_neural_parameters_number(), LOG);
   assert_true(Jacobian == 0.0, LOG);

   // Test 

   mlp.set(3,4,2);
   mlp.initialize_neural_parameters(0.0);

   itds.set(5,3,2);
   sse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   Jacobian = sse.calculate_Jacobian();

   assert_true(Jacobian.get_rows_number() == itds.get_training_instances_number(), LOG);
   assert_true(Jacobian.get_columns_number() == mlp.get_neural_parameters_number(), LOG);
   assert_true(Jacobian == 0.0, LOG);

   // Test

   Vector<int> hidden_layers_size(3);
   hidden_layers_size[0] = 5;
   hidden_layers_size[1] = 1;
   hidden_layers_size[2] = 2;

   mlp.set(2,hidden_layers_size,3);
   mlp.initialize_neural_parameters(0.0);

   itds.set(5,2,3);
   sse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   Jacobian = sse.calculate_Jacobian();

   assert_true(Jacobian.get_rows_number() == itds.get_training_instances_number(), LOG);
   assert_true(Jacobian.get_columns_number() == mlp.get_neural_parameters_number(), LOG);
   assert_true(Jacobian == 0.0, LOG);

   // Test

   mlp.initialize_neural_parameters(1.0);
   itds.initialize_data(1.0);

   Jacobian = sse.calculate_Jacobian();
   Matrix<double> Jacobian_numerical_differentiation = sse.calculate_Jacobian_numerical_differentiation();

   assert_true(Jacobian - Jacobian_numerical_differentiation < 1.0e-6, LOG);
   assert_true(Jacobian - Jacobian_numerical_differentiation > -1.0e-6, LOG);
}


// void test_calculate_Jacobian_forward_differences(void) method

void TestSumSquaredError::test_calculate_Jacobian_forward_differences(void)
{
   message += "test_calculate_Jacobian_forward_differences\n";

   MultilayerPerceptron mlp(1,1,1);

   int neural_parameters_number = mlp.get_neural_parameters_number();

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Matrix<double> Jacobian = sse.calculate_Jacobian_forward_differences();

   assert_true(Jacobian.get_rows_number() == 1, LOG);
   assert_true(Jacobian.get_columns_number() == neural_parameters_number, LOG);
   assert_true(Jacobian >= -1.0e-3 && Jacobian <= 1.0e-3, LOG);
}


// void test_calculate_Jacobian_central_differences(void) method

void TestSumSquaredError::test_calculate_Jacobian_central_differences(void)
{
   message += "test_calculate_Jacobian_central_differences\n";

   MultilayerPerceptron mlp(1,1,1);

   int neural_parameters_number = mlp.get_neural_parameters_number();

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   Matrix<double> Jacobian = sse.calculate_Jacobian_central_differences();

   assert_true(Jacobian.get_rows_number() == 1, LOG);
   assert_true(Jacobian.get_columns_number() == neural_parameters_number, LOG);
   assert_true(Jacobian == 0.0, LOG);
}


// void test_calculate_Jacobian_numerical_differentiation(void) method

void TestSumSquaredError::test_calculate_Jacobian_numerical_differentiation(void)
{
   message += "test_calculate_Jacobian_numerical_differentiation\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   SumSquaredError sse(&mlp, &itds);

   sse.set_numerical_differentiation_method(SumSquaredError::ForwardDifferences);

   Matrix<double> Jacobian_forward_differences = sse.calculate_Jacobian_numerical_differentiation();

   sse.set_numerical_differentiation_method(SumSquaredError::CentralDifferences);

   Matrix<double> Jacobian_central_differences = sse.calculate_Jacobian_numerical_differentiation();

   assert_true(Jacobian_forward_differences != Jacobian_central_differences, LOG);
}


// void test_calculate_validation_error(void) method

void TestSumSquaredError::test_calculate_validation_error(void)   
{
   message += "test_calculate_validation_error\n";
}


// void test_to_XML(void) method

void TestSumSquaredError::test_to_XML(void)   
{
	message += "test_to_XML\n";
   
   SumSquaredError sse;

   std::string object = sse.to_XML(true);

   //std::cout << object << std::endl;
}


// void test_load(void) method

void TestSumSquaredError::test_load(void)
{
   SumSquaredError sse;

   sse.set_display(false);

   sse.save("../Data/SumSquaredError.dat");

   sse.load("../Data/SumSquaredError.dat");

   assert_true(sse.get_display() == false, LOG);
}


// void run_test_case(void) method

void TestSumSquaredError::run_test_case(void)
{
   message += "Running sum squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_input_target_data_set_pointer();

   // Set methods

   test_set_input_target_data_set_pointer();

   // Evaluation methods

   test_calculate_objective();   

   test_calculate_validation_error();

   // Gradient methods

   test_calculate_objective_gradient();

   test_calculate_output_errors();
   test_calculate_hidden_errors();
   test_calculate_hidden_layers_error_gradient();
   test_calculate_output_layer_error_gradient();

   // Jacobian methods

   test_calculate_Jacobian();

   test_calculate_Jacobian_numerical_differentiation();

   test_calculate_Jacobian_forward_differences();
   test_calculate_Jacobian_central_differences();

   test_calculate_squared_errors();

   // Utility methods

   test_to_XML();   
   test_load();

   message += "End of sum squared error test case...\n";
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
