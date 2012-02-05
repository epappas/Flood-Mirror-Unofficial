/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   G R A D I E N T   D E S C E N T   C L A S S                                                      */
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
#include <algorithm>
#include <functional>
#include <limits>
#include <cmath>
#include <ctime>

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/TrainingAlgorithm/GradientDescent.h"

// Unit testing includes

#include "../TestObjectiveFunctional/MockObjectiveFunctional.h"
#include "TestGradientDescent.h"

using namespace Flood;


// GENERAL CONSTRUCTOR 

TestGradientDescent::TestGradientDescent(void) : UnitTesting()
{
}


// DESTRUCTOR

TestGradientDescent::~TestGradientDescent(void)
{
}


// METHODS

// void test_constructor(void) method

void TestGradientDescent::test_constructor(void)
{
   message += "test_constructor\n"; 

   MockObjectiveFunctional mof;

   // Default constructor

   GradientDescent gd1; 
   assert_true(gd1.get_objective_functional_pointer() == NULL, LOG);   

   // Objective functional constructor

   GradientDescent gd2(&mof); 
   assert_true(gd2.get_objective_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void TestGradientDescent::test_destructor(void)
{
   message += "test_destructor\n"; 
}


// void test_set_reserve_all_training_history(void) method

void TestGradientDescent::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   GradientDescent gd;

   gd.set_reserve_all_training_history(true);

   assert_true(gd.get_reserve_elapsed_time_history() == true, LOG);
   assert_true(gd.get_reserve_parameters_history() == true, LOG);
   assert_true(gd.get_reserve_parameters_norm_history() == true, LOG);
   assert_true(gd.get_reserve_evaluation_history() == true, LOG);
   assert_true(gd.get_reserve_gradient_history() == true, LOG);
   assert_true(gd.get_reserve_gradient_norm_history() == true, LOG);
   assert_true(gd.get_reserve_inverse_Hessian_history() == false, LOG);
   assert_true(gd.get_reserve_training_direction_history() == true, LOG);
   assert_true(gd.get_reserve_training_rate_history() == true, LOG);
   assert_true(gd.get_reserve_validation_error_history() == true, LOG);
}


// void test_train(void) method

void TestGradientDescent::test_train(void)
{
   message += "test_train\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   GradientDescent gd(&mof);

   mlp.initialize_independent_parameters(-1.0);

   double old_evaluation = mof.calculate_evaluation();

   gd.set_display(false);
   gd.set_maximum_epochs_number(1),
   gd.train();

   double evaluation = mof.calculate_evaluation();

   assert_true(evaluation < old_evaluation, LOG);

   // Minimum parameters increment norm

   mlp.initialize_independent_parameters(1.0);

   double minimum_parameters_increment_norm = 0.1;

   gd.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   gd.set_evaluation_goal(0.0);
   gd.set_minimum_evaluation_improvement(0.0);
   gd.set_gradient_norm_goal(0.0);
   gd.set_maximum_epochs_number(1000);
   gd.set_maximum_time(1000.0);

   gd.train();

   // Evaluation goal

   mlp.initialize_independent_parameters(1.0);

   double evaluation_goal = 0.1;

   gd.set_minimum_parameters_increment_norm(0.0);
   gd.set_evaluation_goal(evaluation_goal);
   gd.set_minimum_evaluation_improvement(0.0);
   gd.set_gradient_norm_goal(0.0);
   gd.set_maximum_epochs_number(1000);
   gd.set_maximum_time(1000.0);

   gd.train();

   evaluation = mof.calculate_evaluation();

   assert_true(evaluation < evaluation_goal, LOG);

   // Minimum evaluation improvement

   mlp.initialize_independent_parameters(1.0);

   double minimum_evaluation_improvement = 0.1;

   gd.set_minimum_parameters_increment_norm(0.0);
   gd.set_evaluation_goal(0.0);
   gd.set_minimum_evaluation_improvement(minimum_evaluation_improvement);
   gd.set_gradient_norm_goal(0.0);
   gd.set_maximum_epochs_number(1000);
   gd.set_maximum_time(1000.0);

   gd.train();

   // Gradient norm goal 

   mlp.initialize_independent_parameters(1.0);

   double gradient_norm_goal = 0.1;

   gd.set_minimum_parameters_increment_norm(0.0);
   gd.set_evaluation_goal(0.0);
   gd.set_minimum_evaluation_improvement(0.0);
   gd.set_gradient_norm_goal(gradient_norm_goal);
   gd.set_maximum_epochs_number(1000);
   gd.set_maximum_time(1000.0);

   gd.train();

   double gradient_norm = mof.calculate_gradient_norm();

   assert_true(gradient_norm < gradient_norm_goal, LOG);
}


// void test_resize_training_history(void) method

void TestGradientDescent::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   GradientDescent gd;

   gd.set_reserve_all_training_history(true);

   gd.resize_training_history(1);

   assert_true(gd.get_parameters_history().get_size() == 1, LOG);
   assert_true(gd.get_parameters_norm_history().get_size() == 1, LOG);

   assert_true(gd.get_evaluation_history().get_size() == 1, LOG);
   assert_true(gd.get_gradient_history().get_size() == 1, LOG);
   assert_true(gd.get_gradient_norm_history().get_size() == 1, LOG);
   assert_true(gd.get_inverse_Hessian_history().get_size() == 0, LOG);
   assert_true(gd.get_validation_error_history().get_size() == 1, LOG);  

   assert_true(gd.get_training_direction_history().get_size() == 1, LOG);
   assert_true(gd.get_training_rate_history().get_size() == 1, LOG);
   assert_true(gd.get_elapsed_time_history().get_size() == 1, LOG);
}


// void test_get_training_history_XML(void) method

void TestGradientDescent::test_get_training_history_XML(void)
{
   message += "test_get_training_history_XML\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   GradientDescent gd(&mof);

   gd.set_maximum_epochs_number(2);

   gd.set_reserve_all_training_history(true);

   gd.set_display(false);

   gd.train();
   
   std::string training_history = gd.get_training_history_XML(true);

   assert_true(training_history.length() != 0, LOG);
}


// void test_to_XML(void) method

void TestGradientDescent::test_to_XML(void)
{
   message += "test_to\n";

   GradientDescent gd;
   std::string object = gd.to_XML(true);
   //std::cout << object;  
}


// void test_load(void) method

void TestGradientDescent::test_load(void)
{
   message += "test_load\n";

   GradientDescent gd;
   gd.save("../Data/GradientDescent.dat");
   gd.load("../Data/GradientDescent.dat");
}


// void run_test_case(void) method

void TestGradientDescent::run_test_case(void)
{
   message += "Running gradient descent test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Set methods

   test_set_reserve_all_training_history();

   // Train methods

   test_train();

   // Training history methods

   test_resize_training_history();
   test_get_training_history_XML();

   // Utility methods

   test_to_XML();
   test_load();

   message += "End of gradient descent test case...\n";
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

