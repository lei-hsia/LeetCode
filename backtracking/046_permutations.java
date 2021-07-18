// 046
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList();
        List<Integer> tmp = new ArrayList();
        permute(nums, tmp, res);
        return res;
    }
    
    public void permute(int[] nums, List<Integer> tmp, List<List<Integer>> res) {
        if (nums.length == tmp.size()) {
            res.add(new ArrayList(tmp));
            return;
        }
        
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (tmp.contains(nums[i])) continue;
            tmp.add(nums[i]);
            permute(nums, tmp, res);
            tmp.remove(tmp.size() - 1);
        }
    }
}
```

