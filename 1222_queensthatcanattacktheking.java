// array和list: array是数组, list实际上底层是linked list;
// 相比之下array更像arrayList

// array为底，转化为list: Arrays.asList(x, y)


class Solution {
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        List<List<Integer>> res = new ArrayList<>();
        boolean[][] seen = new boolean[8][8];
        for (int[] q : queens) seen[q[0]][q[1]] = true;
        
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int x = king[0] + i, y = king[1] + j;
                while (Math.min(x, y) >=0 && Math.max(x, y) < 8) {
                    if (seen[x][y]) {
                        res.add(Arrays.asList(x, y));
                        break;
                    }
                    x += i; y += j;
                }
            }
        }
        return res;
    }
}
