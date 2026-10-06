#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdexcept>
#include "Reservation.h"
#include "Display.h"
#include "QueueNStack.h"
#include <ctime>
#include <string>
#include <map>
using namespace std;

//get current time
string getTime() 
{
    //current time
    time_t now = time(nullptr);
    //convert to local time
    tm* local = localtime(&now);
    char buffer[64];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local);
    return string(buffer);
}

//walks the list and tallies the num of each reservation
map<string, int> Reservationmanager::getCountsByResource() const
{
    map<string, int> counts;
    Node* current = head;
    while (current != nullptr)
    {
        counts[current->reservation.resourceID]++;
        current = current->next;
    }
    return counts;
}

//gets the count for one resource
int getCount(const map<string, int>& counts, const string& resourceID)
{
    auto it = counts.find(resourceID);
    if (it != counts.end())
        return it->second;
    return 0;
}

//gets how many are waiting per reource
int getWaitingCount(const map<string, queue<Reservation>>& waitingLists, const string& resourceID)
{
    auto it = waitingLists.find(resourceID);
    if (it != waitingLists.end())
        return it->second.size();
    return 0;
}

void displayActiveRes(const map<string, int>& counts, const vector<Resource>>& resources)
{
    cout << "----------------------------------------" << endl;
    cout << "ACTIVE RESERVATIONS" << endl;
    cout << "----------------------------------------" << endl;

    int totalActive = 0;

    for (const Resource& res : resources)
    {
        int count = getCount(counts, res.resourceID);
        cout << res.resourceID << ": " << count << " active reservations" << endl;
        totalActive += count;
    }
    cout << "Total active reservations: " << totalActive << endl;
    
}
void displayUtilization(const map<string, int>& counts, const vector<Resource>& resources)
{
    cout << "----------------------------------------" << endl;
    cout << "RESOURCE UTILIZATION" << endl;
    cout << "----------------------------------------" << endl;
    int totalActive = 0;
    for (const auto& [resourceID, count] : counts)
        totalActive += count;

    int inUse = 0;
    for (const Resource& res : resources)
    {
        int count = getCount(counts, res.resourceID);
        int percent = 0;
        if (totalActive > 0)
            percent = (count * 100) / totalActive;
        cout << res.resourceID << ": " << percent << "% of all reservations" << endl;
        if (count > 0)
            inUse++;
    }
    cout << "Resources in use: " << inUse << " of " << resources.size() << endl;
}
void displayMostRequested(const map<string, int>& counts, const vector<Resource>& resources)
{
    cout << "----------------------------------------" << endl;
    cout << "MOST REQUESTED RESOURCES" << endl;
    cout << "----------------------------------------" << endl;

    int mostRequested = 0;
    string mostID = "n/a";
    for (const Resource& res : resources)
    {
        int active = getCount(counts,res.resourceID);
        int waiting = getWaiting(waitingLists, res.resourceID);
        int requests = active + waiting;

        cout << res.resourceID << ": " << requests << " requests" << " (" << active << " active, " << waiting << " waiting)" << endl;
        if (requests > mostRequested)
        {
            mostRequested = requests;
            mostID = res.resourceID;
        }
    }
    cout << "Most requested resource: " << mostID << " (" << mostRequested << " requests)" << endl;
    
}

void displayWaitingList(const Reservationmanager& manager, const vector<Resource>& resources, const map<string, queue<Reservation>>& waitingLists)
{
    cout << "----------------------------------------" << endl;
    cout << "WAITING LISTS STATISTICS" << endl;
    cout << "----------------------------------------" << endl;
    
    int totalWaiting = 0;
    int withWaitlist = 0;
    int longestWaitlist = 0;
    string longestID = "n/a";

    for (const auto& [resourceID, q] : waitingLists)
    {
        cout << resourceID << ": " << q.size() << " waiting";
        if (!q.empty())
        {
            string next = q.front().studentName + " (" + q.front().reservationDate + ")";
            cout << " (first in line: " << next << ")";
        }
        cout << endl;
        totalWaiting += q.size();
        if (!q.empty())
            withWaitlist++;
        if (q.size() > longestWaitlist)
        {
            longestWaitlist = q.size();
            longestID = resourceID;
        }
    }
    cout << "Resources with waitlists: " << withWaitlist << endl;
    cout << "Longest waitlist: " << longestWaitlist << " (" << longestID << ")" << endl;
    cout << "Total waiting: " << totalWaiting << endl;
    cout << "----------------------------------------" << endl;

}
void displayReport(const Reservationmanager& manager, const vector<Resource>& resources, const map<string, queue<Reservation>>& waitingLists)
{
    map<string, int> counts = manager.getCountsByResourceID();
    cout << "CAMPUS RESOURCE RESERVATION SYSTEM - REPORT" << endl;
    cout << "Report generated at: " << getTime() << endl;
    cout << "----------------------------------------" << endl;
    displayActiveReservations(counts, resources);
    displayUtilization(counts, resources);
    displayMostRequested(counts, resources, waitingLists);
    displayWaitingList(waitingLists);

    cout << "----------------------------------------" << endl;
}
//there is two cancellation histories

//fix reservation pushing to one single queue

