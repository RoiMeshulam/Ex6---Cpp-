#ifndef EX6_GAME_H
#define EX6_GAME_H

#endif //EX5A_ITERATOR_H
#pragma once
#include <iostream>
#include "Team.hpp"

namespace ariel{
    class Game{
    public:
        Team* home;
        Team* away;

        Game(Team* a,Team* b){
            this->home = a;
            this->away = b;
        }
        ~Game(){}

        int randNum(int A, int B){
            int r = (rand()%(B-A)) + A;
            return r;
        }
        void fixHomeWin(){
            this->home->currState = true;
            this->home->currLoseSpree = 0;
            this->home->currWinSpree+=1;
            this->home->wins+=1;
            if (this->home->currWinSpree > this->home->bestWinSpree){
                this->home->bestWinSpree = this->home->currWinSpree;
            }
            this->away->currState = false;
            this->away->currWinSpree = 0;
            this->away->currLoseSpree+=1;
            this->away->loses+=1;
            if (this->away->currLoseSpree > this->away->worstLoseSpree){
                this->away->worstLoseSpree = this->away->currLoseSpree;
            }
        }
        void fixAwayWin(){
            this->away->currState = true;
            this->away->currLoseSpree = 0;
            this->away->currWinSpree+=1;
            this->away->wins+=1;
            if (this->away->currWinSpree > this->away->bestWinSpree){
                this->away->bestWinSpree = this->away->currWinSpree;
            }
            this->home->currState = false;
            this->home->currWinSpree = 0;
            this->home->currLoseSpree+=1;
            this->home->loses+=1;
            if (this->home->currLoseSpree > this->home->worstLoseSpree){
                this->home->worstLoseSpree = this->home->currLoseSpree;
            }
        }
        Team* startGame(){
            int homeRand = randNum(55,100);
            int awayRand = randNum(50,100);
            homeRand += (int)(this->home->talent * 10);
            awayRand += (int)(this->away->talent * 10);
            this->home->scorePts+=(homeRand);
            this->home->sufferedPts+=(awayRand);
            this->away->scorePts+=(awayRand);
            this->away->sufferedPts+=(homeRand);
            if(homeRand>=awayRand){
                fixHomeWin();
                std::cout << this->home->name << " " << homeRand << ":"<< awayRand << " " << this->away->name <<std::endl;
                return this->home;
            }
            fixAwayWin();
            std::cout << this->home->name << " " << homeRand << ":"<< awayRand << " " << this->away->name <<std::endl;
            return this->away;
        }
    };
}
