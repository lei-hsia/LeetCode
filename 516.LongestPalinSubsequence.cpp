class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

// 递归的写法
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return helper(s, 0, n-1, memo);
    }

    int helper(string s, int i, int j, vector<vector<int>>& memo) {
        // Return Condition
        if (memo[i][j] != -1) return memo[i][j];
        // recursive
        if (i > j) return 0;
        if (i == j) return 1;
        if (s[i] == s[j]) memo[i][j] = helper(s, i+1, j-1, memo) + 2;
        else memo[i][j] = max(helper(s, i+1, j, memo), helper(s, i, j-1, memo));
        return memo[i][j];
    }
}
