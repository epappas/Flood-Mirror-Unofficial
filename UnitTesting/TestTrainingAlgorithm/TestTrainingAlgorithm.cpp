/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   T R A I N I N G   A L G O R I T H M   C L A S S                                                  */
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

// Unit testing includes

#include "../TestObjectiveFunctional/MockObjectiveFunctional.h"
#include "MockTrainingAlgorithm.h"
#include "TestTrainingAlgorithm.h"


using namespace Flood;


// GENERAL CONSTRUCTOR 

TestTrainingAlgorithm::TestTrainingAlgorithm(void) : UnitTesting() 
{
}


// DESTRUCTOR

TestTrainingAlgorithm::~TestTrainingAlgorithm(void)
{
}


// METHODS


// void test_constructor(void) method

void TestTrainingAlgorithm::test_constructor(void)
{
   message += "test_constructor\n"; 

   MockObjectiveFunctional mof;

   MockTrainingAlgorithm mta1(&mof); 

   assert_true(mta1.get_objective_functional_pointer() != NULL, LOG);   

   MockTrainingAlgorithm mta2; 

   assert_true(mta2.get_objective_functional_pointer() == NULL, LOG);   
}


// void test_destructor(void) method

void TestTrainingAlgorithm::test_destructor(void)
{
   message += "test_destructor\n"; 

   MockTrainingAlgorithm mta; 

   mta.~MockTrainingAlgorithm();
}


// void test_get_objective_functional_pointer(void) method

void TestTrainingAlgorithm::test_get_objective_functional_pointer(void)
{
   message += "test_get_objective_functional_pointer\n"; 
   
   MockTrainingAlgorithm mta;

   ObjectiveFunctional* ofp = mta.get_objective_functional_pointer();

   assert_true(ofp == NULL, LOG);
}


// void test_get_training_rate_method(void) method

void TestTrainingAlgorithm::test_get_training_rate_method(void)
{
   message += "test_get_training_rate_method\n"; 

   MockTrainingAlgorithm mta;

   mta.set_training_rate_method(TrainingAlgorithm::Fixed);
   assert_true(mta.get_training_rate_method() == TrainingAlgorithm::Fixed, LOG);

   mta.set_training_rate_method(TrainingAlgorithm::GoldenSection);
   assert_true(mta.get_training_rate_method() == TrainingAlgorithm::GoldenSection, LOG);

   mta.set_training_rate_method(TrainingAlgorithm::BrentMethod);
   assert_true(mta.get_training_rate_method() == TrainingAlgorithm::BrentMethod, LOG);
}


// void test_get_training_rate_method_name(void) method

void TestTrainingAlgorithm::test_get_training_rate_method_name(void)
{
   message += "test_get_training_rate_method_name\n"; 
}


// void test_get_maximum_time(void) method

void TestTrainingAlgorithm::test_get_maximum_time(void)
{
   message += "test_get_maximum_time\n"; 

   MockTrainingAlgorithm mta;

   mta.set_maximum_time(1.0);

   assert_true(mta.get_maximum_time() == 1.0, LOG);
}


// void test_get_minimum_parameter_increment_norm(void) method

void TestTrainingAlgorithm::test_get_minimum_parameter_increment_norm(void)
{
   message += "test_get_minimum_parameter_increment_norm\n"; 

   MockTrainingAlgorithm mta;

   mta.set_minimum_parameters_increment_norm(0.0);

   assert_true(mta.get_minimum_parameters_increment_norm() == 0.0, LOG);
}


// void test_get_evaluation_goal(void) method

void TestTrainingAlgorithm::test_get_evaluation_goal(void)
{
   message += "test_get_evaluation_goal\n"; 

   MockTrainingAlgorithm mta;

   mta.set_evaluation_goal(0.0);

   double evaluation_goal = mta.get_evaluation_goal();

   assert_true(evaluation_goal == 0.0, LOG);
}


// void test_get_minimum_evaluation_improvement(void) method

void TestTrainingAlgorithm::test_get_minimum_evaluation_improvement(void)
{
   message += "test_get_minimum_evaluation_improvement\n"; 

   MockTrainingAlgorithm mta;

   mta.set_minimum_evaluation_improvement(0.0);

   assert_true(mta.get_minimum_evaluation_improvement() == 0.0, LOG);
}


// void test_get_gradient_norm_goal(void) method

void TestTrainingAlgorithm::test_get_gradient_norm_goal(void)
{
   message += "test_get_gradient_norm_goal\n"; 

   MockTrainingAlgorithm mta;

   mta.set_gradient_norm_goal(0.0);

   double gradient_norm_goal = mta.get_gradient_norm_goal();

   assert_true(gradient_norm_goal == 0.0, LOG);
}


// void test_get_maximum_epochs_number(void) method

void TestTrainingAlgorithm::test_get_maximum_epochs_number(void)
{
   message += "test_get_maximum_epochs_number\n"; 

   MockTrainingAlgorithm mta;

   mta.set_maximum_epochs_number(0);

   assert_true(mta.get_maximum_epochs_number() == 0, LOG);
}


// void test_get_early_stopping(void) method

void TestTrainingAlgorithm::test_get_early_stopping(void)
{
   message += "test_get_early_stopping\n"; 

   MockTrainingAlgorithm mta;

   mta.set_early_stopping(false);

   assert_true(mta.get_early_stopping() == false, LOG);
}


// void test_get_warning_parameters_norm(void) method

void TestTrainingAlgorithm::test_get_warning_parameters_norm(void)
{
   message += "test_get_warning_parameters_norm\n"; 

   MockTrainingAlgorithm mta;

   mta.set_warning_parameters_norm(0.0);

   assert_true(mta.get_warning_parameters_norm() == 0.0, LOG);
}


// void test_get_warning_gradient_norm(void) method

void TestTrainingAlgorithm::test_get_warning_gradient_norm(void)
{
   message += "test_get_warning_gradient_norm\n"; 

   MockTrainingAlgorithm mta;

   mta.set_warning_gradient_norm(0.0);

   assert_true(mta.get_warning_gradient_norm() == 0.0, LOG);
}


// void test_get_display(void) method

void TestTrainingAlgorithm::test_get_display(void)
{
   message += "test_get_warning_gradient_norm\n"; 

   MockTrainingAlgorithm mta;

   mta.set_display(false);

   assert_true(mta.get_display() == false, LOG);
}


// void test_get_display_period(void) method

void TestTrainingAlgorithm::test_get_display_period(void)
{
   message += "test_get_warning_gradient_norm\n"; 

   MockTrainingAlgorithm mta;

   mta.set_display_period(1);

   assert_true(mta.get_display_period() == 1, LOG);
}


// void test_get_first_training_rate(void) method

void TestTrainingAlgorithm::test_get_first_training_rate(void)
{
   message += "test_get_first_training_rate\n"; 

   MockTrainingAlgorithm mta;

   mta.set_first_training_rate(0.0);

   assert_true(mta.get_first_training_rate() == 0.0, LOG);
}


// void test_get_bracketing_factor(void) method

void TestTrainingAlgorithm::test_get_bracketing_factor(void)   
{
   message += "test_get_bracketing_factor\n"; 

   MockTrainingAlgorithm mta;

   mta.set_bracketing_factor(0.0);

   assert_true(mta.get_bracketing_factor() == 0.0, LOG);
}


// void test_get_training_rate_tolerance(void) method

void TestTrainingAlgorithm::test_get_training_rate_tolerance(void)
{
   message += "test_get_training_rate_tolerance\n"; 

   MockTrainingAlgorithm mta;

   mta.set_bracketing_factor(0.0);

   assert_true(mta.get_bracketing_factor() == 0.0, LOG);
}


// void test_get_warning_training_rate(void) method

void TestTrainingAlgorithm::test_get_warning_training_rate(void)
{
   message += "test_get_warning_training_rate\n"; 

   MockTrainingAlgorithm mta;

   mta.set_warning_training_rate(0.0);

   assert_true(mta.get_warning_training_rate() == 0.0, LOG);
}


// void test_get_error_parameters_norm(void) method

void TestTrainingAlgorithm::test_get_error_parameters_norm(void)
{
   message += "test_get_error_parameters_norm\n"; 
}


// void test_get_error_gradient_norm(void) method

void TestTrainingAlgorithm::test_get_error_gradient_norm(void)
{
   message += "test_get_error_gradient_norm\n"; 
}


// void test_get_error_training_rate(void) method

void TestTrainingAlgorithm::test_get_error_training_rate(void)
{
   message += "test_get_error_training_rate\n"; 

   MockTrainingAlgorithm mta;

   mta.set_error_training_rate(0.0);

   assert_true(mta.get_error_training_rate() == 0.0, LOG);
}


// void test_get_reserve_elapsed_time_history(void) method

void TestTrainingAlgorithm::test_get_reserve_elapsed_time_history(void)
{
   message += "test_get_reserve_elapsed_time_history\n"; 

   MockTrainingAlgorithm mta;

   mta.set_reserve_elapsed_time_history(false);

   assert_true(mta.get_reserve_elapsed_time_history() == false, LOG);
}


// void test_get_reserve_parameters_history(void) method

void TestTrainingAlgorithm::test_get_reserve_parameters_history(void)
{
   message += "test_get_reserve_parameters_history\n"; 

   MockTrainingAlgorithm mta;

   mta.set_reserve_parameters_history(false);

   assert_true(mta.get_reserve_parameters_history() == false, LOG);
}


// void test_get_reserve_parameters_norm_history(void) method

void TestTrainingAlgorithm::test_get_reserve_parameters_norm_history(void)
{
   message += "test_get_reserve_parameters_norm_history\n"; 

   MockTrainingAlgorithm mta;

   mta.set_reserve_parameters_norm_history(false);

   assert_true(mta.get_reserve_parameters_norm_history() == false, LOG);
}


// void test_get_reserve_evaluation_history(void) method

void TestTrainingAlgorithm::test_get_reserve_evaluation_history(void)
{
   message += "test_get_reserve_evaluation_history\n"; 

   MockTrainingAlgorithm mta;

   mta.set_reserve_evaluation_history(false);

   assert_true(mta.get_reserve_evaluation_history() == false, LOG);
}


// void test_get_reserve_gradient_history(void) method

void TestTrainingAlgorithm::test_get_reserve_gradient_history(void)
{
   message += "test_get_reserve_gradient_history\n"; 

   MockTrainingAlgorithm mta;

   mta.set_reserve_gradient_history(false);

   assert_true(mta.get_reserve_gradient_history() == false, LOG);
}


// void test_get_reserve_gradient_norm_history(void) method

void TestTrainingAlgorithm::test_get_reserve_gradient_norm_history(void)
{
   message += "test_get_reserve_gradient_norm_history\n"; 

   MockTrainingAlgorithm mta;

   mta.set_reserve_gradient_norm_history(false);

   assert_true(mta.get_reserve_gradient_norm_history() == false, LOG);
}



// void test_get_reserve_validation_error_history(void) method

void TestTrainingAlgorithm::test_get_reserve_validation_error_history(void)
{
   message += "test_get_reserve_validation_error_history\n"; 
}


// void test_get_reserve_training_direction_history(void) method

void TestTrainingAlgorithm::test_get_reserve_training_direction_history(void)
{
   message += "test_get_reserve_training_direction_history\n"; 

   MockTrainingAlgorithm mta;

   mta.set_reserve_training_direction_history(false);

   assert_true(mta.get_reserve_training_direction_history() == false, LOG);
}


// void test_get_reserve_training_rate_history(void) method

void TestTrainingAlgorithm::test_get_reserve_training_rate_history(void)
{
   message += "test_get_reserve_training_rate_history\n"; 

   MockTrainingAlgorithm mta;

   mta.set_reserve_training_rate_history(false);

   assert_true(mta.get_reserve_training_rate_history() == false, LOG);
}


// void test_get_parameters_history(void) method

void TestTrainingAlgorithm::test_get_parameters_history(void)
{
   message += "test_get_parameters_history\n"; 

   MockTrainingAlgorithm mta;

   Vector< Vector<double> > parameters_history = mta.get_parameters_history();

   assert_true(parameters_history.get_size() == 0, LOG);   
}


// void test_get_parameters_norm_history(void) method

void TestTrainingAlgorithm::test_get_parameters_norm_history(void)
{
   message += "test_get_parameters_norm_history\n"; 

   MockTrainingAlgorithm mta;

   Vector<double> parameters_norm_history = mta.get_parameters_norm_history();

   assert_true(parameters_norm_history.get_size() == 0, LOG);   
}


// void test_get_evaluation_history(void) method

void TestTrainingAlgorithm::test_get_evaluation_history(void)
{
   message += "test_get_evaluation_history\n"; 

   MockTrainingAlgorithm mta;

   Vector<double> evaluation_history = mta.get_evaluation_history();

   assert_true(evaluation_history.get_size() == 0, LOG);   
}


// void test_get_gradient_history(void) method

void TestTrainingAlgorithm::test_get_gradient_history(void)
{
   message += "test_get_gradient_history\n"; 

   MockTrainingAlgorithm mta;

   Vector< Vector<double> > gradient_history = mta.get_gradient_history();

   assert_true(gradient_history.get_size() == 0, LOG);   
}


// void test_get_gradient_norm_history(void) method

void TestTrainingAlgorithm::test_get_gradient_norm_history(void)
{
   message += "test_get_gradient_norm_history\n"; 

   MockTrainingAlgorithm mta;

   Vector<double> gradient_norm_history = mta.get_gradient_norm_history();

   assert_true(gradient_norm_history.get_size() == 0, LOG);   
}


// void test_get_inverse_Hessian_history(void) method

void TestTrainingAlgorithm::test_get_inverse_Hessian_history(void)
{
   message += "test_get_inverse_Hessian_history\n"; 
}


// void test_get_validation_error_history(void) method

void TestTrainingAlgorithm::test_get_validation_error_history(void)
{
   message += "test_get_validation_error_history\n"; 
}


// void test_get_elapsed_time_history(void) method

void TestTrainingAlgorithm::test_get_elapsed_time_history(void)
{
   message += "test_get_elapsed_time_history\n"; 

   MockTrainingAlgorithm mta;

   Vector<double> elapsed_time_history = mta.get_elapsed_time_history();

   assert_true(elapsed_time_history.get_size() == 0, LOG);   
}


// void test_get_training_direction_history(void) method

void TestTrainingAlgorithm::test_get_training_direction_history(void)
{
   message += "test_get_training_direction_history\n"; 

   MockTrainingAlgorithm mta;

   Vector< Vector<double> > training_direction_history = mta.get_training_direction_history();

   assert_true(training_direction_history.get_size() == 0, LOG);   
}


// void test_get_training_rate_history(void) method

void TestTrainingAlgorithm::test_get_training_rate_history(void)
{
   message += "test_get_training_rate_history\n"; 

   MockTrainingAlgorithm mta;

   Vector<double> training_rate_history = mta.get_training_rate_history();

   assert_true(training_rate_history.get_size() == 0, LOG);   
}


// void test_set(void) method

void TestTrainingAlgorithm::test_set(void)
{
   message += "test_set\n"; 
}


// void test_set_default(void) method

void TestTrainingAlgorithm::test_set_default(void)
{
   message += "test_set_default\n"; 
}


// void test_set_objective_functional_pointer(void) method

void TestTrainingAlgorithm::test_set_objective_functional_pointer(void)
{
   message += "test_set_objective_functional_pointer\n"; 
}


// void test_set_evaluation_goal(void) method

void TestTrainingAlgorithm::test_set_evaluation_goal(void)
{
   message += "test_set_evaluation_goal\n"; 
}


// void test_set_gradient_norm_goal(void) method

void TestTrainingAlgorithm::test_set_gradient_norm_goal(void)
{
   message += "test_set_gradient_norm_goal\n"; 
}


// void test_set_maximum_time(void) method

void TestTrainingAlgorithm::test_set_maximum_time(void)
{
   message += "test_set_maximum_time\n"; 
}


// void test_set_minimum_parameter_increment_norm(void) method

void TestTrainingAlgorithm::test_set_minimum_parameter_increment_norm(void)
{
   message += "test_set_minimum_parameter_increment_norm\n"; 
}


// void test_set_minimum_evaluation_improvement(void) method

void TestTrainingAlgorithm::test_set_minimum_evaluation_improvement(void)
{
   message += "test_set_minimum_evaluation_improvement\n"; 
}


// void test_set_maximum_epochs_number(void) method

void TestTrainingAlgorithm::test_set_maximum_epochs_number(void)
{
   message += "test_set_maximum_epochs_number\n"; 
}


// void test_set_early_stopping(void) method

void TestTrainingAlgorithm::test_set_early_stopping(void)
{
   message += "test_set_early_stopping\n"; 
}


// void test_set_warning_parameters_norm(void) method

void TestTrainingAlgorithm::test_set_warning_parameters_norm(void)
{
   message += "test_set_warning_parameters_norm\n"; 
}


// void test_set_warning_gradient_norm(void) method

void TestTrainingAlgorithm::test_set_warning_gradient_norm(void)
{
   message += "test_set_warning_gradient_norm\n"; 
}


// void test_set_display(void) method

void TestTrainingAlgorithm::test_set_display(void)
{
   message += "test_set_display\n"; 
}


// void test_set_display_period(void) method

void TestTrainingAlgorithm::test_set_display_period(void)
{
   message += "test_set_display_period\n"; 
}


// void test_set_reserve_parameters_history(void) method

void TestTrainingAlgorithm::test_set_reserve_parameters_history(void)
{
   message += "test_set_reserve_parameters_history\n"; 
}


// void test_set_reserve_parameters_norm_history(void) method

void TestTrainingAlgorithm::test_set_reserve_parameters_norm_history(void)
{
   message += "test_set_reserve_parameters_norm_history\n"; 
}


// void test_set_reserve_evaluation_history(void) method

void TestTrainingAlgorithm::test_set_reserve_evaluation_history(void)
{
   message += "test_set_reserve_evaluation_history\n"; 
}


// void test_set_reserve_gradient_history(void) method

void TestTrainingAlgorithm::test_set_reserve_gradient_history(void)
{
   message += "test_set_reserve_gradient_history\n"; 
}


// void test_set_reserve_gradient_norm_history(void) method

void TestTrainingAlgorithm::test_set_reserve_gradient_norm_history(void)
{
   message += "test_set_reserve_gradient_norm_history\n"; 
}


// void test_set_reserve_inverse_Hessian_history(void) method

void TestTrainingAlgorithm::test_set_reserve_inverse_Hessian_history(void)
{
   message += "test_set_reserve_inverse_Hessian_history\n"; 
}


// void test_set_reserve_elapsed_time_history(void) method

void TestTrainingAlgorithm::test_set_reserve_elapsed_time_history(void)
{
   message += "test_set_reserve_elapsed_time_history\n"; 
}


// void test_set_parameters_history(void) method

void TestTrainingAlgorithm::test_set_parameters_history(void)
{
   message += "test_set_parameters_history\n"; 
}


// void test_set_parameters_norm_history(void) method

void TestTrainingAlgorithm::test_set_parameters_norm_history(void)
{
   message += "test_set_parameters_norm_history\n"; 
}


// void test_set_evaluation_history(void) method

void TestTrainingAlgorithm::test_set_evaluation_history(void)
{
   message += "test_set_evaluation_history\n"; 
}


// void test_set_gradient_history(void) method

void TestTrainingAlgorithm::test_set_gradient_history(void)
{
   message += "test_set_gradient_history\n"; 
}


// void test_set_gradient_norm_history(void) method

void TestTrainingAlgorithm::test_set_gradient_norm_history(void)
{
   message += "test_set_gradient_norm_history\n"; 
}


// void test_set_inverse_Hessian_history(void) method

void TestTrainingAlgorithm::test_set_inverse_Hessian_history(void)
{
   message += "test_set_inverse_Hessian_history\n"; 
}


// void test_set_validation_error_history(void) method

void TestTrainingAlgorithm::test_set_validation_error_history(void)
{
   message += "test_set_validation_error_history\n"; 
}


// void test_set_elapsed_time_history(void) method

void TestTrainingAlgorithm::test_set_elapsed_time_history(void)
{
   message += "test_set_elapsed_time_history\n"; 
}


// void test_set_training_rate_method(void) method

void TestTrainingAlgorithm::test_set_training_rate_method(void)
{
   message += "test_set_training_rate_method\n"; 
}


// void test_set_first_training_rate(void) method

void TestTrainingAlgorithm::test_set_first_training_rate(void)
{
   message += "test_set_first_training_rate\n"; 
}


// void test_set_bracketing_factor(void) method   

void TestTrainingAlgorithm::test_set_bracketing_factor(void)   
{
   message += "test_set_bracketing_factor\n"; 
}


// void test_set_training_rate_tolerance(void) method

void TestTrainingAlgorithm::test_set_training_rate_tolerance(void)
{
   message += "test_set_training_rate_tolerance\n"; 
}


// void test_set_warning_training_rate(void) method

void TestTrainingAlgorithm::test_set_warning_training_rate(void)
{
   message += "test_set_warning_training_rate\n"; 
}


// void test_set_error_parameters_norm(void) method

void TestTrainingAlgorithm::test_set_error_parameters_norm(void)
{
   message += "test_set_error_parameters_norm\n"; 
}


// void test_set_error_gradient_norm(void) method

void TestTrainingAlgorithm::test_set_error_gradient_norm(void)
{
   message += "test_set_error_gradient_norm\n"; 
}


// void test_set_error_training_rate(void) method

void TestTrainingAlgorithm::test_set_error_training_rate(void)
{
   message += "test_set_error_training_rate\n"; 
}



// void test_set_reserve_validation_error_history(void) method

void TestTrainingAlgorithm::test_set_reserve_validation_error_history(void)
{
   message += "test_set_reserve_validation_error_history\n"; 
}


// void test_set_reserve_training_direction_history(void) method

void TestTrainingAlgorithm::test_set_reserve_training_direction_history(void)
{
   message += "test_set_reserve_training_direction_history\n"; 
}


// void test_set_reserve_training_rate_history(void) method

void TestTrainingAlgorithm::test_set_reserve_training_rate_history(void)
{
   message += "test_set_reserve_training_rate_history\n"; 
}


// void test_set_training_direction_history(void) method

void TestTrainingAlgorithm::test_set_training_direction_history(void)
{
   message += "test_set_training_direction_history\n"; 
}


// void test_set_training_rate_history(void) method

void TestTrainingAlgorithm::test_set_training_rate_history(void)
{
   message += "test_set_training_rate_history\n"; 
}


// void test_calculate_training_rate_evaluation(void) method

void TestTrainingAlgorithm::test_calculate_training_rate_evaluation(void)
{
   message += "test_calculate_training_rate_evaluation\n"; 
}


// void test_calculate_fixed_training_rate_evaluation(void) method
//@todo
void TestTrainingAlgorithm::test_calculate_fixed_training_rate_evaluation(void)
{
   message += "test_calculate_fixed_training_rate_evaluation\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   MockTrainingAlgorithm mta(&mof);

   mlp.initialize_independent_parameters(1.0);

   double evaluation = mof.calculate_evaluation();
   Vector<double> gradient = mof.calculate_gradient();

   Vector<double> training_direction = gradient*(-1.0);
   double initial_training_rate = 0.001;

   Vector<double> training_rate_evaluation 
   = mta.calculate_fixed_training_rate_evaluation(evaluation, training_direction, initial_training_rate);
}



// void test_calculate_golden_section_training_rate_evaluation(void) method
//@todo
void TestTrainingAlgorithm::test_calculate_golden_section_training_rate_evaluation(void)
{
   message += "test_calculate_golden_section_training_rate_evaluation\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   MockTrainingAlgorithm mta(&mof);

   mlp.initialize_independent_parameters(1.0);

   double evaluation = mof.calculate_evaluation();
   Vector<double> gradient = mof.calculate_gradient();

   Vector<double> training_direction = gradient*(-1.0);
   double initial_training_rate = 0.001;

   double training_rate_tolerance = 1.0e-6;
   mta.set_training_rate_tolerance(training_rate_tolerance);
  
   Vector<double> training_rate_evaluation 
   = mta.calculate_golden_section_training_rate_evaluation(evaluation, training_direction, initial_training_rate);

   // Training rate assertion


   // Evaluation assertion
}


// void test_calculate_Brent_method_training_rate_evaluation(void) method

void TestTrainingAlgorithm::test_calculate_Brent_method_training_rate_evaluation(void)
{
   message += "test_calculate_Brent_method_training_rate_evaluation\n";
}


// void test_train(void) method

void TestTrainingAlgorithm::test_train(void)
{
   message += "test_train\n";
}


// void test_set_reserve_all_training_history(void) method

void TestTrainingAlgorithm::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   MockTrainingAlgorithm mta;

   mta.set_reserve_all_training_history(true);
}


// void test_resize_training_history(void) method

void TestTrainingAlgorithm::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";
}


// void test_get_training_history_XML(void) method

void TestTrainingAlgorithm::test_get_training_history_XML(void)
{
   message += "test_get_training_history_XML\n";
}



// void test_print_training_history(void) method

void TestTrainingAlgorithm::test_print_training_history(void)
{
   message += "test_print_training_history\n";
}


// void test_save_training_history(void) method

void TestTrainingAlgorithm::test_save_training_history(void)
{
   message += "test_save_training_history\n";
}


// void test_to_XML(void) method

void TestTrainingAlgorithm::test_to_XML(void)
{
   message += "test_to_XML\n";
}
   

// void test_print(void) method

void TestTrainingAlgorithm::test_print(void)
{
   message += "test_print\n";
}


// void test_save(void) method

void TestTrainingAlgorithm::test_save(void)
{
   message += "test_save\n";

   MockTrainingAlgorithm mta;
   mta.save("../Data/MockTrainingAlgorithm.dat");
}


// void test_load(void) method

void TestTrainingAlgorithm::test_load(void)
{
   message += "test_load\n";

   MockTrainingAlgorithm mta;
   mta.save("../Data/MockTrainingAlgorithm.dat");
   mta.load("../Data/MockTrainingAlgorithm.dat");
}



// void run_test_case(void) method

void TestTrainingAlgorithm::run_test_case(void)
{
   message += "Running training algorithm test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_objective_functional_pointer();

   // Training operators

   test_get_training_rate_method();
   test_get_training_rate_method_name();

   // Training parameters

   test_get_first_training_rate();
   test_get_bracketing_factor();   
   test_get_training_rate_tolerance();

   test_get_warning_parameters_norm();
   test_get_warning_gradient_norm();
   test_get_warning_training_rate();

   test_get_error_parameters_norm();
   test_get_error_gradient_norm();
   test_get_error_training_rate();

   // Stopping criteria

   test_get_minimum_parameter_increment_norm();

   test_get_evaluation_goal();
   test_get_minimum_evaluation_improvement();
   test_get_gradient_norm_goal();

   test_get_maximum_epochs_number();
   test_get_maximum_time();

   // Early stopping

   test_get_early_stopping();

   // Reserve training history

   test_get_reserve_parameters_history();
   test_get_reserve_parameters_norm_history();

   test_get_reserve_evaluation_history();
   test_get_reserve_gradient_history();
   test_get_reserve_gradient_norm_history();
   test_get_reserve_validation_error_history();

   test_get_reserve_training_direction_history();
   test_get_reserve_training_rate_history();
   test_get_reserve_elapsed_time_history();

   // Training history

   test_get_parameters_history();
   test_get_parameters_norm_history();

   test_get_evaluation_history();
   test_get_gradient_history();
   test_get_gradient_norm_history();
   test_get_inverse_Hessian_history();
   test_get_validation_error_history();

   test_get_training_direction_history();
   test_get_training_rate_history();
   test_get_elapsed_time_history();

   // Utilities
   
   test_get_display();
   test_get_display_period();

   // Set methods

   test_set();
   test_set_default();   

   test_set_objective_functional_pointer();

   // Training operators

   test_set_training_rate_method();

   // Training parameters

   test_set_first_training_rate();
   test_set_bracketing_factor();   
   test_set_training_rate_tolerance();

   test_set_warning_parameters_norm();
   test_set_warning_gradient_norm();
   test_set_warning_training_rate();

   test_set_error_parameters_norm();
   test_set_error_gradient_norm();
   test_set_error_training_rate();

   // Stopping criteria

   test_set_minimum_parameter_increment_norm();

   test_set_minimum_evaluation_improvement();
   test_set_evaluation_goal();
   test_set_gradient_norm_goal();

   test_set_maximum_epochs_number();
   test_set_maximum_time();

   // Early stopping

   test_set_early_stopping();

   // Reserve training history

   test_set_reserve_parameters_history();
   test_set_reserve_parameters_norm_history();

   test_set_reserve_evaluation_history();
   test_set_reserve_gradient_history();
   test_set_reserve_gradient_norm_history();
   test_set_reserve_inverse_Hessian_history();
   test_set_reserve_validation_error_history();

   test_set_reserve_training_direction_history();
   test_set_reserve_training_rate_history();
   test_set_reserve_elapsed_time_history();

   test_set_reserve_all_training_history();

   // Training history

   test_set_parameters_history();
   test_set_parameters_norm_history();

   test_set_evaluation_history();
   test_set_gradient_history();
   test_set_gradient_norm_history();
   test_set_inverse_Hessian_history();
   test_set_validation_error_history();

   test_set_training_direction_history();
   test_set_training_rate_history();
   test_set_elapsed_time_history();

   // Utilities

   test_set_display();
   test_set_display_period();

   // Train methods

   test_train();

   test_calculate_training_rate_evaluation();
   test_calculate_fixed_training_rate_evaluation();
   test_calculate_golden_section_training_rate_evaluation();
   test_calculate_Brent_method_training_rate_evaluation();

   // Training history methods   

   test_resize_training_history();

   test_get_training_history_XML();   
   test_print_training_history();
   test_save_training_history();

   // Utility methods

   test_to_XML();
   test_print();
   test_save();
   test_load();

   message += "End of training algorithm test case...\n";
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

