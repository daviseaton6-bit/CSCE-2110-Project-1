#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Resource {
public:
	string id;
	string name;
	string type;
	string status;
	

	Resource(string i, string n, string s, string t ) {
		id = i;
		name = n;
		type = t;
		status = s;
	}

	void display() {
		cout << "Resource " << id << ": " << name << "|" << type << "|" << status << endl;
	}
};

void readResources(vector<Resource>& resources)
{
	ifstream file("resources.txt");

	if (!file.is_open())
	{
		cout << "Could not open resources.txt" << endl;
		return;
	}

	string id;
	string name;
	string type;
	string status;
	while (getline(file, id, '|')) {
		getline(file, name, '|');
		getline(file, type, '|');
		getline(file, status);

		resources.push_back(Resource(id, name, type, status));
	}

	file.close();

}

class Reservation {
public:
	int id;
	string resourceName;
	string studentName;

	Reservation(int i, string r, string s)
	{
		id = i;
		resourceName = r;
	    studentName = s;
	}
		void display() 
	{
			cout << "Reservation " << id << ": " << resourceName
				<< " booked by " << studentName << endl;
	}
};

int searchResourceById(vector<Resource>& resources, int id) 
{
	for (int i = 0; i < resources.size(); i++)
	{
		if (resources[i].id == id)
		{
			return i;
		}
	}
	return -1;
}

int searchReservationById(vector<Reservation>& reservations, int id)
{
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].id == id) 
		{
			return i;
		}
	}
	return -1;
}

vector<Reservation> searchByStudent(vector<Reservation>& reservations, string name)
{
	vector<Reservation> results;
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].studentName == name)
		{
			results.push_back(reservations[i]);
		}
	}
	return results;
}

int main()
{
	vector<Resource> resources;
	vector<Reservation> reservations;

	int choice;
	int id;
	string ID;
	string name;
	string resourceName;
	string type;
	string status;

	do
	{
		cout << "\n--- Reservation System ---\n";
		cout << "1. Add a resource \n";
		cout << "2. Add a reservation\n";
		cout << "3. Search resource by ID\n";
		cout << "4. Search reservation by Id\n";
		cout << "5.Find reservation by student name\n";
		cout << "0: Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter resource ID: ";
			cin >> id;
			cin.ignore();

			cout << "Enter resource name: ";
			getline(cin, name);

			resources.push_back(Resource(ID, name, type, status));
			cout << "Resource added." << endl;
		}
		else if (choice == 2)
		{
			cout << "Enter reservation ID: ";
			cin >> id;
			cin.ignore();

			cout << "Enter resource name: ";
			getline(cin, resourceName);

			cout << "Enter student name: ";
			getline(cin, name);
			reservations.push_back(Reservation(id, resourceName, name));
			cout << "Reservation added." << endl;
		}
		else if (choice == 3)
		{
			cout << "Enter resource ID: ";
			cin >> id;
			int index = searchResourceById(resources, id);
			if (index != -1)
			{
				resources[index].display();
			}
			else
			{
				cout << "Resource not found." << endl;
			}
		}
		else if (choice == 4)
		{
			cout << "Enter reservation ID: ";
			cin >> id;
			int index = searchReservationById(reservations, id);
			if (index != -1)
			{
				reservations[index].display();
			}
			else {
				cout << "Reservation not found." << endl;
			}
		}

		else if (choice == 5)
		{
			cout << "Enter student name: ";
			cin.ignore();
			getline(cin, name);
			vector<Reservation> found = searchByStudent(reservations, name);
			if (found.size() == 0) {
				cout << "No reservations for this student." << endl;
			}
			else {
				for (int i = 0; i < found.size(); i++)
				{
					found[i].display();
				}
			}
		}
		
		


	}
	while (choice != 0);
	return 0;

}
