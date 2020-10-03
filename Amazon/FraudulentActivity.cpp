// https://leetcode.com/discuss/interview-question/862600/

#include <bits/stdc++.h>
using namespace std;

// time : O(L logL)
// space: O(L)
// L = total size of logs
vector<string> fraudulent(vector<string>& logs, int threshold) {
  map<string, int> counter;
  vector<string> ans;
  for (string& log : logs) {
    int space_pos1 = log.find(' '), space_pos2 = log.rfind(' ');
    string user1 = log.substr(0, space_pos1);
    string user2 = log.substr(space_pos1 + 1, space_pos2 - space_pos1 - 1);
    counter[user1]++;
    if (user1 != user2) counter[user2]++;
  }

  // sort map counter by its value
  vector<pair<string, int>> v;
  for (auto it: counter) {
    v.push_back(make_pair(it.first, it.second));
  }

  sort(v.begin(), v.end(), [](const auto &a, const auto &b){
    return a.second > b.second;
  });

  for (auto pair: v)
    if (pair.second >= threshold) 
      ans.push_back(pair.first);

  return ans;
}

int main() {
  vector<string> logs = {
    "345366 89921 45",
    "029323 38239 23",
    "38239 345366 15",
    "029323 38239 77",
    "345366 38239 23",
    "029323 345366 13",
    "38239 38239 23"
  };
  for (auto& user : fraudulent(logs, 3)) 
    cout << user << " ";
  cout << '\n';
}

