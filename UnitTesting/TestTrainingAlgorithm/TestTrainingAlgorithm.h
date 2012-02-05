/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   T R A I N I N G   A L G O R I T H M   C L A S S   H E A D E R                                    */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTTRAININGALGORITHM_H__
#define __TESTTRAININGALGORITHM_H__

#include "../../Flood/Utilities/UnitTesting.h"
 
using namespace Flood;


class TestTrainingAlgorithm : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit TestTrainingAlgorithm(void); 


   // DESTRUCTOR

   virtual ~TestTrainingAlgorithm(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Get methods

   void test_get_objective_functional_pointer(void);

   // Training operators

   void test_get_training_rate_method(void);
   void test_get_training_rate_method_name(void);

   // Training parameters

   void test_get_first_training_rate(void);
   void test_get_bracketing_factor(void);   
   void test_get_training_rate_tolerance(void);

   void test_get_warning_parameters_norm(void);
   void test_get_warning_gradient_norm(void);
   void test_get_warning_training_rate(void);

   void test_get_error_parameters_norm(void);
   void test_get_error_gradient_norm(void);
   void test_get_error_training_rate(void);

   // Stopping criteria

   void test_get_minimum_parameter_increment_norm(void);

   void test_get_minimum_evaluation_improvement(void);
   void test_get_evaluation_goal(void);
   void test_get_gradient_norm_goal(void);

   void test_get_maximum_epochs_number(void);
   void test_get_maximum_time(void);

   // Early stopping

   void test_get_early_stopping(void);

   // Reserve training history

   void test_get_reserve_parameters_history(void);
   void test_get_reserve_parameters_norm_history(void);

   void test_get_reserve_evaluation_history(void);
   void test_get_reserve_gradient_history(void);
   void test_get_reserve_gradient_norm_history(void);
   void test_get_reserve_inverse_Hessian_history(void);
   void test_get_reserve_validation_error_history(void);

   void test_get_reserve_training_direction_history(void);
   void test_get_reserve_training_rate_history(void);
   void test_get_reserve_elapsed_time_history(void);

   // Training history

   void test_get_parameters_history(void);
   void test_get_parameters_norm_history(void);

   void test_get_evaluation_history(void);
   void test_get_gradient_history(void);
   void test_get_gradient_norm_history(void);
   void test_get_inverse_Hessian_history(void);
   void test_get_validation_error_history(void);

   void test_get_training_direction_history(void);
   void test_get_training_rate_history(void);
   void test_get_elapsed_time_history(void);

   // Utilities

   void test_get_display(void);
   void test_get_display_period(void);

   // Set methods

   void test_set(void);
   void test_set_default(void);

   void test_set_objective_functional_pointer(void);

   // Training operators

   void test_set_training_rate_method(void);

   // Training parameters

   void test_set_first_training_rate(void);
   void test_set_bracketing_factor(void);   
   void test_set_training_rate_tolerance(void);

   void test_set_warning_parameters_norm(void);
   void test_set_warning_gradient_norm(void);
   void test_set_warning_training_rate(void);

   void test_set_error_parameters_norm(void);
   void test_set_error_gradient_norm(void);
   void test_set_error_training_rate(void);

   // Stopping criteria

   void test_set_minimum_parameter_increment_norm(void);

   void test_set_minimum_evaluation_improvement(void);
   void test_set_evaluation_goal(void);
   void test_set_gradient_norm_goal(void);

   void test_set_maximum_epochs_number(void);
   void test_set_maximum_time(void);

   // Early stopping

   void test_set_early_stopping(void);

   // Reserve training history

   void test_set_reserve_parameters_history(void);
   void test_set_reserve_parameters_norm_history(void);

   void test_set_reserve_evaluation_history(void);
   void test_set_reserve_gradient_history(void);
   void test_set_reserve_gradient_norm_history(void);
   void test_set_reserve_inverse_Hessian_history(void);
   void test_set_reserve_validation_error_history(void);

   void test_set_reserve_training_direction_history(void);
   void test_set_reserve_training_rate_history(void);
   void test_set_reserve_elapsed_time_history(void);

   void test_set_reserve_all_training_history(void);

   // Training history

   void test_set_parameters_history(void);
   void test_set_parameters_norm_history(void);

   void test_set_evaluation_history(void);
   void test_set_gradient_history(void);
   void test_set_gradient_norm_history(void);
   void test_set_inverse_Hessian_history(void);
   void test_set_validation_error_history(void);

   void test_set_training_direction_history(void);
   void test_set_training_rate_history(void);
   void test_set_elapsed_time_history(void);

    // Utilities

   void test_set_display(void);
   void test_set_display_period(void);

   // Train methods

   void test_train(void);

   void test_calculate_training_rate_evaluation(void);
   void test_calculate_fixed_training_rate_evaluation(void);
   void test_calculate_golden_section_training_rate_evaluation(void);
   void test_calculate_Brent_method_training_rate_evaluation(void);

   // Training history methods
   
   void test_resize_training_history(void);

   void test_get_training_history_XML(void);
   void test_print_training_history(void);
   void test_save_training_history(void);

   // Utility methods

   void test_to_XML(void);

   void test_print(void);
   void test_save(void);
   void test_load(void);

   // Unit testing methods

   void run_test_case(void);

};


#endif


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

