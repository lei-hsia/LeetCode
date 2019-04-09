class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        for (auto a: nestedList) {
            res += getSum(a, 1);
        }
        return res;
    }

    int getSum(NestedInteger n, int level) {
        int res = 0;
        if (n.isInteger()) res += level * n.getInteger();
        for (auto a : n.getList()) {
            res += getSum(a, level+1);
        }
        return res;
    }
}
