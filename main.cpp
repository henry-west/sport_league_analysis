/** author: Henry West
 * date: 15 April, 2013
 * description: the main function of a program to compute the results of a sports league
 * and return the winner
 * proposed points: 46/50
 *      * did not implement tie_breaker function and thus, did not call that function a arbitrary number of times
 */
#include <iostream>
#include <fstream>

#include "team.h"
#include "league.h"
#include <list>

using namespace std;
/*
 * function readInWinData
 * no return, reads the data from an input file to the stream and writes to a league object
 */
void readInWinData(League * lg, ifstream &inFile);
/*
 * main function, runs all of the code segments
 */
int main()
{
    //input file dealings
    ifstream inFile;

    char fileName[20]; //personal preference of char array over cstring
    //badger user for file name until a valid one is given
    do {
        cout << "Enter a League file: ";
        cin >> fileName;
        inFile.open(fileName);
    } while (inFile.fail());

    int numTeams, numDivs;
    inFile >> numTeams >> numDivs;
    cout << numTeams << endl;
    //initialize league
    League * myLeague = new League(numTeams, numDivs);
    readInWinData(myLeague, inFile);
    IntList * winners = myLeague->getWinners();
    //display the fruits of the athletes' efforts
    cout << "League winners: ";
    //display the winners list
    winners->printList();
    return 0;
}

// implementation of readInWinData
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
