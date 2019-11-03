class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int res = 0, odd = 0, n = nums.length;
        int prefix[] = new int[n];
        int i = 0;
        for (i = 0; i < n; ++i) {
            prefix[odd]++;
            if ((nums[i] & 1) == 1) odd++;
            if (odd >= k) res += prefix[odd - k];
//             System.out.print(i);
//             System.out.print(" ");
//             System.out.print(prefix[odd]);
//             System.out.print(" ");
//             if (odd >= k) {
//                 System.out.print(prefix[odd-k]);
//             }
//             System.out.print(" ");
//             System.out.print(res);
            
//             System.out.println();
        }
        return res;
    }
}