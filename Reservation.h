#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <stack>
#include <vector>
#include <queue>
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
    stack<Reservation> cancelledReservations;

public:
    ReservationManager();

    void createReservation(
    const vector<Resource>& resources,
    queue<Reservation>& waitingList
);
    void viewReservations();
    void searchReservation();
    void cancelReservation();
    void undoCancellation();
    void displayCancellationHistory();
};

#endif