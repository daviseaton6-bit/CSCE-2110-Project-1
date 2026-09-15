#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <limits>
#include "Reservation.h"
#include "Display.h"
#include "QueueNStack.h"

using namespace std;

int main()
{
    vector<Resource> resources = loadResources("resources.txt");
    ReservationManager manager;
    queue<Reservation> waitingList;
    int choice = 0;

    while (choice != 11)
    {
        cout << "\n===== Campus Resource Reservation System =====\n";
        cout << "1. Display All Resources\n";
        cout << "2. Display Resource Availability\n";
        cout << "3. Create Reservation\n";
        cout << "4. Cancel Reservation\n";
        cout << "5. Display Active Reservations\n";
        cout << "6. Add Student to Waiting List\n";
        cout << "7. Remove Student from Waiting List\n";
        cout << "8. Display Waiting List\n";
        cout << "9. Undo Cancellation\n";
        cout << "10. Display Cancellation History\n";
        cout << "11. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAll(resources);
            break;

        case 2:
            displayAvailability(resources);
            break;

        case 3:
            cout << "Create Reservation selected.\n";
           manager.createReservation(resources, waitingList);
            break;

        case 4:
            cout << "Cancel Reservation selected.\n";
            manager.cancelReservation();
            break;

        case 5:
            cout << "Display Active Reservations selected.\n";
            manager.viewReservations();
            break;

        case 6:
            cout << "Add Student to Waiting List selected.\n";
            // addToWaitingList();
            break;

        case 7:
            cout << "Remove Student from Waiting List selected.\n";
            // removeFromWaitingList();
            break;

        case 8:
            cout << "Display Waiting List selected.\n";
            displayWaitingList(waitingList);
            break;

        case 9:
    manager.undoCancellation();
    break;

        case 10:
            cout << "Display Cancellation History selected.\n";
            manager.displayCancellationHistory();
            break;

        case 11:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

        if (choice != 11)
        {
            cout << "\nPress Enter to continue...";
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cin.get();
        }
    }

    return 0;
}