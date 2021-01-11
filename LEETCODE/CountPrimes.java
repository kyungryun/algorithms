public class CountPrimes {

    public int countPrimes1(int n) {
        boolean []b = new boolean[n];

        for(int i=2 ; i<n ; i++){
            if(b[i]) continue;

            for(int j=2*i ; j<n ; j+=i){
                b[j] = true;
            }
        }

        int cnt = 0;
        for(int i=2 ; i<n ; i++){
            if(!b[i]) cnt++;
        }

        return cnt;
    }
    public int countPrimes2(int n) {
        if(n < 3) return 0;

        boolean[] ans = new boolean[n];

        int cnt = n/2;
        for(int i=3 ; i*i < n ; i+= 2){
            if(ans[i]) continue;

            for(int j= i*i ; j< n ; j += 2*i){
                if(!ans[j]){
                    ans[j] = true;
                    cnt--;
                }
            }
        }

        return cnt;
    }

}
