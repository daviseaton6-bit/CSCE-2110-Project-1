#ifndef RESERVATION_H
#define RESERVATION_H

#include <queue>
#include <stack>
#include <string>

using namespace std;
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
};

#endif
