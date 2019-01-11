
// 用set记录出现过的数, 没有过就加入set，有过就判断resume point是不是1
class Solution {
public:
    bool isHappy(int n) {
        set<int> set;
        while (n != 1) {
            int temp = 0;
            while (n) {
                temp += (n%10)*(n%10);
                n /= 10;
            }
            n = temp;
            if (set.count(n)) break;
            else set.insert(n);
        }
        return 1==n;
    }
};

// 只要出现cycle: 用 Linked List Cycle Detection的
// “快慢指针循环总相遇”的方法
int digitSquareSum(int n) {
	int sum = 0, temp;
	while (n) {
		temp = sum % 10;
		sum += temp * temp;
		n /= 10;
	}
	return sum;
}

bool isHappy(int n) {
	int slow, fast;
	slow = fast = n;
	do {
		slow = digitSquareSum(slow);
		fast = digitSquareSum(fast);
		fast = digitSquareSum(fast);
	} while (slow != fast)

	if (slow == 1) return 1;
	else return 0;
}