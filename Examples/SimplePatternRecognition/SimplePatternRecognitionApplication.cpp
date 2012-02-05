/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   S I M P L E   C L A S S I F I C A T I O N   A P P L I C A T I O N                                          */
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
#include <sstream>
#include <time.h>
#include <stdexcept>

// Flood includes

#include "../../Flood/Utilities/InputTargetDataSet.h"
#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/ObjectiveFunctional/NormalizedSquaredError.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"
#include "../../Flood/Utilities/PatternRecognitionUtilities.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Simple Pattern Recognition Application." << std::endl;

//   srand( (unsigned)time( NULL ) );

   // Input-target data set object

   InputTargetDataSet itds(100, 2, 1);
   itds.load_data("../Data/SimplePatternRecognitionData.dat");

   itds.split_random_indices(0.75, 0.0, 0.25);

   itds.set_variable_name(0, "x1");   
   itds.set_variable_name(1, "x2");   
   itds.set_variable_name(2, "y");   

   Vector< Vector<std::string> > variables_information = itds.get_variables_information();
   
   Vector< Vector<double> > variables_statistics = itds.scale_input_variables_mean_standard_deviation();

   // Multilayer perceptron object

   MultilayerPerceptron mlp(2, 2, 1);

   mlp.set_variables_information(variables_information);
   mlp.set_variables_statistics(variables_statistics);

   // Normalized squared error object
 
   NormalizedSquaredError nse(&mlp, &itds);

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&nse);

   qnm.set_reserve_evaluation_history(true);

   qnm.train();

   // Pattern recognition utilities object

   PatternRecognitionUtilities pru(&mlp, &itds);

   pru.print_binary_classification_test();
   pru.save_binary_classification_test("../Data/BinaryClassificationTest.dat");

   // Save results

   itds.save("../Data/InputTargetDataSet.dat");
   itds.load("../Data/InputTargetDataSet.dat");
   
   itds.save_data_statistics("../Data/DataStatistics.dat");

   mlp.set_inputs_scaling_method(MultilayerPerceptron::MeanStandardDeviation);

   mlp.save("../Data/MultilayerPerceptron.dat");
   mlp.load("../Data/MultilayerPerceptron.dat");

   mlp.save_expression("../Data/MultilayerPerceptronExpression.dat");

   nse.save("../Data/NormalizedSquaredError.dat");
   nse.load("../Data/NormalizedSquaredError.dat");

   qnm.save("../Data/QuasiNewtonMethod.dat");
   qnm.load("../Data/QuasiNewtonMethod.dat");

   qnm.save_training_history("../Data/TrainingHistory.dat");


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
