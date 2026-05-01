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
    int victim_count = 0;

    while (victim_count < victims) {
        int i = rand() % population.size(); // random index in the population

        double risk = population[i].calculateRiskScore(); // calculating the individual's risk score based on their digital literacy, online exposure, and scam susceptibility
        double roll = (rand() % 100) / 100.0;

         if (roll < risk) { // if the random roll is less than the individual's risk score, they will be affected by cybercrime
            if (!population[i].isDirectlyImpacted()) {
                population[i].setDirectlyImpacted(true);
                victim_count++; // incrementing the victim count only if the individual was not previously directly impacted
            }
            applyCrimeEffect(population[i]); // applying the specific effects of the cyber crime to the individual's variables based on the type of cyber crime they are affected by
        }
    

        // using setters so I can access the private variables
        // applying new values to the variables when they are randomly assigned
        // update variables dependant on what cyber crime is triggered
        // if stress level gets to a certain point, job loss can occur. Maybe make it 50%

        // if cybercrime is phising (50%), financial loss is average, stress level increases a lot, trust index increases a lot
        // if cybercrime is data breaches (50%), financial loss is high, stress level increases a lot, trust index increases average
        // if cybercrime is malware (30%), financial loss is moderate, stress level increases a lot, trust index increases slightly (this one affects businesses and employees)
        // if cybercrime is piracy (20%), financial loss is slight to none (unless for creators), stress level increases very slightly, trust index stays the same
    }
}

CyberCrimeType Simulation::getRandomCyberCrimeType() {
    int roll = rand() % 100; // random number between 0 and 99

    if (roll < 50) {
        return phising; // 50% chance
    } else if (roll < 80) {
        return data_breach; // 30% chance
    } else if (roll < 90) {
        return malware; // 10% chance
    } else {
        return piracy; // 10% chance
    }
}

// it is important to recognize that the way people are affected by cybercrime differs on different aspects such as the type of cybercrime, the individual's characteristics, and the social connections they have. This is why the ripple effect is so important to include in the simulation because it shows how cybercrime can affect not just the direct victim but also those around them. It also shows how different types of cybercrime can have different impacts on individuals and their social connections. This is critical for understanding the full scope of the harm caused by cybercrime and for developing effective strategies to mitigate that harm.
void Simulation::applyCrimeEffect(Person &individual){ // referencing my past Data Structures Final Project "Amusement Park Simulation", we had a similar function to apply the effects of different ticket types on the visitors in the park. This function will apply the specific effects of the cyber crime to the individual's variables based on the type of cyber crime they are affected by. This will be determined by another randomization process that assigns a cyber crime type to the individual based on the percentages mentioned above.
    CyberCrimeType crime_type = getRandomCyberCrimeType(); // this function will randomly assign a cyber crime type based on the percentages mentioned above

    if (crime_type == phising) {
        individual.applyFinancialLoss(500); // this is an average financial loss for phishing scams
        individual.increaseStress(0.6); // this is a significant increase in stress to show the impact of phishing scams
        individual.decreaseTrust(0.4); // this is a significant decrease in trust to show the impact of phishing scams
        individual.setRecoveryTime(6); // this is an average recovery time for phishing scams in months
    } else if (crime_type == data_breach) {
        individual.applyFinancialLoss(2000); // this is an average financial loss for data breaches
        individual.increaseStress(0.7); // this is a significant increase in stress to show the impact of data breaches
        individual.decreaseTrust(0.3); // this is a significant decrease in trust to show the impact of data breaches
        individual.setRecoveryTime(12); // this is an average recovery time for data breaches in months
    } else if (crime_type == malware) {
        individual.applyFinancialLoss(1000); // this is an average financial loss for malware attacks
        individual.increaseStress(0.5); // this is a significant increase in stress to show the impact of malware attacks
        individual.decreaseTrust(0.2); // this is a moderate decrease in trust to show the impact of malware attacks
        individual.setRecoveryTime(6); // this is an average recovery time for malware attacks in months
    } else if (crime_type == piracy) {
        if (individual.getRole() == "creators") {
            individual.applyFinancialLoss(3000); // this is an average financial loss for creators affected by piracy
            individual.increaseStress(0.2); // this is a moderate increase in stress to show the impact of piracy on creators
        } else {
            individual.applyFinancialLoss(100); // this is a slight financial loss for individuals affected by piracy (such as through identity theft or other related crimes)
            individual.increaseStress(0.1); // this is a slight increase in stress to show the impact of piracy on individuals
            individual.decreaseTrust(0.05); // this is a very slight decrease in trust to show the impact of piracy on individuals
        }
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

           
                double chance = (double)(rand() % 100) / 100.0; // random number between 0 and 1

                if (chance < 0.3) { // 30% chance of being indirectly impacted to simulate the slow spread of cybercrime impact through social connections

                    // applying the ripple effect on the connected individual
                    // the impact will be less severe than the direct victim but still significant to show the social harm of cybercrime
                    population[connection_id].setFinancialLoss(100); // this is a slight financial loss to show the impact of being connected to a victim of cybercrime
                    population[connection_id].increaseStress(0.1); // this is a moderate increase in stress to show the impact of being connected to a victim of cybercrime
                    population[connection_id].decreaseTrust(0.5); // this is a significant decrease in trust to show the impact of being connected to a victim of cybercrime

                    if (population[connection_id].getStressLevel() > 0.7) {
                        population[connection_id].setDirectlyImpacted(true);

                    }
                }
            }
        }
    }
}

void Simulation::updateRecovery(){
    for (int i = 0; i < population.size(); i++) {
        if (population[i].isDirectlyImpacted()) {
            population[i].recoverOneMonth(); // this allows manipulation of how much time people have to recover, this can either add or decrease depending on the scenario.
        }
    }

}

void Simulation::recordSnapShot(int day){

    
// output the snapshots in csv files. This allows easy transition to excel which allows graphing!
// https://stackoverflow.com/questions/25201131/writing-csv-files-from-c#:~:text=6%20Answers,2%2C5121%2019%2025 
// https://www.youtube.com/watch?v=LfiQj_X-pkA 
// https://hyperskill.org/learn/step/37563
// https://cplusplus.com/forum/beginner/101911/

    file.open("Snapshots.csv", ios::app); // open the file in append mode to add new snapshots without overwriting previous ones

    if (file.is_open()) {
        // this is the header row:
        if (day == 0){
            file << "Day,Total_Victims,Total_Loss,Avg_Stress,Avg_Trust,Job_Loss" << endl;
        }
        // these are the data rows:
        // examples: 
        // Day 0: snapshot_File << "0,0,0.0,0.0,1.0,0" << endl;
        // Day 30: snapshot_File << "30,40,3300.0,0.3,0.6,2" << endl;

        // reset totals before calculating
        total_victims = 0;
        total_financial_loss = 0;

        double total_stress = 0.0;
        double total_trust = 0.0;

        // loop through entire population to collect data
        for (int i = 0; i < population.size(); i++) {

            if (population[i].isDirectlyImpacted()) {
                total_victims++;
            }

            total_financial_loss += population[i].getFinancialLoss();
            total_stress += population[i].getStressLevel();
            total_trust += population[i].getTrustIndex();
        }

        // calculate averages
        double avg_stress = total_stress / population.size();
        double avg_trust = total_trust / population.size();

        // write ONE clean row
        file << day << ","
             << total_victims << ","
             << total_financial_loss << ","
             << avg_stress << ","
             << avg_trust << endl;
             // add job loss

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

    for (int day = 30; day <=180; day += 30) {
        triggerCyberCrime(); // triggering cybercrime events to show the impact on the community

        rippleEffect(); // applying the ripple effect to show the social harm of cybercrime
        updateRecovery(); // updating the recovery status of individuals based on their recovery time and any additional events that may occur
        recordSnapShot(day); // recording the snapshot at the specified day
    }

}

void Simulation::finalSummary() { // this will give a final summary of the impact of cybercrime on the community after the simulation is complete


    final_file.open("Final_Summary.csv");

    if (!final_file.is_open()) {
        return;
    }

    final_file << "Group,Direct_Victims,Indirect_Victims,Avg_Stress,Avg_Loss\n";

    // creators summary variables
    int creators_direct = 0;
    int creators_indirect = 0;
    double creators_stress = 0;
    double creators_loss = 0;
    int creators_count = 0;

    // employees summary variables
    int employees_direct = 0;
    int employees_indirect = 0;
    double employees_stress = 0;
    double employees_loss = 0;
    int employees_count = 0;

    // individuals summary variables
    int individuals_direct = 0;
    int individuals_indirect = 0;
    double individuals_stress = 0;
    double individuals_loss = 0;
    int individuals_count = 0;

    // elderly summary variables
    int elderly_direct = 0;
    int elderly_indirect = 0;
    double elderly_stress = 0;
    double elderly_loss = 0;
    int elderly_count = 0;

    // loop through the population to calculate the summary data for each group
    for (int i = 0; i < population.size(); i++) {

        Person p = population[i];

        string role = p.getRole();
        bool direct = p.isDirectlyImpacted();
        bool indirect = (!direct && p.getStressLevel() > 0.3);

        double stress = p.getStressLevel();
        double loss = p.getFinancialLoss();

        // creators will have a higher financial loss and stress level due to the impact of piracy, while individuals will have a lower financial loss and stress level. Employees and elderly will fall somewhere in between depending on the type of cybercrime they were affected by and their individual characteristics.   
        if (role == "creators") {
            creators_count++;
            creators_stress += stress;
            creators_loss += loss;

            if (direct) creators_direct++;
            else if (indirect) creators_indirect++;
        }

        // employees will have a higher financial loss and stress level due to the impact of malware and data breaches, while individuals will have a lower financial loss and stress level. Creators and elderly will fall somewhere in between depending on the type of cybercrime they were affected by and their individual characteristics.
        else if (role == "employees") {
            employees_count++;
            employees_stress += stress;
            employees_loss += loss;

            if (direct) employees_direct++;
            else if (indirect) employees_indirect++;
        }

        // individuals will have a lower financial loss and stress level due to the impact of phishing and piracy, while creators will have a higher financial loss and stress level. Employees and elderly will fall somewhere in between depending on the type of cybercrime they were affected by and their individual characteristics.
        else if (role == "individuals") {
            individuals_count++;
            individuals_stress += stress;
            individuals_loss += loss;

            if (direct) individuals_direct++;
            else if (indirect) individuals_indirect++;
        }

        // elderly will have a higher financial loss and stress level due to the impact of phishing and data breaches, while individuals will have a lower financial loss and stress level. Creators and employees will fall somewhere in between depending on the type of cybercrime they were affected by and their individual characteristics.
        else if (role == "elderly") {
            elderly_count++;
            elderly_stress += stress;
            elderly_loss += loss;

            if (direct) elderly_direct++;
            else if (indirect) elderly_indirect++;
        }
    }

    // csv file output for the final summary

    // this will show the final impact of cybercrime on the community after the simulation is complete, broken down by group. It will show the number of direct and indirect victims, the average stress level, and the average financial loss for each group. This will allow for a clear comparison of how different groups were affected by cybercrime and can help to highlight any disparities in the impact of cybercrime on different segments of the population.
    if (creators_count > 0) {
        final_file << "Creators,"
                   << creators_direct << ","
                   << creators_indirect << ","
                   << (creators_stress / creators_count) << ","
                   << (creators_loss / creators_count) << "\n";
    }

    if (employees_count > 0) {
        final_file << "Employees,"
                   << employees_direct << ","
                   << employees_indirect << ","
                   << (employees_stress / employees_count) << ","
                   << (employees_loss / employees_count) << "\n";
    }

    if (individuals_count > 0) {
        final_file << "Individuals,"
                   << individuals_direct << ","
                   << individuals_indirect << ","
                   << (individuals_stress / individuals_count) << ","
                   << (individuals_loss / individuals_count) << "\n";
    }

    if (elderly_count > 0) {
        final_file << "Elderly,"
                   << elderly_direct << ","
                   << elderly_indirect << ","
                   << (elderly_stress / elderly_count) << ","
                   << (elderly_loss / elderly_count) << "\n";
    }

    final_file.close();
}
