#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
int mat[101][101];
vector<pair<int, pair<int, int>>> v;
void check(int y, int x){
    int ny = y;
    int nx = x;
    while(mat[ny][x] != 0) ny++;
    while(mat[y][nx] != 0) nx++;
    for(int i=y ; i<ny ; i++){
        for(int j=x ; j<nx ; j++){
            mat[i][j] = 10;
        }
    }
    int row = ny - y;
    int col = nx - x;
    v.push_back(make_pair(row*col,make_pair(row, col)));
}
int main(){
    int t;
    scanf("%d",&t);
    for(int T=1 ; T<=t ; T++){
        v.clear();
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                scanf("%d",&mat[i][j]);
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][j] > 0 && mat[i][j] < 10){
                    check(i,j);
                }
            }
        }
        sort(v.begin(), v.end());
        int size = v.size();
        printf("#%d %d ",T, size);
        for(int i=0 ; i<size ; i++){
            printf("%d %d ",v[i].second.first, v[i].second.second);
        }
        printf("\n");
    }

}
