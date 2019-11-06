// Given a set of non-negative integers, and a value sum, determine if 
// here is a subset of the given set with sum equal to given sum.

// Example: 
// Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output:  True  //There is a subset (4, 5) with sum 9.

// subset/permutation/combination: 递归

// 递归和dp的思想区别:
// 递归是对函数进行递归，是为了缩小问题的规模;
// dp是对问题的解进行递推，是从子问题,i.e. 缩小规模的解来看;

// 递归是dfs的实现方式; 
// 分治是递归的一种;
// 分治的套路: 分解->解决(触底)->合并(回溯)

// greedy是dp的一种特例

// isSubSetSum(int[] set, int n, int sum):= 
// finding whether there is a subset of set[] with sum equal to sum.
// n is # elements in set[].

// 因为这里实际上并不知道问题的解, 而是只是能递归缩小问题的规模, 所以是递归,不是dp
// 但是，还是从最后一步这个思想看的

// The isSubsetSum problem can be divided into two subproblems
// …a) Include the last element, recur for n = n-1, sum = sum – set[n-1]
// …b) Exclude the last element, recur for n = n-1.

// If any of the above the above subproblems return true, then return true.

// isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) || 
//                            isSubsetSum(set, n-1, sum-set[n-1])

static boolean isSubSetSum(int set[], int n, int sum) {

	// base
	if (sum == 0) return true;
	if (n == 0 && sum != 0) return false;

	if (set[n-1] > sum) {
		return isSubSetSum(set, n-1, sum);
	}

	return isSubSetSum(set, n-1, sum) || isSubSetSum(set, n-1, sum - set[n-1]);
}