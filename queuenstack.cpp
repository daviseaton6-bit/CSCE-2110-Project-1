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
void validateReservation(const Reservation& r)
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
void addToWaitngList(queue<Reservation>& waitingList, const Reservation& r) 
{
    validateReservation(r);
    waitingList.push(r);
}

//parse the queue 
Reservation processNext(queue<Reservation>& waitingList)
{
    if (waitingList.empty()) 
    {
        throw runtime_error("No reservations in the list");
    }
    Reservation nextReservation = waitingList.front();
    waitingList.pop();
    return nextReservation;
}

//Display without modifying the queue
void displayWaitingList(queue<Reservation> waitingList)
{
    cout << "\n=== Waiting List ===\n";
    if (waitingList.empty())
    {
        cout << "(empty)\n";
        return;
    }
    while (!waitingList.empty())
    {
        Reservation r = waitingList.front();
        cout << r.stuName << " (ID: " << r.stuID << ") is waiting for resource " << r.resourceID << endl;
        waitingList.pop();
    }
}

void recordCancellation(stack<Reservation>& history, const Reservation& r)
{
    validateReservation(r);
    history.push(r);
}

//undo function
Reservation undo(stack<Reservation>& history)
{
    if (history.empty())
    {
        cout << "No cancellations to undo" << endl;
        return {"", "", "", "", ""}; //return empty reservation
    }
    Reservation last = history.top(); 
    history.pop();
    return last;
}

//Display wihtout effecting the stack
void displayHistory(stack<Reservation> history) 
{
    cout << "\n=== Cancellation History ===\n";
    if (history.empty())
    {
        cout << "(empty)\n";
        return;
    }
    while (!history.empty())
    {
        Reservation r = history.top();
        cout << r.stuName << " -> " << r.resourceID << endl;
        history.pop();
    }
}




//loading reservation vector, not needed for the queue or stack as i will leave both empty until the user adds reservations, idk why i made it honestly
vector<Reservation> loadReservations(const string& filename) 
{
    vector<Reservation> reservations;
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return reservations;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string resID, stuID, studName, ressourceID, date;
        getline(ss, resID, '|');
        getline(ss, stuID, '|');
        getline(ss, studName, '|');
        getline(ss, ressourceID, '|');
        getline(ss, date, '|');
        //add the reservation to the vector
        reservations.push_back({resID, stuID, studName, ressourceID, date});
    }
    file.close();
    return reservations;
}
