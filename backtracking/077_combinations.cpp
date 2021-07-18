```
class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        backtrack(n, k, 1, tmp);
        return res;
    }
    
    void backtrack(int n, int k, int start, vector<int>& tmp) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        
        for (int i = start; i <= n; ++i) {
            tmp.push_back(i);
            backtrack(n, k, i+1, tmp);
            tmp.pop_back();
        }
    }
};
```

