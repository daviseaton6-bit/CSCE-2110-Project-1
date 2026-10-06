#ifndef SORT_H
#define SORT_H

#include "Display.h"

void mergeSort(vector<Resource>& resources, int left, int right);

void mergeSortType(vector<Resource>& resources,
                   int left,
                   int right);

void mergeSortAvailability(vector<Resource>& resources,
                           int left,
                           int right);
#endif