#include "QueueNStack.h"
#include "Reservation.h"
#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;



// check if empty 
void validateReservation(const Reservation& r)
{
    if (r.reservationID == 0)
        throw invalid_argument("Reservation ID cannot be empty.");
    if (r.studentID == 0)
        throw invalid_argument("Student ID cannot be empty.");
    if (r.studentName.empty())
        throw invalid_argument("Student name cannot be empty.");
    if (r.resourceID.empty())
        throw invalid_argument("Resource ID cannot be empty.");
    if (r.reservationDate.empty())
        throw invalid_argument("Reservation date cannot be empty.");
}


//takes the map by reference
void addToWaitingList(map<string, queue<Reservation>>& waitingList,
                      const Reservation& r)
{
    validateReservation(r);
    waitingList[r.resourceID].push(r);
}

//parse the queue, needs to know which resource has opened
Reservation processNext(map<string, queue<Reservation>>& waitingList,
                        const string& resourceID)
{
    auto it = waitingList.find(resourceID);

    if (it == waitingList.end() || it->second.empty())
    {
        throw runtime_error("No reservations in the list");
    }

    Reservation nextReservation = it->second.front();
    it->second.pop();

    if (it->second.empty())
    {
        waitingList.erase(it);
    }

    return nextReservation;
}

//Display without modifying the queue
void displayWaitingList(map<string, queue<Reservation>> waitingList)
{
    cout << "\n=== Waiting List ===\n";

    if (waitingList.empty())
    {
        cout << "(empty)\n";
        return;
    }

    for (auto& entry : waitingList)
    {
        cout << "[" << entry.first << "]\n";

        while (!entry.second.empty())
        {
            Reservation r = entry.second.front();

            cout << r.studentName
                 << " (ID: "
                 << r.studentID
                 << ") waiting for resource "
                 << r.resourceID
                 << endl;

            entry.second.pop();
        }
    }
}

void recordCancellation(map<string, stack<Reservation>>& history, const Reservation& r)
{
    validateReservation(r);
    history[r.resourceID].push(r);
}

//undo function
Reservation undo(map<string, stack<Reservation>>& history, const string& resourceID)
{
    auto it = history.find(resourceID);

    if (it == history.end() || it->second.empty())
    {
        cout << "No cancellations to undo" << endl;

        Reservation emptyReservation;
        return emptyReservation;
    }

    Reservation last = it->second.top();
    it->second.pop();

    if (it->second.empty())
    {
        history.erase(it);
    }

    return last;
}

//Display wihtout effecting the stack
void displayHistory(map<string, stack<Reservation>> history) 
{
    cout << "\n=== Cancellation History ===\n";
    if (history.empty())
    {
        cout << "(empty)\n";
        return;
    }
    for (auto& entry : history)
    {
        cout << "[" << entry.first << "]\n";
        while (!entry.second.empty())
        {
            Reservation r = entry.second.top();
            cout << r.studentName << " (ID: " << r.studentID << ") -> " << r.resourceID << endl;
            entry.second.pop();
        }
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
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;

        stringstream ss(line);

        string resID;
        string stuID;
        string studName;
        string ressourceID;
        string date;

        getline(ss, resID, '|');
        getline(ss, stuID, '|');
        getline(ss, studName, '|');
        getline(ss, ressourceID, '|');
        getline(ss, date, '|');

        Reservation r;

        r.reservationID = stoi(resID);
        r.studentID = stoi(stuID);
        r.studentName = studName;
        r.resourceID = ressourceID;
        r.reservationDate = date;

        reservations.push_back(r);
    }

    file.close();

    return reservations;
}
