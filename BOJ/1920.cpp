#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int mod = 1000007;
const int prime = 31;

int n,m;
int a,b;

vector<int> hash_table[1000007];

int get_key(int key){
    if(key < 0) key *= -1;
    return (key) % mod;
}
int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>a;
        int key = get_key(a);
        hash_table[key].push_back(a);
    }
    cin>>m;
    for(int i=0 ; i<m ; i++){
        cin>>b;
        int key = get_key(b);
        bool flag = false;
        for(int j=0 ; j<hash_table[key].size() ; j++){
            if(hash_table[key][j] == b){
                flag = true;
                break;
            }
        }
        if(flag) cout<<"1\n";
        else cout<<"0\n";
    }
}
