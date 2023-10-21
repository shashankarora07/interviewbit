#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_set<int> hash;
    for(int i=0;i<A.size();i++){
        hash.insert(A[i]);
    }
    int l=1;
    int maxl=1;
    for(int i=0;i<A.size();i++){
        int j=1;
        l=1;
        if(hash.find(A[i]-1)==hash.end()){ //will work also with A[i]
			cout << A[i] << '\t';   /* A[i]-1 confirms that sequence will start from A[i] element. in other words, if A[i]-1    exists. means might possible sequence will start from A[i]-1 element */
            while(hash.find(A[i]+j)!=hash.end()){
                // h.insert(A[i]+j);
				cout << A[i]+j << '\t';
                j++;
                l++;
            }
			cout << "-------------" << endl;
            if(l>maxl){
                maxl=l;
            }
        }
    }
    return maxl;
}

int main()
{
	const vector<int> g{1, 9, 3, 10, 4, 20, 5};
	int no = longestConsecutive(g);
	cout << "no = "<<no;

}
