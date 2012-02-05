/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   R O S E N B R O C K   F U N C T I O N   A P P L I C A T I O N                                              */
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
#include "RosenbrockFunction.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Rosenbrock Function Application." << std::endl;

   srand((unsigned)time(NULL));

   // Problem parameters

   unsigned int variables_number = 2;

   // Multilayer perceptron object

   MultilayerPerceptron mlp(variables_number);
   
   for(unsigned int i = 0; i < variables_number; i++)
   {
      std::stringstream buffer;
      buffer << "x" << i+1;
      mlp.set_independent_parameter_name(i, buffer.str());

      mlp.set_independent_parameter_minimum(i, -2.048);
      mlp.set_independent_parameter_maximum(i, 2.048);  
   }

   mlp.initialize_independent_parameters_uniform(-2.048, 2.048);

   mlp.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   // Rosenbrock function object

   RosenbrockFunction rf(&mlp);

   rf.set_variables_number(variables_number);

   Vector<double> initial_guess(variables_number, 1.2);
  
   mlp.set_independent_parameters(initial_guess);

   // Evaluation
  
   double evaluation = rf.calculate_evaluation();
   
   std::cout << "Evaluation:" << std::endl
             << evaluation << std::endl;
             
   // Gradient vector

   Vector<double> gradient = rf.calculate_gradient();
   
   std::cout << "Gradient:" << std::endl
	         << gradient << std::endl;
             
   // Hessian matrix

   Matrix<double> hessian = rf.calculate_Hessian();
   
   std::cout << "Hessian:" << std::endl
             << hessian << std::endl;
            
   // Inverse Hessian matrix

   Matrix<double> inverse_Hessian = rf.calculate_inverse_Hessian();
   
   std::cout << "Inverse Hessian:" << std::endl
             << inverse_Hessian << std::endl;
             
   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&rf);

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.set_gradient_norm_goal(1.0e-12);
   qnm.set_maximum_epochs_number(100);

   qnm.set_display_period(1);

   qnm.train();

   // Print minimal argument 

   Vector<double> minimal_argument = mlp.get_independent_parameters();

   std::cout << "Minimal argument:" << std::endl
	         << minimal_argument << std::endl;

   // Save all stuff

   mlp.save("../Data/MultilayerPerceptron.dat");


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
