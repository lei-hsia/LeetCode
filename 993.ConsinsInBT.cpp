
class Solution {
public:
	bool isConsins(TreeNode* root, int x, int y) {
		preorder(root, nullptr, x, y, 0);
		return px!=py && dx==dy;
	}
private:
	TreeNode* px;
	TreeNode* py;
	int dx;
	int dy;

	void preorder(TreeNode* node, TreeNode* p, int x, int y, int d) {
		if (!node) return;
		if (node->val == x) {px=p; dx=d;}
		if (node->val == y) {py=p; dy=d;}
		preorder(node->left, node, x, y, d+1);
		preorder(node->right,node, x, y, d+1);
	}
}