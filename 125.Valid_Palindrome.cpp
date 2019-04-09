// 回文字符串 : 用 Manacher算法,或者左右双指针向中间夹击
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (!isAlphaNum(s[left])) ++left;
            else if (!isAlphaNum(s[right])) --right;
            else if ((s[left]+32-'a')%32 != (s[right]+32-'a')%32) return false;
            else {
                ++left; --right;  // 判断完了两个位置上的,都向中间移动一位
            }
        }
        return true;
    }

    bool isAlphaNum(char &ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
};
