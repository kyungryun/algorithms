#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
list<char> secret;
vector<char> password;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int num;
    
    list<char>::iterator idx;
    cin>>num;
    for(int i=0; i<num; i++){
        cin>>input;
        
        for(int j=0; j<input.length(); j++){
            secret.push_back(input[j]);
        }
        idx = secret.end();
        for(idx = secret.begin(); idx != secret.end(); ){
            if(*idx == '<'){
                if(idx != secret.begin()){
                    --idx;
                }
            }
            else if(*idx == '>'){
                if(idx != secret.end()){
                    ++idx;
                }
            }
            else if(*idx == '-'){
                if(idx != secret.begin())
                    idx = secret.erase(--idx);
            }
            else{
                password.push_back(*idx);
            }
        }
        
        for(int i=0; i<password.size(); i++){
            cout<<password[i];
        }
        
    }
    
    return 0;
}