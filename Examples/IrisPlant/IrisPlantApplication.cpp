/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   I R I S   P L A N T   A P P L I C A T I O N                                                                */
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
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
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
   std::cout << "Flood Neural Network. Iris Plant Application." << std::endl;	

   srand((unsigned)time(NULL));

   // Input-target data set objects
  
   InputTargetDataSet itds(150, 4, 3);

   itds.load_data("../Data/Iris.dat");

   itds.split_random_indices(75, 0, 25);
   
   Vector< Vector<std::string> > variables_information = itds.get_variables_information();

   Vector< Vector<double> > variables_statistics = itds.scale_input_variables_mean_standard_deviation();  
      
   // Multilayer perceptron object

   int inputs_number = itds.get_input_variables_number();
   int outputs_number = itds.get_target_variables_number();

   int hidden_neurons_number = (int)pow(inputs_number*inputs_number+outputs_number*outputs_number, 0.5);

   MultilayerPerceptron mlp(inputs_number, hidden_neurons_number, outputs_number);

   mlp.set_variables_information(variables_information);
   mlp.set_variables_statistics(variables_statistics);

   // Normalized squared error object

   NormalizedSquaredError nse(&mlp, &itds);

  // Quasi-Newton method object

   QuasiNewtonMethod qnm(&nse);

   qnm.set_maximum_epochs_number(1000);
   qnm.set_display_period(100);
   qnm.set_minimum_evaluation_improvement(1.0e-9);
   qnm.set_gradient_norm_goal(0.0);
   
   qnm.train();

   // Pattern recognition utilities object
                  
   PatternRecognitionUtilities pru(&mlp, &itds);

   pru.save_confusion("../Data/Confusion.dat");

   // Save results

   mlp.set_inputs_scaling_method(MultilayerPerceptron::MeanStandardDeviation);

   mlp.save("../Data/MultilayerPerceptron.dat");
   mlp.save_expression("../Data/Expression.dat");   

   return(0);
}  
