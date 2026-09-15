#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>

using namespace std;

struct Resource {
    string id;
    string name;
    string type;
    string availability;
};

vector<Resource> loadResources(const string& filename);

void displayAll(const vector<Resource>& resources);

void displayAvailability(const vector<Resource>& resources);

#endif