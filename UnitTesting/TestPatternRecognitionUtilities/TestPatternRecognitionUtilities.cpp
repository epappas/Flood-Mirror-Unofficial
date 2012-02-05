/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   P A T T E R N   R E C O G N I T I O N   U T I L I T I E S   C L A S S                            */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "TestPatternRecognitionUtilities.h"

// Flood includes

#include "../../Flood/Utilities/PatternRecognitionUtilities.h"
#include "../../Flood/Utilities/InputTargetDataSet.h"
#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"

using namespace Flood;

// GENERAL CONSTRUCTOR

TestPatternRecognitionUtilities::TestPatternRecognitionUtilities(void) : UnitTesting() 
{   
}


// DESTRUCTOR

TestPatternRecognitionUtilities::~TestPatternRecognitionUtilities(void)
{
}


// void test_constructor(void) method

void TestPatternRecognitionUtilities::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   PatternRecognitionUtilities cu1;

   assert_true(cu1.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(cu1.get_input_target_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron constructor

   MultilayerPerceptron mlp2;
   PatternRecognitionUtilities cu2(&mlp2);

//   assert_true(cu1.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(cu1.get_input_target_data_set_pointer() == NULL, LOG);

   // Input-target data set constructor

   InputTargetDataSet itds3;
   PatternRecognitionUtilities cu3(&itds3);

   assert_true(cu3.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(cu3.get_input_target_data_set_pointer() != NULL, LOG);

   // Multilayer perceptron and input-target data set constructor

   MultilayerPerceptron mlp4;
   InputTargetDataSet itds4;

   PatternRecognitionUtilities cu4(&mlp4, &itds4);

//   assert_true(cu3.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(cu3.get_input_target_data_set_pointer() != NULL, LOG);
}


// void test_destructor(void) method

void TestPatternRecognitionUtilities::test_destructor(void)
{
   message += "test_destructor\n";

   PatternRecognitionUtilities* cup = new PatternRecognitionUtilities;
   
   cup->PatternRecognitionUtilities::~PatternRecognitionUtilities();

//   cup.~PatternRecognitionUtilities();
}


// void test_get_multilayer_perceptron_pointer(void) method

void TestPatternRecognitionUtilities::test_get_multilayer_perceptron_pointer(void)
{
   message += "test_get_multilayer_perceptron_pointer\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds);

   MultilayerPerceptron* mlpp = cu.get_multilayer_perceptron_pointer();

   assert_true(mlpp != 0, LOG);
}


// void test_get_input_target_data_set_pointer(void) method

void TestPatternRecognitionUtilities::test_get_input_target_data_set_pointer(void)
{
   message += "test_get_input_target_data_set_pointer\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds);

   InputTargetDataSet* itdsp = cu.get_input_target_data_set_pointer();

   assert_true(itdsp != 0, LOG);
}


// void test_get_display(void) method

void TestPatternRecognitionUtilities::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_multilayer_perceptron_pointer(void) method

void TestPatternRecognitionUtilities::test_set_multilayer_perceptron_pointer(void)
{
   message += "test_set_multilayer_perceptron_pointer\n";

   MultilayerPerceptron mlp;

   PatternRecognitionUtilities cu;

   cu.set_multilayer_perceptron_pointer(&mlp);

   MultilayerPerceptron* mlpp = cu.get_multilayer_perceptron_pointer();

   assert_true(mlpp != 0, LOG);
}


// void test_set_input_target_data_set_pointer(void) method

void TestPatternRecognitionUtilities::test_set_input_target_data_set_pointer(void)
{
   message += "test_set_input_target_data_set_pointer\n";

   InputTargetDataSet itds;

   PatternRecognitionUtilities cu;

   cu.set_input_target_data_set_pointer(&itds);

   InputTargetDataSet* itdsp = cu.get_input_target_data_set_pointer();

   assert_true(itdsp != 0, LOG);
}


// void test_set_display(void) method

void TestPatternRecognitionUtilities::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_generate_artificial_data(void) method

void TestPatternRecognitionUtilities::test_generate_artificial_data(void)
{
   message += "test_generate_artificial_data\n";
   
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&itds);

   Vector< Vector<double> > mean;
   Vector< Vector<double> > standard_deviation;
   Vector<double> prior_probability;

   // Test 
   // 1 input variable (1 attribute)
   // 1 target variable (2 classes)
   
   // Mean of class 1: -1
   // Standard deviation of class 1: 1
   // Prior probability of class 1: 1

   // Mean of class 2:  1
   // Standard deviation of class 2: 1
   // Prior probability of class 2: 0

   itds.set(1,1,1);

   mean.set(2);
   mean[0].set(1, -1.0);
   mean[1].set(1,  1.0);

   standard_deviation.set(2);
   standard_deviation[0].set(1, 1.0);
   standard_deviation[1].set(1, 1.0);

   prior_probability.set(2);
   prior_probability[0] = 1.0;
   prior_probability[1] = 0.0;

   cu.generate_artificial_data(mean, standard_deviation, prior_probability);

   assert_true(itds.get_target_instance(0) == 1.0, LOG);

   // Test 
   // 2 input variables (2 attributes)
   // 1 target variable (2 classes)
   
   // Mean of class 1: -0.5 -0.5
   // Standard deviation of class 1: 0.5 0.5
   // Prior probability of class 1: 0.5

   // Mean of class 2:  0.5  0.5
   // Standard deviation of class 2: 0.5 0.5
   // Prior probability of class 2: 0.5
   
   itds.set(100, 2, 1);

   mean.set(2);
   mean[0].set(2, -0.5);
   mean[1].set(2,  0.5);

   standard_deviation.set(2);
   standard_deviation[0].set(2, 0.5);
   standard_deviation[1].set(2, 0.5);

   prior_probability.set(2);
   prior_probability[0] = 0.5;
   prior_probability[1] = 0.5;

   cu.generate_artificial_data(mean, standard_deviation, prior_probability);

   itds.save_data("../Data/SimplePatternRecognitionData.dat");
}


// void test_calculate_binary_output_data(void) method

void TestPatternRecognitionUtilities::test_calculate_binary_output_data(void)
{
   message += "test_calculate_binary_output_data\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);

   PatternRecognitionUtilities cu(&mlp, &itds);

   Matrix<bool> binary_output_data = cu.calculate_binary_output_data();

   assert_true(binary_output_data.get_rows_number() == 1, LOG);
   assert_true(binary_output_data.get_columns_number() == 1, LOG);
   assert_true(binary_output_data == false, LOG);
}


// void test_calculate_binary_training_output_data(void) method

void TestPatternRecognitionUtilities::test_calculate_binary_training_output_data(void)
{
   message += "test_calculate_binary_training_output_data\n";

   MultilayerPerceptron mlp(1,1,1);
   mlp.initialize_neural_parameters(0.0);

   InputTargetDataSet itds(1,1,1);
   itds.initialize_data(0.0);

   PatternRecognitionUtilities cu(&mlp, &itds);

   Matrix<bool> binary_training_output_data = cu.calculate_binary_training_output_data();

   assert_true(binary_training_output_data.get_rows_number() == 1, LOG);
   assert_true(binary_training_output_data.get_columns_number() == 1, LOG);
   assert_true(binary_training_output_data == false, LOG);
}


// void test_calculate_binary_validation_output_data(void) method

void TestPatternRecognitionUtilities::test_calculate_binary_validation_output_data(void)
{
   message += "test_calculate_binary_validation_output_data\n";
}


// void test_calculate_binary_testing_output_data(void) method

void TestPatternRecognitionUtilities::test_calculate_binary_testing_output_data(void)
{
   message += "test_calculate_binary_testing_output_data\n";
}


// void test_get_binary_target_data(void) method

void TestPatternRecognitionUtilities::test_get_binary_target_data(void)
{
   message += "test_get_binary_target_data\n";
}


// void test_get_binary_training_target_data(void) method

void TestPatternRecognitionUtilities::test_get_binary_training_target_data(void)
{
   message += "test_get_binary_training_target_data\n";
}


// void test_get_binary_validation_target_data(void) method

void TestPatternRecognitionUtilities::test_get_binary_validation_target_data(void)
{
   message += "test_get_binary_validation_target_data\n";
}


// void test_get_binary_testing_target_data(void) method

void TestPatternRecognitionUtilities::test_get_binary_testing_target_data(void)
{
   message += "test_get_binary_testing_target_data\n";
}


// void test_calculate_confusion(void) method

void TestPatternRecognitionUtilities::test_calculate_confusion(void)
{
   message += "test_calculate_confusion\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds); 

//   Matrix<int> confusion = cu.calculate_confusion();

}


// void test_calculate_class_distribution(void) method

void TestPatternRecognitionUtilities::test_calculate_class_distribution(void)
{
   message += "test_calculate_class_distribution\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds); 
   
   Vector<int> class_distribution = cu.calculate_class_distribution();
}


// void test_get_class_distribution_XML(void) method

void TestPatternRecognitionUtilities::test_get_class_distribution_XML(void)
{
   message += "test_get_class_distribution_XML\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds); 
   
   std::string class_distribution = cu.get_class_distribution_XML(true);
}


// void test_print_class_distribution(void) method

void TestPatternRecognitionUtilities::test_print_class_distribution(void)
{
   message += "test_print_class_distribution\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds); 
   
   //cu.print_class_distribution();
}


// void test_save_class_distribution(void) method

void TestPatternRecognitionUtilities::test_save_class_distribution(void)
{
   message += "test_save_class_distribution\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds); 
   
   cu.save_class_distribution("../Data/ClassDistribution.dat");
}


// void test_calculate_binary_classification_test(void) method

void TestPatternRecognitionUtilities::test_calculate_binary_classification_test(void)
{
   message += "test_calculate_binary_classification_test\n";
}


// void test_get_confusion_XML(void) method

void TestPatternRecognitionUtilities::test_get_confusion_XML(void)
{
   message += "test_get_confusion_XML\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds); 
   
   std::string confussion = cu.get_confusion_XML(true);
}



// void test_save_confusion(void) method

void TestPatternRecognitionUtilities::test_save_confusion(void)
{
   message += "test_save_confusion\n";

   MultilayerPerceptron mlp;
   InputTargetDataSet itds;

   PatternRecognitionUtilities cu(&mlp, &itds); 
   
   cu.save_confusion("../Data/Confusion.dat");
}


// void test_get_testing_results(void) method

void TestPatternRecognitionUtilities::test_get_testing_results(void)
{
   message += "test_get_testing_results\n";
   
}


// void test_print_testing_results(void) method

void TestPatternRecognitionUtilities::test_print_testing_results(void)
{
   message += "test_print_testing_results\n";
   
}


// void test_save_testing_results(void) method

void TestPatternRecognitionUtilities::test_save_testing_results(void)
{
   message += "test_save_testing_results\n";
}


// void run_test_case(void) method

void TestPatternRecognitionUtilities::run_test_case(void)
{
   message += "Running pattern recognition utilities test case...\n";

   // Constructor methods

   test_constructor();

   // Destructor methods
   
   test_destructor();

   // Get methods

   test_get_multilayer_perceptron_pointer();
   test_get_input_target_data_set_pointer();
   
   test_get_display();

   // Set methods

   test_set_multilayer_perceptron_pointer();
   test_set_input_target_data_set_pointer();

   test_set_display();

   // Arfificial data generation methods

   test_generate_artificial_data();

   // Output data methods
   
   test_calculate_binary_output_data();

   test_calculate_binary_training_output_data();
   test_calculate_binary_validation_output_data();
   test_calculate_binary_testing_output_data();

   // Target data methods

   test_get_binary_target_data();

   test_get_binary_training_target_data();
   test_get_binary_validation_target_data();
   test_get_binary_testing_target_data();

   // Class distribution methods

   test_calculate_class_distribution();

   test_get_class_distribution_XML();
   test_print_class_distribution();
   test_save_class_distribution();

   // Binary classification test methods

   test_calculate_binary_classification_test();

   // Confusion matrix methods
   
   test_calculate_confusion();
   test_get_confusion_XML();
   test_save_confusion();

   // Testing results methods

   test_get_testing_results();
   test_print_testing_results();
   test_save_testing_results();

   message += "End of pattern recognition utilities test case\n";
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
