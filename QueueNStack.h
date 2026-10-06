#ifndef QUEUENSTACK_H
#define QUEUENSTACK_H

#include "Reservation.h"
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <string>

void validateReservation(const Reservation& r);

void addToWaitingList(std::map<std::string, std::queue<Reservation>>& waitingList,
                      const Reservation& r);
Reservation processNext(std::map<std::string, std::queue<Reservation>>& waitingList,
                        const std::string& resourceID);
void displayWaitingList(std::map<std::string, std::queue<Reservation>> waitingList);

void recordCancellation(std::map<std::string, std::stack<Reservation>>& history,
                        const Reservation& r);
Reservation undo(std::map<std::string, std::stack<Reservation>>& history,
                 const std::string& resourceID);
void displayHistory(std::map<std::string, std::stack<Reservation>> history);

std::vector<Reservation> loadReservations(const std::string& filename);

#endif
