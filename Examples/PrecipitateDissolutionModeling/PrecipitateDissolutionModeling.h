/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   P R E C I P I T A T E   D I S S O L U T I O N   M O D E L I N G   C L A S S   H E A D E R                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __PRECIPITATEDISSOLUTIONMODELING_H__
#define __PRECIPITATEDISSOLUTIONMODELING_H__

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"

#include <string>

namespace Flood
{

class PrecipitateDissolutionModeling : public ObjectiveFunctional
{

private:

   int instances_number;

   Vector<double> timeData;

   Vector<double> temperatureData;

   Vector<double> vickersHardnessData;

   double universalGasConstant;

   double referenceTemperature;

   double referenceTime;

   double minimumVickersHardness;

   double maximumVickersHardness;

   double Minkowski_parameter;

   double minkowskiErrorWeight;

   double regularizationWeight;

public:

   // GENERAL CONSTRUCTOR

   explicit PrecipitateDissolutionModeling(MultilayerPerceptron*);


   // DEFAULT CONSTRUCTOR

   explicit PrecipitateDissolutionModeling(void);


   // DESTRUCTOR

   virtual ~PrecipitateDissolutionModeling(void);

   
   // METHODS

   // Evaluation methods

   // Get methods

   double getMinimumVickersHardness(void);
   double getMaximumVickersHardness(void);

   double getReferenceTemperature(void);
   double getReferenceTime(void);

   double get_Minkowski_parameter(void);

   double getMinkowskiErrorWeight(void);
   double getRegularizationWeight(void);

   // Set methods

   void setMinimumVickersHardness(double);
   void setMaximumVickersHardness(double);

   void setReferenceTemperature(double);
   void setReferenceTime(double);

   void set_Minkowski_parameter(double);

   void setMinkowskiErrorWeight(double);
   void setRegularizationWeight(double);

   // Evaluation methods

   void loadVickersHardnessTest(const char*);

   double getFullDissolutionTime(double);

   double getVolumetricFraction(double);

   double getVickersHardness(double);

   Vector<double> getVolumetricFractionData(void);
   Vector<double> getNormalizedTimeData(void);

   double calculate_objective(void);
  
   // Utilities methods

   std::string to_XML(void);

   void print_information(void);

   void printVickersHardnessTest(void);

   void save_precipitate_dissolution_model(const char*);
   void save_Vickers_hardness_model(const char*);

   void save_inverse_Vickers_hardness_test(const char*);
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
