
// O(N), inorder traversal, 2 O(N) space vectors
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> vals;
        inorder(root, nodes, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vals.size(); i++) {
            nodes[i]->val = vals[i];
        }
    }
     void inorder(TreeNode* root, vector<TreeNode*>& nodes, vector<int>& vals) {
         if (!root) return ;
         inorder(root->left, nodes, vals);
         nodes.push_back(root);
         vals.push_back(root->val);
         inorder(root->right, nodes, vals);
     }
};

// O(1) extra space: find the two nodes and swap
class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        first->val = first->val + second->val;
        second->val = first->val - second->val;
        first->val = first->val - second->val;
    }
    
    void inorder(TreeNode* root) {
        if (!root) return ;
        inorder(root->left);
        if (first==NULL && prev->val >= root->val) first = prev;
        if (first!=NULL && prev->val >= root->val) second = root;
        prev = root;
        inorder(root->right);
    }