#include "QueueNStack.h"
#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <ReservationManager.h>
using namespace std;



// check if empty 
void validateReservation(const ReservationR& r)
{
    if (r.resID.empty())
        throw invalid_argument("Reservation ID cannot be empty.");
    if (r.stuID.empty())
        throw invalid_argument("Student ID cannot be empty.");
    if (r.stuName.empty())
        throw invalid_argument("Student name cannot be empty.");
    if (r.resourceID.empty())
        throw invalid_argument("Resource ID cannot be empty.");
    if (r.date.empty())
        throw invalid_argument("Date cannot be empty.");
}


//takes queue by reference
void addToWaitngList(queue<ReservationR>& waitingList, const ReservationR& r) 
{
    validateReservation(r);
    waitingList.push(r);
}

//parse the queue 
Reservation processNext(queue<ReservationR>& waitingList)
{
    if (waitingList.empty()) 
    {
        throw runtime_error("No reservations in the list");
    }
    ReservationR nextReservation = waitingList.front();
    waitingList.pop();
    return nextReservation;
}

//Display without modifying the queue
void displayWaitingList(queue<ReservationR> waitingList)
{
    cout << "\n=== Waiting List ===\n";
    if (waitingList.empty())
    {
        cout << "(empty)\n";
        return;
    }
    while (!waitingList.empty())
    {
        ReservationR r = waitingList.front();
        cout << r.stuName << " (ID: " << r.stuID << ") is waiting for resource " << r.resourceID << endl;
        waitingList.pop();
    }
}

void recordCancellation(stack<ReservationR>& history, const ReservationR& r)
{
    validateReservation(r);
    history.push(r);
}

//undo function
ReservationR undo(stack<ReservationR>& history)
{
    if (history.empty())
    {
        cout << "No cancellations to undo" << endl;
        return {"", "", "", "", ""}; //return empty reservation
    }
    ReservationR last = history.top(); 
    history.pop();
    return last;
}

//Display wihtout effecting the stack
void displayHistory(stack<ReservationR> history) 
{
    cout << "\n=== Cancellation History ===\n";
    if (history.empty())
    {
        cout << "(empty)\n";
        return;
    }
    while (!history.empty())
    {
        ReservationR r = history.top();
        cout << r.stuName << " -> " << r.resourceID << endl;
        history.pop();
    }
}
