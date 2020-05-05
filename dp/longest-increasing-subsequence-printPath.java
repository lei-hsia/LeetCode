class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int[] f = new int[n];
        int[] pi = new int[n];
        Arrays.fill(f, 1);
        int res = 0;
        int p = 0; // ending index
        for (int i = 0; i < n; ++i) {
            pi[i] = -1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) { 
                    f[i] = Math.max(f[i], f[j] + 1);
                    if (f[i] == f[j] + 1) {
                        pi[i] = j; // each index injects its previous index
                    }
                }
            }
            res = Math.max(res, f[i]); 
            if (f[i] == res) {
                p = i;
            }
        }
        
        // print sequence
        int[] seq = new int[res];
        for (int i = res-1; i >= 0; --i) {
            seq[i] = nums[p];
            p = pi[p];  // previous index
        }
        for (int i = 0; i < res; ++i) {
            System.out.println(seq[i]);
        }
        
        return res;
    }
}