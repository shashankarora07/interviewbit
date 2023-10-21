/*
Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.
NOTE:
A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

Problem Constraints
3 <= N <= 105
1 <= A[i], B <= 108

Given array always contain a bitonic point.
Array A always contain distinct elements.

Input Format
First argument is an integer array A denoting the bitonic sequence.
Second argument is an integer B.

Output Format
Return a single integer denoting the position (0 index based) of the element B in the array A if B doesn't exist in A return -1.

Example Input
Input 1:

 A = [3, 9, 10, 20, 17, 5, 1]
 B = 20

Input 2:
 A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
 B = 30

Example Output
Output 1:

 3

Output 2:

 -1

Example Explanation

Explanation 1:

 B = 20 present in A at index 3

Explanation 2:

 B = 30 is not present in A

*/


#include <bits/stdc++.h>

using namespace std;

int binarySearchRight(vector<int> v, int target, int start, int end)
{
    int mid = 0;
    
    while (start <= end)
    {
        mid = start + ((end - start) / 2);

        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1; 
}

int binarySearchleft(vector<int> v, int target, int start, int end)
{
    int mid = 0;
    
    while (start <= end)
    {
        mid = start + ((end - start) / 2);

        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1; 
}

int findLargestElemInArr(vector<int> v, int size, int start, int end)
{
    int mid = 0;

    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        int prev = (mid + size - 1) % size;
        int next = (mid + 1) % size;

        if (mid > 0 && mid < size - 1)
        {
        
            if (v[mid] > v[prev] && v[mid] > v[next] )
            {
                return mid;
            }
            else if (v[mid] < v[prev])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if ( mid == 0) // This part is not required for bitonic case. Only it need in peak element case
        {
            if (v[mid] > v[mid + 1])
                return mid;
            else
                return mid + 1;
        }
        else if ( mid == size - 1)
        {
            if (v[mid] > v[mid - 1])
                return mid;
            else
                return mid - 1;
        }
    }
       
}

int searchinBitonicArray(vector<int> A, int B)
{
    int start = 0;
    int N = A.size();
    int end = N - 1;
    int mid = 0;

    int index = findLargestElemInArr(A, N, start, end);
    cout << "index = " << index << endl;
    int num1 = binarySearchleft(A, B, 0, index);
    int num2 = binarySearchRight(A, B, index+1, end);
    
    int res = (num1 > num2) ? num1 :  num2;

    return res;
}


int main()
{
    //vector<int> vec{3, 9, 10, 20, 17, 5, 1};
    vector<int> vec{10, 15, 16, 17, 18, 19, 21, 4, 3, 2, 1, 0};
    //vector<int> vec{1};
    int elementToFind = 0;

    int ret = searchinBitonicArray(vec, elementToFind);
    cout << "ret = " << ret << endl;



    return 0;
}