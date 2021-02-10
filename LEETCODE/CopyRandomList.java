/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class CopyRandomList {
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        
        Map<Node, Node> map = new HashMap<>();
        Node cur = head;
        
        while(cur != null){
            map.put(cur, new Node(cur.val));
            cur = cur.next;
        }
        cur = head;
        
        while(cur != null){
            Node tmp = map.get(cur);
            tmp.next = map.get(cur.next);
            tmp.random = map.get(cur.random);
            cur = cur.next;
        }
        
        return map.get(head);
    }
}
