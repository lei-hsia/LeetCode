class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        vector<int> dp(N+1);
        for (int i=0; i<=N; ++i) {
            if (i<10) {
                if (i==0 || i==1 || i==8) dp[i]=1;
                else if (i==2 || i==5 || i==6 || i==9) {
                    dp[i]=2; ++res;
                }
            } else {
                int a = dp[i/10], b = dp[i%10];
                if (a==1 && b==1) dp[i] = 1;
                else if (a>=1 && b>=1) {
                    dp[i]=2; ++res;
                }
            }
        }
        return res;
    }
}
