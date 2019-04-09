class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.size()!=9 || board[0].size() !=9) return;
        solveSudokuDFS(board,0,0);
    }

    bool solveSudokuDFS(vector<vector<char>>& board, int i, int j) {
        if (i==9) return true;
        if (j>=9) return solveSudokuDFS(board, i+1, 0);
        if (board[i][j] == '.') {
            for (int k=1; k<=9; ++k) {
                board[i][j] = (char)(k+'0');
                if (isValid(board, i, j)) {
                    // 这里是递归的精髓:整个棋盘都走完了之后才会出if返回true
                    if (solveSudokuDFS(board, i, j+1)) return true;
                }
                // 如果不是valid的,说明尝试的这个数不行,赋值为初始的 '.'
                board[i][j] = '.';
            }
        } else {
            // 如果当前这个位置上已经有数字了, 直接遍历下一个格子
            return solveSudokuDFS(board, i, j+1);
        }
        // 如果没有从上面的if出去说明给定的初始状态不能solve这个数独,返回false
        return false;
    }

    bool isValid(vector<vector<char>>& board, int i, int j) {
        for (int col=0; col<9; ++col)
            if (col != j && board[i][j]==board[i][col]) return false;
        for (int row=0; row<9; ++row)
            if (row != i && board[i][j]==board[row][j]) return false;
        // 这个对应格子里面的
        for (int row=i/3*3; row<i/3*3+3; ++row) {
            for (int col=j/3*3; col<j/3*3+3; ++col) {
                if ((row!=i || col!=j) && board[i][j]==board[row][col]) return false;
            }
        }
        return true;
    }
};
