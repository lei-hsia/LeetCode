
// 错误的: 
// runtime error: member access within null pointer of type xxx
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return false;
        if (sameTree(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool sameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }
};

// this works
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (sameTree(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool sameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }
};