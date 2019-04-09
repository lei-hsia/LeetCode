class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        dfs(s, 0, res, out);
        return res;
    }

    void dfs(string s, int start, vector<vector<string>>& res, vector<string>& out) {
        // Return Condition
        if (start == s.size()) {
            res.push_back(out);
            return;
        }
        // Backtracking: 其实跟python代码的思路相同
        for (int i=start; i<s.size(); ++i) {
            if (!isPalindrome(s, start, i)) continue;
            out.push_back(s.substr(start, i-start+1));
            dfs(s, i+1, res, out);
            out.pop_back();
        }
    }

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left; --right;
        }
        return true;
    }
}
