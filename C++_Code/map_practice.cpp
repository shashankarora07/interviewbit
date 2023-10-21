#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
cout << "map begin" << endl;
    unordered_map <int, int> A;
    unordered_map <int, int>::iterator itr;

   A.insert({10,1});
   A.insert({5,1});
   A.insert({15,2});
   A.insert({10,3});
  //A[10]++;
    //A[5]++;
    //A[10]++;
    
    //it = A.begin();
    cout << "coming in find" << endl;
    //cout << it->first << it->second << endl;
    cout << "coming nd" << endl;
    for (auto i = A.begin(); i != A.end(); ++i) {
        cout << i->first << '\t' << i->second << endl;
    }
   	
    cout << "#####################" << endl;
	auto pos = A.find(5);
	for (auto it = pos; it != A.end(); it++)
        cout << it->first << '\t' << it->second << endl;
    cout << "#####################" << endl;

    for (auto itr = A.begin(); itr != A.end(); ++itr) {
    //for (auto i = 0; i < 2; ++i) {
        if (A.find(5) != A.end()) { /* A.find(5) tries to find in map and it is able to find the element, therefore, it return iterator which points to the  element and prints all element till equal to A.end(); */ 
        cout << "Check " << endl;
        cout << itr->first << '\t'
        << itr->second << '\n';
        cout << "coming nsasasd" << endl;
        } 
   //     if (A.find(1) == A.end()) { /* A.find(1) tries to find element in map and not found. So, it returns the iterator which points  to the position just after the last element in hash map. i.e -> A.end(). Therefore, statement will become true and prints all elements one by one iteration */
   //     cout << "------------------??" << endl;
   //     cout << itr->first <<'\t' <<itr->second << endl;
   //     cout << "coming in find case . how??" << endl;
   //     }
    }
    //if (A.find(0) == A.end()) {
    //    //cout << it->first << it->second << endl;
    //    cout << "coming in find case . how??" << endl;
    //}

    return 0;
}
