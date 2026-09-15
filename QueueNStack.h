#ifndef QUEUENSTACK_H
#define QUEUENSTACK_H

#include <queue>
#include <stack>
#include <string>

using namespace std;

struct Reservation
{
    string resID;
    string stuID;
    string stuName;
    string resourceID;
    string date;
};

void addToWaitingList(queue<Reservation>& waitingList,
                      const Reservation& r);

Reservation processNext(queue<Reservation>& waitingList);

void displayWaitingList(queue<Reservation> waitingList);

void recordCancellation(stack<Reservation>& history,
                        const Reservation& r);

Reservation undo(stack<Reservation>& history);

void displayHistory(stack<Reservation> history);

#endif