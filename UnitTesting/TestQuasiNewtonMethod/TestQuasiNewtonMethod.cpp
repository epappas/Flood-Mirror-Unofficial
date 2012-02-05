/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */ 
/*   T E S T   Q U A S I - N E W T O N   M E T H O D    C L A S S                                               */
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
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"


// Unit testing includes

#include "../TestObjectiveFunctional/MockObjectiveFunctional.h"
#include "TestQuasiNewtonMethod.h"


using namespace Flood;


// GENERAL CONSTRUCTOR

TestQuasiNewtonMethod::TestQuasiNewtonMethod(void) : UnitTesting() 
{
}


// DESTRUCTOR

/// Destructor.

TestQuasiNewtonMethod::~TestQuasiNewtonMethod(void)
{

}


// METHODS

// void test_constructor(void) method

void TestQuasiNewtonMethod::test_constructor(void)
{
   message += "test_constructor\n"; 

   MockObjectiveFunctional mof;

   // Default constructor

   QuasiNewtonMethod qnm1; 
   assert_true(qnm1.get_objective_functional_pointer() == NULL, LOG);   

   // Objective functional constructor

   QuasiNewtonMethod qnm2(&mof); 
   assert_true(qnm2.get_objective_functional_pointer() != NULL, LOG);   

}


// void test_destructor(void) method

void TestQuasiNewtonMethod::test_destructor(void)
{
}


// void test_get_inverse_Hessian_approximation_method(void) method

void TestQuasiNewtonMethod::test_get_inverse_Hessian_approximation_method(void)
{
   message += "test_get_inverse_Hessian_approximation_method\n";

   QuasiNewtonMethod qnm;

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::DFP);
   assert_true(qnm.get_inverse_Hessian_approximation_method() == QuasiNewtonMethod::DFP, LOG);

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::BFGS);
   assert_true(qnm.get_inverse_Hessian_approximation_method() == QuasiNewtonMethod::BFGS, LOG);
}



// void test_get_inverse_Hessian_approximation_method_name(void) method

void TestQuasiNewtonMethod::test_get_inverse_Hessian_approximation_method_name(void)
{
   message += "test_get_inverse_Hessian_approximation_method_name\n";
}


// void test_set_inverse_Hessian_approximation_method(void) method

void TestQuasiNewtonMethod::test_set_inverse_Hessian_approximation_method(void)
{
   message += "test_set_training_direction_method\n";

   QuasiNewtonMethod qnm;

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::BFGS);
   assert_true(qnm.get_inverse_Hessian_approximation_method() == QuasiNewtonMethod::BFGS, LOG);
}


// void test_calculate_inverse_Hessian_approximation(void) method

void TestQuasiNewtonMethod::test_calculate_inverse_Hessian_approximation(void)
{
   message += "test_calculate_inverse_Hessian_approximation\n";

   MultilayerPerceptron mlp(2);
   MockObjectiveFunctional mof(&mlp);
   QuasiNewtonMethod qnm(&mof);

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::DFP);

   mlp.initialize_parameters(1.0);

   Vector<double> old_parameters = mlp.get_parameters();
   Vector<double> old_gradient = mof.calculate_gradient();
   Matrix<double> old_inverse_Hessian = mof.calculate_inverse_Hessian();

   mlp.initialize_parameters(-0.5);

   Vector<double> parameters = mlp.get_parameters();
   Vector<double> gradient = mof.calculate_gradient();
   Matrix<double> inverse_Hessian = mof.calculate_inverse_Hessian();

   Matrix<double> inverse_Hessian_approximation
   = qnm.calculate_inverse_Hessian_approximation(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

   assert_true(inverse_Hessian_approximation == inverse_Hessian, LOG);

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::DFP);

   mlp.initialize_parameters(1.0);

   old_parameters = mlp.get_parameters();
   old_gradient = mof.calculate_gradient();
   old_inverse_Hessian = mof.calculate_inverse_Hessian();

   mlp.initialize_parameters(-0.5);

   parameters = mlp.get_parameters();
   gradient = mof.calculate_gradient();
   inverse_Hessian = mof.calculate_inverse_Hessian();

   inverse_Hessian_approximation
   = qnm.calculate_inverse_Hessian_approximation(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

   assert_true(inverse_Hessian_approximation == inverse_Hessian, LOG);

   // Test 

   old_parameters.initialize(1.0e-3);
   parameters.initialize(1.0e-6);

   old_gradient.initialize(1.0e-3);
   gradient.initialize(1.0e-6);

   old_inverse_Hessian[0][0] = 0.75;
   old_inverse_Hessian[0][1] = -0.25;
   old_inverse_Hessian[1][0] = -0.25;
   old_inverse_Hessian[1][1] = 0.75;

   inverse_Hessian_approximation
   = qnm.calculate_inverse_Hessian_approximation(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);
}


// void test_calculate_training_direction(void) method

void TestQuasiNewtonMethod::test_calculate_training_direction(void)
{
   message += "test_calculate_training_direction\n";
}


// void test_train(void) method

void TestQuasiNewtonMethod::test_train(void)
{
   message += "test_train\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   QuasiNewtonMethod qnm(&mof);
   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::DFP);

   mlp.initialize_independent_parameters(1.0);

   double old_evaluation = mof.calculate_evaluation();

   qnm.set_maximum_epochs_number(2),
   qnm.set_display(false);

   qnm.train();

   double evaluation = mof.calculate_evaluation();

   assert_true(evaluation < old_evaluation, LOG);

   // Minimum parameters increment norm

   mlp.initialize_independent_parameters(1.0);

   double minimum_parameters_increment_norm = 0.1;

   qnm.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   qnm.set_evaluation_goal(0.0);
   qnm.set_minimum_evaluation_improvement(0.0);
   qnm.set_gradient_norm_goal(0.0);
   qnm.set_maximum_epochs_number(1000);
   qnm.set_maximum_time(1000.0);

   qnm.train();

   // Evaluation goal

   mlp.initialize_independent_parameters(1.0);

   double evaluation_goal = 0.1;

   qnm.set_minimum_parameters_increment_norm(0.0);
   qnm.set_evaluation_goal(evaluation_goal);
   qnm.set_minimum_evaluation_improvement(0.0);
   qnm.set_gradient_norm_goal(0.0);
   qnm.set_maximum_epochs_number(1000);
   qnm.set_maximum_time(1000.0);

   qnm.train();

   evaluation = mof.calculate_evaluation();

   assert_true(evaluation < evaluation_goal, LOG);

   // Minimum evaluation improvement

   mlp.initialize_independent_parameters(1.0);

   double minimum_evaluation_improvement = 0.1;

   qnm.set_minimum_parameters_increment_norm(0.0);
   qnm.set_evaluation_goal(0.0);
   qnm.set_minimum_evaluation_improvement(minimum_evaluation_improvement);
   qnm.set_gradient_norm_goal(0.0);
   qnm.set_maximum_epochs_number(1000);
   qnm.set_maximum_time(1000.0);

   qnm.train();

   // Gradient norm goal 

   mlp.initialize_independent_parameters(1.0);

   double gradient_norm_goal = 0.1;

   qnm.set_minimum_parameters_increment_norm(0.0);
   qnm.set_evaluation_goal(0.0);
   qnm.set_minimum_evaluation_improvement(0.0);
   qnm.set_gradient_norm_goal(gradient_norm_goal);
   qnm.set_maximum_epochs_number(1000);
   qnm.set_maximum_time(1000.0);

   qnm.train();

   double gradient_norm = mof.calculate_gradient_norm();

   assert_true(gradient_norm < gradient_norm_goal, LOG);

}


// void test_to_XML(void) method

void TestQuasiNewtonMethod::test_to_XML(void)   
{
   message += "test_to_XML\n";
}


// void test_load(void) method

void TestQuasiNewtonMethod::test_load(void)
{
   message += "test_load\n";

   QuasiNewtonMethod qnm;
   qnm.save("../Data/QuasiNewtonMethod.dat");
   qnm.load("../Data/QuasiNewtonMethod.dat");   
}


// void test_resize_training_history(void) method

void TestQuasiNewtonMethod::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   QuasiNewtonMethod qnm;
   qnm.resize_training_history(1);

}


// void test_set_reserve_all_training_history(void) method

void TestQuasiNewtonMethod::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   QuasiNewtonMethod qnm;
   qnm.set_reserve_all_training_history(true);
}


// void test_get_training_history_XML(void) method

void TestQuasiNewtonMethod::test_get_training_history_XML(void)   
{
   message += "test_get_training_history_XML\n";

   MultilayerPerceptron mlp(1);

   MockObjectiveFunctional mof(&mlp);

   QuasiNewtonMethod qnm(&mof);

   qnm.set_maximum_epochs_number(1);
   qnm.set_display(false);

   qnm.train();
   
   std::string training_history_XML = qnm.get_training_history_XML(true);
}


// void run_test_case(void) method

void TestQuasiNewtonMethod::run_test_case(void)
{
   message += "Running quasi-Newton method test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor(); 

   // Get methods

   test_get_inverse_Hessian_approximation_method();
   test_get_inverse_Hessian_approximation_method_name();

   // Set methods

   test_set_inverse_Hessian_approximation_method();

   // Train methods

   test_calculate_inverse_Hessian_approximation();
   test_calculate_training_direction();

   test_train();

   // Training history methods

   test_resize_training_history();

   test_set_reserve_all_training_history();

   test_get_training_history_XML();   

   // Utility methods

   test_to_XML();   
   test_load();

   message += "End of quasi-Newton method test case\n";
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
