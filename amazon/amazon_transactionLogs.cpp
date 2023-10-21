#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'processLogs' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY logs
 *  2. INTEGER threshold
 */

vector<string> processLogs(vector<string> logs, int threshold) {
    long senderID = 0;
    long receiverID = 0;
    long transcationAmount = 0;
    int lenvec = logs.size();
    vector <string> result;
    map <string, int> newMap;
    
    for (int i = 0; i < lenvec; i++) {
        // char* tmpstr = strtok(logs[i], " ");
        
        // while( tmpstr != NULL)
        //     senderID = 
        string tmpstr = "";
        string tmpprev = "";
        for (auto s: logs[i])
        {
            if (s == ' ') {
               // cout  << "1st = " << tmpstr << endl;
               if ((tmpprev.compare(tmpstr)) != 0) {
                   newMap[tmpstr]++;
               }
                tmpprev = tmpstr;
                tmpstr.clear();
            } 
            else {
                tmpstr = tmpstr + s;
            }
        }
        tmpprev.clear();
        //cout << "3rd = " << tmpstr << endl;
    }
    
    
    for (auto i = newMap.begin(); i != newMap.end(); i++) {
        //cout << "First = " << i->first << " and Second = " << i->second << endl;
        if (i->second >= threshold)
            result.push_back(i->first); 
    }
    
    return result;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string logs_count_temp;
    getline(cin, logs_count_temp);

    int logs_count = stoi(ltrim(rtrim(logs_count_temp)));

    vector<string> logs(logs_count);

    for (int i = 0; i < logs_count; i++) {
        string logs_item;
        getline(cin, logs_item);

        logs[i] = logs_item;
    }

    string threshold_temp;
    getline(cin, threshold_temp);

    int threshold = stoi(ltrim(rtrim(threshold_temp)));

    vector<string> result = processLogs(logs, threshold);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

