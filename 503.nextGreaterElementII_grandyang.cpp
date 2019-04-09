
/*
      j < i+n : 表现出了circular的数组的特点: 当前的相当于0开始
      为了数组的index不越界: 对n取余操作
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i<n; ++i) {
            for (int j = i+1; j < i+n; ++j) {
                if (nums[j % n] > nums[i]) {
                    res[i] = nums[j % n];
                    break;
                }
            }
        }
        return res;
    }
}
