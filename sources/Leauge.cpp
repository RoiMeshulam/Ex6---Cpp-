#include <iostream>
#include "Leauge.hpp"
int const MAXTEAMS = 20;
double const SCOREBONUS = 0.005;
using namespace std;

namespace ariel{

    Leauge::Leauge(){
        this->leaugeEnd = false;
        for (int i = 0; i < MAXTEAMS; ++i) {
            string newName = "randomTeam";
            newName+=to_string(i);
            this->allTeams.push_back(new Team(newName,0.5));
        }
    }
    Leauge::Leauge(vector<Team*> teams){
        if (teams.size()>20){
            throw invalid_argument("Too much teams\n");
        }
        this->leaugeEnd = false;
        for (unsigned int i = 0; i < teams.size(); ++i) {
            this->allTeams.push_back(teams.at(i));
        }
        int i = 0;
        while(teams.size() < MAXTEAMS){
            string newName = "randomTeam";
            newName+=to_string(i);
            this->allTeams.push_back(new Team(newName,0.5));
            i++;
        }
    }

    Leauge::~Leauge() {
        for (int i = (int)allTeams.size() - 1; i >= 0; --i) {
            delete allTeams.at((unsigned int)i);
        }
    }

    void Leauge::startLeauge(){
        Schedule* sch = new Schedule(this->allTeams);
        vector<Game*> games = sch->makeSchedule();
        for (unsigned int i = 0; i < games.size(); ++i) {
            games.at(i)->startGame();
        }
        this->leaugeEnd = true;
        fixLeauge();

    }

    void Leauge::fixLeauge(){
        if (!this->leaugeEnd){
            throw invalid_argument("Cant do leauge functions as long as leauge didnt start\n");
        }
        for (unsigned int i = 0; i < MAXTEAMS; ++i) {
            this->allTeams.at(i)->score = this->allTeams.at(i)->wins + SCOREBONUS*(this->allTeams.at(i)->scorePts -this->allTeams.at(i)->sufferedPts);
        }
        //SORT USING THE TEAM SCORE
        for (size_t i = 0; i < this->allTeams.size() - 1; ++i) {
            for (size_t j = 0; j < this->allTeams.size() - i - 1; ++j) {
                if (this->allTeams.at(j)->score < this->allTeams.at(j + 1)->score)
                    std::swap(this->allTeams.at(j), this->allTeams.at(j + 1));
            }
        }
    }
    void Leauge::printLeauge(int limit){
        if (!this->leaugeEnd){
            throw invalid_argument("Cant do leauge functions as long as leauge didnt start\n");
        }
        std::cout << "Leauge Ranking" << std::endl;
        for (unsigned int i = 0; i < limit; ++i) {
            std::cout << i+1 << ") " << this->allTeams.at(i)->name << " Wins-Loses: " << this->allTeams.at(i)->wins
                      << "-" << this->allTeams.at(i)->loses << " TOTAL SCORE: " << this->allTeams.at(i)->score << std::endl;
        }
        int maxWINS = 0;
        Team* maxWin;
        int maxLOSES = 0;
        Team* maxLose;
        for (unsigned int i = 0; i < MAXTEAMS; ++i){
            if(this->allTeams.at(i)->bestWinSpree > maxWINS){
                maxWINS = this->allTeams.at(i)->bestWinSpree;
                maxWin = this->allTeams.at(i);
            }
            if(this->allTeams.at(i)->worstLoseSpree > maxLOSES){
                maxLOSES = this->allTeams.at(i)->worstLoseSpree;
                maxLose = this->allTeams.at(i);
            }
        }
        std::cout << "Leauge Statistics Analysis" << std::endl;
        std::cout << "Biggest win spree-" << maxWin->name << " " << maxWINS << " spree" << std::endl;
        std::cout << "Biggest lose spree-" << maxLose->name << " " << maxLOSES << " spree" << std::endl;
        std::cout << "Teams with more buckets than suffered" << std::endl;
        for (unsigned int i = 0; i < MAXTEAMS; ++i) {
            if(this->allTeams.at(i)->scorePts - this->allTeams.at(i)->sufferedPts > 0){
                std::cout << this->allTeams.at(i)->name  << std::endl;
            }
        }
    }

}