
// 501. find mode in Binary Search Tree

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int maxNum = 0;
        unordered_map<int, int> map;
        preorder(root, maxNum, map);
        for (auto entry: map) {
            if (entry.second == maxNum)
                res.push_back(entry.first);
        }
        return res;
    }
    void preorder(TreeNode* root, int& maxNum, unordered_map<int, int>& map) {
        if (!root) return ;
        maxNum = max(maxNum, ++map[root->val]);
        preorder(root->left, maxNum, map);
        preorder(root->right, maxNum, map);
    }
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
    	vector<int> res;
    	int mx = 0, cnt = 1;
    	TreeNode* pre = NULL;
    	inorder(root, pre, cnt, mx, res);
    	return res;
    }
    void inorder(TreeNode* node, TreeNode* pre, int& cnt, int& mx, vector<int>& res) {
    	if (!node) return;
    	inorder(node->left, pre, cnt, mx, res);
    	if (pre) {
    		cnt = (node->val == pre->val) ? cnt + 1 : cnt;
    	}
    	if (cnt >= mx) {
    		if (cnt > mx) res.clear();
    		res.push_back(node->val);
    		mx = cnt;
    	}
    	pre = node;
    	inorder(node->right, pre, cnt, mx, res);
    }
};