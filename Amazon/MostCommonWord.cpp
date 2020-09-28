class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> count;
        // Step 1: remove punctuations and change to lower case
        for (auto &c: paragraph) {
            c = isalpha(c) ? tolower(c):' ';
        }
        
        // Step 2: count the frequency of every word
        istringstream iss(paragraph);
        string word;
        while (iss >> word) {
            count[word]++;
        }
        
        // Step 3: set the frequency of banned word to zero
        for(auto b : banned) count[b] = 0; 
        
        // Step 4: get the word with highest frequency
        int maxCount = 0;
        string res;
        for (auto c: count) {
            if (c.second > maxCount) {
                maxCount = c.second;
                res = c.first;
            }
        }
        return res;
        
    }
};
