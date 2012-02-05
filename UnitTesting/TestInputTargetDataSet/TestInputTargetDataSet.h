/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   I N P U T - T A R G E T   D A T A   S E T   C L A S S   H E A D E R                              */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTINPUTTARGETDATASET_H__
#define __TESTINPUTTARGETDATASET_H__

#include <string>

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;

class TestInputTargetDataSet : public UnitTesting 
{

#define STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:  

   // GENERAL CONSTRUCTOR

   explicit TestInputTargetDataSet(void);


   // DESTRUCTOR

   virtual ~TestInputTargetDataSet(void);
    // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);

   // Get methods

   void test_get_instances_number(void);
   void test_get_variables_number(void);

   // Instances methods 

   void test_get_training_instances_number(void);
   void test_get_training_instances_indices(void);

   void test_get_validation_instances_number(void);
   void test_get_validation_instances_indices(void);

   void test_get_testing_instances_number(void);
   void test_get_testing_instances_indices(void);

   // Variables methods

   void test_get_input_variables_number(void);
   void test_get_input_variables_indices(void);

   void test_get_target_variables_number(void);
   void test_get_target_variables_indices(void);

   // Information methods 

   void test_get_variables_name(void);
   void test_get_variable_name(void);

   void test_get_input_variables_name(void);
   void test_get_target_variables_name(void);

   void test_get_variables_units(void);
   void test_get_variable_units(void);

   void test_get_input_variables_units(void);
   void test_get_target_variables_units(void);

   void test_get_variables_description(void);
   void test_get_variable_description(void);

   void test_get_input_variables_description(void);
   void test_get_target_variables_description(void);

   void test_get_variables_information(void);

   void test_get_display(void);

   // Data methods

   void test_get_data(void);

   void test_get_training_data(void);
   void test_get_validation_data(void);
   void test_get_testing_data(void);

   void test_get_input_data(void);
   void test_get_target_data(void);
  
   // Instance methods

   void test_get_instance(void);

   void test_get_training_instance(void);
   void test_get_validation_instance(void);
   void test_get_testing_instance(void);

   void test_get_input_instance(void);
   void test_get_target_instance(void);

   void test_get_training_input_instance(void);
   void test_get_training_target_instance(void);

   void test_get_validation_input_instance(void);
   void test_get_validation_target_instance(void);

   void test_get_testing_input_instance(void); 
   void test_get_testing_target_instance(void);

   // Set methods

   void test_set(void);

   void test_set_instances_number(void);
   void test_set_variables_number(void);

   // Instances methods

   void test_set_training_instances_indices(void);
   void test_set_validation_instances_indices(void);
   void test_set_testing_instances_indices(void);

   void test_set_training(void);
   void test_set_validation(void);
   void test_set_testing(void);

   // Variables methods

   void test_set_input_variables_indices(void);
   void test_set_target_variables_indices(void);

   void test_set_input(void);
   void test_set_target(void);

   // Information methods

   void test_set_variables_name(void);
   void test_set_variable_name(void);

   void test_set_variables_units(void);
   void test_set_variable_units(void);

   void test_set_variables_description(void);
   void test_set_variable_description(void);

   void test_set_display(void);

   // Data methods

   void test_set_data(void);

   // Instance methods

   void test_set_instance(void);

   void test_set_training_instance(void);
   void test_set_validation_instance(void);
   void test_set_testing_instance(void);

   void test_set_input_instance(void);
   void test_set_target_instance(void);

   void test_set_training_input_instance(void);
   void test_set_training_target_instance(void);

   void test_set_validation_input_instance(void); 
   void test_set_validation_target_instance(void);

   void test_set_testing_input_instance(void);
   void test_set_testing_target_instance(void);

   // Data resizing methods

   void test_add_instance(void);
   void test_subtract_instance(void); 

   // Data splitting methods

   void test_split_given_indices(void);
   void test_split_random_indices(void);

   // Initialization methods

   void test_initialize_data(void);

   // Statistics methods

   void test_calculate_data_statistics(void);

   void test_calculate_training_instances_statistics(void);
   void test_calculate_validation_instances_statistics(void);
   void test_calculate_testing_instances_statistics(void);

   void test_calculate_instances_statistics(void);

   void test_calculate_input_variables_statistics(void);
   void test_calculate_target_variables_statistics(void);

   void test_calculate_variables_statistics(void);

   // Data scaling

   void test_scale_data_mean_standard_deviation(void);  
   void test_scale_data_minimum_maximum(void); 

   // Input variables scaling

   void test_scale_input_variables_mean_standard_deviation(void);
   void test_scale_input_variables_minimum_maximum(void);

   // Target variables scaling

   void test_scale_target_variables_mean_standard_deviation(void);
   void test_scale_target_variables_minimum_maximum(void);

   // Input-target variables scaling

   void test_scale_variables_mean_standard_deviation(void);
   void test_scale_variables_minimum_maximum(void);

   // Data unscaling

   void test_unscale_data_mean_standard_deviation(void);
   void test_unscale_data_minimum_maximum(void);

   // Input variables unscaling

   void test_unscale_input_variables_mean_standard_deviation(void);
   void test_unscale_input_variables_minimum_maximum(void);

   // Target variables unscaling

   void test_unscale_target_variables_mean_standard_deviation(void);
   void test_unscale_target_variables_minimum_maximum(void);

   // Input-target variables unscaling

   void test_unscale_variables_mean_standard_deviation(void);
   void test_unscale_variables_minimum_maximum(void);

   // Utility methods

   void test_to_XML(void);

   void test_print(void);
   void test_save(void);
   void test_load(void);

   void test_print_data(void);
   void test_save_data(void);
   void test_load_data(void);

   void test_get_instances_information(void);
   void test_print_instances_information(void);
   void test_save_instances_information(void);

   void test_get_variables_information_XML(void);
   void test_print_variables_information(void);
   void test_save_variables_information(void);

   void test_get_data_statistics(void);
   void test_print_data_statistics(void);
   void test_save_data_statistics(void);

   void test_get_training_instances_statistics(void);
   void test_print_training_instances_statistics(void);
   void test_save_training_instances_statistics(void);

   void test_get_validation_instances_statistics(void);
   void test_print_validation_instances_statistics(void);
   void test_save_validation_instances_statistics(void);

   void test_get_testing_instances_statistics(void);
   void test_print_testing_instances_statistics(void);
   void test_save_testing_instances_statistics(void);

   void test_get_instances_statistics(void);
   void test_print_instances_statistics(void);
   void test_save_instances_statistics(void);

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
