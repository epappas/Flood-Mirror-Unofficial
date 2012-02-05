/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   A I R C R A F T   L A N D I N G   C L A S S   H E A D E R                                                  */
/*                                                                                                              */
/*   Roberto Lopez and Kevin Lau                                                                                */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es, kevin.lau@imperial.ac.uk                                                      */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __AIRCRAFTLANDING_H__
#define __AIRCRAFTLANDING_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/Utilities/OrdinaryDifferentialEquations.h"
#include "../../Flood/Utilities/IntegrationOfFunctions.h"     

namespace Flood
{

class AircraftLanding : public ObjectiveFunctional
{

#define PI 4.0*atan(1.0)

public:

     // GENERAL CONSTRUCTOR

   explicit AircraftLanding(MultilayerPerceptron*);


     // DEFAULT CONSTRUCTOR

   explicit AircraftLanding(void);


   // DESTRUCTOR

   virtual ~AircraftLanding(void);

   // METHODS

   // Get methods

   double get_short_period_gain(void);
   double get_path_time_constant(void);
   double get_short_period_resonant_frequency(void);
   double get_short_period_damping_factor(void);

   double get_velocity(void);
   double get_landing_time(void);

   double get_initial_pitch_angle(void);
   double get_initial_pitch_angle_rate(void);
   double get_initial_altitude(void);
   double get_initial_altitude_rate(void);

   double get_pitch_angle_rate_weight(void);
   double get_pitch_angle_weight(void);
   double get_altitude_rate_weight(void);    
   double get_altitude_weight(void);
    
   double get_landing_pitch_angle_rate_weight(void);
   double get_landing_pitch_angle_weight(void);
   double get_landing_altitude_rate_weight(void);
   double get_landing_altitude_weight(void);

   double get_elevator_weight(void);

   // Set methods

   void set_short_period_gain(double);
   void set_short_period_resonant_frequency(double);
   void set_short_period_damping_factor(double);
   void set_path_time_constant(double);

   void set_velocity(double);
   void set_landing_time(double);

   void set_initial_pitch_angle(double);
   void set_initial_pitch_angle_rate(double);
   void set_initial_altitude(double);
   void set_initial_altitude_rate(double);    void set_state_variable_weights(double, double, double, double);
   void set_landing_variables_weights(double, double, double, double);
   void set_elevator_weight(double);
    
   // State equation methods

   double calculate_pitch_angle_rate_dot(double, double, double, double, double);
   double calculate_pitch_angle_dot(double, double, double, double, double);
   double calculate_altitude_rate_dot(double, double, double, double, double);
   double calculate_altitude_dot(double, double, double, double, double);

   // Evaluation methods

   double get_pitch_angle_goal(double);
   double get_pitch_angle_rate_goal(double);
   double get_altitude_goal(double);
   double get_altitude_rate_goal(double);

   double calculate_objective(void);

   // Utility methods

   std::string to_XML(void);

   void print(void);

   void save(const char*);
   void load(const char*);

   void print_information(void);

   void save_results(const char*);

private:

   // Aircraft parameters

   double short_period_gain;
   double short_period_resonant_frequency;
   double short_period_damping_factor;
   double path_time_constant;

   // Flying conditions

   double velocity;
   double landing_time;

   // Initial values

   double initial_pitch_angle;
   double initial_pitch_angle_rate;
   double initial_altitude;
   double initial_altitude_rate;

   // Weight factors

   double pitch_angle_weight;
   double pitch_angle_rate_weight;
   double altitude_weight;
   double altitude_rate_weight;

   double landing_pitch_angle_weight;
   double landing_pitch_angle_rate_weight;
   double landing_altitude_weight;
   double landing_altitude_rate_weight;

   double elevator_weight;

   // Integration stuff

   OrdinaryDifferentialEquations ordinary_differential_equations;   

   IntegrationOfFunctions integration_of_functions;
};

}

#endif

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
