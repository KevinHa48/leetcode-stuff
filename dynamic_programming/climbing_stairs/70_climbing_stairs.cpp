/*********************************************************************************
* Leetcode Problem #70
* Name: Climbing Stairs
* Type: Dynamic Programming
* Time Complexity: O(n) (2^n -> n due to memoization, only need n calls to solve.)
* Space Complexity: O(n) (An array of size n+1 is used for memoization.)
**********************************************************************************/ 

#include <iostream>

using namespace std;

int climbHelper(int n, int stairs[]) {
    if(n == 0 || n == 1) return 1;

    if(!stairs[n]) {
        stairs[n] = climbHelper(n-1, stairs) + climbHelper(n-2, stairs);
    }
    
    return stairs[n];
}  

int climbStairs(int n) {
    int *stairs = new int[n + 1]();
    int result = climbHelper(n, stairs);
    delete[] stairs;
    return result;
}

int main() {
    cout << "Result: " << climbStairs(4) << endl;
    return 0;
}




