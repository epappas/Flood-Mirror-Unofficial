/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   B R A C H I S T O C H R O N E   P R O B L E M   A P P L I C A T I O N                                      */
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
#include "BrachistochroneProblem.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Brachistochrone Problem Application." << std::endl;	

   double xa = 0.0;
   double ya = 1.0;
   double xb = 1.0;
   double yb = 0.0;

   srand((unsigned)time(NULL));

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1,3,1);

   mlp.set_input_variable_name(0, "x");
   mlp.set_output_variable_name(0, "y");

   mlp.set_input_variable_minimum(0, xa);
   mlp.set_input_variable_maximum(0, xb);

   // Brachistochrone problem object

   BrachistochroneProblem bp(&mlp);
   bp.set_problem(xa, ya, xb, yb);

   // Save initial guess to file

   bp.save_results("../Data/InitialGuessBrachistochroneProblem.dat");

   // Random search object

   RandomSearch rs(&bp);
   rs.train();

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&bp);	
   qnm.set_maximum_epochs_number(1000); 
   qnm.set_display_period(100); 

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.train();

   // Save results

   mlp.save("../Data/MultilayerPerceptron.dat");
   mlp.save_expression("../Data/ExpressionBrachistochroneProblem.dat");

   bp.save_results("../Data/ResultsBrachistochroneProblem.dat");

   qnm.save_training_history("../Data/TrainingHistoryBrachistochroneProblem.dat"); 

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
