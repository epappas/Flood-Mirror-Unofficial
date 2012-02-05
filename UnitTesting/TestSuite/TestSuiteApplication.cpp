/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   S U I T E   A P P L I C A T I O N                                                                */
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
#include "../../Flood/Utilities/UnitTesting.h"

// Unit testing includes

#include "../TestVector/TestVector.h"
#include "../TestMatrix/TestMatrix.h"
#include "../TestInputTargetDataSet/TestInputTargetDataSet.h"
#include "../TestIntegrationOfFunctions/TestIntegrationOfFunctions.h"
#include "../TestOrdinaryDifferentialEquations/TestOrdinaryDifferentialEquations.h"
#include "../TestFunctionRegressionUtilities/TestFunctionRegressionUtilities.h"
#include "../TestPatternRecognitionUtilities/TestPatternRecognitionUtilities.h"

// Perceptron includes

#include "../TestPerceptron/TestPerceptron.h"

// Multilayer perceptron includes

#include "../TestMultilayerPerceptron/TestMultilayerPerceptron.h"

// Objective functional includes

#include "../TestObjectiveFunctional/TestObjectiveFunctional.h"
#include "../TestSumSquaredError/TestSumSquaredError.h"
#include "../TestMeanSquaredError/TestMeanSquaredError.h"
#include "../TestRootMeanSquaredError/TestRootMeanSquaredError.h"
#include "../TestNormalizedSquaredError/TestNormalizedSquaredError.h"
#include "../TestMinkowskiError/TestMinkowskiError.h"

// Training algorithm includes

#include "../TestTrainingAlgorithm/TestTrainingAlgorithm.h"
#include "../TestRandomSearch/TestRandomSearch.h"
#include "../TestEvolutionaryAlgorithm/TestEvolutionaryAlgorithm.h"
#include "../TestGradientDescent/TestGradientDescent.h"
#include "../TestConjugateGradient/TestConjugateGradient.h"
#include "../TestQuasiNewtonMethod/TestQuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Test Suite Application." << std::endl;   

   std::string message;
   int tests_count = 0;
   int tests_passed_count = 0;
   int tests_failed_count = 0;

   // Test vector

   TestVector test_vector;
   test_vector.run_test_case();
   message += test_vector.get_message();
   tests_count += test_vector.get_tests_count(); 
   tests_passed_count += test_vector.get_tests_passed_count();
   tests_failed_count += test_vector.get_tests_failed_count();

   // Test matrix

   TestMatrix test_matrix;
   test_matrix.run_test_case();
   tests_count += test_matrix.get_tests_count(); 
   tests_passed_count += test_matrix.get_tests_passed_count();
   tests_failed_count += test_matrix.get_tests_failed_count();   

   // Test input-target data set

   TestInputTargetDataSet test_input_target_data_set;
   test_input_target_data_set.run_test_case();
   message += test_input_target_data_set.get_message();
   tests_count += test_input_target_data_set.get_tests_count(); 
   tests_passed_count += test_input_target_data_set.get_tests_passed_count();
   tests_failed_count += test_input_target_data_set.get_tests_failed_count();

   // Test integration of functions

   TestIntegrationOfFunctions test_integration_of_functions;
   test_integration_of_functions.run_test_case();
   message += test_integration_of_functions.get_message();
   tests_count += test_integration_of_functions.get_tests_count(); 
   tests_passed_count += test_integration_of_functions.get_tests_passed_count();
   tests_failed_count += test_integration_of_functions.get_tests_failed_count();
   
   // Test ordinary differential equations

   TestOrdinaryDifferentialEquations test_ordinary_differential_equations;
   test_ordinary_differential_equations.run_test_case();
   message += test_ordinary_differential_equations.get_message();
   tests_count += test_ordinary_differential_equations.get_tests_count(); 
   tests_passed_count += test_ordinary_differential_equations.get_tests_passed_count();
   tests_failed_count += test_ordinary_differential_equations.get_tests_failed_count();

   // Test function regression utilities

   TestFunctionRegressionUtilities test_function_regression_utilities;
   test_function_regression_utilities.run_test_case();
   message += test_function_regression_utilities.get_message();
   tests_count += test_function_regression_utilities.get_tests_count(); 
   tests_passed_count += test_function_regression_utilities.get_tests_passed_count();
   tests_failed_count += test_function_regression_utilities.get_tests_failed_count();

   // Test pattern recognition utilities

   TestPatternRecognitionUtilities test_pattern_recognition_utilities;
   test_pattern_recognition_utilities.run_test_case();
   message += test_pattern_recognition_utilities.get_message();
   tests_count += test_pattern_recognition_utilities.get_tests_count(); 
   tests_passed_count += test_pattern_recognition_utilities.get_tests_passed_count();
   tests_failed_count += test_pattern_recognition_utilities.get_tests_failed_count();

   // Test perceptron

   TestPerceptron test_perceptron;
   test_perceptron.run_test_case();
   message += test_perceptron.get_message();
   tests_count += test_perceptron.get_tests_count(); 
   tests_passed_count += test_perceptron.get_tests_passed_count();
   tests_failed_count += test_perceptron.get_tests_failed_count();

   // Test multilayer perceptron

   TestMultilayerPerceptron test_multilayer_perceptron;
   test_multilayer_perceptron.run_test_case();
   message += test_multilayer_perceptron.get_message();
   tests_count += test_multilayer_perceptron.get_tests_count(); 
   tests_passed_count += test_multilayer_perceptron.get_tests_passed_count();
   tests_failed_count += test_multilayer_perceptron.get_tests_failed_count();

   // Test objective functional

   TestObjectiveFunctional test_objective_functional;
   test_objective_functional.run_test_case();
   message += test_objective_functional.get_message();
   tests_count += test_objective_functional.get_tests_count(); 
   tests_passed_count += test_objective_functional.get_tests_passed_count();
   tests_failed_count += test_objective_functional.get_tests_failed_count();

   // Test sum squared error

   TestSumSquaredError test_sum_squared_error;
   test_sum_squared_error.run_test_case();
   message += test_sum_squared_error.get_message();
   tests_count += test_sum_squared_error.get_tests_count(); 
   tests_passed_count += test_sum_squared_error.get_tests_passed_count();
   tests_failed_count += test_sum_squared_error.get_tests_failed_count();

   // Test mean squared error

   TestMeanSquaredError test_mean_squared_error;
   test_mean_squared_error.run_test_case();
   message += test_mean_squared_error.get_message();
   tests_count += test_mean_squared_error.get_tests_count(); 
   tests_passed_count += test_mean_squared_error.get_tests_passed_count();
   tests_failed_count += test_mean_squared_error.get_tests_failed_count();

   // Test root mean squared error

   TestRootMeanSquaredError test_root_mean_squared_error;
   test_root_mean_squared_error.run_test_case();
   message += test_root_mean_squared_error.get_message();
   tests_count += test_root_mean_squared_error.get_tests_count(); 
   tests_passed_count += test_root_mean_squared_error.get_tests_passed_count();
   tests_failed_count += test_root_mean_squared_error.get_tests_failed_count();

   // Test normalized squared error

   TestNormalizedSquaredError test_normalized_squared_error;
   test_normalized_squared_error.run_test_case();
   message += test_normalized_squared_error.get_message();
   tests_count += test_normalized_squared_error.get_tests_count(); 
   tests_passed_count += test_normalized_squared_error.get_tests_passed_count();
   tests_failed_count += test_normalized_squared_error.get_tests_failed_count();

   // Test Minkowski error

   TestMinkowskiError test_Minkowski_error;
   test_Minkowski_error.run_test_case();
   message += test_Minkowski_error.get_message();
   tests_count += test_Minkowski_error.get_tests_count(); 
   tests_passed_count += test_Minkowski_error.get_tests_passed_count();
   tests_failed_count += test_Minkowski_error.get_tests_failed_count();

   // Test training algorithm

   TestTrainingAlgorithm test_training_algorithm;
   test_training_algorithm.run_test_case();
   message += test_training_algorithm.get_message();
   tests_count += test_training_algorithm.get_tests_count(); 
   tests_passed_count += test_training_algorithm.get_tests_passed_count();
   tests_failed_count += test_training_algorithm.get_tests_failed_count();

   // Test random search

   TestRandomSearch test_random_search;
   test_random_search.run_test_case();
   message += test_random_search.get_message();
   tests_count += test_random_search.get_tests_count(); 
   tests_passed_count += test_random_search.get_tests_passed_count();
   tests_failed_count += test_random_search.get_tests_failed_count();

   // Test evolutionary algorithm

   TestEvolutionaryAlgorithm test_evolutionary_algorithm;
   test_evolutionary_algorithm.run_test_case();
   message += test_evolutionary_algorithm.get_message();
   tests_count += test_evolutionary_algorithm.get_tests_count(); 
   tests_passed_count += test_evolutionary_algorithm.get_tests_passed_count();
   tests_failed_count += test_evolutionary_algorithm.get_tests_failed_count();

   // Test gradient descent

   TestGradientDescent test_gradient_descent;
   test_gradient_descent.run_test_case();
   message += test_gradient_descent.get_message();
   tests_count += test_gradient_descent.get_tests_count(); 
   tests_passed_count += test_gradient_descent.get_tests_passed_count();
   tests_failed_count += test_gradient_descent.get_tests_failed_count();

   // Test conjugate gradient

   TestConjugateGradient test_conjugate_gradient;
   test_conjugate_gradient.run_test_case();
   message += test_conjugate_gradient.get_message();
   tests_count += test_conjugate_gradient.get_tests_count(); 
   tests_passed_count += test_conjugate_gradient.get_tests_passed_count();
   tests_failed_count += test_conjugate_gradient.get_tests_failed_count();

   // Test quasi-Newton method

   TestQuasiNewtonMethod test_quasi_Newton_method;
   test_quasi_Newton_method.run_test_case();
   message += test_quasi_Newton_method.get_message();
   tests_count += test_quasi_Newton_method.get_tests_count(); 
   tests_passed_count += test_quasi_Newton_method.get_tests_passed_count();
   tests_failed_count += test_quasi_Newton_method.get_tests_failed_count();

   // Test suite

   std::cout << message << std::endl;

   std::cout << "Flood test suite results: " << std::endl;
   std::cout << "Tests run: " << tests_count << std::endl;
   std::cout << "Tests passed: " << tests_passed_count << std::endl;
   std::cout << "Tests failed: " << tests_failed_count << std::endl;

   if(tests_failed_count == 0)
   {
	   std::cout << "Test OK" << std::endl;
   }
   else
   {
	   std::cout << "Test NOT OK. " << tests_failed_count << " tests failed" << std::endl;
   } 

   return(0);
}  


// Flood: An Open Source Neural Networks C++ Library.
// Copyright (C) 2005-2010 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
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
