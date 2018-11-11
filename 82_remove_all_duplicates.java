
public class Solution {

	public class ListNode {
		int val;
		ListNode next;
		ListNode(int x) { val = x; }
	}

	public ListNode deleteDuplicates(ListNode head) {
		// use two pointers
		// slow - track the node before the dup nodes,
		// fast - to find the last node of dups
		ListNode dummy = new ListNode(0), fast = head, slow = dummy;
		slow.next = fast;

		while (fast != null) {
			while (fast.next != null && fast.val == fast.next.val) {
				// fast lane to the last node of dups
				fast = fast.next;
			}
			if (slow.next != fast)  // duplicate detected
				slow.next = fast.next;
			else slow = slow.next;  // no dup
			fast = fast.next;
		}

		return dummy.next;
	}
}