
// 450. Delete node in a BST
/* 关键: 如果只有一个子节点，指向另一个子节点就行了
        如果没有子节点，不管
        如果有两个子节点，找到右子树最小节点，值和当前节点互换，
        再递归找到并删除右子树最小值
        */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key){
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            } else {
                TreeNode* rightMin = root->right;
                while (rightMin->left) rightMin = rightMin->left;
                root->val = rightMin->val;
                // 还要在右子树中调用递归删除右子树的最小值
                root->right = deleteNode(root->right, rightMin->val);
            }
        }
        return root;
    }
};

// without using BST properties
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) {
            if (!root->right) return root->left;
            else {
                TreeNode* rightMin = root->right;
                while (rightMin->left) rightMin = rightMin->left;
                swap(root->val, rightMin->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};