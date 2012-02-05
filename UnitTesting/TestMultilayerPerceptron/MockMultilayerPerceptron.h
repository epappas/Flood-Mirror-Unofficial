/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M O C K   M U L T I L A Y E R   P E R C E P T R O N   C L A S S   H E A D E R                              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __MOCKMULTILAYERPERCEPTRON_H__
#define __MOCKMULTILAYERPERCEPTRON_H__


// Flood includes

#include "../../Flood/ObjectiveFunctional/ObjectiveFunctional.h"


using namespace Flood;


class MockMultilayerPerceptron : public MultilayerPerceptron
{

public:

   // GENERAL CONSTRUCTOR

   explicit MockMultilayerPerceptron(int, Vector<int>, int);


   // DEFAULT CONSTRUCTOR

   explicit MockMultilayerPerceptron(void);


   // DESTRUCTOR

   virtual ~MockMultilayerPerceptron(void);


   // METHODS

   Vector<double> calculate_particular_solution(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution(const Vector<double>&);

   Vector<double> calculate_particular_solution_derivative(const Vector<double>&);
   Vector<double> calculate_homogeneous_solution_derivative(const Vector<double>&);

   std::string to_XML(bool);   

   void print(void);   

   void save(const char*);   
   void load(const char*);   
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
