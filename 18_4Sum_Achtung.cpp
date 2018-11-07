

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int len = nums.size();
        
        if (len <= 3)
            return result;
        
        // otherwise result will not be null;
        // sort this array
        sort(nums.begin(), nums.end());
        
        for (int i=0; i <= len-4; i++){
            for (int j = i+1; j <= len-3; j++){
                int k = j + 1;
                int n = len - 1;
                while (k < n){
                    if (nums[i] + nums[j] + nums[k] + nums[n] < target){
                        ++k;
                    } else if (nums[i] + nums[j] + nums[k] + nums[n] > target){
                        --n;
                    } else {
                        result.push_back({ nums[i],nums[j],nums[k],nums[n] });
                        ++k;
                        --n;
                        while ( k<n && nums[k] == nums[k-1])
                            ++k;
                        while ( k<n && nums[n] == nums[n+1])
                            --n;
                    }
                }
                
                // for j
                // while (j<=len-3 && nums[j] == nums[j-1])
                // while之前没有改变j(跟k,n不同), 所以是判断nums[j] == nums[j+1],
                // 并且因为j可能要加1, 所以j的范围变成了j<len-3而不是小于等于
                while (j<len-3 && nums[j] == nums[j+1])
                    ++j;
            }
            // for i
            // while (i<=len-4 && nums[i] == nums[i-1])
            while (i<len-4 && nums[i] == nums[i+1])
                ++i;
        }
        
        return result;
    }
};