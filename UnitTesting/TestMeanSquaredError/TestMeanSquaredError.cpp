/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   M E A N   S Q U A R E D   E R R O R   C L A S S                                                  */
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
#include "../../Flood/ObjectiveFunctional/MeanSquaredError.h"

// Unit testing includes

#include "TestMeanSquaredError.h"

using namespace Flood;

// GENERAL CONSTRUCTOR

TestMeanSquaredError::TestMeanSquaredError(void) : UnitTesting() 
{
}


// DESTRUCTOR

TestMeanSquaredError::~TestMeanSquaredError(void)
{
}


// METHODS

// void test_constructor(void) method

void TestMeanSquaredError::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   MeanSquaredError mse1;

   assert_true(mse1.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(mse1.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron

   MultilayerPerceptron mlp2;
   MeanSquaredError mse2(&mlp2);

   assert_true(mse2.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(mse2.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron and input-target data set

   MultilayerPerceptron mlp3;
   InputTargetDataSet itds3;
   MeanSquaredError mse3(&mlp3, &itds3);

   assert_true(mse3.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(mse3.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_destructor(void) method

void TestMeanSquaredError::test_destructor(void)
{
}


// void test_get_input_target_data_set_pointer(void) method

void TestMeanSquaredError::test_get_input_target_data_set_pointer(void)
{
   message += "test_get_input_target_data_set_pointer\n";

   MeanSquaredError mse;

   assert_true(mse.get_input_target_data_set_pointer() == NULL, LOG);

   InputTargetDataSet itds;

   mse.set_input_target_data_set_pointer(&itds);

   assert_true(mse.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_set_input_target_data_set_pointer(void) method

void TestMeanSquaredError::test_set_input_target_data_set_pointer(void)
{
}


// void test_calculate_objective(void) method

void TestMeanSquaredError::test_calculate_objective(void)   
{
   message += "test_calculate_objective\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);

   MeanSquaredError mse(&mlp, &itds);

   assert_true(mse.calculate_objective() == 0.0, LOG);
}


// void test_calculate_output_errors(void) method

void TestMeanSquaredError::test_calculate_output_errors(void)
{
   message += "test_calculate_output_errors\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   MeanSquaredError mse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = mse.calculate_output_errors(forward_propagation_derivative, target);

   assert_true(output_errors.get_size() == 1, LOG);
   assert_true(output_errors == 0.0, LOG);   
}


// void test_calculate_hidden_errors(void) method

void TestMeanSquaredError::test_calculate_hidden_errors(void)
{
   message += "test_calculate_hidden_errors\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   MeanSquaredError mse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = mse.calculate_output_errors(forward_propagation_derivative, target);

   Vector< Vector<double> > hidden_errors = mse.calculate_hidden_errors(forward_propagation_derivative, output_errors);

   assert_true(hidden_errors.get_size() == 1, LOG);
   assert_true(hidden_errors[0].get_size() == 1, LOG);   
   assert_true(hidden_errors[0] == 0.0, LOG);   
}


// void test_calculate_hidden_layers_error_gradient(void) method

void TestMeanSquaredError::test_calculate_hidden_layers_error_gradient(void)
{
   message += "test_calculate_hidden_layers_error_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   MeanSquaredError mse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = mse.calculate_output_errors(forward_propagation_derivative, target);

   Vector< Vector<double> > hidden_errors = mse.calculate_hidden_errors(forward_propagation_derivative, output_errors);

   Vector<double> hidden_layers_error_gradient 
   = mse.calculate_hidden_layers_error_gradient(input, forward_propagation_derivative, hidden_errors);

   assert_true(hidden_layers_error_gradient.get_size() == mlp.get_hidden_layers_parameters_number(), LOG);
   assert_true(hidden_layers_error_gradient == 0.0, LOG);   
}


// void test_calculate_output_layer_error_gradient(void) method

void TestMeanSquaredError::test_calculate_output_layer_error_gradient(void)
{
   message += "test_calculate_output_layer_error_gradient\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);

   MeanSquaredError mse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = mse.calculate_output_errors(forward_propagation_derivative, target);

   Vector<double> output_layer_error_gradient = mse.calculate_output_layer_error_gradient(forward_propagation_derivative, output_errors);

   assert_true(output_layer_error_gradient.get_size() == mlp.get_output_layer_parameters_number(), LOG);
   assert_true(output_layer_error_gradient == 0.0, LOG);   
}


// void test_calculate_objective_gradient(void) method

void TestMeanSquaredError::test_calculate_objective_gradient(void)
{
   message += "test_calculate_objective_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   MeanSquaredError mse(&mlp, &itds);

   Vector<double> objective_gradient = mse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   mlp.set(3,4,2);
   mlp.initialize_neural_parameters(0.0);

   itds.set(5,3,2);
   mse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   objective_gradient = mse.calculate_objective_gradient();

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
   mse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   objective_gradient = mse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

   mlp.set(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   itds.set(1,1,1);

   itds.initialize_data(0.0);

   objective_gradient = mse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   mlp.set(3,4,2);
   mlp.initialize_neural_parameters(0.0);

   itds.set(5,3,2);
   mse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   objective_gradient = mse.calculate_objective_gradient();

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
   mse.set(&mlp, &itds);
   itds.initialize_data(0.0);

   objective_gradient = mse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
//   assert_true(objective_gradient == 0.0, LOG);

   // Test

   mlp.initialize_neural_parameters(1.0);
   itds.initialize_data(1.0);

   objective_gradient = mse.calculate_objective_gradient();
   Vector<double> objective_gradient_numerical_differentiation = mse.calculate_objective_gradient_numerical_differentiation();

   assert_true(objective_gradient - objective_gradient_numerical_differentiation < 1.0e-3, LOG);
   assert_true(objective_gradient - objective_gradient_numerical_differentiation > -1.0e-3, LOG);
}



// void test_calculate_Jacobian(void) method

void TestMeanSquaredError::test_calculate_Jacobian(void)
{
   message += "test_calculate_Jacobian\n";
}


// void test_calculate_validation_error(void) method

void TestMeanSquaredError::test_calculate_validation_error(void)   
{
   message += "test_calculate_validation_error\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   //itds.set_validation_instances_number()

   itds.initialize_data(0.0);

   MeanSquaredError mse(&mlp, &itds);  
}


// void run_test_case(void) method

void TestMeanSquaredError::run_test_case(void)
{
   message += "Running mean squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_input_target_data_set_pointer();

   // Set methods

   test_set_input_target_data_set_pointer();

   // Evaluation methods

   test_calculate_objective();   

   // Gradient methods

   test_calculate_output_errors();
   test_calculate_hidden_errors();
   test_calculate_hidden_layers_error_gradient();
   test_calculate_output_layer_error_gradient();

   test_calculate_objective_gradient();

   // Jacobian methods

   test_calculate_Jacobian();

   // Validation error methods

   test_calculate_validation_error();

   message += "End of mean squared error test case\n";
}


// Flood: An Open Source Neural Networks C++ Library.
// Copyright (C) 2005-2010 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lemser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lemser General Public License for more details.

// You should have received a copy of the GNU Lemser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
