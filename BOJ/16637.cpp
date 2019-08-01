#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int N;
int nOp;
long long sum;
long long ans = -2e18;
char exp[20];
int visited[20];
bool flag;
long long calc(long long res, char op, long long num){
    if(op == '+') res += num;
    else if(op == '-') res -= num;
    else res *= num;

    return res;
}
void dfs(int cnt){
    if(cnt == nOp){
        char trans[20];
        queue<long long> q;
        queue<char>qq;
        sum = 0;
        for(int i=0 ; i<N ; i++){
            if(visited[i] && i != N-1){
                q.push(calc(exp[i]-'0', exp[i+1], exp[i+2]-'0'));
                i+=2;
            }else if(exp[i] -'0' >=0 && exp[i] - '0' <=9){
                q.push(exp[i]-'0');
            }else qq.push(exp[i]);
        }
        sum = q.front();
        q.pop();
        while(!qq.empty()){
            long long a = q.front();
            q.pop();
            sum = calc(sum,qq.front(),a);
            qq.pop();
        }
        ans = max(sum,ans);
        return;
    }
    for(int i=0 ; i<N-1 ;){
        if(exp[i] - '0' < 0 || exp[i] - '0' > 9) {
            i++;
            continue;
        }

        if(!visited[i] && !visited[i+2]){
            visited[i] = true;
            visited[i+2] = true;
            dfs(cnt+1);
            visited[i] = false;
            visited[i+2] = false;
        }
        i+=2;
    }
}
int main(){
    scanf("%d",&N);
    scanf("%s",exp);
    sum = exp[0] - '0';
    for(int i=1 ; i<N ; i+=2){
        sum = calc(sum, exp[i], exp[i+1] - '0');
    }
    ans = max(sum,ans);
    nOp = 1;
    for(int i=5 ; i<=N ; i+=2){
        dfs(0);
        nOp++;
    }

    printf("%lld\n",ans);
}
