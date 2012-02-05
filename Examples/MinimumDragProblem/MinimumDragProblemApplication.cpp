/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M I N I M U M   D R A G   P R O B L E M   A P P L I C A T I O N                                            */
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
#include "MinimumDragProblem.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Minimum Drag Problem." << std::endl;	

   srand((unsigned)time(NULL));

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1,3,1);   

   mlp.set_input_variable_name(0, "x");
   mlp.set_output_variable_name(0, "y");

   // Minimum drag problem object

   MinimumDragProblem mdp(&mlp);  

   mdp.save_results("../Data/InitialGuessMinimumDragProblem.dat");

   // Random search object

   RandomSearch rs(&mdp);
   rs.set_maximum_epochs_number(100);
   rs.set_display_period(100);

   rs.train();

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&mdp);

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.set_maximum_epochs_number(1000);
   qnm.set_display_period(100);

   qnm.train();
   
   // Save results
   
   mlp.save("../Data/MultilayerPerceptronMinimumDragProblem.dat");
   mlp.save_expression("../Data/ExpressionMinimumDragProblem.dat");   
   mdp.save_results("../Data/Results.dat");

   qnm.save_training_history("../Data/TrainingHistoryMinimumDragProblem.dat");

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
