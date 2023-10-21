/* Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.

Input Format

The first argument given is the integer array A.

The second argument given is integer B.

Output Format

Return the total number of subarrays having bitwise XOR equals to B.

Example Input

Input 1:
 A = [4, 2, 2, 6, 4]
 B = 6

Input 2:
 A = [5, 6, 7, 8, 9]
 B = 5

Example Output
Output 1:
 4

Output 2:
 2
Example Explanation

Explanation 1:
 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Explanation 2:
 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
 */


#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int Count_SubArray_given_XOR(vector<int> &A, int K)
{
	int start = 0;
	int currXOR = 0;
	int count = 0;
	int len = A.size();

	for (int i = 0; i < len; i++) {

		currXOR = A[i];

		for (int j = i+1; j <= len; j++) {
			//currXOR = currXOR ^ K;
			if (currXOR == K)
				count++;
			currXOR = currXOR ^ A[j];
		}
	}

	// for (int i = 0; i < len; i++) {
	// 	currXOR = 0;
	// 	for (int j = i; j < len; j++) {
	// 		currXOR = currXOR ^ A[j];

	// 		if (currXOR == K)
	// 			count++;
	// 	}
	// }


	return count;
}



int Count_SubArray_pair_XOR_HashMap(vector<int> &A, int K)
{
	int start = 0;
	int currXOR = 0;
	int count = 0;
	//int len = A.size();
	int len = 5;
	map <int, int> newMap;

	//for (auto i = newMap.begin(); i != newMap.end(); i++) {

	for (auto i = 0; i < len; i++) {
		currXOR = currXOR ^ A[i];
		if (currXOR == K) {
			count++;
			cout << "count compare " << count << endl;
		}
		
		if (newMap[currXOR ^ K] != 0) {
			count = count + newMap[currXOR ^ K];
			cout << "Key " << (currXOR ^ K) << " found value " << newMap[currXOR ^ K] << endl;
			cout << "count " << count << endl;
		}
		cout << "Key: " << currXOR << " inital value : " << newMap[currXOR];
		newMap[currXOR]++;
		cout << " update value : " << newMap[currXOR] << endl;
	}

	// for (auto i = 0; i < len; i++) {
	// 	currXOR = currXOR ^ A[i];
	// 	newMap[currXOR]++; 
	// }

	// currXOR = 0;
	// for (auto i = 0; i < len; i++) {
	// 	//currXOR = currXOR ^ A[i];
	// 	if (newMap.find(A[i]) != newMap.end())
	// 		count = count + ;
	// 	if (newMap.find(K) != newMap.end())
	// 		count++;
	// }


	return count;
}

int main()
{
    vector<int> vect {4, 2, 2, 6, 4};
    int XORno = 6;
    // vector<int> vect{5, 6, 7, 8, 9};
    // int XORno = 5;

    int result =0;

    // result = Count_SubArray_given_XOR(vect, XORno);
    // if (result)
    //     cout << " XOR pairs count = " << result;
    // else
    //     cout << " No XOR pairs present ";
    // cout << endl;


    result = Count_SubArray_pair_XOR_HashMap(vect, XORno);
    if (result)
        cout << " XOR pairs count = " << result;
    else
        cout << " No XOR pairs present ";
    cout << endl;

    return 0;
}