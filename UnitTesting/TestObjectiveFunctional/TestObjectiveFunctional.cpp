/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   O B J E C T I V E   F U N C T I O N A L   C L A S S                                              */
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
#include <string>
#include <sstream>
#include <cmath>   

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"

// Unit testing includes

#include "MockObjectiveFunctional.h"
#include "TestObjectiveFunctional.h"

using namespace Flood;


// GENERAL CONSTRUCTOR

TestObjectiveFunctional::TestObjectiveFunctional(void) : UnitTesting() 
{
}


// DESTRUCTOR

TestObjectiveFunctional::~TestObjectiveFunctional(void)
{
}


// METHODS

// void test_constructor(void) method

void TestObjectiveFunctional::test_constructor(void)
{
   message += "test_constructor\n";
}


// void test_destructor(void)

void TestObjectiveFunctional::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_multilayer_perceptron_pointer(void) method

void TestObjectiveFunctional::test_get_multilayer_perceptron_pointer(void)
{
   message += "test_get_multilayer_perceptron_pointer\n";

   MockObjectiveFunctional mof;

   assert_true(mof.get_multilayer_perceptron_pointer() == NULL,	LOG);

   MultilayerPerceptron mlp;

   mof.set_multilayer_perceptron_pointer(&mlp);

   assert_true(mof.get_multilayer_perceptron_pointer() != NULL,	LOG);
}


// void test_get_regularization_method(void) method

void TestObjectiveFunctional::test_get_regularization_method(void)
{
   message += "test_get_regularization_method\n";

   MockObjectiveFunctional mof;

   mof.set_regularization_method(ObjectiveFunctional::None);
   assert_true(mof.get_regularization_method() == ObjectiveFunctional::None,	LOG);

   mof.set_regularization_method(ObjectiveFunctional::NeuralParametersNorm);
   assert_true(mof.get_regularization_method() == ObjectiveFunctional::NeuralParametersNorm,	LOG);   
}


// void test_get_regularization_method_name(void) method

void TestObjectiveFunctional::test_get_regularization_method_name(void)   
{
   message += "test_get_regularization_method_name\n";
}


// void test_get_objective_weight(void) method

void TestObjectiveFunctional::test_get_objective_weight(void)
{
   message += "test_get_objective_weight\n";

   MockObjectiveFunctional mof;

   mof.set_objective_weight(0.0);
   
   assert_true(mof.get_objective_weight() == 0.0, LOG);   
}


// void test_get_regularization_weight(void) method

void TestObjectiveFunctional::test_get_regularization_weight(void)
{
   message += "test_get_regularization_weight\n";

   MockObjectiveFunctional mof;

   mof.set_regularization_weight(0.0);
   
   assert_true(mof.get_regularization_weight() == 0.0, LOG);   
}


// void test_get_numerical_epsilon(void) method

void TestObjectiveFunctional::test_get_numerical_epsilon(void)
{
   message += "test_get_numerical_epsilon\n";

   MockObjectiveFunctional mof;

   mof.set_numerical_epsilon(1.0e-6);

   assert_true(mof.get_numerical_epsilon() == 1.0e-6,	LOG);
}


// void test_get_calculate_evaluation_count(void) method

void TestObjectiveFunctional::test_get_calculate_evaluation_count(void)
{
   message += "test_get_calculate_evaluation_count\n";

   MockObjectiveFunctional mof;

   assert_true(mof.get_calculate_evaluation_count() == 0, LOG);
}


// void test_get_calculate_gradient_count(void) method

void TestObjectiveFunctional::test_get_calculate_gradient_count(void)
{
   message += "test_get_calculate_gradient_count\n";

   MockObjectiveFunctional mof;

   assert_true(mof.get_calculate_gradient_count() == 0, LOG);
}


// void test_get_calculate_Hessian_count(void) method

void TestObjectiveFunctional::test_get_calculate_Hessian_count(void)
{
   message += "test_get_calculate_Hessian_count\n";

   MockObjectiveFunctional mof;

   assert_true(mof.get_calculate_Hessian_count() == 0, LOG);
}


// void test_get_display(void) method

void TestObjectiveFunctional::test_get_display(void)
{
   message += "test_get_display\n";

   MockObjectiveFunctional mof;

   mof.set_display(true);
   assert_true(mof.get_display() == true, LOG);

   mof.set_display(false);
   assert_true(mof.get_display() == false, LOG);
}


// void test_get_numerical_epsilon_method(void) method

void TestObjectiveFunctional::test_get_numerical_epsilon_method(void)
{
   message += "test_get_numerical_epsilon_method\n";

   MockObjectiveFunctional mof;

   mof.set_numerical_epsilon_method(ObjectiveFunctional::Absolute);
   assert_true(mof.get_numerical_epsilon_method() == ObjectiveFunctional::Absolute, LOG);

   mof.set_numerical_epsilon_method(ObjectiveFunctional::Relative);
   assert_true(mof.get_numerical_epsilon_method() == ObjectiveFunctional::Relative, LOG);
}


// void test_get_numerical_epsilon_method_name(void) method

void TestObjectiveFunctional::test_get_numerical_epsilon_method_name(void)
{
   message += "test_get_numerical_epsilon_method_name\n";
}


// void test_get_numerical_differentiation_method(void) method

void TestObjectiveFunctional::test_get_numerical_differentiation_method(void)
{
   message += "test_get_numerical_differentiation_method\n";

   MockObjectiveFunctional mof;

   mof.set_numerical_differentiation_method(ObjectiveFunctional::ForwardDifferences);
   assert_true(mof.get_numerical_differentiation_method() == ObjectiveFunctional::ForwardDifferences, LOG);

   mof.set_numerical_differentiation_method(ObjectiveFunctional::CentralDifferences);
   assert_true(mof.get_numerical_differentiation_method() == ObjectiveFunctional::CentralDifferences, LOG);
}


// void test_get_numerical_differentiation_method_name(void) method

void TestObjectiveFunctional::test_get_numerical_differentiation_method_name(void)
{
   message += "test_get_numerical_differentiation_method_name\n";
}


// void test_set_multilayer_perceptron_pointer(void) method

void TestObjectiveFunctional::test_set_multilayer_perceptron_pointer(void)
{
   message += "test_set_multilayer_perceptron_pointer\n";

   MockObjectiveFunctional mof;

   MultilayerPerceptron mlp;

   mof.set_multilayer_perceptron_pointer(&mlp);

   assert_true(mof.get_multilayer_perceptron_pointer() != NULL, LOG);
}


// void test_set_default(void) method

void TestObjectiveFunctional::test_set_default(void)
{
   message += "test_set_default\n";

   MockObjectiveFunctional mof;

   mof.set_default();
}


// void test_set_regularization_method(void) method

void TestObjectiveFunctional::test_set_regularization_method(void)
{
   message += "test_set_regularization_method\n";

   MockObjectiveFunctional mof;

   mof.set_regularization_method(ObjectiveFunctional::None);
   assert_true(mof.get_regularization_method() == ObjectiveFunctional::None,	LOG);

   mof.set_regularization_method(ObjectiveFunctional::NeuralParametersNorm);
   assert_true(mof.get_regularization_method() == ObjectiveFunctional::NeuralParametersNorm,	LOG);   
}


// void test_set_objective_weight(void) method

void TestObjectiveFunctional::test_set_objective_weight(void)
{
   message += "test_set_objective_weight\n";

   MockObjectiveFunctional mof;

   
   mof.set_objective_weight(1.0);
   assert_true(mof.get_objective_weight() == 1.0, LOG);   
}


// void test_set_regularization_weight(void) method

void TestObjectiveFunctional::test_set_regularization_weight(void)
{
   message += "test_set_regularization_weight\n";

   MockObjectiveFunctional mof;

   mof.set_regularization_weight(1.0);
   
   assert_true(mof.get_regularization_weight() == 1.0, LOG);   
}


// void test_set_numerical_epsilon(void) method

void TestObjectiveFunctional::test_set_numerical_epsilon(void)
{
   message += "test_set_numerical_epsilon\n";

   MockObjectiveFunctional mof;

   mof.set_numerical_epsilon(1.0e-3);

   assert_true(mof.get_numerical_epsilon() == 1.0e-3, LOG);
}


// void test_set_calculate_evaluation_count(void) method

void TestObjectiveFunctional::test_set_calculate_evaluation_count(void)
{
   message += "test_set_calculate_evaluation_count\n";

   MockObjectiveFunctional mof;

   mof.set_calculate_evaluation_count(1);

   assert_true(mof.get_calculate_evaluation_count() == 1, LOG);
}


// void test_set_calculate_gradient_count(void) method

void TestObjectiveFunctional::test_set_calculate_gradient_count(void)
{
   message += "test_set_calculate_gradient_count\n";

   MockObjectiveFunctional mof;

   mof.set_calculate_gradient_count(1);

   assert_true(mof.get_calculate_gradient_count() == 1, LOG);
}


// void test_set_calculate_Hessian_count(void) method

void TestObjectiveFunctional::test_set_calculate_Hessian_count(void)
{
   message += "test_set_calculate_Hessian_count\n";

   MockObjectiveFunctional mof;

   mof.set_calculate_Hessian_count(1);

   assert_true(mof.get_calculate_Hessian_count() == 1, LOG);
}


// void test_set_display(void) method

void TestObjectiveFunctional::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_set_numerical_epsilon_method(void) method

void TestObjectiveFunctional::test_set_numerical_epsilon_method(void)
{
   message += "test_set_numerical_epsilon_method\n";
}


// void test_set_numerical_differentiation_method(void) method

void TestObjectiveFunctional::test_set_numerical_differentiation_method(void)
{
   message += "test_set_numerical_differentiation_method\n";
}


// void test_calculate_evaluation(void) method

void TestObjectiveFunctional::test_calculate_evaluation(void)
{
   message += "test_calculate_evaluation\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   MockObjectiveFunctional mof(&mlp);

   double evaluation = mof.calculate_evaluation();

   assert_true(evaluation == 0.0, LOG);
}


// void test_calculate_potential_evaluation(void) method

void TestObjectiveFunctional::test_calculate_potential_evaluation(void)
{
   message += "test_calculate_potential_evaluation\n";

   MultilayerPerceptron mlp;

   Vector<double> parameters;

   MockObjectiveFunctional mof(&mlp);

   double evaluation;
   double potential_evaluation;

   // Only neural parameters

   mlp.set_network_architecture(1,1,1);
   mlp.set_independent_parameters_number(0);
   
   evaluation = mof.calculate_evaluation();

   parameters = mlp.get_parameters();

   potential_evaluation = mof.calculate_potential_evaluation(parameters);

   assert_true(evaluation == potential_evaluation, LOG);

   // Only independent parameters

   mlp.set_network_architecture(0,0,0);
   mlp.set_independent_parameters_number(1);
   
   evaluation = mof.calculate_evaluation();

   parameters = mlp.get_parameters();

   potential_evaluation = mof.calculate_potential_evaluation(parameters);

   assert_true(evaluation == potential_evaluation, LOG);

   // Both neural and independent parameters

   mlp.set_network_architecture(1,1,1);
   mlp.set_independent_parameters_number(1);
   
   evaluation = mof.calculate_evaluation();

   parameters = mlp.get_parameters();

   potential_evaluation = mof.calculate_potential_evaluation(parameters);

   assert_true(evaluation == potential_evaluation, LOG);
}


// void test_calculate_objective(void) method

void TestObjectiveFunctional::test_calculate_objective(void)
{
   message += "test_calculate_objective\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.set_independent_parameters_number(1);
   
   mlp.initialize_parameters(0.0);

   MockObjectiveFunctional mof(&mlp);

   assert_true(mof.calculate_evaluation() == 0.0, LOG);
}


// void test_calculate_regularization(void) method

void TestObjectiveFunctional::test_calculate_regularization(void)
{
   message += "test_calculate_regularization\n";

   MultilayerPerceptron mlp(1,1,1);
   
   double neural_parameters_norm = mlp.calculate_neural_parameters_norm();
   
   MockObjectiveFunctional mof(&mlp);
   
   mof.set_regularization_method(ObjectiveFunctional::None);
   assert_true(mof.calculate_regularization() == 0.0, LOG);

   mof.set_regularization_method(ObjectiveFunctional::NeuralParametersNorm);
   assert_true(mof.calculate_regularization() == neural_parameters_norm, LOG);
}


// void test_calculate_gradient(void) method

void TestObjectiveFunctional::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_parameters(0.0);

   MockObjectiveFunctional mof(&mlp);
   
   Vector<double> gradient = mof.calculate_gradient();

   assert_true(gradient == 0.0, LOG);
}


// void test_calculate_potential_gradient(void) method

void TestObjectiveFunctional::test_calculate_potential_gradient(void)
{
   message += "test_calculate_potential_gradient\n";
   
   MultilayerPerceptron mlp;

   MockObjectiveFunctional mof(&mlp);

   Vector<double> parameters;

   // Only neural parameters

   mlp.set_network_architecture(1, 1, 1);
   mlp.set_independent_parameters_number(0);

   mlp.initialize_parameters(0.0);

   parameters = mlp.get_parameters();

   assert_true(mof.calculate_potential_gradient(parameters) == 0.0, LOG);

   // Only independent parameters

   mlp.set_network_architecture(0, 0, 0);
   mlp.set_independent_parameters_number(1);

   mlp.initialize_parameters(0.0);

   parameters = mlp.get_parameters();

   assert_true(mof.calculate_potential_gradient(parameters) == 0.0, LOG);

   // Both neural and independent parameters

   mlp.set_network_architecture(1, 1, 1);
   mlp.set_independent_parameters_number(1);

   mlp.initialize_parameters(0.0);

   parameters = mlp.get_parameters();

   assert_true(mof.calculate_potential_gradient(parameters) == 0.0, LOG);
}


// void test_calculate_gradient_norm(void) method

void TestObjectiveFunctional::test_calculate_gradient_norm(void)
{
   message += "test_calculate_gradient_norm\n";
}


// void test_calculate_objective_gradient(void) method

void TestObjectiveFunctional::test_calculate_objective_gradient(void)
{
   message += "test_calculate_objective_gradient\n";
}


// void test_calculate_regularization_gradient(void) method

void TestObjectiveFunctional::test_calculate_regularization_gradient(void)
{
   message += "test_calculate_regularization_gradient\n";

   MultilayerPerceptron mlp(1,1,1);
   
   mlp.initialize_neural_parameters(0.0);
   
   MockObjectiveFunctional mof(&mlp);
   
   mof.set_regularization_method(ObjectiveFunctional::None);
   assert_true(mof.calculate_regularization() == 0.0, LOG);
   assert_true(mof.calculate_regularization() == 0.0, LOG);

   mof.set_regularization_method(ObjectiveFunctional::NeuralParametersNorm);
}


// void test_calculate_neural_parameters_gradient(void) method

void TestObjectiveFunctional::test_calculate_neural_parameters_gradient(void)
{
   message += "test_calculate_neural_parameters_gradient\n";

   MultilayerPerceptron mlp;
   MockObjectiveFunctional mof(&mlp);

   int neural_parameters_number;
   Vector<double> neural_parameters_gradient;

   // Test 

   mlp.set();
   neural_parameters_number = mlp.get_neural_parameters_number();   
   neural_parameters_gradient = mof.calculate_neural_parameters_gradient();
   assert_true(neural_parameters_gradient.get_size() == neural_parameters_number, LOG);

   // Test 

   mlp.set(1,1,1);
   neural_parameters_number = mlp.get_neural_parameters_number();
   neural_parameters_gradient = mof.calculate_neural_parameters_gradient();
   assert_true(neural_parameters_gradient.get_size() == neural_parameters_number, LOG);

   // Test 

   mlp.set(1);
   neural_parameters_number = mlp.get_neural_parameters_number();
   neural_parameters_gradient = mof.calculate_neural_parameters_gradient();
   assert_true(neural_parameters_gradient.get_size() == neural_parameters_number, LOG);

   // Test 

   mlp.set(1,1,1);
   mlp.set_independent_parameters_number(1);
   neural_parameters_number = mlp.get_neural_parameters_number();
   neural_parameters_gradient = mof.calculate_neural_parameters_gradient();
   assert_true(neural_parameters_gradient.get_size() == neural_parameters_number, LOG);
}


// void test_calculate_independent_parameters_gradient(void) method

void TestObjectiveFunctional::test_calculate_independent_parameters_gradient(void)
{
   message += "test_calculate_independent_parameters_gradient\n";

   MultilayerPerceptron mlp;
   MockObjectiveFunctional mof(&mlp);

   int independent_parameters_number;
   Vector<double> independent_parameters_gradient;

   // Test 

   mlp.set();
   independent_parameters_number = mlp.get_independent_parameters_number();   
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

   // Test 

   mlp.set(1,1,1);
   independent_parameters_number = mlp.get_independent_parameters_number();
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

   // Test 

   mlp.set(1);
   independent_parameters_number = mlp.get_independent_parameters_number();
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

   // Test 

   mlp.set(1,1,1);
   mlp.set_independent_parameters_number(1);
   independent_parameters_number = mlp.get_independent_parameters_number();
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

}


// void test_calculate_objective_gradient_numerical_differentiation(void) method

void TestObjectiveFunctional::test_calculate_objective_gradient_numerical_differentiation(void)
{
   message += "test_calculate_objective_gradient_numerical_differentiation\n";
}


// void test_calculate_neural_parameters_gradient_numerical_differentiation(void) method

void TestObjectiveFunctional::test_calculate_neural_parameters_gradient_numerical_differentiation(void)
{
   message += "test_calculate_neural_parameters_gradient_numerical_differentiation\n";
}


// void test_calculate_neural_parameters_gradient_forward_differences(void) method

void TestObjectiveFunctional::test_calculate_neural_parameters_gradient_forward_differences(void)
{
   message += "test_calculate_neural_parameters_gradient_forward_differences\n";
}


// void test_calculate_neural_parameters_gradient_central_differences(void) method

void TestObjectiveFunctional::test_calculate_neural_parameters_gradient_central_differences(void)
{
   message += "test_calculate_neural_parameters_gradient_central_differences\n";
}


// void test_calculate_independent_parameters_gradient_numerical_differentiation(void) method

void TestObjectiveFunctional::test_calculate_independent_parameters_gradient_numerical_differentiation(void)
{
   message += "test_calculate_independent_parameters_gradient_numerical_differentiation\n";
}


// void test_calculate_independent_parameters_gradient_forward_differences(void) method

void TestObjectiveFunctional::test_calculate_independent_parameters_gradient_forward_differences(void)
{
   message += "test_calculate_independent_parameters_gradient_forward_differences\n";

   MultilayerPerceptron mlp;
   MockObjectiveFunctional mof(&mlp);

   int independent_parameters_number;
   Vector<double> independent_parameters_gradient;

   // Test 

   mlp.set();
   independent_parameters_number = mlp.get_independent_parameters_number();   
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient_forward_differences();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

   // Test 

   mlp.set(1,1,1);
   independent_parameters_number = mlp.get_independent_parameters_number();
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient_forward_differences();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

   // Test 

   mlp.set(1);
   independent_parameters_number = mlp.get_independent_parameters_number();
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient_forward_differences();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

}


// void test_calculate_independent_parameters_gradient_central_differences(void) method

void TestObjectiveFunctional::test_calculate_independent_parameters_gradient_central_differences(void)
{
   message += "test_calculate_independent_parameters_gradient_central_differences\n";

   MultilayerPerceptron mlp;
   MockObjectiveFunctional mof(&mlp);

   int independent_parameters_number;
   Vector<double> independent_parameters_gradient;

   // Test 

   mlp.set();
   independent_parameters_number = mlp.get_independent_parameters_number();   
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient_central_differences();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

   // Test 

   mlp.set(1,1,1);
   independent_parameters_number = mlp.get_independent_parameters_number();
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient_central_differences();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);

   // Test 

   mlp.set(1);
   independent_parameters_number = mlp.get_independent_parameters_number();
   independent_parameters_gradient = mof.calculate_independent_parameters_gradient_central_differences();
   assert_true(independent_parameters_gradient.get_size() == independent_parameters_number, LOG);
}


// void test_calculate_Hessian(void) method

void TestObjectiveFunctional::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);

   mlp.initialize_parameters(0.0);

   Matrix<double> Hessian = mof.calculate_Hessian();

   assert_true(Hessian == 2.0, LOG);

   for(int i = 0; i < 3; i++)
   {
      Hessian = mof.calculate_Hessian();
   }

}


// void test_calculate_potential_Hessian(void) method

void TestObjectiveFunctional::test_calculate_potential_Hessian(void)
{
   message += "test_calculate_potential_Hessian\n";

   MultilayerPerceptron mlp;
   int parameters_number;
   Vector<double> parameters;
   
   MockObjectiveFunctional mof(&mlp);
   Matrix<double> potential_Hessian;

   mlp.set_network_architecture(1, 1, 1);
   mlp.set_independent_parameters_number(0);

   mlp.initialize_parameters(0.0);

   parameters_number = mlp.get_parameters_number();
   parameters = mlp.get_parameters();

   potential_Hessian = mof.calculate_potential_Hessian(parameters);

   assert_true(potential_Hessian.get_rows_number() == parameters_number, LOG);
   assert_true(potential_Hessian.get_columns_number() == parameters_number, LOG);

   mlp.set_network_architecture(0, 0, 0);
   mlp.set_independent_parameters_number(1);

   mlp.initialize_parameters(0.0);

   parameters_number = mlp.get_parameters_number();
   parameters = mlp.get_parameters();

   potential_Hessian = mof.calculate_potential_Hessian(parameters);

   assert_true(potential_Hessian.get_rows_number() == parameters_number, LOG);
   assert_true(potential_Hessian.get_columns_number() == parameters_number, LOG);

   mlp.set_network_architecture(1, 1, 1);
   mlp.set_independent_parameters_number(1);

   mlp.initialize_parameters(0.0);

   parameters_number = mlp.get_parameters_number();
   parameters = mlp.get_parameters();

   potential_Hessian = mof.calculate_potential_Hessian(parameters);

   assert_true(potential_Hessian.get_rows_number() == parameters_number, LOG);
   assert_true(potential_Hessian.get_columns_number() == parameters_number, LOG);
}


// void test_calculate_Hessian_numerical_differentiation(void) method

void TestObjectiveFunctional::test_calculate_Hessian_numerical_differentiation(void)
{
   message += "test_calculate_Hessian_numerical_differentiation\n";
}


// void test_calculate_Hessian_forward_differences(void) method

void TestObjectiveFunctional::test_calculate_Hessian_forward_differences(void)
{
   message += "test_calculate_Hessian_forward_differences\n";

}


// void test_calculate_Hessian_central_differences(void) method

void TestObjectiveFunctional::test_calculate_Hessian_central_differences(void)
{
   message += "test_calculate_Hessian_central_differences\n";
}


// void test_calculate_inverse_Hessian(void) method

void TestObjectiveFunctional::test_calculate_inverse_Hessian(void)
{
   message += "test_calculate_inverse_Hessian\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.set_independent_parameters_number(1);

   MockObjectiveFunctional mof(&mlp);

   Matrix<double> Hessian = mof.calculate_Hessian();

   assert_true(mof.calculate_inverse_Hessian() == Hessian.calculate_inverse(), LOG);
}


// void test_calculate_DFP_inverse_Hessian_approximation(void) method

void TestObjectiveFunctional::test_calculate_DFP_inverse_Hessian_approximation(void)
{
   message += "test_calculate_DFP_inverse_Hessian_approximation\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   // Test 

   mlp.initialize_parameters(1.0);

   Vector<double> old_parameters = mlp.get_parameters();
   Vector<double> old_gradient = mof.calculate_gradient();
   Matrix<double> old_inverse_Hessian = mof.calculate_inverse_Hessian();

   mlp.initialize_parameters(-0.5);

   Vector<double> parameters = mlp.get_parameters();
   Vector<double> gradient = mof.calculate_gradient();
   Matrix<double> inverse_Hessian = mof.calculate_inverse_Hessian();

   Matrix<double> DFP_inverse_Hessian 
   = mof.calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

   assert_true(DFP_inverse_Hessian == inverse_Hessian, LOG);

   // Test 

   mlp.initialize_parameters(1.0e-3);

   old_parameters = mlp.get_parameters();
   old_gradient = mof.calculate_gradient();
   old_inverse_Hessian = mof.calculate_inverse_Hessian();

   mlp.initialize_parameters(1.0e-6);

   parameters = mlp.get_parameters();
   gradient = mof.calculate_gradient();
   inverse_Hessian = mof.calculate_inverse_Hessian();

   DFP_inverse_Hessian = mof.calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

   assert_true(DFP_inverse_Hessian == inverse_Hessian, LOG);

   // Test 

   mlp.initialize_parameters(1.0e-6);

   old_parameters = mlp.get_parameters();
   old_gradient = mof.calculate_gradient();
   old_inverse_Hessian = mof.calculate_inverse_Hessian();

   mlp.initialize_parameters(1.0e-9);

   parameters = mlp.get_parameters();
   gradient = mof.calculate_gradient();
   inverse_Hessian = mof.calculate_inverse_Hessian();

   DFP_inverse_Hessian = mof.calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

   assert_true(DFP_inverse_Hessian == inverse_Hessian, LOG);

   // Test 

   old_parameters.initialize(1.0e-3);
   parameters.initialize(1.0e-6);

   old_gradient.initialize(1.0e-3);
   gradient.initialize(1.0e-6);

   old_inverse_Hessian[0][0] = 0.75;
   old_inverse_Hessian[0][1] = -0.25;
   old_inverse_Hessian[1][0] = -0.25;
   old_inverse_Hessian[1][1] = 0.75;

   DFP_inverse_Hessian = mof.calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);
}


// void test_calculate_BFGS_inverse_Hessian_approximation(void) method

void TestObjectiveFunctional::test_calculate_BFGS_inverse_Hessian_approximation(void)
{
   message += "test_calculate_BFGS_inverse_Hessian_approximation\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   mlp.initialize_parameters(1.0);

   Vector<double> old_parameters = mlp.get_parameters();
   Vector<double> old_gradient = mof.calculate_gradient();
   Matrix<double> old_inverse_Hessian = mof.calculate_inverse_Hessian();

   mlp.initialize_parameters(-0.5);

   Vector<double> parameters = mlp.get_parameters();
   Vector<double> gradient = mof.calculate_gradient();
   Matrix<double> inverse_Hessian = mof.calculate_inverse_Hessian();

   Matrix<double> BFGS_inverse_Hessian 
   = mof.calculate_BFGS_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

   assert_true(BFGS_inverse_Hessian == inverse_Hessian, LOG);
}


// void test_calculate_vector_dot_Hessian(void) method

void TestObjectiveFunctional::test_calculate_vector_dot_Hessian(void)
{
   message += "test_calculate_vector_dot_Hessian\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.set_independent_parameters_number(1);

   int parameters_number = mlp.get_parameters_number();

   MockObjectiveFunctional mof(&mlp);

   Vector<double> vector(parameters_number);
   vector.initialize_sequential();

   Matrix<double> Hessian = mof.calculate_Hessian();

   assert_true(mof.calculate_vector_dot_Hessian(vector) == vector.dot(Hessian), LOG);
}


// void test_calculate_vector_dot_Hessian_numerical_differentiation(void) method

void TestObjectiveFunctional::test_calculate_vector_dot_Hessian_numerical_differentiation(void)
{
   message += "test_calculate_vector_dot_Hessian_numerical_differentiation\n";
}


// void test_calculate_vector_dot_Hessian_forward_differences(void) method

void TestObjectiveFunctional::test_calculate_vector_dot_Hessian_forward_differences(void)
{
   message += "test_calculate_vector_dot_Hessian_forward_differences\n";
}


// void test_calculate_vector_dot_Hessian_central_differences(void) method

void TestObjectiveFunctional::test_calculate_vector_dot_Hessian_central_differences(void)
{
   message += "test_calculate_vector_dot_Hessian_central_differences\n";
}


// void test_calculate_validation_error(void) method   

void TestObjectiveFunctional::test_calculate_validation_error(void)   
{
   message += "test_calculate_validation_error\n";

   MockObjectiveFunctional mof;

   double validation_error = mof.calculate_validation_error();

   assert_true(validation_error == 0.0, LOG);
}


// void test_calculate_actual_epsilon(void)

void TestObjectiveFunctional::test_calculate_actual_epsilon(void)
{
   message += "test_calculate_actual_epsilon\n";

   MockObjectiveFunctional mof; 

   double actual_epsilon = mof.calculate_actual_epsilon(1.0);

   assert_true(actual_epsilon == mof.get_numerical_epsilon(), LOG);
}


// void test_to_XML(void) method

void TestObjectiveFunctional::test_to_XML(void)
{
   message += "test_to_XML\n";

   MockObjectiveFunctional mof;

   std::string object = mof.to_XML(true);
}


// void test_print(void) method

void TestObjectiveFunctional::test_print(void)
{
   message += "test_print\n";

   MockObjectiveFunctional mof;

   //mof.print();
}


// void test_save(void) method

void TestObjectiveFunctional::test_save(void)
{
   message += "test_save\n";

   MockObjectiveFunctional mof;

   mof.save("../Data/MockObjectiveFunctional.dat");
}


// void test_load(void) method

void TestObjectiveFunctional::test_load(void)
{
   message += "test_load\n";

   MockObjectiveFunctional mof;

   mof.save("../Data/MockObjectiveFunctional.dat");
   mof.load("../Data/MockObjectiveFunctional.dat");
}


// void test_print_information(void) method

void TestObjectiveFunctional::test_print_information(void)
{
   message += "test_print_information\n";

   MockObjectiveFunctional mof;

   //mof.print_information();
}


// void run_test_case(void) method

void TestObjectiveFunctional::run_test_case(void)
{
   message += "Running objective functional test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_multilayer_perceptron_pointer();

   // Objective term methods 

   test_get_objective_weight();

   // Regularization term methods

   test_get_regularization_method();
   test_get_regularization_method();

   test_get_regularization_weight();

   // Numerical differentiation methods

   test_get_numerical_differentiation_method();
   test_get_numerical_differentiation_method();

   test_get_numerical_epsilon_method();
   test_get_numerical_epsilon_method();

   test_get_numerical_epsilon();

   // Counter methods

   test_get_calculate_evaluation_count();
   test_get_calculate_gradient_count();
   test_get_calculate_Hessian_count();

   test_get_display();

   // Set methods

   test_set_multilayer_perceptron_pointer();

   test_set_default();

   // Objective term methods 

   test_set_objective_weight();

   // Regularization term methods

   test_set_regularization_method();
   test_set_regularization_method();

   test_set_regularization_weight();

   // Numerical differentiation methods

   test_set_numerical_differentiation_method();
   test_set_numerical_differentiation_method();

   test_set_numerical_epsilon_method();
   test_set_numerical_epsilon_method();

   test_set_numerical_epsilon();

   // Counter methods

   test_set_calculate_evaluation_count();
   test_set_calculate_gradient_count();
   test_set_calculate_Hessian_count();

   test_set_display();

   // Objective functional evaluation methods

   test_calculate_evaluation();
   test_calculate_potential_evaluation();

   test_calculate_objective();
   test_calculate_regularization();

   // Objective function gradient methods

   test_calculate_gradient();
   test_calculate_potential_gradient();

   test_calculate_gradient_norm();

   test_calculate_objective_gradient(); 
   test_calculate_regularization_gradient(); 

   test_calculate_neural_parameters_gradient();
   test_calculate_independent_parameters_gradient();

   // Objective function gradient numerical differentiation methods

   test_calculate_objective_gradient_numerical_differentiation(); 

   test_calculate_neural_parameters_gradient_numerical_differentiation();
   test_calculate_neural_parameters_gradient_forward_differences();
   test_calculate_neural_parameters_gradient_central_differences();

   test_calculate_independent_parameters_gradient_numerical_differentiation();
   test_calculate_independent_parameters_gradient_forward_differences();
   test_calculate_independent_parameters_gradient_central_differences();   

   // Objective function Hessian methods

   test_calculate_Hessian();
   test_calculate_potential_Hessian();

   // Objective function Hessian numerical differentiation methods

   test_calculate_Hessian_numerical_differentiation();
   test_calculate_Hessian_forward_differences();
   test_calculate_Hessian_central_differences();

   // Objective function inverse Hessian methods

   test_calculate_inverse_Hessian();

   test_calculate_DFP_inverse_Hessian_approximation();

   test_calculate_BFGS_inverse_Hessian_approximation();

   // Objective function vector Hessian product methods

   test_calculate_vector_dot_Hessian();

   // Objective function vector Hessian product numerical differentiation methods

   test_calculate_vector_dot_Hessian_numerical_differentiation();
   test_calculate_vector_dot_Hessian_forward_differences();
   test_calculate_vector_dot_Hessian_central_differences();

   // Validation error methods

   test_calculate_validation_error();   

   // Numerical epsilon methods

   test_calculate_actual_epsilon();

   // Utility methods

   test_to_XML();

   test_print();
   test_save();
   test_load();

   test_print_information();

   message += "End of objective functional test case...\n";
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
