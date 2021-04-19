#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


const int PN = 5381;
const int HASH_SIZE = 300000;

int hash_table[HASH_SIZE][50];
int hash_size = 0;
string hash_data[500000];

int strcmp(string a, string b){
    return a.compare(b);
}
unsigned int get_key(string str){
    int p = 1;
    unsigned int key = 0;
    for(int i=0 ; str[i] != '\0' ; i++){
        key += p*str[i];
        p *= PN;
    }
    return key % HASH_SIZE;
}

void add(string str){
    int i;
    hash_data[hash_size] = str;
    unsigned int key = get_key(str);
    int &h_size = hash_table[key][0];
    hash_table[key][h_size+1] = hash_size;
    hash_size++;
    h_size++;
}

int contain(string str){
    unsigned int key = get_key(str);
    int &h_size = hash_table[key][0];
    for(int i=1 ; i<=h_size ; i++){
        int n_pos = hash_table[key][i];
        if(strcmp(str, hash_data[n_pos]) == 0){
            return n_pos;
        }
    }
    return -1;
}
bool remove(string str){
    unsigned int key = get_key(str);
    int &h_size = hash_table[key][0];
    for(int i=1 ; i<=h_size ; i++){
        int n_pos = hash_table[key][i];
        if(strcmp(hash_data[n_pos], str) == 0){
            for(int j=i+1 ; j<=h_size ; j++){
                hash_table[key][j-1] = hash_table[key][j];
            }
            h_size--;
            return true;
        }
    }
    return false;
}

int n,m;
string a[500001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string str;

    for(int i=0 ; i<n ; i++){
        cin>>str;
        add(str);
    }
    int idx = 0;
    for(int i=0 ; i<m ; i++){
        cin>>str;
        if(contain(str) != -1){
            a[idx] = str;
            idx++;
        }
    }
    sort(a, a+idx);
    cout<<idx<<"\n";
    for(int i=0 ; i<idx ; i++){
        cout<<a[i]<<"\n";
    }
}
