#include "league.h"

League::League(int t, int d)
{
    numTeams = t;
    numDivs = d;
    maxWinPcnt = -1.0;
    teamArray = new Team *[numTeams];
    //allocate space for tiedTeams if it's a pointer
    tied_teams = new IntList;
    for(int i = 0; i < numTeams; i++)
    {
        teamArray[i] = new Team(i);
    }
}

League::~League()
{
    for(int i = 0; i < numTeams; i++)
    {
        delete teamArray[i];
    }
    delete teamArray;
    delete [] tied_teams;
}

void League::recordGameResult(int winner, int loser)
{
    teamArray[winner]->addWin(teamArray[loser]);
    teamArray[loser]->addLoss(teamArray[winner]);
}

void League::computeMaxWinPercentage()
{
    double bestWinPercentage = -1.0;
    for(int i = 0; i < numTeams; i++)
    {
        if(teamArray[i]->winPercentage() > bestWinPercentage)
        {
            bestWinPercentage = teamArray[i]->winPercentage();
        }
    }
    maxWinPcnt = bestWinPercentage;
}


IntList * League::getWinners()
{
    computeMaxWinPercentage();
    for(int i = 0; i < numTeams; i++)
    {
        if(teamArray[i]->winPercentage() == maxWinPcnt)
        {
            tied_teams->appendToList(teamArray[i]->getId());
        }
    }
    return tied_teams;
}
IntList * League::tie_breaker() {
    /* figure out tie breaker algorithm */
    return 0;
}
