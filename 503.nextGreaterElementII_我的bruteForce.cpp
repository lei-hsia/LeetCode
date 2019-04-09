class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        for (int i=0; i<nums.size(); ++i) {
            int j = 0;
            for (j=i+1; j<nums.size(); ++j) {
                if (nums[j] > nums[i]) {
                    res[i] = nums[j]; break;
                }
            }
            if (j == nums.size()) {
                int k =0;
                for (; k<i; ++k) {
                    if (nums[k] > nums[i]) {
                        res[i] = nums[k]; break;
                    }
                }
                if (k == i) res[i] = -1;
            }
        }
        return res;
    }
};
