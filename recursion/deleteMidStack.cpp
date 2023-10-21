#include <bits/stdc++.h>

using namespace std;

void MidDelFromStack(stack<int> &s, int mid)
{
    if (mid == 1) {
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();

    MidDelFromStack(s, mid-1);
    s.push(temp);

    return;
}


void DelMidElemStack(stack<int> &stack)
{
    if (stack.size() == 0)
        return;

    int mid = (stack.size()/2) + 1;

    // stack<int> s_cpy = stack;
    // while(!s_cpy.empty()) {
    //     cout << ' ' << s_cpy.top();
    //     cout << ", temp = " << temp << " <-- SortStack" << endl;
    //     s_cpy.pop();
    // }

    MidDelFromStack(stack, mid);

    return;
}

int main()
{
    stack<int> s;

    for (int i = 1; i <= 5; i++)
        s.push(i);

    DelMidElemStack(s);

    stack<int> s_cpy = s;
    while(!s_cpy.empty()) {
        cout << s_cpy.top() << " ";
        s_cpy.pop();
    }


    cout << endl;

    return 0;
}