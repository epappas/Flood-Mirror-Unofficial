/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   P E R C E P T R O N   C L A S S                                                                  */
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
#include <cstdlib>
#include <ctime>

// Flood includes

#include "../../Flood/Utilities/UnitTesting.h"
#include "../../Flood/Perceptron/Perceptron.h"

// Unit testing includes

#include "TestPerceptron.h"


using namespace Flood;


// CONSTRUCTOR 

TestPerceptron::TestPerceptron(void) : UnitTesting() 
{
}


// DESTRUCTOR

TestPerceptron::~TestPerceptron(void)
{
}


// METHODS

// void test_constructor(void) method

void TestPerceptron::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   Perceptron p1;

   assert_true(p1.get_inputs_number() == 0, LOG);

   // Inputs number constructor 

   Perceptron p2(1);

   assert_true(p2.get_inputs_number() == 1, LOG);

   // Inputs number and initialization constructor
   
   Perceptron p3(5, 0.0);

   assert_true(p3.get_inputs_number() == 5, LOG);
   assert_true(p3.get_parameters() == 0.0, LOG);

   // File constructor 

   Perceptron p4(3, 1.0);
   p4.save("../Data/Perceptron.dat");

   Perceptron p5("../Data/Perceptron.dat");

   assert_true(p5.get_inputs_number() == 3, LOG);
   assert_true(p5.get_parameters() == 1.0, LOG);

   // Copy constructor

   Perceptron p6(10, 2.0);

   Perceptron p7(p6);

   assert_true(p7.get_inputs_number() == 10, LOG);
   assert_true(p7.get_parameters() == 2.0, LOG);

}


// void test_destructor(void) method

void TestPerceptron::test_destructor(void)
{
   message += "test_destructor\n";

   Perceptron p;

   p.~Perceptron();
}


// void test_assignment_operator(void) method

void TestPerceptron::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   Perceptron p_1;

   p_1.set_activation_function(Perceptron::Threshold);

   Perceptron p_2 = p_1;

   assert_true(p_2.get_activation_function() == Perceptron::Threshold, LOG);
}


// void test_get_activation_function(void) method

void TestPerceptron::test_get_activation_function(void)
{
   message += "test_get_activation_function\n";

   Perceptron p;

   p.set_activation_function(Perceptron::SymmetricThreshold);

   assert_true(p.get_activation_function() == Perceptron::SymmetricThreshold, LOG);
}


// void test_get_inputs_number(void) method

void TestPerceptron::test_get_inputs_number(void)
{
   message += "test_get_inputs_number\n";

   Perceptron p;

   assert_true(p.get_inputs_number() == 0, LOG);
}


// void test_get_bias(void) method   

void TestPerceptron::test_get_bias(void)   
{
   message += "test_get_inputs_number\n";

   Perceptron p;
   p.initialize_parameters(0.0);

   assert_true(p.get_bias() == 0.0, LOG);
}


// void test_get_synaptic_weights(void) method

void TestPerceptron::test_get_synaptic_weights(void)
{
   message += "test_get_synaptic_weights\n";

   Perceptron p;

   Vector<double> synaptic_weights = p.get_synaptic_weights();

   assert_true(synaptic_weights.get_size() == 0, LOG);
}


// void test_get_synaptic_weight(void) method

void TestPerceptron::test_get_synaptic_weight(void)
{
   message += "test_get_synaptic_weights\n";

   Perceptron p(1);
   p.initialize_parameters(0.0);

   assert_true(p.get_synaptic_weight(0) == 0.0, LOG);
}


// void test_get_parameters_number(void) method

void TestPerceptron::test_get_parameters_number(void)
{
   message += "test_get_parameters_number\n";

   Perceptron p(1);

   int parameters_number = p.get_parameters_number();

   assert_true(parameters_number == 2, LOG);
}


// void test_get_parameters(void) method

void TestPerceptron::test_get_parameters(void)
{
   message += "test_get_parameters\n";
   
   Perceptron p(1);

   Vector<double> parameters = p.get_parameters();

   int size = parameters.get_size();

   assert_true(size == 2, LOG);
}


// void test_get_display(void) method

void TestPerceptron::test_get_display(void)
{
   message += "test_get_display\n";
   
   Perceptron p;

   p.set_display(true);

   assert_true(p.get_display() == true, LOG);
}


// Test Set methods

// void test_set(void) method

void TestPerceptron::test_set(void)
{
   message += "test_set\n";
}


// void test_set_activation_function(void) method

void TestPerceptron::test_set_activation_function(void)
{
   message += "test_set_activation_function\n";

   Perceptron p;

   p.set_activation_function(Perceptron::Linear);

   assert_true(p.get_activation_function() == Perceptron::Linear, LOG);
}


// void test_set_inputs_number(void) method

void TestPerceptron::test_set_inputs_number(void)
{
   message += "test_set_inputs_number\n";

   Perceptron p;

   p.set_inputs_number(0);

   assert_true(p.get_inputs_number() == 0, LOG);
}


// void test_set_bias(void) method

void TestPerceptron::test_set_bias(void)
{
   message += "test_set_bias\n";

   Perceptron p;

   p.set_bias(0.0);

   assert_true(p.get_bias() == 0.0, LOG);   
}


// void test_set_synaptic_weights(void) method

void TestPerceptron::test_set_synaptic_weights(void)
{
   message += "test_set_synaptic_weights\n";

   Perceptron p;

   Vector<double> synaptic_weights;

   p.set_synaptic_weights(synaptic_weights);

   synaptic_weights = p.get_synaptic_weights();

   assert_true(synaptic_weights.get_size() == 0, LOG);   
}


// void test_set_synaptic_weight(void) method

void TestPerceptron::test_set_synaptic_weight(void)
{
   message += "test_set_synaptic_weight\n";

   Perceptron p(2);

   p.set_synaptic_weight(1, 1.0);

   assert_true(p.get_synaptic_weight(1) == 1.0, LOG);   
}


// void test_set_parameters(void) method

void TestPerceptron::test_set_parameters(void)
{
   message += "test_set_parameters\n";

   Perceptron p;

   Vector<double> parameters(1);

   p.set_parameters(parameters);

   parameters = p.get_parameters();

   assert_true(parameters.get_size() == 1, LOG);   
}


// void test_set_display(void) method

void TestPerceptron::test_set_display(void)
{
   message += "test_set_display\n";

   Perceptron p;

   p.set_display(false);

   assert_true(p.get_display() == false, LOG);   
}


// void test_initialize_parameters(void) method

void TestPerceptron::test_initialize_parameters(void)
{
   message += "test_initialize_parameters\n";

   Perceptron p(1);

   p.initialize_parameters(0.0);

   assert_true(p.get_parameters() == 0.0, LOG);   
}


// void test_initialize_bias_uniform(void) method

void TestPerceptron::test_initialize_bias_uniform(void)
{
   message += "test_initialize_bias_uniform\n";

   Perceptron p;

   p.initialize_bias_uniform(0.0, 0.0);

   assert_true(p.get_bias() == 0.0, LOG);   
}


// void test_initialize_bias_normal(void) method

void TestPerceptron::test_initialize_bias_normal(void)
{
   message += "test_initialize_bias_normal\n";

   Perceptron p;

   p.initialize_bias_normal(0.0, 0.0);

   assert_true(p.get_bias() == 0.0, LOG);   
}


// void test_initialize_synaptic_weights_uniform(void) method

void TestPerceptron::test_initialize_synaptic_weights_uniform(void)
{
   message += "test_initialize_synaptic_weights_uniform\n";

   Perceptron p(1);

   p.initialize_synaptic_weights_uniform(0.0, 0.0);

   assert_true(p.get_synaptic_weight(0) == 0.0, LOG);   
}


// void test_initialize_synaptic_weights_normal(void) method

void TestPerceptron::test_initialize_synaptic_weights_normal(void)
{
   message += "test_initialize_synaptic_weights_normal\n";

   Perceptron p(1);

   p.initialize_synaptic_weights_normal(0.0, 0.0);

   assert_true(p.get_synaptic_weight(0) == 0.0, LOG);   
}


// Test combination methods

// void test_calculate_combination(void) method

void TestPerceptron::test_calculate_combination(void)
{
   message += "test_calculate_combination\n";

   int inputs_number = 3;

   Perceptron p(inputs_number);

   double bias = 0.0;
   Vector<double> synaptic_weights(inputs_number, 0.0);

   p.set_bias(bias);
   p.set_synaptic_weights(synaptic_weights);

   Vector<double> input(inputs_number, 0.0);
   
   double combination = p.calculate_combination(input);

   assert_true(combination == 0.0, LOG);

   p.set(3);

   input.set(3);
   input[0] = -0.8;
   input[1] =  0.2;
   input[2] = -0.4;

   p.set_bias(-0.5);

   synaptic_weights.set(3);
   synaptic_weights[0] =  1.0;
   synaptic_weights[1] = -0.75;
   synaptic_weights[2] =  0.25;

   p.set_synaptic_weights(synaptic_weights);

   combination = p.calculate_combination(input);

   assert_true(combination == -1.55, LOG);
}


// void test_calculate_activation(void) method

void TestPerceptron::test_calculate_activation(void)
{
   message += "test_calculate_activation\n";

   double activation;   

   Perceptron p;

   double combination;
   
   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 0.5, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 0.0, LOG);

   // Threshold activation function 
   
   p.set_activation_function(Perceptron::Threshold);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 1.0, LOG);

   // Symmetric threshold activation function 
   
   p.set_activation_function(Perceptron::SymmetricThreshold);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 1.0, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(combination == 0.0, LOG);

   // Threshold activation function 
   
   p.set_activation_function(Perceptron::Threshold);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 1.0, LOG);

   // SymmetricThreshold activation function 
   
   p.set_activation_function(Perceptron::SymmetricThreshold);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 1.0, LOG);

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   combination = 0.0;
   activation = p.calculate_activation(combination);

   assert_true(fabs(activation - 1.0/(1.0+exp(-combination))) < 1.0e-12, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   activation = p.calculate_activation(combination);
   assert_true(fabs(activation - tanh(combination)) < 1.0e-12, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   activation = p.calculate_activation(combination);
   assert_true(combination == activation, LOG);
}


// void test_calculate_output(void) method

void TestPerceptron::test_calculate_output(void)
{
   message += "test_calculate_output\n";

   double output;   

   int inputs_number = 3;

   Perceptron p(inputs_number);

   double bias = 0.0;
   Vector<double> synaptic_weights(inputs_number, 0.0);

   p.set_bias(bias);
   p.set_synaptic_weights(synaptic_weights);

   Vector<double> input(inputs_number, 0.0);

   double combination = p.calculate_combination(input);

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   output = p.calculate_output(input);
   assert_true(output == 0.5, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   output = p.calculate_output(input);
   assert_true(output == 0.0, LOG);

   // Threshold activation function 
   
   p.set_activation_function(Perceptron::Threshold);

   output = p.calculate_output(input);
   assert_true(output == 1.0, LOG);

   // SymmetricThreshold activation function 
   
   p.set_activation_function(Perceptron::SymmetricThreshold);

   output = p.calculate_output(input);
   assert_true(output == 1.0, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   output = p.calculate_output(input);
   assert_true(output == 0.0, LOG);


   // New test

   p.set(2);

   p.set_activation_function(Perceptron::Logistic);

   input.set(2);
   input[0] = -0.2;
   input[1] =  0.5;

   p.set_bias(-0.5);

   synaptic_weights.set(2);
   synaptic_weights[0] = 1.0;
   synaptic_weights[1] = 0.25;

   p.set_synaptic_weights(synaptic_weights);

   output = p.calculate_output(input);

   // New test

   p.set(3);

   input.set(3);
   input[0] = -0.8;
   input[1] =  0.2;
   input[2] = -0.4;

   p.set_bias(-0.5);

   synaptic_weights.set(3);
   synaptic_weights[0] =  1.0;
   synaptic_weights[1] = -0.75;
   synaptic_weights[2] =  0.25;

   p.set_synaptic_weights(synaptic_weights);

   output = p.calculate_output(input);

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   combination = p.calculate_combination(input);
   output = p.calculate_output(input);
   assert_true(fabs(output - 1.0/(1.0 + exp(-combination))) < 1.0e-12, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   combination = p.calculate_combination(input);
   output = p.calculate_output(input);
   assert_true(fabs(output - tanh(combination)) < 1.0e-12, LOG);

   // Threshold activation function 
   
   p.set_activation_function(Perceptron::Threshold);

   output = p.calculate_output(input);
   assert_true(output == 0.0, LOG);

   // SymmetricThreshold activation function 
   
   p.set_activation_function(Perceptron::SymmetricThreshold);

   output = p.calculate_output(input);
   assert_true(output == -1.0, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   combination = p.calculate_combination(input);
   output = p.calculate_output(input);
   assert_true(fabs(output - combination) < 1.0e-12, LOG);   
}


// void test_calculate_activation_derivative(void) method

void TestPerceptron::test_calculate_activation_derivative(void)
{
   message += "test_calculate_activation_derivative\n";

   double activation_derivative;   

   Perceptron p;

   double combination;

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   combination = 0.0;
   activation_derivative = p.calculate_activation_derivative(combination);
   assert_true(activation_derivative == 0.25, LOG);

   combination = -1.55;
   activation_derivative = p.calculate_activation_derivative(combination);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   combination = 0.0;
   activation_derivative = p.calculate_activation_derivative(combination);
   assert_true(activation_derivative == 1.0, LOG);

   combination = -1.55;
   activation_derivative = p.calculate_activation_derivative(combination);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   combination = 0.0;
   activation_derivative = p.calculate_activation_derivative(combination);
   assert_true(activation_derivative == 1.0, LOG);
}

  
// void test_calculate_activation_second_derivative(void) method

void TestPerceptron::test_calculate_activation_second_derivative(void)
{
   message += "test_calculate_activation_second_derivative\n";

   Perceptron p;

   double combination;   
   double activation_second_derivative;   

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   combination = 0.0;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative == 0.0, LOG);

   combination = -1.55;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   combination = 0.0;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative == 0.0, LOG);

   combination = -1.55;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   combination = 0.0;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative == 0.0, LOG);
}


// void test_to_XML(void) method

void TestPerceptron::test_to_XML(void)
{
   message += "test_to_XML\n";

   Perceptron p;

   std::string object = p.to_XML(true);
}



// void test_print(void) method

void TestPerceptron::test_print(void)
{
   message += "test_print\n";

   Perceptron p;
   p.set_display(false);
   p.print();
}


// void test_save(void) method

void TestPerceptron::test_save(void)
{
   Perceptron p(1);

   p.initialize_parameters(0.0);

   p.save("../Data/Perceptron.dat");
}


// void test_load(void) method

void TestPerceptron::test_load(void)
{
   Perceptron p(1);
 
   p.set_activation_function(Perceptron::Logistic);

   p.initialize_parameters(0.0);

   p.save("../Data/Perceptron.dat");

   p.load("../Data/Perceptron.dat");

   assert_true(p.get_inputs_number() == 1, LOG);
   assert_true(p.get_activation_function() == Perceptron::Logistic, LOG);

   Vector<double> parameters = p.get_parameters();

   assert_true(parameters.get_size() == 2, LOG);
   assert_true(parameters == 0, LOG);   
}


// void run_test_case(void) method

void TestPerceptron::run_test_case(void)
{
   message += "Running perceptron test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor(); 

   // Assignment operator 

   test_assignment_operator();

   // Get methods

   test_get_inputs_number();
   test_get_activation_function();
   test_get_bias();   
   test_get_synaptic_weights();
   test_get_synaptic_weight();
   test_get_parameters_number();
   test_get_parameters();
   test_get_display();

   // Set methods

   test_set();

   test_set_inputs_number();
   test_set_activation_function();
   test_set_bias();
   test_set_synaptic_weights();
   test_set_synaptic_weight();
   test_set_parameters();
   test_set_display();

   // Initialization methods

   test_initialize_bias_uniform();
   test_initialize_bias_normal();

   test_initialize_synaptic_weights_uniform();
   test_initialize_synaptic_weights_normal();

   test_initialize_parameters();

   // Combination methods

   test_calculate_combination();

   // Activation methods

   test_calculate_activation();
   test_calculate_activation_derivative();
   test_calculate_activation_second_derivative();

   // Output methods

   test_calculate_output();

   // Utility methods

   test_to_XML();

   test_print();
   test_save();
   test_load();

   message += "End of perceptron test case...\n";
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

