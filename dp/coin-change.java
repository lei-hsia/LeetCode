// 正如老师所讲，dp的凑target的问题, 一共有多少种啦，最小多少种啦，一定有一维是target那一维

class Solution {
    public int coinChange(int[] coins, int a) {
        int n = coins.length;
        if (n == 0) return 0;
        int[] f = new int[a+1];
        f[0] = 0;
        for (int i = 1; i <= a; ++i) {
            f[i] = a+1;
            for (int j = 0; j < n; ++j) {
                if (i >= coins[j]) {
                    f[i] = Math.min(f[i], f[i - coins[j]] + 1);
                }
            }
        }
        return f[a] == (a+1) ? -1 : f[a];
    }
}