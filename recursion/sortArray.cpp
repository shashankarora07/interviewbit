#include <bits/stdc++.h>

using namespace std;

void InsertElem(vector<int> &v, int tmp)
{
    cout << "start insert = " << tmp << " v.size = " << v.size() << endl;
    if (v.size() == 0 || v[v.size()-1] <= tmp) {
        v.push_back(tmp);
        cout << "Inserted Elem: " << tmp << " (Done)"<< endl;
        return;
    }

    int val = v[v.size()-1];
    v.pop_back();
    
    for (auto it = v.begin(); it != v.end(); it++)
        cout << ' ' << *it;
    cout << ", val= "<< val << ", tmp= "<< tmp << " <-- Begin InsertElem" << endl;

    InsertElem(v, tmp);
    v.push_back(val);

    for (auto it = v.begin(); it != v.end(); it++)
        cout << ' ' << *it;
    cout << ", val= "<< val << ", tmp= "<< tmp << " <-- End InsertElem" << endl;
    cout << endl;

    return;
}

void SortArray(vector<int> &vect)
{
    if (vect.size() == 1)
        return;

    int temp = vect[vect.size() - 1];
    vect.pop_back();

    for (auto it = vect.begin(); it != vect.end(); it++)
        cout << ' ' << *it;
    cout << ", temp = " << temp << " <-- SortArray" << endl;

    SortArray(vect);

    InsertElem(vect, temp);

}

int main()
{
    //vector<int> arr{4, 6, 2, 5, 1, 3};
    vector<int> arr{5, 1, 0, 6};

    SortArray(arr);

    for (auto it = arr.begin(); it != arr.end(); it++)
        cout << ' ' << *it;

    cout << endl;

    return 0;
}