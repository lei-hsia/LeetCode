
/* 	

#313 super ugly numbers 和 #264 ugly numbers II 原理完全一样: 
1. base 不同分为了N个质数的赛道;
2. 每个赛道乘自己的base得到本道下一个number; 
3. 取global min, 加入总赛道
4. global min对应的那个赛道index++， 
5. global min放到总赛道中

上面的步骤循环直到n达到
```primes```是给的质数数组
```temp``` 是根据给的质数确定的每一轮算完得到的每一个质数赛道上的数，**实际上每一轮只更新一个数**
```index```对应每一个质数道上有多少个质数

	*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1), index(primes.size(), 0);
        while (res.size() < n) {
            vector<int> temp; // 每一轮算出来每个质数道上的结果(实际上每一轮只更新一个数)
            int mn = INT_MAX;
            for (int i = 0; i < primes.size(); ++i) {
                temp.push_back(res[index[i]] * primes[i]);
            }
            for (int i = 0; i < primes.size(); ++i) {
                mn = min(mn, temp[i]);
            }
            for (int i = 0; i < primes.size(); ++i) {
                if (mn == temp[i]) ++index[i];
            }
            res.push_back(mn);
        }
        return res.back();
    }
};