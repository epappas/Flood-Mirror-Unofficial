/****************************************************************************************************************/
/*                                                                                                              */ 
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   C A R   P R O B L E M   N E U R O C O M P U T I N G   A P P L I C A T I O N                                */
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
#include "CarProblemNeurocomputing.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/QuasiNewtonMethod.h"

using namespace Flood;

int main(void)
{
	std::cout << "Flood Neural Network. Car Problem Neurocomputing Application." << std::endl;

   srand((unsigned)time(NULL));

   // Problem parameters

   double minimum_acceleration = -1.0;
   double maximum_acceleration = 1.0;

   double initial_position = 0.0;
   double initial_velocity = 0.0;

   double final_position_goal = 1.0;
   double final_velocity_goal = 0.0;

   double final_position_error_weight = 1.0;
   double final_velocity_error_weight = 1.0;
   double final_time_weight = 1.0e-3;

   // Multilayer perceptron object

   MultilayerPerceptron mlp(1,3,1);
   mlp.set_independent_parameters_number(1);

   mlp.set_input_variable_name(0, "time");
   mlp.set_output_variable_name(0, "acceleration");

   mlp.set_output_variable_lower_bound(0, minimum_acceleration);
   mlp.set_output_variable_upper_bound(0, maximum_acceleration);

   mlp.set_independent_parameter_name(0, "final_time");

   mlp.set_independent_parameter_lower_bound(0, 0.0);

   mlp.initialize_parameters_uniform(-0.1,0.1);   

   // Car problem Neurocomputing object

   CarProblemNeurocomputing cpn(&mlp);
   
   cpn.set_initial_position(initial_position);
   cpn.set_initial_velocity(initial_velocity);

   cpn.set_final_position_goal(final_position_goal);
   cpn.set_final_velocity_goal(final_velocity_goal);

   cpn.set_final_position_error_weight(final_position_error_weight);
   cpn.set_final_velocity_error_weight(final_velocity_error_weight);
   cpn.set_final_time_weight(final_time_weight);

   // Random search object

   RandomSearch rs(&cpn);
   rs.set_maximum_epochs_number(100);
   rs.set_display_period(10);

   rs.train();

   // Quasi-Newton method object

   QuasiNewtonMethod qnm(&cpn);
   qnm.set_maximum_epochs_number(1000);
   qnm.set_display_period(10);

   qnm.set_reserve_evaluation_history(true);
   qnm.set_reserve_gradient_norm_history(true);

   qnm.train();

   // Save results to data files

   mlp.save("../Data/MultilayerPerceptron.dat");
   mlp.load("../Data/MultilayerPerceptron.dat");

   cpn.save_results("../Data/Results.dat");

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
