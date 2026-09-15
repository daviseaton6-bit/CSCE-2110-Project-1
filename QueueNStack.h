#ifndef QUEUENSTACK_H
#define QUEUENSTACK_H
#include "Reservation.h"
#include <queue>
#include <stack>
#include <string>

using namespace std;



void addToWaitingList(queue<Reservation>& waitingList,
                      const Reservation& r);

Reservation processNext(queue<Reservation>& waitingList);

void displayWaitingList(queue<Reservation> waitingList);

void recordCancellation(stack<Reservation>& history,
                        const Reservation& r);

Reservation undo(stack<Reservation>& history);

void displayHistory(stack<Reservation> history);

#endif