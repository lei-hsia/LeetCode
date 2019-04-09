
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<int> out(n, -1);
		solveNQueens(pos, 0, res);
		return res;
	}

	void solveNQueens(vector<int>& pos, int row, vector<vector<string>>& res) {
		int n = pos.size();
		if (row == n) {
			vector<string> out(n, string(n, '.'));
			for (int i=0; i<n; ++i) {
				out[i][pos[i]] = 'Q';
			}
			res.push_back(out);
		} 
		else {
			for (int col=0; col<n; ++col) {
				if (isValid(pos, row, col)) {
					pos[row] = col;
					solveNQueens(pos, row+1, res);
					pos[row] = -1;
				}
			}
		}
	}

	bool isValid(vector<int>& pos, int row, int col) {
		for (int i=0; i<row; ++i) {
			if (col==pos[i] || abs(row-i)==abs(col-pos[i]))
				return false;
		}
		return true;
	}
}