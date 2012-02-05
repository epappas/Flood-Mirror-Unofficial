/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   L O G I C A L   O P E R A T O R S   A P P L I C A T I O N                                                  */
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
#include <math.h>
#include <time.h>

// Flood includes

#include "../../Flood/Utilities/Vector.h"
#include "../../Flood/Utilities/Matrix.h"
#include "../../Flood/Utilities/InputTargetDataSet.h"
#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/ObjectiveFunctional/NormalizedSquaredError.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Logical Operations Application." << std::endl;	

   srand((unsigned)time(NULL));

   // Input-target data set object

   InputTargetDataSet itds("../Data/InputTargetDataSet.dat");
   
   Vector< Vector<std::string> > variables_information = itds.get_variables_information();

   Vector< Vector<double> > variables_statistics = itds.scale_variables_minimum_maximum();

   // Multilayer perceptron object

   MultilayerPerceptron mlp(2,6,6);
   mlp.set_variables_information(variables_information);    
   mlp.set_variables_statistics(variables_statistics); 

   // Mean squared error object

   NormalizedSquaredError nse(&mlp, &itds);

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&nse);

   qnm.set_gradient_norm_goal(1.0e-6);

   qnm.train();
   
   // Save results

   mlp.set_variables_scaling_method(MultilayerPerceptron::MinimumMaximum);
   mlp.save("../Data/MultilayerPerceptron.dat");   

   // Print results to screen

   std::cout << std::endl 
             << "X " 
             << "Y " 
             << "AND "  
             << "OR " 
             << "NAND " 
             << "NOR " 
             << "XOR " 
             << "XNOR " 
             << std::endl;

   Vector<double> input(2, 0.0);
   Vector<double> output(6, 0.0);

   input[0] = 1.0;
   input[1] = 1.0;

   output = mlp.calculate_output(input);

   std::cout << (int)input[0] << " " 
             << (int)input[1] << " " 
             << (int)(output[0] + 0.5) << "   "  
             << (int)(output[1] + 0.5) << "  " 
             << (int)(output[2] + 0.5) << "    " 
             << (int)(output[3] + 0.5) << "   " 
             << (int)(output[4] + 0.5) << "   " 
             << (int)(output[5] + 0.5) << std::endl;

   input[0] = 1.0;
   input[1] = 0.0;

   output = mlp.calculate_output(input);

   std::cout << (int)input[0] << " " 
             << (int)input[1] << " " 
             << (int)(output[0] + 0.5) << "   "  
             << (int)(output[1] + 0.5) << "  " 
             << (int)(output[2] + 0.5) << "    " 
             << (int)(output[3] + 0.5) << "   " 
             << (int)(output[4] + 0.5) << "   " 
             << (int)(output[5] + 0.5) << std::endl;

   input[0] = 0.0;
   input[1] = 1.0;

   output = mlp.calculate_output(input);

   std::cout << (int)input[0] << " " 
             << (int)input[1] << " " 
             << (int)(output[0] + 0.5) << "   "  
             << (int)(output[1] + 0.5) << "  " 
             << (int)(output[2] + 0.5) << "    " 
             << (int)(output[3] + 0.5) << "   " 
             << (int)(output[4] + 0.5) << "   " 
             << (int)(output[5] + 0.5) << std::endl;

   input[0] = 0.0;
   input[1] = 0.0;

   output = mlp.calculate_output(input);

   std::cout << (int)input[0] << " " 
             << (int)input[1] << " " 
             << (int)(output[0] + 0.5) << "   "  
             << (int)(output[1] + 0.5) << "  " 
             << (int)(output[2] + 0.5) << "    " 
             << (int)(output[3] + 0.5) << "   " 
             << (int)(output[4] + 0.5) << "   " 
             << (int)(output[5] + 0.5) << std::endl;

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
