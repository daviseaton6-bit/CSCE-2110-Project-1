#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <vector>
#include <queue>
#include <map>
#include "Reservation.h"
#include "Display.h"

using namespace std;

//get current time
string getTime();

//helpers
int getCount(const map<string, int>& counts, const string& resourceID);
int getWaitingCount(const map<string, queue<Reservation>>& waitingLists, const string& resourceID);

//report sections
void displayActiveRes(const map<string, int>& counts, const vector<Resource>& resources);
void displayUtilization(const map<string, int>& counts, const vector<Resource>& resources);
void displayMostRequested(const map<string, int>& counts, const vector<Resource>& resources,
                          const map<string, queue<Reservation>>& waitingLists);
void displayWaitingListStats(const map<string, queue<Reservation>>& waitingLists);

//full report
void displayReport(const ReservationManager& manager, const vector<Resource>& resources,
                   const map<string, queue<Reservation>>& waitingLists);

#endif
