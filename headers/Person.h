// This person class will model the types of harm at the individual level
// There will be 1000 individuals in this simulation
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <vector>
using namespace std; // using this as to not complicate more things and keeping everything basic

class Person {

    private:
        int id; // each individual will have an id for easier tracking and helping create better snapshots
        string role; // each individual will have an role consisting of whether the person is a creator, employee, elder, or individual (meaning public)
        double income; // each individual will have an income depending on what role they are assigned or just a randomized range... its unknown right now
        double stress_level; // each individual obviously will have a stress level that will increase or decrease depending on the experiences they have. This addition is critical for the snapshot being more affective.
        double trust_index; // each individual will have a trust index of digital systems that vary depending on the crime affecting them or people around them
        double financial_loss; // if a cybercrime causes financial loss, this method will be affected. When this method is affected, other variables will follow.
        int recovery_time; // when cybercrime strikes, every individual will be assigned an amount of time it will take them to recover depending on the severity of the crime. If additional factors occur that harms the individual, more time will be added to the recovery time.
        bool directly_impacted; // determines whether the individual is someone directly impacted or further removed from the incident
        vector<int> connected_people; // This vector will add all the people will be indirectly affected by the cybercrime depending on the people they are connected to. (this is me trying to make this as accurate to real life as possible)
            // each individual will have a range of 5-10 connections. The range will be randomized per individual.
        // after conversations with a professor from a different school, I have decided to include risk-based targeting. This means that certain individuals will be more likely to be targeted by cybercrime based on their role and other factors. There are different variables that create a susceptible target such as digital literacy, online exposure, and more. This will be reflected in the simulation by assigning different probabilities of being targeted to different roles. For example, elderly individuals might have a higher probability of being targeted due to lower digital literacy, while creators might have a higher probability due to their online exposure.
        double digital_literacy; // this variable will represent the individual's digital literacy level, which can affect their susceptibility to cybercrime. It will be a value between 0 and 1, with higher values indicating higher digital literacy.
        double online_exposure; // this variable will represent the individual's level of online exposure, which
        double scam_susceptibility; // this variable will represent the individual's susceptibility to scams, which can be influenced by factors such as age, digital literacy, and online behavior. It will be a value between 0 and 1, with higher values indicating higher susceptibility.
        double risk_score; // this variable will represent the individual's overall risk score for being targeted by cybercrime, which can be calculated based on their digital literacy, online exposure, and scam susceptibility. It will be a value between 0 and 1, with higher values indicating higher risk.


    public:
        Person();
        Person(int id, string role);
        double calculateRiskScore(); // this method will calculate the individual's risk score based on their digital literacy, online exposure, and scam susceptibility. The formula for this can be adjusted based on research findings, but for this example, I will use a simple weighted average.
        void applyFinancialLoss(double amount); // when the issue occurs, here is where the financial loss is applied to the individual affected
        void increaseStress(double amount); // when some instance causes more stress to an individual, this is where that is manipulated.
        void decreaseTrust(double amount); // if a person is affected by cybercrime, their trust in digital systems decreases. This is where that is manipulated.
        void recoverOneMonth(); // this allows manipulation of how much time people have to recover, this can either add or decrease depending on the scenario.
        bool isRecovered(); // if a person is recovered from cybercrime, they will be added to a separate section that will allow fro more analysis on that individual

        // setters
        // this is so that I can access these variables because otherwise they are stuck in private
        void setDirectlyImpacted(bool impacted);
        void setFinancialLoss(double amount);
        void setStressLevel(double amount);
        void setTrustIndex(double amount);
        void setConnectedPeople(vector<int> people);
        void setRecoveryTime(int time) {
            recovery_time = time;
        }

        // getters
        int getId();
        string getRole();
        double getIncome();
        double getStressLevel();
        double getTrustIndex();
        double getFinancialLoss();
        int getRecoveryTime();
        bool isDirectlyImpacted();
        vector<int> getConnectedPeople();

};

#endif