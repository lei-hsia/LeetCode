// 1250. Check If It Is a Good Array

// Given an array nums of positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers. The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.

// Return True if the array is good otherwise return False.

// Input: nums = [12,5,7,23]
// Output: true
// Explanation: Pick numbers 5 and 7.
// 5*3 + 7*(-2) = 1

// Input: nums = [29,6,10]
// Output: true
// Explanation: Pick numbers 29, 6 and 10.
// 29*1 + 6*(-3) + 10*(-1) = 1

// Input: nums = [3,6]
// Output: false

// 考察: Chinese Reminder Theorem; Bezout Identity
// 本质: 找数组种所有的数的gcd; 根据这些数的gcd看所有的数是不是线性无关;

// select some subsets: 
// 1. if multiplication is not allowed: recursion;
// 2. if allowed: CRT
// 3. CRT/Bezout(裴署定理);

// 实际上就是遍历所有的数看所有的数是不是线性相关:
// 1. 如果是线性相关, 那么所有的数同余, i.e. gcd不是1；
// 2. 如果非线性相关，那么所有的数互质, gcd是1;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        for (int i : nums) {
            res = gcd(res, i);
        }
        return res == 1;
    }
};