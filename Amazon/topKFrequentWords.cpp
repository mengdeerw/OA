//https://leetcode.com/discuss/interview-question/542597/

#include <vector>
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second < b.second;
	}
};

bool isNotAlnum(char c) {
    if(c==' ')
        return false;    //when we return false char is not removed
    return isalnum(c) == 0; //isalnum return 1  for alphanumeric 
}

vector<string> topK(int k, vector<string>& keywords, vector<string>& reviews)
{
	for (string review: reviews) {
		for (char c: review) {
			c = islower(c)?c:' ';
		}
	}

    unordered_set<string>hashkey;
    unordered_map<string,int>count;
    for(auto s:keywords)//considaring all keywords are lower case else we can convert to lower case.
        hashkey.insert(s);
    for(auto rev:reviews){
        unordered_set<string>added; 
        //rev.erase(std::remove_if(rev.begin(), rev.end(), isNotAlnum), rev.end());
        //delete ! . , ? non alphanum char except ' '//instead of deleting we can replace them with space 
        for(auto &c:rev)//convert to lower case
                c=::tolower(c);
        
        istringstream iss(rev);
        string temp;
        while(getline(iss,temp,' ')){
            if(hashkey.find(temp)!=hashkey.end() && added.find(temp)==added.end()){
                count[temp]++;
                added.insert(temp);
            }
        }
    }

	priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
	for (auto i:count) {
		pq.push({i.first, i.second});
	}

	vector<string> ans;
	while (!pq.empty() && k--) {
		ans.emplace_back(pq.top().first);
		pq.pop();
	}

	return ans;
}

int main() 
{
	int k=2;
    vector<string> keywords1 = {"anacell", "betacellular", "cetracular"};
    vector<string> reviews1 = {"Anacell provides the best services in the city",
  	"betacellular has awesome services",
  	"Best services provided by anacell, everyone should use anacell"};
	vector<string> keywords2 = {"anacell", "betacellular", "cetracular", "deltacellular", "eurocell"};
    vector<string> reviews2 = {"I love anacell Best services; Best services provided by anacell",
			"betacellular has great services", "deltacellular provides much better services than betacellular",
			"cetracular is worse than anacell", "Betacellular is better than deltacellular." };
    vector<string> res1 = topK(k, keywords1, reviews1);
    vector<string> res2 = topK(k, keywords2, reviews2);
    for(auto s:res1)
        cout<<s<<" ";
  	cout<<endl;
    for(auto s:res2)
        cout<<s<<" ";
}
