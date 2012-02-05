/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   M U L T I L A Y E R   P E R C E P T R O N   C L A S S   H E A D E R                              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTMULTILAYERPERCEPTRON_H__
#define __TESTMULTILAYERPERCEPTRON_H__

// Flood includes

#include "../../Flood/Utilities/UnitTesting.h"

#include "../../Flood/Utilities/Vector.h"
#include "../../Flood/Utilities/Matrix.h"

using namespace Flood;


class TestMultilayerPerceptron : public UnitTesting
{

#define STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit TestMultilayerPerceptron(void);


   // DESTRUCTOR

   virtual ~TestMultilayerPerceptron(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);

   // Get methods

   // Network architecture 

   void test_get_inputs_number(void);

   void test_get_hidden_layers_number(void);
   void test_get_hidden_layers_size(void);
   void test_get_hidden_layer_size(void);

   void test_get_outputs_number(void);

   void test_get_hidden_layer_inputs_number(void);
   void test_get_output_layer_inputs_number(void);

   void test_get_hidden_layers(void);
   void test_get_hidden_layer(void);

   void test_get_output_layer(void);

   // Neural parameters

   void test_get_neural_parameters_number(void);

   void test_get_hidden_layers_parameters_number(void);
   void test_get_hidden_layer_parameters_number(void);
   void test_get_output_layer_parameters_number(void);

   void test_get_neural_parameters(void);   

   void test_get_hidden_layers_biases(void);
   void test_get_hidden_layer_biases(void);

   void test_get_hidden_layers_synaptic_weights(void);
   void test_get_hidden_layer_synaptic_weights(void);

   void test_get_hidden_layers_parameters(void);
   void test_get_hidden_layer_parameters(void);

   void test_get_output_layer_biases(void);
   void test_get_output_layer_synaptic_weights(void);
   void test_get_output_layer_parameters(void);

   void test_get_hidden_layer_bias_index(void);
   void test_get_hidden_layer_synaptic_weight_index(void);

   void test_get_output_layer_bias_index(void);
   void test_get_output_layer_synaptic_weight_index(void);

   // Activation functions

   void test_get_hidden_layers_activation_function(void);
   void test_get_hidden_layers_activation_function_name(void);

   void test_get_hidden_layer_activation_function(void);
   void test_get_hidden_layer_activation_function_name(void);
   
   void test_get_output_layer_activation_function(void); 
   void test_get_output_layer_activation_function_name(void);

   // Variables scaling and unscaling

   void test_get_inputs_scaling_method(void);
   void test_get_inputs_scaling_method_name(void);

   void test_get_outputs_unscaling_method(void);
   void test_get_outputs_unscaling_method_name(void);

   // Input variables information

   void test_get_input_variables_name(void);
   void test_get_input_variable_name(void);

   void test_get_input_variables_units(void);
   void test_get_input_variable_units(void);

   void test_get_input_variables_description(void);
   void test_get_input_variable_description(void);

   // Output variables information

   void test_get_output_variables_name(void);
   void test_get_output_variable_name(void);

   void test_get_output_variables_units(void);
   void test_get_output_variable_units(void);

   void test_get_output_variables_description(void);
   void test_get_output_variable_description(void);

   // Variables information

   void test_get_variables_information(void);

   // Input variables statistics

   void test_get_input_variables_mean(void);
   void test_get_input_variable_mean(void);

   void test_get_input_variables_standard_deviation(void);
   void test_get_input_variable_standard_deviation(void);

   void test_get_input_variables_minimum(void);
   void test_get_input_variable_minimum(void);

   void test_get_input_variables_maximum(void);
   void test_get_input_variable_maximum(void);

   void test_get_input_variables_mean_standard_deviation(void);
   void test_get_input_variables_minimum_maximum(void);

   // Output variables statistics

   void test_get_output_variables_mean(void);
   void test_get_output_variable_mean(void);

   void test_get_output_variables_standard_deviation(void);
   void test_get_output_variable_standard_deviation(void);

   void test_get_output_variables_minimum(void);
   void test_get_output_variable_minimum(void);

   void test_get_output_variables_maximum(void);
   void test_get_output_variable_maximum(void);

   void test_get_output_variables_mean_standard_deviation(void);
   void test_get_output_variables_minimum_maximum(void);

   // Variables statistics

   void test_get_variables_statistics(void);

   // Variables bounds

   void test_get_output_variables_lower_bound(void);
   void test_get_output_variable_lower_bound(void);

   void test_get_output_variables_upper_bound(void);
   void test_get_output_variable_upper_bound(void);

   void test_get_output_variables_bounds(void);

   // Independent parameters

   void test_get_independent_parameters_number(void);

   void test_get_independent_parameters(void);   
   void test_get_independent_parameter(void);   

   // Independent parameters scaling and unscaling

   void test_get_independent_parameters_scaling_method(void);
   void test_get_independent_parameters_scaling_method_name(void);

   // Independent parameters information

   void test_get_independent_parameters_name(void);
   void test_get_independent_parameter_name(void);

   void test_get_independent_parameters_units(void);
   void test_get_independent_parameter_units(void);

   void test_get_independent_parameters_description(void);
   void test_get_independent_parameter_description(void);

   void test_get_independent_parameters_information(void);

   // Independent parameters statistics

   void test_get_independent_parameters_mean(void);
   void test_get_independent_parameter_mean(void);

   void test_get_independent_parameters_standard_deviation(void);
   void test_get_independent_parameter_standard_deviation(void);

   void test_get_independent_parameters_mean_standard_deviation(void);

   void test_get_independent_parameters_minimum(void);
   void test_get_independent_parameter_minimum(void);

   void test_get_independent_parameters_maximum(void);
   void test_get_independent_parameter_maximum(void);


   void test_get_independent_parameters_minimum_maximum(void);

   void test_get_independent_parameters_statistics(void);

   // Independent parameters bounds

   void test_get_independent_parameters_lower_bound(void);
   void test_get_independent_parameter_lower_bound(void);

   void test_get_independent_parameters_upper_bound(void);
   void test_get_independent_parameter_upper_bound(void);

   void test_get_independent_parameters_bounds(void);

   // Parameters methods

   void test_get_parameters_number(void);
   void test_get_parameters(void);   

   // Numerical differentiation

   void test_get_numerical_differentiation_method(void);
   void test_get_numerical_differentiation_method_name(void);

   void test_get_numerical_epsilon_method(void);
   void test_get_numerical_epsilon_method_name(void);

   void test_get_numerical_epsilon(void);

   // Display messages

   void test_get_display_range_out_warning(void);
   void test_get_display(void);

   // SET METHODS

   void test_set(void);
   void test_set_default(void);

   // Network architecture

   void test_set_network_architecture(void);

   void test_set_hidden_layers_size(void);
   void test_set_hidden_layer_size(void);

   // Neural parameters

   void test_set_neural_parameters(void);

   void test_set_hidden_layers_biases(void);
   void test_set_hidden_layer_biases(void);

   void test_set_hidden_layers_synaptic_weights(void);
   void test_set_hidden_layer_synaptic_weights(void);

   void test_set_hidden_layers_parameters(void);
   void test_set_hidden_layer_parameters(void);

   void test_set_output_layer_biases(void);
   void test_set_output_layer_synaptic_weights(void);
   void test_set_output_layer_parameters(void);

   // Activation functions

   void test_set_hidden_layers_activation_function(void);

   void test_set_hidden_layer_activation_function(void);

   void test_set_output_layer_activation_function(void);

   // Variables scaling and unscaling

   void test_set_inputs_scaling_method(void);

   void test_set_outputs_unscaling_method(void);

   void test_set_variables_scaling_method(void);

   // Input variables information
   void test_set_input_variables_name(void);
   void test_set_input_variable_name(void);

   void test_set_input_variables_units(void);
   void test_set_input_variable_units(void);

   void test_set_input_variables_description(void);
   void test_set_input_variable_description(void);

   // Output variables information

   void test_set_output_variables_name(void);
   void test_set_output_variable_name(void);

   void test_set_output_variables_units(void);
   void test_set_output_variable_units(void);

   void test_set_output_variables_description(void);
   void test_set_output_variable_description(void);

   // Variables information

   void test_set_variables_information(void);

   // Input variables statistics

   void test_set_input_variables_mean(void);
   void test_set_input_variable_mean(void);

   void test_set_input_variables_standard_deviation(void);
   void test_set_input_variable_standard_deviation(void);

   void test_set_input_variables_minimum(void);
   void test_set_input_variable_minimum(void);

   void test_set_input_variables_maximum(void);
   void test_set_input_variable_maximum(void);

   void test_set_input_variables_mean_standard_deviation(void);
   void test_set_input_variables_minimum_maximum(void);

   // Output variables statistics

   void test_set_output_variables_mean(void);
   void test_set_output_variable_mean(void);

   void test_set_output_variables_standard_deviation(void);
   void test_set_output_variable_standard_deviation(void);

   void test_set_output_variables_minimum(void);
   void test_set_output_variable_minimum(void);

   void test_set_output_variables_maximum(void);
   void test_set_output_variable_maximum(void);

   void test_set_output_variables_mean_standard_deviation(void);
   void test_set_output_variables_minimum_maximum(void);

   // Variables statistics

   void test_set_variables_statistics(void);

   // Variables bounds

   void test_set_output_variables_lower_bound(void);
   void test_set_output_variable_lower_bound(void);

   void test_set_output_variables_upper_bound(void);
   void test_set_output_variable_upper_bound(void);

   void test_set_output_variables_bounds(void);

   // Independent parameters

   void test_set_independent_parameters_number(void);

   void test_set_independent_parameters(void);
   void test_set_independent_parameter(void);

   // Independent parameters scaling and unscaling

   void test_set_independent_parameters_scaling_method(void);

   // Independent parameters information
   void test_set_independent_parameters_name(void);
   void test_set_independent_parameter_name(void);

   void test_set_independent_parameters_units(void);
   void test_set_independent_parameter_units(void);

   void test_set_independent_parameters_description(void);
   void test_set_independent_parameter_description(void);

   // Independent parameters statistics

   void test_set_independent_parameters_mean(void);
   void test_set_independent_parameter_mean(void);

   void test_set_independent_parameters_standard_deviation(void);
   void test_set_independent_parameter_standard_deviation(void);
   
   void test_set_independent_parameters_minimum(void);
   void test_set_independent_parameter_minimum(void);

   void test_set_independent_parameters_maximum(void);
   void test_set_independent_parameter_maximum(void);

   void test_set_independent_parameters_mean_standard_deviation(void);
   void test_set_independent_parameters_minimum_maximum(void);

   void test_set_independent_parameters_statistics(void);

   // Independent parameters bounds
   void test_set_independent_parameters_lower_bound(void);
   void test_set_independent_parameter_lower_bound(void);

   void test_set_independent_parameters_upper_bound(void);
   void test_set_independent_parameter_upper_bound(void);

   void test_set_independent_parameters_bounds(void);

   // Parameters
   void test_set_parameters(void);

   // Scaling

   void test_set_scaling_method(void);

   // Numerical differentiation

   void test_set_numerical_differentiation_method(void);

   void test_set_numerical_epsilon_method(void);

   void test_set_numerical_epsilon(void);

   // Display messages

   void test_set_display_range_out_warning(void);
   void test_set_display(void);

   // Neural parameters initialization methods

   void test_initialize_neural_parameters(void);

   void test_initialize_biases(void);    
   void test_initialize_synaptic_weights(void);
   void test_initialize_neural_parameters_uniform(void);
   void test_initialize_neural_parameters_normal(void);

   // Independent parameters initialization methods

   void test_initialize_independent_parameters(void);

   void test_initialize_independent_parameters_uniform(void);
   void test_initialize_independent_parameters_normal(void);
   // Parameters initialization methods

   void test_initialize_parameters(void);
   void test_initialize_parameters_uniform(void);
   void test_initialize_parameters_normal(void);

   // Parameters norm 

   void test_calculate_neural_parameters_norm(void);   
   void test_calculate_independent_parameters_norm(void);   
   void test_calculate_parameters_norm(void);

   // Output methods

   void test_calculate_output(void);
   void test_calculate_output_matrix(void);

   void test_calculate_output_boundary_conditions(void);
   void test_calculate_output_matrix_boundary_conditions(void);

   void test_calculate_forward_propagation(void);
   void test_calculate_forward_propagation_derivative(void);
   void test_calculate_forward_propagation_second_derivative(void);

   void test_check_input_range(void);

   void test_calculate_scaled_input(void);

   void test_calculate_hidden_layer_combination(void);
   void test_calculate_hidden_layer_activation(void);
   void test_calculate_hidden_layer_activation_derivative(void);
   void test_calculate_hidden_layer_activation_second_derivative(void);

   void test_calculate_hidden_layer_output(void);

   void test_calculate_output_layer_combination(void);
   void test_calculate_output_layer_activation(void);
   void test_calculate_output_layer_activation_derivative(void);
   void test_calculate_output_layer_activation_second_derivative(void);

   void test_calculate_output_layer_output(void);

   void test_calculate_unscaled_output(void);

   void test_calculate_bounded_output(void);

   // Independent parameters methods

   void test_scale_independent_parameters(void);
   void test_unscale_independent_parameters(void);

   void test_bound_independent_parameters(void);
   void test_bound_independent_parameter(void);

   // Jacobian methods

   void test_calculate_Jacobian(void);
   void test_calculate_Jacobian_vector(void);

   void test_calculate_Jacobian_boundary_conditions(void);
   void test_calculate_Jacobian_vector_boundary_conditions(void);

   void test_calculate_hidden_layer_Jacobian(void);   
   void test_calculate_output_layer_Jacobian(void);
   void test_calculate_Jacobian_numerical_differentiation(void);

   void test_calculate_Jacobian_forward_differences(void);   
   void test_calculate_Jacobian_central_differences(void);

   // Sensitivity methods

   void test_calculate_sensitivity(void);
   void test_calculate_sensitivity_vector(void);

   void test_calculate_sensitivity_numerical_differentiation(void);

   void test_calculate_sensitivity_forward_differences(void);   
   void test_calculate_sensitivity_central_differences(void);

   // Expression methods

   void test_get_expression(void);

   void test_get_inputs_name_expression(void);
   void test_get_scaled_inputs_name_expression(void);

   void test_get_hidden_layer_inputs_name_expression(void);
   void test_get_hidden_layer_outputs_name_expression(void);

   void test_get_scaled_outputs_name_expression(void);
   void test_get_outputs_name_expression(void);

   void test_get_hidden_layer_activation_function_expression(void);
   void test_get_output_layer_activation_function_expression(void);

   void test_get_hidden_layer_expression(void);
   void test_get_output_layer_expression(void);

   void test_get_inputs_scaling_expression(void);
   void test_get_outputs_unscaling_expression(void);

   void test_save_expression(void);

   // Hinton diagram methods

   void test_get_Hinton_diagram(void);   
   void test_save_Hinton_diagram(void);

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
