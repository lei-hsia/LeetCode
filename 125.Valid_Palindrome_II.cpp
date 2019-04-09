// 附加条件: 字符串中最多删一个, 看能不能是 palindrome
class Solution {
public:
    // 如果出现了要删掉一个字母的情况: 删掉之后进入isValid()函数,此时要严格
    // 匹配了, 相当于pruning之后的子串判断是不是palindrome:从一个函数进入了另一个函数
    // 如果没有出现不等的情况, 不进入if, 一直就是 ++left; --right;
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] != s[right]) return isValid(s, left, right-1) || isValid(s, left+1, right);
            ++left; --right;
        }
        return true;
    }

    bool isValid(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left; --right;
        }
        return true;
    }
}
