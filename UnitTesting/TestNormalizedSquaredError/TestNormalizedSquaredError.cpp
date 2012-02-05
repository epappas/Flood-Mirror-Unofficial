/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   N O R M A L I Z E D   S Q U A R E D   E R R O R   C L A S S                                      */
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
#include <limits>
#include <cmath>

// Flood includes

#include "../../Flood/Utilities/InputTargetDataSet.h"
#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/ObjectiveFunctional/NormalizedSquaredError.h"

// Unit testing includes

#include "TestNormalizedSquaredError.h"

using namespace Flood;


// GENERAL CONSTRUCTOR


TestNormalizedSquaredError::TestNormalizedSquaredError(void) : UnitTesting() 
{
}


// DESTRUCTOR

TestNormalizedSquaredError::~TestNormalizedSquaredError(void)
{
}


// METHODS

// void test_constructor(void) method

void TestNormalizedSquaredError::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   NormalizedSquaredError nse1;

   assert_true(nse1.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(nse1.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron

   MultilayerPerceptron mlp2;
   NormalizedSquaredError nse2(&mlp2);

   assert_true(nse2.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(nse2.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron and input-target data set

   MultilayerPerceptron mlp3;
   InputTargetDataSet itds3;
   NormalizedSquaredError nse3(&mlp3, &itds3);

   assert_true(nse3.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(nse3.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_destructor(void)

void TestNormalizedSquaredError::test_destructor(void)
{
   message += "test_destructor\n";

   NormalizedSquaredError nse;

   nse.~NormalizedSquaredError();
}


// void test_get_input_target_data_set_pointer(void) method

void TestNormalizedSquaredError::test_get_input_target_data_set_pointer(void)
{
   message += "test_get_input_target_data_set_pointer\n";

   NormalizedSquaredError nse;

   assert_true(nse.get_input_target_data_set_pointer() == NULL, LOG);

   InputTargetDataSet itds;

   nse.set_input_target_data_set_pointer(&itds);

   assert_true(nse.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_set(void) method

void TestNormalizedSquaredError::test_set(void)
{
   message += "test_set\n";
}


// void test_set_input_target_data_set_pointer(void) method

void TestNormalizedSquaredError::test_set_input_target_data_set_pointer(void)
{
   message += "test_set_input_target_data_set_pointer\n";
}


// void test_calculate_training_normalization_coefficient(void) method

void TestNormalizedSquaredError::test_calculate_training_normalization_coefficient(void)
{
   message += "test_calculate_training_normalization_coefficient\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(2,1,1);
   itds.initialize_data(0.0);

   NormalizedSquaredError nse(&mlp, &itds); 

   double training_normalization_coefficient = nse.calculate_training_normalization_coefficient();

   assert_true(training_normalization_coefficient == 0.0, LOG);

   Matrix<double> new_data(2,2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   itds.set_data(new_data);

   training_normalization_coefficient = nse.calculate_training_normalization_coefficient();   

   assert_true(training_normalization_coefficient == 2.0, LOG);
}


// void test_calculate_validation_normalization_coefficient(void) method

void TestNormalizedSquaredError::test_calculate_validation_normalization_coefficient(void)
{
   message += "test_calculate_validation_normalization_coefficient\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(2,1,1);
   itds.set_validation();

   itds.initialize_data(0.0);

   NormalizedSquaredError nse(&mlp, &itds); 

   double validation_normalization_coefficient = nse.calculate_validation_normalization_coefficient();

   assert_true(validation_normalization_coefficient == 0.0, LOG);

   Matrix<double> new_data(2,2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   itds.set_data(new_data);

   validation_normalization_coefficient = nse.calculate_validation_normalization_coefficient();   

   assert_true(validation_normalization_coefficient == 2.0, LOG);
}


// void test_calculate_objective(void) method

void TestNormalizedSquaredError::test_calculate_objective(void)   
{
   message += "test_calculate_objective\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Linear);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Linear);

   mlp.initialize_biases(0.0);
   mlp.initialize_synaptic_weights(1.0);

   InputTargetDataSet itds(2,1,1);

   Matrix<double> new_data(2, 2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   itds.set_data(new_data);

   NormalizedSquaredError nse(&mlp, &itds);

   assert_true(nse.calculate_objective() == 0.0, LOG);
}


// void test_calculate_validation_error(void) method

void TestNormalizedSquaredError::test_calculate_validation_error(void)   
{
   message += "test_calculate_validation_error\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.set_validation();

   itds.initialize_data(0.0);

   NormalizedSquaredError nse(&mlp, &itds);  
}


// void test_calculate_output_errors(void) method

void TestNormalizedSquaredError::test_calculate_output_errors(void)
{
   message += "test_calculate_output_errors\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Linear);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Linear);

   mlp.initialize_biases(0.0);
   mlp.initialize_synaptic_weights(1.0);

   InputTargetDataSet itds(2,1,1);

   Matrix<double> new_data(2, 2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   itds.set_data(new_data);

   NormalizedSquaredError nse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = nse.calculate_output_errors(forward_propagation_derivative, target);

   assert_true(output_errors.get_size() == 1, LOG);
   assert_true(output_errors == 0.0, LOG);   
}


// void test_calculate_hidden_errors(void) method

void TestNormalizedSquaredError::test_calculate_hidden_errors(void)
{
   message += "test_calculate_hidden_errors\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(2,1,1);

   Matrix<double> new_data(2, 2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   itds.set_data(new_data);

   NormalizedSquaredError nse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = nse.calculate_output_errors(forward_propagation_derivative, target);

   Vector< Vector<double> > hidden_errors = nse.calculate_hidden_errors(forward_propagation_derivative, output_errors);

   assert_true(hidden_errors.get_size() == 1, LOG);
   assert_true(hidden_errors[0].get_size() == 1, LOG);   
   assert_true(hidden_errors[0] == 0.0, LOG);   
}


// void test_calculate_hidden_layers_error_gradient(void) method

void TestNormalizedSquaredError::test_calculate_hidden_layers_error_gradient(void)
{
   message += "test_calculate_hidden_layers_error_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(2,1,1);

   Matrix<double> new_data(2, 2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   itds.set_data(new_data);

   NormalizedSquaredError nse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = nse.calculate_output_errors(forward_propagation_derivative, target);

   Vector< Vector<double> > hidden_errors = nse.calculate_hidden_errors(forward_propagation_derivative, output_errors);

   Vector<double> hidden_layers_error_gradient 
   = nse.calculate_hidden_layers_error_gradient(input, forward_propagation_derivative, hidden_errors);

   assert_true(hidden_layers_error_gradient.get_size() == mlp.get_hidden_layers_parameters_number(), LOG);
   assert_true(hidden_layers_error_gradient == 0.0, LOG);   
}


// void test_calculate_output_layer_error_gradient(void) method

void TestNormalizedSquaredError::test_calculate_output_layer_error_gradient(void)
{
   message += "test_calculate_output_layer_error_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(2,1,1);

   Matrix<double> new_data(2, 2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   itds.set_data(new_data);

   NormalizedSquaredError nse(&mlp, &itds);

   Vector<double> input = itds.get_input_instance(0);
   Vector<double> target = itds.get_target_instance(0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   Vector<double> output_errors = nse.calculate_output_errors(forward_propagation_derivative, target);

   Vector<double> output_layer_error_gradient = nse.calculate_output_layer_error_gradient(forward_propagation_derivative, output_errors);

   assert_true(output_layer_error_gradient.get_size() == mlp.get_output_layer_parameters_number(), LOG);
}


// void test_calculate_objective_gradient(void) method

void TestNormalizedSquaredError::test_calculate_objective_gradient(void)
{
   message += "test_calculate_objective_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(2,1,1);

   Matrix<double> new_data(2, 2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   itds.set_data(new_data);

   NormalizedSquaredError nse(&mlp, &itds);

   Vector<double> objective_gradient = nse.calculate_objective_gradient();

   assert_true(objective_gradient.get_size() == mlp.get_neural_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);
}


// void run_test_case(void) method

void TestNormalizedSquaredError::run_test_case(void)
{
   message += "Running normalized squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_input_target_data_set_pointer();

   // Set methods

   test_set();
   test_set_input_target_data_set_pointer();

   // Evaluation methods

   test_calculate_training_normalization_coefficient();
   test_calculate_validation_normalization_coefficient();

   test_calculate_objective();   
   test_calculate_validation_error();

   // Gradient methods

   test_calculate_output_errors();
   test_calculate_hidden_errors();
   test_calculate_hidden_layers_error_gradient();
   test_calculate_output_layer_error_gradient();

   test_calculate_objective_gradient();

   message += "End of normalized squared error test case...\n";
}


// Flood: An Open Source Neural Networks C++ Library.
// Copyright (C) 2005-2010 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lenser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lenser General Public License for more details.

// You should have received a copy of the GNU Lenser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
