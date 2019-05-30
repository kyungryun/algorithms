#include <cstdio>

using namespace std;

int main(){
  int T;
  int n;
  char encoded[100001];
  char decoded[100001];
  int ascii[128];
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    scanf("%s",encoded);

    for(int i=0 ; i<26 ; i++) ascii['A' + i] = i;
    for(int i=0 ; i<26 ; i++) ascii['a' + i] = 26+i;
    for(int i=0 ; i<11 ; i++) ascii['0' + i] = i+52;
    ascii['+'] = 62;
    ascii['/'] = 63;

    int pos = 0;
    int pos2 = 0;
    int bits;
    while(encoded[pos]){
      bits = ascii[encoded[pos++]]<<18;
      bits += ascii[encoded[pos++]]<<12;
      bits += ascii[encoded[pos++]]<<6;
      bits += ascii[encoded[pos++]];
      decoded[pos2++] = bits>>16&0xFF;
      decoded[pos2++] = bits>>8&0xFF;
      decoded[pos2++] = bits&0xFF;
    }
    printf("#%d \n%s\n",t,decoded);
  }
}
