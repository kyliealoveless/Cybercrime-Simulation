#include "..\headers\Simulation.h"
#include <fstream>

// Referencing my past Data Structures Final Project "Amusement Park Simulation"

Simulation::Simulation(){
    // constructor
}

void Simulation::initializePopulation(int size){
    // 1000 individuals... as of right now this number will not change

}

void Simulation::triggerCyberCrime(){
    // targets 3% of the population
    // randomized types of cyber crime (one must impact each individual assigned role: creators, individuals, employee, elderly)

    // directly_impacted = 0.03% randomly distributed?
    // for (population of 1000) { /  rand 0.03 by 1000}
    //
    //

    

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