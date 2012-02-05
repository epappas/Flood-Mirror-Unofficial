/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   N E W T O N   M E T H O D   C L A S S                                                            */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/TrainingAlgorithm/NewtonMethod.h"

// Unit testing includes

#include "../TestObjectiveFunctional/MockObjectiveFunctional.h"
#include "TestNewtonMethod.h"

using namespace Flood;


// GENERAL CONSTRUCTOR

TestNewtonMethod::TestNewtonMethod(void) : UnitTesting() 
{   
}


// DESTRUCTOR

TestNewtonMethod::~TestNewtonMethod(void)
{
}


// void test_constructor(void) method

void TestNewtonMethod::test_constructor(void)
{
   message += "test_constructor\n"; 

   MockObjectiveFunctional mof;

   // Default constructor

   NewtonMethod nm1; 
   assert_true(nm1.get_objective_functional_pointer() == NULL, LOG);   

   // Objective functional constructor

   NewtonMethod nm2(&mof); 
   assert_true(nm2.get_objective_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void TestNewtonMethod::test_destructor(void)
{
   message += "test_destructor\n";

   NewtonMethod nm;

   nm.~NewtonMethod();
}


// void test_train(void) method

void TestNewtonMethod::test_train(void)
{
   message += "test_train\n";

   MultilayerPerceptron mlp(2);
   MockObjectiveFunctional mof(&mlp);
   NewtonMethod nm(&mof);

   mlp.initialize_independent_parameters(0.1);

   double old_evaluation = mof.calculate_evaluation();

   nm.set_display(false);
   nm.set_maximum_epochs_number(1);
   nm.train();

   double evaluation = mof.calculate_evaluation();
   
   assert_true(evaluation < old_evaluation, LOG);

   // Minimum parameters increment norm

   mlp.initialize_independent_parameters(1.0);

   double minimum_parameters_increment_norm = 0.1;

   nm.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   nm.set_evaluation_goal(0.0);
   nm.set_minimum_evaluation_improvement(0.0);
   nm.set_gradient_norm_goal(0.0);
   nm.set_maximum_epochs_number(1000);
   nm.set_maximum_time(1000.0);

   nm.train();

   // Evaluation goal

   mlp.initialize_independent_parameters(1.0);

   double evaluation_goal = 0.1;

   nm.set_minimum_parameters_increment_norm(0.0);
   nm.set_evaluation_goal(evaluation_goal);
   nm.set_minimum_evaluation_improvement(0.0);
   nm.set_gradient_norm_goal(0.0);
   nm.set_maximum_epochs_number(1000);
   nm.set_maximum_time(1000.0);

   nm.train();

   evaluation = mof.calculate_evaluation();

   assert_true(evaluation < evaluation_goal, LOG);

   // Minimum evaluation improvement

   mlp.initialize_independent_parameters(1.0);

   double minimum_evaluation_improvement = 0.1;

   nm.set_minimum_parameters_increment_norm(0.0);
   nm.set_evaluation_goal(0.0);
   nm.set_minimum_evaluation_improvement(minimum_evaluation_improvement);
   nm.set_gradient_norm_goal(0.0);
   nm.set_maximum_epochs_number(1000);
   nm.set_maximum_time(1000.0);

   nm.train();

   // Gradient norm goal 

   mlp.initialize_independent_parameters(1.0);

   double gradient_norm_goal = 0.1;

   nm.set_minimum_parameters_increment_norm(0.0);
   nm.set_evaluation_goal(0.0);
   nm.set_minimum_evaluation_improvement(0.0);
   nm.set_gradient_norm_goal(gradient_norm_goal);
   nm.set_maximum_epochs_number(1000);
   nm.set_maximum_time(1000.0);

   nm.train();

   double gradient_norm = mof.calculate_gradient_norm();

   assert_true(gradient_norm < gradient_norm_goal, LOG);

}


// void test_to_XML(void) method

void TestNewtonMethod::test_to_XML(void)
{
   message += "test_to\n";

   NewtonMethod nm;
   std::string object = nm.to_XML(true);
   //std::cout << object;
}


// void test_load(void) method

void TestNewtonMethod::test_load(void)
{
   message += "test_load\n";

   NewtonMethod nm;
   nm.save("../Data/NewtonMethod.dat");
   nm.load("../Data/NewtonMethod.dat");
}


// void test_resize_training_history(void) method

void TestNewtonMethod::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   NewtonMethod nm;

   nm.set_reserve_all_training_history(true);

   nm.resize_training_history(1);

   assert_true(nm.get_parameters_history().get_size() == 1, LOG);
   assert_true(nm.get_parameters_norm_history().get_size() == 1, LOG);

   assert_true(nm.get_evaluation_history().get_size() == 1, LOG);
   assert_true(nm.get_gradient_history().get_size() == 1, LOG);
   assert_true(nm.get_gradient_norm_history().get_size() == 1, LOG);
   assert_true(nm.get_inverse_Hessian_history().get_size() == 1, LOG);
   assert_true(nm.get_validation_error_history().get_size() == 1, LOG);  

   assert_true(nm.get_training_direction_history().get_size() == 1, LOG);
   assert_true(nm.get_training_rate_history().get_size() == 1, LOG);
   assert_true(nm.get_elapsed_time_history().get_size() == 1, LOG);

}


// void test_set_reserve_all_training_history(void) method

void TestNewtonMethod::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   NewtonMethod nm;
   nm.set_reserve_all_training_history(true);

   assert_true(nm.get_reserve_parameters_history() == true, LOG);
   assert_true(nm.get_reserve_parameters_norm_history() == true, LOG);

   assert_true(nm.get_reserve_evaluation_history() == true, LOG);
   assert_true(nm.get_reserve_gradient_history() == true, LOG);
   assert_true(nm.get_reserve_gradient_norm_history() == true, LOG);
   assert_true(nm.get_reserve_inverse_Hessian_history() == true, LOG);

   assert_true(nm.get_reserve_training_direction_history() == true, LOG);
   assert_true(nm.get_reserve_training_rate_history() == true, LOG);
   assert_true(nm.get_reserve_elapsed_time_history() == true, LOG);
   assert_true(nm.get_reserve_validation_error_history() == true, LOG);
}


// void test_get_training_history_XML(void) method

void TestNewtonMethod::test_get_training_history_XML(void)
{
   MultilayerPerceptron mlp(1);

   MockObjectiveFunctional mof(&mlp);

   NewtonMethod nm(&mof);

   nm.set_maximum_epochs_number(1);

   nm.set_reserve_all_training_history(true);

   nm.set_display(false);

   nm.train();
   
   std::string training_history = nm.get_training_history_XML(true);
   //std::cout << training_history;
}


// void run_test_case(void) method

void TestNewtonMethod::run_test_case(void)
{
   message += "Running Newton method test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Train methods

   test_train();

   // Training history methods

   test_resize_training_history();
   test_set_reserve_all_training_history();
   test_get_training_history_XML();

   // Utility methods

   test_to_XML();
   test_load();

   message += "End of Newton method test case...\n";
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
