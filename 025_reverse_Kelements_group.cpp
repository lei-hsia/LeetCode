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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // k-batch each time, push to stack and save to result
        stack<int> kElements;
        ListNode* result = new ListNode(0);
        ListNode* zero = result;
        ListNode* ptr = head;
        int count;
        
        while (ptr != NULL) {
            ++count;  // #elements in this list
            ptr = ptr ->next;
        }
        
        while (count >= k) {
            for (int i=0; i<=k; i++) {
                kElements.push(ptr -> val);
                ptr = ptr->next;
            }
            zero -> next = new ListNode(kElements.top());
            kElements.pop();
            count -= k;
        }
        return result->next; 
        