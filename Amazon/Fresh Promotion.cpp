//https://leetcode.com/discuss/interview-question/344650/Amazon-Online-Assessment-Questions
/*
Inspired by leecode 392-Is subsequence. Use two pointers i and j respectively for an element in two given lists. For a specific code codelist[i], check the subarray with the same length of codelist[i] starting from j in shoppingCart List.
*/

#include <vector>
#include <iostream>
using namespace std;

int isWinner(vector<vector<string>> codeList, vector<string> shoppingCart)
{
	if (codeList.empty()) return 1;
	if (shoppingCart.empty()) return 0;

	int i = 0, j = 0; //codeList[i]
	while (i < codeList.size() && j + codeList.size() < shoppingCart.size()) {
		bool isMatch = true;
		for (int k = 0; k < codeList[i].size(); k++) {
			if ((codeList[i][k] != "anything") && (shoppingCart[j + k]) != codeList[i][k]) {
				isMatch = false;
				break;
			}
		}

		if (isMatch) {
			j += codeList.size();
			i++;
		} else {
			j++;
		}
	}

	return (i == codeList.size()) ? 1 : 0;

}

int main() {
	vector<vector<string>> codeList1 = { { "apple", "apple" }, { "banana", "anything", "banana" } };
    vector<string> shoppingCart1 = {"orange", "apple", "apple", "banana", "orange", "banana"};
    vector<vector<string>> codeList2 =  { { "apple", "apple" }, { "banana", "anything", "banana" } };
    vector<string> shoppingCart2 = {"banana", "orange", "banana", "apple", "apple"};
        
    cout<<isWinner(codeList1,shoppingCart1)<<endl;
    cout<<isWinner(codeList2,shoppingCart2)<<endl;

}
