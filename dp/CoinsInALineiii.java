// Alice, Bob can only take the first or last element in an array. 
// They add their sum obtained, and each time play optimally as in 
// a game theory problem.

// dp: how to get the equation: 

// let A represent the sum Alice gets, B for Bob, then if they want to 
// have their maximum, let X = (A-B), Y = (B-A), Alice wants to maximize
// A while Bob wants to maximize B. A = -B;

// In each round, 他们自己都是先手，每一轮就当作之前那个人拿两端的某一个数这件事情
// 没有发生；

// 这里难的是每次都是自己的payoff函数转移一次之后下一轮是另一个人的payoff函数，
// 不知道怎么写关系; 
// 而在有了 A=-B 之后，另一个人的与我的payoff的差值，就是我跟他的payoff的差值的相反数；
// 然后再加上我现在拿的首尾某个数，两种情况取较大值，得到我的payoff的转移方程.

// 因为是每次从两端拿一个，所以很明显是array在往中间缩小，所以有明显的子问题: 区间型dp

// f[i][j] := 当前先手在面对a[i...j]数字时，能得到的最大的与对手的数字差

// f[i][j] = max(a[i] - f[i+1][j], a[j] - f[i][j-1])

// 计算顺序: 
// 长度为1: f[0][0], f[1][1], ... f[n-1][n-1]
// 长度为2: f[0][1], ... f[n-2][n-1]
// ...
// 长度为n: f[0][n-1]

// 最后: 如果f[0][n-1] >= 0: 先手Alice胜，否则必败

public class Solution {
	/**
		@param values: an array of integers
		@return: a boolean which equals to true of firs player will win
	*/
	public boolean firstWillWin(int[] A) {

		int n = A.length;
		int[][] f = new int[n][n];
		int i, j, len;
		for (i = 0; i < n; ++i) {
			f[i][i] = A[i];
		}

		for (len = 2; len <= n; ++len) {
			for (i = 0; i <= n - len; ++i) {
				j = i + len - 1;
				f[i][j] = Math.max(A[i] - f[i+1][j], A[j] - f[i][j-1]);
			}
		}

		return f[0][n-1] >= 0;
	}
}