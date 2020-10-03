// https://leetcode.com/discuss/interview-question/861432/
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include <bits/stdc++.h>
using namespace std;

int musicPairs(vector<int> times) {
	int result = 0;
	vector<int> count (60);
	for (int time: times) {
		result += count[time % 60 ? (60 - time % 60) : 0];
		count[time % 60]++;
	}
	return result;

}

int main() {
	vector<int> songs1 = {37, 23, 60};
	vector<int> songs2 = {60, 60, 60};
	vector<int> songs3 = {10, 50, 90, 30};
	cout << musicPairs(songs1) << endl;
	cout << musicPairs(songs2) << endl;
	cout << musicPairs(songs3) << endl;
}
