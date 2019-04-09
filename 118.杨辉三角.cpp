// 其实并没有必要用组合的性质:
// 下面一行的数是上面位置和上面左边位置的数的和-->
//非常明显的状态转移方程: dp

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
      vector<vector<int>> dp(numRows, vector<int>());
      for (int i=0; i<numRows; ++i) {
          dp[i].resize(i+1, 1);  // vector的resize
          for (int j=1; j<i; ++j) {
              dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
          }
      }
      return dp;
  }
}
