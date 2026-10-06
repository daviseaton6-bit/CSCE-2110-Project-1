#ifndef QUEUENSTACK_H
#define QUEUENSTACK_H

#include "Reservation.h"
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <string>
using namespace std;

void validateReservation(const Reservation& r);

void addToWaitingList(map<string, queue<Reservation>>& waitingList,
                      const Reservation& r);
Reservation processNext(map<string, queue<Reservation>>& waitingList,
                        const string& resourceID);
void displayWaitingList(map<string, queue<Reservation>> waitingList);

void recordCancellation(map<string, stack<Reservation>>& history,
                        const Reservation& r);
Reservation undo(map<string, stack<Reservation>>& history,
                 const string& resourceID);
void displayHistory(map<string, stack<Reservation>> history);

vector<Reservation> loadReservations(const string& filename);

#endif
