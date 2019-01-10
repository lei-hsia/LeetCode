
// iterative
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            count++;
            if (count == k) return p->val;
            p = p->right;
        }
        return 0;
    }
};

// divide & conquer
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = countNode(root->left);
        if (count >= k) { // k-th smallest in left subtree
            return kthSmallest(root->left, k);
        } else if (count+1 < k) {
            return kthSmallest(root->right, k-count-1);
        }
        return root->val;
    }
    int countNode(TreeNode* node) {
        if (!node) return 0;
        return countNode(node->left) + 1 + countNode(node->right);
    }
};