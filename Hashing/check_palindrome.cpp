/* Given a string A consisting of lowercase characters.

Check if characters of the given string can be rearranged to form a palindrome.

Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.

Input Format
First argument is an string A.

Output Format
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.

Example Input
Input 1:

 A = "abcde"

Input 2:

 A = "abbaee"

Example Output
Output 1:
 0

Output 2:
 1

Example Explanation

Explanation 1:

 No possible rearrangement to make the string palindrome.

Explanation 2:

 Given string "abbaee" can be rearranged to "aebbea" to form a palindrome.
*/

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int Valid_palindrome_ByRearrangeString(string A)
{
    map<char, int> newMap;
    int result = 0, odd = 0;

    if (A.size() == 1)
        return 1;

    for (std::string::iterator i = A.begin(); i != A.end(); i++)
    {
        newMap[(*i)]++;
    }

    for (auto i = newMap.begin(); i != newMap.end(); i++)
    {

        if (newMap.find(i->first)  != newMap.end()) {
            if (i->second % 2 == 0) {
                result = 1;
            }
            else
                odd++;
        }

        if (odd > 1)
            return 0;
    }


    return result;
}

int main()
{

    string Str = "abcde";
    int result =0;

    result = Valid_palindrome_ByRearrangeString(Str);
    if (result)
        cout << " palindrome possible = " << result;
    else
        cout << " palindrome not possible ";
    cout << endl;

    // result = TwoSum_2nd(vect, target);
    // cout << result[0] << " and " << result[1] << endl;
    return 0;
}