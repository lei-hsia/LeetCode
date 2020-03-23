/*

给出一个数XX，−10^5≤x≤10^5，可以随意改变XX中数字的顺序，
问可以得到的最小数是多少。要求得到的数不允许有前导0。

e.g. 
输入：301，输出：103
输入：-8139，输出：-9831

achtung:
1. 处理前导0：把最小的非零数字换到首位即可。
2. 处理负数：这里利用C++的特性，对正数取模会得到正余数，
对负数取模会得到负余数。例如 −8139%10=−9−8139%10=−9，
所以我们对所有数字从小到大排序时，−9−9会排在最前面， 
而这正是我们想要的。因此处理负数时，代码不需要做任何修改！
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_minimum_number(int x)
{
    if (!x) return 0;

    vector<int> nums; // 存储X的所有数位
    while (x)
    {
        nums.push_back(x % 10); // 依次取出X的所有数位
        x /= 10;
    }
    sort(nums.begin(), nums.end());
    int k = 0;
    while (nums[k] == 0) k++;
    swap(nums[0], nums[k]); // 处理前导0，把最小的非零数字换到首位
    int res = 0;
    for (int i = 0; i < nums.size(); i++) res = res * 10 + nums[i]; // 把各个数位拼成一个整数
    return res;
}

int main()
{
    int x;
    cin >> x;
    cout << get_minimum_number(x) << endl;
    return 0;
}

作者：yxc
链接：https://www.acwing.com/blog/content/13/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。