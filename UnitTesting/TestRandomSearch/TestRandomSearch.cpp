/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   R A N D O M   S E A R C H   C L A S S                                                            */
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
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"

// Unit testing includes

#include "../TestObjectiveFunctional/MockObjectiveFunctional.h"
#include "TestRandomSearch.h"

using namespace Flood;


// GENERAL CONSTRUCTOR 

TestRandomSearch::TestRandomSearch(void) : UnitTesting()
{
}


// DESTRUCTOR

/// Destructor.

TestRandomSearch::~TestRandomSearch(void)
{
}

// METHODS

// void test_constructor(void) method

void TestRandomSearch::test_constructor(void)
{
   message += "test_constructor\n"; 

   MockObjectiveFunctional mof;

   // Default constructor

   RandomSearch rs1; 
   assert_true(rs1.get_objective_functional_pointer() == NULL, LOG);   

   // Objective functional constructor

   RandomSearch rs2(&mof); 
   assert_true(rs2.get_objective_functional_pointer() != NULL, LOG);   

}


// void test_destructor(void) method

void TestRandomSearch::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_training_rate_reduction_factor(void) method

void TestRandomSearch::test_get_training_rate_reduction_factor(void)
{
   message += "test_get_training_rate_reduction_factor\n";
}


// void test_get_reserve_potential_parameters_history(void) method

void TestRandomSearch::test_get_reserve_potential_parameters_history(void)
{
   message += "test_get_reserve_potential_parameters_history\n";
}


// void test_get_reserve_potential_parameters_norm_history(void) method

void TestRandomSearch::test_get_reserve_potential_parameters_norm_history(void)
{
   message += "test_get_reserve_potential_parameters_norm_history\n";
}


// void test_get_reserve_potential_evaluation_history(void) method

void TestRandomSearch::test_get_reserve_potential_evaluation_history(void)
{
   message += "test_get_reserve_potential_evaluation_history\n";
}


// void test_get_potential_parameters_history(void) method

void TestRandomSearch::test_get_potential_parameters_history(void)
{
   message += "test_get_potential_parameters_history\n";
}


// void test_get_potential_parameters_norm_history(void) method

void TestRandomSearch::test_get_potential_parameters_norm_history(void)
{
   message += "test_get_potential_parameters_norm_history\n";
}


// void test_get_potential_evaluation_history(void) method

void TestRandomSearch::test_get_potential_evaluation_history(void)
{
   message += "test_get_potential_evaluation_history\n";
}



// void test_set_training_rate_reduction_factor(void) method

void TestRandomSearch::test_set_training_rate_reduction_factor(void)
{
   message += "test_set_training_rate_reduction_factor\n";
}


// void test_set_reserve_potential_parameters_history(void) method

void TestRandomSearch::test_set_reserve_potential_parameters_history(void)
{
   message += "test_set_reserve_potential_parameters_history\n";
}


// void test_set_reserve_potential_parameters_norm_history(void) method

void TestRandomSearch::test_set_reserve_potential_parameters_norm_history(void)
{
   message += "test_set_reserve_potential_parameters_norm_history\n";
}


// void test_set_reserve_potential_evaluation_history(void) method

void TestRandomSearch::test_set_reserve_potential_evaluation_history(void)
{
   message += "test_set_reserve_potential_evaluation_history\n";
}


// void test_set_potential_parameters_history(void) method

void TestRandomSearch::test_set_potential_parameters_history(void)
{
   message += "test_set_potential_parameters_history\n";
}


// void test_set_potential_parameters_norm_history(void) method

void TestRandomSearch::test_set_potential_parameters_norm_history(void)
{
   message += "test_set_potential_parameters_norm_history\n";
}


// void test_set_potential_evaluation_history(void) method

void TestRandomSearch::test_set_potential_evaluation_history(void)
{
   message += "test_set_potential_evaluation_history\n";
}


// void test_calculate_training_direction(void) method

void TestRandomSearch::test_calculate_training_direction(void)
{
   message += "test_calculate_training_direction\n";
}


// void test_train(void) method

void TestRandomSearch::test_train(void)
{
   message += "test_train\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   RandomSearch rs(&mof);

   rs.set_display(false);
   rs.set_maximum_epochs_number(5),

   rs.set_reserve_all_training_history(true);

   rs.set_display_period(1),
   rs.train();
}


// void test_set_reserve_all_training_history(void) method

void TestRandomSearch::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   RandomSearch rs;
   rs.set_reserve_all_training_history(true);
}


// void test_resize_training_history(void) method

void TestRandomSearch::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   RandomSearch rs;
   rs.resize_training_history(1);
}


// void test_get_training_history_XML(void) method

void TestRandomSearch::test_get_training_history_XML(void)
{
   message += "test_get_training_history_XML\n";
}


// void test_to_XML(void) method

void TestRandomSearch::test_to_XML(void)
{
   message += "test_to_XML\n";

   RandomSearch rs;
   rs.save("../Data/RandomSearch.dat");
}


// void test_load(void) method

void TestRandomSearch::test_load(void)
{
   message += "test_load\n";

   RandomSearch rs;
   rs.save("../Data/RandomSearch.dat");
   rs.load("../Data/RandomSearch.dat");
}


// void run_test_case(void) method

void TestRandomSearch::run_test_case(void)
{
   message += "Running random search test case...\n";

   // Get methods

   test_get_training_rate_reduction_factor();

   test_get_reserve_potential_parameters_history();
   test_get_reserve_potential_parameters_norm_history();

   test_get_reserve_potential_evaluation_history();

   test_get_potential_parameters_history();
   test_get_potential_parameters_norm_history();

   test_get_potential_evaluation_history();

   // Set methods

   test_set_training_rate_reduction_factor();

   test_set_reserve_potential_parameters_history();
   test_set_reserve_potential_parameters_norm_history();

   test_set_reserve_potential_evaluation_history();

   test_set_potential_parameters_history();
   test_set_potential_parameters_norm_history();

   test_set_potential_evaluation_history();

   // Train methods

   test_calculate_training_direction();

   test_train();

   // Training history methods

   test_resize_training_history();

   test_set_reserve_all_training_history();

   test_get_training_history_XML();

   // Utiltity methods

   test_to_XML();

   test_load();

   message += "End of random search test case...\n";
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
