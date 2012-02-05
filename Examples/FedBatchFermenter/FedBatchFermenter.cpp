/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   F E D   B A T C H   F E R M E N T E R   C L A S S                                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <string>
#include <sstream>
#include <iostream>     
#include <fstream>     
#include <cmath>   

// Flood includes

#include "FedBatchFermenter.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"


namespace Flood
{

// GENERAL CONSTRUCTOR

FedBatchFermenter::FedBatchFermenter(MultilayerPerceptron* new_multilayer_perceptron)
: ObjectiveFunctional(new_multilayer_perceptron)
{
   final_time = 54.0;

   initialCellMassConcentration = 1.0;
   initialSubstrateConcentration = 150.0;
   initialProductConcentration = 0.0;
   initialBrothVolume = 10.0;

   fermenterVolume = 200.0;
   
   minimumFeedRate = 0.0;
   maximum_feed_rate = 12.0;

   volumeErrorWeight = 1.0e-2;
   yieldWeight = 1.0e-9;

   yieldCoefficient = 0.1; // no units
   feedSubstrateConcentration = 150.0; // g/l

   kineticConstantMu0 =0.408; // 1/h
   kineticConstantEta0 = 1.0; // 1/h
   kineticConstantKp = 16.0; // g/l
   kineticConstantKpDash = 71.5; // g/l
   kineticConstantKs = 0.22; // g/l
   kineticConstantKsDash = 0.44; // g/l

   double tolerance = 1.0e-15;
   int initial_size = 5000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);

}


// DEFAULT CONSTRUCTOR

FedBatchFermenter::FedBatchFermenter(void) : ObjectiveFunctional()
{
  final_time = 54.0;

  initialCellMassConcentration = 1.0;
  initialSubstrateConcentration = 150.0;
  initialProductConcentration = 0.0;
  initialBrothVolume = 10.0;

  fermenterVolume = 200.0;
   
  minimumFeedRate = 0.0;
  maximum_feed_rate = 12.0;

  volumeErrorWeight = 1.0e-2;
  yieldWeight = 1.0e-9;

   double tolerance = 1.0e-15;
   int initial_size = 5000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DESTRUCTOR

FedBatchFermenter::~FedBatchFermenter(void)
{

}


// METHODS

// double get_final_time(void) method

double FedBatchFermenter::get_final_time(void)
{
   return(final_time);
}


// double get_initial_cell_mass_concentration(void) method

double FedBatchFermenter::get_initial_cell_mass_concentration(void)
{
   return(initialCellMassConcentration);
}


// double get_initial_substrate_concentration(void) method

double FedBatchFermenter::get_initial_substrate_concentration(void)
{
   return(initialSubstrateConcentration);
}


// double get_initial_product_concentration(void) method

double FedBatchFermenter::get_initial_product_concentration(void)
{
   return(initialProductConcentration);
}


// double get_initial_broth_volume(void) method

double FedBatchFermenter::get_initial_broth_volume(void)
{
   return(initialBrothVolume);
}


// double get_fermenter_volume(void) method

double FedBatchFermenter::get_fermenter_volume(void)
{
   return(fermenterVolume);
}


// double get_minimum_feed_rate(void) method

double FedBatchFermenter::get_minimum_feed_rate(void)
{
   return(minimumFeedRate);
}


// double get_maximum_feed_rate(void) method

double FedBatchFermenter::get_maximum_feed_rate(void)
{
   return(maximum_feed_rate);
}


// double get_volume_error_weight(void) method

double FedBatchFermenter::get_volume_error_weight(void)
{
   return(volumeErrorWeight);
}


// double get_yield_weight(void) method

double FedBatchFermenter::get_yield_weight(void)
{
   return(yieldWeight);
}


// void set_final_time(double) method

void FedBatchFermenter::set_final_time(double newFinalTime)
{
   // Set final time

   final_time = newFinalTime;
}


// void set_initial_cell_mass_concentration(double) method

void FedBatchFermenter::set_initial_cell_mass_concentration(double newInitialCellMassConcentration)
{
   initialCellMassConcentration = newInitialCellMassConcentration;
}


// void set_initial_substrate_concentration(double) method

void FedBatchFermenter::set_initial_substrate_concentration(double newInitialSubstrateConcentration)
{
   initialSubstrateConcentration = newInitialSubstrateConcentration;
}


// void set_initial_product_concentration(double) method

void FedBatchFermenter::set_initial_product_concentration(double newInitialProductConcentration)
{
   initialProductConcentration = newInitialProductConcentration;
}


// void set_initial_broth_volume(double) method

void FedBatchFermenter::set_initial_broth_volume(double newInitialBrothVolume)
{
   initialBrothVolume = newInitialBrothVolume;
}


// void set_fermenter_volume(double) method

void FedBatchFermenter::set_fermenter_volume(double newFermenterVolume)
{
   fermenterVolume = newFermenterVolume;
}


// void set_minimum_feed_rate(double) method

void FedBatchFermenter::set_minimum_feed_rate(double newMinimumFeedRate)
{
   minimumFeedRate = newMinimumFeedRate;
}


// void set_maximum_feed_rate(double) method

void FedBatchFermenter::set_maximum_feed_rate(double newMaximumFeedRate)
{
   maximum_feed_rate = newMaximumFeedRate;
}


// void set_volume_error_weight(double) method

void FedBatchFermenter::set_volume_error_weight(double newVolumeErrorWeight)
{
   volumeErrorWeight = newVolumeErrorWeight;
}


// void set_yield_weight(double) method

void FedBatchFermenter::set_yield_weight(double newYieldWeight)
{
   yieldWeight = newYieldWeight;
}


// double calculate_specific_growth_rate(double, double) method

double FedBatchFermenter
::calculate_specific_growth_rate(double productConcentration, double substrateConcentration)
{
   double specificGrowthRate = 0.0;
   
   specificGrowthRate 
   = (kineticConstantMu0/(1.0+productConcentration/kineticConstantKp))
   *(substrateConcentration/(kineticConstantKs+substrateConcentration));

   return(specificGrowthRate);
}


// double calculate_specific_productivity(double, double) method

double FedBatchFermenter
::calculate_specific_productivity(double productConcentration, double substrateConcentration)
{
   double specificProductivity = 0.0;

   specificProductivity 
   = (kineticConstantEta0/(1.0+productConcentration/kineticConstantKpDash))
   *(substrateConcentration/(kineticConstantKsDash+substrateConcentration));

   return(specificProductivity);
}


// void calculate_cell_mass_concentration_dot(double, double, double, double, double) method

double FedBatchFermenter::calculate_cell_mass_concentration_dot(double time, 
double cellMassConcentration, double substrateConcentration, double productConcentration, double brothVolume)
{
   double cellMassConcentrationDot = 0.0;

   // Obtain control

   double feedRate = 0.0;

   Vector<double> input(1, time);

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input);

   // Bound control

   if(output[0] < minimumFeedRate)
   {
      feedRate = minimumFeedRate;
   }
   else if(output[0] > maximum_feed_rate)
   {
      feedRate = maximum_feed_rate;
   }
   else
   {
       feedRate = output[0];
   }

   // Calculate cell mass concentration derivative

    double specificGrowthRate = calculate_specific_growth_rate(productConcentration, substrateConcentration);

   cellMassConcentrationDot = 
   specificGrowthRate*cellMassConcentration - feedRate*(cellMassConcentration/brothVolume);
    
   return(cellMassConcentrationDot);
}


// void calculate_substrate_concentration_dot(double, double, double, double, double) method

double FedBatchFermenter::calculate_substrate_concentration_dot(double time, 
double cellMassConcentration, double substrateConcentration, double productConcentration, double brothVolume)
{
   double substrateConcentrationDot = 0.0;

   // Obtain control 

   double feedRate = 0.0;

   Vector<double> input(1, time);

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input);

   if(output[0] < minimumFeedRate)
   {
      feedRate = minimumFeedRate;
   }
   else if(output[0] > maximum_feed_rate)
   {
      feedRate = maximum_feed_rate;
   }
   else
   {
       feedRate = output[0];
   }

   // Calculate substrate concentration derivative

    double specificGrowthRate = calculate_specific_growth_rate(productConcentration, substrateConcentration);

   substrateConcentrationDot = 
   -1.0*specificGrowthRate*cellMassConcentration/yieldCoefficient 
   + feedRate*(feedSubstrateConcentration-substrateConcentration)/brothVolume;

   return(substrateConcentrationDot);
}


// void calculate_product_concentration_dot(double, double, double, double, double) method

double FedBatchFermenter::calculate_product_concentration_dot(double time, 
double cellMassConcentration, double substrateConcentration, double productConcentration, double brothVolume)
{
   double productConcentrationDot = 0.0;

   // Obtain control

   double feedRate = 0.0;

   Vector<double> input(1, time);

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input);

   // Bound control

   if(output[0] < minimumFeedRate)
   {
      feedRate = minimumFeedRate;
   }
   else if(output[0] > maximum_feed_rate)
   {
      feedRate = maximum_feed_rate;
   }
   else
   {
       feedRate = output[0];
   }

   // calculate product concentration derivative

    double specificProductivity = calculate_specific_productivity(productConcentration, substrateConcentration);

    productConcentrationDot = specificProductivity*cellMassConcentration
   - feedRate*productConcentration/brothVolume;

   return(productConcentrationDot);
}


// void calculate_broth_volume_dot(double, double, double, double, double) method

double FedBatchFermenter::calculate_broth_volume_dot(double time, double, double, double, double)
{
   double brothVolumeDot = 0.0;

   // Obtain control

   double feedRate = 0.0;
   
   Vector<double> input(1, time);

   Vector<double> output = multilayer_perceptron_pointer->calculate_output(input);

   // Bound control

   if(output[0] < minimumFeedRate)
   {
      feedRate = minimumFeedRate;
   }
   else if(output[0] > maximum_feed_rate)
   {
      feedRate = maximum_feed_rate;
   }
   else
   {
       feedRate = output[0];
   }

   // Calculate broth volume derivative

   brothVolumeDot = feedRate;

   return(brothVolumeDot);
}


// double calculate_evaluation(void) method

double FedBatchFermenter::calculate_objective(void)
{
   // Solve state equations 

   Vector<double> time;
   Vector<double> cellMassConcentration;
   Vector<double> substrateConcentration;
   Vector<double> productConcentration;
   Vector<double> brothVolume;

   double initial_time = 0.0;

    int points_number = 
    ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
    time, cellMassConcentration, substrateConcentration, productConcentration, brothVolume,
    &FedBatchFermenter::calculate_cell_mass_concentration_dot,
    &FedBatchFermenter::calculate_substrate_concentration_dot,
    &FedBatchFermenter::calculate_product_concentration_dot,
    &FedBatchFermenter::calculate_broth_volume_dot,
    initial_time, final_time, 
    initialCellMassConcentration, initialSubstrateConcentration, initialProductConcentration, initialBrothVolume);

   // Obtain control vector

   Vector<double> feedRate(points_number);

   Vector<double> input(1), output(1);

   for(int i = 0; i < points_number; i++)
   {
      input[0] = time[i];
      output = multilayer_perceptron_pointer->calculate_output(input);
      feedRate[i] = output[0];
   }   

   // Calculate volume error

   double volumeError = 0.0;

   if(brothVolume[points_number-1] <= fermenterVolume)
   {
      volumeError = 0.0;
   }
   else
   {
      volumeError = brothVolume[points_number-1] - fermenterVolume;
   }

   // Calculate yield

   double yield = productConcentration[points_number-1]*brothVolume[points_number-1];

   // Calculate evaluation
    
   return(volumeErrorWeight*pow(volumeError,2) -1.0*yieldWeight*pow(yield,2));
}


// void save_results(const char*) method

void FedBatchFermenter::save_results(const char* filename)
{
   Vector<double> input(1), output(1);
   
   // Solve state equations 

   Vector<double> time;
   Vector<double> cellMassConcentration;
   Vector<double> substrateConcentration;
   Vector<double> productConcentration;
   Vector<double> brothVolume;

   double initial_time = 0.0;

   int points_number = 
    ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   time, cellMassConcentration, substrateConcentration, productConcentration, brothVolume,
   &FedBatchFermenter::calculate_cell_mass_concentration_dot,
   &FedBatchFermenter::calculate_substrate_concentration_dot,
   &FedBatchFermenter::calculate_product_concentration_dot,
   &FedBatchFermenter::calculate_broth_volume_dot,
   initial_time, final_time, 
   initialCellMassConcentration, initialSubstrateConcentration, initialProductConcentration, initialBrothVolume);

   // Control vector

   Vector<double> feedRate(points_number);

   for(int i = 0; i < points_number; i++)
   {
      // Obtain control 

      input[0] = time[i];
      output = multilayer_perceptron_pointer->calculate_output(input);

      // Bound control

      if(output[0] < minimumFeedRate)
      {
         feedRate[i] = minimumFeedRate;
      }
      else if(output[0] > maximum_feed_rate)
      {
         feedRate[i] = maximum_feed_rate;
      }
      else
      {
         feedRate[i] = output[0];
      }
   }   

   // Obtain yield

   double yield = productConcentration[points_number-1]*brothVolume[points_number-1];

   // Write file

   std::fstream file; 

   file.open(filename, std::ios::out);

   if(!file.is_open())
   {
      std::cout << std::endl 
                << "Cannot open fed batch fermenter problem results data file."
                << std::endl;
      
      exit(1);
   }
   else
   {
      std::cout << std::endl
                << "Saving fed batch fermenter problem results to data file..."
                << std::endl;
   }

   file << "% Yield (g): " << yield << std::endl
        << "% Batch time (h): " << final_time << std::endl
        << "%" << std::endl;

   file << "% 1 - Time" << std::endl
        << "% 2 - Cell mass concentration (g/l)" << std::endl
        << "% 3 - Substrate concentration (g/l)" << std::endl
        << "% 4 - Product concentration (g/l)" << std::endl
        << "% 5 - Broth volume (l)" << std::endl
        << "% 6 - Specific growth rate" << std::endl
        << "% 7 - Specific productivity" << std::endl
        << "% 8 - Feed rate -control- (g/l)" << std::endl
        << std::endl;

   double specificGrowthRate = 0.0;
   double specificProductivity = 0.0;

   for(int i = 0; i < points_number; i++)
   {
      specificGrowthRate = calculate_specific_growth_rate(productConcentration[i], substrateConcentration[i]);
      specificProductivity = calculate_specific_productivity(productConcentration[i], substrateConcentration[i]);

      file << time[i] << " " 
           << cellMassConcentration[i] << " "
           << substrateConcentration[i] << " "
           << productConcentration[i] << " "
           << brothVolume[i] << " "
           << specificGrowthRate << " "
           << specificProductivity << " "
           << feedRate[i] << std::endl;   
   }   

   file.close();
}


// void print_information(void) method

void FedBatchFermenter::print_information(void)
{      
   // Solve state equations 

   Vector<double> time;
   Vector<double> cellMassConcentration;
   Vector<double> substrateConcentration;
   Vector<double> productConcentration;
   Vector<double> brothVolume;

    double initial_time = 0.0;

   int points_number = 
   ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this,
   time, cellMassConcentration, substrateConcentration, productConcentration, brothVolume,
   &FedBatchFermenter::calculate_cell_mass_concentration_dot,
   &FedBatchFermenter::calculate_substrate_concentration_dot,
   &FedBatchFermenter::calculate_product_concentration_dot,
   &FedBatchFermenter::calculate_broth_volume_dot,
   initial_time, final_time, 
   initialCellMassConcentration, initialSubstrateConcentration, initialProductConcentration, initialBrothVolume);

   double volumeError = 0.0;
   
   if(brothVolume[points_number-1] <= fermenterVolume)
   {
      volumeError = 0.0;
   }
   else
   {
      volumeError = brothVolume[points_number-1] - fermenterVolume;
   }

   // Calculate yield

   double yield = productConcentration[points_number-1]*brothVolume[points_number-1];

   std::cout << "Volume error: " << volumeError << std::endl
             << "Yield: " << yield << std::endl;
}

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
