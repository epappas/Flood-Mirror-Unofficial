/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   F E D   B A T C H   F E R M E N T E R   C L A S S   H E A D E R                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __FEDBATCHFERMENTER_H__
#define __FEDBATCHFERMENTER_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"

namespace Flood
{

class FedBatchFermenter : public ObjectiveFunctional
{

public:

   // GENERAL CONSTRUCTOR  

   explicit FedBatchFermenter(MultilayerPerceptron*);


   // DEFAULT CONSTRUCTOR

   explicit FedBatchFermenter(void);


   // DESTRUCTOR

   virtual ~FedBatchFermenter(void);

   // METHODS

   // Get methods

   double get_final_time(void);

   double get_initial_cell_mass_concentration(void);
   double get_initial_substrate_concentration(void);
   double get_initial_product_concentration(void);
   double get_initial_broth_volume(void);

   double get_fermenter_volume(void);

   double get_minimum_feed_rate(void);
   double get_maximum_feed_rate(void);

   double get_volume_error_weight(void);
   double get_yield_weight(void);

   // Set methods

   void set_final_time(double);

   void set_initial_cell_mass_concentration(double);
   void set_initial_substrate_concentration(double);
   void set_initial_product_concentration(double);
   void set_initial_broth_volume(double);

   void set_fermenter_volume(double);

   void set_minimum_feed_rate(double);
   void set_maximum_feed_rate(double);

   void set_volume_error_weight(double);
   void set_yield_weight(double);

   // State equation methods

   double calculate_cell_mass_concentration_dot(double, double, double, double, double);
   double calculate_substrate_concentration_dot(double, double, double, double, double);
   double calculate_product_concentration_dot(double, double, double, double, double);
   double calculate_broth_volume_dot(double, double, double, double, double);

   double calculate_specific_growth_rate(double, double);
   double calculate_specific_productivity(double, double);

   // Objective methods

   double calculate_objective(void);

   // Utility methods

   void print_information(void);

   void save_results(const char*);

private:

   double final_time;

   double initialCellMassConcentration;

   double initialSubstrateConcentration;

   double initialProductConcentration;

   double initialBrothVolume;

   double fermenterVolume;

   double minimumFeedRate;

   double maximum_feed_rate;
     
   double volumeErrorWeight;

   double yieldWeight;
   
   double yieldCoefficient;

   double feedSubstrateConcentration;

   double kineticConstantMu0;

   double kineticConstantEta0;

   double kineticConstantKp;

   double kineticConstantKpDash;

   double kineticConstantKs;

   double kineticConstantKsDash;

   OrdinaryDifferentialEquations ordinary_differential_equations;
};

}

#endif


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
