// Reverse a Stack in O(1) space using Recursion

#include <bits/stdc++.h>

using namespace std;

void Insert(stack<int> &s, int tmp)
{
    if (s.size() == 0) {
        s.push(tmp);
        return;
    }

    int val = s.top();
    s.pop();

    Insert(s, tmp);
    s.push(val);

    return;
}


void ReverseStack(stack<int> &stack)
{
    if (stack.size() == 1)
        return;

    int temp = stack.top();
    stack.pop();

    // stack<int> s_cpy = stack;
    // while(!s_cpy.empty()) {
    //     cout << ' ' << s_cpy.top();
    //     cout << ", temp = " << temp << " <-- ReverseStack" << endl;
    //     s_cpy.pop();
    // }


    ReverseStack(stack);

    Insert(stack, temp);

    return;
}

int main()
{
    stack<int> s;

    for (int i = 1; i <= 5; i++)
        s.push(i);

    stack<int> s_cpy = s;
    cout << "Stack Input: ";
    while(!s_cpy.empty()) {
        cout << s_cpy.top() << " ";
        s_cpy.pop();
    }
    cout << endl;

    ReverseStack(s);

    s_cpy = s;
    cout << "Reverse Output: ";
    while(!s_cpy.empty()) {
        cout << s_cpy.top() << " ";
        s_cpy.pop();
    }
    cout << endl;

    return 0;
}