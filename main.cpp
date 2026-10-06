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
#include "Sort.h"

using namespace std;

int main()
{
    vector<Resource> resources = loadResources("resources.txt");
    ReservationManager manager;
    queue<Reservation> waitingList;
    int choice = 0;

while (choice != 14)
{
    cout << "\n===== Campus Resource Reservation System =====\n";
    cout << "1. Display All Resources\n";
    cout << "2. Display Resource Availability\n";
    cout << "3. Create Reservation\n";
    cout << "4. Cancel Reservation\n";
    cout << "5. Display Active Reservations\n";
    cout << "6. Search Reservation\n";
    cout << "7. Waiting List Information\n";
    cout << "8. Remove Student from Waiting List\n";
    cout << "9. Display Waiting List\n";
    cout << "10. Undo Cancellation\n";
    cout << "11. Display Cancellation History\n";
    cout << "12. Sort Menu\n";
    cout << "13. Generate Report\n";
    cout << "14. Exit\n";
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
        cout << "Search Reservation selected.\n";
        manager.searchReservation();
        break;

    case 7:
        cout << "Waiting List Information\n";
        cout << "Students are automatically added when a resource is unavailable.\n";
        break;

    case 8:
        cout << "Remove Student from Waiting List selected.\n";

        try
        {
            Reservation next = processNext(waitingList);

            cout << "Removed from waiting list:\n";
            next.display();
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }

        break;

    case 9:
        cout << "Display Waiting List selected.\n";
        displayWaitingList(waitingList);
        break;

    case 10:
        manager.undoCancellation();
        break;

    case 11:
        cout << "Display Cancellation History selected.\n";
        manager.displayCancellationHistory();
        break;

case 12:
{
    int sortChoice;

    cout << "\n===== Sorting Menu =====\n";
    cout << "1. Sort Resources By Name\n";
    cout << "2. Sort Resources By Type\n";
    cout << "3. Sort Resources By Availability\n";
    cout << "4. Return to Main Menu\n";
    cout << "Enter Choice: ";

    cin >> sortChoice;

    switch (sortChoice)
    {
    case 1:
        mergeSort(resources, 0, resources.size() - 1);

        cout << "\nResources sorted by name.\n";
        displayAll(resources);
        break;

    case 2:
        mergeSortType(resources, 0, resources.size() - 1);

        cout << "\nResources sorted by type.\n";
        displayAll(resources);
        break;

    case 3:
        mergeSortAvailability(resources, 0, resources.size() - 1);

        cout << "\nResources sorted by availability.\n";
        displayAll(resources);
        break;

    case 4:
        break;

    default:
        cout << "Invalid sorting choice.\n";
    }

    break;
}
    case 13:
        cout << "\n===== System Report =====\n";

        cout << "Resources Loaded: "
             << resources.size() << endl;

        cout << "\nCurrent Waiting List:\n";
        displayWaitingList(waitingList);

        cout << "\nCancellation History:\n";
        manager.displayCancellationHistory();

        break;

    case 14:
        cout << "Exiting program...\n";
        break;

    default:
        cout << "Invalid choice.\n";
    }

    if (choice != 14)
    {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}

    return 0;
}