#include <bits/stdc++.h>

using namespace std;

void towerOfHanoi(int N, vector<int> &iv, vector<int> &dv, vector<int> &hv)
{
    if (N == 1) {
        dv.push_back(iv[N-1]);
        iv.pop_back();
        return;
    }

    hv.push_back(iv[N-1]);
    iv.pop_back();

    cout << "check";
    for (auto i = iv.begin(); i != iv.end(); i++ ) {
        cout << *i << ' ';
    }
    cout  << endl;
    towerOfHanoi(N -1, iv, dv, hv);

    //towerOfHanoi();

}

int main()
{
    vector<int> is;
    vector<int> ds;
    int noOfPlates = 8;
    vector<int> hs;

    for (int i = 1; i <= noOfPlates; i++)
        is.push_back(i);
    
    cout << "vector Input: " << endl;
    for (auto i = is.begin(); i != is.end(); i++ ) {
        cout << "plate: " << *i << " ";
        cout << endl;
    }
    cout << endl;
    
    towerOfHanoi(noOfPlates, is, ds, hs);

    cout << "Output vector: " << endl;
    for (auto i = ds.begin(); i != ds.end(); i++ ) {
        cout << "plate: " << *i << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}