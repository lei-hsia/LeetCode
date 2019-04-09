/**
Definition for a binary tree
**/
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelDFS(root, 0, res);
        return res;
    }
    void levelDFS(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (level==res.size()) res.push_back({});
        res[level].push_back(node->val);
        levelDFS(node->left, level+1, res);
        levelDFS(node->right, level+1, res);
    }
};
