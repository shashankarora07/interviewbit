/* Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
*/

/*
Hint: 

Think in terms of two pointers. If you encounter a repeating character,
you won’t be able to include the new character till you exclude out the
previous occurrence of the character. Which means your window needs to shrink
till your start character is pointing to the position next to previous
occurrence of the character.
*/


#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define NO_OF_CHARS 256
 
int longestUniqueSubsttr(string str)
{
    int n = str.size();
 
    int res = 0; // result
 
    // last index of all characters is initialized
    // as -1
    vector <int> lastRepeatCharIndex(255,-1);
    int lenMax = 0;
    
 
    // Initialize start of current window
    int currIndex = 0;
 
    // Move end of current window
    for (int j = 0; j < n; j++) {
 
        // Find the last index of str[j]
        // Update i (starting index of current window)
        // as maximum of current value of i and last
        // index plus 1
        currIndex = max(currIndex, lastRepeatCharIndex[str[j]] + 1);
        cout << str[j] + 1 << "---> "<< lastRepeatCharIndex[str[j]] << "  currIndex = " << currIndex << endl;
 
        // Update result if we get a larger window
        lenMax = max(lenMax, j - currIndex + 1);
        cout << "lenMax = " << lenMax << endl;
 
        // Update last index of j.6
        lastRepeatCharIndex[str[j]] = j;
    }
    return lenMax;
}

int lengthOfLongestSubstring(string s)
{

        vector<int> charMapIndex(256,-1);
        int maxlen = 0;
        int strLen = s.length();
        int currIndex = -1;

       // for(int i = 0; i < 256; i++)
      //      charMapIndex[i] = -1;
        
        for(int i = 0; i < strLen; i++) {

            if (charMapIndex[s[i]] > currIndex)
                currIndex = charMapIndex[s[i]];
            
        	cout << "currIndex = " << currIndex << endl;
            maxlen  = max(maxlen, i - currIndex);
            charMapIndex[s[i]] = i;
        }

	return maxlen;
}

int main()
{
    //string str = "aspsqrtws";
    //string str = "abcabcbb";
    string str = "tmmzuxt";
    cout << "The input string is " << str << endl;
    //int len = longestUniqueSubsttr(str);
    int len = lengthOfLongestSubstring(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len << endl;
    return 0;
}


/* 
Explanation of code:

This solution uses extra space to store the last indexes of already visited
characters. The idea is to scan the string from left to right, keep track of
the maximum length Non-Repeating Character Substring seen so far in res. When
we traverse the string, to know the length of current window we need two
indexes. 1) Ending index ( j ) : We consider current index as ending index.
2) Starting index ( i ) : It is same as previous window if current character
was not present in the previous window. To check if the current character was
present in the previous window or not, we store last index of every character
in an array lasIndex[]. If lastIndex[str[j]] + 1 is more than previous start,
then we updated the start index i. Else we keep same i.

Time Complexity: O(n + d) where n is length of the input string and d is number
 of characters in input string alphabet. For example, if string consists of 
 lowercase English characters then value of d is 26.
Auxiliary Space: O(d)
*/
/*
    int n = A.size();
    vector<int> index(256, -1);
    int ans, start;
    ans = 0;
    start = -1;
    for(int i = 0; i < n; i++) {
        if(index[A[i]] > start) {
            start = index[A[i]];
        }
        ans = max(ans, i - start);
        index[A[i]] = i;
    }
    return ans;
*/
