#include <bits/stdc++.h>

using namespace std;

void InsertElem(stack<int> &s, int tmp)
{
    if (s.size() == 0 || s.top() <= tmp) {
        s.push(tmp);
        return;
    }

    int val = s.top();
    s.pop();
    
    InsertElem(s, tmp);
    s.push(val);

    return;
}


void SortStack(stack<int> &stack)
{
    if (stack.size() == 1)
        return;

    int temp = stack.top();
    stack.pop();

    // stack<int> s_cpy = stack;
    // while(!s_cpy.empty()) {
    //     cout << ' ' << s_cpy.top();
    //     cout << ", temp = " << temp << " <-- SortStack" << endl;
    //     s_cpy.pop();
    // }

    SortStack(stack);

    InsertElem(stack, temp);

    return;
}

int main()
{
    stack<int> s;

    s.push(4);
    s.push(6);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(3);

    SortStack(s);

    stack<int> s_cpy = s;
    while(!s_cpy.empty()) {
        cout << s_cpy.top() << " ";
        s_cpy.pop();
    }


    cout << endl;

    return 0;
}