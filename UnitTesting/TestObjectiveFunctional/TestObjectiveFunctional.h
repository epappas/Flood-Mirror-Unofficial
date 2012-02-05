/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   O B J E C T I V E   F U N C T I O N A L   C L A S S   H E A D E R                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __TESTMOCKOBJECTIVEFUNCTIONAL_H__
#define __TESTMOCKOBJECTIVEFUNCTIONAL_H__

// Unit testing includes

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;


class TestObjectiveFunctional : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit TestObjectiveFunctional(void);


   // DESTRUCTOR

   virtual ~TestObjectiveFunctional(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Get methods

   void test_get_multilayer_perceptron_pointer(void);

   // Objective term methods 

   void test_get_objective_weight(void);

   // Regularization term methods

   void test_get_regularization_method(void);   
   void test_get_regularization_method_name(void);   

   void test_get_regularization_weight(void);

   // Numerical differentiation methods

   void test_get_numerical_differentiation_method(void);
   void test_get_numerical_differentiation_method_name(void);

   void test_get_numerical_epsilon_method(void);
   void test_get_numerical_epsilon_method_name(void);

   void test_get_numerical_epsilon(void);

   // Counter methods

   void test_get_calculate_evaluation_count(void);
   void test_get_calculate_gradient_count(void);
   void test_get_calculate_Hessian_count(void);

   void test_get_display(void);

   // Set methods

   void test_set_multilayer_perceptron_pointer(void);
   
   void test_set_default(void);

   // Objective term methods 

   void test_set_objective_weight(void);

   // Regularization term methods

   void test_set_regularization_method(void);   

   void test_set_regularization_weight(void);

   // Numerical differentiation methods

   void test_set_numerical_differentiation_method(void);

   void test_set_numerical_epsilon_method(void);

   void test_set_numerical_epsilon(void);

   // Counter methods

   void test_set_calculate_evaluation_count(void);
   void test_set_calculate_gradient_count(void);
   void test_set_calculate_Hessian_count(void);

   void test_set_display(void);

   // Objective functional evaluation methods

   void test_calculate_evaluation(void);
   void test_calculate_potential_evaluation(void);

   void test_calculate_objective(void);
   void test_calculate_regularization(void); 

   // Objective function gradient methods

   void test_calculate_gradient(void);
   void test_calculate_potential_gradient(void);

   void test_calculate_gradient_norm(void);

   void test_calculate_objective_gradient(void); 
   void test_calculate_regularization_gradient(void); 

   void test_calculate_neural_parameters_gradient(void);
   void test_calculate_independent_parameters_gradient(void);

   // Objective function gradient numerical differentiation methods

   void test_calculate_objective_gradient_numerical_differentiation(void); 

   void test_calculate_neural_parameters_gradient_numerical_differentiation(void);
   void test_calculate_neural_parameters_gradient_forward_differences(void);
   void test_calculate_neural_parameters_gradient_central_differences(void);

   void test_calculate_independent_parameters_gradient_numerical_differentiation(void);
   void test_calculate_independent_parameters_gradient_forward_differences(void);
   void test_calculate_independent_parameters_gradient_central_differences(void);

   // Objective function Hessian methods

   void test_calculate_Hessian(void);
   void test_calculate_potential_Hessian(void);

   // Objective function Hessian numerical differentiation methods

   void test_calculate_Hessian_numerical_differentiation(void);

   void test_calculate_Hessian_forward_differences(void);
   void test_calculate_Hessian_central_differences(void);

   // Objective function inverse Hessian methods

   void test_calculate_inverse_Hessian(void);

   void test_calculate_DFP_inverse_Hessian_approximation(void);

   void test_calculate_BFGS_inverse_Hessian_approximation(void);

   // Objective function vector Hessian product methods

   void test_calculate_vector_dot_Hessian(void);

   // Objective function vector Hessian product numerical differentiation methods

   void test_calculate_vector_dot_Hessian_numerical_differentiation(void);

   void test_calculate_vector_dot_Hessian_forward_differences(void);
   void test_calculate_vector_dot_Hessian_central_differences(void);

   // Validation error methods
  
   void test_calculate_validation_error(void);   

   // Numerical epsilon methods

   void test_calculate_actual_epsilon(void); 

   // Utility methods

   void test_to_XML(void);   

   void test_print(void);   
   void test_save(void);   
   void test_load(void);   

   void test_print_information(void);   

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
