// for循环中仍然是挨着的一位一位地判断, 所以for中并没有一个while循环
// count因为是要每一位都记录连着的dups的次数，所以用一个数组对应i记录到每一位连着的char就很好，如果只是一个int记录，并不能体现连着的dups

// 1. two pointers
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size(), i = 0;
        vector<int> count(n);
        for (int j = 0; j < n; ++i, ++j) {
            s[i] = s[j];
            count[i] = (i > 0 && s[i-1] == s[i]) ? count[i-1] + 1 : 1;
            if (count[i] == k) i -= k;
        }
        return s.substr(0, i);
    }
};

// 2. stack
// 实际上就是把string s相邻k个的元素去掉:做这个事情，然后重新赋值给stack这个vector(实际上是一个vector), vector中的每个
// 元素是一个pair分别记录的是当前的char和出现的次数; 
// >>> 其实这个stack像是s的一个卷积数组, 相邻的相同的char改变的是stack数组中的同一个cell，改变的是freq但是char还是那个,达到阀值k就删掉
class Solution {
public:
    string removeDuplicates(string s, int k) {
        // 因为一进入for循环就有.back(),所以stack必须有一个初始值, 否则: 
        // Line 832: Char 45: runtime error: pointer index expression with base 0x000000000000 overflowed to 0xfffffffffffffff8 (stl_iterator.h)
        vector<pair<int, char>> stack = {{0, '#'}};
        for (char c : s) {
            if (stack.back().second != c) {
                stack.push_back({1, c});
            } else if (++stack.back().first == k) {  // 进入这个else说明==c, 那么肯定要先++,如果达到了k，就pop_back()
                stack.pop_back();
            }
        }
        string res;
        for (auto &p : stack) {
            res += string(p.first, p.second);  
        }
        return res;
    }
};
