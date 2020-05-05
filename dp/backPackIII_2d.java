public int backPackIII(int[] A, int[] V, int m) {
	int n = A.length;
	if (n == 0) return 0;

	int[][] f = new int[n+1][m+1];
	int i, j;
	f[0][0] = 0;
	for (i = 1; i <= m; ++i) {
		f[0][i] = -1;
	}

	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= m; ++j) {
			f[i][j] = f[i-1][j];
			if (j >= A[j-1] && f[i][j - A[i-1]] != -1) {
				f[i][j] = Math.max(f[i][j], f[i][j - A[i-1]] + V[i-1]);
			}
		}
	}

	int res = 0;
	for (i = 0; i <= m; ++i) {
		if (f[n][i] != -1) {
			res = Math.max(res, f[n][i]);
		}
	}

	return res; 
}