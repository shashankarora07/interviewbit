/*
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.
If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.
Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
*/
#include<bits/stdc++.h>
using namespace std;

void twoSum(const vector<int> &A, int B)
{
    vector<int> res;
    auto size = A.size();
    unordered_map<int, int> hash;
    unordered_map<int, int>::iterator it;
    it = hash.begin();

    
    for (auto i = 0; i<size; ++i)
    {
        if (hash.find(B - A[i]) != hash.end())
        {
            cout << "inside i = " << i << endl; 
            res.emplace_back(hash[B - A[i]]);
            res.emplace_back(i+1);
            cout << "hash ready" << endl;
            for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
                cout << itr->first << '\t'
                << itr->second << '\n';
            }
            cout << "end of hash" << endl;
            cout << "print vector list" << endl;
            for (int i=0; i<res.size(); i++) 
                cout << res[i] << "  , ";
            cout << endl; 
            cout << "end of list" << endl;
            break;
        }
        if (hash.find(A[i]) == hash.end()) {
            hash[A[i]] = i+1;
            cout << "outside i = " << i << " - ";
            cout << endl;
            cout << "hash in find equal case" << endl;
            for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
                cout << itr->first << '\t'
                << itr->second << '\n';
            }
            cout << "end of hash find end ...." << endl;
            cout << endl;
        }
    }

    //for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
    //    cout << itr->first << '\t'
    //    << itr->second << '\n';
    //}

    //for (int i=0; i<res.size(); i++) 
    //   cout << res[i] << " ";
    //cout << endl; 

}

int main()
{
    const vector<int> A = {1,-2,1,0,5};
    int target = 1;

    twoSum(A,target);

    return 0;
}