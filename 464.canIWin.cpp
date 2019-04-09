class Solution {
public:
    bool canIWin(int m, int t) {
        if (m >= t) return true;
        if (m*(m+1)/2 < t) return false;
        unordered_map<int, bool> map;
        return canIWin(m, t, 0, res, map);
    }

    bool canIWin(int length, int total, int used, unordered_map<int, bool>& m) {
        if (m.count(used)) return m[used];
        for (int i=0; i<length; ++i) {
            int cur = (1 << i);
            if ((cur & used) == 0) {  // mask的值按位与得到 0，说明没有在used中出现
                if (total <= i+1 || !canIWin(length, total-(i+1), cur|used, m)) {
                    m[used] = true;
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
}
