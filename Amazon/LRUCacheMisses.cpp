// https://leetcode.com/discuss/interview-question/855839/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
	int capacity_;
	unordered_map<int, list<int>::iterator> m_;

	// Most recently used element ... least recently used element
  // front ............................................... back
	list<int> list_;

public:
	LRUCache(int capacity) : capacity_(capacity) {}

	void insert(int page) {
		// if already exists, update and return
		if (contains(page)) {
			update(page);
			return;
		}
		// if exceeds capacity, pop least recent page
		if (m_.size() >= capacity_) {
			int least = list_.back();
			list_.pop_back();
			m_.erase(least);
		}
		// add to cache
		list_.push_front(page);
		m_[page] = list_.begin();
	}

	bool contains(int page) {
		return m_.count(page);
	}

	void update(int page) {
		auto it = m_.find(page);
		list_.erase(it->second);
		list_.push_front(page);
		m_[page] = list_.begin();
	}
};

int cacheMisses(int num, vector<int>& pages, int capacity) {
	int result = 0;
	LRUCache cache(capacity);
	for (int page: pages) {
		if (cache.contains(page)) {
			cache.update(page);
		}
		else {
			// cache miss since page not found in cache
			cache.insert(page);
			result++;
		}
	}
	return result;
}

int main() {
	int num = 6;
	vector<int> pages = {1, 2, 1, 3, 1, 2};
	int capacity = 2;
	int result = cacheMisses(num, pages, capacity);
	cout << result << endl;
	return 0;
}
