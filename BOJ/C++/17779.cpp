#include <cstdio>
#include <algorithm>
using namespace std;

struct Point{
    int r;
    int c;
};
int n;
int city[21][21], area[21][21];
int ans = 987654321;
Point p[4];

bool check(int r, int c, int d1, int d2){
    if(r + d1 + d2 >= n || c - d1 < 0 || c + d2 >= n) return false;
    return true;
}
void calc(){
    int population[5] = {0,};
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            population[area[i][j]-1] += city[i][j];
        }
    }
    sort(population, population + 5);
    ans = min(ans, population[4] - population[0]);
}
void district(){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            area[i][j] = 5;
        }
    }
    int temp = 0;
    for(int i=0 ; i<p[1].r ; i++){
        if(i >= p[0].r) temp++;
        for(int j=0 ; j<=p[0].c - temp ; j++){
            area[i][j] = 1;
        }
    }
    temp = 0;
    for(int i=0 ; i<=p[2].r ; i++){
        if(i > p[0].r) temp++;
        for(int j=p[0].c+1+temp ; j<n ; j++){
            area[i][j] = 2;
        }
    }
    temp = 0;
    for(int i=n-1 ; i>= p[1].r ; i--){
        if(i < p[3].r) temp++;
        for(int j=0 ; j<p[3].c-temp ; j++){
            area[i][j] = 3;
        }
    }
    temp = 0;
    for(int i=n-1 ; i>p[2].r ; i--){
        if(i <= p[3].r) temp++;
        for(int j=p[3].c+temp ; j<n ; j++){
            area[i][j] = 4;
        }
    }
    calc();

}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&city[i][j]);
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=1 ; j<n ; j++){
            for(int d1=1 ; d1<=j ; d1++){
                for(int d2=1 ; d2<n-j ; d2++){
                    if(check(i,j,d1,d2)){
                        p[0].r = i, p[0].c = j;
                        p[1].r = i + d1, p[1].c = j - d1;
                        p[2].r = i + d2, p[2].c = j + d2;
                        p[3].r = i + d1 + d2, p[3].c = j - d1 + d2;
                        district();
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}