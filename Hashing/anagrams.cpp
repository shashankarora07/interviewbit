/*
Given an array of strings, return all groups of strings that are anagrams.
Represent a group by a list of integers representing the index in the
original list. Look at the sample case for clarification.

    Anagram : a word, phrase, or name formed by rearranging the letters of
    another, such as 'spar', formed from 'rasp'

    Note:  All inputs will be in lower-case.

Example :

Input : cat dog god tca 
Output : [[1, 4], [2, 3]]

cat and tca are anagrams which correspond to index 1 and 4. 

dog and god are another set of anagrams which correspond to index 2 and 3.

The indices are 1 based ( the first element has index 1 instead of index 0).

    Ordering of the result : You should not change the relative ordering of
    the words / phrases within the group. Within a group containing A[i] and
    A[j], A[i] comes before A[j] if i < j.
*/

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/*
c ->> 99 --> 1
a ->> 97 --> 1
t ->> 116 --> 1

t ->> 116 --> 4
a ->> 97 --> 4
c ->> 99 --> 4
*/

string NewSort(string s)
{
	vector<int> v;
	for (auto i = 0; i < s.length(); i++) {
		v.push_back((int)s[i]);
	}
	sort(v.begin(), v.end());
	string str = "";
	for (auto i = 0; i < s.length(); i++)
		str = str + (char)v[i];

	return str;
}

vector<vector<int>> anagrams_IndexMatch(const vector<string> &A)
{
	vector<vector<int>> result;
	unordered_map<string, vector<int>> newMap;

	for (auto i = 0; i < A.size(); i++)
		cout << A[i] << ' ';
	cout << endl;

	for (auto i = 0; i < A.size(); i++) {
		string str = NewSort(A[i]);
		newMap[str].push_back(i+1);
	}
	int i = 0;
	for (auto it = newMap.begin(); it != newMap.end(); it++) {
		cout << "i = "<< i << " it = " << it->first << ", ";
		result.push_back(it->second);
		i++;
	}
	cout << endl;
	return result;
}



int main()
{
	vector<vector<int>> arr;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(4);
	arr.push_back(v1);
	v1.clear();
	v1.push_back(2);
	v1.push_back(3);
	arr.push_back(v1);
	//arr.push_back(6);

	for (int i = 0; i < 2; i++) {
		cout << "at i = " << i << ": ";
		for (auto it = arr[i].begin(); it != arr[i].end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}

	vector<string> anagrams_str{"cat", "dog", "god", "tca"};
	arr = anagrams_IndexMatch(anagrams_str);

	for (int i = 0; i < arr.size(); i++) {
		cout << "at i = " << i << ": ";
		for (auto it = arr[i].begin(); it != arr[i].end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}

	return 0;
}