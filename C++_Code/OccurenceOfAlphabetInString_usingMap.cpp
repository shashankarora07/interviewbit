#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void NoOfOccurence_Ofchar_inString_usingMap(string str)
{
    int len = str.size();
    int i = 0;

    map <char, int> A;

    map <char, int>::iterator itr;

    for (itr = A.begin(), i = 0; itr != A.end(), i < len; ++itr, i++) {
        if (islower(str[i]))
            A[str[i]]++;
        if (isupper(str[i]))
            A[str[i]]++;
    }
        

    for (itr = A.begin(); itr != A.end(); ++itr) {

        cout << itr->first << " - " << itr->second << endl;
    }

}


int main()
{
    string str = "Hi bro how are you. are u following geeks for geeks";
    //string str = "Hibrohow areyouareufollowinggeeksforgeeks";

    NoOfOccurence_Ofchar_inString_usingMap(str);

    return 0;
}