#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include "intlist.h"

using namespace std;
class Team
{
private:
    int id;
    IntList wins;
    IntList losses;
public:
    Team(int i);
    int getId() const;
    void addWin(Team * other);
    void addLoss(Team * other);
    double winPercentage();
    bool defeated(Team * other);
    bool lostTo(Team * other);
};

#endif // TEAM_H
