// https://leetcode.com/problems/house-robber-ii/description/

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int[] f = new int[n];
        
        f[0] = 0;
        f[1] = nums[0];
        for (int i = 2; i < n; ++i) {
            f[i] = Math.max(nums[i-1] + f[i-2], f[i-1]);
        }
        int temp = f[n-1];
        
        Arrays.fill(f, 0);
        f[1] = nums[1];
        for (int i = 2; i < n; ++i) { // nums[i-1] -> nums[i]
            f[i] = Math.max(nums[i] + f[i-2], f[i-1]);
        }
        return Math.max(temp, f[n-1]);
    }
}