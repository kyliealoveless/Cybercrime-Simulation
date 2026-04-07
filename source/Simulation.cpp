#include "..\headers\Simulation.h"
#include <fstream>
#include <cstdlib> // for rand()

// Referencing my past Data Structures Final Project "Amusement Park Simulation"

Simulation::Simulation(){
    // constructor
}

void Simulation::initializePopulation(int size){
    // 1000 individuals... as of right now this number will not change
    // this will assign what percentage of he population will get one of the 4 roles

    for (int i = 0; i < size; i++) { // creating the population. I will make sure it is 1000 in main

        string role; // assigning roles throughout the population

        if (i < 500) { // majority will be broad individuals 
            role = "individuals";
        } else if (i < 750) { // next most is the working population taking up majority of the world's population
            role = "employees";
        } else if (i < 900) {
            role = "elderly"; // next will be elderly who are the #1 victim of cyber crime
        } else {
            role = "creators"; // last will represent creators that get affected through the act of piracy
        }
       
        population.push_back(Person(i, role)); // adding the person with their newly assigned role to the population 

    }
    
    
}

void Simulation::triggerCyberCrime(){
    // targets 3% of the population
    // randomized types of cyber crime (one must impact each individual assigned role: creators, individuals, employee, elderly)

    // directly_impacted = 0.03% randomly distributed?
    // for (population of 1000) { /  rand 0.03 by 1000}
    //
    //

    int victims = population.size() * 0.03; // the victims will be 3% of the population

    for (int i = 0; i < victims; i++) {
        // looping through the victims to assign a cyber crime effect on the variables

        // I want to randomize the 3% 
        int random = rand() % population.size();

        // using setters so I can access the private variables
        // applying new values to the variables when they are randomly assigned
        population[random].setDirectlyImpacted(true);
        population[random].setFinancialLoss(500);
        population[random].setStressLevel(0.3);
        population[random].setTrustIndex(-0.2);
    }

    

}

void Simulation::rippleEffect(){
    // 2-5% direct victimization rate per simulated event
    // financial loss will be proportionally scaled based on crime type
    // emotional distress values will be weighted based on literature findings

}

void Simulation::updateRecovery(){


}

void Simulation::recordSnapShot(){

    
// output the snapshots in csv files. This allows easy transition to excel which allows graphing!
// https://stackoverflow.com/questions/25201131/writing-csv-files-from-c#:~:text=6%20Answers,2%2C5121%2019%2025 
// https://www.youtube.com/watch?v=LfiQj_X-pkA 

    ofstream snapshot_File("Snapshots.csv");

    if (snapshot_File.is_open()) {
        // this is the header row:
        snapshot_File << "Day,Total_Victims,Total_Loss,Avg_Stress,Avg_Trust,Job_Loss" << endl;

        // these are the data rows:
        // examples: 
        // Day 0: snapshot_File << "0,0,0.0,0.0,1.0,0" << endl;
        // Day 30: snapshot_File << "30,40,3300.0,0.3,0.6,2" << endl;

        // I am thinking that to do this I have to include specific variables that are constantly updated
    }

    // total_individuals = individuals.size();

    // Day: __
    // Total Victims: __
    // Total Loss: $__
    // Average Stress: __
    // Average Trust: __
    // Job Loss: __

}

void Simulation::runSimulation(int duration, int num_individuals){


    // Include Community Impact Summary

    // Total Days: 180

    // Group: Creators
    // Direct Victims: __
    // Indirect Victims: __
    // Average Stress: __%
    // Average Loss: $__

    // Group: Employees
    // Direct Victims: __
    // Indirect Victims: __
    // Average Stress: __%
    // Average Loss: $__

    // Group: Individuals
    // Direct Victims: __
    // Indirect Victims: __
    // Average Stress: __%
    // Average Loss: $__

    // Group: Elderly
    // Direct Victims: __
    // Indirect Victims: __
    // Average Stress: __%
    // Average Loss: $__

}