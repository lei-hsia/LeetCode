```cpp
class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        backtrack(nums, tmp, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& tmp, int start) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            backtrack(nums, tmp, i+1);
            tmp.pop_back();
        }
    }
};
```

