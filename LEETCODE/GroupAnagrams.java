class GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        
        for(String str : strs){
            char[] c = str.toCharArray();
            Arrays.sort(c);
            
            String key = String.valueOf(c);
            if(!map.containsKey(key)){   
                map.put(key, new ArrayList<>(Arrays.asList(str)));
            }else{
                map.get(key).add(str);    
            }
            
        }
        
        return new ArrayList<>(map.values());
    }
}
