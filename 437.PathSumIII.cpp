
// 1.最直观会想到的方法
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> onePath;
        pathSumDFS(root, sum, 0, onePath, res);
        return res;
    }
    void pathSumDFS(TreeNode* node, int sum, int cumSum, vector<TreeNode*>& onePath, int& res) {
        if (!node) return ;
        cumSum += node->val;
        onePath.push_back(node);
        if (sum == cumSum) res++;
        int temp = cumSum;
        for (int i = 0; i < onePath.size()-1; i++) {
            temp -= onePath[i]->val;
            if (sum == temp) res++;
        }
        pathSumDFS(node->left, sum, cumSum, onePath, res);
        pathSumDFS(node->right,sum, cumSum, onePath, res);
        onePath.pop_back();
    }
};

// 比较难想的连续递归
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return curSum(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int curSum(TreeNode* node, int& sum, int pre) {
        if (!node) return 0;
        pre += node->val;
        return (pre==sum) + curSum(node->left, sum, pre) + curSum(node->right, sum, pre);
    }
};