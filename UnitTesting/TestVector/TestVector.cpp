/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   V E C T O R   C L A S S                                                                          */
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

// Utilities includes 

#include "TestVector.h"
#include "../../Flood/Utilities/Vector.h"


using namespace Flood;


// GENERAL CONSTRUCTOR

TestVector::TestVector(void) : UnitTesting() 
{   
}


// DESTRUCTOR

TestVector::~TestVector(void)
{
}


// METHODS

// void test_constructor(void)

void TestVector::test_constructor(void)
{
   message += "test_constructor\n";

   // Default 

   Vector<bool> v1;

   assert_true(v1.get_size() == 0, LOG);

   // Size

   Vector<bool> v2(1);

   assert_true(v2.get_size() == 1, LOG);

   // Size initialization

   Vector<bool> v3(1, false);

   assert_true(v3.get_size() == 1, LOG);
   assert_true(v3[0] == false, LOG);

   // File

   Vector<int> v4(3, 0);
   v4.save("../Data/Vector.dat");

   Vector<int> w4("../Data/Vector.dat");
   
   assert_true(w4.get_size() == 3, LOG);

   // Copy

   Vector<bool> v5(1, false);

   Vector<bool> w5(v5);

   assert_true(w5.get_size() == 1, LOG);
   assert_true(w5[0] == false, LOG);
}




// void test_destructor(void)

void TestVector::test_destructor(void)
{
}


// void test_assignment_operator(void) method

void TestVector::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   Vector<bool> v(1, false);

   Vector<bool> w = v;

   assert_true(w.get_size() == 1, LOG);
   assert_true(w[0] == false, LOG);  
}


// void test_reference_operator(void) method

void TestVector::test_reference_operator(void)
{
}


// void test_sum_operator(void) method

void TestVector::test_sum_operator(void)
{
   message += "test_sum_operator\n";

   Vector<double> a, b, c, d;

   // Scalar

   a.set(1, 1.0);
   b =  a + 1.0;

   c.set(1, 2.0);
   
   assert_true(b == c, LOG);

   // Sum

   a.set(1, 1.0);
   b.set(1, 1.0);

   c = a + b;

   d.set(1, 2.0);

   assert_true(c == d, LOG);
}


// void test_rest_operator(void) method

void TestVector::test_rest_operator(void)
{
   message += "test_rest_operator\n";

   Vector<double> a, b, c, d;

   // Scalar

   a.set(1, 1.0);
   b =  a - 1.0;

   c.set(1, 0.0);
   
   assert_true(b == c, LOG);

   // Vector

   a.set(1, 1.0);
   b.set(1, 1.0);

   c = a - b;

   d.set(1, 0.0);

   assert_true(c == d, LOG);
}


// void test_product_operator(void) method

void TestVector::test_product_operator(void)
{
   message += "test_product_operator\n";

   Vector<double> a, b, c, d;

   // Scalar

   a.set(1, 1.0);
   b =  a*2.0;

   c.set(1, 2.0);
   
   assert_true(b == c, LOG);

   // Vector

   a.set(1, 1.0);
   b.set(1, 1.0);

   c = a*b;

   d.set(1, 1.0);

   assert_true(c == d, LOG);
}


// void test_division_operator(void) method

void TestVector::test_division_operator(void)
{
   message += "test_division_operator\n";

   Vector<double> a, b, c, d;

   // Scalar

   a.set(1, 1.0);
   b =  a/2.0;

   c.set(1, 0.5);
   
   assert_true(b == c, LOG);

   // Vector

   a.set(1, 2.0);
   b.set(1, 2.0);

   c = a/b;

   d.set(1, 1.0);

   assert_true(c == d, LOG);
}


// void test_sum_assignment_operator(void) method

void TestVector::test_sum_assignment_operator(void)
{
   message += "test_sum_assignment_operator\n";

   Vector<int> a, b;

   // Scalar

   a.set(2, 1);

   a += 1;

   assert_true(a == 2, LOG);

   // Vector

   a.set(2, 1);
   b.set(2, 1);

   a += b;

   assert_true(a == 2, LOG);
}


// void test_rest_assignment_operator(void) method

void TestVector::test_rest_assignment_operator(void)
{
   message += "test_rest_assignment_operator\n";

   Vector<int> a, b;

   // Scalar

   a.set(2, 1);

   a -= 1;

   assert_true(a == 0, LOG);

   // Vector

   a.set(2, 1);
   b.set(2, 1);

   a -= b;

   assert_true(a == 0, LOG);
}


// void test_product_assignment_operator(void) method

void TestVector::test_product_assignment_operator(void)
{
   message += "test_product_assignment_operator\n";

   Vector<int> a, b;

   // Scalar

   a.set(2, 2);

   a *= 1;

   assert_true(a == 2, LOG);

   // Vector

   a.set(2, 2);
   b.set(2, 1);

   a *= b;

   assert_true(a == 2, LOG);
}


// void test_division_assignment_operator(void) method

void TestVector::test_division_assignment_operator(void)
{
   message += "test_division_assignment_operator\n";

   Vector<int> a, b;

   // Scalar

   a.set(2, 2);

   a /= 2;

   assert_true(a == 1, LOG);

   // Vector

   a.set(2, 2);
   b.set(2, 2);

   a /= b;

   assert_true(a == 1, LOG);
}


// void test_equal_to_operator(void) method

void TestVector::test_equal_to_operator(void)
{
   message += "test_equal_to_operator\n";

   Vector<int> a(2);
   a[0] = 0;
   a[1] = 1;

   Vector<int> b(2);
   b[0] = 0;
   b[1] = 1;

   Vector<int> c(2, -1);

   assert_true(a == b, LOG);
   assert_true(c == -1, LOG);
}


// void test_not_equal_to_operator(void) method

void TestVector::test_not_equal_to_operator(void)
{
   message += "test_not_equal_to_operator\n";

   Vector<double> a(2, -1.0);
   Vector<double> b(2, 1.0);

   assert_true(a != b, LOG);
   assert_true(a != 0.0, LOG);
   assert_true(b != 0.0, LOG);
}


// void test_greater_than_operator(void) method

void TestVector::test_greater_than_operator(void)
{
   message += "test_greater_than_operator\n";

   Vector<int> a(2);   
   a[0] = 1;
   a[1] = 2;

   Vector<int> b(2);
   b[0] = 0;
   b[1] = 1;

   assert_true(a > b, LOG);

   assert_true(a > 0, LOG);
   assert_false(a > 1, LOG);

   assert_true(b > -1, LOG);
   assert_false(b > 0, LOG);
}


// void test_less_than_operator(void) method

void TestVector::test_less_than_operator(void)
{
   message += "test_less_than_operator\n";

   Vector<double> a(2);   
   a[0] = 0.0;
   a[1] = 1.0;

   Vector<double> b(2);
   b[0] = 1.0;
   b[1] = 2.0;

   assert_true(a < b, LOG);

   assert_true(a < 2.0, LOG);
   assert_false(a < 1.0, LOG);

   assert_true(b < 3.0, LOG);
   assert_false(b < 1.0, LOG);
}


// void test_greater_than_or_equal_to_operator(void) method

void TestVector::test_greater_than_or_equal_to_operator(void)
{
   message += "test_greater_than_or_equal_to_operator\n";

   Vector<int> a(2);   
   a[0] = 1;
   a[1] = 2;

   Vector<int> b(2);
   b[0] = 1;
   b[1] = 1;

   assert_true(a >= b, LOG);

   assert_true(a >= 1, LOG);
   assert_false(a >= 2, LOG);

   assert_true(b >= 1, LOG);
   assert_false(b >= 2, LOG);
}


// void test_less_than_or_equal_to_operator(void) method

void TestVector::test_less_than_or_equal_to_operator(void)
{
   message += "test_less_than_or_equal_to_operator\n";

   Vector<double> a(2);   
   a[0] = 1.0;
   a[1] = 1.0;

   Vector<double> b(2);
   b[0] = 1.0;
   b[1] = 2.0;

   assert_true(a <= b, LOG);

   assert_true(a <= 1.0, LOG);
   assert_false(a <= 0.0, LOG);

   assert_true(b <= 2.0, LOG);
   assert_false(b <= 1.0, LOG);
}


// void test_get_size(void) method

void TestVector::test_get_size(void)
{
   message += "test_get_size\n";

   Vector<int> v; 

   assert_true(v.get_size() == 0, LOG);

   v.set_size(1);

   assert_true(v.get_size() == 1, LOG);

   v.set_size(0);

   assert_true(v.get_size() == 0, LOG);
}


// void test_get_display(void) method

void TestVector::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set(void) method

void TestVector::test_set(void)
{
   message += "test_set\n";

   Vector<int> v(3, 0);

   // Default 

   v.set();

   assert_true(v.get_size() == 0, LOG);

   // Size 

   v.set(1);

   assert_true(v.get_size() == 1, LOG);

   // Size initialization

   v.set(1, 0);

   assert_true(v.get_size() == 1, LOG);
   assert_true(v == 0, LOG);

   // File 

   v.save("../Data/Vector.dat");
   v.set("../Data/Vector.dat");

   assert_true(v.get_size() == 1, LOG);
   assert_true(v == 0, LOG);

   // Copy

   v.set(v);

   assert_true(v.get_size() == 1, LOG);
   assert_true(v == 0, LOG);
}


// void test_set_size(void) method

void TestVector::test_set_size(void)
{
   message += "test_set_size\n";
}


// void test_set_display(void) method

void TestVector::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_resize(void) method

void TestVector::test_resize(void)
{
   message += "test_resize\n";

   Vector<int> a(1, 0);

   // Decrease size

   a.resize(2);

   assert_true(a.get_size() == 2, LOG);

   // Increase size

   a.resize(0);

   assert_true(a.get_size() == 0, LOG);
  
}


// void test_initialize(void) method

void TestVector::test_initialize(void)
{
   message += "test_initialize\n";

   Vector<int> v(2);

   v.initialize(0);

   Vector<int> w(2, 0);
   
   assert_true(v == w, LOG);
}


// void test_initialize_sequential(void) method

void TestVector::test_initialize_sequential(void)
{
   message += "test_initialize_sequential\n";

   Vector<double> v(2);

   v.initialize_sequential();

   Vector<double> w(2);
   w[0] = 0.0;
   w[1] = 1.0;
   
   assert_true(v == w, LOG);
}


// void test_initialize_uniform(void) method

void TestVector::test_initialize_uniform(void)
{
   message += "test_initialize_uniform\n";

   Vector<double> v(3);

   v.initialize_uniform();

   assert_true(v >= -1.0, LOG);
   assert_true(v <=  1.0, LOG);
  
   v.initialize_uniform(0.0, 2.0);
   
   assert_true(v >= 0.0, LOG);
   assert_true(v <= 2.0, LOG);
}


// void test_initialize_normal(void) method

void TestVector::test_initialize_normal(void)
{
   message += "test_initialize_normal\n";

   Vector<double> v(2);

   v.initialize_normal();

   v.initialize_normal(0.0, 0.0);

   assert_true(v == 0.0, LOG);
}


// void test_calculate_sum(void) method

void TestVector::test_calculate_sum(void)
{
   message += "test_calculate_sum\n";

   Vector<int> v;

   assert_true(v.calculate_sum() == 0, LOG);

   v.set_size(2);
   v.initialize(1);

   assert_true(v.calculate_sum() == 2, LOG);
}


// void test_calculate_product(void) method

void TestVector::test_calculate_product(void)
{
   message += "test_calculate_product\n";

   Vector<double> v;

   assert_true(v.calculate_product() == 1.0, LOG);

   v.set_size(2);
   v[0] = 0.5;
   v[1] = 1.5;

   assert_true(v.calculate_product() == 0.75, LOG);
}


// void test_calculate_mean(void) method

void TestVector::test_calculate_mean(void)
{
   message += "test_calculate_mean\n";
   
   Vector<double> v(1, 1.0);

   assert_true(v.calculate_mean() == 1.0, LOG);

   v.set_size(2);
   v[0] = -1.0;
   v[1] =  1.0;

   assert_true(v.calculate_mean() == 0.0, LOG);
}


// void test_calculate_standard_deviation(void) method

void TestVector::test_calculate_standard_deviation(void)
{
   message += "test_calculate_standard_deviation\n";
   
   Vector<double> v(1, 1.0);

   assert_true(v.calculate_standard_deviation() == 0.0, LOG);

   v.set_size(2);
   v[0] = -1.0;
   v[1] =  1.0;

   assert_true(v.calculate_standard_deviation() == 1.0, LOG);
}

   
// void test_calculate_mean_standard_deviation(void) method

void TestVector::test_calculate_mean_standard_deviation(void)
{
   Vector<double> v(2);
   v[0] = -1.0;
   v[1] =  1.0;

   Vector<double> mean_standard_deviation = v.calculate_mean_standard_deviation();

   assert_true(mean_standard_deviation[0] == 0.0, LOG);
   assert_true(mean_standard_deviation[1] == 1.0, LOG);
}


// void test_calculate_minimum(void) method

void TestVector::test_calculate_minimum(void)
{
   message += "test_calculate_minimum\n";
   
   Vector<int> v(1, 1);

   assert_true(v.calculate_minimum() == 1, LOG);

   v.set_size(3);
   v[0] = -1;
   v[1] =  0;
   v[2] =  1;

   assert_true(v.calculate_minimum() == -1, LOG);
}


// void test_calculate_maximum(void) method

void TestVector::test_calculate_maximum(void)
{
   message += "test_calculate_maximum\n";
   
   Vector<double> v(1, 1.0);

   assert_true(v.calculate_maximum() == 1.0, LOG);

   v.set_size(3);
   v[0] = -1.0;
   v[1] =  0.0;
   v[2] =  1.0;

   assert_true(v.calculate_maximum() == 1.0, LOG);
}


// void test_calculate_minimum_maximum(void) method

void TestVector::test_calculate_minimum_maximum(void)
{
   message += "test_calculate_minimum_maximum\n";
   
   Vector<int> v(3);
   v[0] = -1;
   v[1] =  0;
   v[2] =  1;

   Vector<int> minimum_maximum = v.calculate_minimum_maximum();

   assert_true(minimum_maximum[0] == -1, LOG);
   assert_true(minimum_maximum[1] == 1, LOG);
}


// void test_calculate_minimal_index(void) method

void TestVector::test_calculate_minimal_index(void)
{
   message += "test_calculate_minimal_index\n";
   
   Vector<double> v(1, 1.0);

   assert_true(v.calculate_minimal_index() == 0, LOG);

   v.set_size(3);
   v[0] =  1.0;
   v[1] =  0.0;
   v[2] = -1.0;

   assert_true(v.calculate_minimal_index() == 2, LOG);
}


// void test_calculate_maximal_index(void) method

void TestVector::test_calculate_maximal_index(void)
{
   message += "test_calculate_maximal_index\n";
   
   Vector<int> v(1);

   assert_true(v.calculate_maximal_index() == 0, LOG);

   v.set_size(3);
   v[0] = -1;
   v[1] =  0;
   v[2] =  1;

   assert_true(v.calculate_maximal_index() == 2, LOG);
}


// void test_calculate_minimal_maximal_index(void) method

void TestVector::test_calculate_minimal_maximal_index(void)
{
   message += "test_calculate_minimal_maximal_index\n";
   
   Vector<int> v(2);
   v.initialize_sequential();

   Vector<int> minimal_maximal_index = v.calculate_minimal_maximal_index();

   assert_true(minimal_maximal_index[0] == 0, LOG);
   assert_true(minimal_maximal_index[1] == 1, LOG);
}


// void test_calculate_norm(void) method

void TestVector::test_calculate_norm(void)
{
   Vector<double> v;

   assert_true(v.calculate_norm() == 0.0, LOG);

   v.set_size(2);
   v.initialize(1);

   assert_true(v.calculate_norm() == sqrt(2.0), LOG);
}


// void test_calculate_lower_bounded(void) method

void TestVector::test_calculate_lower_bounded(void)
{
   message += "test_calculate_lower_bounded\n";

   Vector<double> v(1, -1.0);
   Vector<double> lower_bound(1, 0.0);

   assert_true(v.calculate_lower_bounded(lower_bound) == 0.0, LOG); 
}


// void test_calculate_upper_bounded(void) method

void TestVector::test_calculate_upper_bounded(void)
{
   message += "test_calculate_upper_bounded\n";
}


// void test_calculate_lower_upper_bounded(void) method

void TestVector::test_calculate_lower_upper_bounded(void)
{
   message += "test_calculate_lower_upper_bounded\n";
}


// void test_dot_vector(void) method

void TestVector::test_dot_vector(void)
{
   message += "test_dot_vector\n";

   Vector<double> a(2, 0.0);
   Vector<double> b(2, 0.0);

   double c = a.dot(b);

   assert_true(c == 0.0, LOG);
}


// void test_dot_matrix(void) method

void TestVector::test_dot_matrix(void)
{
   message += "test_dot_matrix\n";

   Vector<double> a(2, 0.0);
   Matrix<double> b(2, 2, 0.0);

   Vector<double> c = a.dot(b);

   assert_true(c == 0.0, LOG);
}


// void test_insert(void) method

void TestVector::test_insert(void)
{
   message += "test_insert\n";

   Vector<int> a(4, 0);
   Vector<int> b(2, 1);

   a.insert(1, b);

   Vector<int> c(4);
   c[0] = 0;
   c[1] = 1;
   c[2] = 1;
   c[3] = 0;

   assert_true(a == c, LOG);
}


// void test_extract(void) method

void TestVector::test_extract(void)
{
   message += "test_extract\n";

   Vector<int> a(4);
   a[0] = 0;
   a[1] = 1;
   a[2] = 1;
   a[3] = 0;

   Vector<int> b = a.extract(1, 2);

   Vector<int> c(2, 1);

   assert_true(b == c, LOG);
}


// void test_assemble(void) method

void TestVector::test_assemble(void)
{
   message += "test_assemble\n";

   Vector<int> a;
   Vector<int> b;
   Vector<int> c; 
   Vector<int> d; 
	   
   c = a.assemble(b);

   assert_true(c.get_size() == 0, LOG);

   a.set_size(1, 0);
   b.set_size(0, 0),
   c = a.assemble(b);

   assert_true(c.get_size() == 1, LOG);

   a.set_size(0, 0);
   b.set_size(1, 0),
   c = a.assemble(b);

   assert_true(c.get_size() == 1, LOG);

   a.set_size(1, 0);
   b.set_size(1, 1);
  
   c = a.assemble(b);

   d.resize(2);
   d[0] = 0;
   d[1] = 1;

   assert_true(c == d, LOG);
}


// void test_to_XML(void) method

void TestVector::test_to_XML(void)
{
   message += "test_to\n";
}


// void test_load(void) method

void TestVector::test_load(void)
{
   message += "test_load\n";

   Vector<int> v(3, 0);

   v.save("../Data/Vector.dat");
   v.load("../Data/Vector.dat");

   assert_true(v.get_size() == 3, LOG);   
}


// void test_load_data(void) method

void TestVector::test_load_data(void)
{
   message += "test_load_data\n";

   Vector<int> v1;

   v1.save_data("../Data/Vector.dat");
   v1.load_data("../Data/Vector.dat");

   Vector<double> v2(2);

   v2.save_data("../Data/Vector.dat");
   v2.load_data("../Data/Vector.dat");

   Vector<double> v3(2, 1.0);

   v3.save_data("../Data/Vector.dat");
   v3.load_data("../Data/Vector.dat");

   assert_true(v3 == 1.0, LOG);   
}


// void test_save(void) method

void TestVector::test_save(void)
{
   message += "test_save\n";

   Vector<int> v(2, 0);
   Vector<int> w(v);

   v.save("v.dat");

   v.load("v.dat");   

   assert_true(v == w, LOG);   
}


// void test_save_data(void) method

void TestVector::test_save_data(void)
{
   message += "test_save_data\n";
}


// void run_test_case(void) method

void TestVector::run_test_case(void)
{
   message += "Running vector test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();   

   // Reference operator 

   test_reference_operator();

   // Arithmetic operators

   test_sum_operator();
   test_rest_operator();
   test_product_operator();
   test_division_operator();

   // Operation and assignment operators

   test_sum_assignment_operator();
   test_rest_assignment_operator();
   test_product_assignment_operator();
   test_division_assignment_operator();

   // Equality and relational operators

   test_equal_to_operator();
   test_not_equal_to_operator();

   test_greater_than_operator();
   test_greater_than_or_equal_to_operator();

   test_less_than_operator();
   test_less_than_or_equal_to_operator();

   // Get methods

   test_get_size();
   test_get_display();

   // Set methods

   test_set();
   test_set_size();
   test_set_display();

   // Resize methods

   test_resize();

   test_insert();
   test_extract();
   
   test_assemble();

   // Initialization methods

   test_initialize();
   test_initialize_sequential();
   test_initialize_uniform();
   test_initialize_normal();

   // Mathematical methods

   test_dot_vector();
   test_dot_matrix();

   test_calculate_sum();
   test_calculate_product();

   test_calculate_mean();
   test_calculate_standard_deviation();

   test_calculate_mean_standard_deviation();

   test_calculate_minimum();
   test_calculate_maximum();

   test_calculate_minimum_maximum();  

   test_calculate_minimal_index();
   test_calculate_maximal_index();

   test_calculate_minimal_maximal_index();

   test_calculate_norm();

   test_calculate_lower_bounded();
   test_calculate_upper_bounded();

   test_calculate_lower_upper_bounded();

   // Utility methods

   test_to_XML();

   test_save();
   test_save_data();

   test_load();
   test_load_data();

   message += "End vector test case\n";
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
