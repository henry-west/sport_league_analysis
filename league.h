#ifndef LEAGUE_H
#define LEAGUE_H

#include "team.h"
#include "intlist.h"

class League : public IntList {
private:
    int numTeams;
    int numDivs;
    double maxWinPcnt;
    Team * *teamArray;
    IntList * tied_teams;
    void computeMaxWinPercentage();
public:
    League(int t, int d);
    ~League();
    void recordGameResult(int winner, int loser);
    IntList * getWinners();
    IntList * tie_breaker();
    int getNumTeams() const{ return numTeams; }
};

#endif // LEAGUE_H
