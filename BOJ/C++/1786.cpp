#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MOD = 1000000000;

int main(){
    char W[1000001], S[1000001];
    int M, N;
    gets(S);
    gets(W);
    N = strlen(S);
    M = strlen(W);
    int PN = 23;
    vector<int> result;
    long long G = 0, H = 0, head = 1;
    for(int i=0 ; i<M ; i++){
        G = (G*PN + W[i]) % MOD;
        H = (H*PN + S[i]) % MOD;
        if(i!=0)head = (head*PN)%MOD;
    }
    for(int i=0; i<=N-M; i++){
        if(G == H)result.push_back(i+1);
        if(i+M == N) break;
        H = (PN*(H-S[i]*head) + S[i+M])%MOD;
        if(H < 0) H += MOD;
    }
    printf("%d\n", result.size());
    for(int i: result)
        printf("%d ", i);
}
