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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null) return head;
        
        ListNode ans = head;
        int n1, n2;
        while(head != null && head.next != null){
            n1 = head.val;
            n2 = head.next.val;
            
            if(n1 == n2){
                while(head.next != null && head.next.val == n1){
                    head.next = head.next.next;
                }
            }
            head = head.next;
        }
        return ans;
        
    }
}
