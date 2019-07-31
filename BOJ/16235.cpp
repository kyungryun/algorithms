#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int N, M, K;
int map[11][11];
int nutr[11][11];
int dr[8] = {0,0,1,-1,1,-1,-1,1};
int dc[8] = {1,-1,0,0,1,1,-1,-1};
struct Tree{
    int r;
    int c;
    int age;
};

bool compare(const Tree &a, const Tree &b){
    return a.age < b.age;
}
int main(){
    vector<int> tree[11][11];
    scanf("%d%d%d",&N, &M, &K);

    for(int i=1 ; i<=N; i++){
        for(int j=1 ; j<=N ; j++){
            map[i][j] = 5;
        }
    }
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            scanf("%d",&nutr[i][j]);
        }
    }
    int r,c,a;
    for(int i=0 ; i<M ; i++){
        scanf("%d%d%d",&r,&c,&a);
        tree[r][c].push_back(a);
    }
    while(K--){

        vector<Tree> live;
        vector<Tree> dead;
        for(int i=1 ; i<=N;  i++){
            for(int j=1 ; j<=N ; j++){
                if(tree[i][j].empty()) continue;

                sort(tree[i][j].begin(), tree[i][j].end());
                int size = tree[i][j].size();

                vector<int> age;
                for(int k=0 ; k<size ; k++){
                    int a = tree[i][j][k];
                    Tree t;
                    if(map[i][j] >= a){
                        map[i][j] -= a;
                        age.push_back(a+1);
                        if((a+1)%5 == 0){
                            t.r = i;
                            t.c = j;
                            t.age = 1;
                            live.push_back(t);
                        }
                    }else{
                        t.r = i;
                        t.c = j;
                        t.age = a/2;
                        dead.push_back(t);
                    }
                }
                tree[i][j] = age;
            }
        }
        int size = dead.size();
        for(int i=0 ; i<size ; i++){
            map[dead[i].r][dead[i].c] += dead[i].age;
        }
        size = live.size();
        for(int i=0 ; i<size ; i++){
            int r = live[i].r;
            int c = live[i].c;
            for(int j=0 ; j<8 ; j++){
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
                tree[nr][nc].push_back(1);
            }
        }

        for(int i=1 ; i<=N ; i++){
            for(int j=1 ; j<=N ; j++){
                map[i][j] += nutr[i][j];
            }
        }
    }
    int ans = 0;
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            ans += tree[i][j].size();
        }
    }
    printf("%d\n",ans);
}
