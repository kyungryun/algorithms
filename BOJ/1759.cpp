#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int L,C;
char arr[20];
int idx;
void dfs(int cnt, string str, int c1, int c2){
    if(str.size() == L){
        if(c1<2 || c2<1) return;
        cout<<str<<"\n";
    }
    for(int i=cnt ; i<C ; i++){
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
            dfs(i+1, str+arr[i], c1, c2+1);
        }else{
            dfs(i+1, str+arr[i], c1+1, c2);
        }
    }
}
int main(){
    cin>>L>>C;
    char c;
    for(int i=0 ; i<C ; i++){
        cin>>arr[i];
    }
    sort(arr, arr+C);
    dfs(0,"",0,0);
}
