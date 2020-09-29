// https://leetcode.com/problems/reorder-data-in-log-files/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, result;
        vector<pair<string, string>> letterLogs;
        // separate digit-logs and letter-logs
        for (string s: logs) {
            int i = 0;
            while (s[i] != ' ') i++;
            if (isalpha(s[i + 1])) {
                letterLogs.emplace_back(s.substr(0, i), s.substr(i + 1)); //emplace the pair of id and log string
            } else {
                digitLogs.push_back(s);
            }
        }
        
        // sort the letter-logs
        sort(letterLogs.begin(), letterLogs.end(), [](auto a, auto b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        
        // convert letter-logs pair back to string
        for (auto i: letterLogs) {
            result.push_back(i.first + " " + i.second);
        }
        
        for (string s: digitLogs) {
            result.push_back(s);
        }

        return result;
    }
};
