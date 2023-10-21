/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

*/

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

bool isAllConditionValid(vector<int> A, long long mid, int size, int H)
{
    long long hoursCount = 0;
    int remaining_banana_pile = 0;
   // cout << "hoursCount = " << hoursCount << endl;

    for (int i = 0; i < size; i++)
    {
        if (A[i] < mid) {
            hoursCount++;
        }
        else if (A[i] % mid == 0) {
            hoursCount +=  (A[i]/mid);
        }
        else 
            hoursCount += (A[i] / mid) + 1;
    }
   // cout << "hoursCount = " << hoursCount << endl;

    if ( hoursCount <= H )
        return true;

    return false;
}


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    
    long size = piles.size();
    long long start = 1;
    long long end = maxElementinArr(piles, size);
    int res = 0;
    long long mid = 0;

    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        //cout << "start: " << start << " end: " << end << " mid: " << mid << endl;

        if (isAllConditionValid(piles, mid, size, h) == true) {
            res = mid;
            end = mid - 1;
            
            //cout << "$$$$$ res = " << res << endl;
        }
        else 
            start = mid + 1;
    }

    return res;       
    }
};