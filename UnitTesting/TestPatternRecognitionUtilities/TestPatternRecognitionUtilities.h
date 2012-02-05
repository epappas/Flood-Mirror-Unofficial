/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   P A T T E R N   R E C O G N I T I O N   U T I L I T I E S   C L A S S   H E A D E R              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTPATTERNRECOGNITIONUTILITIES_H__
#define __TESTPATTERNRECOGNITIONUTILITIES_H__

// Flood includes

#include "../../Flood/Utilities/UnitTesting.h"

using namespace Flood;

class TestPatternRecognitionUtilities : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // CONSTRUCTOR

   explicit TestPatternRecognitionUtilities(void);

   // DESTRUCTOR

   virtual ~TestPatternRecognitionUtilities(void);

   // METHODS

   // Constructor methods

   void test_constructor(void);

   // Destructor methods
   
   void test_destructor(void);

   // Get methods

   void test_get_multilayer_perceptron_pointer(void);
   void test_get_input_target_data_set_pointer(void);
   
   void test_get_display(void);

   // Set methods

   void test_set_multilayer_perceptron_pointer(void);
   void test_set_input_target_data_set_pointer(void);

   void test_set_display(void);

   // Arfificial data generation methods

   void test_generate_artificial_data(void);

   // Output data methods

   void test_calculate_binary_output_data(void);

   void test_calculate_binary_training_output_data(void);
   void test_calculate_binary_validation_output_data(void);
   void test_calculate_binary_testing_output_data(void);

   // Target data methods

   void test_get_binary_target_data(void);

   void test_get_binary_training_target_data(void);
   void test_get_binary_validation_target_data(void);
   void test_get_binary_testing_target_data(void);

   // Class distribution methods

   void test_calculate_class_distribution(void);

   void test_get_class_distribution_XML(void);
   void test_print_class_distribution(void);
   void test_save_class_distribution(void);

   // Binary classification test methods

   void test_calculate_binary_classification_test(void);
   void test_get_binary_classification_test_XML(void);
   void test_print_binary_classification_test(void);
   void test_save_binary_classification_test(void);

   // Confusion matrix methods
   
   void test_calculate_confusion(void);
   void test_get_confusion_XML(void);
   void test_print_confusion(void);
   void test_save_confusion(void);

   // Testing results methods

   void test_get_testing_results(void);
   void test_print_testing_results(void);
   void test_save_testing_results(void);

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
