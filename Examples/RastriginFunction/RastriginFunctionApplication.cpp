/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   R A S T R I G I N   F U N C T I O N   A P P L I C A T I O N                                                */
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
#include "RastriginFunction.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"
#include "../../Flood/TrainingAlgorithm/EvolutionaryAlgorithm.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Rastrigin Function Application." << std::endl;

   srand((unsigned)time(NULL));

   // Problem parameters 

   unsigned int variables_number = 3;

   // Multilayer perceptron object

   MultilayerPerceptron mlp;

   // Set multilayer perceptron stuff

   mlp.set_independent_parameters_number(variables_number);
   
   for(unsigned int i = 0; i < variables_number; i++)
   {
      std::stringstream buffer;
      buffer << "x" << i+1;
      mlp.set_independent_parameter_name(i, buffer.str());

      mlp.set_independent_parameter_minimum(i, -5.12);
	  mlp.set_independent_parameter_maximum(i, 5.12);  
   }

   mlp.initialize_independent_parameters_uniform(-5.12, 5.12);

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   // Rastrigin function object

   RastriginFunction rf(&mlp);

   rf.set_variables_number(variables_number);
   
   // Evolutionary algorithm object

   EvolutionaryAlgorithm ea(&rf);

   ea.set_population_size(10*variables_number);
   ea.set_maximum_generations_number(1000);

   ea.set_display_period(100);

   ea.initialize_population_uniform(-5.12, 5.12);

   ea.train();

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&rf);

   qnm.train();

   // Print minimal argument 

   Vector<double> minimal_argument = mlp.get_independent_parameters();

   std::cout << "Minimal argument:" << std::endl
	         << minimal_argument << std::endl;

   mlp.save("../Data/MultilayerPerceptron.dat");

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
