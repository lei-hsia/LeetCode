/**
Given a m x n grid filled with non-negative numbers, find a path 
from top left to bottom right which minimizes the sum of all 
numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

// output also included: 

class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        if (n == 0) return 0;
        int[][] f = new int[m][n];
        // path, solution: 记录状态
        // pi[i][j] = 0 : from up
        // pi[i][j] = 1 : from left
        int[][] pi= new int[m][n];
        int i, j;
        
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (i ==0 && j ==0) {
                    f[i][j] = grid[i][j];
                    continue;
                }
                
                int t = Integer.MAX_VALUE;
                // row && column: two rounds; get min from both sides
                if (i > 0) {
                    t = Math.min(t, f[i-1][j]);
                    if (t == f[i-1][j]) { // 这里记录状态
                        pi[i][j] = 0;
                    }
                }
                if (j > 0) {
                    t = Math.min(t, f[i][j-1]); 
                    if (t == f[i][j-1]) {
                        pi[i][j] = 1;
                    }
                }
                f[i][j] = t + grid[i][j];
            }
        }
        
        int[] path = new int[m+n-1];
        int x = m -1;
        int y = n -1;
        // reverse order: 
        // initial: 1 5 6 3 2 7
        // final:   7 2 3 6 5 1
        for (int p = 0; p < m+n-1; ++p) {
            path[p] = grid[x][y];
            if (pi[x][y] == 0) --x; // from up
            else --y; // from left
        }
        
        for (int p = m+n-2; p>=0; --p) {
            System.out.println(path[p]);
        }
        
        return f[m-1][n-1];
    }
}