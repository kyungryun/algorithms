class ImplementTrie {

    TrieNode root = null;
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode cur = root;
        for(int i=0 ; i<word.length() ; i++){
            char c = word.charAt(i);
            int idx = c - 'a';
            if(cur.node[idx] == null) cur.node[idx] = new TrieNode();
            cur = cur.node[idx];

        }
        cur.str = word;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode cur = root;
        for(int i=0 ; i<word.length() ; i++){
            char c = word.charAt(i);
            int idx = c - 'a';
            if(cur.node[idx] == null) return false;
            cur = cur.node[idx];
        }
        return cur.str != null;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode cur = root;
        for(int i=0 ; i<prefix.length() ; i++){
            char c = prefix.charAt(i);
            int idx = c - 'a';
            if(cur.node[idx] == null) return false;
            cur = cur.node[idx];
        }
        return true;
    }
}

class TrieNode{
    TrieNode[] node = new TrieNode[26];
    String str = null;
}
