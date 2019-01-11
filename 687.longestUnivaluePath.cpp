
// 687 Longest Univalue Path
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int count = 0;
        longestDFS(root, count);
        return count;
    }
    int longestDFS(TreeNode* node, int& count) {
        if (!node) return 0;
        int leftCount = longestDFS(node->left, count);
        int rightCount= longestDFS(node->right, count);
        leftCount = (node->left && node->val == node->left->val) ? ++leftCount : 0; // not satisfying: assign 0 to leftCount
        rightCount = (node->right && node->val==node->right->val) ? ++rightCount : 0;
        count = max(count, leftCount+rightCount);
        return max(leftCount, rightCount);
    }
};

// 多递归
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(sub, helper(root->left, root->val) + helper(root->right, root->val));
    }
    int helper(TreeNode* node, int parent) {
        if (!node || node->val != parent) return 0;
        return 1 + max(helper(node->left, node->val), helper(node->right, node->val));
    }
};