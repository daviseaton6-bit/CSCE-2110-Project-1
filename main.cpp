#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Display.h"
using namespace std;

int main()
{
    vector<Resource> resources = loadResources("resources.txt");

    int choice = 0;

    while (choice != 9)
    {
        cout << "\n===== Campus Resource Reservation System =====\n";
        cout << "1. View Resources\n";
        cout << "2. Create Reservation\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. View Waiting Lists\n";
        cout << "5. Undo Cancellation\n";
        cout << "6. Search Reservations\n";
        cout << "7. Sort Resources\n";
        cout << "8. Generate Report\n";
        cout << "9. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        if (choice == 1)
        {
            displayAll(resources);
            displayAvailability(resources);

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else if (choice == 2)
        {
            cout << "Create Reservation selected.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else if (choice == 3)
        {
            cout << "Cancel Reservation selected.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else if (choice == 4)
        {
            cout << "View Waiting Lists selected.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else if (choice == 5)
        {
            cout << "Undo Cancellation selected.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else if (choice == 6)
        {
            cout << "Search Reservations selected.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else if (choice == 7)
        {
            cout << "Sort Resources selected.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else if (choice == 8)
        {
            cout << "Generate Report selected.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else if (choice != 9)
        {
            cout << "Invalid choice.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }

    cout << "Exiting program...\n";
    return 0;
}