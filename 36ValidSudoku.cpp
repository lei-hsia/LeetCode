class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> rowFlag(m, vector<bool>(n, false));
        vector<vector<bool>> colFlag(m, vector<bool>(n, false));
        vector<vector<bool>> celFlag(m, vector<bool>(n, false));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
              if (board[i][j]>='1' && board[i][j]<= '9') {
                  int c = board[i][j] - '1';
                  if (rowFlag[i][c] || colFlag[c][j] || celFlag[3*(i/3)+j/3][c])
                      return false;
                  rowFlag[i][c] = true;
                  colFlag[c][j] = true;
                  celFlag[3*(i/3)+j/3][c] = true;
              }
            }
        }
        return true;
    }
}
