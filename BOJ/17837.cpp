#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Chess{
    int dir;
    int r;
    int c;
};

int dr[5] = {0,0,0,-1,1};
int dc[5] = {0,1,-1,0,0};
int flip[5] = {0,2,1,4,3};
int board[13][13];
Chess p[10];
int n,k;
vector<int> p_info[13][13];

int move(int i){
    int r = p[i].r, c = p[i].c;

    int nr = r + dr[p[i].dir];
    int nc = c + dc[p[i].dir];
    
    if(nr < 1 || nr > n || nc < 1 || nc > n || board[nr][nc] == 2){
        p[i].dir = flip[p[i].dir];
        nr = r + dr[p[i].dir];
        nc = c + dc[p[i].dir];

        if(nr < 1 || nr > n || nc < 1 || nc > n || board[nr][nc] == 2){
            return -1;
        }
    }
    vector<int>::iterator s;
    for(s = p_info[r][c].begin() ; s != p_info[r][c].end() ; s++){
        if(*s == i) break;
    }
    if(board[nr][nc] == 1){
        reverse(s,p_info[r][c].end());
    }

    vector<int>::iterator it = s;
    for( ;it != p_info[r][c].end() ; it++){
        p[*it].r = nr;
        p[*it].c = nc;
        p_info[nr][nc].push_back(*it);
    }
    p_info[r][c].erase(s, p_info[r][c].end());
    return p_info[nr][nc].size();
}
int simulation(){
    int t=1;
    while(t<=1000){
        for(int i=0 ; i<k ; i++){
            int cnt = move(i);
            if(cnt>=4){
                return t;
            }
        }
        t++;
    }
    return -1;
}

int main(){
    scanf("%d%d",&n,&k);
    
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            scanf("%d",&board[i][j]);
        }
    }
    for(int i=0 ; i<k ; i++){
        scanf("%d%d%d",&p[i].r,&p[i].c,&p[i].dir);
        p_info[p[i].r][p[i].c].push_back(i);
    }

    int ans = simulation();
    printf("%d\n",ans);
}