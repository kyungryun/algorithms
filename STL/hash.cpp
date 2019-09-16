#include <cstdio>

const int PN = 5381;
const int HASH_SIZE = 30000;

int hash_table[HASH_SIZE][50];
int hash_size = 0;
char hash_data[30000][100];

int strcmp(char a[], char b[]){
    int i=0,j=0;
    while(a[i]){
        if(a[i++] != b[j++]){
            break;
        }
    }
    return a[i] - b[j];
}
unsigned int get_key(char str[]){
    int p = 1;
    unsigned int key = 0;
    for(int i=0 ; str[i] != '\0' ; i++){
        key += p*str[i];
        p *= PN;
    }
    return key % HASH_SIZE;
}

void add(char str[]){
    int i;
    for(i=0 ; str[i] != '\0' ; i++){
        hash_data[hash_size][i] = str[i];
    }
    hash_data[hash_size][i] = 0;
    unsigned int key = get_key(str);
    int &h_size = hash_table[key][0];
    hash_table[key][h_size+1] = hash_size;
    hash_size++;
    h_size++;
}

int contain(char str[]){
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
bool remove(char str[]){
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

int main(){
    int n;
    scanf("%d",&n);
    char str[50][100];
    for(int i=0 ; i<n ; i++){
        scanf("%s",str[i]);
    }
    for(int i=0 ; i<n ; i++){
        if(contain(str[i]) == -1){
            printf("add %s \n",str[i]);
            add(str[i]);
        }else{
            printf("not add\n");
        }
    }

}
