#include <cstdio>

using namespace std;
int circle[52][52];
int check[52][52];
int temp[52][52];
int n,m,t,ans;
void print(){
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m ; j++){
            printf("%d",circle[i][j]);
        }
        printf("\n");
    }
}
void circle_copy(int (*src)[52], int (*dest)[52]){
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m ; j++){
            dest[i][j] = src[i][j];
        }
    }
}
void rotate(int idx, int d, int k){
    circle_copy(circle, temp);
    if(d == 0){
        for(int i=0 ; i<m ; i++){
            temp[idx][(i+k)%m] = circle[idx][i];
        }
    }else{
        for(int i=0 ; i<m ; i++){
            temp[idx][i-k < 0 ? i-k+m : i-k] = circle[idx][i];
        }
    }
    circle_copy(temp,circle);
}
void simulation(){
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m ; j++){
            check[i][j] = 0;
        }
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m-1 ; j++){
            if(circle[i][j] == circle[i][j+1]) check[i][j] = check[i][j+1] = 1;
        }
        if(circle[i][0] == circle[i][m-1]) check[i][0] = check[i][m-1] = 1;

        for(int j=0 ; j<m ; j++){
            if(circle[i][j] == circle[i+1][j]) check[i][j] = check[i+1][j] = 1;
        }
    }
    bool flag = false;
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m ; j++){
            if(check[i][j] == 1){
                if(circle[i][j] != 0) flag = true;
                circle[i][j] = 0;
            }
        }
    }

    if(!flag){
        int cnt = 0, sum = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=0 ; j<m ; j++){
                if(circle[i][j] != 0){
                    cnt++;
                    sum += circle[i][j];
                }
            }
        }
        if(cnt == 0){
            return;
        }
        double avg = (double)sum/cnt;
        for(int i=1 ; i<=n ; i++){
            for(int j=0 ; j<m ; j++){
                if(circle[i][j] == 0) continue;
                if(circle[i][j] > avg) circle[i][j]--;
                else if(circle[i][j] < avg) circle[i][j]++;
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&t);

    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&circle[i][j]);
        }
    }

    for(int i=0 ; i<t ; i++){
        int x,d,k;
        scanf("%d%d%d",&x,&d,&k);
        for(int j=x ; j<=n ; j+=x){
            rotate(j,d,k);
        }
        simulation();
    }
    ans = 0;
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m ; j++){
            ans += circle[i][j];
        }
    }
    printf("%d\n",ans);
}