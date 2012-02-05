/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   P L A N E - C Y L I N D E R   A P P L I C A T I O N                                                        */
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
#include <stdexcept>

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "PlaneCylinder.h"
#include "../../Flood/TrainingAlgorithm/RandomSearch.h"
#include "../../Flood/TrainingAlgorithm/ConjugateGradient.h"

using namespace Flood;

int main(void)
{
   std::cout << "Flood Neural Network: Plane Cylinder Application." << std::endl;

   srand( (unsigned)time( NULL ) );

   // Multilayer perceptron object

   MultilayerPerceptron multilayer_perceptron(2);

   multilayer_perceptron.set_independent_parameter_name(0, "x");
   multilayer_perceptron.set_independent_parameter_name(1, "y");
   
   multilayer_perceptron.set_independent_parameter_minimum(0, -5.12);
   multilayer_perceptron.set_independent_parameter_minimum(1, -5.12);
   
   multilayer_perceptron.set_independent_parameter_maximum(0, 5.12);
   multilayer_perceptron.set_independent_parameter_maximum(1, 5.12);

   multilayer_perceptron.initialize_independent_parameters_uniform(-5.12, 5.12);

   multilayer_perceptron.set_independent_parameters_scaling_method(MultilayerPerceptron::MinimumMaximum);

   // Plane cylinder object

   PlaneCylinder planeCylinder(&multilayer_perceptron);
   planeCylinder.set_penalty(1000.0);

   int variables_number = multilayer_perceptron.get_independent_parameters_number();
   
   Vector<double> initial_guess(variables_number, 1.2);

   multilayer_perceptron.set_independent_parameters(initial_guess);

   // Print initial guess

   std::cout << "Initial guess: " << std::endl
    	     << initial_guess << std::endl;
	          
   // Evaluation
  
   double evaluation = planeCylinder.calculate_evaluation();
   
   std::cout << "Evaluation:" << std::endl
             << evaluation << std::endl;
             
   // Gradient vector

   Vector<double> gradient = planeCylinder.calculate_gradient();
   
   std::cout << "Gradient:" << std::endl
    	     << gradient << std::endl;            

   // Hessian matrix

   Matrix<double> hessian = planeCylinder.calculate_Hessian();
   
   std::cout << "Hessian:" << std::endl
	         << hessian;

   // Inverse Hessian matrix

   Matrix<double> inverse_Hessian = planeCylinder.calculate_inverse_Hessian();
   
   std::cout << "Inverse Hessian:" << std::endl
             << inverse_Hessian;
             
   // Random search object

   RandomSearch randomSearch(&planeCylinder);
   randomSearch.train();

   // Conjugate gradient object

   ConjugateGradient conjugate_gradient(&planeCylinder);
   conjugate_gradient.train();

   // Print minimal argument

   Vector<double> minimal_argument = multilayer_perceptron.get_independent_parameters();

   std::cout << "Minimal argument:" << std::endl 
	         << minimal_argument << std::endl;

   return(0);
}  
