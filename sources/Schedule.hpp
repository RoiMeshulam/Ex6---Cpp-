#ifndef EX6_PARTA_SCHEDULE_H
#define EX6_PARTA_SCHEDULE_H

#endif //EX6_PARTA_SCEHDULE_H
#pragma once
#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"

using namespace std;
namespace ariel{
    class Schedule{
    public:
        vector<Team*> teams;

        Schedule(vector<Team*> gameSet){
            this->teams = gameSet;
        }
        ~Schedule(){}
        vector<Game*> ascendingSchedule(){
            vector<Game*> schedule;
            for (unsigned int i = 0; i < this->teams.size(); ++i) {
                for (unsigned int j = i; j < this->teams.size(); ++j) {
                    if(i==j){
                        continue;
                    }
                    schedule.push_back(new Game(this->teams.at(i), this->teams.at(j)));
                }
            }
            return schedule;
        }
        vector<Game*> descendingSchedule(){
            vector<Game*> schedule;
            for (unsigned int i = 0; i < this->teams.size(); ++i) {
                for (unsigned int j = i; j < this->teams.size(); ++j) {
                    if(i==j){
                        continue;
                    }
                    schedule.push_back(new Game(this->teams.at(j), this->teams.at(i)));
                }
            }
            return schedule;
        }
        vector<Game*> makeSchedule (){
            vector<Game*> schedule;
            vector<Game*> scheduleasc = ascendingSchedule();
            vector<Game*> scheduledes = descendingSchedule();
            schedule.insert(schedule.begin(),scheduleasc.begin(),scheduleasc.end());
            schedule.insert(schedule.end(),scheduledes.begin(),scheduledes.end());
            return schedule;
        }
    };
}
