class Solution {
    public int longestPalindromeSubseq(String ss) {
        char[] s = ss.toCharArray();
        int n = s.length;
        if (n == 0) return 0;
        if (n == 1) return 1; 
        int[][] f = new int[n][n];
        int[][] pi = new int[n][n];
        int i, j, len;  // [i,j] type: outer loop on len
        
        for (i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (i = 0; i < n-1; ++i) {
            f[i][i+1] = s[i] == s[i+1] ? 2 : 1;
        }
        for (len = 3; len <= n; ++len) {
            // 0 1 2 ...    n-3 n-1
            for (i = 0; i <= n - len; ++i) {
                j = i + len - 1;
                f[i][j] = Math.max(f[i+1][j], f[i][j-1]);
                if (f[i][j] == f[i+1][j]) {
                    pi[i][j] = 0;
                }
                else {
                    pi[i][j] = 1;
                }
                if (s[i] == s[j]) {
                    f[i][j] = Math.max(f[i][j], f[i+1][j-1] + 2);
                    if (f[i][j] == f[i+1][j-1] + 2) {
                        pi[i][j] = 2;
                    }
                }
            }
        }
        
        char[] res = new char[f[0][n-1]];
        int p = 0, q = f[0][n-1] - 1;
        i = 0;
        j = n - 1;
        while (i <= j) {
            if (i == j) {
                res[p] = s[i];
                break;
            }
            if (i + 1 == j) {
                res[p] = s[i];
                res[q] = s[j];
                break;
            }
            
            if (pi[i][j] == 0) {
                ++i;
            }
            else {
                if (pi[i][j] == 1) {
                    --j;
                }
                else {
                    res[p++] = s[i];
                    res[q--] = s[j];
                    ++i;
                    --j;
                }
            }
        }
        
        System.out.println("Result is: ");
        for (i = 0; i < f[0][n-1]; ++i) {
            System.out.print(res[i]);
        }
        System.out.println("");
        
        return f[0][n-1];
    }
}