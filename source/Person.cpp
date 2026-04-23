#include "..\headers\Person.h"
#include "Person.h"

Person::Person(){
    // constructor
}

Person::Person(int id, string role){
    // copy constructor
    this->id = id;
    this->role = role;

    // Set the variables to default
    stress_level = 0.0;
    trust_index = 1.0;
    financial_loss = 0.0; // dollars
    recovery_time = 0;
    directly_impacted = false;
    income = 0.0; // I want income to vary based on role 

    // including the risk-based targeting variables
    digital_literacy = (rand() % 100) / 100.0; // random value between 0 and 1
    online_exposure = (rand() % 100) / 100.0; // random value between 0 and 1
    scam_susceptibility = (rand() % 100) / 100.0; // random value between 0 and 1
    // now there needs to be a way to calculate the risk score based on these variables. I will use a simple weighted average for this example, but it can be adjusted based on research findings.

}

double Person::calculateRiskScore(){
    // this method will calculate the individual's risk score based on their digital literacy, online exposure, and scam susceptibility. The formula for this can be adjusted based on research findings, but for this example, I will use a simple weighted average.

    risk_score = (0.4 * (1 - digital_literacy)) + (0.3 * online_exposure) + (0.3 * scam_susceptibility);

    return risk_score;
}

void Person::applyFinancialLoss(double amount){
    // as different cybercrimes are impacting individuals, a potential financial loss will be added to their role. An event such as job loss will additionally contribute to financial loss.

    // different cybercrimes will have different financial impacts

    

}

void Person::increaseStress(double amount){
    // as cybercrimes and events impact individuals, their stress will increase by 0.1
    // maybe there could be something that gives an alert when an individual's stress has maxed out
    stress_level += amount;
    if (stress_level > 1.0) stress_level = 1.0;

}

void Person::decreaseTrust(double amount){
    // as cybercrimes impact individuals, their trust in digital systems will decrease by a certain amount (unknown amount)
    trust_index -= amount;
    if (trust_index < 0.0) trust_index = 0.0;
}

void Person::recoverOneMonth(){
    // if another event occurs to this individual, recovery time will increase by one month to simulate real social harm
    if (recovery_time > 0) {
        recovery_time --;
        
        stress_level *= 0.9; // faster recovery if no additional events occur, this is just an example and can be adjusted based on research findings
        trust_index += 0.02; // slower rebuilding of trust, this is just an example and can be adjusted based on research findings
        
        if (trust_index > 1.0) trust_index = 1.0;
    }
    
}

bool Person::isRecovered(){
    // determining if an individual has recovered from a cybercrime event
    // research shows that recovery takes on average 1 year (the whole point of this inclusion is to prove that cybercrime takes so long to heal that this simulation cannot even prove it)

    // if (individual recovery_time = 0) {
    // isRecovered = true
    // } else {
    // isRecovered = false;
    // }

    if (recovery_time == 0){
        return true;
    } else {
        return false;
    }

}


// setters

void Person::setDirectlyImpacted(bool impacted){
    this->directly_impacted = impacted;
}

void Person::setFinancialLoss(double amount){
    this->financial_loss += amount;
}

void Person::setStressLevel(double amount){
    this->stress_level = amount;
}

void Person::setTrustIndex(double amount){
    this->trust_index = amount;
}

void Person::setConnectedPeople(vector<int> people){
    this->connected_people = people;
}


// getters

int Person::getId(){
    return id;
}

string Person::getRole(){
    return role;
}

double Person::getIncome(){
    return income;
}

double Person::getStressLevel(){
    return stress_level;
}

double Person::getTrustIndex(){
    return trust_index;
}

double Person::getFinancialLoss(){
    return financial_loss;
}

int Person::getRecoveryTime(){
    return recovery_time;
}

bool Person::isDirectlyImpacted(){
    return directly_impacted;
}

vector<int> Person::getConnectedPeople(){
    return connected_people;
}

