#include <cstdio>
#include <algorithm>
using namespace std;

char room[1000001];
int ans;
int number[10];
int main(){
    scanf("%s",room);
    int i=0;
    while(room[i] != '\0'){
        number[room[i++]-'0']++;
    }
    for(int i=0 ; i<=9 ; i++){
        if(i != 6 && i != 9 ) ans = max(ans, number[i]);
    }
    printf("%d\n",max(ans, (number[6] + number[9] + 1)/2));
}
