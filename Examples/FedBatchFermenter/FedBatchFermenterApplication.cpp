/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   F E D   B A T C H   F E R M E N T E R   A P P L I C A T I O N                                              */
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

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "FedBatchFermenter.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Fed Batch Fermenter Application." << std::endl;

//   srand((unsigned)time(NULL));

   // Problem parameters

   double maximum_feed_rate = 12.0;
   double final_time = 54.0;

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1,2,1);

   mlp.set_input_variable_name(0, "time");
   mlp.set_output_variable_name(0, "feed_rate");

   mlp.set_input_variable_minimum(0, 0.0);
   mlp.set_input_variable_maximum(0, final_time);

   mlp.set_output_variable_minimum(0, 0.0);
   mlp.set_output_variable_maximum(0, maximum_feed_rate);

   mlp.set_output_variable_lower_bound(0, 0.0);
   mlp.set_output_variable_upper_bound(0, maximum_feed_rate);

   mlp.set_variables_scaling_method(MultilayerPerceptron::MinimumMaximum);

   mlp.initialize_parameters_uniform(-0.1, 0.1);

   // Fed batch fermenter object

   FedBatchFermenter fbf(&mlp);

   fbf.set_volume_error_weight(1.0e-3);
   fbf.set_yield_weight(1.0e-10);

   // Random search object

   RandomSearch rs(&fbf);
   rs.set_maximum_epochs_number(100);
   rs.set_display_period(10);
   rs.train();

   fbf.save_results("../Data/InitialGuessFedBatchFermenter.dat");

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&fbf);

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.set_maximum_epochs_number(1000);
   qnm.set_display_period(10);
  
   qnm.train();

   // Save results

   mlp.save("../Data/MultilayerPerceptronFedBatchFermenter.dat");
   mlp.save_expression("../Data/ExpressionFedBatchFermenter.dat");

   fbf.save_results("../Data/ResultsFedBatchFermenter.dat");

   qnm.save_training_history("../Data/TrainingHistoryFedBatchFermenter.dat");

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
