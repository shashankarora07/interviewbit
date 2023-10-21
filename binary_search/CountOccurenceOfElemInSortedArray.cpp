#include <bits/stdc++.h>

using namespace std;

int firstOccOfElemBinarySearch(vector<int> vec, int findElem, int start, int end)
{
    int firstInst = -1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (vec[mid] == findElem) {
            firstInst = mid;
            end = mid - 1;
        }
        else if (vec[mid] > findElem)
            end = mid - 1;
        else
           start = mid + 1;


    }

    return firstInst;
}

int lastOccOfElemBinarySearch(vector<int> vec,int findElem, int start, int end)
{
    int lastInst = -1;
    cout << "start = " << start << " end = " << end << endl;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (vec[mid] == findElem) {
            lastInst = mid;
            start = mid + 1;
        }
        else if (vec[mid] > findElem)
            end = mid - 1;
        else 
            start = mid + 1;

    }

    return lastInst;
}

void countOccurenceOfElemInSortedArr(vector<int> vec, int elemTosearch, int &NumOcc)
{
    int start = 0, end = vec.size() - 1;
    int firstOcc = firstOccOfElemBinarySearch(vec, elemTosearch, start, end);
    int lastOcc = lastOccOfElemBinarySearch(vec, elemTosearch, start, end);

    cout << "firstOcc = " << firstOcc << endl;
    cout << "lastOcc = " << lastOcc << endl;
    if (lastOcc == -1 && firstOcc == -1)
        NumOcc = 0;
    else
        NumOcc = lastOcc - firstOcc + 1;

} 



int main()
{
    vector<int> v{2,5,8,10,10,10,12,18,25,31};
    //vector<int> v{1};
    int NumOcc = -1;
    int Elem = 11;

    countOccurenceOfElemInSortedArr(v, Elem, NumOcc);
    cout << "Count the occurence of element in sorted array: " << NumOcc << endl;

    return 0;
}