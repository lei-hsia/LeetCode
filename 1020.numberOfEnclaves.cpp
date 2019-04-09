class Solution {
public:
    int numEnclaves(vector<vetor<int>>& A) {
        for (auto i=0; i< A.size(); ++i) {
            for (auto j=0; j<A[0].size(); ++j) {
                if (i*j==0 || i==A.size()-1 || j==A[0].size()-1)
                    dfs(A, i, j);
            }
        }

        return accumulate(begin(A), end(A), 0, [](int s, vector<int>& r) {
            return s + accumulate(begin(r), end(r), 0);
        });
    }

    // 从边界开始递归, 能从边界上触及到的1全部变成0, 直到递归越界
    // ⚠️if条件中是A[i][j] != 1而不是==0; 因为如果是空是不用递归的也是直接返回
    void dfs(vector<vector<int>>& A, int i, int j) {
        if (i<0 || j<0 || i==A.size() || j==A[0].size() || A[i][j]!=1) return;
        A[i][j] = 0;
        dfs(A, i+1, j);
        dfs(A, i-1, j);
        dfs(A, i, j+1);
        dfs(A, i, j-1);
    }
};
