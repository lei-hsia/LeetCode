
class solution {
	
	public static class ListNode {
		int val;
		ListNode next;
		ListNode(int x) { val = x; }
 }
	
	//traversal/print list; overloading print
	public static void traversal(ListNode head) {
		ListNode n = head;
		while (n != null){
			System.out.print(n.val + " ");
			n = n.next;
		}
		
	}
    public static ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        ListNode cur = head;
        while (cur.next != null) {
            if (cur.next.val == cur.val) cur.next = cur.next.next;
            else cur = cur.next;
        }
        return head;
    }
    
    public static void main(String[] args) {
    	ListNode first = new ListNode(1);
    	ListNode second = new ListNode(1);
    	ListNode third = new ListNode(2);

    	first.next = second;
    	second.next = third;
    	
    	traversal(deleteDuplicates(first)); 
    	
    }
}