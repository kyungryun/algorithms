#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);

    for(int T=1 ; T<=t ; T++){
        long long n;
        string ans;
        scanf("%lld",&n);
        long long x = 1;
        int turn = 0;
        long long term = 1;
        while(x < n){
            if(!turn){
                term *= 4;
            }
            x += term;
            turn = !turn;
        }
        if(turn) ans = "Alice";
        else ans = "Bob";
        printf("#%d %s\n",T,ans.c_str());
    }
}
