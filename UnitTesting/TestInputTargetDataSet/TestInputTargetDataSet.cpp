/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   I N P U T   T A R G E T   D A T A   S E T   C L A S S                                            */
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

#include "../../Flood/Utilities/InputTargetDataSet.h"

// Unit testing includes

#include "TestInputTargetDataSet.h"

using namespace Flood;

// GENERAL CONSTRUCTOR

TestInputTargetDataSet::TestInputTargetDataSet(void) : UnitTesting() 
{
}



// DESTRUCTOR

TestInputTargetDataSet::~TestInputTargetDataSet(void)
{
}


// METHODS

// void test_constructor(void)

void TestInputTargetDataSet::test_constructor(void)
{
   message += "test_constructor\n";

   InputTargetDataSet itds1(1, 1, 1);

   assert_true(itds1.get_instances_number() == 1, LOG);
   assert_true(itds1.get_input_variables_number() == 1, LOG);
   assert_true(itds1.get_target_variables_number() == 1, LOG);

   InputTargetDataSet itds2(1, 1, 1);
   itds2.set_display(false);
   itds2.initialize_data(1.0);

   itds2.save("../Data/InputTargetDataSet.dat");

   InputTargetDataSet itds3("../Data/InputTargetDataSet.dat");

   assert_true(itds3.get_instances_number() == 1, LOG);
   assert_true(itds3.get_input_variables_number() == 1, LOG);
   assert_true(itds3.get_target_variables_number() == 1, LOG);

   InputTargetDataSet itds4;

   assert_true(itds4.get_instances_number() == 0, LOG);
   assert_true(itds4.get_input_variables_number() == 0, LOG);
   assert_true(itds4.get_target_variables_number() == 0, LOG);

   InputTargetDataSet itds5(1, 1, 1);

   InputTargetDataSet itds6(itds5);

   assert_true(itds6.get_instances_number() == 1, LOG);
   assert_true(itds6.get_input_variables_number() == 1, LOG);
   assert_true(itds6.get_target_variables_number() == 1, LOG);   
}


// void test_destructor(void)

void TestInputTargetDataSet::test_destructor(void)
{
   message += "test_destructor\n";

   InputTargetDataSet itds;

   itds.~InputTargetDataSet();

   InputTargetDataSet* itdsp = new InputTargetDataSet(1,1,1);

   delete itdsp;
}


// void test_assignment_operator(void) method

void TestInputTargetDataSet::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   InputTargetDataSet itds1(1, 1, 1);
   InputTargetDataSet itds2 = itds1;

   assert_true(itds2.get_instances_number() == 1, LOG);
   assert_true(itds2.get_input_variables_number() == 1, LOG);
   assert_true(itds2.get_target_variables_number() == 1, LOG);
}


// void test_get_instances_number(void) method

void TestInputTargetDataSet::test_get_instances_number(void) 
{
   message += "test_get_instances_number\n";

   InputTargetDataSet itds;

   assert_true(itds.get_instances_number() == 0, LOG);
}


// void test_get_variables_number(void) method

void TestInputTargetDataSet::test_get_variables_number(void) 
{
   message += "test_get_variables_number\n";

   InputTargetDataSet itds;

   assert_true(itds.get_variables_number() == 0, LOG);
}


// void test_get_training_instances_number(void) method

void TestInputTargetDataSet::test_get_training_instances_number(void) 
{
   message += "test_get_training_instances_number\n";

   InputTargetDataSet itds;

   assert_true(itds.get_training_instances_number() == 0, LOG);
   
   itds.set(1, 1, 1);

   assert_true(itds.get_training_instances_number() == 1, LOG);
}


// void test_get_training_instances_indices(void) method

void TestInputTargetDataSet::test_get_training_instances_indices(void) 
{
   message += "test_get_training_instances_indices\n";

   InputTargetDataSet itds;

   Vector<int> training_instances_indices;

   training_instances_indices = itds.get_training_instances_indices();

   assert_true(training_instances_indices.get_size() == 0, LOG);
   
   itds.set(1, 1, 1);

   training_instances_indices = itds.get_training_instances_indices();

   assert_true(training_instances_indices.get_size() == 1, LOG);
}


// void test_get_validation_instances_number(void) method

void TestInputTargetDataSet::test_get_validation_instances_number(void) 
{
   message += "test_get_validation_instances_number\n";

   InputTargetDataSet itds;

   assert_true(itds.get_validation_instances_number() == 0, LOG);
   
   itds.set(1, 1, 1);

   assert_true(itds.get_validation_instances_number() == 0, LOG);
}


// void test_get_validation_instances_indices(void) method

void TestInputTargetDataSet::test_get_validation_instances_indices(void) 
{
   message += "test_get_validation_instances_indices\n";

   InputTargetDataSet itds;

   Vector<int> validation_instances_indices;

   validation_instances_indices = itds.get_validation_instances_indices();

   assert_true(validation_instances_indices.get_size() == 0, LOG);
   
   itds.set(1, 1, 1);

   validation_instances_indices = itds.get_validation_instances_indices();

   assert_true(validation_instances_indices.get_size() == 0, LOG);
}


// void test_get_testing_instances_number(void) method

void TestInputTargetDataSet::test_get_testing_instances_number(void) 
{
   message += "test_get_testing_instances_number\n";

   InputTargetDataSet itds;

   assert_true(itds.get_testing_instances_number() == 0, LOG);
   
   itds.set(1, 1, 1);

   assert_true(itds.get_testing_instances_number() == 0, LOG);
}


// void test_get_testing_instances_indices(void) method

void TestInputTargetDataSet::test_get_testing_instances_indices(void) 
{
   message += "test_get_testing_instances_indices\n";
 
   InputTargetDataSet itds;

   Vector<int> testing_instances_indices;

   testing_instances_indices = itds.get_testing_instances_indices();

   assert_true(testing_instances_indices.get_size() == 0, LOG);
   
   itds.set(1, 1, 1);

   testing_instances_indices = itds.get_testing_instances_indices();

   assert_true(testing_instances_indices.get_size() == 0, LOG);
}


// void test_get_input_variables_number(void) method

void TestInputTargetDataSet::test_get_input_variables_number(void) 
{
   message += "test_get_input_variables_number\n";

   InputTargetDataSet itds;

   assert_true(itds.get_input_variables_number() == 0, LOG);
}


// void test_get_input_variables_indices(void) method

void TestInputTargetDataSet::test_get_input_variables_indices(void)
{
   message += "test_get_input_variables_indices\n";

   InputTargetDataSet itds;

   Vector<int> input_variables_indices = itds.get_input_variables_indices();

   assert_true(input_variables_indices.get_size() == 0, LOG);
}


// void test_get_target_variables_number(void) method

void TestInputTargetDataSet::test_get_target_variables_number(void) 
{
   message += "test_get_target_variables_number\n";

   InputTargetDataSet itds;

   assert_true(itds.get_target_variables_number() == 0, LOG);
}


// void test_get_target_variables_indices(void) method

void TestInputTargetDataSet::test_get_target_variables_indices(void)
{
   message += "test_get_target_variables_indices\n";

   InputTargetDataSet itds;

   Vector<int> target_variables_indices = itds.get_target_variables_indices();

   assert_true(target_variables_indices.get_size() == 0, LOG);
}


// void test_get_variables_name(void) method

void TestInputTargetDataSet::test_get_variables_name(void)
{
   message += "test_get_variables_name\n";

   InputTargetDataSet itds;

   Vector<std::string> variables_name = itds.get_variables_name();

   assert_true(variables_name.get_size() == 0, LOG);
}


// void test_get_variable_name(void) method

void TestInputTargetDataSet::test_get_variable_name(void)
{
   message += "test_get_variable_name\n";
}


// void test_get_input_variables_name(void) method

void TestInputTargetDataSet::test_get_input_variables_name(void)
{
   message += "test_get_input_variables_name\n";
}


// void test_get_target_variables_name(void) method

void TestInputTargetDataSet::test_get_target_variables_name(void)
{
   message += "test_get_target_variables_name\n";
}


// void test_get_variables_units(void) method

void TestInputTargetDataSet::test_get_variables_units(void)
{
   message += "test_get_variables_units\n";

   InputTargetDataSet itds;

   Vector<std::string> variables_units = itds.get_variables_units();

   assert_true(variables_units.get_size() == 0, LOG);
}


// void test_get_variable_units(void) method

void TestInputTargetDataSet::test_get_variable_units(void)
{
   message += "test_get_variable_units\n";
}


// void test_get_input_variables_units(void) method

void TestInputTargetDataSet::test_get_input_variables_units(void)
{
   message += "test_get_input_variables_units\n";
}


// void test_get_target_variables_units(void) method

void TestInputTargetDataSet::test_get_target_variables_units(void)
{
   message += "test_get_target_variables_units\n";
}


// void test_get_variables_description(void) method

void TestInputTargetDataSet::test_get_variables_description(void)
{
   message += "test_get_variables_description\n";

   InputTargetDataSet itds;

   Vector<std::string> variables_description = itds.get_variables_description();

   assert_true(variables_description.get_size() == 0, LOG);
}


// void test_get_variable_description(void) method

void TestInputTargetDataSet::test_get_variable_description(void)
{
   message += "test_get_variable_description\n";
}


// void test_get_input_variables_description(void) method

void TestInputTargetDataSet::test_get_input_variables_description(void)
{
   message += "test_get_input_variables_description\n";
}


// void test_get_target_variables_description(void) method

void TestInputTargetDataSet::test_get_target_variables_description(void)
{
   message += "test_get_target_variables_description\n";
}


// void test_get_variables_information(void) method

void TestInputTargetDataSet::test_get_variables_information(void) 
{
   message += "test_get_variables_information\n";

   InputTargetDataSet itds(1,3,2);

   Vector< Vector<std::string> > variables_information = itds.get_variables_information();

   int size = variables_information.get_size();

   assert_true(size == 6, LOG);

}


// void test_get_display(void) method

void TestInputTargetDataSet::test_get_display(void) 
{
   message += "test_get_display\n";

   InputTargetDataSet itds;

   itds.set_display(true);

   assert_true(itds.get_display() == true, LOG);

   itds.set_display(false);

   assert_true(itds.get_display() == false, LOG);
}


// void test_get_data(void) method

void TestInputTargetDataSet::test_get_data(void) 
{
   message += "test_get_data\n";

   InputTargetDataSet itds(1,1,1);

   itds.initialize_data(0.0);

   Matrix<double>& data = itds.get_data();

   assert_true(data.get_rows_number() == 1, LOG);
   assert_true(data.get_columns_number() == 2, LOG);
   assert_true(data == 0.0, LOG);
}


// void test_get_training_data(void) method

void TestInputTargetDataSet::test_get_training_data(void)
{
   message += "test_get_training_data\n";
}


// void test_get_validation_data(void) method

void TestInputTargetDataSet::test_get_validation_data(void)
{
   message += "test_get_validation_data\n";
}


// void test_get_testing_data(void) method

void TestInputTargetDataSet::test_get_testing_data(void)
{
   message += "test_get_testing_data\n";
}


// void test_get_input_data(void) method

void TestInputTargetDataSet::test_get_input_data(void) 
{
   message += "test_get_input_data\n";

   InputTargetDataSet itds(1,3,2);

   int instances_number = itds.get_instances_number();
   int input_variables_number = itds.get_input_variables_number();

   Matrix<double> input_data = itds.get_input_data();

   int rows_number = input_data.get_rows_number();
   int columns_number = input_data.get_columns_number();

   assert_true(instances_number == rows_number, LOG);
   assert_true(input_variables_number == columns_number, LOG);
}


// void test_get_target_data(void) method

void TestInputTargetDataSet::test_get_target_data(void) 
{
   message += "test_get_target_data\n";

   InputTargetDataSet itds(1,3,2);

   int instances_number = itds.get_instances_number();
   int target_variables_number = itds.get_target_variables_number();

   Matrix<double> target_data = itds.get_target_data();

   int rows_number = target_data.get_rows_number();
   int columns_number = target_data.get_columns_number();

   assert_true(instances_number == rows_number, LOG);
   assert_true(target_variables_number == columns_number, LOG);
}


// void test_get_instance(void) method

void TestInputTargetDataSet::test_get_instance(void)
{
   message += "test_get_instance\n";

   InputTargetDataSet itds(1, 1, 1);

   itds.initialize_data(1.0);

   Vector<double> instance = itds.get_instance(0);

   assert_true(instance.get_size() == 2, LOG);
   assert_true(instance == 1.0, LOG);
}


// void test_get_training_instance(void) method

void TestInputTargetDataSet::test_get_training_instance(void)
{
   message += "test_get_training_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_training();

   Vector<double> training_instance = itds.get_training_instance(0);

   assert_true(training_instance.get_size() == 2, LOG);
   assert_true(training_instance == 0.0, LOG);
}


// void test_get_validation_instance(void) method

void TestInputTargetDataSet::test_get_validation_instance(void)
{
   message += "test_get_validation_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_validation();

   Vector<double> validation_instance = itds.get_validation_instance(0);

   assert_true(validation_instance.get_size() == 2, LOG);
   assert_true(validation_instance == 0.0, LOG);
}


// void test_get_testing_instance(void) method

void TestInputTargetDataSet::test_get_testing_instance(void)
{
   message += "test_get_testing_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_testing();

   Vector<double> testing_instance = itds.get_testing_instance(0);

   assert_true(testing_instance.get_size() == 2, LOG);
   assert_true(testing_instance == 0.0, LOG);
}


// void test_get_input_instance(void) method

void TestInputTargetDataSet::test_get_input_instance(void)
{
   message += "test_get_input_instance\n";

   InputTargetDataSet itds(1, 1, 1);

   itds.initialize_data(1.0);

   Vector<double> input_instance = itds.get_input_instance(0);

   assert_true(input_instance.get_size() == 1, LOG);
   assert_true(input_instance == 1.0, LOG);
}


// void test_get_target_instance(void) method

void TestInputTargetDataSet::test_get_target_instance(void)
{
   message += "test_get_target_instance\n";

   InputTargetDataSet itds(1, 1, 1);

   itds.initialize_data(1.0);

   Vector<double> target_instance = itds.get_target_instance(0);

   assert_true(target_instance.get_size() == 1, LOG);
   assert_true(target_instance == 1.0, LOG);
}


// void test_get_training_input_instance(void) method

void TestInputTargetDataSet::test_get_training_input_instance(void) 
{
   message += "test_get_training_input_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_training();

   Vector<double> training_input_instance = itds.get_training_input_instance(0);

   assert_true(training_input_instance.get_size() == 1, LOG);
   assert_true(training_input_instance == 0.0, LOG);
}


// void test_get_training_target_instance(void) method

void TestInputTargetDataSet::test_get_training_target_instance(void) 
{
   message += "test_get_training_target_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_training();

   Vector<double> training_target_instance = itds.get_training_target_instance(0);

   assert_true(training_target_instance.get_size() == 1, LOG);
   assert_true(training_target_instance == 0.0, LOG);
}


// void test_get_validation_input_instance(void) method

void TestInputTargetDataSet::test_get_validation_input_instance(void) 
{
   message += "test_get_validation_input_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_validation();

   Vector<double> validation_input_instance = itds.get_validation_input_instance(0);

   assert_true(validation_input_instance.get_size() == 1, LOG);
   assert_true(validation_input_instance == 0.0, LOG);
}


// void test_get_validation_target_instance(void) method

void TestInputTargetDataSet::test_get_validation_target_instance(void) 
{
   message += "test_get_validation_target_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_validation();

   Vector<double> validation_target_instance = itds.get_validation_target_instance(0);

   assert_true(validation_target_instance.get_size() == 1, LOG);
   assert_true(validation_target_instance == 0.0, LOG);
}


// void test_get_testing_input_instance(void) method

void TestInputTargetDataSet::test_get_testing_input_instance(void) 
{
   message += "test_get_testing_input_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_testing();

   Vector<double> testing_input_instance = itds.get_testing_input_instance(0);

   assert_true(testing_input_instance.get_size() == 1, LOG);
   assert_true(testing_input_instance == 0.0, LOG);
}


// void test_get_testing_target_instance(void) method

void TestInputTargetDataSet::test_get_testing_target_instance(void) 
{
   message += "test_get_testing_target_instance\n";

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);
   itds.set_testing();

   Vector<double> testing_target_instance = itds.get_testing_target_instance(0);

   assert_true(testing_target_instance.get_size() == 1, LOG);
   assert_true(testing_target_instance == 0.0, LOG);
}


// void test_set(void) method

void TestInputTargetDataSet::test_set(void) 
{
   message += "test_set\n";

   InputTargetDataSet itds;

   // Instances and input and target variables

   itds.set(1, 2, 3);

   assert_true(itds.get_instances_number() == 1, LOG);
   assert_true(itds.get_input_variables_number() == 2, LOG);
   assert_true(itds.get_target_variables_number() == 3, LOG);

   Matrix<double>& data = itds.get_data();

   assert_true(data.get_rows_number() == 1, LOG);
   assert_true(data.get_columns_number() == 5, LOG);

   itds.set(0,0,0);

   assert_true(itds.get_instances_number() == 0, LOG);
   assert_true(itds.get_input_variables_number() == 0, LOG);
   assert_true(itds.get_target_variables_number() == 0, LOG);

   data = itds.get_data();

   assert_true(data.get_rows_number() == 0, LOG);
   assert_true(data.get_columns_number() == 0, LOG);

   // Instances and variables

   // Default 

   // File 
}


// void test_set_instances_number(void) method

void TestInputTargetDataSet::test_set_instances_number(void) 
{
   message += "test_set_instances_number\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_instances_number(2);

   assert_true(itds.get_instances_number() == 2, LOG);
}


// void test_set_variables_number(void) method

void TestInputTargetDataSet::test_set_variables_number(void) 
{
   message += "test_set_variables_number\n";

   InputTargetDataSet itds(1,1);

   itds.set_variables_number(2);

   assert_true(itds.get_variables_number() == 2, LOG);
}


// void test_set_training_instances_indices(void) method

void TestInputTargetDataSet::test_set_training_instances_indices(void)
{
   message += "test_set_training_instances_indices\n";

   InputTargetDataSet itds(1,1,1);

   Vector<int> new_training_instances_indices(1, 0);

   itds.set_training_instances_indices(new_training_instances_indices);

   Vector<int> training_instances_indices = itds.get_training_instances_indices();

   assert_true(training_instances_indices == new_training_instances_indices, LOG);
}


// void test_set_validation_instances_indices(void) method

void TestInputTargetDataSet::test_set_validation_instances_indices(void)
{
   message += "test_set_validation_instances_indices\n";

   InputTargetDataSet itds(1,1,1);

   Vector<int> new_validation_instances_indices(1, 0);

   itds.set_validation_instances_indices(new_validation_instances_indices);

   Vector<int> validation_instances_indices = itds.get_validation_instances_indices();

   assert_true(validation_instances_indices == new_validation_instances_indices, LOG);
}


// void test_set_testing_instances_indices(void) method

void TestInputTargetDataSet::test_set_testing_instances_indices(void)
{
   message += "test_set_testing_instances_indices\n";

   InputTargetDataSet itds(1,1,1);

   Vector<int> new_testing_instances_indices(1, 0);

   itds.set_testing_instances_indices(new_testing_instances_indices);

   Vector<int> testing_instances_indices = itds.get_testing_instances_indices();

   assert_true(testing_instances_indices == new_testing_instances_indices, LOG);
}


// void test_set_training(void) method

void TestInputTargetDataSet::test_set_training(void)
{
   message += "test_set_training\n";
   
   InputTargetDataSet itds(1,1,1);
   itds.set_training();

   assert_true(itds.get_training_instances_number() == 1, LOG);
   assert_true(itds.get_validation_instances_number() == 0, LOG);
   assert_true(itds.get_testing_instances_number() == 0, LOG);

   assert_true(itds.get_training_instances_indices() == 0, LOG);
}


// void test_set_validation(void) method

void TestInputTargetDataSet::test_set_validation(void)
{
   message += "test_set_validation\n";

   InputTargetDataSet itds(1,1,1);
   itds.set_validation();

   assert_true(itds.get_training_instances_number() == 0, LOG);
   assert_true(itds.get_validation_instances_number() == 1, LOG);
   assert_true(itds.get_testing_instances_number() == 0, LOG);

   assert_true(itds.get_validation_instances_indices() == 0, LOG);
}


// void test_set_testing(void) method

void TestInputTargetDataSet::test_set_testing(void)
{
   message += "test_set_testing\n";

   InputTargetDataSet itds(1,1,1);
   itds.set_testing();

   assert_true(itds.get_training_instances_number() == 0, LOG);
   assert_true(itds.get_validation_instances_number() == 0, LOG);
   assert_true(itds.get_testing_instances_number() == 1, LOG);

   assert_true(itds.get_testing_instances_indices() == 0, LOG);
}


// void test_set_input_variables_indices(void) method

void TestInputTargetDataSet::test_set_input_variables_indices(void)
{
   message += "test_set_input_variables_indices\n";
}


// void test_set_target_variables_indices(void) method

void TestInputTargetDataSet::test_set_target_variables_indices(void)
{
   message += "test_set_target_variables_indices\n";
}


// void test_set_input(void) method

void TestInputTargetDataSet::test_set_input(void)
{
   message += "test_set_input\n";
}


// void test_set_target(void) method

void TestInputTargetDataSet::test_set_target(void)
{
   message += "test_set_target\n";
}


// void test_set_variables_name(void) method

void TestInputTargetDataSet::test_set_variables_name(void)
{
   message += "test_set_variables_name\n";
}


// void test_set_variable_name(void) method

void TestInputTargetDataSet::test_set_variable_name(void)
{
   message += "test_set_variable_name\n";
}


// void test_set_variables_units(void) method

void TestInputTargetDataSet::test_set_variables_units(void)
{
   message += "test_set_variables_units\n";
}


// void test_set_variable_units(void) method

void TestInputTargetDataSet::test_set_variable_units(void)
{
   message += "test_set_variable_units\n";
}


// void test_set_variables_description(void) method

void TestInputTargetDataSet::test_set_variables_description(void)
{
   message += "test_set_variables_description\n";
}


// void test_set_variable_description(void) method

void TestInputTargetDataSet::test_set_variable_description(void)
{
   message += "test_set_variable_description\n";
}


// void test_set_display(void) method

void TestInputTargetDataSet::test_set_display(void) 
{
   message += "test_set_display\n";
}


// void test_set_data(void) method

void TestInputTargetDataSet::test_set_data(void) 
{
   message += "test_set_data\n";

   InputTargetDataSet itds(1, 1, 1);

   Matrix<double> new_data(1, 2, 0.0);

   itds.set_data(new_data);

   Matrix<double> data = itds.get_data();

   assert_true(data == new_data, LOG);
}


// void test_set_instance(void) method

void TestInputTargetDataSet::test_set_instance(void)
{
   message += "test_set_instance\n";

   InputTargetDataSet itds(1, 1, 1);

   Vector<double> new_instance(2, 0.0);

   itds.set_instance(0, new_instance);

   Vector<double> instance = itds.get_instance(0);

   assert_true(instance == new_instance, LOG);
}


// void test_set_training_instance(void) method

void TestInputTargetDataSet::test_set_training_instance(void)
{
   message += "test_set_training_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_training();

   Vector<double> new_training_instance(2, 0.0);

   itds.set_training_instance(0, new_training_instance);

   Vector<double> training_instance = itds.get_training_instance(0);

   assert_true(training_instance == new_training_instance, LOG);
}


// void test_set_validation_instance(void) method

void TestInputTargetDataSet::test_set_validation_instance(void)
{
   message += "test_set_validation_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_validation();

   Vector<double> new_validation_instance(2, 0.0);

   itds.set_validation_instance(0, new_validation_instance);

   Vector<double> validation_instance = itds.get_validation_instance(0);

   assert_true(validation_instance == new_validation_instance, LOG);
}


// void test_set_testing_instance(void) method

void TestInputTargetDataSet::test_set_testing_instance(void)
{
   message += "test_set_testing_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_testing();

   Vector<double> new_testing_instance(2, 0.0);

   itds.set_testing_instance(0, new_testing_instance);

   Vector<double> testing_instance = itds.get_testing_instance(0);

   assert_true(testing_instance == new_testing_instance, LOG);
}


// void test_set_input_instance(void)

void TestInputTargetDataSet::test_set_input_instance(void)
{
   message += "test_set_input_instance\n";
}


// void test_set_target_instance(void)

void TestInputTargetDataSet::test_set_target_instance(void)
{
   message += "test_set_target_instance\n";
}


// void test_set_training_input_instance(void) method

void TestInputTargetDataSet::test_set_training_input_instance(void)
{
   message += "test_set_training_input_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_training();

   Vector<double> new_training_input_instance(1, 0.0);

   itds.set_training_input_instance(0, new_training_input_instance);

   Vector<double> training_input_instance = itds.get_training_input_instance(0);

   assert_true(training_input_instance == new_training_input_instance, LOG);
}


// void test_set_training_target_instance(void) method

void TestInputTargetDataSet::test_set_training_target_instance(void)
{
   message += "test_set_training_target_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_training();

   Vector<double> new_training_target_instance(1, 0.0);

   itds.set_training_target_instance(0, new_training_target_instance);

   Vector<double> training_target_instance = itds.get_training_target_instance(0);

   assert_true(training_target_instance == new_training_target_instance, LOG);
}


// void test_set_validation_input_instance(void) method

void TestInputTargetDataSet::test_set_validation_input_instance(void)
{
   message += "test_set_validation_input_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_validation();

   Vector<double> new_validation_input_instance(1, 0.0);

   itds.set_validation_input_instance(0, new_validation_input_instance);

   Vector<double> validation_input_instance = itds.get_validation_input_instance(0);

   assert_true(validation_input_instance == new_validation_input_instance, LOG);
}


// void test_set_validation_target_instance(void) method

void TestInputTargetDataSet::test_set_validation_target_instance(void)
{
   message += "test_set_validation_target_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_validation();

   Vector<double> new_validation_target_instance(1, 0.0);

   itds.set_validation_target_instance(0, new_validation_target_instance);

   Vector<double> validation_target_instance = itds.get_validation_target_instance(0);

   assert_true(validation_target_instance == new_validation_target_instance, LOG);
}


// void test_set_testing_input_instance(void) method

void TestInputTargetDataSet::test_set_testing_input_instance(void)
{
   message += "test_set_testing_input_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_testing();

   Vector<double> new_testing_input_instance(1, 0.0);

   itds.set_testing_input_instance(0, new_testing_input_instance);

   Vector<double> testing_input_instance = itds.get_testing_input_instance(0);

   assert_true(testing_input_instance == new_testing_input_instance, LOG);
}


// void test_set_testing_target_instance(void) method

void TestInputTargetDataSet::test_set_testing_target_instance(void)
{
   message += "test_set_testing_target_instance\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_testing();

   Vector<double> new_testing_target_instance(1, 0.0);

   itds.set_testing_target_instance(0, new_testing_target_instance);

   Vector<double> testing_target_instance = itds.get_testing_target_instance(0);

   assert_true(testing_target_instance == new_testing_target_instance, LOG);
}


// void test_add_instance(void) method

void TestInputTargetDataSet::test_add_instance(void) 
{
   message += "test_add_instance\n";

   InputTargetDataSet itds(1,1,1);

   Vector<double> new_instance(2, 0.0);

   itds.add_instance(new_instance);

   assert_true(itds.get_instances_number() == 2, LOG);

   Vector<double> instance = itds.get_instance(1);

   assert_true(instance == new_instance, LOG);
}


// void test_subtract_instance(void) method

void TestInputTargetDataSet::test_subtract_instance(void) 
{
   message += "test_subtract_instance\n";

   InputTargetDataSet itds(3, 1, 1);

   itds.subtract_instance(1);

   assert_true(itds.get_instances_number() == 2, LOG);
}


// void test_calculate_data_statistics(void) method

void TestInputTargetDataSet::test_calculate_data_statistics(void) 
{
   message += "test_calculate_data_statistics\n";

   InputTargetDataSet itds(2,2,2);
   itds.initialize_data(0.0);

   Vector< Vector<double> > statistics = itds.calculate_data_statistics();

   assert_true(statistics.get_size() == 4, LOG);
   assert_true(statistics[0] == 0.0, LOG);
   assert_true(statistics[1] == 0.0, LOG);
   assert_true(statistics[2] == 0.0, LOG);
   assert_true(statistics[3] == 0.0, LOG);
}


// void test_calculate_training_instances_statistics(void)

void TestInputTargetDataSet::test_calculate_training_instances_statistics(void)
{
   message += "test_calculate_training_instances_statistics\n";

   InputTargetDataSet itds(2,2,2);
   itds.set_training();
   itds.initialize_data(0.0);

   Vector< Vector<double> > training_instances_statistics = itds.calculate_training_instances_statistics();

}


// void test_calculate_validation_instances_statistics(void)

void TestInputTargetDataSet::test_calculate_validation_instances_statistics(void)
{
   message += "test_calculate_validation_instances_statistics\n";

   InputTargetDataSet itds(2,2,2);
   itds.set_validation();
   itds.initialize_data(0.0);

   Vector< Vector<double> > validation_instances_statistics = itds.calculate_validation_instances_statistics();

}


// void test_calculate_testing_instances_statistics(void)

void TestInputTargetDataSet::test_calculate_testing_instances_statistics(void)
{
   message += "test_calculate_testing_instances_statistics\n";

   InputTargetDataSet itds(2,2,2);
   itds.set_testing();
   itds.initialize_data(0.0);

   Vector< Vector<double> > testing_instances_statistics = itds.calculate_testing_instances_statistics();

}


// void test_calculate_instances_statistics(void) method

void TestInputTargetDataSet::test_calculate_instances_statistics(void)
{
   message += "test_calculate_instances_statistics\n";

   InputTargetDataSet itds(6,2,2);
   itds.split_random_indices(2,2,2);
   itds.initialize_data(0.0);

   Vector< Vector<double> > instances_statistics = itds.calculate_instances_statistics();

}


// void test_calculate_input_variables_statistics(void)

void TestInputTargetDataSet::test_calculate_input_variables_statistics(void)
{
   message += "test_calculate_input_variables_statistics\n";

}


// void test_calculate_target_variables_statistics(void)

void TestInputTargetDataSet::test_calculate_target_variables_statistics(void)
{
   message += "test_calculate_target_variables_statistics\n";

}


// void test_calculate_variables_statistics(void)

void TestInputTargetDataSet::test_calculate_variables_statistics(void)
{
   message += "test_calculate_variables_statistics\n";

}


// void test_scale_data_mean_standard_deviation(void) method

void TestInputTargetDataSet::test_scale_data_mean_standard_deviation(void)  
{
   message += "test_scale_data_mean_standard_deviation\n";
}


// void test_scale_data_minimum_maximum(void) method

void TestInputTargetDataSet::test_scale_data_minimum_maximum(void) 
{
   message += "test_scale_data_minimum_maximum\n";
}


// void test_scale_input_variables_mean_standard_deviation(void) method

void TestInputTargetDataSet::test_scale_input_variables_mean_standard_deviation(void) 
{
   message += "test_scale_input_variables_mean_standard_deviation\n";

   InputTargetDataSet itds(2, 2, 2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> input_data = itds.get_input_data();

   Vector<double> mean(2, 0.0);
   Vector<double> standard_deviation(2, 1.0);

   itds.scale_input_variables_mean_standard_deviation(mean, standard_deviation);

   Matrix<double> new_input_data = itds.get_input_data();

   assert_true(new_input_data == input_data, LOG);

}


// void test_scale_target_variables_mean_standard_deviation(void) method

void TestInputTargetDataSet::test_scale_target_variables_mean_standard_deviation(void) 
{
   message += "test_scale_target_variables_mean_standard_deviation\n";

   InputTargetDataSet itds(2,2,2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> target_data = itds.get_target_data();

   Vector<double> mean(2, 0.0);
   Vector<double> standard_deviation(2, 1.0);

   itds.scale_target_variables_mean_standard_deviation(mean, standard_deviation);

   Matrix<double> new_target_data = itds.get_target_data();

   assert_true(new_target_data == target_data, LOG);
}


// void test_scale_input_variables_minimum_maximum(void) method

void TestInputTargetDataSet::test_scale_input_variables_minimum_maximum(void) 
{
   message += "test_scale_input_variables_minimum_maximum\n";

   InputTargetDataSet itds(2, 2, 2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> input_data = itds.get_input_data();

   Vector<double> minimum(2, -1.0);
   Vector<double> maximum(2,  1.0);

   itds.scale_input_variables_minimum_maximum(minimum, maximum);

   Matrix<double> new_input_data = itds.get_input_data();

   assert_true(new_input_data == input_data, LOG);
}


// void test_scale_target_variables_minimum_maximum(void) method

void TestInputTargetDataSet::test_scale_target_variables_minimum_maximum(void) 
{
   message += "test_scale_target_variables_minimum_maximum\n";

   InputTargetDataSet itds(2,2,2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> target_data = itds.get_target_data();

   Vector<double> minimum(2, -1.0);
   Vector<double> maximum(2,  1.0);

   itds.scale_target_variables_minimum_maximum(minimum, maximum);

   Matrix<double> new_target_data = itds.get_target_data();

   assert_true(new_target_data == target_data, LOG);

}


// void test_scale_variables_mean_standard_deviation(void) method

void TestInputTargetDataSet::test_scale_variables_mean_standard_deviation(void) 
{
   message += "test_scale_variables_mean_standard_deviation\n";
  
   InputTargetDataSet itds(2, 2, 2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> data = itds.get_data();

   Vector< Vector<double> > statistics = itds.scale_variables_mean_standard_deviation();

   Matrix<double> new_data = itds.get_data();
   
   assert_true(statistics.get_size() == 8, LOG);
   assert_true(new_data == data, LOG);
}


// void test_scale_variables_minimum_maximum(void) method

void TestInputTargetDataSet::test_scale_variables_minimum_maximum(void) 
{
   message += "test_scale_variables_minimum_maximum\n";
   
   InputTargetDataSet itds(2,2,2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> data = itds.get_data();

   Vector< Vector<double> > statistics = itds.scale_variables_minimum_maximum();

   Matrix<double> new_data = itds.get_data();
   
   assert_true(statistics.get_size() == 8, LOG);
   assert_true(new_data == data, LOG);
}


// void test_unscale_data_mean_standard_deviation(void) method

void TestInputTargetDataSet::test_unscale_data_mean_standard_deviation(void)
{
   message += "test_unscale_data_mean_standard_deviation\n";
}


// void test_unscale_data_minimum_maximum(void) method

void TestInputTargetDataSet::test_unscale_data_minimum_maximum(void)
{
   message += "test_unscale_data_minimum_maximum\n";
}


// void test_unscale_input_variables_mean_standard_deviation(void) method

void TestInputTargetDataSet::test_unscale_input_variables_mean_standard_deviation(void) 
{
   message += "test_unscale_input_variables_mean_standard_deviation\n";
   
   InputTargetDataSet itds(2, 2, 2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> input_data = itds.get_input_data();

   Vector<double> mean(2, 0.0);
   Vector<double> standard_deviation(2, 1.0);

   itds.unscale_input_variables_mean_standard_deviation(mean, standard_deviation);

   Matrix<double> new_input_data = itds.get_input_data();

   assert_true(new_input_data == input_data, LOG);

}


// void test_unscale_target_variables_mean_standard_deviation(void) method

void TestInputTargetDataSet::test_unscale_target_variables_mean_standard_deviation(void) 
{
   message += "test_unscale_target_variables_mean_standard_deviation\n";
   
   InputTargetDataSet itds(2, 2, 2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> target_data = itds.get_target_data();

   Vector<double> mean(2, 0.0);
   Vector<double> standard_deviation(2, 1.0);

   itds.unscale_target_variables_mean_standard_deviation(mean, standard_deviation);

   Matrix<double> new_target_data = itds.get_target_data();

   assert_true(new_target_data == target_data, LOG);

}


// void test_unscale_variables_mean_standard_deviation(void) method

void TestInputTargetDataSet::test_unscale_variables_mean_standard_deviation(void) 
{
   message += "test_unscale_variables_mean_standard_deviation\n";
}


// void test_unscale_input_variables_minimum_maximum(void) method

void TestInputTargetDataSet::test_unscale_input_variables_minimum_maximum(void) 
{
   message += "test_unscale_input_variables_minimum_maximum\n"; 
}


// void test_unscale_target_variables_minimum_maximum(void) method

void TestInputTargetDataSet::test_unscale_target_variables_minimum_maximum(void) 
{
   message += "test_unscale_target_variables_minimum_maximum\n";
   
   InputTargetDataSet itds(2, 2, 2);
   itds.initialize_data(0.0);

   itds.set_display(false);

   Matrix<double> target_data = itds.get_target_data();

   Vector<double> minimum(2, -1.0);
   Vector<double> maximum(2,  1.0);

   itds.unscale_target_variables_minimum_maximum(minimum, maximum);

   Matrix<double> new_target_data = itds.get_target_data();

   assert_true(new_target_data == target_data, LOG);
}


// void test_unscale_variables_minimum_maximum(void) method

void TestInputTargetDataSet::test_unscale_variables_minimum_maximum(void) 
{
   message += "test_unscale_variables_minimum_maximum\n"; 
}


// void test_split_given_indices(void) method

void TestInputTargetDataSet::test_split_given_indices(void) 
{
   message += "test_split_given_indices\n";
   
   InputTargetDataSet itds(1,1,1);

   Vector<int> training_instances_indices;
   Vector<int> validation_instances_indices;
   Vector<int> testing_instances_indices(1, 1);

   itds.split_given_indices(training_instances_indices, validation_instances_indices, testing_instances_indices);

   assert_true(itds.get_training_instances_number() == 0, LOG);
   assert_true(itds.get_validation_instances_number() == 0, LOG);
   assert_true(itds.get_testing_instances_number() == 1, LOG);
}


// void test_split_random_indices(void) method

void TestInputTargetDataSet::test_split_random_indices(void) 
{
   message += "test_split_random_indices\n";

   int training_instances_number = 0;
   int validation_instances_number = 0;
   int testing_instances_number = 0;

   InputTargetDataSet itds(12,1,1);

   // All data for training

   itds.split_random_indices(1.0, 0.0, 0.0);
  
   training_instances_number = itds.get_training_instances_number();
   validation_instances_number = itds.get_validation_instances_number();
   testing_instances_number = itds.get_testing_instances_number();

   assert_true(training_instances_number == 12, LOG);
   assert_true(validation_instances_number == 0, LOG);
   assert_true(testing_instances_number == 0, LOG);

   // All data for validation 

   itds.split_random_indices(0.0, 10.0, 0.0);
  
   training_instances_number = itds.get_training_instances_number();
   validation_instances_number = itds.get_validation_instances_number();
   testing_instances_number = itds.get_testing_instances_number();

   assert_true(training_instances_number == 0, LOG);
   assert_true(validation_instances_number == 12, LOG);
   assert_true(testing_instances_number == 0, LOG);

   // All data for testing 

   itds.split_random_indices(0.0, 0.0, 100.0);
  
   training_instances_number = itds.get_training_instances_number();
   validation_instances_number = itds.get_validation_instances_number();
   testing_instances_number = itds.get_testing_instances_number();

   assert_true(training_instances_number == 0, LOG);
   assert_true(validation_instances_number == 0, LOG);
   assert_true(testing_instances_number == 12, LOG);

   // Split data for training, validation and testing

   itds.split_random_indices(0.5, 0.25, 0.25);
  
   training_instances_number = itds.get_training_instances_number();
   validation_instances_number = itds.get_validation_instances_number();
   testing_instances_number = itds.get_testing_instances_number();

   assert_true(training_instances_number == 6, LOG);
   assert_true(validation_instances_number == 3, LOG);
   assert_true(testing_instances_number == 3, LOG);

   // Split data for training, validation and testing

   itds.split_random_indices(2.0, 1.0, 1.0);
  
   training_instances_number = itds.get_training_instances_number();
   validation_instances_number = itds.get_validation_instances_number();
   testing_instances_number = itds.get_testing_instances_number();

   assert_true(training_instances_number == 6, LOG);
   assert_true(validation_instances_number == 3, LOG);
   assert_true(testing_instances_number == 3, LOG);
}


// void test_initialize_data(void) method

void TestInputTargetDataSet::test_initialize_data(void)
{
   message += "test_initialize_data\n";
}



















// void test_to_XML(void) method

void TestInputTargetDataSet::test_to_XML(void) 
{
   message += "test_to\n";

   InputTargetDataSet itds;

   std::string object = itds.to_XML(true);
}


// void test_print(void) method

void TestInputTargetDataSet::test_print(void) 
{
   message += "test_print\n";

   InputTargetDataSet itds;

   itds.set_display(false);

   itds.print();
}


// void test_save(void) method

void TestInputTargetDataSet::test_save(void) 
{
   message += "test_save\n";
 
   InputTargetDataSet itds;

   itds.set_display(false);

   itds.save("../Data/InputTargetDataSet.dat");
}


// void test_load(void) method

void TestInputTargetDataSet::test_load(void) 
{
   message += "test_load\n";
 
   InputTargetDataSet itds;

   itds.save("../Data/InputTargetDataSet.dat");
   itds.load("../Data/InputTargetDataSet.dat");

   itds.set(1,1,1);

   itds.set_variable_name(0, "x");
   itds.set_variable_units(0, "[m]");
   itds.set_variable_description(0, "distance");

   itds.set_variable_name(1, "y");
   itds.set_variable_units(1, "[s]");
   itds.set_variable_description(1, "time");

   itds.save("../Data/InputTargetDataSet.dat");
   itds.load("../Data/InputTargetDataSet.dat");

   assert_true(itds.get_variable_name(0) == "x", LOG);
   assert_true(itds.get_variable_units(0) == "[m]", LOG);
   assert_true(itds.get_variable_description(0) == "distance", LOG);

   assert_true(itds.get_variable_name(1) == "y", LOG);
   assert_true(itds.get_variable_units(1) == "[s]", LOG);
   assert_true(itds.get_variable_description(1) == "time", LOG);
}


// void test_print_data(void) method

void TestInputTargetDataSet::test_print_data(void)
{
   message += "test_print_data\n";
}


// void test_save_data(void) method

void TestInputTargetDataSet::test_save_data(void)
{
   message += "test_save_data\n";

   InputTargetDataSet itds(2,2,2);

   itds.set_display(false);

   itds.save_data("../Data/Data.dat");
}


// void test_load_data(void) method

void TestInputTargetDataSet::test_load_data(void) 
{
   message += "test_load_data\n";
 
   InputTargetDataSet itds(2, 2, 2);

   itds.initialize_data(0.0);

   itds.set_display(false);

   itds.save_data("../Data/InputTargetDataSet.dat");

   itds.load_data("../Data/InputTargetDataSet.dat");

   Matrix<double> data = itds.get_data();

   assert_true(itds.get_data() == 0.0, LOG);
}


// void test_get_instances_information(void) method

void TestInputTargetDataSet::test_get_instances_information(void)
{
   message += "test_get_instances_information\n";
}


// void test_print_instances_information(void) method

void TestInputTargetDataSet::test_print_instances_information(void)
{
   message += "test_get_instances_information\n";
}


// void test_save_instances_information(void) method

void TestInputTargetDataSet::test_save_instances_information(void)
{
   message += "test_get_instances_information\n";
}


// void test_get_variables_information_XML(void) method

void TestInputTargetDataSet::test_get_variables_information_XML(void)
{
   message += "test_get_variables_information_XML\n";
 
}


// void test_print_variables_information(void) method

void TestInputTargetDataSet::test_print_variables_information(void)
{
   message += "test_print_variables_information\n";
 
}


// void test_save_variables_information(void) method

void TestInputTargetDataSet::test_save_variables_information(void)
{
   message += "test_save_variables_information\n";

   InputTargetDataSet itds(1,1,1);

   itds.set_variable_name(0, "x");
   itds.set_variable_units(0, "[m]");
   itds.set_variable_description(0, "distance");

   itds.set_variable_name(1, "y");
   itds.set_variable_units(1, "[s]");
   itds.set_variable_description(1, "time");

   std::string variables_information = itds.get_variables_information_XML(true);
}


// void test_get_data_statistics(void) method

void TestInputTargetDataSet::test_get_data_statistics(void)
{
   message += "test_get_data_statistics\n";

   InputTargetDataSet itds(1,1,1);
}


// void test_save_data_statistics(void) method

void TestInputTargetDataSet::test_save_data_statistics(void)
{
   message += "test_save_data_statistics\n";

   InputTargetDataSet itds(2,2,2);

   itds.initialize_data(0.0);

   itds.set_display(false);

   itds.save_data_statistics("../Data/Statistics.dat");
}


// void test_print_data_statistics(void) method

void TestInputTargetDataSet::test_print_data_statistics(void)
{
   message += "test_print_data_statistics\n";
}


// void test_get_training_instances_statistics(void) method

void TestInputTargetDataSet::test_get_training_instances_statistics(void)
{
   message += "test_get_training_instances_statistics\n";

}


// void test_save_training_instances_statistics(void) method

void TestInputTargetDataSet::test_save_training_instances_statistics(void)
{
   message += "test_save_training_instances_statistics\n";
}


// void test_print_training_instances_statistics(void) method

void TestInputTargetDataSet::test_print_training_instances_statistics(void)
{
   message += "test_print_training_instances_statistics\n";
}


// void test_get_validation_instances_statistics(void) method

void TestInputTargetDataSet::test_get_validation_instances_statistics(void)
{
   message += "test_get_validation_instances_statistics\n";
}


// void test_save_validation_instances_statistics(void) method

void TestInputTargetDataSet::test_save_validation_instances_statistics(void)
{
   message += "test_save_validation_instances_statistics\n";
}


// void test_print_validation_instances_statistics(void) method

void TestInputTargetDataSet::test_print_validation_instances_statistics(void)
{
   message += "test_print_validation_instances_statistics\n";
}


// void test_get_testing_instances_statistics(void) method

void TestInputTargetDataSet::test_get_testing_instances_statistics(void)
{
   message += "test_get_testing_instances_statistics\n";
}


// void test_save_testing_instances_statistics(void) method

void TestInputTargetDataSet::test_save_testing_instances_statistics(void)
{
   message += "test_save_testing_instances_statistics\n";
}


// void test_print_testing_instances_statistics(void) method

void TestInputTargetDataSet::test_print_testing_instances_statistics(void)
{
   message += "test_print_testing_instances_statistics\n";
}


// void test_get_instances_statistics(void) method

void TestInputTargetDataSet::test_get_instances_statistics(void)
{
   message += "test_get_instances_statistics\n";
}


// void test_save_instances_statistics(void) method

void TestInputTargetDataSet::test_save_instances_statistics(void)
{
   message += "test_save_instances_statistics\n";
}


// void test_print_instances_statistics(void) method

void TestInputTargetDataSet::test_print_instances_statistics(void)
{
   message += "test_print_instances_statistics\n";
}


// void run_test_case(void) method

void TestInputTargetDataSet::run_test_case(void)
{
   message += "Running input-target data set test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   test_get_instances_number();
   test_get_variables_number();

   // Instances methods 

   test_get_training_instances_number();
   test_get_training_instances_indices();

   test_get_validation_instances_number();
   test_get_validation_instances_indices();

   test_get_testing_instances_number();
   test_get_testing_instances_indices();

   // Variables methods

   test_get_input_variables_number();
   test_get_input_variables_indices();

   test_get_target_variables_number();
   test_get_target_variables_indices();

   // Information methods

   test_get_variables_name();
   test_get_variable_name();

   test_get_input_variables_name();
   test_get_target_variables_name();

   test_get_variables_units();
   test_get_variable_units();

   test_get_input_variables_units();
   test_get_target_variables_units();

   test_get_variables_description();
   test_get_variable_description();

   test_get_input_variables_description();
   test_get_target_variables_description();
 
   test_get_variables_information();

   test_get_display();

   // Data methods

   test_get_data();

   test_get_training_data();
   test_get_validation_data();
   test_get_testing_data();

   test_get_input_data();
   test_get_target_data();

   // Instance methods

   test_get_instance();

   test_get_training_instance();
   test_get_validation_instance();
   test_get_testing_instance();

   test_get_input_instance();
   test_get_target_instance();

   test_get_training_input_instance();
   test_get_training_target_instance();

   test_get_validation_input_instance();
   test_get_validation_target_instance();

   test_get_testing_target_instance();
   test_get_testing_input_instance();

   // Set methods

   test_set();

   // Instances methods

   test_set_training_instances_indices();
   test_set_validation_instances_indices();
   test_set_testing_instances_indices();

   test_set_training();
   test_set_validation();
   test_set_testing();

   // Variables methods

   test_set_input_variables_indices();
   test_set_target_variables_indices();

   test_set_input();
   test_set_target();

   // Information methods

   test_set_variables_name();
   test_set_variable_name();

   test_set_variables_units();
   test_set_variable_units();

   test_set_variables_description();
   test_set_variable_description();

   test_set_display();

   // Data methods

   test_set_data();

   test_set_instances_number();
   test_set_variables_number();

   // Instance methods

   test_set_instance();

   test_set_training_instance();
   test_set_validation_instance();
   test_set_testing_instance();

   test_set_input_instance();
   test_set_target_instance();

   test_set_training_input_instance();
   test_set_training_target_instance();
   
   test_set_validation_target_instance();
   test_set_validation_input_instance();

   test_set_testing_input_instance();
   test_set_testing_target_instance();

   // Data resizing methods

   test_add_instance();
   test_subtract_instance();

   // Data splitting methods

   test_split_given_indices();
   test_split_random_indices();

   // Initialization methods

   test_initialize_data();

   // Statistics methods

   test_calculate_data_statistics();

   test_calculate_training_instances_statistics();
   test_calculate_validation_instances_statistics();
   test_calculate_testing_instances_statistics();

   test_calculate_instances_statistics();

   test_calculate_input_variables_statistics();
   test_calculate_target_variables_statistics();
  
   test_calculate_variables_statistics();

   // Data scaling

   test_scale_data_mean_standard_deviation();  
   test_scale_data_minimum_maximum(); 

   // Input variables scaling

   test_scale_input_variables_mean_standard_deviation();
   test_scale_input_variables_minimum_maximum();

   // Target variables scaling

   test_scale_target_variables_mean_standard_deviation();
   test_scale_target_variables_minimum_maximum();

   // Input-target variables scaling

   test_scale_variables_mean_standard_deviation();
   test_scale_variables_minimum_maximum();

   // Data unscaling

   test_unscale_data_mean_standard_deviation();
   test_unscale_data_minimum_maximum();

   // Input variables unscaling

   test_unscale_input_variables_mean_standard_deviation();
   test_unscale_input_variables_minimum_maximum();

   // Target variables unscaling

   test_unscale_target_variables_mean_standard_deviation();
   test_unscale_target_variables_minimum_maximum();

   // Input-target variables unscaling

   test_unscale_variables_mean_standard_deviation();
   test_unscale_variables_minimum_maximum();

   // Utility methods

   test_to_XML();

   test_print();
   test_save();
   test_load();

   test_print_data();
   test_save_data();
   test_load_data();

   test_get_instances_information();
   test_print_instances_information();
   test_save_instances_information();

   test_get_variables_information_XML();
   test_print_variables_information();
   test_save_variables_information();

   test_get_data_statistics();
   test_print_data_statistics();
   test_save_data_statistics();

   test_get_training_instances_statistics();
   test_print_training_instances_statistics();
   test_save_training_instances_statistics();

   test_get_validation_instances_statistics();
   test_print_validation_instances_statistics();
   test_save_validation_instances_statistics();

   test_get_testing_instances_statistics();
   test_print_testing_instances_statistics();
   test_save_testing_instances_statistics();

   test_get_instances_statistics();
   test_print_instances_statistics();
   test_save_instances_statistics();

   message += "End of input-target data set test case...\n";
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
