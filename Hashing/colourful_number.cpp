/* For Given Number N find if its COLORFUL number or not
Return 0/1
COLORFUL number:
A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:
N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 
Output : 1
*/


#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int ColorfulNumber(int A)
{

	unordered_map <long long, long long> newMap;
	long long product = 1;
	vector <int> digit;

	while(A) {
		digit.insert(digit.begin(),A%10);
		A = A/10;
	}

	for (auto i = 0; i < digit.size(); i++) {
		product = 1;
		cout << "product = ";
		for (auto j = i; j < digit.size(); j++) {
			product = product * digit[j];
			cout << product << '\t'; 
			if (newMap.find(product) != newMap.end())
				return 0;
			newMap.insert({product,product});
		}
		cout << endl;
	}

	return 1;
}

int main()
{
	//int no = 326; // 3 32 326, 2 26, 6
	int no = 123; // 1 12 123, 2 23, 3
	int result = 0;

    result = ColorfulNumber(no);
    if (result)
        cout << " Is ColorfulNumber " << result;
    else
        cout << " Is not ColorfulNumber ";
    cout << endl;

    return 0;
}