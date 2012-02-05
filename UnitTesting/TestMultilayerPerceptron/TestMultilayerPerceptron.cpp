/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   M U L T I L A Y E R   P E R C E P T R O N   C L A S S                                            */
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
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>   

// Flood incldues

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"

// Unit testing includes

#include "MockMultilayerPerceptron.h"
#include "TestMultilayerPerceptron.h"


using namespace Flood;


// GENERAL CONSTRUCTOR

TestMultilayerPerceptron::TestMultilayerPerceptron(void) : UnitTesting()
{
}


// DESTRUCTOR

TestMultilayerPerceptron::~TestMultilayerPerceptron(void)
{
}


// METHODS

// void test_constructor(void) method

void TestMultilayerPerceptron::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor
   MultilayerPerceptron mlp1;

   assert_true(mlp1.get_inputs_number() == 0, LOG);
   assert_true(mlp1.get_hidden_layers_size() == 0, LOG);
   assert_true(mlp1.get_outputs_number() == 0, LOG);

   assert_true(mlp1.get_independent_parameters_number() == 0, LOG);

   // Inputs, hidden layers size, outputs constructor
   Vector<int> hidden_layers_size(2);
   hidden_layers_size[0] = 2;

   hidden_layers_size[1] = 3;

   MultilayerPerceptron mlp2(1, hidden_layers_size, 4);

   assert_true(mlp2.get_inputs_number() == 1, LOG);

   assert_true(mlp2.get_hidden_layers_number() == 2, LOG);

   assert_true(mlp2.get_hidden_layer_size(0) == 2, LOG);
   assert_true(mlp2.get_hidden_layer_size(1) == 3, LOG);
   assert_true(mlp2.get_outputs_number() == 4, LOG);
   assert_true(mlp2.get_independent_parameters_number() == 0, LOG);

   // Inputs, single hidden layer size, outputs constructor

   MultilayerPerceptron mlp3(1, 2, 3);

   assert_true(mlp3.get_inputs_number() == 1, LOG);
   assert_true(mlp3.get_hidden_layers_number() == 1, LOG);
   assert_true(mlp3.get_hidden_layer_size(0) == 2, LOG);
   assert_true(mlp3.get_outputs_number() == 3, LOG);
   assert_true(mlp3.get_independent_parameters_number() == 0, LOG);
 
   // Independent parameters constructor

   MultilayerPerceptron mlp4(1);

   assert_true(mlp4.get_inputs_number() == 0, LOG);

   assert_true(mlp4.get_hidden_layers_size() == 0, LOG);

   assert_true(mlp4.get_outputs_number() == 0, LOG);

   assert_true(mlp4.get_independent_parameters_number() == 1, LOG);

   // File constructor

   mlp1.save("../Data/MultilayerPerceptron.dat");

   MultilayerPerceptron mlp5("../Data/MultilayerPerceptron.dat");

   assert_true(mlp5.get_inputs_number() == 0, LOG);
   assert_true(mlp5.get_hidden_layers_size() == 0, LOG);
   assert_true(mlp5.get_outputs_number() == 0, LOG);
   assert_true(mlp5.get_independent_parameters_number() == 0, LOG);

   mlp2.save("../Data/MultilayerPerceptron.dat");
   MultilayerPerceptron mlp6("../Data/MultilayerPerceptron.dat");
   assert_true(mlp6.get_inputs_number() == 1, LOG);
   assert_true(mlp6.get_hidden_layers_number() == 2, LOG);
   assert_true(mlp6.get_hidden_layer_size(0) == 2, LOG);
   assert_true(mlp6.get_hidden_layer_size(1) == 3, LOG);
   assert_true(mlp6.get_outputs_number() == 4, LOG);
   assert_true(mlp6.get_independent_parameters_number() == 0, LOG);

   mlp3.save("../Data/MultilayerPerceptron.dat");
   MultilayerPerceptron mlp7("../Data/MultilayerPerceptron.dat");

   assert_true(mlp7.get_inputs_number() == 1, LOG);
   assert_true(mlp7.get_hidden_layers_number() == 1, LOG);
   assert_true(mlp7.get_hidden_layer_size(0) == 2, LOG);
   assert_true(mlp7.get_outputs_number() == 3, LOG);
   assert_true(mlp7.get_independent_parameters_number() == 0, LOG);
   mlp4.save("../Data/MultilayerPerceptron.dat");
   MultilayerPerceptron mlp8("../Data/MultilayerPerceptron.dat");
   assert_true(mlp8.get_inputs_number() == 0, LOG);
   assert_true(mlp8.get_hidden_layers_size() == 0, LOG);
   assert_true(mlp8.get_outputs_number() == 0, LOG);
   assert_true(mlp8.get_independent_parameters_number() == 1, LOG);   

   // Copy constructor
}


// void test_destructor(void)

void TestMultilayerPerceptron::test_destructor(void)
{
   message += "test_destructor\n";
   MultilayerPerceptron mlp;
   mlp.~MultilayerPerceptron();
}


// void test_assignment_operator(void)

void TestMultilayerPerceptron::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   MultilayerPerceptron mlp_1;
   MultilayerPerceptron mlp_2 = mlp_1;
   assert_true(mlp_2.get_inputs_number() == 0, LOG);
   assert_true(mlp_2.get_hidden_layers_number() == 0, LOG);
   assert_true(mlp_2.get_outputs_number() == 0, LOG);
   assert_true(mlp_2.get_independent_parameters_number() == 0, LOG);
}



// void test_get_inputs_number(void) method

void TestMultilayerPerceptron::test_get_inputs_number(void)
{
   message += "test_get_inputs_number\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_inputs_number() == 0, LOG);

   mlp.set_network_architecture(1, 1, 1);

   assert_true(mlp.get_inputs_number() == 1, LOG);
}


// void test_get_hidden_layers_size(void) method

void TestMultilayerPerceptron::test_get_hidden_layers_size(void)
{
   message += "test_get_hidden_layers_size\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_hidden_layers_size() == 0, LOG);

   mlp.set_network_architecture(1, 1, 1);

   assert_true(mlp.get_hidden_layers_size() == 1, LOG);
}


// void test_get_hidden_layer_size(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_size(void)
{
   message += "test_get_hidden_layer_size\n";

   Vector<int> hidden_layers_size(2);
   hidden_layers_size[0] = 1;
   hidden_layers_size[1] = 2;
   MultilayerPerceptron mlp(1, hidden_layers_size, 1);
   
   assert_true(mlp.get_hidden_layer_size(0) == 1, LOG);
   assert_true(mlp.get_hidden_layer_size(1) == 2, LOG);
}


// void test_get_outputs_number(void) method

void TestMultilayerPerceptron::test_get_outputs_number(void)
{
   message += "test_get_outputs_number\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_outputs_number() == 0, LOG);
}


// void test_get_hidden_layer_inputs_number(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_inputs_number(void)
{
   message += "test_get_hidden_layer_inputs_number\n";
     
   Vector<int> hidden_layers_size(2, 2);

   MultilayerPerceptron mlp(1, hidden_layers_size, 1);

   assert_true(mlp.get_hidden_layer_inputs_number(0) == 1, LOG);
   assert_true(mlp.get_hidden_layer_inputs_number(1) == 2, LOG);
}


// void test_get_output_layer_inputs_number(void) method

void TestMultilayerPerceptron::test_get_output_layer_inputs_number(void)
{
   message += "test_get_output_layer_inputs_number\n";
     
   Vector<int> hidden_layers_size(2, 2);

   MultilayerPerceptron mlp(1, hidden_layers_size, 1);

   assert_true(mlp.get_output_layer_inputs_number() == 2, LOG);
}


// void test_get_hidden_layers_activation_function(void) method

void TestMultilayerPerceptron::test_get_hidden_layers_activation_function(void)
{
   message += "test_get_hidden_layers_activation_function\n";

   MultilayerPerceptron mlp;

   Vector<MultilayerPerceptron::LayerActivationFunction> hidden_layers_activation_function;

   mlp.set_hidden_layers_activation_function(hidden_layers_activation_function);

   hidden_layers_activation_function = mlp.get_hidden_layers_activation_function();

   assert_true(hidden_layers_activation_function.get_size() == 0, LOG);
}


// void test_get_hidden_layers_activation_function_name(void) method

void TestMultilayerPerceptron::test_get_hidden_layers_activation_function_name(void)
{
   message += "test_get_hidden_layers_activation_function_name\n";
}


// void test_get_hidden_layer_activation_function(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_activation_function(void)
{
   message += "test_get_hidden_layer_activation_function\n";

   MultilayerPerceptron mlp(1,1,1);
   
   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Logistic);
   assert_true(mlp.get_hidden_layer_activation_function(0) == MultilayerPerceptron::Logistic, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::HyperbolicTangent);
   assert_true(mlp.get_hidden_layer_activation_function(0) == MultilayerPerceptron::HyperbolicTangent, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Threshold);
   assert_true(mlp.get_hidden_layer_activation_function(0) == MultilayerPerceptron::Threshold, LOG);
   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::SymmetricThreshold);
   assert_true(mlp.get_hidden_layer_activation_function(0) == MultilayerPerceptron::SymmetricThreshold, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Linear);
   assert_true(mlp.get_hidden_layer_activation_function(0) == MultilayerPerceptron::Linear, LOG);
}


// void test_get_hidden_layer_activation_function_name(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_activation_function_name(void)
{
   message += "test_get_hidden_layer_activation_function_name\n";
}


// void test_get_output_layer_activation_function(void) method

void TestMultilayerPerceptron::test_get_output_layer_activation_function(void)
{
   message += "test_get_output_layer_activation_function\n";

   MultilayerPerceptron mlp(1,1,1);
   
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Logistic);
   assert_true(mlp.get_output_layer_activation_function() == MultilayerPerceptron::Logistic, LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::HyperbolicTangent);
   assert_true(mlp.get_output_layer_activation_function() == MultilayerPerceptron::HyperbolicTangent, LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::Threshold);
   assert_true(mlp.get_output_layer_activation_function() == MultilayerPerceptron::Threshold, LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::SymmetricThreshold);
   assert_true(mlp.get_output_layer_activation_function() == MultilayerPerceptron::SymmetricThreshold, LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::Linear);
   assert_true(mlp.get_output_layer_activation_function() == MultilayerPerceptron::Linear, LOG);
}


// void test_get_output_layer_activation_function_name(void) method

void TestMultilayerPerceptron::test_get_output_layer_activation_function_name(void)
{
   message += "test_get_output_layer_activation_function_name\n";
}


// void test_get_hidden_layers(void) method

void TestMultilayerPerceptron::test_get_hidden_layers(void)
{
   message += "test_get_hidden_layers\n";

   MultilayerPerceptron mlp;

   Vector< Vector<Perceptron> > hidden_layers;
   
   hidden_layers = mlp.get_hidden_layers();

   assert_true(hidden_layers.get_size() == 0, LOG);
}



// void test_get_hidden_layer(void) method

void TestMultilayerPerceptron::test_get_hidden_layer(void)
{
   message += "test_get_hidden_layer\n";

   Vector<int> hidden_layers_size(3);
   hidden_layers_size[0] = 4;
   hidden_layers_size[1] = 2;
   hidden_layers_size[2] = 3;

   MultilayerPerceptron mlp(1, hidden_layers_size, 1);

   Vector<Perceptron> hidden_layer = mlp.get_hidden_layer(1);

   assert_true(hidden_layer.get_size() == 2, LOG);
}


// void test_get_output_layer(void) method

void TestMultilayerPerceptron::test_get_output_layer(void)
{
   message += "test_get_hidden_layer\n";

   MultilayerPerceptron mlp(1, 1, 1);

   Vector<Perceptron> output_layer = mlp.get_output_layer();

   assert_true(output_layer.get_size() == 1, LOG);
}


// void test_get_hidden_layers_number(void) method

void TestMultilayerPerceptron::test_get_hidden_layers_number(void)
{
   message += "test_get_hidden_layers_number\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_hidden_layers_number() == 0, LOG);

   Vector<int> hidden_layers_size(3);
   hidden_layers_size[0] = 4;
   hidden_layers_size[1] = 2;
   hidden_layers_size[2] = 3;

   mlp.set_network_architecture(1, hidden_layers_size, 1);

   assert_true(mlp.get_hidden_layers_number() == 3, LOG);
}


// void test_get_neural_parameters_number(void) method

void TestMultilayerPerceptron::test_get_neural_parameters_number(void)
{
   message += "test_get_neural_parameters_number\n";

   MultilayerPerceptron mlp;
   mlp.set_independent_parameters_number(1); 

   mlp.set_network_architecture(0, 0, 0);

   assert_true(mlp.get_neural_parameters_number() == 0, LOG);
}


// void test_get_hidden_layers_parameters_number(void) method

void TestMultilayerPerceptron::test_get_hidden_layers_parameters_number(void)
{   
   message += "test_get_hidden_layers_parameters_number\n";
   MultilayerPerceptron mlp;

   assert_true(mlp.get_hidden_layers_parameters_number() == 0, LOG);
   mlp.set_network_architecture(1, 1, 1);
   assert_true(mlp.get_hidden_layers_parameters_number() == 2, LOG);
   Vector<int> hidden_layers_size(2, 1);
   mlp.set_hidden_layers_size(hidden_layers_size);
   assert_true(mlp.get_hidden_layers_parameters_number() == 4, LOG);
}


// void test_get_hidden_layer_parameters_number(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_parameters_number(void)
{      message += "test_get_hidden_layer_parameters_number\n";

   MultilayerPerceptron mlp;
   mlp.set_network_architecture(1, 1, 1);
   assert_true(mlp.get_hidden_layer_parameters_number(0) == 2, LOG);
   Vector<int> hidden_layers_size(2, 1);
   mlp.set_hidden_layers_size(hidden_layers_size);
   assert_true(mlp.get_hidden_layer_parameters_number(0) == 2, LOG);
   assert_true(mlp.get_hidden_layer_parameters_number(1) == 2, LOG);
}


// void test_get_output_layer_parameters_number(void) method

void TestMultilayerPerceptron::test_get_output_layer_parameters_number(void)
{
   message += "test_get_output_layer_parameters_number\n";
   MultilayerPerceptron mlp;
   assert_true(mlp.get_output_layer_parameters_number() == 0, LOG);
   mlp.set_network_architecture(1, 1, 1);
   assert_true(mlp.get_output_layer_parameters_number() == 2, LOG);
}


// void test_get_neural_parameters(void) method   

void TestMultilayerPerceptron::test_get_neural_parameters(void)   
{
   message += "test_get_neural_parameters\n";

   MultilayerPerceptron mlp(3,4,2);
   mlp.initialize_neural_parameters(0.0);

   Vector<double> neural_parameters = mlp.get_neural_parameters();

   assert_true(neural_parameters == 0.0, LOG);
}


// void test_set(void) method

void TestMultilayerPerceptron::test_set(void)
{
   message += "test_set\n";
}


// void test_set_default(void) method

void TestMultilayerPerceptron::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_set_neural_parameters(void) method

void TestMultilayerPerceptron::test_set_neural_parameters(void)
{
	message += "test_set_neural_parameters\n";

	MultilayerPerceptron mlp(1,1,1);

	int neural_parameters_number = mlp.get_neural_parameters_number();

	Vector<double> neural_parameters(neural_parameters_number);
	
	neural_parameters.initialize_uniform();

	mlp.set_neural_parameters(neural_parameters);

    Vector<double> new_neural_parameters = mlp.get_neural_parameters();

    assert_true(new_neural_parameters == neural_parameters, LOG);
}


// void test_get_hidden_layers_biases(void) method

void TestMultilayerPerceptron::test_get_hidden_layers_biases(void)
{
   message += "test_get_hidden_layers_biases\n";

   Vector<int> hidden_neurons_numbers(2, 1);

   MultilayerPerceptron mlp(1, hidden_neurons_numbers, 1);

   mlp.initialize_neural_parameters(0.0);

   Vector< Vector<double> > hidden_layers_biases = mlp.get_hidden_layers_biases();

   Vector< Vector<double> > true_hidden_layers_biases(2);
   Vector<double> true_hidden_layer_biases(1, 0.0);
   true_hidden_layers_biases[0] = true_hidden_layer_biases;
   true_hidden_layers_biases[1] = true_hidden_layer_biases;

   assert_true(hidden_layers_biases == true_hidden_layers_biases, LOG);
}


// void test_get_hidden_layers_synaptic_weights(void) method

void TestMultilayerPerceptron::test_get_hidden_layers_synaptic_weights(void)
{
   message += "test_get_hidden_layers_synaptic_weights\n";

   Vector<int> hidden_neurons_numbers(2, 1);

   MultilayerPerceptron mlp(1, hidden_neurons_numbers, 1);

   mlp.initialize_neural_parameters(0.0);

   Vector< Matrix<double> > hidden_layers_synaptic_weights = mlp.get_hidden_layers_synaptic_weights();

   Vector< Matrix<double> > true_hidden_layers_synaptic_weights(2);

   Matrix<double> true_hidden_layer_synaptic_weights(1, 1, 0.0);
   true_hidden_layers_synaptic_weights[0] = true_hidden_layer_synaptic_weights;
   true_hidden_layers_synaptic_weights[1] = true_hidden_layer_synaptic_weights;

   int hidden_layers_number = mlp.get_hidden_layers_number();
 
   for(int i = 0; i < hidden_layers_number; i++)
   {
      assert_true(hidden_layers_synaptic_weights[i] == true_hidden_layers_synaptic_weights[i], LOG);
   }
}


// void test_get_hidden_layers_parameters(void) method

void TestMultilayerPerceptron::test_get_hidden_layers_parameters(void)
{
   message += "test_get_hidden_layers_parameters\n";

   Vector<int> hidden_layers_size(2, 1);

   MultilayerPerceptron mlp(1, hidden_layers_size, 1);

   Vector< Matrix<double> > hidden_layers_parameters = mlp.get_hidden_layers_parameters();
   assert_true(hidden_layers_parameters.get_size() == 2, LOG);
}


// void test_get_hidden_layer_biases(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_biases(void)
{
   message += "test_get_hidden_layer_biases\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(1.0);

   Vector<double> hidden_layer_biases = mlp.get_hidden_layer_biases(0);

   assert_true(hidden_layer_biases.get_size() == 1, LOG);
   assert_true(hidden_layer_biases == 1.0, LOG);   
}


// void test_get_hidden_layer_synaptic_weights(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_synaptic_weights(void)
{
   message += "test_get_hidden_layer_synaptic_weights\n";

   MultilayerPerceptron mlp(1, 1, 1);

   mlp.initialize_neural_parameters(0.0);

   Matrix<double> hidden_layer_synaptic_weights = mlp.get_hidden_layer_synaptic_weights(0);

   Matrix<double> true_hidden_layer_synaptic_weights(1, 1, 0.0);

   assert_true(hidden_layer_synaptic_weights == true_hidden_layer_synaptic_weights, LOG);
}


// void test_get_hidden_layer_parameters(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_parameters(void)
{
   message += "test_get_hidden_layer_parameters\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(1.0);

   Matrix<double> hidden_layer_parameters = mlp.get_hidden_layer_parameters(0);

   assert_true(hidden_layer_parameters.get_rows_number() == 1, LOG);
   assert_true(hidden_layer_parameters.get_columns_number() == 2, LOG);
   assert_true(hidden_layer_parameters == 1.0, LOG);
}


// void test_get_output_layer_biases(void) method

void TestMultilayerPerceptron::test_get_output_layer_biases(void)
{
   message +="test_get_output_layer_biases\n";

   MultilayerPerceptron mlp(1, 1, 1);
   
   mlp.initialize_neural_parameters(0.0);

   Vector<double> output_layer_biases = mlp.get_output_layer_biases();

   Vector<double> true_output_layer_biases(1, 0.0);

   assert_true(output_layer_biases == true_output_layer_biases, LOG);
}


// void test_get_output_layer_synaptic_weights(void) method

void TestMultilayerPerceptron::test_get_output_layer_synaptic_weights(void)
{
   message += "test_get_output_layer_synaptic_weights\n";

   MultilayerPerceptron mlp(1, 1, 1);
   
   mlp.initialize_neural_parameters(0.0);

   Matrix<double> output_layer_synaptic_weights = mlp.get_output_layer_synaptic_weights();

   Matrix<double> true_output_layer_synaptic_weights(1, 1, 0.0);

   assert_true(output_layer_synaptic_weights == true_output_layer_synaptic_weights, LOG);
}


// void test_get_output_layer_parameters(void) method

void TestMultilayerPerceptron::test_get_output_layer_parameters(void)
{
   message += "test_get_output_layer_parameters\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(1.0);

   Matrix<double> output_layer_parameters = mlp.get_output_layer_parameters();

   assert_true(output_layer_parameters.get_rows_number() == 1, LOG);
   assert_true(output_layer_parameters.get_columns_number() == 2, LOG);
   assert_true(output_layer_parameters == 1.0, LOG);
}


// void test_get_hidden_layer_bias_index(void) method
//@todo

void TestMultilayerPerceptron::test_get_hidden_layer_bias_index(void)
{
   message += "test_get_hidden_layer_bias_index\n";

   MultilayerPerceptron mlp(1, 3, 1);

   assert_true(mlp.get_hidden_layer_bias_index(0, 0) == 0, LOG);
   assert_true(mlp.get_hidden_layer_bias_index(0, 1) == 2, LOG);
   assert_true(mlp.get_hidden_layer_bias_index(0, 2) == 4, LOG);

   Vector<int> hidden_layers_size(2, 1);

   mlp.set_hidden_layers_size(hidden_layers_size);

   assert_true(mlp.get_hidden_layer_bias_index(1, 0) == 2, LOG);
}


// void test_get_hidden_layer_synaptic_weight_index(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_synaptic_weight_index(void)
{
   message += "test_get_hidden_layer_synaptic_weight_index\n";

   MultilayerPerceptron mlp(1, 1, 1);

   assert_true(mlp.get_hidden_layer_synaptic_weight_index(0, 0, 0) == 1, LOG);
}


// void test_get_output_layer_bias_index(void) method

void TestMultilayerPerceptron::test_get_output_layer_bias_index(void)
{
   message += "test_get_output_layer_bias_index\n";
}


// void test_get_output_layer_synaptic_weight_index(void) method

void TestMultilayerPerceptron::test_get_output_layer_synaptic_weight_index(void)
{
   message += "test_get_output_layer_synaptic_weight_index\n";
}


// void test_set_hidden_layers_biases(void) method

void TestMultilayerPerceptron::test_set_hidden_layers_biases(void)
{
   message += "test_set_hidden_layers_biases\n";

   Vector<int> hidden_neurons_numbers(2, 1);

   MultilayerPerceptron mlp(1, hidden_neurons_numbers, 1);

   Vector< Vector<double> > true_hidden_layers_biases(2);

   Vector<double> true_hidden_layer_biases(1, 0.0);

   true_hidden_layers_biases[0] = true_hidden_layer_biases;
   true_hidden_layers_biases[1] = true_hidden_layer_biases;

   mlp.set_hidden_layers_biases(true_hidden_layers_biases);

   Vector< Vector<double> > hidden_layers_biases = mlp.get_hidden_layers_biases();

   assert_true(hidden_layers_biases == true_hidden_layers_biases, LOG);
}


// void test_set_hidden_layers_synaptic_weights(void) method

void TestMultilayerPerceptron::test_set_hidden_layers_synaptic_weights(void)
{
   message += "test_set_hidden_layers_synaptic_weights\n";

   Vector<int> hidden_neurons_numbers(2, 1);

   MultilayerPerceptron mlp(1, hidden_neurons_numbers, 1);

   Vector< Matrix<double> > true_hidden_layers_synaptic_weights(2);

   Matrix<double> true_hidden_layer_synaptic_weights(1, 1, 0.0);

   true_hidden_layers_synaptic_weights[0] = true_hidden_layer_synaptic_weights;
   true_hidden_layers_synaptic_weights[1] = true_hidden_layer_synaptic_weights;

   mlp.set_hidden_layers_synaptic_weights(true_hidden_layers_synaptic_weights);

   Vector< Matrix<double> > hidden_layers_synaptic_weights = mlp.get_hidden_layers_synaptic_weights();

   int hidden_layers_number = mlp.get_hidden_layers_number();

   for(int i = 0; i < hidden_layers_number; i++)
   {
      assert_true(hidden_layers_synaptic_weights[i] == true_hidden_layers_synaptic_weights[i], LOG);
   }
}


// void test_set_hidden_layers_parameters(void) method
//@todo

void TestMultilayerPerceptron::test_set_hidden_layers_parameters(void)
{
   message += "test_set_hidden_layers_synaptic_weights\n";

   Vector<int> hidden_layers_size(2, 1);

   MultilayerPerceptron mlp(1, hidden_layers_size, 1);

   Matrix<double> hidden_layer_synaptic_weights(1, 1);
   Vector< Matrix<double> > hidden_layers_synaptic_weights(2, hidden_layer_synaptic_weights);

}


// void test_set_hidden_layer_biases(void) method

void TestMultilayerPerceptron::test_set_hidden_layer_biases(void)
{
   message += "test_set_hidden_layer_biases\n";

   MultilayerPerceptron mlp(1, 1, 1);

   Vector<double> hidden_layer_biases(1, 0.0);

   mlp.set_hidden_layer_biases(0, hidden_layer_biases);

   assert_true(mlp.get_hidden_layer_biases(0) == hidden_layer_biases, LOG);
}


// void test_set_hidden_layer_synaptic_weights(void) method

void TestMultilayerPerceptron::test_set_hidden_layer_synaptic_weights(void)
{
   message += "test_set_hidden_layer_synaptic_weights\n";

   MultilayerPerceptron mlp(1, 1, 1);

   Matrix<double> hidden_layer_synaptic_weights(1, 1, 0.0);

   mlp.set_hidden_layer_synaptic_weights(0, hidden_layer_synaptic_weights);

   assert_true(mlp.get_hidden_layer_synaptic_weights(0) == hidden_layer_synaptic_weights, LOG);
}


// void test_set_hidden_layer_parameters(void) method

void TestMultilayerPerceptron::test_set_hidden_layer_parameters(void)
{
   message += "test_set_hidden_layer_parameters\n";

   MultilayerPerceptron mlp(1, 1, 1);

   Matrix<double> hidden_layer_parameters(1, 2, 0.0);

   mlp.set_hidden_layer_parameters(0, hidden_layer_parameters);

   assert_true(mlp.get_hidden_layer_parameters(0) == hidden_layer_parameters, LOG);

}


// void test_set_output_layer_biases(void) method

void TestMultilayerPerceptron::test_set_output_layer_biases(void)
{
   message += "test_set_output_layer_biases\n";

   MultilayerPerceptron mlp(1,1,1);

   Vector<double> true_output_layer_biases(1, 0.0);

   mlp.set_output_layer_biases(true_output_layer_biases);

   Vector<double> output_layer_biases = mlp.get_output_layer_biases();

   assert_true(output_layer_biases == true_output_layer_biases, LOG);
}


// void test_set_output_layer_synaptic_weights(void) method

void TestMultilayerPerceptron::test_set_output_layer_synaptic_weights(void)
{
   message += "test_set_output_layer_synaptic_weights\n";

   MultilayerPerceptron mlp(1,1,1);

   Matrix<double> true_output_layer_synaptic_weights(1, 1, 0.0);

   mlp.set_output_layer_synaptic_weights(true_output_layer_synaptic_weights);

   Matrix<double> output_layer_synaptic_weights = mlp.get_output_layer_synaptic_weights();

   assert_true(output_layer_synaptic_weights == true_output_layer_synaptic_weights, LOG);
}


// void test_set_output_layer_parameters(void) method

void TestMultilayerPerceptron::test_set_output_layer_parameters(void)
{
   message += "test_set_output_layer_parameters\n";

}


// void test_get_input_variables_name(void) method

void TestMultilayerPerceptron::test_get_input_variables_name(void)
{
   message += "test_get_input_variables_name\n";

   MultilayerPerceptron mlp;

   Vector<std::string> input_variables_name = mlp.get_input_variables_name();

   assert_true(input_variables_name.get_size() == 0, LOG); 
}


// void test_get_output_variables_name(void) method

void TestMultilayerPerceptron::test_get_output_variables_name(void)
{
   message += "test_get_output_variables_name\n";

   MultilayerPerceptron mlp;

   Vector<std::string> output_variables_name = mlp.get_output_variables_name();

   assert_true(output_variables_name.get_size() == 0, LOG);
}


// void test_get_input_variable_name(void) method

void TestMultilayerPerceptron::test_get_input_variable_name(void)
{
   message += "test_get_input_variable_name\n";

   MultilayerPerceptron mlp(1, 1, 1);

   mlp.set_input_variable_name(0, "x");

   assert_true(mlp.get_input_variable_name(0) == "x", LOG);
}


// void test_get_output_variable_name(void) method

void TestMultilayerPerceptron::test_get_output_variable_name(void)
{
   message += "test_get_input_variable_name\n";

   MultilayerPerceptron mlp(1, 1, 1);

   mlp.set_output_variable_name(0, "y");

   assert_true(mlp.get_output_variable_name(0) == "y", LOG);
}


// void test_get_input_variables_units(void) method

void TestMultilayerPerceptron::test_get_input_variables_units(void)
{
   message += "test_get_input_variables_units\n";

   MultilayerPerceptron mlp;

   Vector<std::string> input_variables_units = mlp.get_input_variables_units();

   assert_true(input_variables_units.get_size() == 0, LOG); 
}


// void test_get_output_variables_units(void) method

void TestMultilayerPerceptron::test_get_output_variables_units(void)
{
   message += "test_get_output_variables_units\n";

   MultilayerPerceptron mlp;

   Vector<std::string> output_variables_units = mlp.get_output_variables_units();

   assert_true(output_variables_units.get_size() == 0, LOG); 
}


// void test_get_input_variable_units(void) method

void TestMultilayerPerceptron::test_get_input_variable_units(void)
{
   message += "test_get_input_variable_units\n";

   MultilayerPerceptron mlp(1, 1, 1);

   mlp.set_input_variable_units(0, "m");

   assert_true(mlp.get_input_variable_units(0) == "m", LOG);
}


// void test_get_output_variable_units(void) method

void TestMultilayerPerceptron::test_get_output_variable_units(void)
{
   message += "test_get_output_variable_units\n";

   MultilayerPerceptron mlp(1, 1, 1);

   mlp.set_output_variable_units(0, "m");

   assert_true(mlp.get_output_variable_units(0) == "m", LOG);
}


// void test_get_input_variables_description(void) method

void TestMultilayerPerceptron::test_get_input_variables_description(void)
{
   message += "test_get_input_variables_description\n";

   MultilayerPerceptron mlp;

   Vector<std::string> input_variables_description = mlp.get_input_variables_description();

   assert_true(input_variables_description.get_size() == 0, LOG); 
}


// void test_get_output_variables_description(void) method

void TestMultilayerPerceptron::test_get_output_variables_description(void)
{
   message += "test_get_output_variables_description\n";

   MultilayerPerceptron mlp;

   Vector<std::string> output_variables_description = mlp.get_output_variables_description();

   assert_true(output_variables_description.get_size() == 0, LOG); 
}


// void test_get_input_variable_description(void) method

void TestMultilayerPerceptron::test_get_input_variable_description(void)
{
   message += "test_get_input_variable_description\n";

   MultilayerPerceptron mlp(1, 1, 1);

   mlp.set_input_variable_description(0, "info");

   assert_true(mlp.get_input_variable_description(0) == "info", LOG);
}


// void test_get_output_variable_description(void) method

void TestMultilayerPerceptron::test_get_output_variable_description(void)
{
   message += "test_get_output_variable_description\n";

   MultilayerPerceptron mlp(1, 1, 1);

   mlp.set_output_variable_description(0, "info");

   assert_true(mlp.get_output_variable_description(0) == "info", LOG);
}


// void test_get_variables_information(void) method

void TestMultilayerPerceptron::test_get_variables_information(void)
{
   message += "test_get_variables_information\n";

   MultilayerPerceptron mlp(1,1,1);

   Vector< Vector<std::string>* > variables_information = mlp.get_variables_information();

   int size = variables_information.get_size();

   assert_true(size == 6, LOG);
}


// void test_get_input_variables_mean(void) method

void TestMultilayerPerceptron::test_get_input_variables_mean(void)
{
   message += "test_get_input_variables_mean\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_input_variables_mean() == 0, LOG);

   mlp.set(1,1,1);
   mlp.set_input_variable_mean(0, 2.0);

   Vector<double>& input_variables_mean = mlp.get_input_variables_mean();
 
   assert_true(input_variables_mean.get_size() == 1, LOG);
   assert_true(input_variables_mean == 2.0, LOG);

}


// void test_get_input_variables_standard_deviation(void) method

void TestMultilayerPerceptron::test_get_input_variables_standard_deviation(void)
{
   message += "test_get_input_variables_standard_deviation\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_input_variables_standard_deviation() == NULL, LOG);
}


// void test_get_output_variables_mean(void) method

void TestMultilayerPerceptron::test_get_output_variables_mean(void)
{
   message += "test_get_output_variables_mean\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_output_variables_mean() == 0, LOG);
}


// void test_get_output_variables_standard_deviation(void) method

void TestMultilayerPerceptron::test_get_output_variables_standard_deviation(void)
{
   message += "test_get_output_variables_standard_deviation\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_output_variables_standard_deviation() == 0, LOG);
}


// void test_get_input_variables_mean_standard_deviation(void) method
//@todo
void TestMultilayerPerceptron::test_get_input_variables_mean_standard_deviation(void)
{
   message += "test_get_input_variables_mean_standard_deviation\n";

   MultilayerPerceptron mlp;

   Vector< Vector<double>* > input_variables_mean_standard_deviation 
   = mlp.get_input_variables_mean_standard_deviation();

   assert_true(input_variables_mean_standard_deviation.get_size() == 2, LOG);

   assert_true(input_variables_mean_standard_deviation[0]->get_size() == 0, LOG);
   assert_true(input_variables_mean_standard_deviation[1]->get_size() == 0, LOG);

}


// void test_get_output_variables_mean_standard_deviation(void) method

void TestMultilayerPerceptron::test_get_output_variables_mean_standard_deviation(void)
{
   message += "test_get_output_variables_mean_standard_deviation\n";
}


// void test_get_input_variable_mean(void) method

void TestMultilayerPerceptron::test_get_input_variable_mean(void)
{
   message += "test_get_input_variable_mean\n";
}


// void test_get_input_variable_standard_deviation(void) method

void TestMultilayerPerceptron::test_get_input_variable_standard_deviation(void)
{
   message += "test_get_input_variable_standard_deviation\n";
}


// void test_get_output_variable_mean(void) method

void TestMultilayerPerceptron::test_get_output_variable_mean(void)
{
   message += "test_get_output_variable_mean\n";
}


// void test_get_output_variable_standard_deviation(void) method

void TestMultilayerPerceptron::test_get_output_variable_standard_deviation(void)
{
   message += "test_get_output_variable_standard_deviation\n";
}


// void test_get_input_variables_minimum(void) method

void TestMultilayerPerceptron::test_get_input_variables_minimum(void)
{
   message += "test_get_input_variables_minimum\n";
}


// void test_get_input_variables_maximum(void) method

void TestMultilayerPerceptron::test_get_input_variables_maximum(void)
{
   message += "test_get_input_variables_maximum\n";
}


// void test_get_output_variables_minimum(void) method

void TestMultilayerPerceptron::test_get_output_variables_minimum(void)
{
   message += "test_get_output_variables_minimum\n";
}


// void test_get_output_variables_maximum(void) method

void TestMultilayerPerceptron::test_get_output_variables_maximum(void)
{
   message += "test_get_output_variables_maximum\n";
}


// void test_get_input_variables_minimum_maximum(void) method

void TestMultilayerPerceptron::test_get_input_variables_minimum_maximum(void)
{
   message += "test_get_input_variables_minimum_maximum\n";
}


// void test_get_output_variables_minimum_maximum(void) method

void TestMultilayerPerceptron::test_get_output_variables_minimum_maximum(void)
{
   message += "test_get_output_variables_minimum_maximum\n";
}


// void test_get_input_variable_minimum(void) method

void TestMultilayerPerceptron::test_get_input_variable_minimum(void)
{
   message += "test_get_input_variable_minimum\n";
}


// void test_get_input_variable_maximum(void) method

void TestMultilayerPerceptron::test_get_input_variable_maximum(void)
{
   message += "test_get_input_variable_maximum\n";
}


// void test_get_output_variable_minimum(void) method

void TestMultilayerPerceptron::test_get_output_variable_minimum(void)
{
   message += "test_get_output_variable_minimum\n";
}


// void test_get_output_variable_maximum(void) method

void TestMultilayerPerceptron::test_get_output_variable_maximum(void)
{
   message += "test_get_output_variable_maximum\n";
}


// void test_get_variables_statistics(void) method

void TestMultilayerPerceptron::test_get_variables_statistics(void)
{
   message += "test_get_variables_statistics\n";
}


// void test_get_output_variables_lower_bound(void) method

void TestMultilayerPerceptron::test_get_output_variables_lower_bound(void)
{
   message += "test_get_output_variables_lower_bound\n";
}


// void test_get_output_variables_upper_bound(void) method

void TestMultilayerPerceptron::test_get_output_variables_upper_bound(void)
{
   message += "test_get_output_variables_upper_bound\n";
}


// void test_get_output_variables_bounds(void) method

void TestMultilayerPerceptron::test_get_output_variables_bounds(void)
{
   message += "test_get_output_variables_bounds\n";
}


// void test_get_output_variable_lower_bound(void) method

void TestMultilayerPerceptron::test_get_output_variable_lower_bound(void)
{
   message += "test_get_output_variable_lower_bound\n";
}


// void test_get_output_variable_upper_bound(void) method

void TestMultilayerPerceptron::test_get_output_variable_upper_bound(void)
{
   message += "test_get_output_variable_upper_bound\n";
}


// void test_get_independent_parameters_number(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_number(void)
{
   message += "test_get_independent_parameters_number\n";
}


// void test_get_independent_parameters(void) method

void TestMultilayerPerceptron::test_get_independent_parameters(void)   
{
   message += "test_get_independent_parameters\n";
}


// void test_get_independent_parameter(void) method   

void TestMultilayerPerceptron::test_get_independent_parameter(void)   
{
   message += "test_get_independent_parameter\n";
}


// void test_get_independent_parameters_name(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_name(void)
{
   message += "test_get_independent_parameters_name\n";
}


// void test_get_independent_parameter_name(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_name(void)
{
   message += "test_get_independent_parameter_name\n";
}


// void test_get_independent_parameters_units(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_units(void)
{
   message += "test_get_independent_parameters_units\n";
}


// void test_get_independent_parameter_units(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_units(void)
{
   message += "test_get_independent_parameter_units\n";
}


// void test_get_independent_parameters_information(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_information(void)
{
   message += "test_get_independent_parameters_information\n";
}


// void test_get_independent_parameters_description(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_description(void)
{
   message += "test_get_independent_parameters_description\n";
}


// void test_get_independent_parameter_description(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_description(void)
{
   message += "test_get_independent_parameter_description\n";
}


// void test_get_independent_parameters_mean(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_mean(void)
{
   message += "test_get_independent_parameters_mean\n";
}


// void test_get_independent_parameters_standard_deviation(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_standard_deviation(void)
{
   message += "test_get_independent_parameters_standard_deviation\n";
}


// void test_get_independent_parameters_mean_standard_deviation(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_mean_standard_deviation(void)
{
   message += "test_get_independent_parameters_mean_standard_deviation\n";
}


// void test_get_independent_parameter_mean(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_mean(void)
{
   message += "test_get_independent_parameter_mean\n";
}


// void test_get_independent_parameter_standard_deviation(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_standard_deviation(void)
{
   message += "test_get_independent_parameter_standard_deviation\n";
}


// void test_get_independent_parameters_minimum(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_minimum(void)
{
   message += "test_get_independent_parameters_minimum\n";
}


// void test_get_independent_parameters_maximum(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_maximum(void)
{
   message += "test_get_independent_parameters_maximum\n";
}


// void test_get_independent_parameters_minimum_maximum(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_minimum_maximum(void)
{
   message += "test_get_independent_parameters_minimum_maximum\n";
}


// void test_get_independent_parameter_minimum(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_minimum(void)
{
   message += "test_get_independent_parameter_minimum\n";
}


// void test_get_independent_parameter_maximum(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_maximum(void)
{
   message += "test_get_independent_parameter_maximum\n";
}


// void test_get_independent_parameters_statistics(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_statistics(void)
{
   message += "test_get_independent_parameters_statistics\n";
}


// void test_get_independent_parameters_lower_bound(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_lower_bound(void)
{
   message += "test_get_independent_parameters_lower_bound\n";
}


// void test_get_independent_parameters_upper_bound(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_upper_bound(void)
{
   message += "test_get_independent_parameters_upper_bound\n";
}


// void test_get_independent_parameters_bounds(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_bounds(void)
{
   message += "test_get_independent_parameters_bounds\n";
}


// void test_get_independent_parameter_lower_bound(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_lower_bound(void)
{
   message += "test_get_independent_parameter_lower_bound\n";
}


// void test_get_independent_parameter_upper_bound(void) method

void TestMultilayerPerceptron::test_get_independent_parameter_upper_bound(void)
{
   message += "test_get_independent_parameter_upper_bound\n";
}


// void test_get_numerical_epsilon_method(void) method

void TestMultilayerPerceptron::test_get_numerical_epsilon_method(void)
{
   message += "test_get_numerical_epsilon_method\n";
}


// void test_get_numerical_epsilon_method_name(void) method

void TestMultilayerPerceptron::test_get_numerical_epsilon_method_name(void)
{
   message += "test_get_numerical_epsilon_method_name\n";
}


// void test_get_numerical_epsilon(void) method

void TestMultilayerPerceptron::test_get_numerical_epsilon(void)
{
   message += "test_get_numerical_epsilon\n";
}


// void test_get_display_range_out_warning(void) method

void TestMultilayerPerceptron::test_get_display_range_out_warning(void)
{
   message += "test_get_display_range_out_warning\n";
}


// void test_get_display(void) method

void TestMultilayerPerceptron::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_inputs_scaling_method(void) method

void TestMultilayerPerceptron::test_set_inputs_scaling_method(void)
{
   message += "test_set_inputs_scaling_method\n";
}


// void test_set_outputs_unscaling_method(void) method

void TestMultilayerPerceptron::test_set_outputs_unscaling_method(void)
{
   message += "test_set_outputs_unscaling_method\n";
}


// void test_set_variables_scaling_method(void) method

void TestMultilayerPerceptron::test_set_variables_scaling_method(void)
{
   message += "test_set_variables_scaling_method\n";
}


// void test_set_independent_parameters_scaling_method(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_scaling_method(void)
{
   message += "test_set_independent_parameters_scaling_method\n";
}


// void test_set_numerical_differentiation_method(void) method

void TestMultilayerPerceptron::test_set_numerical_differentiation_method(void)
{
   message += "test_set_numerical_differentiation_method\n";
}


// void test_set_numerical_epsilon_method(void) method

void TestMultilayerPerceptron::test_set_numerical_epsilon_method(void)
{
   message += "test_set_numerical_epsilon_method\n";
}


// void test_set_numerical_epsilon(void) method

void TestMultilayerPerceptron::test_set_numerical_epsilon(void)
{
   message += "test_set_numerical_epsilon\n";
}


// void test_set_network_architecture(void) method

void TestMultilayerPerceptron::test_set_network_architecture(void)
{
   message += "test_set_network_architecture\n";

   MultilayerPerceptron mlp;

   mlp.set_network_architecture(1,1,1);

   int inputs_number = mlp.get_inputs_number();
   Vector<int> hidden_neurons_numbers = mlp.get_hidden_layers_size();
   int outputs_number = mlp.get_outputs_number();

   assert_true(inputs_number == 1, LOG);
   assert_true(hidden_neurons_numbers[0] == 1, LOG);
   assert_true(outputs_number == 1, LOG);
}


// void test_set_hidden_layers_size(void) method

void TestMultilayerPerceptron::test_set_hidden_layers_size(void)
{
   message += "test_set_hidden_layers_size\n";
}


// void test_set_hidden_layer_size(void) method

void TestMultilayerPerceptron::test_set_hidden_layer_size(void)
{
   message += "test_set_hidden_layer_size\n";
}


// void test_set_hidden_layers_activation_function(void) method

void TestMultilayerPerceptron::test_set_hidden_layers_activation_function(void)
{
   message += "test_set_hidden_layers_activation_function\n";
}


// void test_set_hidden_layer_activation_function(void) method

void TestMultilayerPerceptron::test_set_hidden_layer_activation_function(void)
{
   message += "test_set_hidden_layer_activation_function\n";
}


// void test_set_output_layer_activation_function(void) method

void TestMultilayerPerceptron::test_set_output_layer_activation_function(void)
{
   message += "test_set_output_layer_activation_function\n";
}


// void test_set_input_variables_name(void) method

void TestMultilayerPerceptron::test_set_input_variables_name(void)
{
   message += "test_set_input_variables_name\n";
}


// void test_set_output_variables_name(void) method

void TestMultilayerPerceptron::test_set_output_variables_name(void)
{
   message += "test_set_output_variables_name\n";
}


// void test_set_input_variable_name(void) method

void TestMultilayerPerceptron::test_set_input_variable_name(void)
{
   message += "test_set_input_variable_name\n";
}


// void test_set_output_variable_name(void) method

void TestMultilayerPerceptron::test_set_output_variable_name(void)
{
   message += "test_set_output_variable_name\n";
}


// void test_set_input_variables_units(void) method

void TestMultilayerPerceptron::test_set_input_variables_units(void)
{
   message += "test_set_input_variables_units\n";
}


// void test_set_input_variable_units(void) method

void TestMultilayerPerceptron::test_set_input_variable_units(void)
{
   message += "test_set_input_variable_units\n";
}


// void test_set_output_variables_units(void) method

void TestMultilayerPerceptron::test_set_output_variables_units(void)
{
   message += "test_set_output_variables_units\n";
}


// void test_set_output_variable_units(void) method

void TestMultilayerPerceptron::test_set_output_variable_units(void)
{
   message += "test_set_output_variable_units\n";
}


// void test_set_input_variables_description(void) method

void TestMultilayerPerceptron::test_set_input_variables_description(void)
{
   message += "test_set_input_variables_description\n";
}


// void test_set_output_variables_description(void) method

void TestMultilayerPerceptron::test_set_output_variables_description(void)
{
   message += "test_set_output_variables_description\n";
}


// void test_set_input_variable_description(void) method

void TestMultilayerPerceptron::test_set_input_variable_description(void)
{
   message += "test_set_input_variable_description\n";
}


// void test_set_output_variable_description(void) method

void TestMultilayerPerceptron::test_set_output_variable_description(void)
{
   message += "test_set_output_variable_description\n";
}


// void test_set_variables_information(void) method

void TestMultilayerPerceptron::test_set_variables_information(void)
{
   message += "test_set_variables_information\n";
}


// void test_set_input_variables_mean(void) method

void TestMultilayerPerceptron::test_set_input_variables_mean(void)
{
   message += "test_set_input_variables_mean\n";
}


// void test_set_input_variables_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_input_variables_standard_deviation(void)
{
   message += "test_set_input_variables_standard_deviation\n";
}


// void test_set_output_variables_mean(void) method

void TestMultilayerPerceptron::test_set_output_variables_mean(void)
{
   message += "test_set_output_variables_mean\n";
}


// void test_set_output_variables_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_output_variables_standard_deviation(void)
{
   message += "test_set_output_variables_standard_deviation\n";
}


// void test_set_input_variables_mean_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_input_variables_mean_standard_deviation(void)
{
   message += "test_set_input_variables_mean_standard_deviation\n";
}


// void test_set_output_variables_mean_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_output_variables_mean_standard_deviation(void)
{
   message += "test_set_output_variables_mean_standard_deviation\n";
}


// void test_set_input_variable_mean(void) method

void TestMultilayerPerceptron::test_set_input_variable_mean(void)
{
   message += "test_set_input_variable_mean\n";
}


// void test_set_input_variable_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_input_variable_standard_deviation(void)
{
   message += "test_set_input_variable_standard_deviation\n";
}


// void test_set_output_variable_mean(void) method

void TestMultilayerPerceptron::test_set_output_variable_mean(void)
{
   message += "test_set_output_variable_mean\n";
}


// void test_set_output_variable_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_output_variable_standard_deviation(void)
{
   message += "test_set_output_variable_standard_deviation\n";
}


// void test_set_input_variables_minimum(void) method

void TestMultilayerPerceptron::test_set_input_variables_minimum(void)
{
   message += "test_set_input_variables_minimum\n";
}


// void test_set_input_variables_maximum(void) method

void TestMultilayerPerceptron::test_set_input_variables_maximum(void)
{
   message += "test_set_input_variables_maximum\n";
}


// void test_set_output_variables_minimum(void) method

void TestMultilayerPerceptron::test_set_output_variables_minimum(void)
{
   message += "test_set_output_variables_minimum\n";
}


// void test_set_output_variables_maximum(void) method

void TestMultilayerPerceptron::test_set_output_variables_maximum(void)
{
   message += "test_set_output_variables_maximum\n";
}


// void test_set_input_variables_minimum_maximum(void) method

void TestMultilayerPerceptron::test_set_input_variables_minimum_maximum(void)
{
   message += "test_set_input_variables_minimum_maximum\n";
}


// void test_set_output_variables_minimum_maximum(void) method

void TestMultilayerPerceptron::test_set_output_variables_minimum_maximum(void)
{
   message += "test_set_output_variables_minimum_maximum\n";
}


// void test_set_input_variable_minimum(void) method

void TestMultilayerPerceptron::test_set_input_variable_minimum(void)
{
   message += "test_set_input_variable_minimum\n";
}


// void test_set_input_variable_maximum(void) method

void TestMultilayerPerceptron::test_set_input_variable_maximum(void)
{
   message += "test_set_input_variable_maximum\n";
}


// void test_set_output_variable_minimum(void) method

void TestMultilayerPerceptron::test_set_output_variable_minimum(void)
{
   message += "test_set_output_variable_minimum\n";
}


// void test_set_output_variable_maximum(void) method

void TestMultilayerPerceptron::test_set_output_variable_maximum(void)
{
   message += "test_set_output_variable_maximum\n";
}


// void test_set_variables_statistics(void) method

void TestMultilayerPerceptron::test_set_variables_statistics(void)
{
   message += "test_set_variables_statistics\n";
}


// void test_set_output_variables_lower_bound(void) method

void TestMultilayerPerceptron::test_set_output_variables_lower_bound(void)
{
   message += "test_set_output_variables_lower_bound\n";
}


// void test_set_output_variables_upper_bound(void) method

void TestMultilayerPerceptron::test_set_output_variables_upper_bound(void)
{
   message += "test_set_output_variables_upper_bound\n";
}


// void test_set_output_variables_bounds(void) method

void TestMultilayerPerceptron::test_set_output_variables_bounds(void)
{
   message += "test_set_output_variables_bounds\n";
}


// void test_set_output_variable_lower_bound(void) method

void TestMultilayerPerceptron::test_set_output_variable_lower_bound(void)
{
   message += "test_set_output_variable_lower_bound\n";
}


// void test_set_output_variable_upper_bound(void) method

void TestMultilayerPerceptron::test_set_output_variable_upper_bound(void)
{
   message += "test_set_output_variable_upper_bound\n";
}


// void test_set_independent_parameters_number(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_number(void)
{
   message += "test_set_independent_parameters_number\n";
}


// void test_set_independent_parameters(void) method

void TestMultilayerPerceptron::test_set_independent_parameters(void)
{
   message += "test_set_independent_parameters\n";
}


// void test_set_independent_parameter(void) method

void TestMultilayerPerceptron::test_set_independent_parameter(void)
{
   message += "test_set_independent_parameter\n";
}


// void test_set_independent_parameters_name(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_name(void)
{
   message += "test_set_independent_parameters_name\n";
}


// void test_set_independent_parameter_name(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_name(void)
{
   message += "test_set_independent_parameter_name\n";
}


// void test_set_independent_parameters_units(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_units(void)
{
   message += "test_set_independent_parameters_units\n";
}


// void test_set_independent_parameter_units(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_units(void)
{
   message += "test_set_independent_parameter_units\n";
}


// void test_set_independent_parameters_description(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_description(void)
{
   message += "test_set_independent_parameters_description\n";
}


// void test_set_independent_parameter_description(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_description(void)
{
   message += "test_set_independent_parameter_description\n";
}


// void test_set_independent_parameters_mean(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_mean(void)
{
   message += "test_set_independent_parameters_mean\n";
}


// void test_set_independent_parameters_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_standard_deviation(void)
{
   message += "test_set_independent_parameters_standard_deviation\n";
}


// void test_set_independent_parameters_mean_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_mean_standard_deviation(void)
{
   message += "test_set_independent_parameters_mean_standard_deviation\n";
}


// void test_set_independent_parameter_mean(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_mean(void)
{
   message += "test_set_independent_parameter_mean\n";
}


// void test_set_independent_parameter_standard_deviation(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_standard_deviation(void)
{
   message += "test_set_independent_parameter_standard_deviation\n";
}


// void test_set_independent_parameters_minimum(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_minimum(void)
{
   message += "test_set_independent_parameters_minimum\n";
}


// void test_set_independent_parameter_minimum(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_minimum(void)
{
   message += "test_set_independent_parameter_minimum\n";
}


// void test_set_independent_parameters_maximum(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_maximum(void)
{
   message += "test_set_independent_parameters_maximum\n";
}


// void test_set_independent_parameter_maximum(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_maximum(void)
{
   message += "test_set_independent_parameter_maximum\n";
}


// void test_set_independent_parameters_minimum_maximum(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_minimum_maximum(void)
{
   message += "test_set_independent_parameters_minimum_maximum\n";
}


// void test_set_independent_parameters_statistics(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_statistics(void)
{
   message += "test_set_independent_parameters_statistics\n";
}


// void test_set_independent_parameters_lower_bound(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_lower_bound(void)
{
   message += "test_set_independent_parameters_lower_bound\n";
}


// void test_set_independent_parameters_upper_bound(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_upper_bound(void)
{
   message += "test_set_independent_parameters_upper_bound\n";
}


// void test_set_independent_parameters_bounds(void) method

void TestMultilayerPerceptron::test_set_independent_parameters_bounds(void)
{
   message += "test_set_independent_parameters_bounds\n";
}


// void test_set_independent_parameter_lower_bound(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_lower_bound(void)
{
   message += "test_set_independent_parameter_lower_bounds\n";
}


// void test_set_independent_parameter_upper_bound(void) method

void TestMultilayerPerceptron::test_set_independent_parameter_upper_bound(void)
{
   message += "test_set_independent_parameter_upper_bound\n";
}


// void test_set_display_range_out_warning(void) method

void TestMultilayerPerceptron::test_set_display_range_out_warning(void)
{
   message += "test_set_display_range_out_warning\n";
}


// void test_set_display(void) method

void TestMultilayerPerceptron::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_get_parameters_number(void) method

void TestMultilayerPerceptron::test_get_parameters_number(void)
{
   message += "test_get_parameters_number\n";

   MultilayerPerceptron mlp;

   assert_true(mlp.get_parameters_number() == 0, LOG);

   mlp.set_network_architecture(1,1,1);
   mlp.set_independent_parameters_number(0);
   assert_true(mlp.get_parameters_number() == 4, LOG);

   mlp.set_network_architecture(0,0,0);
   mlp.set_independent_parameters_number(1);
   assert_true(mlp.get_parameters_number() == 1, LOG);

   mlp.set_network_architecture(1,1,1);
   mlp.set_independent_parameters_number(1);
   assert_true(mlp.get_parameters_number() == 5, LOG);
}


// void test_get_parameters(void) method  

void TestMultilayerPerceptron::test_get_parameters(void)   
{
   message += "test_get_parameters\n";

   MultilayerPerceptron mlp;
   Vector<double> parameters;

   parameters = mlp.get_parameters();

   assert_true(parameters.get_size() == 0, LOG);

   mlp.set_network_architecture(1,1,1);
   mlp.set_independent_parameters_number(0);
   mlp.initialize_parameters(0.0);
   parameters = mlp.get_parameters();

   assert_true(parameters.get_size() == 4, LOG);
   assert_true(parameters == 0.0, LOG);

   mlp.set_network_architecture(0,0,0);
   mlp.set_independent_parameters_number(1);
   mlp.initialize_parameters(0.0);
   parameters = mlp.get_parameters();
   assert_true(parameters.get_size() == 1, LOG);
   assert_true(parameters == 0.0, LOG);

   mlp.set_network_architecture(1,1,1);
   mlp.set_independent_parameters_number(1);
   mlp.initialize_parameters(0.0);
   parameters = mlp.get_parameters();

   assert_true(parameters.get_size() == 5, LOG);
   assert_true(parameters == 0.0, LOG);
}


// void test_set_parameters(void) method

void TestMultilayerPerceptron::test_set_parameters(void)
{
   message += "test_set_parameters\n";
   Vector<int> hidden_layers_size;
   MultilayerPerceptron mlp;

   int parameters_number;
   Vector<double> parameters;
   // Empty multilayer perceptron
   mlp.set_parameters(parameters);   

   parameters = mlp.get_parameters();
   assert_true(parameters.get_size() == 0, LOG);

   // Only neural parameters
   // Only independent parameters
   // Both neural and independent parameters
      hidden_layers_size.set(2,2);
   mlp.set_network_architecture(2, hidden_layers_size, 2);
   mlp.set_independent_parameters_number(2);
   parameters_number = mlp.get_parameters_number();
   parameters.set(parameters_number);
   parameters.initialize_sequential();   
   mlp.set_parameters(parameters);   
   parameters = mlp.get_parameters();
   assert_true(parameters.get_size() == parameters_number, LOG);
   assert_true(parameters[0] == 0.0, LOG);
   assert_true(parameters[parameters_number-1] == parameters_number-1.0, LOG); 
}


// void test_set_scaling_method(void) method

void TestMultilayerPerceptron::test_set_scaling_method(void)
{
   message += "test_set_scaling_method\n";
}


// void test_initialize_neural_parameters(void) method

void TestMultilayerPerceptron::test_initialize_neural_parameters(void)
{
   message += "test_initialize_neural_parameters\n";

   MultilayerPerceptron mlp;

   Vector<double> neural_parameters;
   mlp.set_network_architecture(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   neural_parameters = mlp.get_neural_parameters();

   assert_true(neural_parameters == 0.0, LOG);
}

// void test_initialize_biases(void) method

void TestMultilayerPerceptron::test_initialize_biases(void)
{
   message += "test_initialize_biases\n";
}

// void test_initialize_synaptic_weights(void) method

void TestMultilayerPerceptron::test_initialize_synaptic_weights(void)
{
   message += "test_initialize_synaptic_weights\n";
}

// void test_initialize_independent_parameters(void) method

void TestMultilayerPerceptron::test_initialize_independent_parameters(void)
{      message += "test_initialize_independent_parameters\n";
   MultilayerPerceptron mlp;
   Vector<double> independent_parameters;

   mlp.set_independent_parameters_number(1);
      mlp.initialize_independent_parameters(0.0);
   independent_parameters = mlp.get_independent_parameters();
      assert_true(independent_parameters == 0.0, LOG);
}

// void test_initialize_parameters(void) method

void TestMultilayerPerceptron::test_initialize_parameters(void)
{
   message += "test_initialize_parameters\n";

   MultilayerPerceptron mlp;
   Vector<double> parameters;
   mlp.set_network_architecture(1,1,1);
   mlp.set_independent_parameters_number(1);    mlp.initialize_parameters_normal(1.0, 0.0);
   parameters = mlp.get_parameters();
   assert_true(parameters == 1.0, LOG);
}


// void test_initialize_neural_parameters_uniform(void) method

void TestMultilayerPerceptron::test_initialize_neural_parameters_uniform(void)
{
   message += "test_initialize_neural_parameters_uniform\n";
   MultilayerPerceptron mlp;
   Vector<double> neural_parameters;
   mlp.set_network_architecture(1,1,1);      mlp.initialize_neural_parameters_uniform();
   neural_parameters = mlp.get_neural_parameters();
   assert_true(neural_parameters >= -1.0, LOG);
   assert_true(neural_parameters <=  1.0, LOG);
}


// void test_initialize_neural_parameters_normal(void) method

void TestMultilayerPerceptron::test_initialize_neural_parameters_normal(void)
{
   message += "test_initialize_neural_parameters_normal\n";
   MultilayerPerceptron mlp;
   Vector<double> neural_parameters;
   mlp.set_network_architecture(1,1,1);      mlp.initialize_neural_parameters_normal(1.0, 0.0);
   neural_parameters = mlp.get_neural_parameters();
   assert_true(neural_parameters == 1.0, LOG);
}


// void test_initialize_independent_parameters_uniform(void) method

void TestMultilayerPerceptron::test_initialize_independent_parameters_uniform(void)
{
   message += "test_initialize_independent_parameters_uniform\n";
   MultilayerPerceptron mlp;
   Vector<double> independent_parameters;
   mlp.set_independent_parameters_number(1);      mlp.initialize_independent_parameters_uniform();
   independent_parameters = mlp.get_independent_parameters();   
   assert_true(independent_parameters >= -1.0, LOG);
   assert_true(independent_parameters <=  1.0, LOG);
}


// void test_initialize_independent_parameters_normal(void) method

void TestMultilayerPerceptron::test_initialize_independent_parameters_normal(void)
{
   message += "test_initialize_independent_parameters_normal\n";
   MultilayerPerceptron mlp;
   Vector<double> independent_parameters;
   mlp.set_independent_parameters_number(1);
      mlp.initialize_independent_parameters_normal(1.0, 0.0);
   independent_parameters = mlp.get_independent_parameters();
      assert_true(independent_parameters == 1.0, LOG);
}


// void test_initialize_parameters_uniform(void) method

void TestMultilayerPerceptron::test_initialize_parameters_uniform(void)
{
   message += "test_initialize_parameters_uniform\n";
   MultilayerPerceptron mlp;
   Vector<double> parameters;
   mlp.set_network_architecture(1,1,1);
   mlp.set_independent_parameters_number(1);    mlp.initialize_parameters_uniform();
   parameters = mlp.get_parameters();
   assert_true(parameters >= -1.0, LOG);
   assert_true(parameters <=  1.0, LOG);   
}


// void test_initialize_parameters_normal(void) method

void TestMultilayerPerceptron::test_initialize_parameters_normal(void)
{
   message += "test_initialize_parameters_normal\n";

   MultilayerPerceptron mlp;
   Vector<double> neural_parameters;
   mlp.set_network_architecture(1,1,1);      mlp.set_independent_parameters_number(1);
   mlp.initialize_neural_parameters_normal(1.0, 0.0);
   neural_parameters = mlp.get_neural_parameters();
   assert_true(neural_parameters == 1.0, LOG);
}


// void test_calculate_neural_parameters_norm(void) method

void TestMultilayerPerceptron::test_calculate_neural_parameters_norm(void)
{
   message += "test_calculate_neural_parameters_norm\n";
}


// void test_calculate_independent_parameters_norm(void) method 

void TestMultilayerPerceptron::test_calculate_independent_parameters_norm(void)
{
   message += "test_calculate_independent_parameters_norm\n";
}


// void test_calculate_parameters_norm(void) method

void TestMultilayerPerceptron::test_calculate_parameters_norm(void)
{
   message += "test_calculate_parameters_norm\n";
}


// void check_input_range(void) method

void TestMultilayerPerceptron::test_check_input_range(void)
{
   message += "test_check_input_range\n";
   MultilayerPerceptron mlp(1,1,1);
   mlp.set_input_variable_minimum(0, -1.0);      mlp.set_input_variable_maximum(0, 1.0);
   Vector<double> input(1, 0.0);
   mlp.check_input_range(input);
}


// void test_calculate_scaled_input(void) method

void TestMultilayerPerceptron::test_calculate_scaled_input(void)
{
   message += "test_calculate_scaled_input\n";
   MultilayerPerceptron mlp(1,1,1);
   
   Vector<double> input(1);

   mlp.set_inputs_scaling_method(MultilayerPerceptron::None);

   mlp.initialize_neural_parameters(0.0);
   input[0] = 0.0;

   assert_true(mlp.calculate_scaled_input(input) == input, LOG);

   mlp.set_inputs_scaling_method(MultilayerPerceptron::MeanStandardDeviation);
 
   mlp.set_input_variable_mean(0, 0.0);
   mlp.set_input_variable_standard_deviation(0, 1.0);

   mlp.initialize_neural_parameters(0.0);
   input[0] = 0.0;

   assert_true(mlp.calculate_scaled_input(input) == input, LOG);

   mlp.set_inputs_scaling_method(MultilayerPerceptron::MinimumMaximum);

   mlp.set_input_variable_minimum(0, -1.0);
   mlp.set_input_variable_maximum(0,  1.0);

   mlp.initialize_neural_parameters(0.0);
   input[0] = 0.0;

   assert_true(mlp.calculate_scaled_input(input) == input, LOG);
}


// void test_calculate_hidden_layer_combination(void) method

void TestMultilayerPerceptron::test_calculate_hidden_layer_combination(void)
{
   message += "test_calculate_hidden_layer_combination\n";

   MultilayerPerceptron mlp(1,2,3);
   mlp.initialize_neural_parameters(0.0);
   Vector<double> input(1, 0.0);   

   Vector<double> hidden_layer_combination = mlp.calculate_hidden_layer_combination(0, input);
   assert_true(hidden_layer_combination.get_size() == 2, LOG);      assert_true(hidden_layer_combination == 0.0, LOG);
}


// void test_calculate_hidden_layer_activation(void) method

void TestMultilayerPerceptron::test_calculate_hidden_layer_activation(void)
{
   message += "test_calculate_hidden_layer_activation\n";

   MultilayerPerceptron mlp(1,2,3);
   mlp.initialize_neural_parameters(0.0);
   Vector<double> hidden_layer_combination(2, 0.0);   
      Vector<double> hidden_layer_activation(2);
   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Logistic);
   hidden_layer_activation = mlp.calculate_hidden_layer_activation(0, hidden_layer_combination);
   assert_true(hidden_layer_activation.get_size() == 2, LOG);
   assert_true(hidden_layer_activation == 0.5, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::HyperbolicTangent);
   hidden_layer_activation = mlp.calculate_hidden_layer_activation(0, hidden_layer_combination);
   assert_true(hidden_layer_activation.get_size() == 2, LOG);
   assert_true(hidden_layer_activation == 0.0, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Threshold);
   hidden_layer_activation = mlp.calculate_hidden_layer_activation(0, hidden_layer_combination);
   assert_true(hidden_layer_activation.get_size() == 2, LOG);
   assert_true(hidden_layer_activation == 1.0, LOG);
   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::SymmetricThreshold);
   hidden_layer_activation = mlp.calculate_hidden_layer_activation(0, hidden_layer_combination);
   assert_true(hidden_layer_activation.get_size() == 2, LOG);
   assert_true(hidden_layer_activation == 1.0, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Linear);
   hidden_layer_activation = mlp.calculate_hidden_layer_activation(0, hidden_layer_combination);
   assert_true(hidden_layer_activation.get_size() == 2, LOG);
   assert_true(hidden_layer_activation == 0.0, LOG);
}


// void test_calculate_hidden_layer_activation_derivative(void) method

void TestMultilayerPerceptron::test_calculate_hidden_layer_activation_derivative(void)
{
   message += "test_calculate_hidden_layer_activation_derivative\n";

   MultilayerPerceptron mlp(1, 2, 3);
   mlp.initialize_neural_parameters(0.0);
   Vector<double> hidden_layer_combination(2, 0.0);         Vector<double> hidden_layer_activation_derivative(2); 
   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Logistic);
   hidden_layer_activation_derivative = mlp.calculate_hidden_layer_activation_derivative(0, hidden_layer_combination);
      assert_true(hidden_layer_activation_derivative.get_size() == 2, LOG);
   assert_true(hidden_layer_activation_derivative == 0.25, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::HyperbolicTangent);
   hidden_layer_activation_derivative = mlp.calculate_hidden_layer_activation_derivative(0, hidden_layer_combination);       assert_true(hidden_layer_activation_derivative.get_size() == 2, LOG);
   assert_true(hidden_layer_activation_derivative == 1.0, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Linear);
   hidden_layer_activation_derivative = mlp.calculate_hidden_layer_activation_derivative(0, hidden_layer_combination);      assert_true(hidden_layer_activation_derivative.get_size() == 2, LOG);
   assert_true(hidden_layer_activation_derivative == 1.0, LOG);   
}


// void test_calculate_hidden_layer_activation_second_derivative(void) method

void TestMultilayerPerceptron::test_calculate_hidden_layer_activation_second_derivative(void)
{
   message += "test_calculate_hidden_layer_activation_second_derivative\n";

   MultilayerPerceptron mlp(1,2,3);
   mlp.initialize_neural_parameters(0.0);
   Vector<double> hidden_layer_combination(2, 0.0);   
      Vector<double> hidden_layer_activation_second_derivative(2); 

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Logistic);
   hidden_layer_activation_second_derivative  = mlp.calculate_hidden_layer_activation_second_derivative(0, hidden_layer_combination);
      assert_true(hidden_layer_activation_second_derivative.get_size() == 2, LOG);

   assert_true(hidden_layer_activation_second_derivative == 0.0, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::HyperbolicTangent);
   hidden_layer_activation_second_derivative = mlp.calculate_hidden_layer_activation_second_derivative(0, hidden_layer_combination);
      assert_true(hidden_layer_activation_second_derivative.get_size() == 2, LOG);
   assert_true(hidden_layer_activation_second_derivative == 0.0, LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Linear);
   hidden_layer_activation_second_derivative = mlp.calculate_hidden_layer_activation_second_derivative(0, hidden_layer_combination);
      assert_true(hidden_layer_activation_second_derivative.get_size() == 2, LOG);
   assert_true(hidden_layer_activation_second_derivative == 0.0, LOG);
}

// void test_calculate_hidden_layer_output(void) method

void TestMultilayerPerceptron::test_calculate_hidden_layer_output(void)
{
   message += "test_calculate_hidden_layer_output\n";
}


// void test_calculate_output_layer_combination(void) method

void TestMultilayerPerceptron::test_calculate_output_layer_combination(void)
{
   message += "test_calculate_output_layer_combination\n";

   MultilayerPerceptron mlp(1,2,3);
   mlp.initialize_neural_parameters(0.0);
   Vector<double> hidden_layer_output(2, 0.0);   

   Vector<double> output_layer_combination = mlp.calculate_output_layer_combination(hidden_layer_output);         assert_true(output_layer_combination.get_size() == 3, LOG);
   assert_true(output_layer_combination == 0.0, LOG);
}


// void test_calculate_output_layer_activation(void) method

void TestMultilayerPerceptron::test_calculate_output_layer_activation(void)
{
   message += "test_calculate_output_layer_activation\n";
}


// void test_calculate_output_layer_activation_derivative(void) method

void TestMultilayerPerceptron::test_calculate_output_layer_activation_derivative(void)
{
   message += "test_calculate_output_layer_activation_derivative\n";

   MultilayerPerceptron mlp;

   Vector<double> output_layer_combination;
   Vector<double> output_layer_activation_derivative;

   // Test 

   mlp.set_network_architecture(1,1,2);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Logistic);

   output_layer_combination.set_size(2);
   output_layer_combination[0] = -5.0;
   output_layer_combination[1] =  5.0;

   output_layer_activation_derivative = mlp.calculate_output_layer_activation_derivative(output_layer_combination);

   // Test 

   mlp.set_network_architecture(1,1,2);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::HyperbolicTangent);

   output_layer_combination.set_size(2);
   output_layer_combination[0] = -5.0;
   output_layer_combination[1] =  5.0;

   output_layer_activation_derivative = mlp.calculate_output_layer_activation_derivative(output_layer_combination);

   // Test 

   mlp.set_network_architecture(1,1,2);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Linear);

   output_layer_combination.set_size(2);
   output_layer_combination[0] = -5.0;
   output_layer_combination[1] =  5.0;

   output_layer_activation_derivative = mlp.calculate_output_layer_activation_derivative(output_layer_combination);

   assert_true(output_layer_activation_derivative.get_size() == 2, LOG);
   assert_true(output_layer_activation_derivative == 1.0, LOG);
}


// void test_calculate_output_layer_activation_second_derivative(void) method

void TestMultilayerPerceptron::test_calculate_output_layer_activation_second_derivative(void)
{
   message += "test_calculate_output_layer_activation_second_derivative\n";

   MultilayerPerceptron mlp;

   Vector<double> output_layer_combination;
   Vector<double> output_layer_activation_second_derivative;

   // Test 

   mlp.set_network_architecture(1,1,2);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Logistic);

   output_layer_combination.set_size(2);
   output_layer_combination[0] = -1.0;
   output_layer_combination[1] =  1.0;

   output_layer_activation_second_derivative = mlp.calculate_output_layer_activation_second_derivative(output_layer_combination);

   // Test 

   mlp.set_network_architecture(1,1,2);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::HyperbolicTangent);

   output_layer_combination.set_size(2);
   output_layer_combination[0] = -1.0;
   output_layer_combination[1] =  1.0;

   output_layer_activation_second_derivative = mlp.calculate_output_layer_activation_second_derivative(output_layer_combination);

   // Test 

   mlp.set_network_architecture(1,1,2);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Linear);

   output_layer_combination.set_size(2);
   output_layer_combination[0] = -1.0;
   output_layer_combination[1] =  1.0;

   output_layer_activation_second_derivative = mlp.calculate_output_layer_activation_second_derivative(output_layer_combination);

   assert_true(output_layer_activation_second_derivative.get_size() == 2, LOG);
   assert_true(output_layer_activation_second_derivative == 0.0, LOG);
}


// void test_calculate_output_layer_output(void) method

void TestMultilayerPerceptron::test_calculate_output_layer_output(void)
{
   message += "test_calculate_output_layer_output\n";

   MultilayerPerceptron mlp(1,2,3);

   mlp.initialize_neural_parameters(0.0);

   Vector<double> output_layer_combination(3, 0.0);   
      Vector<double> output_layer_activation(3);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Logistic);
   output_layer_activation = mlp.calculate_output_layer_activation(output_layer_combination);
   assert_true(output_layer_activation.get_size() == 3, LOG);
   assert_true(output_layer_activation == 0.5, LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::HyperbolicTangent);
   output_layer_activation = mlp.calculate_output_layer_activation(output_layer_combination);
   assert_true(output_layer_activation.get_size() == 3, LOG);
   assert_true(output_layer_activation == 0.0, LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::Threshold);
   output_layer_activation = mlp.calculate_output_layer_activation(output_layer_combination);
   assert_true(output_layer_activation.get_size() == 3, LOG);
   assert_true(output_layer_activation == 1.0, LOG);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::SymmetricThreshold);
   output_layer_activation = mlp.calculate_output_layer_activation(output_layer_combination);

   assert_true(output_layer_activation.get_size() == 3, LOG);
   assert_true(output_layer_activation == 1.0, LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::Linear);
   output_layer_activation = mlp.calculate_output_layer_activation(output_layer_combination);
   assert_true(output_layer_activation.get_size() == 3, LOG);
   assert_true(output_layer_activation == 0.0, LOG);
}


// void test_calculate_unscaled_output(void) method

void TestMultilayerPerceptron::test_calculate_unscaled_output(void)
{
   message += "test_calculate_unscaled_output\n";

   MultilayerPerceptron mlp(1, 1, 1);

   Vector<double> scaled_output(1);

   mlp.set_outputs_unscaling_method(MultilayerPerceptron::None);

   scaled_output[0] = 0.0;
   mlp.initialize_neural_parameters(0.0);

   assert_true(mlp.calculate_unscaled_output(scaled_output) == scaled_output, LOG);

   mlp.set_outputs_unscaling_method(MultilayerPerceptron::MeanStandardDeviation);

   mlp.set_output_variable_mean(0, 0.0);
   mlp.set_output_variable_standard_deviation(0, 1.0);

   scaled_output[0] = 0.0;
   mlp.initialize_neural_parameters(0.0);

   assert_true(mlp.calculate_unscaled_output(scaled_output) == scaled_output, LOG);

   mlp.set_outputs_unscaling_method(MultilayerPerceptron::MinimumMaximum);

   mlp.set_output_variable_minimum(0, -1.0);
   mlp.set_output_variable_maximum(0,  1.0);

   scaled_output[0] = 0.0;
   mlp.initialize_neural_parameters(0.0);

   assert_true(mlp.calculate_unscaled_output(scaled_output) == scaled_output, LOG);
}


// void test_calculate_bounded_output(void) method

void TestMultilayerPerceptron::test_calculate_bounded_output(void)
{
   message += "test_calculate_bounded_output\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.set_output_variable_lower_bound(0, -1.0);
   mlp.set_output_variable_upper_bound(0,  1.0);
   Vector<double> output(1);

   Vector<double> bounded_output(1);
   output[0] = -2.0; 
   bounded_output = mlp.calculate_bounded_output(output);
   assert_true(bounded_output.get_size() == 1, LOG);
   assert_true(bounded_output == -1.0, LOG);
   output[0] = 2.0;
   bounded_output = mlp.calculate_bounded_output(output);
   assert_true(bounded_output.get_size() == 1, LOG);
   assert_true(bounded_output == 1.0, LOG);
}


// void test_calculate_forward_propagation(void) method

void TestMultilayerPerceptron::test_calculate_forward_propagation(void)
{
   message += "test_calculate_forward_propagation\n";

   Vector<int> hidden_layers_size(2);
   hidden_layers_size[0] = 2;
   hidden_layers_size[1] = 3;

   MultilayerPerceptron mlp(1,hidden_layers_size,4);

   int hidden_layers_number = mlp.get_hidden_layers_number();

   mlp.initialize_neural_parameters(0.0);

   Vector<double> input(1, 0.0);

   Vector< Vector<double> > forward_propagation = mlp.calculate_forward_propagation(input);

   int forward_propagation_size = forward_propagation.get_size();
   assert_true(forward_propagation_size == hidden_layers_number+1, LOG);

   // Output from first hidden layer

   int first_hidden_layer_output_size = forward_propagation[0].get_size();
   assert_true(first_hidden_layer_output_size == 2, LOG);

   Vector<double> first_hidden_layer_output = forward_propagation[0];
   assert_true(first_hidden_layer_output == 0.0, LOG);

   // Output from second hidden layer

   int second_hidden_layer_output_size = forward_propagation[1].get_size();
   assert_true(second_hidden_layer_output_size == 3, LOG);

   Vector<double> second_hidden_layer_output = forward_propagation[1];
   assert_true(second_hidden_layer_output == 0.0, LOG);

   // Output from output layer

   int output_layer_output_size = forward_propagation[2].get_size();
   assert_true(output_layer_output_size == 4, LOG);

   Vector<double> output_layer_output = forward_propagation[2];
   assert_true(output_layer_output == 0.0, LOG);
}


// void test_calculate_forward_propagation_derivative(void) method

void TestMultilayerPerceptron::test_calculate_forward_propagation_derivative(void)
{
   message += "test_calculate_forward_propagation_derivative\n";

   Vector<int> hidden_layers_size(2);
   hidden_layers_size[0] = 2;
   hidden_layers_size[1] = 3;

   MultilayerPerceptron mlp(1,hidden_layers_size,4);

   int hidden_layers_number = mlp.get_hidden_layers_number();

   mlp.initialize_neural_parameters(0.0);

   Vector<double> input(1, 0.0);

   Vector< Vector<double> > forward_propagation_derivative = mlp.calculate_forward_propagation_derivative(input);

   int forward_propagation_derivative_size = forward_propagation_derivative.get_size();
   assert_true(forward_propagation_derivative_size == 2*hidden_layers_number+2, LOG);

   // Activation from first hidden layer

   int first_hidden_layer_activation_size = forward_propagation_derivative[0].get_size();
   assert_true(first_hidden_layer_activation_size == 2, LOG);

   Vector<double> first_hidden_layer_activation = forward_propagation_derivative[0];
   assert_true(first_hidden_layer_activation == 0.0, LOG);

   // Activation derivative from first hidden layer

   int first_hidden_layer_activation_derivative_size = forward_propagation_derivative[1].get_size();
   assert_true(first_hidden_layer_activation_derivative_size == 2, LOG);

   Vector<double> first_hidden_layer_activation_derivative = forward_propagation_derivative[1];
   assert_true(first_hidden_layer_activation_derivative == 1.0, LOG);

   // Activation from second hidden layer

   int second_hidden_layer_activation_size = forward_propagation_derivative[2].get_size();
   assert_true(second_hidden_layer_activation_size == 3, LOG);

   Vector<double> second_hidden_layer_activation = forward_propagation_derivative[2];
   assert_true(second_hidden_layer_activation == 0.0, LOG);

   // Activation derivative from second hidden layer

   int second_hidden_layer_activation_derivative_size = forward_propagation_derivative[3].get_size();
   assert_true(second_hidden_layer_activation_derivative_size == 3, LOG);

   Vector<double> second_hidden_layer_activation_derivative = forward_propagation_derivative[3];
   assert_true(second_hidden_layer_activation_derivative == 1.0, LOG);

   // Activation from output layer

   int output_layer_activation_size = forward_propagation_derivative[4].get_size();
   assert_true(output_layer_activation_size == 4, LOG);

   Vector<double> output_layer_activation = forward_propagation_derivative[4];
   assert_true(output_layer_activation == 0.0, LOG);

   // Activation derivative from output layer

   int output_layer_activation_derivative_size = forward_propagation_derivative[5].get_size();
   assert_true(output_layer_activation_derivative_size == 4, LOG);

   Vector<double> output_layer_activation_derivative = forward_propagation_derivative[5];
   assert_true(output_layer_activation_derivative == 1.0, LOG);
}


// void test_calculate_forward_propagation_second_derivative(void) method

void TestMultilayerPerceptron::test_calculate_forward_propagation_second_derivative(void)
{
   message += "test_calculate_forward_propagation_second_derivative\n";

}


// void test_calculate_output(void) method

void TestMultilayerPerceptron::test_calculate_output(void)
{
   message += "test_calculate_output\n";

   MultilayerPerceptron mlp(3, 4, 2);

   mlp.initialize_neural_parameters(0.0);

   Vector<double> input(3, 0.0);

   Vector<double> output = mlp.calculate_output(input);

   assert_true(output == 0.0, LOG);

   // Pre and unscaling

   // Bounds

}


// void test_calculate_output_matrix(void) method

void TestMultilayerPerceptron::test_calculate_output_matrix(void)
{
   message += "test_calculate_output_matrix\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   Matrix<double> input_matrix(2, 1, 0.0);

   Matrix<double> true_input_matrix(2, 1, 0.0);

   Matrix<double> output_matrix = mlp.calculate_output_matrix(input_matrix);

   assert_true(input_matrix == true_input_matrix, LOG);
}


// void test_calculate_output_boundary_conditions(void) method

void TestMultilayerPerceptron::test_calculate_output_boundary_conditions(void)
{
   message += "test_calculate_output_boundary_conditions\n";

   // x1 = -1, y_1 = -1,
   // x1 =  1, y_1 =  1,

   Vector<int> hidden_layers_size(1, 1);
   MockMultilayerPerceptron mmlp(1, hidden_layers_size, 1);

   mmlp.set_inputs_scaling_method(MultilayerPerceptron::None);

   Vector<double> input(1);
   Vector<double> output(1);

   // x1 = -1, y_1 = -1,

   input[0] = -1.0;
   output = mmlp.calculate_output(input, mmlp);
//   assert_true(output[0] == -1.0, LOG);

   // x1 =  1, y_1 =  1,

   input[0] =  1.0;
   output = mmlp.calculate_output(input, mmlp);
//   assert_true(output[0] == 1.0, LOG);
}


// void test_calculate_output_matrix_boundary_conditions(void) method

void TestMultilayerPerceptron::test_calculate_output_matrix_boundary_conditions(void)
{
   message += "test_calculate_output_matrix_boundary_conditions\n";
}


// void test_scale_independent_parameters(void) method

void TestMultilayerPerceptron::test_scale_independent_parameters(void)
{
   message += "test_scale_independent_parameters\n";

   MultilayerPerceptron mlp(1);
   Vector<double> independent_parameters(1);
   Vector<double> scaled_independent_parameters(1);
   
   // No scaling and unscaling
   
   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::None);

   mlp.initialize_independent_parameters(0.0);

   independent_parameters = mlp.get_independent_parameters();

   assert_true(mlp.scale_independent_parameters() == independent_parameters, LOG);

   // Mean and standard deviation scaling and unscaling

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MeanStandardDeviation);
 
   mlp.set_independent_parameter_mean(0, 0.0);
   mlp.set_independent_parameter_standard_deviation(0, 1.0);

   mlp.initialize_independent_parameters(0.0);

   assert_true(mlp.scale_independent_parameters() == independent_parameters, LOG);

   // Minimum and maximum scaling and unscaling

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   mlp.set_independent_parameter_minimum(0, -1.0);
   mlp.set_independent_parameter_maximum(0,  1.0);

   mlp.initialize_independent_parameters(0.0);

   assert_true(mlp.scale_independent_parameters() == independent_parameters, LOG);      
}


// void test_unscale_independent_parameters(void) method

void TestMultilayerPerceptron::test_unscale_independent_parameters(void)
{
   message += "test_unscale_independent_parameters\n";

   MultilayerPerceptron mlp(1);
   Vector<double> scaled_independent_parameters(1, 0.0);
   Vector<double> independent_parameters(1, 0.0);

   // No scaling and unscaling

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::None);

   scaled_independent_parameters[0] = 0.0;

   mlp.unscale_independent_parameters(scaled_independent_parameters);

   independent_parameters = mlp.get_independent_parameters();

   assert_true(independent_parameters == scaled_independent_parameters, LOG);

   // Mean and standard deviation scaling and unscaling

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MeanStandardDeviation);

   mlp.set_independent_parameter_mean(0, 0.0);
   mlp.set_independent_parameter_standard_deviation(0, 1.0);

   scaled_independent_parameters[0] = 0.0;
   mlp.initialize_independent_parameters(0.0);

   mlp.unscale_independent_parameters(scaled_independent_parameters);

   independent_parameters = mlp.get_independent_parameters();

   assert_true(independent_parameters == scaled_independent_parameters, LOG);

   // Minimum and maximum scaling and unscaling

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   mlp.set_independent_parameter_minimum(0, -1.0);
   mlp.set_independent_parameter_maximum(0,  1.0);

   scaled_independent_parameters[0] = 0.0;
   mlp.initialize_independent_parameters(0.0);

   mlp.unscale_independent_parameters(scaled_independent_parameters);

   independent_parameters = mlp.get_independent_parameters();

   assert_true(independent_parameters == scaled_independent_parameters, LOG);
}


// void test_bound_independent_parameters(void) method

void TestMultilayerPerceptron::test_bound_independent_parameters(void)
{
   message += "test_bound_independent_parameters\n";
}


// void test_bound_independent_parameter(void) method

void TestMultilayerPerceptron::test_bound_independent_parameter(void)
{
   message += "test_bound_independent_parameter\n";
}


// void test_calculate_Jacobian(void) method

void TestMultilayerPerceptron::test_calculate_Jacobian(void)
{
   message += "test_calculate_Jacobian\n";

   // One hidden layer

   MultilayerPerceptron mlp;
   Vector<double> input;
   Matrix<double> Jacobian;
   Matrix<double> true_Jacobian;
   Vector<int> hidden_layers_size;   

   // Test

   mlp.set(1,1,1);
   mlp.initialize_neural_parameters(0.0);
   input.set_size(1, 0.0);
   Jacobian = mlp.calculate_Jacobian(input);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   mlp.set(3,4,2);
   mlp.initialize_neural_parameters(0.0);
   input.set(3, 0.0);
   Jacobian = mlp.calculate_Jacobian(input);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   mlp.set(3,4,2);
   mlp.initialize_neural_parameters(0.0);
   input.set(3, 0.0);
   true_Jacobian = mlp.calculate_Jacobian_numerical_differentiation(input);
   Jacobian = mlp.calculate_Jacobian(input);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   hidden_layers_size.set(2, 1);   
   mlp.set(1, hidden_layers_size, 1);
   mlp.initialize_neural_parameters(0.0);
   input.set(1, 0.0);
   Jacobian = mlp.calculate_Jacobian(input);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   hidden_layers_size.set(2);   
   hidden_layers_size[0] = 4;
   hidden_layers_size[1] = 1;
   mlp.set(3, hidden_layers_size, 2);
   mlp.initialize_neural_parameters(0.0);
   input.set(3, 0.0);
   Jacobian = mlp.calculate_Jacobian(input);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   hidden_layers_size.set(2);   
   hidden_layers_size[0] = 4;
   hidden_layers_size[1] = 5;
   mlp.set(3, hidden_layers_size, 2);

   input.set(3);
   input[0] = 0.0;
   input[1] = 1.0;
   input[2] = 2.0;

   true_Jacobian = mlp.calculate_Jacobian_numerical_differentiation(input);   

   Jacobian = mlp.calculate_Jacobian(input);

   assert_true(true_Jacobian - Jacobian > -1.0e-6, LOG);    
   assert_true(true_Jacobian - Jacobian <  1.0e-6, LOG);    
}


// void test_calculate_hidden_layer_Jacobian(void) method

void TestMultilayerPerceptron::test_calculate_hidden_layer_Jacobian(void)
{
	message += "test_calculate_hidden_layer_Jacobian\n";
}

// void test_calculate_output_layer_Jacobian(void) method

void TestMultilayerPerceptron::test_calculate_output_layer_Jacobian(void)
{
   message += "test_calculate_output_layer_Jacobian\n";
}


// void test_calculate_Jacobian_numerical_differentiation(void) method

void TestMultilayerPerceptron::test_calculate_Jacobian_numerical_differentiation(void)
{
   message += "test_calculate_Jacobian_numerical_differentiation\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   Vector<double> input(1, 0.0);

   Matrix<double> true_Jacobian(1, 1, 0.0);

   Matrix<double> Jacobian = mlp.calculate_Jacobian_numerical_differentiation(input);

   assert_true(Jacobian == true_Jacobian, LOG);
}


// void test_calculate_Jacobian_forward_differences(void) method

void TestMultilayerPerceptron::test_calculate_Jacobian_forward_differences(void)
{
   message += "test_calculate_Jacobian_forward_differences\n";
}

// void test_calculate_Jacobian_central_differences(void) method

void TestMultilayerPerceptron::test_calculate_Jacobian_central_differences(void)
{
   message += "test_calculate_Jacobian_central_differences\n";
}


// void test_calculate_Jacobian_vector(void) method

void TestMultilayerPerceptron::test_calculate_Jacobian_vector(void)
{
   message += "test_calculate_Jacobian_vector\n";
}


// void test_calculate_Jacobian_boundary_conditions(void) method

void TestMultilayerPerceptron::test_calculate_Jacobian_boundary_conditions(void)
{
   message += "test_calculate_Jacobian_boundary_conditions\n";
}


// void test_calculate_Jacobian_vector_boundary_conditions(void) method

void TestMultilayerPerceptron::test_calculate_Jacobian_vector_boundary_conditions(void)
{
   message += "test_calculate_Jacobian_vector_boundary_conditions\n";
}


// void test_calculate_sensitivity(void) method

void TestMultilayerPerceptron::test_calculate_sensitivity(void)
{
   message += "test_calculate_sensitivity\n";

   MultilayerPerceptron mlp(1,1,1);

   mlp.initialize_neural_parameters(0.0);

   Vector<double> input(1, 0.0);

   Matrix<double> sensitivity = mlp.calculate_sensitivity(input);
}


// void test_calculate_sensitivity_vector(void) method

void TestMultilayerPerceptron::test_calculate_sensitivity_vector(void)
{
   message += "test_calculate_sensitivity_vector\n";
}


// void test_calculate_sensitivity_numerical_differentiation(void) method

void TestMultilayerPerceptron::test_calculate_sensitivity_numerical_differentiation(void)
{
   message += "test_calculate_sensitivity_numerical_differentiation\n";
}


// void test_calculate_sensitivity_forward_differences(void) method

void TestMultilayerPerceptron::test_calculate_sensitivity_forward_differences(void)
{
	message += "test_calculate_sensitivity_forward_differences\n";
}

// void test_calculate_sensitivity_central_differences(void) method

void TestMultilayerPerceptron::test_calculate_sensitivity_central_differences(void)
{
   message += "test_calculate_sensitivity_central_differences\n";
}


// void test_to_XML(void) method

void TestMultilayerPerceptron::test_to_XML(void)
{
   message += "test_to\n";

   MultilayerPerceptron  mlp;

   std::string object = mlp.to_XML(true);

   assert_true(object.length() != 0, LOG);
}


// void print(void) method

void TestMultilayerPerceptron::test_print(void)
{
   message += "test_print\n";

   MultilayerPerceptron  mlp;

   mlp.set_display(false);

   //mlp.print();
}


// void test_save(void) method

void TestMultilayerPerceptron::test_save(void)
{
   message += "test_save\n";

   // Empty multilayer perceptron
 
   MultilayerPerceptron mlp1;
   mlp1.save("../Data/MultilayerPerceptron.dat");

   // Only network architecture

   MultilayerPerceptron mlp2(2, 4, 3);
   mlp2.save("../Data/MultilayerPerceptron.dat");

   // Only independent parameters

   MultilayerPerceptron mlp3(2);
   mlp3.save("../Data/MultilayerPerceptron.dat");

   // Both network architecture and independent parameters

   MultilayerPerceptron mlp4(1, 1, 1);
   mlp4.set_independent_parameters_number(1);
   mlp4.save("../Data/MultilayerPerceptron.dat");

   // Name

   MultilayerPerceptron mlp5(1,1,1);
   mlp5.set_independent_parameters_number(1);

   mlp5.set_input_variable_name(0, "Input");
   mlp5.set_output_variable_name(0, "Output");
   mlp5.set_independent_parameter_name(0, "IndependentParameter");

   mlp5.save("../Data/MultilayerPerceptron.dat");

   // Units

   // Description
}


// void test_load(void) method

void TestMultilayerPerceptron::test_load(void)
{
   message += "test_load\n";

   // Empty multilayer perceptron

   MultilayerPerceptron mlp1;
   mlp1.save("../Data/MultilayerPerceptron.dat");
   mlp1.load("../Data/MultilayerPerceptron.dat");

   assert_true(mlp1.get_inputs_number() == 0, LOG);
   assert_true(mlp1.get_hidden_layers_number() == 0, LOG);
   assert_true(mlp1.get_outputs_number() == 0, LOG);
   assert_true(mlp1.get_independent_parameters_number() == 0, LOG);

   // Only network architecture

   MultilayerPerceptron mlp2(2, 4, 3);

   mlp2.set_input_variable_name(0, "Input 1");
   mlp2.set_output_variable_name(2, "Output 3");

   mlp2.set_input_variable_units(1, "[m]");
   mlp2.set_output_variable_units(0, "[s-1]");

   mlp2.set_input_variable_description(0, "Description of input variable 1");
   mlp2.set_output_variable_description(1, "Description of output variable 2");

   mlp2.set_input_variable_mean(0, 2.0);
   mlp2.set_input_variable_standard_deviation(1, 0.5);

   mlp2.set_input_variable_minimum(0, -2.0);
   mlp2.set_input_variable_maximum(1, -0.5);

   mlp2.set_output_variable_mean(2, 20.0);
   mlp2.set_output_variable_standard_deviation(0, 0.05);

   mlp2.set_output_variable_minimum(0, -20.0);
   mlp2.set_output_variable_maximum(2, -0.05);

   mlp2.save("../Data/MultilayerPerceptron.dat");
   mlp2.load("../Data/MultilayerPerceptron.dat");

   assert_true(mlp2.get_inputs_number() == 2, LOG);
   assert_true(mlp2.get_hidden_layers_number() == 1, LOG);
   assert_true(mlp2.get_hidden_layers_size() == 4, LOG);
   assert_true(mlp2.get_outputs_number() == 3, LOG);
   assert_true(mlp2.get_independent_parameters_number() == 0, LOG);

   assert_true(mlp2.get_input_variable_name(0) == "Input 1", LOG);
   assert_true(mlp2.get_output_variable_name(2) == "Output 3", LOG);
  
   assert_true(mlp2.get_input_variable_units(1) == "[m]", LOG);
   assert_true(mlp2.get_output_variable_units(0) == "[s-1]", LOG);

   assert_true(mlp2.get_input_variable_description(0) == "Description of input variable 1", LOG);
   assert_true(mlp2.get_output_variable_description(1) == "Description of output variable 2", LOG);

   assert_true(mlp2.get_input_variable_mean(0) == 2.0, LOG);
   assert_true(mlp2.get_input_variable_standard_deviation(1) == 0.5, LOG);
   assert_true(mlp2.get_input_variable_minimum(0) == -2.0, LOG);
   assert_true(mlp2.get_input_variable_maximum(1) == -0.5, LOG);

   assert_true(mlp2.get_output_variable_mean(2) == 20.0, LOG);
   assert_true(mlp2.get_output_variable_standard_deviation(0) == 0.05, LOG);
   assert_true(mlp2.get_output_variable_minimum(0) == -20.0, LOG);
   assert_true(mlp2.get_output_variable_maximum(2) == -0.05, LOG);

   // Only independent parameters

   MultilayerPerceptron mlp3(3);

   mlp3.set_independent_parameter_name(0, "Independent parameter 1");
   mlp3.set_independent_parameter_units(1, "[kg]");
   mlp3.set_independent_parameter_description(2, "Description of independent parameter 3");

   mlp3.set_independent_parameter_mean(0, 2.0);
   mlp3.set_independent_parameter_standard_deviation(1, 0.5);
   mlp3.set_independent_parameter_minimum(0, -2.0);
   mlp3.set_independent_parameter_maximum(1, -0.5);

   mlp3.save("../Data/MultilayerPerceptron.dat");
   mlp3.load("../Data/MultilayerPerceptron.dat");
   
   assert_true(mlp3.get_inputs_number() == 0, LOG);
   assert_true(mlp3.get_hidden_layers_number() == 0, LOG);
   assert_true(mlp3.get_outputs_number() == 0, LOG);
   assert_true(mlp3.get_independent_parameters_number() == 3, LOG);

   assert_true(mlp3.get_independent_parameter_name(0) == "Independent parameter 1", LOG);
   assert_true(mlp3.get_independent_parameter_units(1) == "[kg]", LOG);
   assert_true(mlp3.get_independent_parameter_description(2) == "Description of independent parameter 3", LOG);

   assert_true(mlp3.get_independent_parameter_mean(0) == 2.0, LOG);
   assert_true(mlp3.get_independent_parameter_standard_deviation(1) == 0.5, LOG);
   assert_true(mlp3.get_independent_parameter_minimum(0) == -2.0, LOG);
   assert_true(mlp3.get_independent_parameter_maximum(1) == -0.5, LOG);
}


// void test_get_inputs_name_expression(void) method

void TestMultilayerPerceptron::test_get_inputs_name_expression(void)
{
   message += "test_get_inputs_name_expression\n";

   MultilayerPerceptron mlp;
   Vector<std::string> inputs_name_expression =  mlp.get_inputs_name_expression();
   assert_true(inputs_name_expression.get_size() == 0, LOG);
   mlp.set(2,1,1);
   inputs_name_expression =  mlp.get_inputs_name_expression();

   assert_true(inputs_name_expression.get_size() == 2, LOG);
   assert_true(inputs_name_expression[0] == "x1", LOG);
   assert_true(inputs_name_expression[1] == "x2", LOG);
}


// void test_get_scaled_inputs_name_expression(void) method

void TestMultilayerPerceptron::test_get_scaled_inputs_name_expression(void)
{
   message += "test_get_scaled_inputs_name_expression\n";

   MultilayerPerceptron mlp;
   Vector<std::string> scaled_inputs_name_expression =  mlp.get_scaled_inputs_name_expression();
      assert_true(scaled_inputs_name_expression.get_size() == 0, LOG);

   mlp.set(2,1,1);
   scaled_inputs_name_expression =  mlp.get_scaled_inputs_name_expression();
   assert_true(scaled_inputs_name_expression.get_size() == 2, LOG);
   assert_true(scaled_inputs_name_expression[0] == "scaled_x1", LOG);
   assert_true(scaled_inputs_name_expression[1] == "scaled_x2", LOG);
}


// void test_get_hidden_layer_inputs_name_expression(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_inputs_name_expression(void)
{
   message += "test_get_hidden_layer_inputs_name_expression\n";

   MultilayerPerceptron mlp(2,1,1);
   Vector<std::string> hidden_layer_inputs_name_expression =  mlp.get_hidden_layer_inputs_name_expression(0);    assert_true(hidden_layer_inputs_name_expression.get_size() == 2, LOG);
   assert_true(hidden_layer_inputs_name_expression[0] == "scaled_x1", LOG);
   assert_true(hidden_layer_inputs_name_expression[1] == "scaled_x2", LOG);
}


// void test_get_hidden_layer_outputs_name_expression(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_outputs_name_expression(void)
{
   message += "test_get_hidden_layer_outputs_name_expression\n";

   MultilayerPerceptron mlp(1,2,1);

   Vector<std::string> hidden_layer_outputs_name_expression = mlp.get_hidden_layer_outputs_name_expression(0);   
   assert_true(hidden_layer_outputs_name_expression.get_size() == 2, LOG);
   assert_true(hidden_layer_outputs_name_expression[0] == "y11", LOG);
   assert_true(hidden_layer_outputs_name_expression[1] == "y12", LOG);
}


// void test_get_scaled_outputs_name_expression(void) method

void TestMultilayerPerceptron::test_get_scaled_outputs_name_expression(void)
{
   message += "test_get_scaled_outputs_name_expression\n";

   MultilayerPerceptron mlp;
   Vector<std::string> scaled_outputs_name_expression =  mlp.get_scaled_outputs_name_expression();
      assert_true(scaled_outputs_name_expression.get_size() == 0, LOG);
   mlp.set(1,1,2);
   scaled_outputs_name_expression =  mlp.get_scaled_outputs_name_expression();
   assert_true(scaled_outputs_name_expression.get_size() == 2, LOG);
   assert_true(scaled_outputs_name_expression[0] == "scaled_y1", LOG);
   assert_true(scaled_outputs_name_expression[1] == "scaled_y2", LOG);
}


// void test_get_outputs_name_expression(void) method

void TestMultilayerPerceptron::test_get_outputs_name_expression(void)
{
   message += "test_get_outputs_name_expression\n";
   MultilayerPerceptron mlp;
   Vector<std::string> outputs_name_expression =  mlp.get_outputs_name_expression();
      assert_true(outputs_name_expression.get_size() == 0, LOG);

   mlp.set(1,1,2);
   outputs_name_expression =  mlp.get_outputs_name_expression();
   assert_true(outputs_name_expression.get_size() == 2, LOG);
   assert_true(outputs_name_expression[0] == "y1", LOG);
   assert_true(outputs_name_expression[1] == "y2", LOG);
}


// void test_get_hidden_layer_activation_function_expression(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_activation_function_expression(void)
{
   message += "test_get_hidden_layer_activation_function_expression\n";

   MultilayerPerceptron mlp(1, 1, 1);
   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Logistic);
   assert_true(mlp.get_hidden_layer_activation_function_expression(0) == "logistic", LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::HyperbolicTangent);
   assert_true(mlp.get_hidden_layer_activation_function_expression(0) == "tanh", LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Threshold);
   assert_true(mlp.get_hidden_layer_activation_function_expression(0) == "threshold", LOG);
   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::SymmetricThreshold);
   assert_true(mlp.get_hidden_layer_activation_function_expression(0) == "symmetric_threshold", LOG);

   mlp.set_hidden_layer_activation_function(0, MultilayerPerceptron::Linear);
   assert_true(mlp.get_hidden_layer_activation_function_expression(0) == "", LOG);
}


// void test_get_output_layer_activation_function_expression(void) method

void TestMultilayerPerceptron::test_get_output_layer_activation_function_expression(void)
{
   message += "test_get_output_layer_activation_function_expression\n";
   MultilayerPerceptron mlp(1, 1, 1);
      mlp.set_output_layer_activation_function(MultilayerPerceptron::Logistic);
   assert_true(mlp.get_output_layer_activation_function_expression() == "logistic", LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::HyperbolicTangent);
   assert_true(mlp.get_output_layer_activation_function_expression() == "tanh", LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::Threshold);
   assert_true(mlp.get_output_layer_activation_function_expression() == "threshold", LOG);      mlp.set_output_layer_activation_function(MultilayerPerceptron::SymmetricThreshold);
   assert_true(mlp.get_output_layer_activation_function_expression() == "symmetric_threshold", LOG);

   mlp.set_output_layer_activation_function(MultilayerPerceptron::Linear);
   assert_true(mlp.get_output_layer_activation_function_expression() == "", LOG);
}


// void test_get_hidden_layer_expression(void) method

void TestMultilayerPerceptron::test_get_hidden_layer_expression(void)
{
   message += "test_get_hidden_layer_expression\n";

   MultilayerPerceptron mlp(2,3,4);   

   std::string hidden_layer_expression = mlp.get_hidden_layer_expression(0);
   mlp.set(2,1,1);

   Vector<std::string> scaled_inputs_name_expression =  mlp.get_scaled_inputs_name_expression();
   assert_true(scaled_inputs_name_expression.get_size() == 2, LOG);
   assert_true(scaled_inputs_name_expression[0] == "scaled_x1", LOG);
   assert_true(scaled_inputs_name_expression[1] == "scaled_x2", LOG);
}

// void test_get_output_layer_expression(void) method

void TestMultilayerPerceptron::test_get_output_layer_expression(void)
{   
   message += "test_get_output_layer_expression\n";
}


// void test_get_inputs_scaling_expression(void) method

void TestMultilayerPerceptron::test_get_inputs_scaling_expression(void)
{

   message += "test_get_inputs_scaling_expression\n";
}


// void test_get_outputs_unscaling_expression(void) method

void TestMultilayerPerceptron::test_get_outputs_unscaling_expression(void)
{
   message += "test_get_outputs_unscaling_expression\n";
}


// void test_get_expression(void) method  

void TestMultilayerPerceptron::test_get_expression(void)
{
   message += "test_get_expression\n";
   MultilayerPerceptron mlp;
   std::string expression;

//   expression = mlp.get_expression();

   mlp.set_network_architecture(1, 1, 1);
   mlp.initialize_neural_parameters(-1.0);
   expression = mlp.get_expression();

   mlp.set_network_architecture(2, 1, 1);
   mlp.initialize_neural_parameters(-1.0);
   expression = mlp.get_expression();

   mlp.set_network_architecture(1, 2, 1);
   mlp.initialize_neural_parameters(-1.0);
   expression = mlp.get_expression();

   mlp.set_network_architecture(1, 1, 2);
   mlp.initialize_neural_parameters(-1.0);
   expression = mlp.get_expression();

   mlp.set_network_architecture(2, 2, 2);
   mlp.initialize_neural_parameters(-1.0);
   expression = mlp.get_expression();

   Vector<int> hidden_layers_size(2, 2);
   mlp.set_network_architecture(2, hidden_layers_size, 2);
   mlp.initialize_neural_parameters(-1.0);
   expression = mlp.get_expression();
}


// void test_save_expression(void) method

void TestMultilayerPerceptron::test_save_expression(void)
{
   message += "test_save_expression\n";
   MultilayerPerceptron mlp(1, 1, 1);

   mlp.save_expression("../Data/Expression.dat");
}


// void test_get_inputs_scaling_method(void) method

void TestMultilayerPerceptron::test_get_inputs_scaling_method(void)
{
   message += "test_get_inputs_scaling_method\n";

   MultilayerPerceptron mlp;

   mlp.set_inputs_scaling_method(MultilayerPerceptron::None);

   assert_true(mlp.get_inputs_scaling_method() == MultilayerPerceptron::None, LOG);

   mlp.set_inputs_scaling_method(MultilayerPerceptron::MeanStandardDeviation);

   assert_true(mlp.get_inputs_scaling_method() == MultilayerPerceptron::MeanStandardDeviation, LOG);

   mlp.set_inputs_scaling_method(MultilayerPerceptron::MinimumMaximum);

   assert_true(mlp.get_inputs_scaling_method() == MultilayerPerceptron::MinimumMaximum, LOG);
}


// void test_get_inputs_scaling_method_name(void) method

void TestMultilayerPerceptron::test_get_inputs_scaling_method_name(void)
{
   message += "test_get_inputs_scaling_method_name\n";
}


// void test_get_outputs_unscaling_method(void) method

void TestMultilayerPerceptron::test_get_outputs_unscaling_method(void)
{
   message += "test_get_outputs_postrocessing_method\n";

   MultilayerPerceptron mlp;

   mlp.set_outputs_unscaling_method(MultilayerPerceptron::None);

   assert_true(mlp.get_outputs_unscaling_method() == MultilayerPerceptron::None, LOG);

   mlp.set_outputs_unscaling_method(MultilayerPerceptron::MeanStandardDeviation);

   assert_true(mlp.get_outputs_unscaling_method() == MultilayerPerceptron::MeanStandardDeviation, LOG);

   mlp.set_outputs_unscaling_method(MultilayerPerceptron::MinimumMaximum);

   assert_true(mlp.get_outputs_unscaling_method() == MultilayerPerceptron::MinimumMaximum, LOG);
}


// void test_get_outputs_unscaling_method_name(void) method

void TestMultilayerPerceptron::test_get_outputs_unscaling_method_name(void)
{
   message += "test_get_outputs_unscaling_method_name\n";
}


// void test_get_independent_parameters_scaling_method(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_scaling_method(void)
{
   message += "test_get_independent_parameters_scaling_method\n";

   MultilayerPerceptron mlp;

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::None);

   assert_true(mlp.get_independent_parameters_scaling_method() == MultilayerPerceptron::None, LOG);

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MeanStandardDeviation);

   assert_true(mlp.get_independent_parameters_scaling_method() == MultilayerPerceptron::MeanStandardDeviation, LOG);

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   assert_true(mlp.get_independent_parameters_scaling_method() == MultilayerPerceptron::MinimumMaximum, LOG);
}


// void test_get_independent_parameters_scaling_method_name(void) method

void TestMultilayerPerceptron::test_get_independent_parameters_scaling_method_name(void)
{
   message += "test_get_independent_parameters_scaling_method_name\n";
}


// void test_get_numerical_differentiation_method(void) method

void TestMultilayerPerceptron::test_get_numerical_differentiation_method(void)
{
   message += "test_get_numerical_differentiation_method\n";

   MultilayerPerceptron mlp;

   mlp.set_numerical_differentiation_method(MultilayerPerceptron::ForwardDifferences);

   assert_true(mlp.get_numerical_differentiation_method() == MultilayerPerceptron::ForwardDifferences, LOG);

   mlp.set_numerical_differentiation_method(MultilayerPerceptron::CentralDifferences);

   assert_true(mlp.get_numerical_differentiation_method() == MultilayerPerceptron::CentralDifferences, LOG);
}


// void test_get_numerical_differentiation_method_name(void) method

void TestMultilayerPerceptron::test_get_numerical_differentiation_method_name(void)
{
   message += "test_get_numerical_differentiation_method_name\n";
}


// void test_get_Hinton_diagram(void) method

void TestMultilayerPerceptron::test_get_Hinton_diagram(void)
{
   message += "test_get_Hinton_diagram\n";
}


// void test_save_Hinton_diagram(void) method

void TestMultilayerPerceptron::test_save_Hinton_diagram(void)
{
   message += "test_save_Hinton_diagram\n";
}


// void run_test_case(void) method

void TestMultilayerPerceptron::run_test_case(void)
{
   message += "Running multilayer perceptron test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   // Network architecture

   test_get_inputs_number();

   test_get_hidden_layers_number();
   test_get_hidden_layers_size();
   test_get_hidden_layer_size();

   test_get_outputs_number();

   test_get_hidden_layer_inputs_number();
   test_get_output_layer_inputs_number();

   test_get_hidden_layers();
   test_get_hidden_layer();
   test_get_output_layer();

   // Neural parameters

   test_get_neural_parameters_number();

   test_get_hidden_layers_parameters_number();
   test_get_hidden_layer_parameters_number();
   test_get_output_layer_parameters_number();

   test_get_neural_parameters();  
   test_get_hidden_layers_biases();
   test_get_hidden_layer_biases();
   test_get_hidden_layers_synaptic_weights();
     test_get_hidden_layer_synaptic_weights();
   test_get_hidden_layers_parameters();
   test_get_hidden_layer_parameters();      test_get_output_layer_biases();   
   test_get_output_layer_synaptic_weights();   
   test_get_output_layer_parameters();      test_get_hidden_layer_bias_index();    
   test_get_hidden_layer_synaptic_weight_index();

   test_get_output_layer_bias_index();
   test_get_output_layer_synaptic_weight_index();

   // Activation functions

   test_get_hidden_layers_activation_function();
   test_get_hidden_layers_activation_function_name();

   test_get_hidden_layer_activation_function();
   test_get_hidden_layer_activation_function_name();
   
   test_get_output_layer_activation_function();  
   test_get_output_layer_activation_function_name();

   // Variables scaling and unscaling

   test_get_inputs_scaling_method();
   test_get_inputs_scaling_method_name();

   test_get_outputs_unscaling_method();
   test_get_outputs_unscaling_method_name();
   
   // Input variables information

   test_get_input_variables_name();
   test_get_input_variable_name();

   test_get_input_variables_units();
   test_get_input_variable_units();

   test_get_input_variables_description();
   test_get_input_variable_description();

   // Output variables information?
   test_get_output_variables_name();
   test_get_output_variable_name();

   test_get_output_variables_units();
   test_get_output_variable_units();

   test_get_output_variables_description();
   test_get_output_variable_description();

   // Variables information?

   test_get_variables_information();

   // Input variables statistics

   test_get_input_variables_mean();
   test_get_input_variable_mean();

   test_get_input_variables_standard_deviation();
   test_get_input_variable_standard_deviation();

   test_get_input_variables_minimum();
   test_get_input_variable_minimum();

   test_get_input_variables_maximum();
   test_get_input_variable_maximum();

   test_get_input_variables_mean_standard_deviation();
   test_get_input_variables_minimum_maximum();

   test_get_output_variables_mean();
   test_get_output_variable_mean();

   // Output variables statistics?
   test_get_output_variables_standard_deviation();
   test_get_output_variable_standard_deviation();

   test_get_output_variables_minimum();
   test_get_output_variable_minimum();

   test_get_output_variables_maximum();
   test_get_output_variable_maximum();

   test_get_output_variables_mean_standard_deviation();
   test_get_output_variables_minimum_maximum();

   // Variables statistics

   test_get_variables_statistics();

   // Variables bounds

   test_get_output_variables_lower_bound();
   test_get_output_variable_lower_bound();

   test_get_output_variables_upper_bound();
   test_get_output_variable_upper_bound();

   test_get_output_variables_bounds();

   // Independent parameters

   test_get_independent_parameters_number();
   
   test_get_independent_parameters();   
   test_get_independent_parameter();   

   // Independent parameters scaling and unscaling
   test_get_independent_parameters_scaling_method();
   test_get_independent_parameters_scaling_method_name();

   // Independent parameters information

   test_get_independent_parameters_name();
   test_get_independent_parameter_name();

   test_get_independent_parameters_units();
   test_get_independent_parameter_units();

   test_get_independent_parameters_description();
   test_get_independent_parameter_description();

   test_get_independent_parameters_information();

   // Independent parameters statistics

   test_get_independent_parameters_mean();
   test_get_independent_parameter_mean();

   test_get_independent_parameters_standard_deviation();
   test_get_independent_parameter_standard_deviation();

   test_get_independent_parameters_minimum();
   test_get_independent_parameter_minimum();

   test_get_independent_parameters_maximum();
   test_get_independent_parameter_maximum();

   test_get_independent_parameters_mean_standard_deviation();
   test_get_independent_parameters_minimum_maximum();

   test_get_independent_parameters_statistics();

   // Independent parameters bounds

   test_get_independent_parameters_lower_bound();
   test_get_independent_parameter_lower_bound();

   test_get_independent_parameters_upper_bound();
   test_get_independent_parameter_upper_bound();

   test_get_independent_parameters_bounds();

   // Parameters methods?
   test_get_parameters_number();
   test_get_parameters();   

   // Numerical differentiation

   test_get_numerical_differentiation_method();
   test_get_numerical_differentiation_method_name();

   test_get_numerical_epsilon_method();
   test_get_numerical_epsilon_method_name();

   test_get_numerical_epsilon();

   // Display messages

   test_get_display();
   test_get_display_range_out_warning();

   // Set methods

   test_set();
   test_set_default();

   // Network architecture

   test_set_network_architecture();

   test_set_hidden_layers_size();
   test_set_hidden_layer_size();

   // Neural parameters
   test_set_neural_parameters();

   test_set_hidden_layers_biases();
   test_set_hidden_layer_biases();
   test_set_hidden_layers_synaptic_weights();      
   test_set_hidden_layer_synaptic_weights();
   test_set_hidden_layers_parameters();
   test_set_hidden_layer_parameters();
   test_set_output_layer_biases();
   test_set_output_layer_synaptic_weights();
   test_set_output_layer_parameters();

   // Activation functions

   test_set_hidden_layers_activation_function();
   test_set_hidden_layer_activation_function();
   test_set_output_layer_activation_function();

   // Variables scaling and unscaling

   test_set_inputs_scaling_method();
   test_set_outputs_unscaling_method();
   test_set_variables_scaling_method();

   // Input variables information

   test_set_input_variables_name();
   test_set_input_variable_name();

   test_set_input_variables_units();
   test_set_input_variable_units();

   test_set_input_variables_description();
   test_set_input_variable_description();

   // Output variables information?
   test_set_output_variables_name();
   test_set_output_variable_name();

   test_set_output_variables_units();
   test_set_output_variable_units();

   test_set_output_variables_description();
   test_set_output_variable_description();

   // Variables information

   test_set_variables_information();

   // Input variables statistics?
   test_set_input_variables_mean();
   test_set_input_variable_mean();

   test_set_input_variables_standard_deviation();
   test_set_input_variable_standard_deviation();

   test_set_input_variables_minimum();
   test_set_input_variable_minimum();

   test_set_input_variables_maximum();
   test_set_input_variable_maximum();

   test_set_input_variables_mean_standard_deviation();
   test_set_input_variables_minimum_maximum();

   // Output variables statistics?
   test_set_output_variables_mean();
   test_set_output_variable_mean();

   test_set_output_variables_standard_deviation();
   test_set_output_variable_standard_deviation();

   test_set_output_variables_minimum();
   test_set_output_variable_minimum();

   test_set_output_variables_maximum();
   test_set_output_variable_maximum();

   test_set_output_variables_minimum_maximum();
   test_set_output_variables_mean_standard_deviation();

   // Variables statistics
   test_set_variables_statistics();

   // Variables bounds

   test_set_output_variables_lower_bound();
   test_set_output_variable_lower_bound();

   test_set_output_variables_upper_bound();
   test_set_output_variable_upper_bound();

   test_set_output_variables_bounds();

   // Independent parameters

   test_set_independent_parameters_number();
   test_set_independent_parameters();

   test_set_independent_parameter();

   // Independent parameters scaling and unscaling

   test_set_independent_parameters_scaling_method();
   // Independent parameters information

   test_set_independent_parameters_name();
   test_set_independent_parameter_name();

   test_set_independent_parameters_units();
   test_set_independent_parameter_units();

   test_set_independent_parameters_description();
   test_set_independent_parameter_description();

   // Independent parameters statistics

   test_set_independent_parameters_mean();
   test_set_independent_parameter_mean();

   test_set_independent_parameters_standard_deviation();
   test_set_independent_parameter_standard_deviation();
   
   test_set_independent_parameters_minimum();
   test_set_independent_parameter_minimum();

   test_set_independent_parameters_maximum();
   test_set_independent_parameter_maximum();

   test_set_independent_parameters_mean_standard_deviation();
   test_set_independent_parameters_minimum_maximum();

   test_set_independent_parameters_statistics();

   // Independent parameters bounds?
   test_set_independent_parameters_lower_bound();
   test_set_independent_parameter_lower_bound();

   test_set_independent_parameters_upper_bound();
   test_set_independent_parameter_upper_bound();

   test_set_independent_parameters_bounds();

   // Parameters methods

   test_set_parameters();

   // Variables and independent parameters scaling and unscaling method

   test_set_scaling_method();

   // Numerical differentiation?
   test_set_numerical_differentiation_method();

   test_set_numerical_epsilon_method();

   test_set_numerical_epsilon();

   // Display messages

   test_set_display_range_out_warning();
   test_set_display();

   // Neural parameters initialization methods

   test_initialize_neural_parameters();
   test_initialize_biases(); 
   test_initialize_synaptic_weights();
   test_initialize_neural_parameters_uniform();
   test_initialize_neural_parameters_normal();

   // Independent parameters initialization methods

   test_initialize_independent_parameters();
   test_initialize_independent_parameters_uniform();
   test_initialize_independent_parameters_normal();

   // Parameters initialization methods

   test_initialize_parameters();
   test_initialize_parameters_uniform();
   test_initialize_parameters_normal();

   // Parameters norm 

   test_calculate_neural_parameters_norm();      
   test_calculate_independent_parameters_norm();

   test_calculate_parameters_norm();

   // Output methods

   test_calculate_output();

   test_calculate_output_matrix();

   test_calculate_output_boundary_conditions();
   test_calculate_output_matrix_boundary_conditions();
   test_calculate_forward_propagation();
   test_calculate_forward_propagation_derivative();
   test_calculate_forward_propagation_second_derivative();
   test_check_input_range();

   test_calculate_scaled_input();

   test_calculate_hidden_layer_combination();
   test_calculate_hidden_layer_activation();
   test_calculate_hidden_layer_activation_derivative();
   test_calculate_hidden_layer_activation_second_derivative();
   test_calculate_hidden_layer_output();
   test_calculate_output_layer_combination();
   test_calculate_output_layer_activation();
   test_calculate_output_layer_activation_derivative();
   test_calculate_output_layer_activation_second_derivative();

   test_calculate_output_layer_output();

   test_calculate_unscaled_output();

   test_calculate_bounded_output();

   // Jacobian methods

   test_calculate_Jacobian();
   test_calculate_Jacobian_vector();

   test_calculate_Jacobian_boundary_conditions();
   test_calculate_Jacobian_vector_boundary_conditions();

   test_calculate_hidden_layer_Jacobian();
   test_calculate_output_layer_Jacobian();
   test_calculate_Jacobian_numerical_differentiation();
   test_calculate_Jacobian_forward_differences();
   test_calculate_Jacobian_central_differences();

   // Sensitivity methods

   test_calculate_sensitivity();
   test_calculate_sensitivity_vector();

   test_calculate_sensitivity_numerical_differentiation();

   test_calculate_sensitivity_forward_differences();
   test_calculate_sensitivity_central_differences();

   // Independent parameters methods   

   test_scale_independent_parameters();
   test_unscale_independent_parameters();
   test_bound_independent_parameters();
   test_bound_independent_parameter();

   // Expression methods

   test_get_expression();
   test_get_inputs_name_expression();
   test_get_scaled_inputs_name_expression();

   test_get_hidden_layer_inputs_name_expression();
   test_get_hidden_layer_outputs_name_expression();

   test_get_hidden_layer_inputs_name_expression();

   test_get_scaled_outputs_name_expression();
   test_get_outputs_name_expression();

   test_get_hidden_layer_activation_function_expression();
   test_get_output_layer_activation_function_expression();

   test_get_hidden_layer_expression();
   test_get_output_layer_expression();
   test_get_inputs_scaling_expression();
   test_get_outputs_unscaling_expression();
   test_save_expression();

   // Hinton diagram methods

   test_get_Hinton_diagram();
   test_save_Hinton_diagram();

   // Utility methods

   test_to_XML();
   test_print();
   test_save();
   test_load();

   message += "End of multilayer perceptron test case\n";
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
