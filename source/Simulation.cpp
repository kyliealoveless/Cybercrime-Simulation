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

void Simulation::assignConnections(){
    // this is where I will assign the connections for each individual. This is critical for the ripple effect and showing how cybercrime affects more than just the direct victim

    // each individual will have a range of 5-10 connections. The range will be randomized per individual.

    for (int i = 0; i < population.size(); i++) {
        int num_connections = rand() % 6 + 5; // random number between 5 and 10
        vector<int> connections;

        for (int j = 0; j < num_connections; j++) {
            int connection_id = rand() % population.size(); // random connection from the population
            connections.push_back(connection_id);
        }

        population[i].setConnectedPeople(connections); // setting the connections for the individual
    }
}

void Simulation::triggerCyberCrime(){
    // targets 3% of the population
    // randomized types of cyber crime (one must impact each individual assigned role: creators, individuals, employee, elderly)
    // cyber crimes will consist of Malware, Phishing scams, piracy, and data breaches
    // Based upon my research, phishing and data breaches are the most common cyber crime. This will affect what percentage the crime might occur. Malware is the next most reported cyber crime leaving piracy last.
    // Keep in mind, this information is limited to REPORTED cyber crimes. Piracy is historically an under-reported crime.
    // Phishing and Data Breaches: 50%
    // Malware: 30%
    // Piracy: 20%

    
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
        // update variables dependant on what cyber crime is triggered
        // if stress level gets to a certain point, job loss can occur. Maybe make it 50%

        // if cybercrime is phising (50%), financial loss is average, stress level increases a lot, trust index increases a lot
        // if cybercrime is data breaches (50%), financial loss is high, stress level increases a lot, trust index increases average
        // if cybercrime is malware (30%), financial loss is moderate, stress level increases a lot, trust index increases slightly (this one affects businesses and employees)
        // if cybercrime is piracy (20%), financial loss is slight to none (unless for creators), stress level increases very slightly, trust index stays the same
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
    // connected people will apply here to show how directly impacted victims affect others

    for (int i = 0; i < population.size(); i++) {

        if (population[i].isDirectlyImpacted()) {
            vector<int> connections = population[i].getConnectedPeople();

            for (int j = 0; j < connections.size(); j++) {

                int connection_id = connections[j];
                // if the directly impacted victim has a connection, that connection will be affected by the ripple effect
                // this is where the social harm is shown and how cybercrime affects more than just the direct victim

                // for example, if a person is directly impacted by a cybercrime, their connections will have a 10% chance of being indirectly impacted. This can be adjusted based on research findings.

           
                int chance = rand() % 100; // random number between 0 and 99

                if (chance < 3) { // 3% chance of being indirectly impacted to simulate the slow spread of cybercrime impact through social connections

                    // applying the ripple effect on the connected individual
                    // the impact will be less severe than the direct victim but still significant to show the social harm of cybercrime
                    double newLoss = population[connection_id].getFinancialLoss() + 100;
                    // updating the connected individual's variables based on the ripple effect
                    population[connection_id].setFinancialLoss(newLoss);
                    population[connection_id].increaseStress(0.1); // this is a moderate increase in stress to show the impact of being connected to a victim of cybercrime
                    population[connection_id].decreaseTrust(0.5); // this is a significant decrease in trust to show the impact of being connected to a victim of cybercrime

                    // mark as impacted
                    if (!population[connection_id].isDirectlyImpacted()) {
                        population[connection_id].setDirectlyImpacted(true);
                    }
                }
            }
        }
    }

}

void Simulation::updateRecovery(){


}

void Simulation::recordSnapShot(int day){

    
// output the snapshots in csv files. This allows easy transition to excel which allows graphing!
// https://stackoverflow.com/questions/25201131/writing-csv-files-from-c#:~:text=6%20Answers,2%2C5121%2019%2025 
// https://www.youtube.com/watch?v=LfiQj_X-pkA 

    file.open("Snapshots.csv");

    if (file.is_open()) {
        // this is the header row:
        file << "Day,Total_Victims,Total_Loss,Avg_Stress,Avg_Trust,Job_Loss" << endl;

        // these are the data rows:
        // examples: 
        // Day 0: snapshot_File << "0,0,0.0,0.0,1.0,0" << endl;
        // Day 30: snapshot_File << "30,40,3300.0,0.3,0.6,2" << endl;

        // I am thinking that to do this I have to include specific variables that are constantly updated

        file << day << "," << total_victims << "," << total_financial_loss << "," << "avg_stress" << "," << "avg_trust" << "," << "job_loss" << endl;

        file.close();
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
    // make it into a csv file

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

    recordSnapShot(0); // initial snapshot before any cybercrime occurs

    for (int day = 30; day <=100; day += 30) {
        rippleEffect(); // applying the ripple effect to show the social harm of cybercrime
        updateRecovery(); // updating the recovery status of individuals based on their recovery time and any additional events that may occur
        recordSnapShot(day); // recording the snapshot at the specified day
    }

}