// essence: greedy.

// Lemma: if the optimal contains a period ```[i, j]``` where you buy at time ```i``` and sell at time ```j```, then each increment in ```[i,j]``` must go up all the time.
// Because if not, if there's an increment going down, then the optimal can be further improved by only extracting the going up period, with dropping this going down period.
// Using this mindset, it can be showed that the best is to just buy everyday and sell tomorrow, if price tomorrow is higher than that of today.

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i-1]) 
                sum += (prices[i] - prices[i-1]);
        }
        return sum;
    }
}