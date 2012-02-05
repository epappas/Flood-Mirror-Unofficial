/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A T E N A R Y   P R O B L E M   A P P L I C A T I O N                                                    */
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
#include "CatenaryProblem.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"


using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Catenary Problem Application." << std::endl;	

   srand( (unsigned)time( NULL ) );

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1,3,1);

   mlp.set_input_variable_name(0, "x");
   mlp.set_output_variable_name(0, "y");

   // Catenary problem object

   CatenaryProblem cp(&mlp);
   cp.set_potential_energy_weight(1.0);
   cp.set_length_error_weight(100.0);

   cp.save_results("../Data/InitialGuessCatenaryProblem.dat");

   // Random search object

   RandomSearch rs(&cp);
   rs.train();

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&cp);	

   qnm.set_maximum_epochs_number(1000); 
   qnm.set_display_period(10); 

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   // Train neural network

   cp.set_calculate_evaluation_count(0);

   qnm.train(); 

   int calculate_evaluation_count = cp.get_calculate_evaluation_count();

   std::cout << "Number of evaluations: " 
             << calculate_evaluation_count <<  std::endl;	

   // Save results 

   mlp.save("../Data/MultilayerPerceptron.dat");
   mlp.save_expression("../Data/ExpressionCatenaryProblem.dat");

   cp.save_results("../Data/ResultsCatenaryProblem.dat");

   qnm.save_training_history("../Data/TrainingHistoryCatenaryProblem.dat");

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
