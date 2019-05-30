#include <cstdio>

using namespace std;

int main(){
  int T;
  int n;
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    char pass[51];
    char temp[51];
    int cnt = 0;
    scanf("%s",pass);
    int i;
    for(i=0 ; pass[i] != '\0' ; i++)temp[i] = '0';
    temp[i] = '\0';

    for(int i=0 ; temp[i]!='\0';i++){
      if(pass[i] != temp[i]){
        for(int j=i ; temp[j] != '\0' ; j++) {
          if(pass[i] == '1')
            temp[j] = '1';
          else temp[j] = '0';
        }
        cnt++;
      }
    }
    printf("#%d %d\n",t, cnt);
  }
}
