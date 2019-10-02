class Solution {
    public int largestRectangleArea(int[] h) {
        int n = h.length, res = 0;
        for (int i = 0; i < n; ++i) {
            // 最后一位不仅不能忽略，因为当前的高度是和后面一位比较，所以实际上最后一位总是要有的，所以应该i<n 而不是 i < n-1
            if (i+1 < n && h[i] <= h[i+1]) continue;
            int minHeight = h[i];
            int area = 0;
            for (int j = i; j >= 0; --j) {
                minHeight = Math.min(minHeight, h[j]);
                area = Math.max(area, minHeight * (i-j+1));
            }
            res = Math.max(res, area);
        }
        return res;
    }
}
