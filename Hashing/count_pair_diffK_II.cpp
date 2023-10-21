#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int count_pair_diffK_IISolution(vector<int> &A, int k)
{
    unordered_set<int>s;
    int count = 0;

    for(auto v:A)
    {
        int t1=v+k;
        int t2=v-k;
        if(s.find(t1)!=s.end() || s.find(t2)!=s.end()) 
        	count++;

        s.insert(v);
    }
    return count;
}

int count_pair_diffK(vector<int> &A, int K)
{
	map<int, int> newMap;
	int count = 0;
	int len = A.size();

	for (int i = 0; i < len; i++)
	{
		newMap[A[i]]++;
	}

	for (auto i = newMap.begin(); i != newMap.end(); i++)
	{

		if (newMap.find(i->first + K) != newMap.end()) {
			if (K == 0 && i->second > 1) {		
				count++;
			}
			else if (K != 0)
			{
				count++;
			}
		
		}
	}

	return count;
}

int main()
{
	vector<int> vect{1,3, 1, 5, 4};
	// vector<int> vect {66, 37, 46, 56, 49, 65, 62, 21, 7, 70, 13, 71, 93, 26, 18, 84, 96, 65, 92, 69, 97, \
	// 	47, 6, 18, 17, 47, 28, 71, 70, 24, 46, 58, 71, 21, 30, 44, 78, 31, 45, 65, 16, 3, 22, 54, 51, 68, \
	// 	19, 86, 44, 99, 53, 24, 40, 92, 38, 81, 4, 96, 1, 13, 45, 76, 77, 8, 88, 50, 89, 38, 60, 61, 49, 25, \
	// 	10, 80, 49, 63, 95, 74, 29, 27, 52, 27, 40, 66, 38, 22, 85, 22, 91, 98, 19, 20, 78, 77, 48, 63, 27};
	//vector<int> vect{1, 2, 3};
	int result =0;
	int diffK = 2;

	result = count_pair_diffK_IISolution(vect, diffK);
	if (result)
		cout << " pairs count = " << result;
	else
		cout << " No pairs present ";
	cout << endl;

	// result = TwoSum_2nd(vect, target);
	// cout << result[0] << " and " << result[1] << endl;
	return 0;
}