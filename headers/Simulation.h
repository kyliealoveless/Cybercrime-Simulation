// this class is incredibly important because it is how the simulation will run and record the much needed snapshots
// I can manipulate how long the simulation is run and how many people are within it
// this simulation will run for 6 months with 1000 people
#ifndef SIMULATION_H  
#define SIMULATION_H

#include <iostream>
#include <vector>
#include "Person.h"
using namespace std; // again I don't want to further complex things so I'm utilizing this tool

class Simulation {

    private:
        vector<Person> population; // determining the population of 1000 individuals all assigned to different variables
        int curr_day; // recording what day it is. Critical for the snapshots
        int total_victims; // recording how many victims are in the population right now, also crucial for the snapshots
        double total_financial_loss; // recording what the total financial loss is combining all individuals. The snapshot will deeply benefit from this

    public:
        Simulation();
        void initializePopulation(int size); // how I can manipulate the size of the population. Should stay at 1000 but who knows
        void triggerCyberCrime(); // incorporating cybercrimes into the simulation. Without this there is no CYBERCRIME simulation
        void RippleEffect(); // adding a ripple effect into the community. This generates the impact of social harm and furthers the point I will make at the end
        void updateRecovery(); // depending on the individual's situation, their recovery time will be altered
        void recordSnapShot(); // MY FAVORITE ADDITION!! the simulation is running... so what? Here is where the impact is documented (day 0, day 30, day 90, day 180, final results)
        void runSimulation (int duration); // the start button essentially. Also I can manipulate how long the simulation will run for (6 months).



};

#endif