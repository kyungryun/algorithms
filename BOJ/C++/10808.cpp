#include <cstdio>
using namespace std;

int main(){
    char word[101];
    int alphabet[26] = {0,};

    scanf("%s",word);

    for(int i=0 ; word[i] != 0 ; i++){
        alphabet[word[i]-97]++;
    }
    for(int i=0 ; i<=25 ; i++){
        printf("%d ",alphabet[i]);
    }
    printf("\n");
}
