#include <iostream>

using namespace std;

int arr1[16];
int arr2[16];
char map[16][16];
int n;
int main(){
  scanf("%d",&n);

  for(int i=0 ; i<n ; i++){
    scanf("%d",&arr1[i]);
  }
  for(int i=0 ; i<n ; i++){
    scanf("%d",&arr2[i]);
  }
  for(int i=0 ; i<n ; i++){
    for(int j=n-1 ; j>=0 ; j--){
      int a = (arr1[i]>>j)&1;
      int b = (arr2[i]>>j)&1;
      int c = a|b;
      if(c == 0){
        map[i][n-(j+1)] = ' ';
      }else map[i][n-(j+1)] = '#';
    }
  }
  for(int i=0 ; i<n ; i++){
    printf("%s\n",map[i]);
  }
}
