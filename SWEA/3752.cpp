#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int T=1 ; T<=t ; T++){
        int N;
        int d[100001]={0};
        int score[101];
        int sum = 0;
        int ans = 0;
        scanf("%d",&N);
        for(int i=0 ; i<N ; i++){
            scanf("%d",&score[i]);
            sum+=score[i];
        }
        d[0] = 1;
        for(int i=0 ; i<N ; i++){
            for(int j=sum ; j>=0 ; j--){
                if(d[j] == 1){
                    d[j+score[i]] = 1;
                }
            }
        }
        for(int i=0 ; i<100001 ; i++){
            if(d[i] == 1) ans++;
        }
        printf("#%d %d\n",T,ans);
    }
}
