#include <string>
#include <iostream>

using namespace std;

int main(){
    string str;
    while(1){
        getline(cin,str);
        if(str.compare("END") == 0) break;

        for(int i=str.size()-1 ; i>=0 ; i--){
            cout<<str[i];
        }
        cout<<"\n";
    }
}
