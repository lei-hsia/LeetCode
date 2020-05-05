public class Solution {
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    public boolean firstWillWin(int n) {
        // write your code here
        if (n == 0) return false;
        if (n == 1) return true;
        boolean[] f = new boolean[n+1];
        f[0] = false;
        f[1] = true;
        for (int i = 2; i <=n; ++i) {
            // i: take 1, remain: i-1, rival must lose: then I will win; or 
            // take 2, remain: i-2, rival must lose: then I will win 
            f[i] = (!f[i-1]) || (!f[i-2]);
        }
        return f[n];
    }
}