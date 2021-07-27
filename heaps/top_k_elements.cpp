/***********************
Top K Frequent Elements
***********************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqCount;

    // Use greater comparator to form a min-heap.
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    vector<int> answer;
    
    // Time complexity: O(n)
    for(int num : nums) {
        freqCount[num]++;
    }
    
    // Time Complexity: O(N * log k)
    for(pair<int, int> p : freqCount) {
        minHeap.push(make_pair(p.second, p.first));
        // STL pop and push take O(log n) time
        // Extra time comes from adjusting the heap to maintain it's properties.
        if(minHeap.size() > k) minHeap.pop();
    }
    // Time Complexity: O(k * log k)
    for(int i = k-1; i >= 0; i--) {
        answer.push_back(minHeap.top().second);
        minHeap.pop();
    }
    // Overall space: O(N + k), where N = hashing, k = min heap / queue
    return answer;
}

int main() {
    topKFrequent([1,1,1,2,2,3], 2);
    return 0;
}
