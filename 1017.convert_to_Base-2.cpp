
    N & 1: 异或与判断: N的二进制如果最后一位是1那么返回true, 否则返回false
    N >> 1: N 右移一位，相当于 N / 2

    res = Integer.toString(N & 1) + res;
    因为每次都是得到最高位的余数是1还是0， 所以新得到的数总是加在左边

    为什么 base2: N = N >> 1; base-2: N = -(N >> 1);
    本质原因: 二进制是把每个bit乘以1, 2, 4, 8...
    -2进制是1, -2, 4, -8... 即(-2)^0, (-2)^1, (-2)^2, ...
    可以看出从0轮开始辗转，那么只有奇数轮的时候是base用负数,偶数轮是不变的;
    当前第一轮对应的底数是(-2)^0 = 1, 所以当前是正数，那么下一轮是负数，
    所以while中当前是正数，负正负正地变化;

class Solution {
public:
    string base2(int N) {
        string res = "";
        while (N) {
            res = to_string(N & 1) + res;
            N = N >> 1;
        }
        return res.empty() ? "0" : res;
    }

    string baseNeg2(int N) {
        string res = "";
        while (N) {
            res = to_string(N & 1) + res;
            N = -(N >> 1);
        }
        return res.empty() ? "0" : res;
    }
}
