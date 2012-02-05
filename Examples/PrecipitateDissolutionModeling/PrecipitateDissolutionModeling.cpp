/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   P R E C I P I T A T E   D I S S O L U T I O N   M O D E L I N G   C L A S S                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */ 
/*                                                                                                              */
/****************************************************************************************************************/

// Flood includes

#include "PrecipitateDissolutionModeling.h"     

// System includes

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cmath>

namespace Flood
{

// GENERAL CONSTRUCTOR

PrecipitateDissolutionModeling::PrecipitateDissolutionModeling(MultilayerPerceptron* new_multilayer_perceptron)       
: ObjectiveFunctional(new_multilayer_perceptron)
{
   instances_number = 0;

   universalGasConstant = 8.314e-3; // kJ / mol K

   referenceTemperature = 0.0; // K
   referenceTime = 0.0; // s

   minimumVickersHardness = 0.0;
   maximumVickersHardness = 0.0;

   Minkowski_parameter = 2.0;

   minkowskiErrorWeight = 1.0;
   regularizationWeight = 0.0;
}


// DEFAULT CONSTRUCTOR

PrecipitateDissolutionModeling::PrecipitateDissolutionModeling(void) : ObjectiveFunctional()
{
   instances_number = 0;

   referenceTime = 16.0; // s
   universalGasConstant = 8.314e-3; // kJ / mol K
   referenceTemperature = 623.0; // K

   minimumVickersHardness = 73.8;
   maximumVickersHardness = 203.1;

   Minkowski_parameter = 2.0;

   minkowskiErrorWeight = 1.0;
   regularizationWeight = 0.0;
}


// DESTRUCTOR

PrecipitateDissolutionModeling::~PrecipitateDissolutionModeling(void) 
{

}


// METHODS

// double getMinimumVickersHardness(void) method

double PrecipitateDissolutionModeling::getMinimumVickersHardness(void)
{
   return(minimumVickersHardness);
}


// double getMaximumVickersHardness(void) method

double PrecipitateDissolutionModeling::getMaximumVickersHardness(void)
{
   return(maximumVickersHardness);
}


// double getReferenceTemperature(void)

double PrecipitateDissolutionModeling::getReferenceTemperature(void)
{
   return(referenceTemperature);
}


// double getReferenceTime(void)

double PrecipitateDissolutionModeling::getReferenceTime(void)
{
   return(referenceTime);
}


// double get_Minkowski_parameter(void) method

double PrecipitateDissolutionModeling::get_Minkowski_parameter(void)
{
   return(Minkowski_parameter);
}


// double getMinkowskiErrorWeight(void) method

double PrecipitateDissolutionModeling::getMinkowskiErrorWeight(void)
{
   return(minkowskiErrorWeight);
}


// double getRegularizationWeight(void) method

double PrecipitateDissolutionModeling::getRegularizationWeight(void)
{
   return(regularizationWeight);
}


// void setMinimumVickersHardness(double) method

void PrecipitateDissolutionModeling::setMinimumVickersHardness(double newMinimumVickersHardness)
{
   minimumVickersHardness = newMinimumVickersHardness;
}


// void setMaximumVickersHardness(double) method

void PrecipitateDissolutionModeling::setMaximumVickersHardness(double newMaximumVickersHardness)
{
   maximumVickersHardness = newMaximumVickersHardness;
}


// void setReferenceTemperature(double) method

void PrecipitateDissolutionModeling::setReferenceTemperature(double newReferenceTemperature)
{
   referenceTemperature = newReferenceTemperature;
}


// void setReferenceTime(double) method

void PrecipitateDissolutionModeling::setReferenceTime(double newReferenceTime)
{
   referenceTime = newReferenceTime;
}


// void set_Minkowski_parameter(double) method

void PrecipitateDissolutionModeling::set_Minkowski_parameter(double newMinkowskiParameter)
{
   Minkowski_parameter = newMinkowskiParameter;
}


// void setMinkowskiErrorWeight(double) method

void PrecipitateDissolutionModeling::setMinkowskiErrorWeight(double newMinkowskiErrorWeight)
{
   minkowskiErrorWeight = newMinkowskiErrorWeight;
}


// void setRegularizationWeight(double) method

void PrecipitateDissolutionModeling::setRegularizationWeight(double newRegularizationWeight)
{
   regularizationWeight = newRegularizationWeight;
}


// void loadVickersHardnessTest(const char*)

void PrecipitateDissolutionModeling::loadVickersHardnessTest(const char* filename)
{
   std::fstream file;

   file.open(filename, std::ios::in);

   if(!file.is_open())
   {
      std::cout << std::endl
                << "void loadVickersHardnessTest(const char*) method." << std::endl
                << "Cannot open Vickers hardness test data file."  << std::endl
                << std::endl;

      exit(1);
   }
   else
   {
      if(display)
      {
         std::cout << std::endl
                   << "Loading Vickers harndess test from file..." << std::endl;
      }
   }


   std::string word;

   // Minimum Vickers hardness

   while(word != "MinimumVickersHardness:")
   {
      file >> word;
   }
 
   file >> minimumVickersHardness;

   // Maximum Vickers hardness

   file >> word;

   file >> maximumVickersHardness;

   // Reference time

   file >> word;

   file >> referenceTime;

   // Reference temperature

   file >> word;

   file >> referenceTemperature;

   referenceTemperature += 273.16;

   // Number of samples

   file >> word;

   file >> instances_number;

   // Experimental data

   file >> word;

   Vector<double> newTemperatureData(instances_number);
   Vector<double> newTimeData(instances_number);
   Vector<double> newVickersHardnessData(instances_number);

   for(int i = 0; i < instances_number; i++)
   {
      file >> newTemperatureData[i];
      file >> newTimeData[i];
      file >> newVickersHardnessData[i];

     newTemperatureData[i] += 273.16;
   }

   temperatureData = newTemperatureData;
   timeData = newTimeData;
   vickersHardnessData = newVickersHardnessData;

   file.close();
}


// double getFullDissolutionTime(double) method

double PrecipitateDissolutionModeling::getFullDissolutionTime(double temperature)
{
   double fullDissolutionTime = 0.0;

   double effective_activation_energy = multilayer_perceptron_pointer->get_independent_parameter(0);

   fullDissolutionTime = referenceTime
   *exp((effective_activation_energy/universalGasConstant)*(1.0/temperature-1.0/referenceTemperature));

   return(fullDissolutionTime);
}


// double getVolumetricFraction(double) method

double PrecipitateDissolutionModeling::getVolumetricFraction(double vickersHardness)
{
   double volumetricFraction 
   = (vickersHardness - minimumVickersHardness)/(maximumVickersHardness - minimumVickersHardness);

   return(volumetricFraction);
}


// double getVickersHardness(double) method

double PrecipitateDissolutionModeling::getVickersHardness(double volumetricFraction)
{
   double vickersHardness = minimumVickersHardness 
   + (maximumVickersHardness-minimumVickersHardness)*(1.0 - volumetricFraction);

   return(vickersHardness);
}


// Vector<double> getNormalizedTimeData(void) method

Vector<double> PrecipitateDissolutionModeling::getNormalizedTimeData(void)
{
   Vector<double> normalizedTimeData(instances_number);

   double fullDissolutionTime = 0.0;

   for(int i = 0; i < instances_number; i++)
   {
      fullDissolutionTime = getFullDissolutionTime(temperatureData[i]); 

      normalizedTimeData[i] = log10(timeData[i]/fullDissolutionTime);
   }

   return(normalizedTimeData);
}


// Vector<double> getVolumetricFractionData(void) method

Vector<double> PrecipitateDissolutionModeling::getVolumetricFractionData(void)
{
   Vector<double> volumetricFractionData(instances_number);

   Vector<double> normalizedTimeData = getNormalizedTimeData();

   double volumetricFraction = 0.0;

   for(int i = 0; i < instances_number; i++)
   {
      volumetricFraction = getVolumetricFraction(vickersHardnessData[i]);
    
      volumetricFractionData[i] = 1.0 - volumetricFraction;
   }

   return(volumetricFractionData);
}


// double calculate_objective(void) method

double PrecipitateDissolutionModeling::calculate_objective(void)
{
   Vector<double> normalizedTimeData = getNormalizedTimeData();
   Vector<double> volumetricFractionData = getVolumetricFractionData();

   Vector<double> input(1);
   Vector<double> output(1);

   Vector<double> volumetricFractionModel(instances_number);

   double minkowskiError = 0.0;

   for(int i = 0; i < instances_number; i++)
   {
      input[0] = normalizedTimeData[i];
      output = multilayer_perceptron_pointer->calculate_output(input);
      
      volumetricFractionModel[i] = output[0];

      minkowskiError += pow(fabs(volumetricFractionData[i] - volumetricFractionModel[i]), Minkowski_parameter);
   }

   minkowskiError = pow(minkowskiError/(double)instances_number, 1.0/Minkowski_parameter);
  
   Vector<double> neural_parameters = multilayer_perceptron_pointer->get_neural_parameters();

   double neuralparameters_norm = neural_parameters.calculate_norm();

   double objective = minkowskiErrorWeight*minkowskiError + regularizationWeight*neuralparameters_norm;

   return(objective);
}


// void printVickersHardnessTest(void) method

void PrecipitateDissolutionModeling::printVickersHardnessTest(void)
{
   std::cout << std::endl;

   std::cout << "Dissolution modeling. Vickers hardness test." << std::endl;

   std::cout << "Minimum Vickers hardness:" << std::endl 
             << minimumVickersHardness << std::endl;

   std::cout << "Maximum Vickers hardness:" << std::endl 
             << maximumVickersHardness << std::endl;

   std::cout << "Reference time [s]:" << std::endl 
             << referenceTime << std::endl;

   std::cout << "Reference temperature [K]:" << std::endl 
             << referenceTemperature << std::endl;

   std::cout << "Number of samples:" << std::endl 
             << instances_number << std::endl;

   std::cout << "Experimental data:" << std::endl;
 
   for(int i = 0; i < instances_number; i++)
   {
      std::cout << temperatureData[i] << " " << timeData[i] << " " << vickersHardnessData[i] << std::endl;
   }
}


// std::string to_XML(void) method

std::string PrecipitateDissolutionModeling::to_XML(void)
{
   std::stringstream buffer;

   return(buffer.str());
}


// void print(void) method

void PrecipitateDissolutionModeling::print_information(void)
{
   double effective_activation_energy = multilayer_perceptron_pointer->get_independent_parameter(0);

   std::cout << "Effective activation energy: " << effective_activation_energy << std::endl;
}


// void save_precipitate_dissolution_model(const char*) method

void PrecipitateDissolutionModeling::save_precipitate_dissolution_model(const char* filename)
{
   std::fstream file; 

   file.open(filename, std::ios::out);

   // Control sentence

   if(!file.is_open())
   {
      std::cout << std::endl
                << "Cannot open precipitate dissolution model data file."
                << std::endl;
      
      exit(1);
   }


   int inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   Vector<int> numbersOfHiddenNeurons = multilayer_perceptron_pointer->get_hidden_layers_size();
   int outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   double effective_activation_energy = multilayer_perceptron_pointer->get_independent_parameter(0);

   Vector<double> normalizedTimeData = getNormalizedTimeData();
   Vector<double> volumetricFractionData = getVolumetricFractionData();

   Vector<double> input(1);
   Vector<double> output(1);

   Vector<double> volumetricFractionModel(instances_number);

   for(int i = 0; i < instances_number; i++)
   {
      input[0] = normalizedTimeData[i];
      output = multilayer_perceptron_pointer->calculate_output(input);

      volumetricFractionModel[i] = output[0];
   }

   // Sort data

   Vector<double> sortedNormalizedTimeData = normalizedTimeData;

   std::sort(sortedNormalizedTimeData.begin(), sortedNormalizedTimeData.end(), std::less<double>());

   Vector<double> sortedVolumetricFractionData(instances_number);
   Vector<double> sortedVolumetricFractionModel(instances_number);

   for(int i = 0; i < instances_number; i++)
   {
      for(int j = 0; j < instances_number; j++)
      {
         if(normalizedTimeData[j] == sortedNormalizedTimeData[i])
         {
            sortedVolumetricFractionData[i] = volumetricFractionData[j];
            sortedVolumetricFractionModel[i] = volumetricFractionModel[j];
         }
      }
   }

   file << "% Flood Neural Network. Precipitate Dissolution Model Data File." << std::endl;

   file << "% Network architecture: " << inputs_number << ":" << numbersOfHiddenNeurons << ":" << outputs_number 
        << std::endl;
   
   file << "% Effective activation energy: " << effective_activation_energy << std::endl;

   file << std::endl
        << "% Column data: " << std::endl
        << "% 1. Experimental X" << std::endl
        << "% 2. Experimental Y" << std::endl;

   
   for(int i = 0; i < instances_number; i++)
   {
     file << normalizedTimeData[i] << " " << volumetricFractionData[i] << std::endl;
   }

   file << std::endl
       << "% Column data: " << std::endl
       << "% 1. Normalized time (log(t/t*))" << std::endl
       << "% 2. Volumetric fraction (1-f/f0)" << std::endl;

   for(int i = 0; i < instances_number; i++)
   {
     file << sortedNormalizedTimeData[i] << " " << sortedVolumetricFractionData[i] << std::endl;
   }

   file.close();
}


// void save_Vickers_hardness_model(const char*) method

void PrecipitateDissolutionModeling::save_Vickers_hardness_model(const char* filename)
{
   std::fstream file; 

   file.open(filename, std::ios::out);

   // Control sentence

   if(!file.is_open())
   {
      std::cout << std::endl
                << "Cannot open Vickers hardness model data file."
                << std::endl;
      
      exit(1);
   }

   int inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   Vector<int> numbersOfHiddenNeurons = multilayer_perceptron_pointer->get_hidden_layers_size();
   int outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   double effective_activation_energy = multilayer_perceptron_pointer->get_independent_parameter(0);

   Vector<double> normalizedTimeData = getNormalizedTimeData();
   Vector<double> volumetricFractionData = getVolumetricFractionData();

   Vector<double> input(1);
   Vector<double> output(1);

   Vector<double> volumetricFractionModel(instances_number);

   for(int i = 0; i < instances_number; i++)
   {
      input[0] = normalizedTimeData[i];
      output = multilayer_perceptron_pointer->calculate_output(input);

      volumetricFractionModel[i] = output[0];
   }

   // Sort data

   Vector<double> sortedNormalizedTimeData = normalizedTimeData;

   std::sort(sortedNormalizedTimeData.begin(), sortedNormalizedTimeData.end(), std::less<double>());

   Vector<double> sortedVolumetricFractionData(instances_number);
   Vector<double> sortedVolumetricFractionModel(instances_number);

   for(int i = 0; i < instances_number; i++)
   {
      for(int j = 0; j < instances_number; j++)
      {
         if(normalizedTimeData[j] == sortedNormalizedTimeData[i])
         {
            sortedVolumetricFractionData[i] = volumetricFractionData[j];
            sortedVolumetricFractionModel[i] = volumetricFractionModel[j];
         }
      }
   }

   file << "% Flood Neural Network. Precipitate Dissolution Model Data File." << std::endl;

   file << "% Network architecture: " << inputs_number << ":" << numbersOfHiddenNeurons << ":" << outputs_number 
        << std::endl;
   
   file << "% Effective activation energy: " << effective_activation_energy << std::endl;

   file << std::endl
        << "% Column data: " << std::endl
        << "% 1. Normalized time data (log(t/t*))" << std::endl
        << "% 2. Vickers hardness data" << std::endl;

   
   for(int i = 0; i < instances_number; i++)
   {
     file << normalizedTimeData[i] << " " << vickersHardnessData[i] << std::endl;
   }

   file << std::endl
        << "% Column data: " << std::endl
        << "% 1. Sorted normalized time data (log(t/t*))" << std::endl
        << "% 2. Sorted Vickers hardness model" << std::endl;

   for(int i = 0; i < instances_number; i++)
   {
     file << sortedNormalizedTimeData[i] << " " << getVickersHardness(sortedVolumetricFractionModel[i]) << std::endl;
   }

   file.close();
}


// void save_inverse_Vickers_hardness_test(const char*) method

void PrecipitateDissolutionModeling::save_inverse_Vickers_hardness_test(const char* filename)
{
   std::fstream file; 

   file.open(filename, std::ios::out);

   // Control sentence

   if(!file.is_open())
   {
      std::cout << std::endl
                << "Cannot open reverse Vickers hardness test data file."
                << std::endl;
      
      exit(1);
   }

   int temperatures_number = 7;

   Vector<double> temperature(temperatures_number);

   temperature[0] = 200.0 + 273.16;
   temperature[1] = 250.0 + 273.16;
   temperature[2] = 300.0 + 273.16;
   temperature[3] = 350.0 + 273.16;
   temperature[4] = 400.0 + 273.16;
   temperature[5] = 450.0 + 273.16;
   temperature[6] = 500.0 + 273.16;

   int points_number = 11;

   Vector<double> time(points_number);

   time[0] = 1.0;
   time[1] = 5.0;
   time[2] = 10.0;
   time[3] = 50.0;
   time[4] = 100.0;
   time[5] = 500.0;
   time[6] = 1000.0;
   time[7] = 5000.0;
   time[8] = 10000.0;
   time[9] = 50000.0;
   time[10] = 100000.0;

   // Calculate and write inverse Vickers hardness test

   for(int i  = 0; i < points_number; i++)
   {
      file << time[i] << " ";

      for(int j = 0; j < temperatures_number; j++)
      {
         double fullDissolutionTime = getFullDissolutionTime(temperature[j]);
          
         Vector<double> input(1, log10(time[i]/fullDissolutionTime));
         Vector<double> output = multilayer_perceptron_pointer->calculate_output(input);
             
         double volumetricFraction = output[0];
         double vickersHardness = getVickersHardness(volumetricFraction);

         file << vickersHardness << " ";
      }
 
      file << std::endl;
   }

   // Close file

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
