// LinkedHashMap 
// class LRUCache {
    
//     int capacity;
//     Map<Integer, Integer> m;
    
//     public LRUCache(int capacity) {
//         this.capacity = capacity;
//         m = new LinkedHashMap<>(capacity, 0.75F, true);
//     }
    
//     public int get(int key) {
//         return m.getOrDefault(key, -1);
//     }
    
//     public void put(int key, int value) {
//         m.put(key, value);
//         if(m.size() > capacity){
//             int removeKey = m.keySet().iterator().next();
//             m.remove(removeKey);
//         }
//     }
    
// }

class Node{
    Node prev;
    Node next;
    int key;
    int value;
    public Node(int key, int value){
        this.key = key;
        this.value = value;
    }
}

class LRUCache {
    int capacity;
    int cnt;
    Node head;
    Node tail;
    Map<Integer, Node> m;
    
    public LRUCache(int capacity){
        this.capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        m = new HashMap<>();
        cnt = 0;
        head.next = tail;
        tail.prev = tail;
    }
    
    public int get(int key){
        if(m.containsKey(key)){
            Node node = m.get(key);
            remove(key);
            add(key, node.value);
            return node.value;
        }
        
        return -1;
    }
    public void put(int key, int value){
        if(m.containsKey(key)){
            remove(key);
        }
        add(key, value);
    }
    void remove(int key){
        Node cur = m.get(key);
        Node prev = cur.prev;
        Node next = cur.next;
        prev.next = next;
        next.prev = prev;
        
        m.remove(key);
        cnt--;
    }
    void add(int key, int value){
        Node node = new Node(key, value);
        Node next = head.next;
        
        head.next = node;
        node.next = next;
        next.prev = node;
        node.prev = head;
        
        m.put(key, node);
        cnt++;
        if(cnt > capacity){
            Node removeKey = tail.prev;
            remove(removeKey.key);
        }
    }
}
