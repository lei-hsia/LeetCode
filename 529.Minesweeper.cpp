
class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if (board.empty() || board[0].empty()) return {};
		int m = board.size(), n = board[0].size();
		int row = click[0], col = click[1], count =0;
		if (board[row][col] == 'M') {
			board[row][col] = 'X';
		} else {
			vector<vector<int>> neighbors;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					int x = row + i, y = col + j;
					if (x<0 || x>=m || y<0 || y >=n) continue;
					if (board[x][y] == 'M') count++; // 根据一圈cells是不是M的情况算这个cell的count
					else if (count == 0 && board[x][y] == 'E') neighbors.push_back({x, y});
				}
			}
			if (count > 0) board[row][col] = count + '0';
			else {
				for (auto a : neighbors) {
					board[row][col] = 'B';
					updateBoard(board, a);
				}
			}
		}
	}
}