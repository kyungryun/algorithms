class Star {
    public int solution(int[] a) {
        int answer = 0;
        int[] star = new int[a.length];
        for(int i=0 ; i<a.length ; i++) star[a[i]]++;
        
        for(int i=0 ; i<star.length ; i++){
            if(star[i] == 0) continue;
            if(star[i] <= answer) continue;
            int cnt = 0;
            for(int j=0 ; j<star.length-1 ; j++){
                if(a[j] != i && a[j+1] != i) continue;
                if(a[j] == a[j+1]) continue;
                cnt++;
                j++;
            }
            answer = Math.max(answer, cnt);
        }
        return answer*2;
    }
}
