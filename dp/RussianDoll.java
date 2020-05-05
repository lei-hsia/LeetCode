// for循环外层i从0开始而不是1开始, 因为即使f一开始都赋值为1, res初始化为0, 如果size就是1而i从1开始，那么根本就进不了for循环, res不会被更新所以还是0;
// 实际上应该要记住: 如果前面不是二维的dp数组有整行整列的初始化值,那么i应该总是从0开始而不是1开始

class Solution {
    public int maxEnvelopes(int[][] pairs) {
        int n = pairs.length;
        if (n == 0) return 0;
        Arrays.sort(pairs, new Comparator<int[]>(){
            public int compare(int[] a, int[] b) {
                if (a[0] == b[0]) 
                    return a[1] - b[1];
                else return a[0] - b[0];
            }
        });
        
        int[] f = new int[n];
        Arrays.fill(f, 1);
        int i, j, res = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][0] && pairs[i][1] > pairs[j][1]) {
                    f[i] = Math.max(f[i], f[j] + 1);
                }
            }
            res = Math.max(res, f[i]);
        }
        return res;
    }
}