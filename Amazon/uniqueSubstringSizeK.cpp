//https://leetcode.com/discuss/interview-question/370112

//Given a string s and an int k, return all unique substrings of s of size k with k distinct characters.

#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

unordered_set<string> uniqueSubstringSizeK(string s, int k) 
{
	unordered_set<string> result;
	int ch[26] = {0};
	int lo = 0, hi = 0;
	while (lo <= hi && hi < s.length())
	{
		ch[s[hi] - 'a']++;
		while (ch[s[hi] - 'a'] != 1)
		{
			ch[s[lo] - 'a']--;
			lo++;
		}
		if (hi - lo + 1 == k)
		{
			result.insert(s.substr(lo, k));
			ch[s[lo] - 'a']--;
			lo++;
		}
		hi++;
	}

	return result;
}

int main()
{
	unordered_set<string> res1 = uniqueSubstringSizeK("abcabc", 3);
	unordered_set<string> res2 = uniqueSubstringSizeK("abacbc", 3);
	unordered_set<string> res3 = uniqueSubstringSizeK("awaglknagawunagwkwagl", 4);

	// int n = sizeof(res1)/sizeof(res1[0])
	for (unordered_set<string>::iterator it = res3.begin(); it != res3.end(); it++)
	{
		cout<<' '<<*it;
	}

	cout<<'\n';
}
