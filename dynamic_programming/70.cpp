// LeetCode 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Note: The answer is guaranteed to be less than or equal to 2^31 - 1.
// Example 1:
// Input: n = 2
// Output: 2 
// Explanation: There are two ways to climb to the top:
// 1. 1 step + 1 step
// 2. 2 steps

// A basic recursive solution to the problem
// Used a map to store the number of ways to climb the stairs for each step
// This is a top-down dynamic programming approach
// The time complexity is O(n) and the space complexity is O(n) due to the map
class Solution {
    public:
        std::map<int, int> nStairMethods;
        int climbStairs(int n) {
            nStairMethods[1] = 1;
            nStairMethods[2] = 2;
            if (nStairMethods.find(n) != nStairMethods.end()){
                return nStairMethods[n];
            } 
            nStairMethods[n] = climbStairs(n - 1) + climbStairs(n - 2);
            return nStairMethods[n];
        }
    };