#include "team.h"

Team::Team(int i)
{
    id = i;
}

int Team::getId() const
{
    return id;
}


void Team::addWin(Team * other)
{
    //put a new win against other into
    //the wins list
    wins.appendToList(other->getId());
}

void Team::addLoss(Team *other)
{
    //put a new loss against other into
    //the losses list
    losses.appendToList(other->getId());
}

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

bool Team::defeated(Team *other)
{
    //go through the wins list and determine if other
    //is one of the teams that this team defeated
    //return true if so, false otherwise
    return wins.contains(other->getId());

}

bool Team::lostTo(Team *other)
{
    //go through the losses list and determine if other
    //is one of the teams that this team defeated
    //return true if so, false otherwise
    return losses.contains(other->getId());
}

