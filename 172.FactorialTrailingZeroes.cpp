class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n/5;
            n /= 5; // 因为乘数可能很大,n自己辗转相除
        }
        return res;
    }
};

// 上面是迭代，还可以递归
class Solution {
public:
    int trailingZeroes(int n) {
        return n==0 ? 0 : n/5 + trailingZeroes(n/5);
    }
}
