/*

Given an integer array A of size N, find the first repeating element in it.

We need to find the element that occurs more than once and whose index of first occurrence is smallest.

If there is no repeating element, return -1.

Example Input

Input 1:

 A = [10, 5, 3, 4, 3, 5, 6]

Input 2:

 A = [6, 10, 5, 4, 9, 120]

Example Output

Output 1:

 5

Output 2:

 -1

*/

#include <bits/stdc++.h>

using namespace std;

int firstRepeatingElement(vector<int> &A)
{
	//unordered_map<int, int> map;
	set<int> hash_set;
	int result = -1;
	int len = A.size();
	for(int i = len -1; i >= 0; --i) {
		if (hash_set.find(A[i]) != hash_set.end())
			result = A[i];
		else
			hash_set.insert(A[i]);
	}

	return result;
}


int main()
{
	vector<int> vect{4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
	int result =0;

	result = firstRepeatingElement(vect);
	if (result)
		cout << " first repeating element : " << result;
	else
		cout << " No duplicate element ";
	cout << endl;

	// result = TwoSum_2nd(vect, target);
	// cout << result[0] << " and " << result[1] << endl;
	return 0;
}

