/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   C O N J U G A T E   G R A D I E N T   C L A S S                                                  */
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

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/TrainingAlgorithm/ConjugateGradient.h"


// Unit testing includes

#include "../TestObjectiveFunctional/MockObjectiveFunctional.h"
#include "TestConjugateGradient.h"


using namespace Flood;

// GENERAL CONSTRUCTOR

TestConjugateGradient::TestConjugateGradient(void) : UnitTesting() 
{
}


// DESTRUCTOR

TestConjugateGradient::~TestConjugateGradient(void)
{
}


// METHODS

// void test_constructor(void) method

void TestConjugateGradient::test_constructor(void)
{
   message += "test_constructor\n"; 

   MockObjectiveFunctional mof;

   // Default constructor

   ConjugateGradient cg1; 
   assert_true(cg1.get_objective_functional_pointer() == NULL, LOG);   

   // Objective functional constructor

   ConjugateGradient cg2(&mof); 
   assert_true(cg2.get_objective_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void TestConjugateGradient::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_training_direction_method(void) method

void TestConjugateGradient::test_get_training_direction_method(void)
{
   message += "test_get_training_direction_method\n";

   ConjugateGradient cg;

   cg.set_training_direction_method(ConjugateGradient::PolakRibiere);

   ConjugateGradient::TrainingDirectionMethod training_direction_method = cg.get_training_direction_method();

   assert_true(training_direction_method == ConjugateGradient::PolakRibiere, LOG);
}


// void test_get_training_direction_method_name(void)

void TestConjugateGradient::test_get_training_direction_method_name(void)
{
   message += "test_get_training_direction_method_name\n";
}


// void test_set_training_direction_method(void) method

void TestConjugateGradient::test_set_training_direction_method(void)
{
   message += "test_set_training_direction_method\n";

   ConjugateGradient cg;

   cg.set_training_direction_method(ConjugateGradient::FletcherReeves);
   assert_true(cg.get_training_direction_method() == ConjugateGradient::FletcherReeves, LOG);

   cg.set_training_direction_method(ConjugateGradient::PolakRibiere);
   assert_true(cg.get_training_direction_method() == ConjugateGradient::PolakRibiere, LOG);
}


// void test_set_reserve_all_training_history(void) method

void TestConjugateGradient::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   ConjugateGradient cg;
   cg.set_reserve_all_training_history(true);

   assert_true(cg.get_reserve_parameters_history() == true, LOG);
   assert_true(cg.get_reserve_parameters_norm_history() == true, LOG);

   assert_true(cg.get_reserve_evaluation_history() == true, LOG);
   assert_true(cg.get_reserve_gradient_history() == true, LOG);
   assert_true(cg.get_reserve_gradient_norm_history() == true, LOG);
   assert_true(cg.get_reserve_inverse_Hessian_history() == false, LOG);

   assert_true(cg.get_reserve_training_direction_history() == true, LOG);
   assert_true(cg.get_reserve_training_rate_history() == true, LOG);
   assert_true(cg.get_reserve_elapsed_time_history() == true, LOG);
   assert_true(cg.get_reserve_validation_error_history() == true, LOG);
}


// void test_calculate_Polak_Ribiere_parameter(void) method
//@todo
void TestConjugateGradient::test_calculate_Polak_Ribiere_parameter(void)
{
   message += "test_calculate_Polak_Ribiere_parameter\n";

   MultilayerPerceptron mlp(2);
   MockObjectiveFunctional mof(&mlp);
   ConjugateGradient cg(&mof);

   mlp.initialize_independent_parameters(2.0);
   Vector<double> old_gradient = mof.calculate_gradient();

   mlp.initialize_independent_parameters(1.0);
   Vector<double> gradient = mof.calculate_gradient();

   double Polak_Ribiere_parameter = cg.calculate_Polak_Ribiere_parameter(old_gradient, gradient);

   assert_true(Polak_Ribiere_parameter == 0.0, LOG);
}


// void test_calculate_Fletcher_Reeves_parameter(void) method
//@todo
void TestConjugateGradient::test_calculate_Fletcher_Reeves_parameter(void)
{
   message += "test_calculate_Fletcher_Reeves_parameter\n";

   MultilayerPerceptron mlp(2);
   MockObjectiveFunctional mof(&mlp);
   ConjugateGradient cg(&mof);

   mlp.initialize_independent_parameters(2.0);
   Vector<double> old_gradient = mof.calculate_gradient();

   mlp.initialize_independent_parameters(1.0);
   Vector<double> gradient = mof.calculate_gradient();

   double Fletcher_Reeves_parameter = cg.calculate_Fletcher_Reeves_parameter(old_gradient, gradient);

   assert_true(Fletcher_Reeves_parameter == 0.25, LOG);
}


// void test_calculate_Polak_Ribiere_training_direction(void) method

void TestConjugateGradient::test_calculate_Polak_Ribiere_training_direction(void)
{
   message += "test_calculate_Polak_Ribiere_training_direction\n";

   MultilayerPerceptron mlp(2);
   MockObjectiveFunctional mof(&mlp);
   ConjugateGradient cg(&mof);

   mlp.initialize_independent_parameters(2.0);
   Vector<double> old_gradient = mof.calculate_gradient();
   Vector<double> old_training_direction = old_gradient;   

   mlp.initialize_independent_parameters(1.0);
   Vector<double> gradient = mof.calculate_gradient();

   Vector<double> Polak_Ribiere_training_direction 
   = cg.calculate_Polak_Ribiere_training_direction(old_gradient, gradient, old_training_direction);
}


// void test_calculate_Fletcher_Reeves_training_direction(void) method

void TestConjugateGradient::test_calculate_Fletcher_Reeves_training_direction(void)
{
   message += "test_calculate_Fletcher_Reeves_training_direction\n";

   MultilayerPerceptron mlp(2);
   MockObjectiveFunctional mof(&mlp);
   ConjugateGradient cg(&mof);

   mlp.initialize_independent_parameters(2.0);
   Vector<double> old_gradient = mof.calculate_gradient();
   Vector<double> old_training_direction = old_gradient;   

   mlp.initialize_independent_parameters(1.0);
   Vector<double> gradient = mof.calculate_gradient();
	
   Vector<double> Fletcher_Reeves_training_direction 
   = cg.calculate_Fletcher_Reeves_training_direction(old_gradient, gradient, old_training_direction);
}


// void test_calculate_training_direction(void) method

void TestConjugateGradient::test_calculate_training_direction(void)
{
   message += "test_calculate_training_direction\n";

}


// void test_train(void) method

void TestConjugateGradient::test_train(void)
{
   message += "test_train\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   ConjugateGradient cg(&mof);

   mlp.initialize_independent_parameters(-1.0);

   double old_evaluation = mof.calculate_evaluation();

   cg.set_display(false);
   cg.set_maximum_epochs_number(1),
   cg.train();

   double evaluation = mof.calculate_evaluation();

   assert_true(evaluation < old_evaluation, LOG);

   // Minimum parameters increment norm

   mlp.initialize_independent_parameters(1.0);

   double minimum_parameters_increment_norm = 0.1;

   cg.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   cg.set_evaluation_goal(0.0);
   cg.set_minimum_evaluation_improvement(0.0);
   cg.set_gradient_norm_goal(0.0);
   cg.set_maximum_epochs_number(1000);
   cg.set_maximum_time(1000.0);

   cg.train();

   // Evaluation goal

   mlp.initialize_independent_parameters(1.0);

   double evaluation_goal = 0.1;

   cg.set_minimum_parameters_increment_norm(0.0);
   cg.set_evaluation_goal(evaluation_goal);
   cg.set_minimum_evaluation_improvement(0.0);
   cg.set_gradient_norm_goal(0.0);
   cg.set_maximum_epochs_number(1000);
   cg.set_maximum_time(1000.0);

   cg.train();

   evaluation = mof.calculate_evaluation();

   assert_true(evaluation < evaluation_goal, LOG);

   // Minimum evaluation improvement

   mlp.initialize_independent_parameters(1.0);

   double minimum_evaluation_improvement = 0.1;

   cg.set_minimum_parameters_increment_norm(0.0);
   cg.set_evaluation_goal(0.0);
   cg.set_minimum_evaluation_improvement(minimum_evaluation_improvement);
   cg.set_gradient_norm_goal(0.0);
   cg.set_maximum_epochs_number(1000);
   cg.set_maximum_time(1000.0);

   cg.train();

   // Gradient norm goal 

   mlp.initialize_independent_parameters(1.0);

   double gradient_norm_goal = 0.1;

   cg.set_minimum_parameters_increment_norm(0.0);
   cg.set_evaluation_goal(0.0);
   cg.set_minimum_evaluation_improvement(0.0);
   cg.set_gradient_norm_goal(gradient_norm_goal);
   cg.set_maximum_epochs_number(1000);
   cg.set_maximum_time(1000.0);

   cg.train();

   double gradient_norm = mof.calculate_gradient_norm();

   assert_true(gradient_norm < gradient_norm_goal, LOG);
}


// void test_resize_training_history(void) method

void TestConjugateGradient::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   ConjugateGradient cg;

   cg.set_reserve_all_training_history(true);

   cg.resize_training_history(1);

   assert_true(cg.get_parameters_history().get_size() == 1, LOG);
   assert_true(cg.get_parameters_norm_history().get_size() == 1, LOG);

   assert_true(cg.get_evaluation_history().get_size() == 1, LOG);
   assert_true(cg.get_gradient_history().get_size() == 1, LOG);
   assert_true(cg.get_gradient_norm_history().get_size() == 1, LOG);
   assert_true(cg.get_inverse_Hessian_history().get_size() == 0, LOG);
   assert_true(cg.get_validation_error_history().get_size() == 1, LOG);  

   assert_true(cg.get_training_direction_history().get_size() == 1, LOG);
   assert_true(cg.get_training_rate_history().get_size() == 1, LOG);
   assert_true(cg.get_elapsed_time_history().get_size() == 1, LOG);
}


// void test_get_training_history_XML(void) method

void TestConjugateGradient::test_get_training_history_XML(void)
{
   message += "test_get_training_history_XML\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   ConjugateGradient cg(&mof);

   cg.set_maximum_epochs_number(2);

   cg.set_reserve_all_training_history(true);

   cg.set_display(false);

   cg.train();
   
   std::string training_history = cg.get_training_history_XML(true);
}


// void test_to_XML(void) method   

void TestConjugateGradient::test_to_XML(void)   
{
   message += "test_to\n";

   ConjugateGradient cg;
   std::string object = cg.to_XML(true);
   //std::cout << object;
}


// void test_load(void) method

void TestConjugateGradient::test_load(void)
{
   message += "test_load\n";

   ConjugateGradient cg;
   cg.save("../Data/ConjugateGradient.dat");
   cg.load("../Data/ConjugateGradient.dat");
}


// void run_test_case(void) method

void TestConjugateGradient::run_test_case(void)
{
   message += "Running conjugate gradient test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_training_direction_method();
   test_get_training_direction_method_name();

   // Set methods

   test_set_training_direction_method();

   // Train methods

   test_calculate_Polak_Ribiere_parameter();
   test_calculate_Fletcher_Reeves_parameter();

   test_calculate_Fletcher_Reeves_training_direction();
   test_calculate_Polak_Ribiere_training_direction();

   test_calculate_training_direction();

   test_train();

   // Training history methods

   test_set_reserve_all_training_history();
   test_resize_training_history();
   test_get_training_history_XML();

   // Utility methods

   test_to_XML();   
   test_load();

   message += "End of conjugate gradient test case\n";
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
