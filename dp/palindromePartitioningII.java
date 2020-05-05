public class Solution {

/**
Lintcode: Palindrome Partition II; 

Given a string s, cut s into some substrings such that every substring 
is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.
	
		@param s a string
		@return an integer
	*/

	private boolean[][] = calcPalin(char[] s) {
		int n = s.length;
		boolean[][] f = new boolean[n][n];
		int i, j, c;
		// init
		for (i = 0; i < n; ++i) {
			for (j = i; j < n; ++j) {
				f[i][j] = false;
			}
		}

		// odd length palindrome
		// center character
		for (c = 0; c < n; ++c) {
			i = j = c;
			// extend to both directions
			while (i >= 0 && j < n && s[i] == s[j]) {
				f[i][j] = true;
				--i;
				++j;
			}
		}

		// even length palindrome
		// center character
		for (c = 0; c < n-1; ++c) {
			i = c;
			j = c + 1;
			// extend to both directions
			while (i >= 0 && j < n && s[i] == s[j]) {
				f[i][j] = true;
				--i;
				++j;
			}
		}

		return f;
	}

	// dp
	public int minCut(String ss) {
		// write code here
		char[] s = ss.toCharArray();
		int n = s.length;
		if (n == 0) {
			return 0;
		}

		boolean[][] isPalin = calcPalin(s);
		int i, j;
		int[] f = new int[n+1];
		f[0] = 0;
		for (i = 1; i <= n; ++i) {
			f[i] = Integer.MAX_VALUE;
			for (j = 0; j < i; ++j) {
				if (isPalin[j][i-1]) { // 0-(n-1) corresponds: j - (i-1)
					f[i]  =Math.max(f[i], f[j] + 1);
				}
			}
		}
	}

	return f[n] - 1; // #cut = #palindrome - 1

}