class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        char[] s1 = text1.toCharArray();
        char[] s2 = text2.toCharArray();
        int m = s1.length;
        int n = s2.length;
        int[][] f = new int[m+1][n+1];
        int[][] pi = new int[m+1][n+1];
        int i, j;
        
        for (i = 0; i <= m; ++i) {
            for (j = 0; j <=n; ++j) {
                if (i == 0 || j == 0) {
                    f[i][j] = 0;
                    continue;
                }
                
                f[i][j] = Math.max(f[i-1][j], f[i][j-1]);
                if (f[i][j] == f[i-1][j]) { // don't move i, j, only record state
                    pi[i][j] = 0;
                }
                else if (f[i][j] == f[i][j-1]) {
                    pi[i][j] = 1;
                }
                if (s1[i-1] == s2[j-1]) {
                    f[i][j] = Math.max(f[i][j], f[i-1][j-1] + 1);
                    if (f[i][j] == f[i-1][j-1] + 1) {
                        pi[i][j] = 2;
                    }
                }
            }
        }
        
        char[] res = new char[f[m][n]];
        int p = f[m][n] - 1;
        i = m;
        j = n;
        while (i > 0 && j > 0) {
            if (pi[i][j] == 0) {
                --i;
            }
            else if (pi[i][j] == 1) {
                --j;
            }
            else {
                res[p] = s1[i-1];
                --p;
                --i; --j;
            }
        }
        
        System.out.println("Longest Common Subsequence is: ");
        for (i = 0; i < f[m][n]; ++i) {
            System.out.print(res[i]);
        }
        System.out.println("");
        
        return f[m][n];
    }
}