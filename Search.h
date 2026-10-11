#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include "Reservation.h"
#include "Display.h"

using namespace std;

// Resource searches
int searchResourceById(vector<Resource>& resources, string id);

// Reservation searches
int searchReservationById(vector<Reservation>& reservations, int id);

// Student search
vector<Reservation> searchByStudent(vector<Reservation>& reservations,
                                    string name);

#endif