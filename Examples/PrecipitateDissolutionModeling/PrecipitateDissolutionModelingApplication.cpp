/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   P R E C I P I T A T E   D I S S O L U T I O N   A P P L I C A T I O N                                      */
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
#include "PrecipitateDissolutionModeling.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Precipitate Dissolution Application." << std::endl;	

//   srand((unsigned)time(NULL));

   // Multilayer perceptron objects

   MultilayerPerceptron mlp(1,3,1);
   
   mlp.set_input_variable_name(0, "log(t/t*)"); 
   mlp.set_output_variable_name(0, "1-f/f0"); 

   mlp.set_input_variable_minimum(0, -6.0);
   mlp.set_input_variable_maximum(0, 6.0);

   mlp.set_output_variable_minimum(0, 0.0);
   mlp.set_output_variable_maximum(0, 1.0);

   mlp.set_output_variable_lower_bound(0, 0.0);
   mlp.set_output_variable_upper_bound(0, 1.0);

   mlp.set_independent_parameters_number(1);
   mlp.set_independent_parameter_name(0, "effective_activation_energy");

   mlp.set_independent_parameter_minimum(0, 100.0);
   mlp.set_independent_parameter_maximum(0, 200.0);

   mlp.set_independent_parameter_lower_bound(0, 0.0);
   
   mlp.set_scaling_method(MultilayerPerceptron::MinimumMaximum);


   mlp.initialize_parameters_normal(0.0,1.0);

   mlp.set_display(false);

   // Activation energy object

   PrecipitateDissolutionModeling pdm(&mlp);

   pdm.set_Minkowski_parameter(1.0);

   pdm.setRegularizationWeight(0.0075);

   pdm.loadVickersHardnessTest("../Data/AA-2014-T6/VickersHardnessTestAA-2014-T6.dat");  

   //pdm.printVickersHardnessTest();

   // Random search object

   RandomSearch rs(&pdm);

   rs.train();

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&pdm);

   qnm.set_minimum_evaluation_improvement(0.0);
   qnm.set_maximum_epochs_number(1000);
   qnm.set_display_period(100);

   qnm.train();

   // Save results

   mlp.save("../Data/AA-7449-T79/MultilayerPerceptronAA-7449-T79.dat");

   mlp.save_expression("../Data/AA-7449-T79/ExpressionAA-7449-T79.dat");

   pdm.save_precipitate_dissolution_model("../Data/AA-7449-T79/PrecipitateDissolutionModelAA-7449-T79.dat");
   pdm.save_Vickers_hardness_model("../Data/AA-7449-T79/VickersHardnessModelOneNeuronAA-7449-T79.dat");
   pdm.save_inverse_Vickers_hardness_test("../Data/AA-7449-T79/InverseVickersHardnessTestAA-7449-T79.dat");

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
