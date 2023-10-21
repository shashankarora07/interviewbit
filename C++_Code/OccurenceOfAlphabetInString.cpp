#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 52


void NoOfOccurence_Ofchar_inString(string str)
{
    int len = str.size();

    int occurence[SIZE];

    memset(occurence,0,sizeof(occurence));

    for (int i = 0; i < len; i++) {
        if (islower(str[i]))
            occurence[str[i] - 'a']++;
        if (isupper(str[i]))
            occurence[str[i+26] - 'A']++;
    }
        

    for (int i = 0; i < len; i++) {

        if ( (occurence[str[i] - 'a'] != 0) && islower(str[i]) ) {
            cout << str[i] << " - " << occurence[str[i] - 'a'] << endl;
            occurence[str[i] - 'a'] = 0;
        }
        else if ( (occurence[str[i+26] - 'A'] != 0) && isupper(str[i]) ) {
            cout << str[i] << " - " << occurence[str[i+26] - 'A'] << endl;
            occurence[str[i+26] - 'A'] = 0;
        }

    }

}


int main()
{
    string str = "Hi bro how are you. are u following geeks for geeks";
    //string str = "Hibrohow areyouareufollowinggeeksforgeeks";

    NoOfOccurence_Ofchar_inString(str);

    return 0;
}