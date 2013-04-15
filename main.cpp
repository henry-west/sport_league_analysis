#include <iostream>
#include <fstream>

#include "team.h"
#include "league.h"
#include <list>

using namespace std;

void readInWinData(League * lg, ifstream &inFile);

int main()
{
    ifstream inFile;
    char fileName[20];
    do {
        cout << "Enter a League file: ";
        cin >> fileName;
        inFile.open(fileName);
    } while (inFile.fail());

    int numTeams, numDivs;
    inFile >> numTeams >> numDivs;
    cout << numTeams << endl;

    League * myLeague = new League(numTeams, numDivs);
    readInWinData(myLeague, inFile);
    IntList * winners = myLeague->getWinners();
    cout << "Here 1" << endl;

    cout << "League winners: ";
    //display the winners list
    //perform the tie breaker over and over until
    //there is only one team left or until
    //the list of winners remains unchanged
    //after applying the tie breaker
    winners->printList();
    return 0;
}


void readInWinData(League * lg, ifstream &inFile)
{
    for(int winId = 0; winId < lg->getNumTeams(); winId++)
    {
        int loserId;
        inFile >> loserId;
        while(loserId != -1)
        {
            lg->recordGameResult(winId,loserId);
            inFile >> loserId;
        }
    }
}
