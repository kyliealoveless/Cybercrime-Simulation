#include <iostream>
#include "../headers/Simulation.h"
#include <ctime> //needed for random number generation
using namespace std;

int main() {

    srand (time(NULL)); // initializing a seed for random number generation

    // testing
    cout << "testing person class and its methods" << endl;
    Person test_person(1, "individuals");
    cout << "Initial Stress Level: " << test_person.getStressLevel() << endl;
    cout << "Initial Trust Index: " << test_person.getTrustIndex() << endl;
    test_person.applyFinancialLoss(500);
    cout << "Stress Level after financial loss: " << test_person.getStressLevel() << endl;
    cout << "Trust Index after financial loss: " << test_person.getTrustIndex() << endl;
    test_person.recoverOneMonth();
    cout << "Stress Level after one month of recovery: " << test_person.getStressLevel() << endl;
    cout << "Trust Index after one month of recovery: " << test_person.getTrustIndex() << endl;
    cout << "end test" << endl << endl;

    cout << "Welcome to my Cyber Crime Simulation!" << endl << endl;
    cout << "The purpose of this simulation is to give a visual representation as to how cyber crime affects a community. Cyber crime has long been viewed as victimless or even centered upon victim-blaming mentality. With this simulation, I will prove how cyber crime is essentially a ripple effect of harm throughout to many different aspects. Though the goal is to make this simulation as accurate as possible, there is a severe underreporting rate due to the nature of these crime causing this simulation to not be 100% accurate." << endl << endl;
    cout << "As this simulation runs there will be snapshots, after a certain amount of time, to show insights into the ripple effect that occurs and the toll the crimes have on the community of 1000 individuals." << endl;
    cout << endl << endl;

    cout << "--------------- Simulation Begins -------------------" << endl;

    // Creating Assignments

    Simulation SocialHarmImpact;
    SocialHarmImpact.initializePopulation(1000);
    // testing
    cout << "Population of 1000 individuals created and assigned roles." << endl;

    SocialHarmImpact.assignConnections();
    // testing
    cout << "Connections assigned for each individual." << endl;
    remove("Snapshots.csv"); // this is to ensure that every time the simulation is run, the snapshots are reset and not appended to previous runs
    SocialHarmImpact.runSimulation(180); // running the simulation for 180 days and 1000 individuals
    // testing
    cout << "Simulation ran for 180 days." << endl;
    SocialHarmImpact.finalSummary(); // this will give a final summary of the impact of cybercrime on the community after the simulation is complete
    return 0;



}