class Solution {
    int[][] f = null;
    char[] s = null;
    int n = 0;
    
    private void Compute(int i, int j) {
        // memorization
        if (f[i][j] != -1) return;
        if (i == j) {
            f[i][j] = 1;
            return;
        }
        if (i + 1 == j) {
            f[i][j] = s[i] == s[j] ? 2 : 1;
            return;
        }
        
        // recursion
        Compute(i+1, j);
        Compute(i, j-1);
        Compute(i+1, j-1);
        
        // dp;3 values needed in dp are calculated as above
        f[i][j] = Math.max(f[i+1][j], f[i][j-1]);
        if (s[i] == s[j]) {
            f[i][j] = Math.max(f[i][j], f[i+1][j-1] + 2);
        }
    }
    
    public int longestPalindromeSubseq(String ss) {
        s = ss.toCharArray();
        n = s.length;
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        f = new int[n][n];
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                f[i][j] = -1; // not computed yet
            }
        }
        Compute(0, n-1);
        return f[0][n-1];
    }
}