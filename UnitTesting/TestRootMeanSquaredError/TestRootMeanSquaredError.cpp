/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   R O O T   M E A N   S Q U A R E D   E R R O R   C L A S S                                                  */
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
#include "../../Flood/ObjectiveFunctional/RootMeanSquaredError.h"

// Unit testing includes

#include "TestRootMeanSquaredError.h"

using namespace Flood;


// GENERAL CONSTRUCTOR

TestRootMeanSquaredError::TestRootMeanSquaredError(void) : UnitTesting() 
{
}


// DESTRUCTOR

/// Destructor.

TestRootMeanSquaredError::~TestRootMeanSquaredError(void)
{

}


// METHODS

// void test_constructor(void) method

void TestRootMeanSquaredError::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   RootMeanSquaredError rmse1;

   assert_true(rmse1.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(rmse1.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron

   MultilayerPerceptron mlp2;
   RootMeanSquaredError rmse2(&mlp2);

   assert_true(rmse2.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(rmse2.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron and input-target data set

   MultilayerPerceptron mlp3;
   InputTargetDataSet itds3;
   RootMeanSquaredError rmse3(&mlp3, &itds3);

   assert_true(rmse3.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(rmse3.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_destructor(void) method

void TestRootMeanSquaredError::test_destructor(void)
{
   message += "test_destructor\n";

   RootMeanSquaredError rmse;

   rmse.~RootMeanSquaredError();
}


// void test_get_input_target_data_set_pointer(void) method

void TestRootMeanSquaredError::test_get_input_target_data_set_pointer(void)
{
   message += "test_get_input_target_data_set_pointer\n";

   RootMeanSquaredError rmse;

   assert_true(rmse.get_input_target_data_set_pointer() == NULL, LOG);

   InputTargetDataSet itds;

   rmse.set_input_target_data_set_pointer(&itds);

   assert_true(rmse.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_set(void) method

void TestRootMeanSquaredError::test_set(void)
{
   message += "test_set\n";
}


// void test_set_input_target_data_set_pointer(void) method

void TestRootMeanSquaredError::test_set_input_target_data_set_pointer(void)
{
   message += "test_set_input_target_data_set_pointer\n";
}


// void test_calculate_objective(void) method

void TestRootMeanSquaredError::test_calculate_objective(void)   
{
   message += "test_calculate_objective\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);

   RootMeanSquaredError rmse(&mlp, &itds);

   assert_true(rmse.calculate_objective() == 0.0, LOG);
}


// void test_calculate_output_errors(void) method

void TestRootMeanSquaredError::test_calculate_output_errors(void)
{
   message += "test_calculate_output_errors\n";
}


// void test_calculate_hidden_errors(void) method

void TestRootMeanSquaredError::test_calculate_hidden_errors(void)
{
   message += "test_calculate_hidden_errors\n";
}


// void test_calculate_hidden_layers_error_gradient(void) method

void TestRootMeanSquaredError::test_calculate_hidden_layers_error_gradient(void)
{
   message += "test_calculate_hidden_layers_error_gradient\n";
}


// void test_calculate_output_layer_error_gradient(void) method

void TestRootMeanSquaredError::test_calculate_output_layer_error_gradient(void)
{
   message += "test_calculate_output_layer_error_gradient\n";
}


// void test_calculate_objective_gradient(void) method

void TestRootMeanSquaredError::test_calculate_objective_gradient(void)
{
   message += "test_calculate_objective_gradient\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;
   RootMeanSquaredError rmse(&mlp, &itds);
   Vector<double> objective_gradient;

   // Test

   mlp.initialize_neural_parameters(1.0);
   itds.initialize_data(1.0);

   objective_gradient = rmse.calculate_objective_gradient();
   Vector<double> objective_gradient_numerical_differentiation = rmse.calculate_objective_gradient_numerical_differentiation();

   assert_true(objective_gradient - objective_gradient_numerical_differentiation < 1.0e-3, LOG);
   assert_true(objective_gradient - objective_gradient_numerical_differentiation > -1.0e-3, LOG);
}


// void test_calculate_validation_error(void) method

void TestRootMeanSquaredError::test_calculate_validation_error(void)   
{
   message += "test_calculate_validation_error\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);

   itds.set_validation();

   itds.initialize_data(0.0);

   RootMeanSquaredError rmse(&mlp, &itds);  
}


// void test_to_XML(void) method

void TestRootMeanSquaredError::test_to_XML(void)   
{
   message += "test_to_XML\n";
   
   RootMeanSquaredError rmse;

   std::string object = rmse.to_XML(true);

   //std::cout << object << std::endl;
}


// void test_load(void) method

void TestRootMeanSquaredError::test_load(void)
{
   RootMeanSquaredError rmse;

   rmse.set_display(false);

   rmse.save("../Data/RootMeanSquaredError.dat");

   rmse.load("../Data/RootMeanSquaredError.dat");

   assert_true(rmse.get_display() == false, LOG);
}



// void run_test_case(void) method

void TestRootMeanSquaredError::run_test_case(void)
{
   message += "Running root mean squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_input_target_data_set_pointer();

   // Set methods

   test_set();
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

   // Utility methods

   test_to_XML();   
   test_load();

   message += "End of root mean squared error test case...\n";
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
