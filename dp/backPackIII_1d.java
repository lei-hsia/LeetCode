public int backPackIII(int[] A, int[] V, int m) {
	int n = A.length;
	if (n == 0) return 0;

	// if just 1-d, then it's the dimension of M
	int[] f = new int[m+1];
	int i, j;
	f[0] = 0;
	for (i = 1; i <= m; ++i) {
		f[i] = -1;
	}

	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= m; ++j) {
			// f[j] = f[j];
							   // f[i][j - A[i-1]]
			if (j >= A[j-1] && f[j - A[i-1]] != -1) {
				f[j] = Math.max(f[j], f[j - A[i-1]] + V[i-1]);
				// now f[j] is f[i][j]
			}
		}
	}

	int res = 0;
	for (i = 0; i <= m; ++i) {
		if (f[i] != -1) {
			res = Math.max(res, f[i]);
		}
	}

	return res; 
}