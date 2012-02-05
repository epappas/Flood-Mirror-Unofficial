/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   M A T R I X   C L A S S                                                                          */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

#include "TestMatrix.h"

#include "../../Flood/Utilities/Matrix.h"

using namespace Flood;


// GENERAL CONSTRUCTOR

TestMatrix::TestMatrix(void) : UnitTesting() 
{   
}


// DESTRUCTOR

TestMatrix::~TestMatrix(void)
{
}


// METHODS

// void test_constructor(void) method

void TestMatrix::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   Matrix<bool> m1;

   assert_true(m1.get_rows_number() == 0, LOG);
   assert_true(m1.get_columns_number() == 0, LOG);

   // Rows and columns numbers

   Matrix<bool> m2(0, 0);

   assert_true(m2.get_rows_number() == 0, LOG);
   assert_true(m2.get_columns_number() == 0, LOG);
  
   Matrix<double> m3(1, 1, 1.0);
   assert_true(m3.get_rows_number() == 1, LOG);
   assert_true(m3.get_columns_number() == 1, LOG);

   // Rows and columns numbers and initialization

   Matrix<bool> m4(0, 0, true);

   assert_true(m4.get_rows_number() == 0, LOG);
   assert_true(m4.get_columns_number() == 0, LOG);

   Matrix<bool> m5(1, 1, true);

   assert_true(m5.get_rows_number() == 1, LOG);
   assert_true(m5.get_columns_number() == 1, LOG);
   assert_true(m5 == true, LOG);

   // File constructor

   m1.save("../Data/Matrix.dat");
   Matrix<bool> m6("../Data/Matrix.dat");
   assert_true(m6.get_rows_number() == 0, LOG);
   assert_true(m6.get_columns_number() == 0, LOG);

   m2.save("../Data/Matrix.dat");
   Matrix<bool> m7("../Data/Matrix.dat");
   assert_true(m7.get_rows_number() == 0, LOG);
   assert_true(m7.get_columns_number() == 0, LOG);

   m3.save("../Data/Matrix.dat");

   Matrix<double> m8("../Data/Matrix.dat");
   assert_true(m8.get_rows_number() == 1, LOG);
   assert_true(m8.get_columns_number() == 1, LOG);

   m4.save("../Data/Matrix.dat");
   Matrix<bool> m9("../Data/Matrix.dat");
   assert_true(m9.get_rows_number() == 0, LOG);
   assert_true(m9.get_columns_number() == 0, LOG);

   m5.save("../Data/Matrix.dat");

   Matrix<bool> m10("../Data/Matrix.dat");
   assert_true(m10.get_rows_number() == 1, LOG);
   assert_true(m10.get_columns_number() == 1, LOG);
   assert_true(m10 == true, LOG); 

   // Copy constructor

   Matrix<double> a5;
   Matrix<double> b5(a5);

   assert_true(b5.get_rows_number() == 0, LOG);
   assert_true(b5.get_columns_number() == 0, LOG);
   assert_true(b5.get_display() == true, LOG);  

   Matrix<bool> a6(1, 1, true);

   Matrix<bool> b6(a6);

   assert_true(b6.get_rows_number() == 1, LOG);
   assert_true(b6.get_columns_number() == 1, LOG);
   assert_true(b6.get_display() == true, LOG);  
   assert_true(b6 == true, LOG);
}


// void test_destructor(void) method

void TestMatrix::test_destructor(void)
{  
   message += "test_destructor\n";
}


// void test_assignment_operator(void) method

void TestMatrix::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   Matrix<int> a(1, 1, 0);

   Matrix<int> b = a;

   for(int i = 0; i < 2; i++)
   {
      b = a;
   }

   assert_true(b.get_rows_number() == 1, LOG);
   assert_true(b.get_columns_number() == 1, LOG);
   assert_true(b == 0, LOG);
}


// void test_reference_operator(void) method

void TestMatrix::test_reference_operator(void)
{
   message += "test_reference_operator\n";
}


// void test_sum_operator(void) method

void TestMatrix::test_sum_operator(void)
{
   message += "test_sum_operator\n";

   Matrix<int> a(1, 1, 1);
   Matrix<int> b(1, 1, 1);
   Matrix<int> c(1, 1);
   
   c = a + 1;

   for(int i = 0; i < 2; i++)
   {
      c = a + 1;
   }  

   assert_true(c.get_rows_number() == 1, LOG);
   assert_true(c.get_columns_number() == 1, LOG);
   assert_true(c == 2, LOG);

   c = a + b;

   assert_true(c.get_rows_number() == 1, LOG);
   assert_true(c.get_columns_number() == 1, LOG);
   assert_true(c == 2, LOG);
}


// void test_rest_operator(void) method

void TestMatrix::test_rest_operator(void)
{
   message += "test_rest_operator\n";

   Matrix<int> a(1, 1, 1);
   Matrix<int> b(1, 1, 1);
   Matrix<int> c(1, 1);
   
   c = a - 1;

   assert_true(c.get_rows_number() == 1, LOG);
   assert_true(c.get_columns_number() == 1, LOG);
   assert_true(c == 0, LOG);

   c = a - b;

   assert_true(c.get_rows_number() == 1, LOG);
   assert_true(c.get_columns_number() == 1, LOG);
   assert_true(c == 0, LOG);
}


// void test_multiplication_operator(void) method

void TestMatrix::test_multiplication_operator(void)
{
   message += "test_multiplication_operator\n";

   Matrix<int> a(1, 1, 2);
   Matrix<int> b(1, 1, 2);
   Matrix<int> c(1, 1);
   
   c = a*2;

   assert_true(c.get_rows_number() == 1, LOG);
   assert_true(c.get_columns_number() == 1, LOG);
   assert_true(c == 4, LOG);

   c = a*b;

   assert_true(c.get_rows_number() == 1, LOG);
   assert_true(c.get_columns_number() == 1, LOG);
   assert_true(c == 4, LOG);
}


// void test_division_operator(void) method

void TestMatrix::test_division_operator(void)
{
   message += "test_division_operator\n";

   Matrix<int> a(1, 1, 2);
   Matrix<int> b(1, 1, 2);
   Matrix<int> c(1, 1);
   
   c = a/2;

   assert_true(c.get_rows_number() == 1, LOG);
   assert_true(c.get_columns_number() == 1, LOG);
   assert_true(c == 1, LOG);

   c = a/b;

   assert_true(c.get_rows_number() == 1, LOG);
   assert_true(c.get_columns_number() == 1, LOG);
   assert_true(c == 1, LOG);
}


// void test_sum_assignment_operator(void) method

void TestMatrix::test_sum_assignment_operator(void)
{
   message += "test_sum_assignment_operator\n";
}


// void test_rest_assignment_operator(void) method

void TestMatrix::test_rest_assignment_operator(void)
{
   message += "test_rest_assignment_operator\n";
}


// void test_multiplication_assignment_operator(void) method

void TestMatrix::test_multiplication_assignment_operator(void)
{
   message += "test_multiplication_assignment_operator\n";
}


// void test_division_assignment_operator(void) method

void TestMatrix::test_division_assignment_operator(void)
{
   message += "test_division_assignment_operator\n";
}


// void test_equal_to_operator(void) method

void TestMatrix::test_equal_to_operator(void)
{
	message += "test_equal_to_operator\n";

   Matrix<int> a(1,1,0);
   Matrix<int> b(1,1,0);
   Matrix<int> c(1,1,1);

   assert_true(a == b, LOG);
   assert_false(a == c, LOG);
}


// void test_not_equal_to_operator(void) method

void TestMatrix::test_not_equal_to_operator(void)
{
   message += "test_not_equal_to_operator\n";

   Matrix<int> a(1,1,0);
   Matrix<int> b(1,1,0);
   Matrix<int> c(1,1,1);

   assert_false(a != b, LOG);
   assert_true(a != c, LOG);
}


// void test_greater_than_operator(void) method

void TestMatrix::test_greater_than_operator(void)
{
   message += "test_greater_than_operator\n";

   Matrix<double> a(1,1,1.0);
   Matrix<double> b(1,1,0.0);

   assert_true(a > 0.0, LOG);
   assert_true(a > b, LOG);
}


// void test_less_than_operator(void) method

void TestMatrix::test_less_than_operator(void)
{
   message += "test_less_than_operator\n";

   Matrix<double> a(1,1,0.0);
   Matrix<double> b(1,1,1.0);

   assert_true(a < 1.0, LOG);
   assert_true(a < b, LOG);
}


// void test_greater_than_or_equal_to_operator(void) method

void TestMatrix::test_greater_than_or_equal_to_operator(void)
{
   message += "test_greater_than_or_equal_to_operator\n";

   Matrix<double> a(1,1,1.0);
   Matrix<double> b(1,1,1.0);

   assert_true(a >= 1.0, LOG);
   assert_true(a >= b, LOG);
}


// void test_less_than_or_equal_to_operator(void) method

void TestMatrix::test_less_than_or_equal_to_operator(void)
{
   message += "test_less_than_or_equal_to_operator\n";

   Matrix<double> a(1,1,1.0);
   Matrix<double> b(1,1,1.0);

   assert_true(a <= 1.0, LOG);
   assert_true(a <= b, LOG);
}


// void test_get_rows_number(void) method

void TestMatrix::test_get_rows_number(void)
{
   message += "test_get_rows_number\n";

   Matrix<bool> m(2,3);

   int rows_number = m.get_rows_number();

   assert_true(rows_number == 2, LOG);
}


// void test_get_columns_number(void) method

void TestMatrix::test_get_columns_number(void)  
{
   message += "test_get_columns_number\n";

   Matrix<bool> m(2,3);

   int columns_number = m.get_columns_number();

   assert_true(columns_number == 3, LOG);
}

// void test_get_row(void) method

void TestMatrix::test_get_row(void)
{
   message += "test_get_row\n";

   Matrix<int> m(1, 1, 0);

   Vector<int> row = m.get_row(0);

   assert_true(row == 0, LOG);
}


// void test_get_column(void) method

void TestMatrix::test_get_column(void)
{
   message += "test_get_column\n";

   Matrix<int> m(1, 1, 0);

   Vector<int> column = m.get_column(0);

   assert_true(column == 0, LOG);
}


// void test_get_submatrix(void) method

void TestMatrix::test_get_submatrix(void)
{
   message += "test_get_submatrix\n";
}


// void test_get_diagonal(void) method

void TestMatrix::test_get_diagonal(void)
{
   message += "test_get_diagonal\n";

   Matrix<bool> m(2, 2, true);

   Vector<bool> diagonal = m.get_diagonal();

   assert_true(diagonal.get_size() == 2, LOG);
   assert_true(diagonal == true, LOG);
}



// void test_get_display(void) method

void TestMatrix::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set(void) method

void TestMatrix::test_set(void)
{
   message += "test_set\n";

   Matrix<double> m;

   // Default

   m.set();

   assert_true(m.get_rows_number() == 0, LOG);
   assert_true(m.get_columns_number() == 0, LOG);

   // Numbers of rows and columns

   m.set(0, 0);

   assert_true(m.get_rows_number() == 0, LOG);
   assert_true(m.get_columns_number() == 0, LOG);

   m.set(2, 3);

   assert_true(m.get_rows_number() == 2, LOG);
   assert_true(m.get_columns_number() == 3, LOG);

   m.set(0, 0);

   assert_true(m.get_rows_number() == 0, LOG);
   assert_true(m.get_columns_number() == 0, LOG);

   // Initialization 

   m.set(3, 2, 1.0);

   assert_true(m.get_rows_number() == 3, LOG);
   assert_true(m.get_columns_number() == 2, LOG);
   assert_true(m == 1.0, LOG);

   // File 

   m.save("../Data/Matrix.dat");
   m.set("../Data/Matrix.dat");

   assert_true(m.get_rows_number() == 3, LOG);
   assert_true(m.get_columns_number() == 2, LOG);
   assert_true(m == 1.0, LOG);
}


// void test_set_rows_number(void) method

void TestMatrix::test_set_rows_number(void)
{
   message += "test_set_rows_number\n";

}


// void test_set_columns_number(void) method

void TestMatrix::test_set_columns_number(void)
{
   message += "test_set_columns_number\n";

}


// void test_set_row(void) method

void TestMatrix::test_set_row(void)
{
   message += "test_set_row\n";

   Matrix<double> m(1,1);

   Vector<double> row(1, 1.0);

   m.set_row(0, row);

   assert_true(m.get_row(0) == row, LOG);
}


// void test_set_column(void) method

void TestMatrix::test_set_column(void)
{
   message += "test_set_column\n";

   Matrix<double> m(1,1);

   Vector<double> column(1, 1.0);

   m.set_column(0, column);

   assert_true(m.get_column(0) == column, LOG);
}


// void test_set_display(void) method

void TestMatrix::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_resize(void) method

void TestMatrix::test_resize(void)
{
   message += "test_resize\n";

   Matrix<int> m(1,1);
   
   m.resize(0, 0);

   assert_true(m.get_rows_number() == 0, LOG);
   assert_true(m.get_columns_number() == 0, LOG);

   m.resize(1,1);   

   assert_true(m.get_rows_number() == 1, LOG);
   assert_true(m.get_columns_number() == 1, LOG);

   m.initialize(1);

   m.resize(2,2);

   assert_true(m.get_rows_number() == 2, LOG);
   assert_true(m.get_columns_number() == 2, LOG);
   assert_true(m[0][0] == 1, LOG);
   assert_true(m[1][1] != 1, LOG);
}


// void test_add_row(void) method

void TestMatrix::test_add_row(void)
{
   message += "test_add_row\n";

   Matrix<bool> m(1, 1, false);

   Vector<bool> v(1, true);

   m.add_row(v);

   assert_true(m.get_rows_number() == 2, LOG);
   assert_true(m[1][0] == true, LOG);
}


// void test_add_column(void) method

void TestMatrix::test_add_column(void)
{
   message += "test_add_column\n";

   Matrix<bool> m(1, 1, false);

   Vector<bool> v(1, true);

   m.add_column(v);

   assert_true(m.get_columns_number() == 2, LOG);
   assert_true(m[0][1] == true, LOG);
}


// void test_subtract_row(void) method

void TestMatrix::test_subtract_row(void)
{
   message += "test_subtract_row\n";

   Matrix<bool> m(2, 1);
   m[0][0] = true;
   m[1][0] = false;

   m.subtract_row(0);

   assert_true(m.get_rows_number() == 1, LOG);
   assert_true(m[0][0] == false, LOG);  
}


// void test_subtract_column(void) method

void TestMatrix::test_subtract_column(void)
{
   message += "test_subtract_column\n";

   Matrix<bool> m(1, 2, false);
   m[0][0] = true;
   m[0][1] = false;

   m.subtract_column(0);

   assert_true(m.get_columns_number() == 1, LOG);
   assert_true(m[0][0] == false, LOG);  
}


// void test_initialize(void) method

void TestMatrix::test_initialize(void)
{
   message += "test_initialize\n";
}


// void test_initialize_uniform(void) method

void TestMatrix::test_initialize_uniform(void)
{
   message += "test_initialize_uniform\n";

   Matrix<double> m(1, 1);

   m.initialize_uniform();

   assert_true(m >= -1.0, LOG);
   assert_true(m <=  1.0, LOG);

   m.initialize_uniform(-1.0, 0.0);

   assert_true(m >= -1.0, LOG);
   assert_true(m <=  0.0, LOG);
}


// void test_initialize_normal(void) method

void TestMatrix::test_initialize_normal(void)
{
   message += "test_initialize_normal\n";
}


// void test_set_to_identity(void) method

void TestMatrix::test_set_to_identity(void)
{
   message += "test_set_to_identity\n";

   Matrix<int> a(2, 2);
   a.set_to_identity();

   Matrix<int> b(2, 2);
   b[0][0] = 1;
   b[0][1] = 0;
   b[1][0] = 0;
   b[1][1] = 1;

   assert_true(a == b, LOG);
}


// void test_dot(void)

void TestMatrix::test_dot(void)
{
   message += "test_dot\n";
}


// void test_calculate_mean_standard_deviation(void)

void TestMatrix::test_calculate_mean_standard_deviation(void)
{
   message += "test_calculate_mean_standard_deviation\n";
}


// void test_calculate_minimum_maximum(void)

void TestMatrix::test_calculate_minimum_maximum(void)
{
   message += "test_calculate_minimum_maximum\n";

}


// void test_calculate_determinant(void) method

void TestMatrix::test_calculate_determinant(void)
{
   message += "test_calculate_determinant\n";

   Matrix<int> m(1, 1, 1);

   assert_true(m.calculate_determinant() == 1, LOG);

   m.resize(2, 2);

   m[0][0] = 1;
   m[0][1] = 2;

   m[1][0] = 3;
   m[1][1] = 4;

   assert_true(m.calculate_determinant() == -2, LOG);

   m.resize(3, 3);

   m[0][0] = 1;
   m[0][1] = 2;
   m[0][2] = 3;

   m[1][0] = 4;
   m[1][1] = 5;
   m[1][2] = 6;

   m[2][0] = 7;
   m[2][1] = 8;
   m[2][2] = 9;

   assert_true(m.calculate_determinant() == 0, LOG);

   m.resize(4, 4);

   m[0][0] = 1;
   m[0][1] = 2;
   m[0][2] = 3;
   m[0][3] = 4;

   m[1][0] = 5;
   m[1][1] = 6;
   m[1][2] = 7;
   m[1][3] = 8;

   m[2][0] = 9;
   m[2][1] = 10;
   m[2][2] = 11;
   m[2][3] = 12;

   m[3][0] = 13;
   m[3][1] = 14;
   m[3][2] = 15;
   m[3][3] = 16;

   assert_true(m.calculate_determinant() == 0, LOG);

}


// void test_calculate_transpose(void) method

void TestMatrix::test_calculate_transpose(void)
{
   message += "test_calculate_transpose\n";

   Matrix<int> m(1, 1, 0);

   Matrix<int> transpose = m.calculate_transpose();

   assert_true(transpose == m, LOG);
}


// void test_calculate_cofactor(void) method

void TestMatrix::test_calculate_cofactor(void)
{
   message += "test_calculate_cofactor\n";
}


// void test_calculate_inverse(void) method

void TestMatrix::test_calculate_inverse(void)
{
   message += "test_calculate_inverse\n";

   Matrix<double> m(1, 1, 1.0);

//   assert_true(m.calculate_inverse() == 1.0, LOG);

   m.resize(2, 2);

   m[0][0] = 1.0;
   m[0][1] = 2.0;

   m[1][0] = 3.0;
   m[1][1] = 4.0;

//   assert_true(m.calculate_inverse() == -2, LOG);

   m.resize(3, 3);

   m[0][0] = 1.0;
   m[0][1] = 2.0;
   m[0][2] = 3.0;

   m[1][0] = 4.0;
   m[1][1] = 5.0;
   m[1][2] = 6.0;

   m[2][0] = 7.0;
   m[2][1] = 8.0;
   m[2][2] = 9.0;

//   assert_true(m.calculate_inverse() == 0, LOG);

   m.resize(4, 4);

   m[0][0] = 1.0;
   m[0][1] = 2.0;
   m[0][2] = 3.0;
   m[0][3] = 4.0;

   m[1][0] = 5.0;
   m[1][1] = 6.0;
   m[1][2] = 7.0;
   m[1][3] = 8.0;

   m[2][0] = 9.0;
   m[2][1] = 10.0;
   m[2][2] = 11.0;
   m[2][3] = 12.0;

   m[3][0] = 13.0;
   m[3][1] = 14.0;
   m[3][2] = 15.0;
   m[3][3] = 16.0;

//   assert_true(m.calculate_inverse() == 0, LOG);

}


// void test_is_symmetric(void) method

void TestMatrix::test_is_symmetric(void)
{
   message += "test_is_symmetric\n";

   Matrix<int> m(1, 1, 1);

   assert_true(m.is_symmetric(), LOG);

   m.set(2, 2);

   m.set_to_identity();

   assert_true(m.is_symmetric(), LOG);
}


// void test_is_antisymmetric(void) method

void TestMatrix::test_is_antisymmetric(void)
{
   message += "test_is_antisymmetric\n";

   Matrix<int> m(1, 1, 1);

   assert_true(m.is_antisymmetric(), LOG);
}


// void test_scale_mean_standard_deviation(void) method

void TestMatrix::test_scale_mean_standard_deviation(void)
{
   message += "test_scale_mean_standard_deviation\n";

}


// void test_scale_minimum_maximum(void) method

void TestMatrix::test_scale_minimum_maximum(void)
{
   message += "test_scale_minimum_maximum\n";

}


// void test_unscale_mean_standard_deviation(void) method

void TestMatrix::test_unscale_mean_standard_deviation(void)
{
   message += "test_unscale_mean_standard_deviation\n";

}


// void test_unscale_minimum_maximum(void) method

void TestMatrix::test_unscale_minimum_maximum(void)
{
   message += "test_unscale_minimum_maximum\n";

}


// void test_to_XML(void) method

void TestMatrix::test_to_XML(void)
{
   message += "test_to\n";

   Matrix<double> m;

   std::string object = m.to_XML(true);

   m.set(2, 3, 0.0);

   object = m.to_XML(true);

   //std::cout << object << std::endl;
}


// void test_print(void) method

void TestMatrix::test_print(void)
{
   message += "test_print\n";

   Matrix<bool> m(6, 1, true);
   //m.print();
}


// void test_print_data(void) method

void TestMatrix::test_print_data(void)
{
   message += "test_print_data\n";

}


// void test_save(void) method

void TestMatrix::test_save(void)
{
   message += "test_save\n";

   Matrix<int> m;

   m.save("../Data/Matrix.dat");
}


// void test_save_data(void) method

void TestMatrix::test_save_data(void)
{
   message += "test_save_data\n";

   Matrix<int> m;

   m.save_data("../Data/Data.dat");
}


// void test_load(void) method

void TestMatrix::test_load(void)
{
   message += "test_load\n";

   Matrix<int> m;

   m.save("../Data/Matrix.dat");
   m.load("../Data/Matrix.dat");

   assert_true(m.get_rows_number() == 0, LOG);
   assert_true(m.get_columns_number() == 0, LOG);

   m.set(1, 2, 3);

   m.save("../Data/Matrix.dat");
   m.load("../Data/Matrix.dat");

   assert_true(m.get_rows_number() == 1, LOG);
   assert_true(m.get_columns_number() == 2, LOG);
   assert_true(m == 3, LOG);   

   m.set(2, 1, 1);

   m.save("../Data/Matrix.dat");
   m.load("../Data/Matrix.dat");

   assert_true(m.get_rows_number() == 2, LOG);
   assert_true(m.get_columns_number() == 1, LOG);

   m.set(4, 4, 0);

   m.save("../Data/Matrix.dat");
   m.load("../Data/Matrix.dat");

   assert_true(m.get_rows_number() == 4, LOG);
   assert_true(m.get_columns_number() == 4, LOG);
   assert_true(m == 0, LOG);

   m.set(1, 1, -99);

   m.save("../Data/Matrix.dat");
   m.load("../Data/Matrix.dat");

   assert_true(m.get_rows_number() == 1, LOG);
   assert_true(m.get_columns_number() == 1, LOG);
   assert_true(m == -99, LOG);
}


// void test_load_data(void) method

void TestMatrix::test_load_data(void)
{
   message += "test_load_data\n";

   Matrix<double> m;

   m.save_data("../Data/Data.dat");
   m.load_data("../Data/Data.dat");

   assert_true(m.get_rows_number() == 0, LOG);
   assert_true(m.get_columns_number() == 0, LOG);

   m.set(2, 1);

   m.save_data("../Data/Data.dat");
   m.load_data("../Data/Data.dat");

   assert_true(m.get_rows_number() == 2, LOG);
   assert_true(m.get_columns_number() == 1, LOG);

   m.set(1, 1, 0);

   m.save_data("../Data/Data.dat");
   m.load_data("../Data/Data.dat");

   assert_true(m.get_rows_number() == 1, LOG);
   assert_true(m.get_columns_number() == 1, LOG);
   assert_true(m[0][0] == 0, LOG);   
}


// void run_test_case(void) method

void TestMatrix::run_test_case(void)
{
   message += "Running matrix test case...\n";  

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();   

   // Reference operator methods

   test_reference_operator();   

   // Arithmetic operators

   test_sum_operator();
   test_rest_operator();
   test_multiplication_operator();
   test_division_operator();

   // Arithmetic and assignment operators

   test_sum_assignment_operator();
   test_rest_assignment_operator();
   test_multiplication_assignment_operator();
   test_division_assignment_operator();

   // Equality and relational operators

   test_equal_to_operator();
   test_not_equal_to_operator();
   test_greater_than_operator();
   test_less_than_operator();
   test_greater_than_or_equal_to_operator();
   test_less_than_or_equal_to_operator();

   // Get methods

   test_get_rows_number();
   test_get_columns_number();  

   test_get_row();
   test_get_column();

   test_get_submatrix();

   test_get_diagonal();

   test_get_display();

   // Set methods

   test_set();
   
   test_set_rows_number();
   test_set_columns_number();

   test_set_row();
   test_set_column();

   test_set_display();

   // Resize methods

   test_resize();
    
   test_add_row();
   test_add_column();
   
   test_subtract_row();
   test_subtract_column();

   // Initialization methods

   test_initialize();
   test_initialize_uniform();
   test_initialize_normal();

   test_set_to_identity();

   // Mathematical methods

   test_dot();

   test_calculate_mean_standard_deviation();

   test_calculate_minimum_maximum();

   test_calculate_determinant();
   test_calculate_transpose();
   test_calculate_cofactor();
   test_calculate_inverse();

   test_is_symmetric();
   test_is_antisymmetric();

   // Scaling methods
 
   test_scale_mean_standard_deviation();
   test_scale_minimum_maximum();

   // Unscaling methods

   test_unscale_mean_standard_deviation();
   test_unscale_minimum_maximum();

   // Utility methods

   test_to_XML();

   test_print();
   test_print_data();

   test_load();
   test_load_data();

   test_save();
   test_save_data();

   message += "End of matrix test case...\n";  
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
