#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include "Display.h"
using namespace std;

class Reservation
{
public:
    int reservationID;
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;

    Reservation();

    void display();
};

struct Node
{
    Reservation reservation;
    Node* next;

    Node(Reservation r);
};

class ReservationManager
{
private:
    Node* head;
    map<string, stack<Reservation>> cancelledReservations;

public:
    ReservationManager();

    void createReservation(
    vector<Resource>& resources,
    map<string, queue<Reservation>>& waitingList
);
    void viewReservations();
    void searchReservation();
    void cancelReservation(vector<Resource>& resources,
                           map<string, queue<Reservation>>& waitingList);
    void undoCancellation(vector<Resource>& resources);
    void displayCancellationHistory();
    map<string, int> getCountsByResource() const;
    vector<Reservation> getReservations() const;
    void addLoadedReservations(const vector<Reservation>& loaded,
                               vector<Resource>& resources,
                               map<string, queue<Reservation>>& waitingList);
};

#endif
