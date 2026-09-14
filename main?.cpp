#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
using namespace std;

int main()
{
    queue<Reservation> waitingList; 
    stack<Reservation> cancellationHistory;
    vector<Resource> resources = loadResources("resources.txt");
    
    cout << "===== Campus Resource Reservation System ===== \n 1.View Resources \n 2. Create Reservation\n 3.Cancel Reservation \n 4.View Waiting Lists \n 5.Undo Cancellation \n 6.Search Reservations \n 7.Sort Resources \n 8.Generate Report \n 9.Exit \n Enter Choice: ";
    int choice;
    cin >> choice

    //potential way to re-ask the cout and cin statement for next input
    while (choice != 9) {
      
      //View Resources
      if (choice == 1) 
      {
          displayAll(resources);
          displayAvailability(resources)
          
      }
      //Create reservation
      if (choice == 2) 
      {

      }
      //Cancel Reservation
      if (choice == 3) 
      {

      }
      //View Waiting Lists
      if (choice == 4) 
      {
          displayWaitingList(waitingList);
      }  
      //Undo Cancellation
      if (choice == 5) 
      {
          undo(cancellationHistory);
      }
      //Search Reservations
      if (choice == 6) 
      {

      }
      //Sort Resources
      if (choice == 7) 
      {

      }
      //Generate Report
      if (choice == 8) 
      {

      }
      //Exit
      if (choice == 9) 
      {
          return 0;
      }
    }
      return 0;
  }
