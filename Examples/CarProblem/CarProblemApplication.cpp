/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A R   P R O B L E M    A P P L I C A T I O N                                                             */
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
#include "CarProblem.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Car Problem Application." << std::endl;

   srand((unsigned)time(NULL));

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1,3,2);
   mlp.set_independent_parameters_number(1); 

   // Car problem object

   CarProblem cp(&mlp);
   
   cp.set_initial_position(0.0);
   cp.set_initial_velocity(0.0);

   cp.set_final_position_goal(1.0);
   cp.set_final_velocity_goal(0.0);

   cp.set_final_position_error_weight(1.0);
   cp.set_final_velocity_error_weight(1.0);
   cp.set_final_time_weight(1.0e-2);

   mlp.initialize_parameters_uniform(-0.1, 0.1);

   // Random search object

   RandomSearch rs(&cp);
   rs.set_maximum_epochs_number(100);
   rs.train();

   cp.save_results("../Data/InitialGuessCarProblem.dat");

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&cp);
   qnm.set_maximum_epochs_number(100);
   qnm.set_display_period(1);

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.train();

   // Save results

   mlp.save("../Data/MultilayerPerceptronCarProblem.dat");

   mlp.save_expression("../Data/ExpressionCarProblem.dat");

   cp.save_results("../Data/ResultsCarProblem.dat");

   qnm.save_training_history("../Data/TrainingHistoryCarProblem.dat");

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
