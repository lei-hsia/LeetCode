```
class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        backtrack(nums, tmp);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& tmp) {
        if (nums.size() == tmp.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (std::find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) continue;
            tmp.push_back(nums[i]);
            backtrack(nums, tmp);
            tmp.pop_back();
        }
    }
};
```

