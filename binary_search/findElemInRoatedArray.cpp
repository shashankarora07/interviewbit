#include <bits/stdc++.h>

using namespace std;


int binarySearch(vector<int> v, int start, int end, int target)
{
    while(start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int findMinimumNoIndex(vector<int> v, int start, int end)
{
    int mid = 0, prev_elem = 0, next_elem = 0;
    int N_elem = v.size();

    cout << "starts: " << __func__ << endl; 
    while(start <= end)
    {
        mid = start + ((end - start) / 2);
        prev_elem = (mid + N_elem - 1) % N_elem; 
        next_elem = (mid + 1) % N_elem; 
        
        cout << "start: " << start << " end: " << end << " mid: " << mid << endl;
        if (v[mid] <= v[prev_elem] && v[mid] <= v[next_elem]) {
            cout << "Element found at " << mid << endl;
            return mid;
        }
        else if (v[mid] <= v[end])
            end = mid - 1;
        //else if (v[mid] <= v[end]) 
        else
            start = mid + 1;  
    }

    cout << "ends: " << __func__ << endl; 
    return -1;
}

int search(vector<int>& nums, int target) 
{
    int start = 0;
    int N_elem = nums.size();
    int end = nums.size() - 1;
    int result = -1;

    int index = findMinimumNoIndex(nums, start, end);
    int mid1 = binarySearch(nums, 0, index - 1, target);
    int mid2 = binarySearch(nums, index, end, target);
    if (mid1 >= 0)
        result = mid1;
    if (mid2 >= 0)
        result = mid2;
    return result;
}

int main()
{
    //vector<int> vec{4,5,6,7,0,1,2};
    vector<int> vec{1};
    int elementToFind = 1;

    int ret = search(vec, elementToFind);
    cout << "ret = " << ret << endl;


    return 0;
}