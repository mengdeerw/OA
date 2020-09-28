//https://leetcode.com/discuss/interview-question/854110/ 
/* Given the number of five-star and total reviews for each product a company sells, as well as the threshold
percentage, what is the minimum number of additional five-star reviews the company needs to become five star seller. For
ex, there are 3 products (n=3) with productRatings =[[4,4],[1,2],[3,6]], percentage rating threshold = 77. [1,2]
indicates => [1 (five star reviews) ,2 (total reviews)]. We need to get the seller reach the threshold with minimum
number of additional five star reviews. */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

double computeRatings(vector<vector<int>>& productRatings) 
{
	double sum = 0., n = productRatings.size();
	for (int i = 0; i < n; i++) {
		sum += (double)(productRatings[i][0]*1./(productRatings[i][1]*1.));
	}
	printf("%f\n", (sum/n * 1.) * 100.);
	return (sum/n * 1.) * 100.;
}

int fiveStarReviews(vector<vector<int>>& productRatings, int ratingsThreshold)
{
	int steps = 0;
	priority_queue<pair<double, vector<vector<int>>>, vector<pair<double, vector<vector<int>>>>> pq;
	// using pq as default minHeap (always having max node on the top)
	pq.push(make_pair(computeRatings(productRatings), productRatings));
	while(!pq.empty()) {
		auto topPair = pq.top(); pq.pop();
		double rating = topPair.first;
		vector<vector<int>> currProductRatings = topPair.second;
		if (rating >= ratingsThreshold)
			return steps;
		for (int i = 0; i < currProductRatings.size(); i++) {
			// check every possible solutions, reverse back before searching next one in pq
			currProductRatings[i][0]++; currProductRatings[i][1]++;
			pq.push(make_pair(computeRatings(currProductRatings), currProductRatings));
			currProductRatings[i][0]--; currProductRatings[i][1]--;
		}
		steps++;
	}
	return steps;
}

int main() 
{
	vector<vector<int>> productRatings = {{4,4},{1,2},{3,6}};
	int threshold = 77;
	int ans = fiveStarReviews(productRatings, threshold);
	cout<<ans<<endl;
	return 0;
}
