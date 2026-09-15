#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Display.h"
#include "QueueNStack.h"
using namespace std;

int main()
{
    vector<Resource> resources = loadResources("resources.txt");
    queue<Reservation> waitingList;
    stack<Reservation> cancellationHistory;
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
            // createReservation();
            break;

        case 4:
            cout << "Cancel Reservation selected.\n";
            // cancelReservation();
            break;

        case 5:
            cout << "Display Active Reservations selected.\n";
            // displayReservations();
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
{
Reservation restored = undo(cancellationHistory);
if (!restored.resID.empty())
{
cout << "Restored: "
<< restored.stuName
<< endl;
}
break;

}

        case 10:
            cout << "Display Cancellation History selected.\n";
            displayHistory(cancellationHistory);
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
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}