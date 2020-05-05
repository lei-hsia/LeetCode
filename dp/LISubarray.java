// each IS is disjoint;
// anchor marks the start of each possible IS;
// iterate through; ++i, i - anchor + 1 is the length of current IS;
// it's seen that sliding window is not necessarily manifested by two pointers.

class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int n = nums.length, res = 0, anchor = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i-1] >= nums[i]) anchor = i; // anchor marks the start of a new IS
            res = Math.max(res, i - anchor + 1);
        }
        return res;
    }
}