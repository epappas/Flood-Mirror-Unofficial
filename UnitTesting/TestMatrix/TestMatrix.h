/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   M A T R I X   C L A S S   H E A D E R                                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __TESTMATRIX_H__
#define __TESTMATRIX_H__

// Utilities includes

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;

class TestMatrix : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // CONSTRUCTOR

   explicit TestMatrix(void);

   // DESTRUCTOR

   virtual ~TestMatrix(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);   

   // Reference operator methods

   void test_reference_operator(void);   

   // Arithmetic operators

   void test_sum_operator(void);
   void test_rest_operator(void);
   void test_multiplication_operator(void);
   void test_division_operator(void);

   // Arithmetic and assignment operators

   void test_sum_assignment_operator(void);
   void test_rest_assignment_operator(void);
   void test_multiplication_assignment_operator(void);
   void test_division_assignment_operator(void);

   // Equality and relational operators

   void test_equal_to_operator(void);
   void test_not_equal_to_operator(void);
   void test_greater_than_operator(void);
   void test_less_than_operator(void);
   void test_greater_than_or_equal_to_operator(void);
   void test_less_than_or_equal_to_operator(void);

   // METHODS

   // Get methods

   void test_get_rows_number(void);
   void test_get_columns_number(void);  

   void test_get_row(void);
   void test_get_column(void);

   void test_get_submatrix(void);

   void test_get_diagonal(void);

   void test_get_display(void);

   // Set methods

   void test_set(void);

   void test_set_rows_number(void);
   void test_set_columns_number(void);

   void test_set_row(void);
   void test_set_column(void);

   void test_set_display(void);

   // Resize methods

   void test_resize(void);

   void test_add_row(void);
   void test_add_column(void);
   
   void test_subtract_row(void);
   void test_subtract_column(void);

   // Initialization methods

   void test_initialize(void);
   void test_initialize_uniform(void);
   void test_initialize_normal(void);

   void test_set_to_identity(void);

   // Mathematical methods

   void test_dot(void);

   void test_calculate_mean_standard_deviation(void);

   void test_calculate_minimum_maximum(void);

   void test_calculate_determinant(void);
   void test_calculate_transpose(void);
   void test_calculate_cofactor(void);
   void test_calculate_inverse(void);

   void test_is_symmetric(void);
   void test_is_antisymmetric(void);

   // Scaling methods
 
   void test_scale_mean_standard_deviation(void);
   void test_scale_minimum_maximum(void);

   // Unscaling methods

   void test_unscale_mean_standard_deviation(void);
   void test_unscale_minimum_maximum(void);

   // Utility methods

   void test_to_XML(void);

   void test_print(void);
   void test_print_data(void);

   void test_load(void);
   void test_load_data(void);

   void test_save(void);
   void test_save_data(void);

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
