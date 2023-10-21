#include<bits/stdc++.h>

using namespace std;

vector<string> vs;

void subsetUnqiue(string ipstr, string outstr)
{
    if (ipstr.length() == 0) {
        vs.push_back(outstr);
        return;
    }

    string outstr1 = outstr;
    string outstr2 = outstr;

    outstr2.push_back(ipstr[0]);
    ipstr.erase(ipstr.begin() + 0);

    subsetUnqiue(ipstr, outstr1);
    subsetUnqiue(ipstr, outstr2);

    return;
}
int main()
{
    string str = "aabc";
    string out = "";

    subsetUnqiue(str, out);

    cout << "set of subset: ";
    for (auto its = vs.begin(); its != vs.end(); its++) {
        cout << *its << " ";
    }
    cout << endl;

    unordered_set<string> setunique;
    for (auto its = vs.begin(); its != vs.end(); its++) {
        setunique.insert(*its);
    }
    cout << "set of unique subset: ";
    for (auto its = setunique.begin(); its != setunique.end(); its++) {
        cout << *its << " ";
    }
    cout << endl;

    return 0;
}