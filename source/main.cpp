#include <iostream>
#include "../headers/Simulation.h"
#include <ctime> //needed for random number generation
using namespace std;

int main() {

    srand (time(NULL)); // initializing a seed for random number generation

    cout << "Welcome to my Cyber Crime Simulation!" << endl << endl;
    cout << "The purpose of this simulation is to give a visual representation as to how cyber crime affects a community. Cyber crime has long been viewed as victimless or even centered upon victim-blaming mentality. With this simulation, I will prove how cyber crime is essentially a ripple effect of harm throughout to many different aspects. Though the goal is to make this simulation as accurate as possible, there is a severe underreporting rate due to the nature of these crime causing this simulation to not be 100% accurate." << endl << endl;
    cout << "As this simulation runs there will be snapshots, after a certain amount of time, to show insights into the ripple effect that occurs and the toll the crimes have on the community of 1000 individuals." << endl;
    cout << endl << endl;

    cout << "--------------- Simulation Begins -------------------" << endl;

    // Creating Assignments

    Simulation SocialHarmImpact;
    SocialHarmImpact.initializePopulation(1000);
    SocialHarmImpact.assignConnections();
    remove("Snapshots.csv"); // this is to ensure that every time the simulation is run, the snapshots are reset and not appended to previous runs
    SocialHarmImpact.runSimulation(180, 1000); // running the simulation for 180 days and 1000 individuals
    SocialHarmImpact.finalSummary(); // this will give a final summary of the impact of cybercrime on the community after the simulation is complete
    return 0;


    
}