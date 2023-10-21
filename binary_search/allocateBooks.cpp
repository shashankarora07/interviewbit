/*Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

    Each student gets at least one book.
    Each book should be allocated to only one student.
    Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1*/


#include <bits/stdc++.h>

using namespace std;

int maxElementinArr(vector<int> arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int sumOfArr(vector<int> arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

bool isAllConditionValid(vector<int> A, int size, int m, int maxPages)
{
    int sum = 0;
    int student = 1;

    for (int i = 0; i < size; i++)
    {
        sum += A[i];
        
        if(maxPages < sum) {
            sum = A[i];
            student++;
        }

        if (student > m)
            return false;
    }

    return true;
}

int AllocateBookPagesMinimumToStudent(vector<int> A, int m)
{
    int size = A.size();
    int start = maxElementinArr(A, size);  // Each student gets at least one book
    int end = sumOfArr(A, size);
    int res = -1;
    int mid = 0;

    if (size < m)
        return -1;

    while (start <= end)
    {
        mid = (start + end) / 2;
        cout << "start: " << start << " end: " << end << " mid: " << mid << endl;

        if (isAllConditionValid(A, size, m, mid) == true)
        {
            res = mid;
            end = mid - 1;
            cout << "$$$$$ res = " << res << endl;
        }
        else
            start = mid + 1;
    }
    cout << "########start: " << start << " end: " << end << " mid: " << mid << endl;
    return res;
}


int main()
{
    //vector<int> A{10,20,30,40};
    vector<int> A{12, 34, 67, 90};
    int m = 2;
    int res = 0;

    for(auto vecElem = A.begin(); vecElem != A.end(); vecElem++)
        cout << *vecElem << "  ";
    cout << endl;

    res = AllocateBookPagesMinimumToStudent(A,m);
    cout << "res = " << res << endl;

    return 0;
}