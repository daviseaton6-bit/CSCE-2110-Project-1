//re-write of reservation and reservation manager to allow for no inheritance of memeber functions needed from the reservation and reservation manager classes 
//not needed but wanted to put it in here as i discussed it in the report
//also had the queue and stack in here for testing purposes

#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

//shared struct for stack, queue, and linked list
struct Reservation
{
    int reservationID;
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;
};

struct Node
{
    Reservation reservation;
    Node* next;
};

void displayReservation(const Reservation& r)
{
    cout << "Reservation ID: " << r.reservationID << endl;
    cout << "Student ID: " << r.studentID << endl;
    cout << "Student Name: " << r.studentName << endl;
    cout << "Resource ID: " << r.resourceID << endl;
    cout << "Reservation Date: " << r.reservationDate << endl;
}

//check if empty 
void validateReservation(const Reservation& r)
{
    if (r.studentName.empty())
        throw invalid_argument("Student name cannot be empty");
    if (r.resourceID.empty())
        throw invalid_argument("Resource ID cannot be empty");
    if (r.reservationDate.empty())
        throw invalid_argument("Date cannot be empty");
}

// returns true if reservationID already exists in the list
bool reservationExists(Node* head, int reservationID)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->reservation.reservationID == reservationID)
            return true;
        current = current->next;
    }
    return false;
}

void addReservation(Node*& head, const Reservation& r)
{
    Node* newNode = new Node{ r, nullptr };

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = newNode;
}

void createReservation(Node*& head)
{
    Reservation r;

    cout << "\n===== Create Reservation =====" << endl;
    cout << "Enter Reservation ID: ";
    cin >> r.reservationID;

    if (reservationExists(head, r.reservationID))
    {
        cout << "This reservation ID is already in the system" << endl;
        return;
    }

    cout << "Enter Student ID: ";
    cin >> r.studentID;
    cin.ignore(); // clear the newline

    cout << "Enter Student Name: ";
    getline(cin, r.studentName);

    cout << "Enter Resource ID: ";
    getline(cin, r.resourceID);

    cout << "Enter Reservation Date: ";
    getline(cin, r.reservationDate);

    try
    {
        validateReservation(r);
    }
    catch (const invalid_argument& e)
    {
        cout << "Invalid reservation details: " << e.what() << endl;
        return;
    }

    addReservation(head, r);
    cout << "Resrvation added" << endl;
}

void clearList(Node*& head)
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
}

// queue

void addToWaitingList(queue<Reservation>& waitingList, const Reservation& r)
{
    validateReservation(r);
    waitingList.push(r);
}

Reservation processNext(queue<Reservation>& waitingList)
{
    if (waitingList.empty())
    {
        throw runtime_error("No reservations in the waiting list");
    }
    Reservation nextReservation = waitingList.front();
    waitingList.pop();
    return nextReservation;
}

void displayWaitingList(queue<Reservation> waitingList)
{
    cout << "\n=== Waiting List ===" << endl;
    if (waitingList.empty())
    {
        cout << "(empty)" << endl;
        return;
    }
    while (!waitingList.empty())
    {
        Reservation r = waitingList.front();
        cout << r.studentName << " (ID: " << r.studentID << ") is waiting for resource "
             << r.resourceID << endl;
        waitingList.pop();
    }
}

//stack

void recordCancellation(stack<Reservation>& history, const Reservation& r)
{
    validateReservation(r);
    history.push(r);
}

Reservation undo(stack<Reservation>& history)
{
    if (history.empty())
    {
        throw runtime_error("No cancellations to undo");
    }
    Reservation last = history.top();
    history.pop();
    return last;
}

//same as displaying the queue, takes by value
void displayHistory(stack<Reservation> history)
{
    cout << "\n=== Cancellation History ===" << endl;
    if (history.empty())
    {
        cout << "(empty)" << endl;
        return;
    }
    while (!history.empty())
    {
        Reservation r = history.top();
        cout << r.studentName << " -> " << r.resourceID << endl;
        history.pop();
    }
}
