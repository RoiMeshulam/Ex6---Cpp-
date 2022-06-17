#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Leauge.hpp"
int const MAXTEAM = 20;
using namespace ariel;

int main() {
    vector<Team*> uefaTeam;
    //Im not good at basketball teams so Im making its based on UEFA Champions Leauge
    uefaTeam.push_back(new Team("Real Madrid", 1));
    uefaTeam.push_back(new Team("Bayern Munich", 1));
    uefaTeam.push_back(new Team("Barcelona", 0));
    uefaTeam.push_back(new Team("Manchester UTD", 0.7));
    uefaTeam.push_back(new Team("Juventus", 0.4));
    uefaTeam.push_back(new Team("Milan", 0.5));
    uefaTeam.push_back(new Team("Liverpool", 1));
    uefaTeam.push_back(new Team("Porto", 0.1));
    uefaTeam.push_back(new Team("Benfica", 0.1));
    uefaTeam.push_back(new Team("Ajax", 0.2));
    uefaTeam.push_back(new Team("Chelsea", 0.7));
    uefaTeam.push_back(new Team("Arsenal", 0.4));
    uefaTeam.push_back(new Team("Inter", 0.6));
    uefaTeam.push_back(new Team("Manchester City", 1));
    uefaTeam.push_back(new Team("PSG", 1));
    uefaTeam.push_back(new Team("Atletico Madrid", 0.6));
    uefaTeam.push_back(new Team("Dortmund", 0.5));
    uefaTeam.push_back(new Team("Lyon", 0.3));
    uefaTeam.push_back(new Team("Dynamo Kyiv", 0));
    uefaTeam.push_back(new Team("PSV", 0.1));
    Leauge* l = new Leauge(uefaTeam);
    l->startLeauge();
    l->printLeauge(8);

}