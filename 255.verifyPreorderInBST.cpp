
// 255. verify preorder sequence in BST
class Solution {
public:
	bool verifyPreorder(vector<int>& preorder) {
		int low = INT_MIN;
		stack<int> s;
		for (auto a: preorder) {
			if (a < low) return false;
			while (!s.empty() && a > s.top()) {
				low = s.top(); s.pop();
			}
			s.push(a);
		}
		return true;
	}
}

// 空间复杂度 O(1)的做法: 
// 不新建一个空间为O(N)的stack, 直接在原有的preorder的arr
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN, i = -1;
        for (auto a : preorder) {
            if (a < low) return false;
            while (i >= 0 && a > preorder[i]) {
                low = preorder[i--];
            }
            preorder[++i] = a;
        }
        return true;
    }
};