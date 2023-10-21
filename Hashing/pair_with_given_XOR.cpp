 /* Given an 1D integer array A containing N distinct integers.

Find the number of unique pairs of integers in the array whose XOR is equal to B.

NOTE:

Pair (a, b) and (b, a) is considered to be same and should be counted once.

Problem Constraints

1 <= N <= 105

1 <= A[i], B <= 107

Input Format

First argument is an 1D integer array A.

Second argument is an integer B.

Output Format

Return a single integer denoting the number of unique pairs of integers in the array A whose XOR is equal to B.


Example Input

Input 1:

 A = [5, 4, 10, 15, 7, 6]
 B = 5

Input 2:

 A = [3, 6, 8, 10, 15, 50]
 B = 5

Example Output

Output 1:

 1

Output 2:

 2

Example Explanation

Explanation 1:

 (10 ^ 15) = 5

Explanation 2:

 (3 ^ 6) = 5 and (10 ^ 15) = 5 
*/


#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int Count_Pair_XOR(vector<int> &A, int K)
{
    map<int, int> newMap;
    int count = 0;
    int len = A.size();
    auto itr = newMap.begin();
    cout << "itr->first = " << itr->first << endl;

    for (int i = 0; i < len; i++)
    {
        newMap[A[i]]++;
    }

    for (auto i = newMap.begin(); i != newMap.end(); i++)
    {

        if (newMap.find(i->first ^ K) != newMap.end()) {
            count++;
            newMap.erase(i->first ^ K);
        }
    }

    return count;
}

int main()
{
    // vector<int> vect{5, 4, 10, 15, 7, 6};
    vector<int> vect {3, 6, 8, 10, 15, 50};
    //vector<int> vect{1, 2, 3};
    int result =0;
    int XORno = 5;

    result = Count_Pair_XOR(vect, XORno);
    if (result)
        cout << " XOR pairs count = " << result;
    else
        cout << " No XOR pairs present ";
    cout << endl;

    // result = TwoSum_2nd(vect, target);
    // cout << result[0] << " and " << result[1] << endl;
    return 0;
}