#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long ans;
long long a, b;

long long calc(string str, long long len, bool bit){
    long long e;
    if(bit) e = 0;
    else e = 1;
    long long j=1;
    long long res = 0;
    for(long long i = len-1 ; i>=e ; i--, j*=9){
        if(str[i] >'3') str[i]--;
        res += (str[i] - '0')*j;
    }
    return res;
}
int main(){
    int T;

    scanf("%d",&T);
    for(int t = 1 ; t<=T ; t++){
        ans = 0;
        string a;
        string b;
        cin>>a>>b;
        bool aa,bb;
        aa = bb = true;
        if(a[0] == '-') aa = false;
        if(b[0] == '-') bb = false;
        long long ca,cb;
        ca = calc(a, a.size(), aa);
        cb = calc(b, b.size(), bb);

        if(!aa && bb) ans = cb + ca - 1;
        else if(aa && bb) ans = cb - ca;
        else ans = ca-cb;
        cout<<"#"<<t<<" "<<ans<<"\n";
    }
}
