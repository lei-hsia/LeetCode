
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /* 新用一个stack会Memory Limit Exceeded

        stack<int> stack;
        ListNode* cur = head;
        ListNode* result = new ListNode(0);
        // ListNode result(0);
        ListNode* reptr = result;
        
        while (cur->next != NULL) stack.push(cur->val);
        while (!stack.empty()) {
            reptr->next = new ListNode(stack.top());
            stack.pop();
        }
        return result->next;
        */

    	// 1. Iterative
        ListNode *prev = NULL, *cur = head, *next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            // next = cur->next; 这句话要写在上面一行cur=next之前，因为如果cur已经进位,cur到最后一个node再cur->next是NULL的next
        }
        return prev;
    }
};