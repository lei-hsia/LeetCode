
// add 2 numbers in form of linked list,
// return a linked list

struct ListNode {
	int val;
	ListNode *next;
	// C, struct 中的constructor: : field_name(param) {code}
	ListNode(int x) : val(x), next(NULL) {}
}

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// 定义一个prehead是因为list中的第一个node的val不一定是0,
        // 所以需要一个base node到第一个node,那么创建一个prehead
        ListNode prehead(0), *p = prehead;
        int extra = 0; // extra:进位与否,extra是1/0
        while (l1 || l2 || extra) {
        	int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        	extra = sum / 10;
        	p->next = new ListNode(sum % 10); // 这一步是真正地把梳子放进新list的node中
        	p = p->next;
        	l1 = l1 ? l1->next : 0;
        	l2 = l2 ? l2->next : 0;
        }

        return prehead.next;
        // 对next的用法: 指针用->, dereference得到node用.(因为相当于一个field)
	}
}