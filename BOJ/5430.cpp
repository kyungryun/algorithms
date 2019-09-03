#include <cstdio>
#include <deque>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0 ; t<T ; t++){
        char p[100001];
        char n[700001];
        int tmp;
        deque<int> dq;
        scanf("%s",p);
        scanf("%d",&tmp);
        scanf("%s",n);
        int i=0;
        while(n[i] != '\0'){
            if(n[i] >= '0' && n[i] <= '9'){
                int j=i;
                int num = n[i]-'0';
                while(n[j] >= '0' && n[j] <= '9' ) j++;
                for(int k=i+1 ; k<j ; k++){
                    num*=10;
                    num += n[k] - '0';
                }
                dq.push_back(num);
                i = j;
            }else i++;
        }
        i=0;
        int dir = 1;
        bool flag = true;
        while(p[i] != '\0'){
            if(p[i] == 'R'){
                dir *= -1;
            }else{
                if(dq.empty()){
                    flag = false;
                    break;
                }
                if(dir == 1) dq.pop_front();
                else dq.pop_back();
            }
            i++;
        }
        if(flag){
            printf("[");
            for(int i=0 ; i<dq.size() ; i++) {
                if(dir == 1) printf("%d",dq[i]);
                else printf("%d",dq[dq.size()-i-1]);
                if(i != dq.size()-1) printf(",");
            }
            printf("]\n");
        }else printf("error\n");
    }
}
