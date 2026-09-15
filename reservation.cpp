// Campus resources reservation system.cpp : 
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Reservation class
class Reservation
{
public:
    int reservationID;
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;

    Reservation()
    {
        reservationID = 0;
        studentID = 0;
        studentName = " ";
        resourceID = " ";
        reservationDate = " ";
    }
    void display()
    {
        cout << "Reservation ID: " << reservationID << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Resource ID: " << resourceID << endl;
        cout << "Reservation Date: " << reservationDate << endl;
    }
};

//linked list
struct Node
{
    Reservation reservation;
    Node* next;

    Node(Reservation r)
    {
        reservation = r;
        next = nullptr;
    }
};

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
};

//create reservation
void createReservation(int reservationID)
{
    int reservationID;
    int studentID;
    string studentName;
    string resourceID;
    string reservationDate;

    cout << "\n ===== create reservation =====" << endl;
    cout << "Enter Reservation ID: ";
    cin >> reservationID;

    //check if ID exists

    Node* current = head;

    while (current != nullptr)
    {
        if (current->reservation.reservationID == reservationID)
        
            cout << " This reservation ID is already in the system." << endl;
            return;
        

    }
    cout << "Enter Student ID: ";
    cin >> studentID;

    cout << "Enter Student Name: ";
    getline(cin, studentName);

    cout << "Enter Resource ID: ";
    getline(cin, resourceID);

    cout << "Enter Reservation Date: ";
    getline(cin, reservationDate);

    //create new reservation
    Reservation newReservation(
        reservationID,
        studentID,
        studentName,
        resourceID,
        reservationDate
    );

    //create new node

    Node* newNode = new Node(newReservation);

    cout << "Reservation created Successfully! " << endl;
}
    //Display the reservations
void viewReservations()
{
    cout << "\n=== Current Reservations ====" << endl;

    if (head == nullptr)
    {
        cout << " There are no reservations. " << endl;
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
     void searchReservation()
        {
            int reservationID;

            cout << "\n===== Search Reservation =====" << endl;

            cout << " Enter Reservation ID: ";
            cin >> reservationID;

            Node* current = head;
            
            while (current != nullptr)
            {
                if (current->reservation.reservationID == reservationID)
                {
                    cout << "\nReservation Found!" << endl;
                    current->reservation.display();
                    return;
                }

                current = current->next;

            }

            cout << "Reservation not found. " << endl;

     }

     // cancel a reservation
     void cancelReservation()
     {
         int reservationID;

         cout << "\n===== Cancel Reservation =====" << endl;

         cout << " Enter Reservation ID: ";
         cin >> reservationID;

         Node* current = head;
         Node* previous = nullptr;

         //search for the reservation
         while (current != nullptr)
         {
             if (current->reservation.reservationID == reservationID)
                 break;

             previous = current;
             current = current->next;
         }


     }
        
       
        






int main()
{
    
    ReservationManager manager;
    Reservation newReservation;
    
   
}


