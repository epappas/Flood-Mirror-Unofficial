/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M O C K   T R A I N I N G   A L G O R I T H M   C L A S S   H E A D E R                                    */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __MOCKTRAININGALGORITHM_H__
#define __MOCKTRAININGALGORITHM_H__

#include "../../Flood/TrainingAlgorithm/TrainingAlgorithm.h"
#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"
 
using namespace Flood;


class MockTrainingAlgorithm : public TrainingAlgorithm
{

public:

   // GENERAL CONSTRUCTOR

   explicit MockTrainingAlgorithm(ObjectiveFunctional*); 


   // DEFAULT CONSTRUCTOR

   explicit MockTrainingAlgorithm(void); 


   // DESTRUCTOR

   virtual ~MockTrainingAlgorithm(void);


   // METHODS

   // Train methods

   void train(void);
};


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
