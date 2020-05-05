class Solution {
    public int maxEnvelopes(int[][] env) {
        if (env == null || env.length == 0) return 0;
        Arrays.sort(env, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] == b[0]) return a[1] - b[1];
                else return a[0] - b[0];
            }
        });
        int n = env.length;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        int i, j, res = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                if (env[i][0] > env[j][0] && env[i][1] > env[j][1]) {
                    f[i] = Math.max(f[i], f[j]+1);
                }
            }
            res = Math.max(res, f[i]);
        }
        
        return res;
    }
}