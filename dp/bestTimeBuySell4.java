class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;
        
        if (k > n/2) {
            // can always buy on day and sell the second day := buy & sell without limit
            // no need to keep record of f, just one sum to sum all profits.
            int sum = 0;
            for (int i = 0; i < n-1; ++i) {
                if (prices[i+1] > prices[i]) {
                    sum += prices[i+1] - prices[i];
                }
            }
            return sum;
        }
        
        int[][] f = new int[n+1][2*k+2];
        int i, j;
        
        f[0][1] = 0;
        for (j = 2; j <= 2*k+1; ++j) {
            f[0][j] = Integer.MIN_VALUE;
        }
        
        for (i = 1; i <= n; ++i) {
            // 1,3,5: f[i][j] = max(f[i-1][j], f[i-1][j-1] + prices[i-1] - prices[i-2]);
            for (j = 1; j <= 2*k+1; j += 2) {
                f[i][j] = f[i-1][j];
                if (j > 1 && i >= 2 && f[i-1][j-1] != Integer.MIN_VALUE) {
                    f[i][j] = Math.max(f[i][j], f[i-1][j-1] + prices[i-1] - prices[i-2]);
                }
            }
            // 2, 4: f[i][j] = max(f[i-1][j] + prices[i-1] - prices[i-2], f[i-1][j-1])
            for (j = 2; j <= 2*k+1; j += 2) {
                f[i][j] = f[i-1][j-1];
                if (i >= 2 && f[i-1][j] != Integer.MIN_VALUE) {
                    f[i][j] = Math.max(f[i][j], f[i-1][j] + prices[i-1] - prices[i-2]);
                }
            }
        }
        
        int res = 0;
        for (i = 1; i <= 2*k+1; i += 2) {
            res = Math.max(res, f[n][i]);
        }
        return res;
    }
}