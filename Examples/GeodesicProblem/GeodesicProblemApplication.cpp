/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   G E O D E S I C   P R O B L E M   A P P L I C A T I O N                                                    */
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
#include "GeodesicProblem.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Geodesic Problem Application." << std::endl;	

   srand((unsigned)time(NULL));

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1, 3, 1);

   mlp.set_input_variable_name(0, "x");
   mlp.set_output_variable_name(0, "y");

   // Geodesic problem object

   GeodesicProblem gp(&mlp);

   // Save initial guess

   gp.save_results("../Data/InitialGuessGeodesicProblem.dat");

   double evaluation = gp.calculate_evaluation();

   std::cout << "Evaluation:" << std::endl
             << evaluation << std::endl;

   Vector<double> gradient = gp.calculate_gradient();

   std::cout << "Gradient:" << std::endl
             << gradient << std::endl;

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&gp);	
    
   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.set_evaluation_goal(0.0); 

   qnm.set_minimum_evaluation_improvement(0.0);
   qnm.set_maximum_epochs_number(100); 
   qnm.set_display_period(1); 

   // Train neural network

   gp.set_calculate_evaluation_count(0);

   qnm.train(); 

   // Save results to file

   mlp.save("../Data/MultilayerPerceptronGeodesicProblem.dat");
   mlp.save_expression("../Data/ExpressionGeodesicProblem.dat");

   gp.save_results("../Data/ResultsGeodesicProblem.dat");

   qnm.save_training_history("../Data/TrainingHistoryGeodesicProblem.dat");

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
