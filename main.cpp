#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//struct to hold all the items in the resources 
struct Resource {
    string id;
    string name;
    string type;
    string availability;
};
//storing the stuff in a vector
vector<Resource> loadResources(const string& filename) {
    vector<Resource> resources;
    ifstream file(filename);
//making sure the file can open, could remove if we dont want it for clutter reduction 
    if (!file.is_open()) {
        cout << "Could not open file.\n";
        return resources;
    }
//reading the lines then keeping the | to make it neat? could replace w/ other stuff 
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, type, availability;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, type, '|');
        getline(ss, availability, '|');
//added resources to the vector
        resources.push_back({id, name, type, availability});
    }

    return resources;
}
//displaying it all to make it neat 
void displayAll(const vector<Resource>& resources) {
    cout << "\n=== All Resources ===\n";
    for (const auto& r : resources) {
        cout << r.id << " | " << r.name << " | " << r.type 
             << " | " << r.availability << endl;
    }
}
//this is the avalibility part made it seperate from the rest
void displayAvailability(const vector<Resource>& resources) {
    cout << "\n=== Resource Availability ===\n";
    for (const auto& r : resources) {
        cout << r.name << " -> " << r.availability << endl;
    }
}

int main() {
    vector<Resource> resources = loadResources("resources.txt");
//again this was just to fact check my work, could be removed 
    if (resources.empty()) {
        cout << "No resources loaded.\n";
        return 1;
    }
// displays the code 
    displayAll(resources);
    displayAvailability(resources);

    return 0;
}
