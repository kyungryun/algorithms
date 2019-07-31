#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N,M,D;
int field[16][16];
int arr[16][16];
int bow[16];
int ans = 0;

void print(){
    printf("\n");
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            printf("%d ",field[i][j]);
        }
        printf("\n");
    }
    printf("------------------\n");
    for(int i=0 ; i<M ; i++){
        printf("%d ",bow[i]);
    }
    printf("\n");
}

bool compare(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>&b){
    if(a.first == b.first) return a.second.second < b.second.second;
    else return a.first < b.first;
}
bool check(){
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            if(field[i][j] == 1) return false;
        }
    }
    return true;
}
int attack(int b){
    int kill = 0;
    vector<pair<int ,pair<int, int> >> v;
    for(int i=N-1 ; i>=N-D ; i--){
        for(int j=0 ; j<M ; j++){
            if(field[i][j] != 0){
                int dist = abs(N - i) + abs(b - j);
                if(dist <= D){
                    v.push_back(make_pair(dist, make_pair(i,j)));
                }
            }
        }
    }
    sort(v.begin(), v.end(),compare);
    if(v.size() > 0){
        if(field[v[0].second.first][v[0].second.second] == 1){
            field[v[0].second.first][v[0].second.second] = 2;
            kill++;
        }
    }
    /*for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            if(field[i][j] == 2){
                field[i][j] = 0;
                kill++;
            }
        }
    }*/
    return kill;
}
void move(){
    for(int i=N-1 ; i>=0 ; i--){
        for(int j=0 ; j<M ; j++){
            if(field[i][j] == 2) field[i][j] = 0;
            else if(i == N-1) field[N-1][j] = 0;
            else{
                field[i+1][j] = field[i][j];
                field[i][j] = 0;
            }
        }
    }
}
void mapCopy(int (*a)[16], int(*b)[16]){
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            a[i][j] = b[i][j];
        }
    }
}
void dfs(int cnt){
    if(cnt == 3){
        int kill = 0;
        mapCopy(field, arr);
        while(1){
            if(check()) break;
            for(int i=0 ; i<M ; i++){
                if(bow[i] == 1) kill+=attack(i);
            }
            move();
            //print();
            //printf("%d\n",kill);
        }
        ans = max(ans, kill);
        return;
    }

    for(int i=0 ; i<M ; i++){
        if(bow[i] == 0){
            bow[i] = 1;
            dfs(cnt+1);
            bow[i] = 0;
        }
    }
}
int main(){
    scanf("%d%d%d",&N,&M,&D);

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dfs(0);
    printf("%d\n",ans);
}
