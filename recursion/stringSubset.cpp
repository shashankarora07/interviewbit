#include <bits/stdc++.h>

using namespace std;

void subset(string ipstr, string outstr)
{
    if (ipstr.length() == 0) {
        cout << outstr << " ";
        return;
    }

    string outstr1 = outstr;
    string outstr2 = outstr;

    outstr2.push_back(ipstr[0]);
    ipstr.erase(ipstr.begin() + 0);
    subset(ipstr, outstr1);
    subset(ipstr, outstr2);

    return;
}

int main()
{
    string istr = "ab";
    string ostr = "";

    subset(istr,ostr);
    cout << endl;

    return 0;
}