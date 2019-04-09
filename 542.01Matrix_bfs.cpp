class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs{{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==0) q.push({i,j});
                else matrix[i][j] = INT_MAX;
            }
        }

        while(!q.empty()) {
            auto t = q.front(); q.pop();
            for (auto dir : dirs) {
                int x = t.first + dir[0], y = t.second + dir[1];
                // 如果当前的值小于周围的值+1: 那么当前的值不用更新,因为当前的值更小
                if (x<0 || x>=m || y<0 || y>=n || matrix[x][y] <= matrix[t.first][t.second]+1)
                    continue;
                matrix[x][y] = matrix[t.first][t.second]+1;
                q.push({x,y});
            }
        }
        return matrix;
    }
}
