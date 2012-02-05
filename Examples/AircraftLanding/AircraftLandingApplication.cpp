/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   A I R C R A F T   L A N D I N G   A P P L I C A T I O N                                                    */
/*                                                                                                              */
/*   Roberto Lopez and Kevin Lau                                                                                */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu, kevin.lau@imperial.ac.uk                                                     */ 
/*                                                                                                              */  
/****************************************************************************************************************/

// System includes

#include <iostream>
#include <time.h>
#include <math.h>

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "AircraftLanding.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network. Aircraft Landing Application." << std::endl;

   srand((unsigned)time(NULL));

   const double pi = 3.1415927;

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1,3,1);    

   mlp.set_input_variable_name(0, "Time");
   mlp.set_output_variable_name(0, "ElevatorDeflectionAngle");

   mlp.set_input_variable_minimum(0, 0.0);
   mlp.set_input_variable_maximum(0, 20.0);

   mlp.set_output_variable_minimum(0, -2.0*pi/360.0);
   mlp.set_output_variable_maximum(0, 2.0*pi/360.0);

   // Aircraft landing object

   AircraftLanding al(&mlp);
   al.set_initial_altitude(100.0);
   al.set_state_variable_weights(500.0, 0.0, 1.0e-8, 5.0e-3);
   al.set_landing_variables_weights(0.0, 200.0, 5.0e-4, 5.0e-1);
   al.set_elevator_weight(10.0);

   // Random search object

   RandomSearch rs(&al);
   rs.set_maximum_epochs_number(100);
   rs.set_display_period(10);
   rs.train();

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&al);
   qnm.set_maximum_epochs_number(1000);
   qnm.set_display_period(100);
   qnm.train();

   // Save results

   mlp.save("../Data/MultilayerPerceptron.dat");
    
   al.save_results("../Data/Results.dat");
  
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
