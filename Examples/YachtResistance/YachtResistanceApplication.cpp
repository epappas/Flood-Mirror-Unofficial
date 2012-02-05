/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   Y A C H T   R E S I S T A N C E   A P P L I C A T I O N                                                    */
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
#include "../../Flood/Utilities/FunctionRegressionUtilities.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Yacht Resistance Application." << std::endl;	

//   srand((unsigned)time(NULL));

   // Input-target data set object
  
   InputTargetDataSet itds("../Data/DelftInputTargetDataSet.dat");

   itds.split_random_indices();

   Vector< Vector<std::string> > variables_information = itds.get_variables_information();
   Vector< Vector<double> > variables_statistics = itds.scale_variables_mean_standard_deviation();  
  
   // Multilayer perceptron object

   int inputs_number = itds.get_input_variables_number();
   int hidden_neurons_number = 9;
   int outputs_number = itds.get_target_variables_number();

   MultilayerPerceptron mlp(inputs_number, hidden_neurons_number, outputs_number);
   mlp.set_variables_information(variables_information);
   mlp.set_variables_statistics(variables_statistics);

   mlp.set_variables_scaling_method(MultilayerPerceptron::None);

   // Normalized squared error object

   NormalizedSquaredError nse(&mlp, &itds);

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&nse);

   qnm.set_minimum_evaluation_improvement(1.0e-9);
   qnm.set_maximum_epochs_number(1000);

   qnm.set_reserve_evaluation_history(true);

   qnm.set_display_period(100);

   qnm.train();

   // Function regression utilities object
                  
   FunctionRegressionUtilities fru(&mlp, &itds);
   fru.save_linear_regression_analysis("../Data/LinearRegressionAnalysis.dat");

   // Save multilayer perceptron results

   mlp.set_variables_scaling_method(MultilayerPerceptron::MeanStandardDeviation);

   mlp.save("../Data/MultilayerPerceptron.dat");
   mlp.save_expression("../Data/Expression.dat");

   // Save quasi-Newton method results

   qnm.save("../Data/QuasiNewtonMethod.dat");
   qnm.save_training_history("../Data/TrainingHistory.dat");


   return(0);
}  
