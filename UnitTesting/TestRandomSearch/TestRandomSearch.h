/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   R A N D O M   S E A R C H   C L A S S   H E A D E R                                              */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TESTRANDOMSEARCH_H__
#define __TESTRANDOMSEARCH_H__

// Flood includes

#include "../../Flood/Utilities/UnitTesting.h"
 

using namespace Flood;


class TestRandomSearch : public UnitTesting
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit TestRandomSearch(void); 


   // DESTRUCTOR

   virtual ~TestRandomSearch(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void); 

   // Get methods

   void test_get_training_rate_reduction_factor(void);

   void test_get_reserve_potential_parameters_history(void);
   void test_get_reserve_potential_parameters_norm_history(void);

   void test_get_reserve_potential_evaluation_history(void);

   void test_get_potential_parameters_history(void);
   void test_get_potential_parameters_norm_history(void);

   void test_get_potential_evaluation_history(void);

   // Set methods

   void test_set_training_rate_reduction_factor(void);

   void test_set_reserve_potential_parameters_history(void);
   void test_set_reserve_potential_parameters_norm_history(void);

   void test_set_reserve_potential_evaluation_history(void);

   void test_set_potential_parameters_history(void);
   void test_set_potential_parameters_norm_history(void);

   void test_set_potential_evaluation_history(void);

   // Train methods

   void test_calculate_training_direction(void);

   void test_train(void);

   // Training history methods

   void test_set_reserve_all_training_history(void);
   void test_resize_training_history(void);
   void test_get_training_history_XML(void);

   // Utiltity methods

   void test_to_XML(void);

   void test_load(void);

   // Unit testing methods

   void run_test_case(void);

};


#endif


// Flood: An Open Source Neural Networks C++ Library.
// Copyright (C) 2005-2010 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later versi