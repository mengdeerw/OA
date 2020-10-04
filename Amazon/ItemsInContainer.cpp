// https://leetcode.com/discuss/interview-question/861453/

#include <bits/stdc++.h>
using namespace std;

// O(S+N), O(S+N), linear
/*
      0 1 2 3 4 5 6 7 8 9
      * * | * * * | * * *
left -1-1 2 2 2 2 6 6 6 6
right 2 2 2 6 6 6 6-1-1-1
star  1 2 2 3 4 5 5 6 7 8
*/

vector<int> numOfItems(string s, vector<int>& startIndices, vector<int>& endIndices) {
	int l = s.size(), n = startIndices.size();
    vector<int> res(n);
    vector<int> left(l), right(l), star(l);
    int pre_left = -1, post_right = -1, cum = 0;
    for(int i = 0; i < l; i++){
        if(s[i] == '|') pre_left = i;
        left[i] = pre_left;
    }
    for(int i = l - 1; i >= 0; i--){
        if(s[i] == '|') post_right = i;
        right[i] = post_right;
    }
    for(int i = 0; i < l; i++){
        if(s[i] == '*') cum++;
        star[i] = cum; 
    }
    for(int i = 0; i < n; i++){
        int start = startIndices[i] - 1, end = endIndices[i] - 1;
        int a = right[start], b = left[end];
        if(a >=b ) res[i] = 0;
        else res[i] = star[b] - star[a];
    }
    return res;
}

//sol1, binary search O(S+NlogS), O(S) S means how many '|' in the string, the worst case the the string length, N is the indices number
vector<int> numOfItems2(string s, vector<int>& startindices, vector<int>& endindices){
    int l = s.size(), n = startindices.size();
    vector<int> res(n);
    int cum = 0;
    vector<int> idxs, cum_star;
    for(int i = 0; i < l; i++){
        if(s[i] == '|'){
            cum_star.push_back(cum);
            idxs.push_back(i);
        }
        else{
            cum++;
        }
    }
    
    for(int i = 0; i < n; i++){
        int start = startindices[i] - 1, end = endindices[i] - 1;
        int a = lower_bound(idxs.begin(), idxs.end(), start) - idxs.begin();
        int b = upper_bound(idxs.begin(), idxs.end(), end) - idxs.begin() - 1;
        if(a > b) res[i] = 0;
        else res[i] = cum_star[b] - cum_star[a];
    }
    return res;        
}

int main() {
	string s = "|**|*|*";
	vector<int> startIndices = {1, 1};
	vector<int> endIndices = {5, 6};
	vector<int> result = numOfItems(s, startIndices, endIndices);
	vector<int> result2 = numOfItems2(s, startIndices, endIndices);
	for (int r: result) {
		cout << r << endl;
	}
	for (int r: result2) {
		cout << r << endl;
	}
	return 0;
}
