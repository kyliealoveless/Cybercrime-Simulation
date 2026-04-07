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

}

void Person::applyFinancialLoss(double amount){
    // as different cybercrimes are impacting individuals, a potential financial loss will be added to their role. An event such as job loss will additionally contribute to financial loss.

}

void Person::increaseStress(double amount){
    // as cybercrimes and events impact individuals, their stress will increase by 0.1
    // maybe there could be something that gives an alert when an individual's stress has maxed out

}

void Person::decreaseTrust(double amount){
    // as cybercrimes impact individuals, their trust in digital systems will decrease by a certain amount (unknown amount)

}

void Person::recoverOneMonth(){
    // if another event occurs to this individual, recovery time will increase by one month to simulate real social harm

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
    this->financial_loss = amount;
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

