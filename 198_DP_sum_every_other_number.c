
// can't take adjacent values in the array

/*
	input: [1,2,3,1]; output: 4
	input: [2,7,9,3,1]; output: 12

*/

#define max(a, b) ((a)>(b) ? (a):(b))
/*
	this is "conditional operator"
	means: 
		if ((a) > (b)) return a
		else return b;
*/ 

int rob(int num[], int n) {
	int a = 0;
	int b = 0;

	for (int i = 0; i < n; i++) {
		// add to the previous stored sum and compare along the way
		// is the essence of DP
		if (i%2 == 0) a = max(a+num[i], b);
		else b = max(a, b+num[i]);
	}

	return max(a,b);
}