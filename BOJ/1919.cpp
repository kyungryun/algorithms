#include <cstdio>

using namespace std;

int an[26];
int bn[26];
char a[1001], b[1001];
int cnt;
int main(){
    scanf("%s%s",a,b);
    for(int i=0 ; a[i] != 0 ; i++){
        an[a[i]-'a']++;
    }
    for(int i=0 ; b[i] != 0 ; i++){
        bn[b[i]-'a']++;
    }
    for(int i=0 ; i<26 ; i++){
        if(an[i] != bn[i]){
            cnt += abs(an[i] - bn[i]);
        }
    }
    printf("%d\n",cnt);
}
