#include<bits/stdc++.h>

using namespace std;

// Induction
void printNo(int no)
{
    // base condition
    if (no == 1) {
        cout << no << " ";
        return;
    }
    printNo(no - 1);
    cout << no << " ";
    
}

void printNorev(int no)
{
    // base condition
    if (no == 1) {
        cout << no << " ";
        return;
    }
    cout << no << " ";
    printNo(no - 1);
        
}


int main()
{
    // Hypothesis: this function will print 1 - N
    // it will print 1 - N
    printNo(7);

    // it will print N - 1
    printNorev(7);

    return 0;
}