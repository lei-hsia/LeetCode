1218. Longest Arithmetic Subsequence of Given Difference

Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which 
is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            m[arr[i]] = m[arr[i] - diff] == 0 ? 1 : m[arr[i] - diff] +1;
            res = max(res, m[arr[i]]);
        }
        return res;
    }
};
