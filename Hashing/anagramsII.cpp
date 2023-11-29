class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> newmap;
        int slen = s.length();
        int tlen = t.length();

        for (int i = 0; i < slen; i++)
            newmap[s[i]]++;

        for (int i = 0; i < tlen; i++)
        {
            //cout << t[i] << " : " << newmap[t[i]] << endl;
            if (newmap.find(t[i]) != newmap.end())
            {
                    newmap[t[i]]--;
                if (newmap[t[i]] == 0) {
                    //cout << "deleting: " << t[i] << endl;
                    newmap.erase(t[i]);
                }
                
            }
        }

        //cout << "newmap.size() = " << newmap.size() << endl;
        if (newmap.size() == 0 && slen == tlen)
            return true;
        else
            return false;

// this solution I was thinking of
/*
       int count[26] ={0};

        for(char x: s){
            count[x-'a']++;
        }

        for(char x:t){
            count[x-'a']--;
        }

        for(int val: count){
            if(val!=0){
                return false;
            }
        }

        return true;
*/
    }
};