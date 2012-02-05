/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   S I X   H U M P   C A M E L   B A C K   F U N C T I O N   A P P L I C A T I O N                            */
/*                                                                                                              */
/*   Alicia  & Iorga                                                                                            */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: a_kalms@hotmail.com, iorga1@mixmail.com                                                            */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <iostream>
#include <sstream>
#include <time.h>
#include <stdexcept>

// Flood includes

#include "../../Flood/Utilities/Vector.h"
#include "../../Flood/Utilities/Matrix.h"
#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "SixHumpCamelBackFunction.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"
#include "../../Flood/TrainingAlgorithm/EvolutionaryAlgorithm.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Six Hump Camel Back Function Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   // Multilayer perceptron object 

   MultilayerPerceptron mlp;
   mlp.set_independent_parameters_number(2);

   mlp.set_independent_parameter_name(0, "x");
   mlp.set_independent_parameter_name(1, "y");

   Vector<double> independent_parameters_minimum(2, 0.0);
   independent_parameters_minimum[0] = -3.0;
   independent_parameters_minimum[1] = -2.0;
   mlp.set_independent_parameters_minimum(independent_parameters_minimum);

   Vector<double> independent_parameters_maximum(2, 0.0);
   independent_parameters_maximum[0] = 3.0;
   independent_parameters_maximum[1] = 2.0;
   mlp.set_independent_parameters_maximum(independent_parameters_maximum);

   mlp.initialize_independent_parameters_uniform(independent_parameters_minimum, independent_parameters_maximum);

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   // Six hump camel back function object

   SixHumpCamelBackFunction shcbf(&mlp); 

   // Evolutionary algorithm object

   EvolutionaryAlgorithm ea(&shcbf);
   ea.set_population_size(100);
   ea.set_maximum_generations_number(1000);   

   ea.set_display_period(100);

   ea.train();

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&shcbf);
   qnm.train();

   // Print minimal argument to screen

   Vector<double> minimal_argument = mlp.get_independent_parameters();

   std::cout << "Minimal argument:" << std::endl
	         << minimal_argument << std::endl;

   return(0);
}  


// Flood: An Open Source Neural Networks C++ Library.
// Copyright (C) 2005-2010 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
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
