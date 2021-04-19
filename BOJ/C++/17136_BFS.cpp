#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[11][11];

struct Data{
    int map[11][11];
    int r;
    int c;
    int paper[5];
    int cnt;
};
void mapCopy(int (*a)[11], int (*b)[11]){
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            a[i][j] = b[i][j];
        }
    }
}
bool isZero(int (*map)[11]){
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            if(map[i][j]) return false;
        }
    }
    return true;
}
void fill(int n, int r, int c, int (*map)[11]){
    for(int i=r ; i<r+n+1 ; i++){
        for(int j=c ; j<c+n+1 ; j++){
            map[i][j] = 0;
        }
    }
}
bool check(int n, int r, int c, int (*map)[11]){
    for(int i=r ; i<r+n+1 ; i++){
        for(int j=c ; j<c+n+1 ; j++){
            if(!(i>=0 && i<10 && j>=0 && j<10 && map[i][j])) return false;
        }
    }
    return true;
}
int main(){
    int ans = -1;
    bool flag = false;
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            scanf("%d",&map[i][j]);

        }
    }
    Data data;
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            if(map[i][j] == 1){
                data.r = i;
                data.c = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    data.cnt = 0;
    mapCopy(data.map, map);
    for(int i=0 ; i<5 ; i++) data.paper[i] = 5;


    queue<Data> q;
    q.push(data);

    while(!q.empty()){
        Data nData = q.front();
        q.pop();
        int tmpMap[11][11];
        int paper[5];

        int nr = nData.r;
        int nc = nData.c;
        int cnt = nData.cnt;
        for(int i=0 ; i<5 ; i++) paper[i] = nData.paper[i];
        mapCopy(tmpMap, nData.map);

        if(ans != -1 && cnt > ans) continue;
        if(isZero(tmpMap)){
            if(ans == -1){
                ans = cnt;
            }
            ans = min(ans, cnt);
        }
        for(int i=0 ; i<5 ; i++){
            if(paper[i]-1 >= 0 && check(i,nr,nc,tmpMap)){
                Data tData;
                mapCopy(tData.map, tmpMap);
                fill(i,nr,nc,tData.map);
                tData.cnt = cnt+1;
                for(int j=0 ; j<5 ; j++) tData.paper[j] = paper[j];
                tData.paper[i]--;

                flag = false;
                for(int j=0 ; j<10 ; j++){
                    for(int k=0 ; k<10 ; k++){
                        if(tData.map[j][k]){
                            tData.r = j;
                            tData.c = k;
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }

                q.push(tData);
            }
        }
    }
    printf("%d\n",ans);
}
