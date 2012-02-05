/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   D E   J O N G   F U N C T I O N   A P P L I C A T I O N                                                    */
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

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "DeJongFunction.h"
#include "../../Flood/TrainingAlgorithm/GradientDescent.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. De Jong Function Application." << std::endl;	

//   srand((unsigned)time(NULL));

   // Problem parameters 

   unsigned int variables_number = 2;

   // Multilayer perceptron object (independent parameters)

   MultilayerPerceptron mlp;

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

   // De Jong function object

   DeJongFunction djf(&mlp);

   djf.set_variables_number(variables_number);
   
   Vector<double> initial_guess(variables_number, 1.0);

   mlp.set_independent_parameters(initial_guess);

   // Evaluation
  
   double evaluation = djf.calculate_evaluation();
   
   std::cout << "Evaluation:" << std::endl
             << evaluation << std::endl;
             
   // Gradient vector

   Vector<double> gradient = djf.calculate_gradient();
   
   std::cout << "Gradient:" << std::endl
             << gradient << std::endl;
             
   // Hessian matrix

   Matrix<double> hessian = djf.calculate_Hessian();
   
   std::cout << "Hessian:" << std::endl
             << hessian;
             
   // Inverse Hessian matrix

   Matrix<double> inverse_Hessian = djf.calculate_inverse_Hessian();
   
   std::cout << "Inverse Hessian:" << std::endl
             << inverse_Hessian;

   // Gradient descent object

   GradientDescent gd(&djf);

   gd.set_reserve_evaluation_history(true);
   gd.set_reserve_gradient_norm_history(true);

   gd.set_maximum_epochs_number(1);
   gd.set_training_rate_tolerance(1.0e-12);

   gd.train();

   // Print minimal argument 

   Vector<double> minimal_argument = mlp.get_independent_parameters();

   std::cout << "Minimal argument:" << std::endl
	         << minimal_argument << std::endl;

   // Save multilayer perceptron results

   mlp.save("../Data/MultilayerPerceptron.dat");

   // Save gradient descent results

   gd.save("../Data/GradientDescent.dat");
   gd.save_training_history("../Data/TrainingHistory.dat");

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
