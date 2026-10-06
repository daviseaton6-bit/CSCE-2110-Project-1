#include "Sort.h"

using namespace std;


// NAME SORT


void merge(vector<Resource>& resources,
           int left,
           int mid,
           int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Resource> L(n1);
    vector<Resource> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = resources[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = resources[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].name <= R[j].name)
        {
            resources[k] = L[i];
            i++;
        }
        else
        {
            resources[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        resources[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        resources[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Resource>& resources,
               int left,
               int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(resources, left, mid);
        mergeSort(resources, mid + 1, right);

        merge(resources, left, mid, right);
    }
}


// TYPE SORT


void mergeType(vector<Resource>& resources,
               int left,
               int mid,
               int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Resource> L(n1);
    vector<Resource> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = resources[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = resources[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].type <= R[j].type)
        {
            resources[k] = L[i];
            i++;
        }
        else
        {
            resources[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        resources[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        resources[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortType(vector<Resource>& resources,
                   int left,
                   int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortType(resources, left, mid);
        mergeSortType(resources, mid + 1, right);

        mergeType(resources, left, mid, right);
    }
}


// AVAILABILITY SORT


void mergeAvailability(vector<Resource>& resources,
                       int left,
                       int mid,
                       int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Resource> L(n1);
    vector<Resource> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = resources[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = resources[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].availability <= R[j].availability)
        {
            resources[k] = L[i];
            i++;
        }
        else
        {
            resources[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        resources[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        resources[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortAvailability(vector<Resource>& resources,
                           int left,
                           int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortAvailability(resources, left, mid);
        mergeSortAvailability(resources, mid + 1, right);

        mergeAvailability(resources, left, mid, right);
    }
}