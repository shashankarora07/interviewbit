#include <bits/stdc++.h>

using namespace std;

int binarySearchRecursion(vector<int> v, int elemToFind, int start, int end)
{

    if (start <= end)
    {
        int mid = start + ((end - start) / 2);
        cout << "start: " << start << " end: " << end << " mid: " << mid << endl;

        if (elemToFind == v[mid]) {
            cout << "Element found at " << mid << endl;
            return mid;
        }
        else if (elemToFind < v[mid]) {
            int mid1 = binarySearchRecursion(v, elemToFind, start, mid-1);
            return mid1;
        }
        else {
            int mid2 = binarySearchRecursion(v, elemToFind, mid+1, end);
            return mid2;
        }

    }
    return -1;  
}


int binarySearch(vector<int> v, int elemToFind)
{
    int start = 0;
    int end = v.size() - 1;

    while(start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (elemToFind == v[mid])
            return mid;
        else if (elemToFind < v[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}


int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    int elementToFind = 2;
    int start = 0, end = vec.size() - 1;

    //int status = binarySearch(vec, elementToFind);
    int status = binarySearchRecursion(vec, elementToFind, start, end);
    if (status >= 0) {
        cout << "Element: " << elementToFind << " is found at '" << status << "' index";
    } else {
        cout << "Element: " << elementToFind << " is not found";
    }
    cout << endl;

    return 0;
}