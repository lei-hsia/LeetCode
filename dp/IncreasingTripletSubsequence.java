class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n = nums.length; 
        if (n == 0) return false;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        int i, j;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    f[i] = Math.max(f[i], f[j] + 1);
                    if (f[i] == 3) return true;
                }
            }
        }
        return false;
    }
}