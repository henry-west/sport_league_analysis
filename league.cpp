/** author: Henry West
 * date: 15 April, 2013
 * description: implementation of
 * the class league.h
 */

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
    //delete stuff
    for(int i = 0; i < numTeams; i++)
    {
        delete teamArray[i];
    }
    delete teamArray;
    delete [] tied_teams;
}
/*
*function recordGameResult
*adds record of win/loss to given team's arrays for wins/losses
*/
void League::recordGameResult(int winner, int loser)
{
    teamArray[winner]->addWin(teamArray[loser]);
    teamArray[loser]->addLoss(teamArray[winner]);
}
/*
 * function computeMaxWinPercentage
 * calculates the highest overall score among the teams
 */
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

/*
 * function getWinners
 * returns an IntList of the teams tied for first place
 */
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
/*
 * function tie_breaker
 * not yet implemented
 */
IntList * League::tie_breaker() {
    /* figure out tie breaker algorithm */
    return tied_teams;
}
