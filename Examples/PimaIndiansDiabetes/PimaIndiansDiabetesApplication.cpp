/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   P I M A   I N D I A N S   D I A B E T E S   A P P L I C A T I O N                                          */
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
#include <time.h>

// Flood includes

#include "../../Flood/Utilities/InputTargetDataSet.h"
#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/ObjectiveFunctional/NormalizedSquaredError.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"
#include "../../Flood/Utilities/PatternRecognitionUtilities.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Pima Indians Diabetes Application." << std::endl;	

   srand((unsigned)time(NULL));

   // Input-target data set object 

   InputTargetDataSet itds(768,8,1);
   itds.load_data("../Data/Data.dat");

   itds.split_random_indices(0.75, 0.0, 0.25);

   itds.save("../Data/InputTargetDataSet.dat");

   Vector< Vector<std::string> > information = itds.get_variables_information();
   Vector< Vector<double> > statistics = itds.scale_input_variables_mean_standard_deviation();

   // Multilayer perceptron object 

   MultilayerPerceptron mlp(8, 6, 1);
   mlp.set_output_layer_activation_function(MultilayerPerceptron::Logistic);

   mlp.set_variables_information(information); 
   mlp.set_variables_statistics(statistics); 

   // Normalized squared error object

   NormalizedSquaredError nse(&mlp, &itds);

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&nse);

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_validation_error_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.set_gradient_norm_goal(0.001);

   qnm.train();

   // Pattern recognition utilities object

   PatternRecognitionUtilities pru(&mlp, &itds);

   pru.save_confusion("../Data/Confusion.dat");   
   pru.save_binary_classification_test("../Data/BinaryClassificationTest.dat");   

   // Save results

   mlp.set_inputs_scaling_method(MultilayerPerceptron::MeanStandardDeviation);
   mlp.save("../Data/MultilayerPerceptron.dat");

   qnm.save_training_history("../Data/TrainingHistory.dat");

   mlp.save_expression("../Data/Expression.dat");

   return(0);
}  


// Flood: An Open Source Neural Networks C++ Library.
// Copyright (C) 2005-2010 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
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
