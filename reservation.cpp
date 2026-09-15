//campus reservation system
#include "Reservation.h"
#include "Display.h"
#include "QueueNStack.h"
#include <iostream>
#include <string>
#include <stack>


using namespace std;

Reservation::Reservation()
{
    reservationID = 0;
    studentID = 0;
    studentName = "";
    resourceID = "";
    reservationDate = "";
}

void Reservation::display()
{
    cout << "Reservation ID: " << reservationID << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Resource ID: " << resourceID << endl;
    cout << "Reservation Date: " << reservationDate << endl;
}

Node::Node(Reservation r)
{
    reservation = r;
    next = nullptr;
}

ReservationManager::ReservationManager()
{
    head = nullptr;
}

//create reservation
void ReservationManager::createReservation(
    const vector<Resource>& resources,
    queue<Reservation>& waitingList)
{
    int reservationID;
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;

    cout << "\n===== Create Reservation =====" << endl;
    cout << "Enter Reservation ID: ";
    cin >> reservationID;

    Node* current = head;

    while (current != nullptr)
    {
        if (current->reservation.reservationID == reservationID)
        {
            cout << "This reservation ID already exists." << endl;
            return;
        }

        current = current->next;
    }

    cout << "Enter Student ID: ";
    cin >> studentID;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, studentName);

    cout << "Enter Resource ID: ";
    getline(cin, resourceID);

    cout << "Enter Reservation Date: ";
    getline(cin, reservationDate);

    Reservation newReservation;

    newReservation.reservationID = reservationID;
    newReservation.studentID = studentID;
    newReservation.studentName = studentName;
    newReservation.resourceID = resourceID;
    newReservation.reservationDate = reservationDate;

    if (isResourceAvailable(resources, resourceID))
{
    Node* newNode = new Node(newReservation);

    newNode->next = head;
    head = newNode;

    cout << "Reservation created successfully!" << endl;
}
else
{
    cout << "Resource is unavailable." << endl;

    addToWaitingList(waitingList, newReservation);

    cout << "Added to waiting list." << endl;
}
}
    //Display the reservations
void ReservationManager::viewReservations()
{
    cout << "\n=== Current Reservations ====" << endl;

    if (head == nullptr)
    {
        cout << "There are no reservations." << endl;
        return;
    }

    Node* current = head;

    while (current != nullptr)
    {
        current->reservation.display();
        current = current->next;
    }
}
    //search for a reservation
void ReservationManager::searchReservation()
{
    int reservationID;

    cout << "\n===== Search Reservation =====\n";
    cout << "Enter Reservation ID: ";
    cin >> reservationID;

    Node* current = head;

    while (current != nullptr)
    {
        if (current->reservation.reservationID == reservationID)
        {
            cout << "\nReservation Found!\n";
            current->reservation.display();
            return;
        }

        current = current->next;
    }

    cout << "Reservation not found.\n";
}

     // cancel a reservation
    void ReservationManager::cancelReservation()
{
    int reservationID;

    cout << "\n===== Cancel Reservation =====" << endl;
    cout << "Enter Reservation ID: ";

    cin >> reservationID;

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr)
    {
        if (current->reservation.reservationID == reservationID)
        {
            break;
        }

        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Reservation not found." << endl;
        return;
    }

    cancelledReservations.push(current->reservation);

    if (previous == nullptr)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    delete current;

    cout << "Reservation cancelled successfully." << endl;
}
        
       void ReservationManager::undoCancellation()
{
    if (cancelledReservations.empty())
    {
        cout << "No cancellations to undo." << endl;
        return;
    }

    Reservation restored = cancelledReservations.top();
    cancelledReservations.pop();

    Node* newNode = new Node(restored);

    newNode->next = head;
    head = newNode;

    cout << "Reservation restored successfully." << endl;
}
 
void ReservationManager::displayCancellationHistory()
{
    cout << "\n=== Cancellation History ===\n";

    if (cancelledReservations.empty())
    {
        cout << "No cancelled reservations." << endl;
        return;
    }

    stack<Reservation> temp = cancelledReservations;

    while (!temp.empty())
    {
        temp.top().display();
        cout << endl;

        temp.pop();
    }
}





