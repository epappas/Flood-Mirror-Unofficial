/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   S C H W E F E L   F U N C T I O N   A P P L I C A T I O N                                                  */
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
#include <sstream>
#include <time.h>
#include <stdexcept>

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "SchwefelFunction.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"
#include "../../Flood/TrainingAlgorithm/EvolutionaryAlgorithm.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Schwefel Function Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   // Problem parameters 

   unsigned int variables_number = 3;

   // Multilayer perceptron object

   MultilayerPerceptron mlp(variables_number);

   for(unsigned int i = 0; i < variables_number; i++)
   {
      std::stringstream buffer;
      buffer << "x" << i+1;
      mlp.set_independent_parameter_name(i, buffer.str());

      mlp.set_independent_parameter_minimum(i, -500.0);
      mlp.set_independent_parameter_maximum(i, 500.0); 
   }

   mlp.initialize_independent_parameters_uniform(-500.0, 500.0);
   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   // Schwefel function object

   SchwefelFunction sf(&mlp);             

   sf.set_variables_number(variables_number);

   // Evolutionary algorithm object

   EvolutionaryAlgorithm ea(&sf);      
   
   ea.set_maximum_epochs_number(2);

   ea.set_reserve_best_evaluation_history(true);
   ea.set_reserve_mean_evaluation_history(true);
   ea.set_reserve_standard_deviation_evaluation_history(true);

   ea.set_display_period(100);              
  
   ea.train();
 
   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&sf);
   
   qnm.set_reserve_evaluation_history(true);

   qnm.set_display_period(1);

   qnm.train();
  
   // Print solution to screen

   Vector<double> minimal_argument = mlp.get_independent_parameters();

   std::cout << "Minimal argument:" << minimal_argument << std::endl;

   // Save multilayer perceptron results

   mlp.save("../Data/MultilayerPerceptron.dat");

   // Save evolutionary algorithm results

   ea.save("../Data/EvolutionaryAlgorithm.dat");
   ea.save_training_history("../Data/TrainingHistoryEvolutionaryAlgorithm.dat");

   // Save quasi-Newton method results

   qnm.save("../Data/QuasiNewtonMethod.dat");
   qnm.save_training_history("../Data/TrainingHistoryQuasiNewtonMethod.dat");

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
