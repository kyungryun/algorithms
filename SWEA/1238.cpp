#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int len, start;
    for(int t=1 ; t<=10 ; t++){
        int contact[101][101]={0,};
        int visited[101]={0,};
        int MAX = 0;
        scanf("%d%d", &len,&start);
        for (int i=1; i <= len/2; i++){
            int from,to;
            scanf("%d%d", &from,&to);
            contact[from][to] = 1;
        }
        queue<int> q;
        queue<int> last;
        q.push(start);
        visited[start] = 1;
        while (!q.empty()){
            while (!last.empty()) last.pop();
            int size = q.size();
            for (int i = 0; i < size; i++){
                int from = q.front();
                q.pop();
                last.push(from);
                for (int j = 1; j <= 100; j++){
                    if (contact[from][j] == 1 && visited[j] == 0){
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
        while (!last.empty()){
            MAX = max(MAX,last.front());
            last.pop();
        }

        printf("#%d %d\n",t,MAX);
    }

}
