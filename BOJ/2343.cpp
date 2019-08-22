#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,disk;
int lesson[100001];
int MAX;

int main(){
    scanf("%d%d",&n,&disk);
    int sum=0;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&lesson[i]);
        MAX = max(MAX, lesson[i]);
        sum += lesson[i];
    }

    int left = MAX;
    int right = sum;
    while(left <= right){
        int mid = (left + right) / 2;
        sum = 0;
        int bluelay = 1;
        for(int i=0 ; i<n ; i++){
            if(sum + lesson[i] > mid){
                sum = 0;
                bluelay++;
            }
            sum+=lesson[i];
        }
        //if(sum != 0)bluelay++;
        if(bluelay <= disk) right = mid - 1;
        else left = mid + 1;
    }
    printf("%d\n",left);
}
