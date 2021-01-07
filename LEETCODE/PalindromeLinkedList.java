/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        ListNode list1 = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }       
        ListNode list2 = reverse(slow);
        
        return check(list1, list2);
    }
    ListNode reverse(ListNode head){
        ListNode next = null;
        ListNode prev = null;
        ListNode curr = head;
        while(curr != null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    boolean check(ListNode head1, ListNode head2){
        while(head2 != null){
            if(head1.val != head2.val) return false;
            
            head1 = head1.next;
            head2 = head2.next;
        }
        
        return true;
    }
}
