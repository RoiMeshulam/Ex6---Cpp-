#ifndef EX6_TEAM_H
#define EX6_TEAM_H

#endif //EX6_TEAM_H
#pragma once
#include <iostream>

using namespace std;
namespace ariel{
    class Team{
    public:
        //Basic Information
        string name; double talent;
        //Statistics Information
        int wins; int loses;
        int currWinSpree; int bestWinSpree;
        int currLoseSpree; int worstLoseSpree;
        bool currState;
        double score;
        int scorePts; int sufferedPts;
        //Constructor
        Team(std::string teamName,double teamTalent){
            if (teamName == "\t" || teamName == "\n" || teamName.empty() || teamName == " " || teamName == "\r"){
                throw std::invalid_argument("Invalid team name\n");
            }
            if (teamTalent<0 || teamTalent>1){
                throw std::invalid_argument("Invalid talent range(Must be in range of [0,1])\n");
            }
            this->name = teamName;
            this->talent = teamTalent;
            this->bestWinSpree = 0;
            this->currWinSpree = 0;
            this->currLoseSpree = 0;
            this->worstLoseSpree = 0;
            this->wins = 0;
            this->loses = 0;
            this->scorePts = 0;
            this->sufferedPts = 0;
        }
        //Destructor
        ~Team(){

        }
        //Operator to compare 2 teams
        bool operator==(const Team& other) const {
            return name == other.name;
        }

        bool operator!=(const Team& other) const {
            return name != other.name;
        }
    };
}
