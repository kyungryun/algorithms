#include <cstdio>

int main() {
	int T;
    scanf("%d", &T);

	for(int t=0; t<T; t++){
		char str[50];
        int cnt = 0;
		scanf("%s", str);

        for(int i=0 ; str[i] != 0 ; i++){
            if(str[i] == '('){
                cnt++;
            }else if(str[i] == ')' && cnt > 0){
                cnt--;
            }else if(str[i] == ')' && cnt <= 0){
                cnt--;
                break;
            }
        }
        if(cnt == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
	}
	return 0;

}
