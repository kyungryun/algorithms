class Maximum69Number {
    public int maximum69Number (int num) {
        StringBuilder str = new StringBuilder(String.valueOf(num));
        
        int idx = str.indexOf("6");
        if(idx == -1) return num;
        
        str.setCharAt(idx, '9');
        
        return Integer.valueOf(str.toString());
    }
}
