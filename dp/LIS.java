// cnt should also be dp:

// 1. If previous index j len[j]+1 maps a longer IS than len[i] for latter index i, then cnt[i] would have to increase, since this is a longer IS than it used to be;
// 2. else if len[j]+1 == len[i], length of LIS stay the same, but now there're new cnt[j] ways of forming this length of LIS: cnt[i] += cnt[j].
// 3. Don't use if, use else if in 2. Once increased in 1, it can largely go into if; else if would eliminate this error.


class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length, maxLen = 1, res = 0;
        int[] len = new int[n]; int[] cnt = new int[n];
        Arrays.fill(len, 1);
        Arrays.fill(cnt, 1);
        int i, j;
        for (i = 0 ; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = Math.max(maxLen, len[i]);
        }
        for (i = 0 ; i < n; ++i) {
            if (len[i] == maxLen) res += cnt[i];
        }
        return res;
    }
}