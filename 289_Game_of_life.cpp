最重要的一点: 所有的cell都是同时更新状态, 而遍历还是一个一个更新, 所以要用状态机转换, 并不能直接根据相邻的cell活着的数目确定, 因为前面遍历过的
已经改变了状态, 所以是不准的

class Solution {
public:
    /*
    transitional state:  1 && 3 最后变为live, 1 && 2最开始是live
    0 : dead to dead
    1 : live to live
    2 : live to dead
    3 : dead to live
    */
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> di{1, 1, 1, 0, 0, -1, -1, -1};
        vector<int> dj{1, 0, -1, 1, -1, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int lives = 0;
                for (int k = 0; k < 8; ++k) {
                    if (i+di[k] <0 || i+di[k] >=m || j+dj[k]<0 || j+dj[k]>= n) continue;
                    if (board[i+di[k]][j+dj[k]] == 1 || board[i+di[k]][j+dj[k]] == 2) lives++;
                }
                if ((board[i][j]==1 || board[i][j]==2) && (lives<2 || lives>3)) board[i][j] = 2;
                if (board[i][j]==0 && lives == 3) board[i][j] = 3; // 本来board[i][j] == 3 也是变为3, 但是本来就是3, 实际上不用改变
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
