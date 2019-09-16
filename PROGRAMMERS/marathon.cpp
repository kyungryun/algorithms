#include <string>
#include <vector>
#include <map>
using namespace std;

const int PN = 23;
const int HASH_SIZE = 100000;

int hash_table[HASH_SIZE][50];
int hash_size = 0;
string hash_data[100000];

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
        if(str.compare(hash_data[n_pos]) == 0){
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
        if(str.compare(hash_data[n_pos]) == 0){
            for(int j=i+1 ; j<=h_size ; j++){
                hash_table[key][j-1] = hash_table[key][j];
            }
            h_size--;
            return true;
        }
    }
    return false;
}
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for(int i=0 ; i<completion.size() ; i++){
        if(contain(completion[i]) == -1){
            add(completion[i]);
            m[completion[i]] = 1;
        }else m[completion[i]]++;
    }
    for(int i=0 ; i<participant.size() ; i++){
        if(contain(participant[i]) == -1){
            answer = participant[i];
        }else{
            if(m[participant[i]] == 1) {
                remove(participant[i]);
            }
            else m[participant[i]]--;

        }
    }
    return answer;
}
