```
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res, h;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto& a:buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a[1] < 0) m.insert(-a[1]);
            else m.erase(m.find(a[1]));
            cur = *m.rbegin();
            if (pre != cur) {
                res.push_back({a[0], cur});
                pre = cur;
            }
        }
        return res;
    }
};class Solution {
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

