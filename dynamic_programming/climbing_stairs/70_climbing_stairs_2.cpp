/*********************************************************************************
* Leetcode Problem #70
* Name: Climbing Stairs
* Type: Dynamic Programming
* Time Complexity: O(n) (Only a singular for loop is required to compute.)
* Space Complexity: O(1) (No array is used, just 3 variables needed.)
**********************************************************************************/ 

#include <iostream>

using namespace std;
 
int climbStairs(int n) {
    if(n == 1) return 1;

    int way1 = 1;
    int way2 = 2;

    for(int i = 3; i <= n; i++) {
        int total_ways = way1 + way2;
        way1 = way2;
        way2 = total_ways;
    }

    return way2;
}

int main() {
    cout << "Result: " << climbStairs(4) << endl;
    return 0;
}