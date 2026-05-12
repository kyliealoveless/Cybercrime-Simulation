// this class is incredibly important because it is how the simulation will run and record the much needed snapshots
// I can manipulate how long the simulation is run and how many people are within it
// this simulation will run for 6 months with 1000 people
#ifndef SIMULATION_H  
#define SIMULATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"
using namespace std; // again I don't want to further complex things so I'm utilizing this tool

// in my past Data Structures Final Project "Amusement Park Simulation", we had used enum to define the ticket types. I found that this made the code much easier to read and manage, especially when applying the effects of different ticket typesto the visitors in the park. 
// in this cybercrime simulation, using an enum to define the different types of cybercrime will make it easier to manage and understand the code when applying the effects of different cybercrimes to individuals in the population. It allows for a clear and organized way to represent the different cybercrime types and their associated effects on individuals.
enum CyberCrimeType {
    phishing,
    data_breach,
    malware,
    piracy
};

class Simulation {

    private:
        vector<Person> population; // determining the population of 1000 individuals all assigned to different variables
        int curr_day; // recording what day it is. Critical for the snapshots
        int total_victims; // recording how many victims are in the population right now, also crucial for the snapshots
        double total_financial_loss; // recording what the total financial loss is combining all individuals. The snapshot will deeply benefit from this
        string cybercrime_type; // identifying what type of cybercrime is being used

    public:
        Simulation();
        ofstream final_file; // this is for the final summary, I want to be able to write to a file to record the final results of the simulation
        ofstream file; // this is for the snapshots, I want to be able to write to a file to record the data from the simulation
        void initializePopulation(int size); // how I can manipulate the size of the population. Should stay at 1000 but who knows
        void assignConnections(); // this is where I will assign the connections for each individual. This is critical for the ripple effect and showing how cybercrime affects more than just the direct victim
        void triggerCyberCrime(); // incorporating cybercrimes into the simulation. Without this there is no CYBERCRIME simulation
        void rippleEffect(); // adding a ripple effect into the community. This generates the impact of social harm and furthers the point I will make at the end
        void updateRecovery(); // depending on the individual's situation, their recovery time will be altered
        CyberCrimeType getRandomCyberCrimeType(); // this function will randomly assign a cyber crime type based on the percentages mentioned above
        void applyCrimeEffect(Person &individual); // this is where the specific effects of the cyber crime will be applied to the individual's variables based on the type of cyber crime they are affected by. This will be determined by another randomization process that assigns a cyber crime type to the individual based on the percentages mentioned above.
        void recordSnapShot(int day); // MY FAVORITE ADDITION!! the simulation is running... so what? Here is where the impact is documented (day 0, day 30, day 90, day 180, final results)
        void runSimulation (int duration); // the start button essentially. Also I can manipulate how long the simulation will run for (6 months).
        void finalSummary(); // this will give a final summary of the impact of cybercrime on the community after the simulation is complete
};

#endif