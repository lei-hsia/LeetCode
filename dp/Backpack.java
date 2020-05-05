public class Solution {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    public int backPack(int m, int[] A) {
        // write your code here
        int n = A.length;
        if (n == 0) return 0;
        boolean[][] f = new boolean[n+1][m+1];
        f[0][0] = true;
        int i, j;
        for (i = 1; i <= m; ++i) {
            f[0][i] = false;
        }
        for (i = 1; i <= n; ++i) {
            f[i][0] = true;
        }
        
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= m; ++j) {
                f[i][j] = f[i-1][j];
                if (j >= A[i-1]) { // f[i]: corresponding to A[i-1]; can be equal, no greater than 
                    f[i][j] |= f[i-1][j - A[i-1]];
                }
            }
        }
        
        int res = 0;
        for (i = m; i >= 0; --i) {
            if (f[n][i] == true) {
                res = i;
                break;
            }
        }
        
        return res;
    }
}