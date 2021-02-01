class SortList {
    public ListNode sortList(ListNode head) {
       return sort(head);
    }
    
    public ListNode sort(ListNode head){
        if(head == null || head.next == null) return head;
        
        ListNode mid = findMid(head);
        ListNode left = sort(head);
        ListNode right = sort(mid);
        
        return merge(left, right);
    }
    public ListNode merge(ListNode head1, ListNode head2){
        ListNode temp = new ListNode();
        ListNode cur = temp;
        
        while(head1 != null && head2 != null){
            if(head1.val < head2.val){
                cur.next = head1;
                head1 = head1.next;
            }else{
                cur.next = head2;
                head2 = head2.next;
            }
            cur = cur.next;
        }
        
        if(head1 != null){
            cur.next = head1;
        }else{
            cur.next = head2;
        }
        
        return temp.next;
        
    }
    public ListNode findMid(ListNode head){
        ListNode slow = head;
        ListNode fast = head.next;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode mid = slow.next;
        slow.next = null;

        return mid;
    }

}
