#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//struct to hold reservation info
struct Reservation
{
    string resID;
    string stuID;
    string stuName;
    string resourceID;
    string date;
};



//takes queue by reference
void addToWatingList(queue<Reservation>& waitingList, const Reservation& r) 
{
    waitingList.push(r);
}

//parse the queue 
Reservation processNext(queue<Reservation>& waitingList)
{
    if (waitingList.empty()) 
    {
        cout << "No reservations in the queue." << endl;
        return {"", "", "", "", ""}; //return an empty reservation
    }
    Reservation nextReservation = waitingList.front();
    waitingList.pop();
    return nextReservation;
}

//Display without modifying the queue
void displayWaitingList(queue<Reservation> waitingList)
{
    cout << "\n--- Waiting List ---\n";
    while (!waitingList.empty())
    {
        Reservation r = waitingList.front();
        cout << r.stuName << " (ID: " << r.stuID << ") is waiting for resource " << r.resourceID << endl;
        waitingList.pop();
    }
}

void recordCancellation(stack<Reservation>& history, const Reservation& r)
{
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
    cout << "\n--- Cancellation History ---\n";
    while (!history.empty())
    {
        Reservation r = history.top();
        cout << r.stuName << " -> " << r.resourceID << endl;
        history.pop();
    }
}





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
