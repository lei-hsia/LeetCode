public class Solution {
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    public int copyBooks(int[] pages, int K) {
        // write your code here
        int n = pages.length;
        if (n == 0) return 0;
        if (K > n) K = n;
        
        int[][] f = new int[n+1][K+1];
        f[0][0] = 0;
        int i, j, k;
        for (i = 1; i <= n; ++i) {
            f[i][0] = Integer.MAX_VALUE;
        }
        
        for (k = 1; k <= K; ++k) {
            f[0][k] = 0;
            for (i = 1; i <= n; ++i) {
                f[i][k] = Integer.MAX_VALUE;
                // sum:(j+1)-n total, i.e. last xxx total 
                int sum = 0;
                for (j = i; j >= 0; --j) {
                    // sum = A[j] ... A[i-1]: these many books, last person 
                    f[i][k] = Math.min(f[i][k], Math.max(f[j][k-1], sum));
                    if (j > 0) {
                        sum += pages[j-1];
                    }   
                }
            }
        }
        
        return f[n][K];
    }
}