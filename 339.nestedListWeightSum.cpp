
// 339. Nested List Weight Sum
class Solution {
public:
	int depthSum(vector<NestedInteger>& nestedList) {
		return getSum(nestedList, 1);
	}
	int getSum(vector<NestedInteger>& nl, int depth) {
		int res = 0;
		for (auto a : nl) {
			res += a.isInteger() ? a.getInteger() * depth : 
								   getSum(a.getList(), depth++);
		}
		return res;
	}
}

