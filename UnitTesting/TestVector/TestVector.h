/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   V E C T O R   C L A S S   H E A D E R                                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTVECTOR_H__
#define __TESTVECTOR_H__

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;


class TestVector : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // CONSTRUCTOR

   explicit TestVector(void);

   // DESTRUCTOR

   virtual ~TestVector(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);   

   // Reference operator

   void test_reference_operator(void);

   // Arithmetic operators

   void test_sum_operator(void);
   void test_rest_operator(void);
   void test_product_operator(void);
   void test_division_operator(void);

   // Operation an assignment operators
   
   void test_sum_assignment_operator(void);
   void test_rest_assignment_operator(void);
   void test_product_assignment_operator(void);
   void test_division_assignment_operator(void);

   // Equality and relational operators

   void test_equal_to_operator(void);
   void test_not_equal_to_operator(void);
   void test_greater_than_operator(void);
   void test_less_than_operator(void);
   void test_greater_than_or_equal_to_operator(void);
   void test_less_than_or_equal_to_operator(void);

   // Get methods

   void test_get_size(void);
   void test_get_display(void);

   // Set

   void test_set(void);

   void test_set_size(void);
   void test_set_display(void);

   // Resize methods

   void test_resize(void);

   void test_insert(void);
   void test_extract(void);
   
   void test_assemble(void);

   // Initialization

   void test_initialize(void);
   void test_initialize_sequential(void);
   void test_initialize_uniform(void);
   void test_initialize_normal(void);

   // Mathematical operations

   void test_dot_vector(void);
   void test_dot_matrix(void);

   void test_calculate_sum(void);
   void test_calculate_product(void);

   void test_calculate_mean(void);
   void test_calculate_standard_deviation(void);

   void test_calculate_mean_standard_deviation(void);

   void test_calculate_minimum(void);
   void test_calculate_maximum(void);

   void test_calculate_minimum_maximum(void);  

   void test_calculate_minimal_index(void);
   void test_calculate_maximal_index(void);

   void test_calculate_minimal_maximal_index(void);

   void test_calculate_norm(void);

   void test_calculate_lower_bounded(void);
   void test_calculate_upper_bounded(void);

   void test_calculate_lower_upper_bounded(void);

   void test_to_XML(void);

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
