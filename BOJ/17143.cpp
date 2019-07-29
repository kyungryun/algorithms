#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Fish{
    int r;
    int c;
    int s;
    int d;
    int z;
    int live;
};
int R,C,M;
vector<Fish> v;
vector<int> map[101][101];
int dr[5] = {0,-1,1,0,0};
int dc[5] = {0,0,0,1,-1};
int main(){
    scanf("%d%d%d",&R,&C,&M);
    for(int i=0 ; i<M ; i++){
        Fish f;
        scanf("%d%d%d%d%d",&f.r,&f.c,&f.s,&f.d,&f.z);
        f.live = true;
        v.push_back(f);
        map[f.r][f.c].push_back(i);
    }
    int fisher = 0;
    int sum = 0;

    for(int t=0 ; t<C ; t++){
        fisher++;
        for(int i=1 ; i<=R ; i++){
            if(map[i][fisher].size() == 1){
                //printf("eat %d\n",v[map[i][fisher][0]].z);
                sum += v[map[i][fisher][0]].z;
                v[map[i][fisher][0]].live = false;
                map[i][fisher].clear();
                break;
            }
        }
        for(int i=0 ; i<M ; i++){
            if(v[i].live == false) continue;
            map[v[i].r][v[i].c].clear();
        }
        for(int i=0 ; i<M ; i++){
            if(v[i].live == false) continue;
            int nr = v[i].r;
            int nc = v[i].c;
            int s = v[i].s;
            int d = v[i].d;

            if(d <= 2 ){
                int move = s % ((R-1)*2);
                while(move--){
                    if(nr == 1 && d == 1) d = 2;
                    if(nr == R && d == 2) d = 1;
                    nr += dr[d];
                }
            }else {
                int move = s % ((C-1)*2);
                while(move--){
                    if(nc == 1 && d == 4) d = 3;
                    if(nc == C && d == 3) d = 4;
                    nc += dc[d];
                }
            }
            v[i].r = nr;
            v[i].c = nc;
            v[i].d = d;
            map[nr][nc].push_back(i);
        }
        for(int i=1 ; i<=R ; i++){
            for(int j=1 ; j<=C ; j++){
                int size = map[i][j].size();
                int MAX = 0;
                int idx = 0;
                if(size > 1){
                    for(int k=0 ; k<size ; k++){
                        if(v[map[i][j][k]].z > MAX){
                            MAX = v[map[i][j][k]].z;
                            idx = map[i][j][k];
                        }
                    }
                    for(int k=0 ; k<size ; k++){
                        if(idx != map[i][j][k]) v[map[i][j][k]].live = false;
                    }
                    map[i][j].clear();
                    map[i][j].push_back(idx);
                }
            }
        }
    }
    printf("%d\n",sum);
}
