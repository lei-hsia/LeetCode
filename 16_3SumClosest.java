
import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<=nums.length-3;i++){
            int j = i+1;
            int k = nums.length - 1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(Math.abs(sum - target) < Math.abs(result - target))
                    result = sum;
                if(sum < target)
                    j++;
                else if(sum > target)
                    k--;
                else{
                    j++;
                    k--;
                }
            }
        }
        return result;
    }

	// main: debug
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		Solution s = new Solution();
		int[] input = {-1, 2, 1, -4};
		int target = 1;
		System.out.println(s.threeSumClosest(input, target));
	}
}

