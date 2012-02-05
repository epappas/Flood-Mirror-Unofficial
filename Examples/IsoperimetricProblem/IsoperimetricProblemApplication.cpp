/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   I S O P E R I M E T R I C   P R O B L E M   A P P L I C A T I O N                                          */
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
#include "IsoperimetricProblem.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Isoperimetric Problem Application." << std::endl;	

//   srand((unsigned)time(NULL));

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1, 3, 2);

   Vector<std::string> input_variables_name(1, "t");
   Vector<std::string> output_variables_name(2);
   output_variables_name[0] = "x";
   output_variables_name[1] = "y";

   mlp.set_input_variables_name(input_variables_name);
   mlp.set_output_variables_name(output_variables_name);

   Vector<double> input_variables_minimum(1, 0.0);
   Vector<double> input_variables_maximum(1, 1.0);
   Vector<double> output_variables_minimum(2,-1.0);
   Vector<double> output_variables_maximum(2,1.0);

   mlp.set_input_variables_minimum(input_variables_minimum);
   mlp.set_input_variables_maximum(input_variables_maximum);
   mlp.set_output_variables_minimum(output_variables_minimum);
   mlp.set_output_variables_maximum(output_variables_maximum);

   // Isoperimetric problem object

   IsoperimetricProblem ip(&mlp);

   ip.set_perimeter_error_weight(100.0);
   ip.set_area_weight(1.0);

   ip.save_results("../Data/InitialGuessIsoperimetricProblem.dat");

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&ip);

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.set_maximum_epochs_number(5000); 
   qnm.set_display_period(10); 

   qnm.train(); 

   // Save results 

   mlp.save("../Data/MultilayerPerceptronIsoperimetricProblem.dat");

   mlp.save_expression("../Data/ExpressionIsoperimetricProblem.dat");

   ip.save_results("../Data/ResultsIsoperimetricProblem.dat");

   qnm.save_training_history("../Data/TrainingHistoryIsoperimetricProblem.dat");

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
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
