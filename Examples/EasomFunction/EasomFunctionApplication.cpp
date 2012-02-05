/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   E A S O M   F U N C T I O N   A P P L I C A T I O N                                                        */
/*                                                                                                              */
/*   Gilles Cadose                                                                                              */
/*   Carlos Vargas de la Fuente                                                                                 */
/*   Hebert Sotelo Aedo                                                                                         */
/*                                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <iostream>
#include <time.h>
#include <stdexcept>

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "EasomFunction.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Easom Function Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   // Multilayer perceptron object

   MultilayerPerceptron mlp(2);

   mlp.set_independent_parameter_name(0, "x");
   mlp.set_independent_parameter_name(1, "y");
   
   mlp.set_independent_parameter_minimum(0, -100.0);
   mlp.set_independent_parameter_minimum(1, -100.0);
   
   mlp.set_independent_parameter_maximum(0, 100.0);
   mlp.set_independent_parameter_maximum(1, 100.0);

   mlp.initialize_independent_parameters_uniform(-100.0, 100.0);

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   // Easom function object

   EasomFunction ef(&mlp);

   // Initial guess

   Vector<double> initial_guess(2, 1.0);

   mlp.set_independent_parameters(initial_guess);

   std::cout << "Initial guess:" << std::endl 
			 << initial_guess << std::endl;

   // Evaluation

   double evaluation = ef.calculate_evaluation();
 
   std::cout << "Evaluation:" << std::endl
             << evaluation<< std::endl;
  
   // Gradient vector

   Vector<double> gradient = ef.calculate_gradient();
 
   std::cout << "Gradient:" << std::endl
	         << gradient << std::endl;

   // Hessian matrix
 
  Matrix<double> hessian = ef.calculate_Hessian();

  std::cout << "Hessian:" << std::endl
	        << hessian; 
 
   // Inverse Hessian matrix

   Matrix<double> inverse_Hessian = ef.calculate_inverse_Hessian();
 
   std::cout << "Inverse Hessian:" << std::endl
			 << inverse_Hessian;

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&ef);

   qnm.set_reserve_all_training_history(true);

   qnm.train();

   // Print minimal argument

   Vector<double> minimal_argument = mlp.get_independent_parameters();

   std::cout << "Minimal argument:" << std::endl
			 << minimal_argument << std::endl;

   // Save multilayer perceptron results

   mlp.save("../Data/MultilayerPerceptron.dat");

   // Save gradient descent results

   qnm.save("../Data/QuasiNewtonMethod.dat");
   qnm.save_training_history("../Data/TrainingHistory.dat");

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
