/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   A I R C R A F T   L A N D I N G   C L A S S                                                                */
/*                                                                                                              */
/*   Roberto Lopez and Kevin Lau                                                                                */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es, kevin.lau@imperial.ac.uk                                                      */ 
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <string>
#include <sstream>
#include <iostream>     
#include <fstream>     
#include <cstdlib>     
#include <cmath>     

// Flood includes

#include "AircraftLanding.h"     

namespace Flood
{

// GENERAL CONSTRUCTOR

AircraftLanding::AircraftLanding(MultilayerPerceptron* new_multilayer_perceptron)       
: ObjectiveFunctional(new_multilayer_perceptron)
{
   // Aircraft parameters

   short_period_gain = -0.95; // (s-1)
   path_time_constant = 2.5; // (s)
   short_period_resonant_frequency = 1.0; // (rad/s)
   short_period_damping_factor = 0.5; // no units

   // Flying conditions

   velocity = 256.0; // (ft/s)
   landing_time = 20.0; // (s)

   // Initial values

   initial_altitude = 100.0; // (ft)
   initial_altitude_rate = -10.0*1.0; // (ft/s)
   initial_pitch_angle = (1.0/velocity)*initial_altitude_rate; 
   initial_pitch_angle_rate = 0.0; // (rad/s)

   // Weight factors

   pitch_angle_rate_weight = 1.0;
   pitch_angle_weight = 1.0;
   altitude_rate_weight = 1.0;
   altitude_weight = 1.0;

   landing_pitch_angle_rate_weight = 1.0;
   landing_pitch_angle_weight = 1.0;
   landing_altitude_rate_weight = 1.0;
   landing_altitude_weight = 1.0;    elevator_weight = 1.0;

   // Integration stuff

   double tolerance = 1.0e-9;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}
 
 
// DEFAULT CONSTRUCTOR

AircraftLanding::AircraftLanding(void) : ObjectiveFunctional()
{   
   // Aircraft parameters

   short_period_gain = -0.95; // (s-1)
   path_time_constant = 2.5; // (s)
   short_period_resonant_frequency = 1.0; // (rad/s)
   short_period_damping_factor = 0.5; // no units

   // Flying conditions

   velocity = 256.0; // (ft/s)
   landing_time = 20.0; // (s)

   // Initial values

   initial_altitude = 100.0; // (ft)
   initial_altitude_rate = -10.0*1.0; // (ft/s)
   initial_pitch_angle = (1.0/velocity)*initial_altitude_rate; 
   initial_pitch_angle_rate = 0.0; // (rad/s)

   // Weight factors

   pitch_angle_rate_weight = 1.0;
   pitch_angle_weight = 1.0;
   altitude_rate_weight = 1.0;
   altitude_weight = 1.0;

   landing_pitch_angle_rate_weight = 1.0;
   landing_pitch_angle_weight = 1.0;
   landing_altitude_rate_weight = 1.0;
   landing_altitude_weight = 1.0;    elevator_weight = 1.0;

   // Integration stuff

   double tolerance = 1.0e-9;
   int initial_size = 1000;

   ordinary_differential_equations.set_tolerance(tolerance);
   ordinary_differential_equations.set_initial_size(initial_size);
}


// DESTRUCTOR

AircraftLanding::~AircraftLanding(void) 
{
}


// METHODS

// double get_short_period_gain(void) method

double AircraftLanding::get_short_period_gain(void)
{
   return(short_period_gain);
}


// double get_path_time_constant(void) method

double AircraftLanding::get_path_time_constant(void)
{
   return(path_time_constant);
}


// double get_short_period_resonant_frequency(void) method

double AircraftLanding::get_short_period_resonant_frequency(void)
{
   return(short_period_resonant_frequency);
}


// double get_short_period_damping_factor(void) method

double AircraftLanding::get_short_period_damping_factor(void)
{
   return(short_period_damping_factor);
}


// double get_velocity(void) method

double AircraftLanding::get_velocity(void)
{
   return(velocity);
}


// double get_landing_time(void) method

double AircraftLanding::get_landing_time(void)
{
   return(landing_time);
}


// double get_initial_pitch_angle(void) method

double AircraftLanding::get_initial_pitch_angle(void)
{
   return(initial_pitch_angle);
}


// double get_initial_pitch_angle_rate(void) method

double AircraftLanding::get_initial_pitch_angle_rate(void)
{
   return(initial_pitch_angle_rate);
}


// double get_initial_altitude(void) method

double AircraftLanding::get_initial_altitude(void)
{
   return(initial_altitude);
}


// double get_initial_altitude_rate(void) method

double AircraftLanding::get_initial_altitude_rate(void)
{
   return(initial_altitude_rate);
}


// double get_pitch_angle_rate_weight(void) method

double AircraftLanding::get_pitch_angle_rate_weight(void)
{   
   return(pitch_angle_rate_weight);
}


// double get_pitch_angle_weight(void) method

double AircraftLanding::get_pitch_angle_weight(void) 
{   
   return(pitch_angle_weight); 
}


// double get_altitude_rate_weight(void) method

double AircraftLanding::get_altitude_rate_weight(void) 
{
   return(altitude_rate_weight);   
}


// double get_altitude_weight(void) method

double AircraftLanding::get_altitude_weight(void) 
{   
   return(altitude_weight);  
}


// double get_landing_pitch_angle_weight(void) method

double AircraftLanding::get_landing_pitch_angle_rate_weight(void)
{   
   return(landing_pitch_angle_rate_weight);
}


// double get_landing_pitch_angle_weight(void) method

double AircraftLanding::get_landing_pitch_angle_weight(void)
{   
   return(landing_pitch_angle_weight);
}


// double get_landing_altitude_weight(void) method

double AircraftLanding::get_landing_altitude_rate_weight(void)
{
   return(landing_altitude_rate_weight);
}


// double get_landing_altitude_weight(void) method

double AircraftLanding::get_landing_altitude_weight(void)
{
   return(landing_altitude_weight);  
}


// double get_elevator_weight(void) method

double AircraftLanding::get_elevator_weight(void)
{   
   return(elevator_weight); 
}


// void set_short_period_gain(double) method

void AircraftLanding::set_short_period_gain(double new_short_period_gain)
{
   short_period_gain = new_short_period_gain;
}


//void set_short_period_resonant_frequency(double) method

void AircraftLanding::set_short_period_resonant_frequency(double new_short_period_resonant_frequency)
{
   short_period_resonant_frequency = new_short_period_resonant_frequency;
}


// void set_path_time_constant(double) method

void AircraftLanding::set_path_time_constant(double new_path_time_constant)
{
   path_time_constant = new_path_time_constant;
}


// void set_short_period_damping_factor(double) method

void AircraftLanding::set_short_period_damping_factor(double new_short_period_damping_factor)
{
   short_period_damping_factor = new_short_period_damping_factor;
}


// void set_velocity(double) method

void AircraftLanding::set_velocity(double new_velocity)
{
   velocity = new_velocity;
}


// void set_landing_time(double) method

void AircraftLanding::set_landing_time(double new_landing_time)
{
   landing_time = new_landing_time;
}


// void set_initial_pitch_angle_rate(double) method

void AircraftLanding::set_initial_pitch_angle_rate(double new_initial_pitch_angle_rate)
{
   initial_pitch_angle_rate = new_initial_pitch_angle_rate;
}


// void set_initial_pitch_angle(double) method

void AircraftLanding::set_initial_pitch_angle(double new_initial_pitch_angle)
{
   initial_pitch_angle = new_initial_pitch_angle;
}


// void set_initial_altitude_rate(double) method

void AircraftLanding::set_initial_altitude_rate(double new_initial_altitude_rate)
{
   initial_altitude_rate = new_initial_altitude_rate;
}


// void set_initial_altitude(double) method

void AircraftLanding::set_initial_altitude(double new_initial_altitude)
{
   initial_altitude = new_initial_altitude;
}


// void set_state_variable_weights(double,double,double, double) method

void AircraftLanding::set_state_variable_weights(double new_pitch_angle_rate_weight, 
double new_pitch_angle_weight, double new_altitude_rate_weight, double new_altitude_weight)
{
   pitch_angle_rate_weight = new_pitch_angle_rate_weight;   
   pitch_angle_weight = new_pitch_angle_weight;   
   altitude_rate_weight = new_altitude_rate_weight;   
   altitude_weight = new_altitude_weight;
}


// void set_landing_variables_weights(double, double, double, double) method

void AircraftLanding::set_landing_variables_weights(double new_landing_pitch_angle_rate_weight,
double new_landing_pitch_angle_weight, double new_landing_altitude_rate_weight, 
double new_landing_altitude_weight)
{
   landing_pitch_angle_rate_weight = new_landing_pitch_angle_rate_weight;    
   landing_pitch_angle_weight = new_landing_pitch_angle_weight;   
   landing_altitude_rate_weight = new_landing_altitude_rate_weight;   
   landing_altitude_weight = new_landing_altitude_weight;
}


// void set_elevator_weight(double) method

void AircraftLanding::set_elevator_weight(double new_elevator_weight)
{
   elevator_weight = new_elevator_weight;
}


// double calculate_pitch_angle_rate_dot(double, double, double, double, double) method

double AircraftLanding::calculate_pitch_angle_rate_dot(double time, 
double pitch_angle_rate, double pitch_angle, double altitude_rate, double)
{
   double pitch_angle_rate_dot = 0.0;

   double elevator_deflection = 0.0;

   Vector<double> input(1), output(1);

   input[0] = time;
   output = multilayer_perceptron_pointer->calculate_output(input);

   if(output[0] < ((-35.0/360.0)*(2.0*PI)))
   {
      elevator_deflection = ((-35.0/360.0)*(2.0*PI));
   }
   else if(output[0] > ((15.0/360.0)*(2.0*PI)))
   {
      elevator_deflection = ((15.0/360.0)*(2.0*PI));        
   }
   else
   {
      elevator_deflection = output[0];
   }

   double b11 = 1.0/path_time_constant 
              - 2.0*short_period_damping_factor*short_period_resonant_frequency;

   double b12 = (2.0*short_period_damping_factor*short_period_resonant_frequency) / path_time_constant
              - pow(short_period_resonant_frequency, 2.0)
              - 1.0/( pow(path_time_constant,2.0));

   double b13 = 1.0/(velocity*pow(path_time_constant,2.0))
              - ( 2.0*short_period_damping_factor*short_period_resonant_frequency) / (velocity*path_time_constant)   
              + ( pow(short_period_resonant_frequency,2.0) / velocity );

   double c1 = pow(short_period_resonant_frequency,2.0)*short_period_gain*path_time_constant;

   pitch_angle_rate_dot = b11*pitch_angle_rate + b12*pitch_angle + b13*altitude_rate + c1*elevator_deflection;

   return(pitch_angle_rate_dot);
}


// double calculate_pitch_angle_dot(double, double, double, double, double) method

double AircraftLanding::calculate_pitch_angle_dot(double, double pitch_angle_rate, double, double, double)
{
   double pitch_angle_dot = pitch_angle_rate;

   return(pitch_angle_dot);
}


// double calculate_altitude_rate_dot(double, double, double, double, double) method

double AircraftLanding::
calculate_altitude_rate_dot(double, double, double pitch_angle, double altitude_rate, double)
{
   double b32 = velocity/path_time_constant;

   double b33 = -(1.0/path_time_constant);

   double altitude_rate_dot = b32*pitch_angle + b33*altitude_rate;

   return(altitude_rate_dot);
}


// double calculate_altitude_dot(double, double, double, double, double) method

double AircraftLanding::calculate_altitude_dot(double, double, double, double altitude_rate, double)
{
   double altitude_dot = altitude_rate;

   return(altitude_dot);
}


// double get_pitch_angle_rate_goal(double) method

double AircraftLanding::get_pitch_angle_rate_goal(double)
{
   double pitch_angle_rate_goal = 0.0;
    
   return(pitch_angle_rate_goal);
}


// double get_pitch_angle_goal(double) method

double AircraftLanding::get_pitch_angle_goal(double time)
{   
   double pitch_angle_goal = 0;
    
   if(time == 20.0)
   {
      pitch_angle_goal = (1.0/180.0)*PI;  
   }
    
   return(pitch_angle_goal);
}


// double get_altitude_rate_goal(double) method

double AircraftLanding::get_altitude_rate_goal(double time)
{
   double altitude_rate_goal = 0.0;

   if(time <= 15.0) 
   {
      altitude_rate_goal = -20.0 * exp(-0.2 * time);   
   } 
   else if(time > 15.0) 
   {
      altitude_rate_goal = -1.0;   
   }

   return(altitude_rate_goal);
}


// double get_altitude_goal(double) method

double AircraftLanding::get_altitude_goal(double time)
{
   double altitude_goal = 0.0;
   
   if(time <= 15.0) 
   {
      altitude_goal = 100.0*exp(-0.2*time);   
   } 
   else if(time > 15.0) 
   {
      altitude_goal = 20.0 - time;   
   }

   return(altitude_goal);
}


// double calculate_objective(void) method

double AircraftLanding::calculate_objective(void)
{
   double objective = 0.0;

   Vector<double> input(1), output(1);

   // Solve state equations 

   Vector<double> time;

   Vector<double> pitch_angle_rate;
   Vector<double> pitch_angle;
   Vector<double> altitude_rate;
   Vector<double> altitude;
       
   int points_number = ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this, 
   time, pitch_angle_rate, pitch_angle, altitude_rate, altitude,
   &AircraftLanding::calculate_pitch_angle_rate_dot,
   &AircraftLanding::calculate_pitch_angle_dot,
   &AircraftLanding::calculate_altitude_rate_dot,
   &AircraftLanding::calculate_altitude_dot,
   0.0, 20.0, 
   initial_pitch_angle_rate, initial_pitch_angle, 
   initial_altitude_rate, initial_altitude);
       
   Vector<double> integrand(points_number);

   Vector<double> altitude_goal(points_number);
   Vector<double> elevator_deflection(points_number);

   for(int i = 0; i < points_number; i++)
   {   
      altitude_goal[i] = get_altitude_goal(time[i]);
            
      // Elevator deflection
      
      input[0] = time[i];
      output = multilayer_perceptron_pointer->calculate_output(input);
      
      if(output[0] < ((-35.0/360.0)*(2.0*PI)))
      {
         elevator_deflection[i] = ((-35.0/360.0)*(2.0*PI));
      }
      else if(output[0] > ((15.0/360.0)*(2.0*PI)))
      {
         elevator_deflection[i] = ((15.0/360.0)*(2.0*PI));        
      }
      else
      {
         elevator_deflection[i] = output[0];
      }   

      // Integrand

      integrand[i] 
      = 1.0e-6*pow(altitude_goal[i]-altitude[i], 2.0) + 1.0e-12*pow(elevator_deflection[i], 2.0);                       
   }

   objective = integration_of_functions.calculate_Simpson_integral(time, integrand);   
        
   objective += 1.0e-3*pow((1.0*PI/180.0)-pitch_angle[points_number-1], 2.0 );
   objective += 1.0e-6*pow(altitude[points_number-1], 2.0);
   
   return(objective);
}


// void print(void) method

void AircraftLanding::print(void)
{
}


// void save(const char*) method

void AircraftLanding::save(const char*)
{
}


// void load(const char*) method

void AircraftLanding::load(const char*)
{
}


// void print_information(void) method

void AircraftLanding::print_information(void)
{
//@todo
}


// std::string to_XML(void) method

std::string AircraftLanding::to_XML(void)
{
   std::stringstream buffer;
   // Aircraft parameters

   buffer << "ShortPeriodGain:" << std::endl
          << short_period_gain << std::endl;

   buffer << "ShortPeriodResonantFrequency:" << std::endl
          << short_period_resonant_frequency << std::endl;

   buffer << "ShortPeriodDampingFactor:" << std::endl
          << short_period_damping_factor << std::endl;

   buffer << "PathTimeConstant:" << std::endl
          << path_time_constant << std::endl;

   // Flying conditions

   buffer << "Velocity:" << std::endl
          << velocity << std::endl;

   buffer << "LandingTime:" << std::endl
          << landing_time << std::endl;

   // Initial values

   buffer << "InitialPitchAngle:" << std::endl
          << initial_pitch_angle << std::endl;

   buffer << "InitialPitchAngleRate:" << std::endl
          << initial_pitch_angle_rate << std::endl;

   buffer << "InitialAltitude:" << std::endl
          << initial_altitude << std::endl;

   buffer << "Initialaltitude_rate:" << std::endl
          << initial_altitude_rate << std::endl;

   // Weight factors

   buffer << "PitchAngleRateWeight:" << std::endl
          << pitch_angle_rate_weight << std::endl;
              
   buffer << "PitchAngleWeight:" << std::endl
          << pitch_angle_weight << std::endl;              
    
   buffer << "altitude_rateWeight:" << std::endl 
          << altitude_rate_weight << std::endl;              
              
   buffer << "AltitudeWeight:" << std::endl 
          << altitude_weight << std::endl;              

   buffer << "LandingPitchAngleRateWeight:" << std::endl 
          << landing_pitch_angle_rate_weight << std::endl;                  

   buffer << "LandingPitchAngleWeight:" << std::endl 
          << landing_pitch_angle_weight << std::endl;                  

   buffer << "Landingaltitude_rateWeight:" << std::endl 
          << landing_altitude_rate_weight << std::endl;                  

   buffer << "LandingAltitudeWeight:" << std::endl 
          << landing_altitude_weight << std::endl;                  

   buffer << "ElevatorWeight:" << std::endl 
          << elevator_weight << std::endl;    

   return(buffer.str());
}


// void save_results(const char*) method

void AircraftLanding::save_results(const char* filename)
{
   Vector<double> input(1), output(1);
   
   double elevator_deflection = 0.0;

   // Solve state equations 

   Vector<double> time;

   Vector<double> pitch_angle_rate;
   Vector<double> pitch_angle;
   Vector<double> altitude_rate;
   Vector<double> altitude;

   int points_number = ordinary_differential_equations.calculate_Runge_Kutta_Fehlberg_integral(*this, 
   time, pitch_angle_rate, pitch_angle, altitude_rate, altitude,
   &AircraftLanding::calculate_pitch_angle_rate_dot,
   &AircraftLanding::calculate_pitch_angle_dot,
   &AircraftLanding::calculate_altitude_rate_dot,
   &AircraftLanding::calculate_altitude_dot,
   0.0, landing_time, 
   initial_pitch_angle_rate, initial_pitch_angle, 
   initial_altitude_rate, initial_altitude);

   Vector<double> pitch_angle_rate_goal(points_number);
   Vector<double> pitch_angle_goal(points_number);
   Vector<double> altitude_rate_goal(points_number);
   Vector<double> altitude_goal(points_number);

   std::fstream file; 

   file.open(filename, std::ios::out);

   if(!file.is_open())
   {
      std::cerr << std::endl
                << "Flood Error: AircraftLanding class." << std::endl
                << "void save_results(const char*) method" << std::endl
                << "Cannot open aircraft landing results data file."  << std::endl;
      
      exit(1);
   }

   // File header

   file << "%  1 - Time" << std::endl
        << "%  2 - Pitch angle rate goal" << std::endl
        << "%  3 - Pitch angle goal" << std::endl
        << "%  4 - Altitude rate goal" << std::endl
        << "%  5 - Altitude goal" << std::endl
        << "%  6 - Pitch angle rate" << std::endl
        << "%  7 - Pitch angle" << std::endl
        << "%  8 - Altitude rate" << std::endl
        << "%  9 - Altitude" << std::endl
        << "% 10 - Elevator deflection" << std::endl << std::endl 
        << std::endl;

   // File data

   for(int i = 0; i < points_number; i++)
   {            
      pitch_angle_rate_goal[i] = get_pitch_angle_rate_goal(time[i]);
      pitch_angle_goal[i] = get_pitch_angle_goal(time[i]);
      altitude_rate_goal[i] = get_altitude_rate_goal(time[i]);
      altitude_goal[i] = get_altitude_goal(time[i]);

      input[0] = time[i];
      output = multilayer_perceptron_pointer->calculate_output(input);

      if(output[0] < ((-35.0/360.0)*(2.0*PI)))
      {
         elevator_deflection = ((-35.0/360.0)*(2.0*PI));
      }
      else if(output[0] > ((15.0/360.0)*(2.0*PI)))
      {
         elevator_deflection = ((15.0/360.0)*(2.0*PI));        
      }
      else
      {
         elevator_deflection = output[0];
      }

      file << time[i] << " " 
           << pitch_angle_rate_goal[i] << " "
           << pitch_angle_goal[i] << " "
           << altitude_rate_goal[i] << " "
           << altitude_goal[i] << " "
           << pitch_angle_rate[i] << " "
           << pitch_angle[i] << " "
           << altitude_rate[i] << " "
           << altitude[i] << " "
           << elevator_deflection << std::endl;   
   }  

   file.close();
}

}


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
