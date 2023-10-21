#include <bits/stdc++.h>

using namespace std;

int maxElementinArr(vector<int> arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

/* Condition to be met */
// Can divide each pile into any number of sub piles
// Allocate piles of candies to k students such that each student gets the same number of candies.

/* Return the maximum number of candies each student can get.*/
bool isAllConditionValid(vector<int> A, int mid, int size, int K)
{
    int allocate_piles = 0;

    for (int i = 0; i < size; i++)
    {
        allocate_piles += (A[i] / mid);
        if ( allocate_piles >= K)
            return true;
    }

    return false;
}

int maxCandiesTo_K_Student(vector<int> A, int k)
{
    int size = A.size();
    int start = 1;
    int end = maxElementinArr(A, size);
    int res = 0;
    int mid = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;
        cout << "start: " << start << " end: " << end << " mid: " << mid << endl;

        if (isAllConditionValid(A, mid, size, k) == true) {
            res = mid;
            start = mid + 1;
            cout << "$$$$$ res = " << res << endl;
        }
        else 
            end = mid - 1;
    }

    return res;  
}

int main()
{
    //vector<int> A{5, 8, 6};
    //vector<int> A{2, 5, 3};
    vector<int> A{4, 5, 7};
    int K = 4;
    int res = 0;

    for(auto vecElem = A.begin(); vecElem != A.end(); vecElem++)
        cout << *vecElem << "  ";
    cout << endl;

    res = maxCandiesTo_K_Student(A,K);
    cout << "res = " << res << endl;

    return 0;
}