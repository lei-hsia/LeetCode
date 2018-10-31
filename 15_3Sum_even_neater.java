
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

// Given num: is an array;
// Build an ArrayList to solve it

public class 15_3Sum_even_neater{

	public List<List<Integer>> threeSum(int[] num){
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		int len = num.length, target = 0;

		if (len <= 2) return result;

		Arrays.sort(num);

		for(int i = 0; i <= len - 3; i++){
			int j = i + 1;
			int k = len - 1;

			while (j < k){
				if (num[i] + num[j] + num[k] < target) ++j;
				else if (num[i] + num[j] + num[k] > target) --k;
				else{
					result.append(Arrays.asList(num[i], num[j], num[k]));
					++ j;
					-- k;
					// avoid duplicates
					while (j < k && num[j] == num[j-1]) ++j;
					while (j < k && num[k] == num[k+1]) --k;
				}
			while (i <= len -3 && num[i] == num[i+1])
				++i;
			}
		}

		return result;
	}
}