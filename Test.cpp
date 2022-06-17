#include "doctest.h"
#include "sources/Leauge.hpp"
using namespace ariel;
TEST_CASE("Testing Teams Correctivity"){
    std::vector<Team*> teamTest;
    CHECK_THROWS(teamTest.push_back(new Team("",0)));
    CHECK_THROWS(teamTest.push_back(new Team("\r",0)));
    CHECK_THROWS(teamTest.push_back(new Team("\n",0)));
    CHECK_THROWS(teamTest.push_back(new Team("\t",0)));
    CHECK_THROWS(teamTest.push_back(new Team("\r",0)));
    CHECK_THROWS(teamTest.push_back(new Team(" ",0)));
    CHECK_NOTHROW(teamTest.push_back(new Team("Roi",0)));
    CHECK_NOTHROW(teamTest.push_back(new Team("OdRoi",0.1)));
    CHECK_NOTHROW(teamTest.push_back(new Team("MaleRoi",0.2)));
    CHECK_NOTHROW(teamTest.push_back(new Team("Roiim",0.3)));
    CHECK_NOTHROW(teamTest.push_back(new Team("YoterMidayRoi",0.005)));
    CHECK_NOTHROW(teamTest.push_back(new Team("TovRoiAharon",1)));
    CHECK_NOTHROW(teamTest.push_back(new Team("UlayOdRoi",0.9999)));
    CHECK_NOTHROW(teamTest.push_back(new Team("OdRoiKedeyLeashlimLe20Testim",0.65)));
    CHECK_NOTHROW(teamTest.push_back(new Team("RoiBiglalMaSheRashumLemala",0.77)));
    CHECK_NOTHROW(teamTest.push_back(new Team("RoiRagilBliHafir",0.123456)));
    CHECK_THROWS(teamTest.push_back(new Team("RoiLoTov",-1)));
    CHECK_THROWS(teamTest.push_back(new Team("RoiLoTov",1.1)));

}
TEST_CASE("Leauge Testing"){
    vector<Team*> teamTests;
    teamTests.push_back(new Team("Golden State Warriors", 1));
    teamTests.push_back(new Team("Boston Celtics", 0.4));
    teamTests.push_back(new Team("Brooklyn Nets", 0.5));
    teamTests.push_back(new Team("Denver Nuggets", 0.3));
    teamTests.push_back(new Team("Philadelphia 76ers", 0.4));
    teamTests.push_back(new Team("Minnesota Timberwolves", 0.5));
    teamTests.push_back(new Team("Chicago Bulls", 0.3));
    teamTests.push_back(new Team("Portland Trail Blazers", 0.2));
    teamTests.push_back(new Team("LA Clippers", 0.5));
    teamTests.push_back(new Team("Los Angeles Lakers", 1));
    teamTests.push_back(new Team("Milwaukee Bucks", 0.7));
    teamTests.push_back(new Team("Atlanta Hawks", 0.3));
    teamTests.push_back(new Team("Charlotte Hornets", 0.2));
    teamTests.push_back(new Team("Miami Heat", 0.6));
    teamTests.push_back(new Team("Phoenix Suns", 0.8));
    teamTests.push_back(new Team("Dallas Mavericks", 0.6));
    teamTests.push_back(new Team("Memphis Grizzlies", 0.5));
    teamTests.push_back(new Team("Utah Jazz", 0.3));
    teamTests.push_back(new Team("Washington Wizards", 0));
    teamTests.push_back(new Team("Oklahoma City Thunder", 0.1));
    Leauge* l = new Leauge(teamTests);
    CHECK_THROWS(l->printLeauge(5));
    l->startLeauge();
    CHECK_NOTHROW(l->printLeauge(5));
}