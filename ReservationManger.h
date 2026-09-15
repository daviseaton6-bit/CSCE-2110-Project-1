#ifndef ReservationManager_H
#define ReservationManager_H

#include <vector>
#include <string>
#include <stack>
using namespace std;

//Reservation Manager
class ReservationManager
{
private:
    Node* head;
    stack<Reservation> cancelledReservations;

public:
    // constructor
    ReservationManager()
    {
        head = nullptr;
    }
    

#endif
