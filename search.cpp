#include "Search.h"

using namespace std;

// Search Resource by ID
int searchResourceById(vector<Resource>& resources, string id)
{
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

// Search Reservation by ID
int searchReservationById(vector<Reservation>& reservations, int id)
{
    for (int i = 0; i < reservations.size(); i++)
    {
        if (reservations[i].reservationID == id)
        {
            return i;
        }
    }

    return -1;
}

// Search Reservations by Student Name
vector<Reservation> searchByStudent(vector<Reservation>& reservations,
                                    string name)
{
    vector<Reservation> results;

    for (int i = 0; i < reservations.size(); i++)
    {
        if (reservations[i].studentName == name)
        {
            results.push_back(reservations[i]);
        }
    }

    return results;
}