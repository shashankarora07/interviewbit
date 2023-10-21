/* Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
*/


// #include<iostream>
// #include <vector>
// #include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
	// *x = *x ^ *y;
	// *y = *x ^ *y;
	// *x = *x ^ *y;
	int tmp = *y;
	*y = *x;
	*x = tmp;
}

int partition(vector<int> &A, int low, int high)
{
	int pivot = A[high];
	int index = low -1;
	cout << pivot << "   " << index <<endl;
	for (int i = low; i <= high-1; i++)
	{
		if (A[i] < pivot) {
			index++;
			swap(&A[index],&A[i]);
		}
	}
	swap(&A[index+1],&A[high]);

	return (index+1);
}

void QuickSort(vector<int> &arr, int start, int end)
{
	if (start < end) {

	int mid  = partition(arr,start,end);
	QuickSort(arr,start,mid-1);
	QuickSort(arr,mid+1,end);
	}

}

vector<int> TwoSum(const vector<int> &A, int B)
{
	unordered_map<int, int> map;
	vector<int> result;
	int len = A.size();


	for (int i = 0; i < len; i++)
	{
		
		if (map.find(B - A[i]) != map.end())
		{
			// result.insert(result.begin(), B - A[i]);
			// result.insert(result.begin(), i);
			result.push_back(map[B - A[i]]);
			result.push_back(i);
			return result;
		}
		if (map.find(A[i]) == map.end())
			map[A[i]] = i;
	
	}

	return result;
}

vector<int> TwoSum_2nd(vector<int> &A, int B)
{
	int len = A.size();
	vector<int>	result;
	int l = 0,r = len-1;
	cout << len <<endl;
	// sort(A.begin(),A.end());

	// for_each(A.begin(), A.end(), [](int x) {  
 //    cout << x << " ";  
 //  	});

//int arr[] = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
  	QuickSort(A,0,len-1);  
	for_each(A.begin(), A.end(), [](int x) {  
    cout << x << " ";  
  	});
	cout << endl;

	while (l < r)
	{
		if (A[l] + A[r] == B) {
			result.push_back(l);
			result.push_back(r);
			return result;
		}
		
		if (A[l] + A[r] > B)
			r--;
		else
			l++; 

	}

	result = {0,0};
	return result;
}

int main()
{
	// vector<int> vect{2,7,11,15};
	// int target = 9;
	vector<int> vect{4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
	int target = -3;
	vector<int> result;

	result = TwoSum(vect, target);
	cout << result[0] << " and " << result[1] << endl;

	result = TwoSum_2nd(vect, target);
	cout << result[0] << " and " << result[1] << endl;
	return 0;
}
