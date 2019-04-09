class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        for (int i=0; i<=s.size(); ++i) {
            for (int j=0; j<i; ++j) {
                if (dp[j] && set.count(s.substr(j, i-j))) {
                    dp[i] = true; break;
                }
            }
        }
        return dp.back();
    }
}
