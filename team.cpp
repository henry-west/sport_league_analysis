/** author: Henry West
 * date: 15 April, 2013
 * description: implementation of
 * the class team.h
 */

#include "team.h"

Team::Team(int i)
{
    id = i;
}
/*
 * function getId
 * returns an integer value of a team, used for identification purposes
 */
int Team::getId() const
{
    return id;
}

/*
 * function addWin
 * no return, adds a win to the linked list of wins for a given team
 */
void Team::addWin(Team * other)
{
    //put a new win against other into
    //the wins list
    wins.appendToList(other->getId());
}
/*
 * function addLoss
 * no return, adds a loss to the linked list of losses for a given team
 */
void Team::addLoss(Team *other)
{
    //put a new loss against other into
    //the losses list
    losses.appendToList(other->getId());
}
/*
 * function winPercentage
 * returns a double representing the win percentage of a given team
 */
double Team::winPercentage()
{
    double winsD = wins.size();//size of the wins list converted to a double
    double lossesD = losses.size();//size of the losses list converted to a double
    if(winsD+lossesD == 0)
    {
        return -1.0;
    }
    return winsD/(winsD+lossesD);
}
/*
 * function defeated
 * returns a bool representing whether or not a team defeated the param team
 */
bool Team::defeated(Team *other)
{
    //go through the wins list and determine if other
    //is one of the teams that this team defeated
    //return true if so, false otherwise
    return wins.contains(other->getId());

}
/*
 * function defeated
 * returns a bool representing whether or not a team lost to the param team
 */
bool Team::lostTo(Team *other)
{
    //go through the losses list and determine if other
    //is one of the teams that this team defeated
    //return true if so, false otherwise
    return losses.contains(other->getId());
}

