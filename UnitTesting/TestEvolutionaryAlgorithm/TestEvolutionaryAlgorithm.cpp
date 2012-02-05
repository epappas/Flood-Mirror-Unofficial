/****************************************************************************************************************/
/*                                                                                                              */
/*   Flood: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T E S T   E V O L U T I O N A R Y   A L G O R I T H M   C L A S S                                          */
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

// Flood includes

#include "../../Flood/MultilayerPerceptron/MultilayerPerceptron.h"
#include "../../Flood/TrainingAlgorithm/EvolutionaryAlgorithm.h"

// Unit testing includees

#include "../TestObjectiveFunctional/MockObjectiveFunctional.h"
#include "TestEvolutionaryAlgorithm.h"

using namespace Flood;


// GENERAL CONSTRUCTOR 

TestEvolutionaryAlgorithm::TestEvolutionaryAlgorithm(void) : UnitTesting()
{
}


// DESTRUCTOR

TestEvolutionaryAlgorithm::~TestEvolutionaryAlgorithm(void)
{
}


// METHODS

// void test_constructor(void) method

void TestEvolutionaryAlgorithm::test_constructor(void)
{
   message += "test_constructor\n"; 

   // Default constructor

   EvolutionaryAlgorithm ea1; 
   assert_true(ea1.get_objective_functional_pointer() == NULL, LOG);   

   // Objective functional constructor

   MockObjectiveFunctional mof2;

   EvolutionaryAlgorithm ea2(&mof2); 
   assert_true(ea2.get_objective_functional_pointer() != NULL, LOG);   

   MultilayerPerceptron mlp3(1);
   MockObjectiveFunctional mof3(&mlp3);
   EvolutionaryAlgorithm ea3(&mof3); 
   assert_true(ea3.get_objective_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void TestEvolutionaryAlgorithm::test_destructor(void)
{
}


// void test_get_population_size(void) method

void TestEvolutionaryAlgorithm::test_get_population_size(void)
{
   message += "test_get_population_size\n";

   EvolutionaryAlgorithm ea;

   int population_size = ea.get_population_size();

   assert_true(population_size == 0, LOG);
}


// void test_get_population(void) method

void TestEvolutionaryAlgorithm::test_get_population(void)
{
   message += "test_get_population\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);

   ea.set_population_size(4);

   Matrix<double> population = ea.get_population();

   int rows_number = population.get_rows_number();
   int columns_number = population.get_columns_number();

   assert_true(rows_number == 4, LOG);
   assert_true(columns_number == 1, LOG);
}


// void test_get_evaluation(void) method

void TestEvolutionaryAlgorithm::test_get_evaluation(void)
{
   message += "test_get_evaluation\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);

   ea.set_population_size(4);

   Vector<double> evaluation = ea.get_evaluation();

   int size = evaluation.get_size();

   assert_true(size == 4, LOG);
}


// void test_get_fitnesss(void) method

void TestEvolutionaryAlgorithm::test_get_fitness(void)
{
   message += "test_get_fitnesss\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);

   ea.set_population_size(4);

   Vector<double> fitness = ea.get_fitness();

   int size = fitness.get_size();

   assert_true(size == 4, LOG);
}


// void test_get_selection(void) method

void TestEvolutionaryAlgorithm::test_get_selection(void)
{
   message += "test_get_selection\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);

   ea.set_population_size(4);

   Vector<bool> selection = ea.get_selection();

   int size = selection.get_size();

   assert_true(size == 4, LOG);
}


// void test_get_selective_pressure(void) method

void TestEvolutionaryAlgorithm::test_get_selective_pressure(void)
{
   message += "test_get_selective_pressure\n";

   EvolutionaryAlgorithm ea;

   ea.set_fitness_assignment_method(EvolutionaryAlgorithm::LinearRanking);

   ea.set_selective_pressure(1.0);

   assert_true(ea.get_selective_pressure() == 1.0, LOG);
}


// void test_get_recombination_size(void) method

void TestEvolutionaryAlgorithm::test_get_recombination_size(void)
{
   message += "test_get_recombination_size\n";

   EvolutionaryAlgorithm ea;

   ea.set_recombination_size(0.0);

   assert_true(ea.get_recombination_size() == 0.0, LOG);
}


// void test_get_mutation_rate(void) method

void TestEvolutionaryAlgorithm::test_get_mutation_rate(void)
{
   message += "test_get_mutation_rate\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_rate(0.0);

   assert_true(ea.get_mutation_rate() == 0.0, LOG);
}


// void test_get_mutation_range(void) method

void TestEvolutionaryAlgorithm::test_get_mutation_range(void)
{
   message += "test_get_mutation_range\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_range(0.0);

   assert_true(ea.get_mutation_range() == 0.0, LOG);
}


// void test_get_maximum_generations_number(void) method

void TestEvolutionaryAlgorithm::test_get_maximum_generations_number(void)
{
   message += "test_get_maximum_generations_number\n";

   EvolutionaryAlgorithm ea;

   ea.set_maximum_generations_number(1);

   assert_true(ea.get_maximum_generations_number() == 1, LOG);
}


// void test_get_reserve_population_history(void) method

void TestEvolutionaryAlgorithm::test_get_reserve_population_history(void)
{
   message += "test_get_reserve_population_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_population_history(true);

   assert_true(ea.get_reserve_population_history() == true, LOG);

   ea.set_reserve_population_history(false);

   assert_true(ea.get_reserve_population_history() == false, LOG);
}


// void test_get_reserve_mean_norm_history(void) method

void TestEvolutionaryAlgorithm::test_get_reserve_mean_norm_history(void)
{
   message += "test_get_reserve_mean_norm_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_mean_norm_history(true);

   assert_true(ea.get_reserve_mean_norm_history() == true, LOG);

   ea.set_reserve_mean_norm_history(false);

   assert_true(ea.get_reserve_mean_norm_history() == false, LOG);
}


// void test_get_reserve_standard_deviation_norm_history(void) method

void TestEvolutionaryAlgorithm::test_get_reserve_standard_deviation_norm_history(void)
{
   message += "test_get_reserve_standard_deviation_norm_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_standard_deviation_norm_history(true);

   assert_true(ea.get_reserve_standard_deviation_norm_history() == true, LOG);

   ea.set_reserve_standard_deviation_norm_history(false);

   assert_true(ea.get_reserve_standard_deviation_norm_history() == false, LOG);
}


// void test_get_reserve_best_norm_history(void) method

void TestEvolutionaryAlgorithm::test_get_reserve_best_norm_history(void)
{
   message += "test_get_reserve_best_norm_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_best_norm_history(true);

   assert_true(ea.get_reserve_best_norm_history() == true, LOG);

   ea.set_reserve_best_norm_history(false);

   assert_true(ea.get_reserve_best_norm_history() == false, LOG);
}


// void test_get_reserve_mean_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_get_reserve_mean_evaluation_history(void)
{
   message += "test_get_reserve_mean_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_mean_evaluation_history(true);

   assert_true(ea.get_reserve_mean_evaluation_history() == true, LOG);

   ea.set_reserve_mean_evaluation_history(false);

   assert_true(ea.get_reserve_mean_evaluation_history() == false, LOG);
}


// void test_get_reserve_standard_deviation_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_get_reserve_standard_deviation_evaluation_history(void)
{
   message += "test_get_reserve_standard_deviation_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_standard_deviation_evaluation_history(true);

   assert_true(ea.get_reserve_standard_deviation_evaluation_history() == true, LOG);

   ea.set_reserve_standard_deviation_evaluation_history(false);

   assert_true(ea.get_reserve_standard_deviation_evaluation_history() == false, LOG);
}


// void test_get_reserve_best_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_get_reserve_best_evaluation_history(void)
{
   message += "test_get_reserve_best_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_best_evaluation_history(true);

   assert_true(ea.get_reserve_best_evaluation_history() == true, LOG);

   ea.set_reserve_best_evaluation_history(false);

   assert_true(ea.get_reserve_best_evaluation_history() == false, LOG);
}


// void test_get_population_history(void) method

void TestEvolutionaryAlgorithm::test_get_population_history(void)
{
   message += "test_get_population_history\n";

   EvolutionaryAlgorithm ea;

   Vector< Matrix<double> > population_history = ea.get_population_history();

   assert_true(population_history.get_size() == 0, LOG);
}


// void test_get_mean_norm_history(void) method

void TestEvolutionaryAlgorithm::test_get_mean_norm_history(void)
{
   message += "test_get_mean_norm_history\n";

   EvolutionaryAlgorithm ea;

   Vector<double> mean_norm_history = ea.get_mean_norm_history();

   assert_true(mean_norm_history.get_size() == 0, LOG);
}


// void test_get_standard_deviation_norm_history(void) method

void TestEvolutionaryAlgorithm::test_get_standard_deviation_norm_history(void)
{
   message += "test_get_standard_deviation_norm_history\n";

   EvolutionaryAlgorithm ea;

   Vector<double> standard_deviation_norm_history = ea.get_standard_deviation_norm_history();

   assert_true(standard_deviation_norm_history.get_size() == 0, LOG);
}


// void test_get_best_norm_history(void) method

void TestEvolutionaryAlgorithm::test_get_best_norm_history(void)
{
   message += "test_get_best_norm_history\n";

   EvolutionaryAlgorithm ea;

   Vector<double> best_norm_history = ea.get_best_norm_history();

   assert_true(best_norm_history.get_size() == 0, LOG);
}


// void test_get_mean_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_get_mean_evaluation_history(void)
{
   message += "test_get_mean_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   Vector<double> mean_evaluation_history = ea.get_mean_evaluation_history();

   assert_true(mean_evaluation_history.get_size() == 0, LOG);
}


// void test_get_standard_deviation_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_get_standard_deviation_evaluation_history(void)
{
   message += "test_get_standard_deviation_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   Vector<double> standard_deviation_evaluation_history = ea.get_standard_deviation_evaluation_history();

   assert_true(standard_deviation_evaluation_history.get_size() == 0, LOG);
}


// void test_get_best_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_get_best_evaluation_history(void)
{
   message += "test_get_best_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   Vector<double> best_evaluation_history = ea.get_best_evaluation_history();

   assert_true(best_evaluation_history.get_size() == 0, LOG);
}


// void test_get_fitness_assignment_method(void) method

void TestEvolutionaryAlgorithm::test_get_fitness_assignment_method(void)
{
   message += "test_get_fitness_assignment_method\n";

   EvolutionaryAlgorithm ea;

   ea.set_fitness_assignment_method(EvolutionaryAlgorithm::LinearRanking);
  
   assert_true(ea.get_fitness_assignment_method() == EvolutionaryAlgorithm::LinearRanking, LOG);
}


// void test_get_selection_method(void) method

void TestEvolutionaryAlgorithm::test_get_selection_method(void)
{
   message += "test_get_selection_method\n";

   EvolutionaryAlgorithm ea;

   ea.set_selection_method(EvolutionaryAlgorithm::RouletteWheel);
  
   assert_true(ea.get_selection_method() == EvolutionaryAlgorithm::RouletteWheel, LOG);

   ea.set_selection_method(EvolutionaryAlgorithm::StochasticUniversalSampling);
  
   assert_true(ea.get_selection_method() == EvolutionaryAlgorithm::StochasticUniversalSampling, LOG);
}


// void test_get_recombination_method(void) method

void TestEvolutionaryAlgorithm::test_get_recombination_method(void)
{
   message += "test_get_recombination_method\n";

   EvolutionaryAlgorithm ea;

   ea.set_recombination_method(EvolutionaryAlgorithm::Line);
  
   assert_true(ea.get_recombination_method() == EvolutionaryAlgorithm::Line, LOG);

   ea.set_recombination_method(EvolutionaryAlgorithm::Intermediate);
  
   assert_true(ea.get_recombination_method() == EvolutionaryAlgorithm::Intermediate, LOG);
}


// void test_get_mutation_method(void) method

void TestEvolutionaryAlgorithm::test_get_mutation_method(void)
{
   message += "test_get_mutation_method\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_method(EvolutionaryAlgorithm::Normal);
  
   assert_true(ea.get_mutation_method() == EvolutionaryAlgorithm::Normal, LOG);

   ea.set_mutation_method(EvolutionaryAlgorithm::Uniform);
  
   assert_true(ea.get_mutation_method() == EvolutionaryAlgorithm::Uniform, LOG);
}


// void test_set(void) method

void TestEvolutionaryAlgorithm::test_set(void)
{
   message += "test_set\n";

}

// void test_set_default(void) method

void TestEvolutionaryAlgorithm::test_set_default(void)
{
   message += "test_set_default\n";

   MultilayerPerceptron mlp;
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);

   // Test
   
   ea.set_default();
   assert_true(ea.get_population_size() == 0, LOG);

   // Test

   mlp.set(1);
   ea.set_default();
   assert_true(ea.get_population_size() == 10, LOG);
}


// void test_set_population_size(void) method

void TestEvolutionaryAlgorithm::test_set_population_size(void)
{
   message += "test_set_population_size\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);
   
   ea.set_population_size(4);

   assert_true(ea.get_population_size() == 4, LOG);
}


// void test_set_population(void) method

void TestEvolutionaryAlgorithm::test_set_population(void)
{
   message += "test_set_population\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);

   ea.set_population_size(4);

   int parameters_number = mlp.get_parameters_number();
   int population_size = ea.get_population_size();

   Matrix<double> population(population_size, parameters_number, 0.0);   

   ea.set_population(population);

   assert_true(ea.get_population() == 0.0, LOG);
}


// void test_set_evaluation(void) method

void TestEvolutionaryAlgorithm::test_set_evaluation(void)
{
   message += "test_set_evaluation\n";

   EvolutionaryAlgorithm ea;

   Vector<double> evaluation;

   ea.set_evaluation(evaluation);

   assert_true(ea.get_evaluation() == 0.0, LOG);
}


// void test_set_fitness(void) method

void TestEvolutionaryAlgorithm::test_set_fitness(void)
{
   message += "test_set_fitness\n";

   EvolutionaryAlgorithm ea;

   Vector<double> fitness;

   ea.set_fitness(fitness);

   assert_true(ea.get_fitness() == 0.0, LOG);
}


// void test_set_selection(void) method

void TestEvolutionaryAlgorithm::test_set_selection(void)
{
   message += "test_set_selection\n";

   EvolutionaryAlgorithm ea;

   Vector<double> selection;

   ea.set_fitness(selection);

   assert_true(ea.get_selection() == 0.0, LOG);
}


// void test_set_selective_pressure(void) method

void TestEvolutionaryAlgorithm::test_set_selective_pressure(void)
{
   message += "test_set_selective_pressure\n";

   EvolutionaryAlgorithm ea;

   ea.set_selective_pressure(1.0);

   assert_true(ea.get_selective_pressure() == 1.0, LOG);
}


// void test_set_recombination_size(void) method

void TestEvolutionaryAlgorithm::test_set_recombination_size(void)
{
   message += "test_set_recombination_size\n";

   EvolutionaryAlgorithm ea;

   ea.set_recombination_size(0.0);

   assert_true(ea.get_recombination_size() == 0.0, LOG);
}


// void test_set_mutation_rate(void) method

void TestEvolutionaryAlgorithm::test_set_mutation_rate(void)
{
   message += "test_set_mutation_rate\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_rate(0.0);

   assert_true(ea.get_mutation_rate() == 0.0, LOG);
}


// void test_set_mutation_range(void) method

void TestEvolutionaryAlgorithm::test_set_mutation_range(void)
{
   message += "test_set_mutation_range\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_range(0.0);

   assert_true(ea.get_mutation_range() == 0.0, LOG);
}


// void test_set_maximum_generations_number(void) method

void TestEvolutionaryAlgorithm::test_set_maximum_generations_number(void)
{
   message += "test_set_maximum_generations_number\n";

   EvolutionaryAlgorithm ea;

   ea.set_maximum_generations_number(1);

   assert_true(ea.get_maximum_generations_number() == 1, LOG);
}


// void test_set_mean_evaluation_goal(void) method

void TestEvolutionaryAlgorithm::test_set_mean_evaluation_goal(void)
{
   message += "test_set_mean_evaluation_goal\n";

   EvolutionaryAlgorithm ea;

   ea.set_mean_evaluation_goal(1.0);

   assert_true(ea.get_mean_evaluation_goal() == 1.0, LOG);
}


// void test_set_standard_deviation_evaluation_goal(void) method

void TestEvolutionaryAlgorithm::test_set_standard_deviation_evaluation_goal(void)
{
   message += "test_set_standard_deviation_evaluation_goal\n";

   EvolutionaryAlgorithm ea;

   ea.set_standard_deviation_evaluation_goal(1.0);

   assert_true(ea.get_standard_deviation_evaluation_goal() == 1.0, LOG);
}


// void test_set_fitness_assignment_method(void) method

void TestEvolutionaryAlgorithm::test_set_fitness_assignment_method(void)
{
   message += "test_set_fitness_assignment_method\n";
}


// void test_set_selection_method(void) method

void TestEvolutionaryAlgorithm::test_set_selection_method(void)
{
   message += "test_set_selection_method\n";
}


// void test_set_recombination_method(void) method

void TestEvolutionaryAlgorithm::test_set_recombination_method(void)
{
   message += "test_set_recombination_method\n";
}


// void test_set_mutation_method(void) method

void TestEvolutionaryAlgorithm::test_set_mutation_method(void)
{
   message += "test_set_mutation_method\n";
}


// void test_set_reserve_population_history(void) method

void TestEvolutionaryAlgorithm::test_set_reserve_population_history(void)
{
   message += "test_set_reserve_population_history\n";
}


// void test_set_reserve_mean_norm_history(void) method

void TestEvolutionaryAlgorithm::test_set_reserve_mean_norm_history(void)
{
   message += "test_set_reserve_mean_norm_history\n";
}


// void test_set_reserve_standard_deviation_norm_history(void) method

void TestEvolutionaryAlgorithm::test_set_reserve_standard_deviation_norm_history(void)
{
   message += "test_set_reserve_standard_deviation_norm_history\n";
}


// void test_set_reserve_best_norm_history(void) method

void TestEvolutionaryAlgorithm::test_set_reserve_best_norm_history(void)
{
   message += "test_set_reserve_best_norm_history\n";
}


// void test_set_reserve_mean_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_set_reserve_mean_evaluation_history(void)
{
   message += "test_set_reserve_mean_evaluation_history\n";
}


// void test_set_reserve_standard_deviation_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_set_reserve_standard_deviation_evaluation_history(void)
{
   message += "test_set_reserve_standard_deviation_evaluation_history\n";
}


// void test_set_reserve_best_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_set_reserve_best_evaluation_history(void)
{
   message += "test_set_reserve_best_evaluation_history\n";
}


// void test_set_population_history(void) method

void TestEvolutionaryAlgorithm::test_set_population_history(void)
{
   message += "test_set_population_history\n";
}


// void test_set_mean_norm_history(void) method

void TestEvolutionaryAlgorithm::test_set_mean_norm_history(void)
{
   message += "test_set_mean_norm_history\n";
}


// void test_set_standard_deviation_norm_history(void) method

void TestEvolutionaryAlgorithm::test_set_standard_deviation_norm_history(void)
{
   message += "test_set_standard_deviation_norm_history\n";
}


// void test_set_best_norm_history(void) method

void TestEvolutionaryAlgorithm::test_set_best_norm_history(void)
{
   message += "test_set_best_norm_history\n";
}


// void test_set_mean_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_set_mean_evaluation_history(void)
{
   message += "test_set_mean_evaluation_history\n";
}


// void test_set_standard_deviation_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_set_standard_deviation_evaluation_history(void)
{
   message += "test_set_standard_deviation_evaluation_history\n";
}


// void test_set_best_evaluation_history(void) method

void TestEvolutionaryAlgorithm::test_set_best_evaluation_history(void)
{
   message += "test_set_best_evaluation_history\n";
}


// void test_get_individual(void) method

void TestEvolutionaryAlgorithm::test_get_individual(void)
{
   message += "test_get_individual\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);

   ea.initialize_population(0.0);

   assert_true(ea.get_individual(0) == 0.0, LOG);
}


// void test_set_individual(void) method

void TestEvolutionaryAlgorithm::test_set_individual(void)
{
   message += "test_set_individual\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);

   Vector<double> individual(1, 0.0);

   ea.set_individual(0, individual);

   assert_true(ea.get_individual(0) == 0.0, LOG);
}


// void test_initialize_population_uniform(void) method

void TestEvolutionaryAlgorithm::test_initialize_population_uniform(void)
{
   message += "test_initialize_population_uniform\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);
   
   ea.initialize_population_uniform();

   Matrix<double> population = ea.get_population();

   assert_true(population >=-1  && population <= 1.0, LOG);
}


// void test_initialize_population_normal(void) method

void TestEvolutionaryAlgorithm::test_initialize_population_normal(void)
{
   message += "test_initialize_population_normal\n";
}


// void test_calculate_population_norm(void) method

void TestEvolutionaryAlgorithm::test_calculate_population_norm(void)
{
   message += "test_calculate_population_norm\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);
   
   ea.initialize_population(0.0);

   assert_true(ea.calculate_population_norm() == 0.0, LOG);
}


// void test_evaluate_population(void) method

void TestEvolutionaryAlgorithm::test_evaluate_population(void)
{
   message += "test_evaluate_population\n";

   MultilayerPerceptron mlp(1);
   MockObjectiveFunctional mof(&mlp);
   EvolutionaryAlgorithm ea(&mof);
   
   ea.initialize_population(0.0);

   ea.evaluate_population();

   assert_true(ea.get_evaluation() == 0.0, LOG);
}


// void test_perform_linear_ranking_fitness_assignment(void) method

void TestEvolutionaryAlgorithm::test_perform_linear_ranking_fitness_assignment(void)
{
   message += "test_perform_linear_ranking_fitness_assignment\n";
}


// void test_perform_roulette_wheel_selection(void) method

void TestEvolutionaryAlgorithm::test_perform_roulette_wheel_selection(void)
{
   message += "test_perform_roulette_wheel_selection\n";
}


// void test_perform_stochastic_universal_sampling_selection(void) method

void TestEvolutionaryAlgorithm::test_perform_stochastic_universal_sampling_selection(void)
{
   message += "test_perform_stochastic_universal_sampling_selection\n";
}


// void test_perform_intermediate_recombination(void) method

void TestEvolutionaryAlgorithm::test_perform_intermediate_recombination(void)
{
   message += "test_perform_intermediate_recombination\n";
}


// void test_perform_line_recombination(void) method

void TestEvolutionaryAlgorithm::test_perform_line_recombination(void)
{
   message += "test_perform_line_recombination\n";
}


// void test_perform_normal_mutation(void) method

void TestEvolutionaryAlgorithm::test_perform_normal_mutation(void)
{
   message += "test_perform_normal_mutation\n";
}


// void test_perform_uniform_mutation(void) method

void TestEvolutionaryAlgorithm::test_perform_uniform_mutation(void)
{
   message += "test_perform_uniform_mutation\n";
}


// void test_train(void) method

void TestEvolutionaryAlgorithm::test_train(void)
{
   message += "test_train\n";

   MultilayerPerceptron mlp(1);

   MockObjectiveFunctional mof(&mlp);

   EvolutionaryAlgorithm ea(&mof);

   mlp.initialize_independent_parameters(-1.0);

   double old_evaluation = mof.calculate_evaluation();

   ea.set_display(false);
   ea.set_maximum_epochs_number(1),
   ea.train();

   double evaluation = mof.calculate_evaluation();

   assert_true(evaluation < old_evaluation, LOG);

   // Evaluation goal

   ea.initialize_population(10.0);

   double evaluation_goal = 1.0;

   ea.set_evaluation_goal(evaluation_goal);
   ea.set_mean_evaluation_goal(0.0);
   ea.set_standard_deviation_evaluation_goal(0.0);
   ea.set_maximum_generations_number(1000);
   ea.set_maximum_time(1000.0);

   ea.train();

   evaluation = mof.calculate_evaluation();

   assert_true(evaluation < evaluation_goal, LOG);

   // Mean evaluation goal
   
   ea.initialize_population_uniform(-10.0, 10.0);

   double mean_evaluation_goal = 1.0;

   ea.set_evaluation_goal(0.0);
   ea.set_mean_evaluation_goal(mean_evaluation_goal);
   ea.set_standard_deviation_evaluation_goal(0.0);
   ea.set_maximum_generations_number(1000);
   ea.set_maximum_time(1000.0);

   ea.train();

   double mean_evaluation = ea.calculate_mean_evaluation();

   assert_true(mean_evaluation < mean_evaluation_goal, LOG);

   // Standard deviation evaluation goal

   ea.initialize_population(10.0);

   double standard_deviation_evaluation_goal = 1.0;

   ea.set_evaluation_goal(0.0);
   ea.set_mean_evaluation_goal(0.0);
   ea.set_standard_deviation_evaluation_goal(standard_deviation_evaluation_goal);
   ea.set_maximum_generations_number(1000);
   ea.set_maximum_time(1000.0);

   ea.train();

   double standard_deviation_evaluation = ea.calculate_standard_deviation_evaluation();

   assert_true(standard_deviation_evaluation < standard_deviation_evaluation_goal, LOG);  
}


// void test_resize_training_history(void) method

void TestEvolutionaryAlgorithm::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   EvolutionaryAlgorithm ea;
   ea.resize_training_history(1);
   ea.resize_training_history(0);
}


// void test_to_XML(void) method

void TestEvolutionaryAlgorithm::test_to_XML(void)
{
   message += "test_to_XML\n";

   EvolutionaryAlgorithm ea;
   std::string object = ea.to_XML(true);

   //std::cout << object << std::endl;
}


// void test_load(void) method

void TestEvolutionaryAlgorithm::test_load(void)
{
   message += "test_load\n";

   EvolutionaryAlgorithm ea;
   ea.save("../Data/EvolutionaryAlgorithm.dat");
   ea.load("../Data/EvolutionaryAlgorithm.dat");

   MockObjectiveFunctional mof;
   ea.set_objective_functional_pointer(&mof);

   ea.save("../Data/EvolutionaryAlgorithm.dat");
   ea.load("../Data/EvolutionaryAlgorithm.dat");

   MultilayerPerceptron mlp(1);
   mof.set_multilayer_perceptron_pointer(&mlp);

   ea.save("../Data/EvolutionaryAlgorithm.dat");
   ea.load("../Data/EvolutionaryAlgorithm.dat");
}


// void test_set_reserve_all_training_history(void) method

void TestEvolutionaryAlgorithm::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   EvolutionaryAlgorithm ea;
   ea.set_reserve_all_training_history(true);
}


// void test_get_training_history_XML(void) method

void TestEvolutionaryAlgorithm::test_get_training_history_XML(void)
{
   message += "test_get_training_history_XML\n";

   MultilayerPerceptron mlp(2);

   MockObjectiveFunctional mof(&mlp);

   EvolutionaryAlgorithm ea(&mof);

   ea.set_maximum_generations_number(2);

   ea.set_reserve_all_training_history(true);

   ea.set_display(false);

   ea.train();
   
   ea.save_training_history("../Data/TrainingHistory.dat");
}


// void run_test_case(void) method

void TestEvolutionaryAlgorithm::run_test_case(void)
{
   message += "Running evolutionary algorithm test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Population methods

   test_get_population_size();

   test_get_population();

   test_get_evaluation();
   test_get_fitness();
   test_get_selection();

   // Training operators

   test_get_fitness_assignment_method();
   test_get_selection_method();
   test_get_recombination_method();
   test_get_mutation_method();

   // Training

   test_get_selective_pressure();
   test_get_recombination_size();
   test_get_mutation_rate();
   test_get_mutation_range();

   test_get_maximum_generations_number();

   test_get_reserve_population_history();
   test_get_reserve_mean_norm_history();
   test_get_reserve_standard_deviation_norm_history();
   test_get_reserve_best_norm_history();
   test_get_reserve_mean_evaluation_history();
   test_get_reserve_standard_deviation_evaluation_history();
   test_get_reserve_best_evaluation_history();

   test_get_population_history();

   test_get_mean_norm_history();
   test_get_standard_deviation_norm_history();
   test_get_best_norm_history();

   test_get_mean_evaluation_history();
   test_get_standard_deviation_evaluation_history();
   test_get_best_evaluation_history();

   // Set methods

   test_set();
   test_set_default();

   test_set_population_size();

   test_set_population();

   test_set_evaluation();
   test_set_fitness();
   test_set_selection();

   test_set_selective_pressure();
   test_set_recombination_size();

   test_set_mutation_rate();
   test_set_mutation_range();

   test_set_maximum_generations_number();
   test_set_mean_evaluation_goal();
   test_set_standard_deviation_evaluation_goal();

   test_set_fitness_assignment_method();
   test_set_selection_method();
   test_set_recombination_method();
   test_set_mutation_method();

   test_set_reserve_population_history();
   test_set_reserve_mean_norm_history();
   test_set_reserve_standard_deviation_norm_history();
   test_set_reserve_best_norm_history();
   test_set_reserve_mean_evaluation_history();
   test_set_reserve_standard_deviation_evaluation_history();
   test_set_reserve_best_evaluation_history();

   test_set_reserve_all_training_history();

   test_set_population_history();

   test_set_mean_norm_history();
   test_set_standard_deviation_norm_history();
   test_set_best_norm_history();

   test_set_mean_evaluation_history();
   test_set_standard_deviation_evaluation_history();
   test_set_best_evaluation_history();

   // Population methods

   test_get_individual();
   test_set_individual();

   test_initialize_population_uniform();
   test_initialize_population_normal();

   test_calculate_population_norm();

   // Population evaluation methods

   test_evaluate_population();

   // Fitness assignment methods

   test_perform_linear_ranking_fitness_assignment();

   // Selection methods

   test_perform_roulette_wheel_selection();
   test_perform_stochastic_universal_sampling_selection();

   // Recombination methods

   test_perform_intermediate_recombination();
   test_perform_line_recombination();

   // Mutation methods

   test_perform_normal_mutation();
   test_perform_uniform_mutation();

   // Train methods

   test_train();

   // Training history methods

   test_resize_training_history();
   test_get_training_history_XML();

   // Utility methods

   test_to_XML();

   test_load();

   message += "End of evolutionary algorithm test case\n";
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
