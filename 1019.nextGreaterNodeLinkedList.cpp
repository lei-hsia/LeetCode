class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        stack<int> s;
        vector<int> res(nums.size());
        for (int i = nums.size()-1; i>=0; --i) {
            while (!s.empty() && nums[i]>=s.top()) s.pop();
            res[i] = (s.empty())? 0 : s.top();
            s.push(nums[i]);
        }
        return res;
    }
}
