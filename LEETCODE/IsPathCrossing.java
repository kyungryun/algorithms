class IsPathCrossing {
    public boolean isPathCrossing(String path) {
        Set<String> set = new HashSet<String>();
        set.add("(0,0)");
        
        int r = 0;
        int c = 0;
        
        for(int i=0 ; i<path.length() ; i++){
            char tmp = path.charAt(i);
            
            if(tmp == 'N') r++;
            else if(tmp == 'S') r--;
            else if(tmp == 'E') c++;
            else c--;
            
            StringBuilder sb = new StringBuilder();
            sb.append("(");
            sb.append(c);
            sb.append(",");
            sb.append(r);
            sb.append(")");
            
            if(!set.add(sb.toString())) return true;
            else set.add(sb.toString());
        }
        
        return false;
    }
}
