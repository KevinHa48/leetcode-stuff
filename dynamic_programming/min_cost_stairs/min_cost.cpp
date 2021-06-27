/*********************************************************************************
* Leetcode Problem #746
* Name: Climbing Stairs
* Type: Dynamic Programming / Greedy
* Time Complexity: O(n) (A singular for loop used.)
* Space Complexity: O(1) (No auxillary data structures used.)
**********************************************************************************/ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int> &cost) {
    for(size_t i = 2; i < cost.size(); i++) {
        cost[i] += min(cost[i-1], cost[i-2]);
    }
    return min(cost[cost.size()-1], cost[cost.size()-2]);
}

int main() {
    vector<int> test1 {1, 100, 1, 1, 1, 100, 1, 1, 100, 1, 1000};
    cout << "Minimum cost: " << minCostClimbingStairs(test1) << endl;
    for(size_t i = 0; i < test1.size(); i++) {
        cout << "Vector[" << i << "]: " << test1[i] << endl;
    }
    return 0;
}